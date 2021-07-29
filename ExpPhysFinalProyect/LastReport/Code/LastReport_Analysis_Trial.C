R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include "CalcGenericMT2/MT2_ROOT.h"
#include <sstream>

class Analysis
{
    private:
        array<Float_t, 1000000> electronPT, electronEta, electronPhi;
        array<Float_t, 1000000> muonPT, muonEta, muonPhi;
        array<Float_t, 1000000> electronPT_emu, electronEta_emu, electronPhi_emu;
        array<Float_t, 1000000> muonPT_emu, muonEta_emu, muonPhi_emu;
        array<Float_t, 1000000> missingMET, missingEta, missingPhi;
        array<Float_t, 1000000> jetPT, jetEta;
        array<UInt_t , 1000000> jetBTag;
        bool electronTrigger = false;
        bool muonTrigger = false;
        bool electron_muonTrigger = false;
    public:
        void CharginosAnalysis(TString path, TString hist_names, UInt_t nfiles, Float_t weights)
        {
            gSystem -> AddDynamicPath("/user/e/edson/public/exp_phys/MG5_aMC_v3_1_0/Delphes/");
            gSystem -> Load("libDelphes");

            string inputpath = "/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/";

            stringstream file_name;
            // Create chain of root trees
            TChain chain("Delphes");
            
            for(UInt_t ifile = 0;ifile < nfiles;ifile++)
            {
                //file_name << inputpath << fileName << "/Events/run_01_" << ifile << "/tag_1_delphes_events.root";
                file_name << path << "run_01_" << ifile << "/tag_1_delphes_events.root";
                chain.Add(file_name.str().c_str());
                file_name.str("");
            }

            // Create object of class ExRootTreeReader
            ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
            Long64_t numberOfEntries = treeReader -> GetEntries();

            cout << "Number of Entries in " << path << ": " << numberOfEntries << endl;

            // Get pointers to branches used in this analysis
	        TClonesArray *branchElectron = treeReader -> UseBranch("Electron");
            TClonesArray *branchMuon     = treeReader -> UseBranch("Muon");
            TClonesArray *branchMET	     = treeReader -> UseBranch("MissingET");
            TClonesArray *branchJet	     = treeReader -> UseBranch("Jet");

            // ee trigger histograms
            //SRs
            TH1F *histMT2_ee_1j0t   = new TH1F("histMT2_ee_1j0t"  , "MT2 ee 1j0t"         , 15, 0, 500);
            TH1F *histMT2_ee_1j1t   = new TH1F("histMT2_ee_1j1t"  , "MT2 ee 0j1t"         , 15, 0, 500);
            TH1F *histMET_ee        = new TH1F("histMET_ee"       , "p^{miss}_{T} ee"     , 15, 100, 1000);
            
            // mumu trigger histograms
            //SRs
            TH1F *histMT2_mumu_1j0t   = new TH1F("histMT2_mumu_1j0t"  , "MT2 mumu 1j0t"         , 15, 0, 500);
            TH1F *histMT2_mumu_1j1t   = new TH1F("histMT2_mumu_1j1t"  , "MT2 mumu 0j1t"         , 15, 0, 500);
            TH1F *histMET_mumu        = new TH1F("histMET_mumu"       , "p^{miss}_{T} mumu"     , 15, 100, 1000);

            // emu trigger histograms
            //SRs
            TH1F *histMT2_emu_1j0t   = new TH1F("histMT2_emu_1j0t"  , "MT2 emu 1j0t"         , 15, 0, 500);
            TH1F *histMT2_emu_1j1t   = new TH1F("histMT2_emu_1j1t"  , "MT2 emu 1j1t"         , 15, 0, 500);
            TH1F *histMET_emu        = new TH1F("histMET_emu"       , "p^{miss}_{T} emu"     , 15, 100, 1000);
            
            // Loop over all events
            for(UInt_t entry = 0; entry < numberOfEntries; ++entry)
            {
                // print event number in the file
                if(entry%1000 == 0) cout << path << ": " << "Reading Event " << entry << endl;

                // Load selected branches with data from specified event
                treeReader -> ReadEntry(entry); 

                if(branchElectron -> GetEntries() == 2) 
                {
                    Electron *electron = (Electron*)  branchElectron -> At(0);
                    electronPT.fill(electron -> PT);
                    electronEta.fill(electron -> Eta);
                    electronPhi.fill(electron -> Phi);
                    !electronTrigger;            
                }

                if(branchMuon -> GetEntries() == 2) 
                {
                    Muon *muon = (Muon*) branchMuon -> At(0);
                    muonPT.fill(muon -> PT);
                    muonEta.fill(muon -> Eta);
                    muonPhi.fill(muon -> Phi);
                    !muonTrigger;             
                }

                if(branchMuon -> GetEntries() == 1 && branchElectron -> GetEntries() == 1)  
                {
                    Electron *electron_emu = (Electron*)  branchElectron -> At(0);
                    Muon *muon_emu = (Muon*) branchMuon -> At(0);
                    electronPT_emu.fill(electron_emu -> PT);
                    electronEta_emu.fill(electron_emu -> Eta);
                    electronPhi_emu.fill(electron_emu -> Phi);
                    muonPT_emu.fill(muon_emu -> PT);
                    muonEta_emu.fill(muon_emu -> Eta);
                    muonPhi_emu.fill(muon_emu -> Phi);
                    !electron_muonTrigger;             
                }

                if(branchMET -> GetEntries() > 0) 
                {          
                    MissingET *met = (MissingET*) branchMET -> At(0);
                    missingMET.fill(met -> MET);
                    missingEta.fill(met -> Eta);
                    missingPhi.fill(met -> Phi);                               
                }

                if(branchJet -> GetEntries() > 0) 
                {          
                    Jet *jet = (Jet*) branchJet -> At(0);
                    jetPT.fill(jet -> PT); 
                    jetEta.fill(jet -> Eta);
                    jetBTag.fill(jet -> BTag);            
                }

                if (TMath::Abs(electronEta.at(entry)) > 2.5 && TMath::Abs(muonEta.at(entry)) > 2.5) continue;

                //ee trigger
                if (!electronTrigger)
                {
                    TLorentzVector l1_ee, l2_ee, Missing_ee, dileptons_ee;
                    
                    if (electronPT.at(entry) >= 25 && TMath::Abs(electronEta.at(entry)) < 2.4)
                    {
                        l1_ee.SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0); 
                        
                        if (electronPT.at(entry) >= 20 && TMath::Abs(electronEta.at(entry)) < 2.4)
                        {
                            l2_ee.SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);     
                            dileptons_ee = l1_ee + l2_ee;
                            Float_t Mll_ee = TMath::Abs(dileptons_ee.M()*pow(10,7));
                            Missing_ee.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);

                            if (Mll_ee >= 20 && Missing_ee.Pt() >= 140)
                            {
                                if (jetPT.at(entry) > 20 && TMath::Abs(jetEta.at(entry)) < 2.4)
                                { 
                                    Float_t PT_miss_ee = Missing_ee.Pt();

                                    if (jetBTag.at(entry) == 0)
                                    {
                                        ComputeMT2 calcMT2_ee = ComputeMT2(l1_ee, l2_ee, Missing_ee);       
                                        Float_t MT2_ee = calcMT2_ee.Compute();
                                        histMT2_ee_1j0t -> Fill(MT2_ee, weights);
                                    }

                                    if (jetBTag.at(entry) == 1)
                                    {
                                        ComputeMT2 calcMT2_ee = ComputeMT2(l1_ee, l2_ee, Missing_ee);       
                                        Float_t MT2_ee = calcMT2_ee.Compute();
                                        histMT2_ee_1j1t -> Fill(MT2_ee, weights);
                                    }

                                    histMET_ee -> Fill(PT_miss_ee, weights);
                                } 
                            }      
                        }
                    }            
                }

                //mumu trigger
                if (!muonTrigger)
                {
                    TLorentzVector l1_mumu, l2_mumu, Missing_mumu, dileptons_mumu;

                    if (electronPT.at(entry) >= 25 && TMath::Abs(electronEta.at(entry)) < 2.4)
                    {
                        l1_mumu.SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0); 
                        
                        if (electronPT.at(entry) >= 20 && TMath::Abs(electronEta.at(entry)) < 2.4)
                        {
                            l2_mumu.SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);     
                            dileptons_mumu = l1_mumu + l2_mumu;
                            Float_t Mll_mumu = TMath::Abs(dileptons_mumu.M()*pow(10,7));
                            Missing_mumu.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);

                            if (Mll_mumu >= 20 && Missing_mumu.Pt() >= 140)
                            {
                                if (jetPT.at(entry) > 20 && TMath::Abs(jetEta.at(entry)) < 2.4)
                                { 
                                    Float_t PT_miss_mumu = Missing_mumu.Pt();

                                    if (jetBTag.at(entry) == 0)
                                    {
                                        ComputeMT2 calcMT2_mumu = ComputeMT2(l1_mumu, l2_mumu, Missing_mumu);       
                                        Float_t MT2_mumu = calcMT2_mumu.Compute();
                                        histMT2_mumu_1j0t -> Fill(MT2_mumu, weights);
                                    }

                                    if (jetBTag.at(entry) == 1)
                                    {
                                        ComputeMT2 calcMT2_mumu = ComputeMT2(l1_mumu, l2_mumu, Missing_mumu);       
                                        Float_t MT2_mumu = calcMT2_mumu.Compute();
                                        histMT2_mumu_1j1t -> Fill(MT2_mumu, weights);
                                    }

                                    histMET_mumu -> Fill(PT_miss_mumu, weights);
                                } 
                            }      
                        }
                    }            
                }


                //emu trigger
                if (!electron_muonTrigger)
                {
                    TLorentzVector l1_emu, l2_emu, Missing_emu, dileptons_emu;

                    if (electronPT_emu.at(entry) >= 25 && TMath::Abs(electronEta_emu.at(entry)) < 2.4)
                    {
                        l1_emu.SetPtEtaPhiM(electronPT_emu.at(entry), electronEta_emu.at(entry), electronPhi_emu.at(entry), 0); 
                        
                        if (muonPT_emu.at(entry) >= 20 && TMath::Abs(muonEta_emu.at(entry)) < 2.4)
                        {
                            l2_emu.SetPtEtaPhiM(muonPT_emu.at(entry), muonEta_emu.at(entry), muonPhi_emu.at(entry), 0);     
                            dileptons_emu = l1_emu + l2_emu;
                            Float_t Mll_emu = TMath::Abs(dileptons_emu.M()*pow(10,7));
                            Missing_emu.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);

                            if (Mll_emu >= 20 && Missing_emu.Pt() >= 140)
                            {
                                if (jetPT.at(entry) > 20 && TMath::Abs(jetEta.at(entry)) < 2.4)
                                { 
                                    Float_t PT_miss_emu = Missing_emu.Pt();

                                    if (jetBTag.at(entry) == 0)
                                    {
                                        ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                        Float_t MT2_emu = calcMT2_emu.Compute();
                                        histMT2_emu_1j0t -> Fill(MT2_emu, weights);
                                    }

                                    if (jetBTag.at(entry) == 1)
                                    {
                                        ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                        Float_t MT2_emu = calcMT2_emu.Compute();
                                        histMT2_emu_1j1t -> Fill(MT2_emu, weights);
                                    }

                                    histMET_emu -> Fill(PT_miss_emu, weights);
                                }
                            }      
                        }
                    }


                    if (muonPT_emu.at(entry) >= 25 && TMath::Abs(muonEta_emu.at(entry)) < 2.4)
                    {
                        l1_emu.SetPtEtaPhiM(muonPT_emu.at(entry), muonEta_emu.at(entry), muonPhi_emu.at(entry), 0); 
                        
                        if (electronPT_emu.at(entry) >= 20 && TMath::Abs(electronEta_emu.at(entry)) < 2.4)
                        {
                            l2_emu.SetPtEtaPhiM(electronPT_emu.at(entry), electronEta_emu.at(entry), electronPhi_emu.at(entry), 0);     
                            dileptons_emu = l1_emu + l2_emu;
                            Float_t Mll_emu = TMath::Abs(dileptons_emu.M()*pow(10,7));
                            Missing_emu.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);

                            if (Mll_emu >= 20 && Missing_emu.Pt() >= 140)
                            {
                                if (jetPT.at(entry) > 20 && TMath::Abs(jetEta.at(entry)) < 2.4)
                                { 
                                    Float_t PT_miss_emu = Missing_emu.Pt();

                                    if (jetBTag.at(entry) == 0)
                                    {
                                        ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                        Float_t MT2_emu = calcMT2_emu.Compute();
                                        histMT2_emu_1j0t -> Fill(MT2_emu, weights);
                                    }

                                    if (jetBTag.at(entry) == 1)
                                    {
                                        ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                        Float_t MT2_emu = calcMT2_emu.Compute();
                                        histMT2_emu_1j1t -> Fill(MT2_emu, weights);
                                    }

                                    histMET_emu -> Fill(PT_miss_emu, weights);
                                }
                            }      
                        }
                    }               
                }
            }

            electronPT.fill(0);
            electronEta.fill(0); 
            electronPhi.fill(0);

            muonPT.fill(0); 
            muonEta.fill(0); 
            muonPhi.fill(0);

            electronPT_emu.fill(0);
            electronEta_emu.fill(0); 
            electronPhi_emu.fill(0);

            muonPT_emu.fill(0); 
            muonEta_emu.fill(0); 
            muonPhi_emu.fill(0);

            missingMET.fill(0); 
            missingEta.fill(0); 
            missingPhi.fill(0);

            jetPT.fill(0); 
            jetEta.fill(0);
            jetBTag.fill(0);
             
            file_name << "Hists_" << hist_names << ".root";
            TFile *f = new TFile(file_name.str().c_str(), "RECREATE");
            
            //ee trigger
            //SRs
            histMT2_ee_1j0t -> Write("", TObject::kOverwrite); 
            histMT2_ee_1j1t -> Write("", TObject::kOverwrite);
            histMET_ee -> Write("", TObject::kOverwrite);
        
            //mumu trigger
            //SRs
            histMT2_mumu_1j0t -> Write("", TObject::kOverwrite); 
            histMT2_mumu_1j1t -> Write("", TObject::kOverwrite);
            histMET_mumu -> Write("", TObject::kOverwrite);
            
            //emu trigger
            //SRs
            histMT2_emu_1j0t -> Write("", TObject::kOverwrite); 
            histMT2_emu_1j1t -> Write("", TObject::kOverwrite);
            histMET_emu -> Write("", TObject::kOverwrite);
        }

        virtual ~Analysis() 
        {
            
        };
};

void LastReport_Analysis_Trial()
{
    vector<UInt_t> Runs  = {10, 10, 10};
    vector<TString> Datasets   = {"/data/atlas/dbetalhc/exphys/signal_events/signal/Events/"
                                  ,"/data/atlas/dbetalhc/exphys/ttbar_events/ttbar/Events/"
                                  ,"/data/atlas/dbetalhc/exphys/tW_events/tW/Events/"
                                 };
    vector<TString> Hist_names = {"signal", "ttbar", "tW"};
    //vector<Float_t> Weights  = {0.000021       , 3      ,  19.5};
    //vector<Float_t> Weights    = {0.00021       , 30      ,  195};
    vector<Float_t> Weights    = {1       , 1      ,  1};

    Analysis *obj1 = new Analysis();

    for (UInt_t i = 0; i < Datasets.size(); ++i)
    {
        obj1 -> CharginosAnalysis(Datasets.at(i), Hist_names.at(i), Runs.at(i), Weights.at(i));
    }
}
