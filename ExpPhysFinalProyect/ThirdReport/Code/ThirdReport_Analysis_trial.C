R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include "CalcGenericMT2/MT2_ROOT.h"
#include <sstream>

class Analysis
{
    private:
        TString trigger;
        Float_t MZ = 90;
    public:
        void CharginosAnalysis(TString fileName, unsigned int nfiles, Float_t weights)
        {
            gSystem -> AddDynamicPath("/user/e/edson/public/exp_phys/MG5_aMC_v3_1_0/Delphes/");
            gSystem -> Load("libDelphes");

            string inputpath = "/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/";

            stringstream file_name;
            // Create chain of root trees
            TChain chain("Delphes");
            for(UInt_t ifile = 0;ifile < nfiles;ifile++)
            {
                file_name << inputpath << fileName << "/Events/run_01_" << ifile << "/tag_1_delphes_events.root";
                chain.Add(file_name.str().c_str());
                file_name.str("");
            }

            // Create object of class ExRootTreeReader
            ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
            Long64_t numberOfEntries = treeReader -> GetEntries();

            cout << "Number of Entries in " << fileName << ": " << numberOfEntries << endl;

            // Get pointers to branches used in this analysis
	        TClonesArray *branchParticle = treeReader -> UseBranch("Particle");
            TClonesArray *branchMET	     = treeReader -> UseBranch("MissingET");
            TClonesArray *branchJet	     = treeReader -> UseBranch("Jet");

            //TH1F *histMT2   = new TH1F(fileName + "_" + "histMT2", "MT2", 10,  0, 200);
            //TH1F *histMET = new TH1F(fileName + "_" + "histMET", "p^{miss}_{T}", 15, 0, 400);

            TH1F *histMT2   = new TH1F("histMT2", "MT2"         , 10, 0, 200);
            TH1F *histMET   = new TH1F("histMET", "p^{miss}_{T}", 15, 0, 400);

            // Loop over all events
            for(UInt_t entry = 0; entry < numberOfEntries; ++entry)
            {
                // print event number in the file
                if(entry%1000 == 0) cout << fileName << ": " << "Reading Event " << entry << endl;

                // Load selected branches with data from specified event
                treeReader -> ReadEntry(entry);

                if(branchParticle -> GetEntries() > 0 && branchMET -> GetEntries() > 0)
                {
                    MissingET *met = (MissingET*) branchMET -> At(0);
                    
                    for(UInt_t i = 0; i < branchParticle -> GetEntries(); ++i)
			        {
                        GenParticle *particle = (GenParticle*) branchParticle -> At(i);

                        TLorentzVector l1, l2, Missing, dileptons;

                        if (TMath::Abs(particle -> PID) == 11 || TMath::Abs(particle -> PID) == 12 || TMath::Abs(particle -> PID) == 13 || TMath::Abs(particle -> PID) == 14 || TMath::Abs(particle -> PID) == 15 || TMath::Abs(particle -> PID) == 16)
                        {    
                            if(TMath::Abs(particle -> PID) == 11){trigger = "ee";} 
                            if(TMath::Abs(particle -> PID) == 11 || TMath::Abs(particle -> PID) == 13){trigger = "emu";}  
                            if(TMath::Abs(particle -> PID) == 13){trigger = "mumu";} 
                             
                            if (trigger == "ee" || trigger == "emu" || trigger == "mumu")
                            {
                                if (particle -> PT >= 25 && TMath::Abs(particle -> Eta) < 2.4)
                                {  
                                    l1.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
                                    if (particle -> PT >= 20 && TMath::Abs(particle -> Eta) < 2.4)
                                    { 
                                        l2.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
                                        dileptons = l1 + l2;
                                        Missing.SetPtEtaPhiM(met -> MET, met -> Eta, met -> Phi, 0.);
                                        Float_t Mll = TMath::Abs(dileptons.M()*1000);
                                        Float_t PT_miss = Missing.Pt();
                                        ComputeMT2 calcMT2 = ComputeMT2(l1, l2, Missing);       
                                        Float_t MT2 = calcMT2.Compute();
                                        histMET -> Fill(PT_miss, weights);

                                        if (Mll >= 20)
                                        {
                                            if (PT_miss >= 140)
                                            {  
                                                histMT2 -> Fill(MT2, weights);
                                            }   
                                        }      
                                    }   
                                }   
                            }

                            if (trigger == "ee" || trigger == "mumu")
                            {
                                if (particle -> PT >= 25 && TMath::Abs(particle -> Eta) < 2.4)
                                {  
                                    l1.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
                                    if (particle -> PT >= 20 && TMath::Abs(particle -> Eta) < 2.4)
                                    { 
                                        l2.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
                                        dileptons = l1 + l2;
                                        Missing.SetPtEtaPhiM(met -> MET, met -> Eta, met -> Phi, 0.);
                                        Float_t Mll = TMath::Abs(dileptons.M()*1000);
                                        Float_t PT_miss = Missing.Pt();
                                        ComputeMT2 calcMT2 = ComputeMT2(l1, l2, Missing);       
                                        Float_t MT2 = calcMT2.Compute();
                                        histMET -> Fill(PT_miss, weights);

                                        if (Mll >= 20)
                                        {
                                            if (TMath::Abs(Mll - MZ) > 15)
                                            {
                                                if (PT_miss >= 140)
                                                {  
                                                    histMT2 -> Fill(MT2, weights);
                                                }   
                                            }
                                        }      
                                    }   
                                }   
                            }    
                        }
                    }
                }
            }

            file_name << "Hists_" << fileName << ".root";
            TFile *f = new TFile(file_name.str().c_str(), "RECREATE");
            histMET   -> Write("", TObject::kOverwrite);
            histMT2   -> Write("", TObject::kOverwrite);
        }
};

void ThirdReport_Analysis_trial()
{
    vector<unsigned int> Runs = {3, 3, 3, 3};
    vector<TString> Datasets = {"signal_try", "ttbar_try", "TW_try", "WW_try"};
    vector<Float_t> weights  = {0.0021       , 3         ,  19.5   ,    21};

    Analysis *obj1 = new Analysis();

    for (unsigned int i = 0; i < Datasets.size(); ++i)
    {
        obj1 -> CharginosAnalysis(Datasets.at(i), Runs.at(i), weights.at(i));
    }
}
