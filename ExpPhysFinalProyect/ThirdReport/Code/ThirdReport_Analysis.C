R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include <sstream>

class Analysis
{      
    private:
        // Leptons
        vector<Float_t> lep_pt, lep_eta, lep_phi, lep_E;
        vector<Int_t> lep_charge, lep_type;
        // Jets
        vector<Float_t> jet_pt, jet_eta, jet_phi, jet_E;
    public:
        void CharginosAnalysis(string fileName, unsigned int nfiles)
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

            // Book histograms                                                                                                                                                                                                                                                                                                                                                                
/* 	        TH1F *histCharginoPT   = new TH1F("histCharginoPT"   , "Chargino P_{T}", 50,  0, 1000);
            TH1F *histCharginoE    = new TH1F("histCharginoE"    , "Chargino E"    , 50,  0, 2800);
            TH1F *histCharginoEta  = new TH1F("histCharginoEta"  , "Chargino #eta" , 50, -5, 5);
            TH1F *histCharginoPhi  = new TH1F("histCharginoPhi"  , "Chargino #phi" , 50, -5, 5);
            TH1F *histCharginoMass = new TH1F("histCharginoMass" , "Chargino Mass" , 50,  0, 1000);		

            TH1F *histElectronPT  = new TH1F("histElectronPT" , "Electron P_{T}", 50,  0, 300);
            TH1F *histElectronEta = new TH1F("histElectronEta", "Electron #eta" , 50, -5, 5);
            TH1F *histElectronPhi = new TH1F("histElectronPhi", "Electron #phi" , 50, -5, 5);

            TH1F *histMuonPT  = new TH1F("histMuonPT" , "Muon P_{T}", 50,  0, 300);
            TH1F *histMuonEta = new TH1F("histMuonEta", "Muon #eta" , 50, -5, 5);
            TH1F *histMuonPhi = new TH1F("histMuonPhi", "Muon #phi" , 50, -5, 5);
	                                                                                                                
            TH1F *histMissingETMET        = new TH1F("histMissingETMET", "E^{miss}_{T}", 50, 0, 300);
            TH1F *histMissingETEta        = new TH1F("histMissingETEta", "#eta", 50, -5, 5);
            TH1F *histMissingETPhi        = new TH1F("histMissingETPhi", "#phi", 50, -5, 5); */	
            
            // Loop over all events                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
            for(UInt_t entry = 0; entry < numberOfEntries; ++entry)
            {
                // print event number in the file                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                if(entry%1000 == 0) cout << fileName << ": " << "Reading Event " << entry << endl;

                // Load selected branches with data from specified event                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                treeReader -> ReadEntry(entry);

                if(branchParticle -> GetEntries() > 0 && branchJet -> GetEntries() > 0)
                {
                    Int_t n_lep = 0;
                    Int_t n_lepbase = 0;
                    Int_t n_lepsign = 0;
                    vector<Int_t> lep_indices;
                    lep_indices.clear();
                    
                    TLorentzVector leptemp;
                    TLorentzVector jettemp;
                    Int_t removed_leptons = 0;
                    vector<Int_t> remove_jet; 
                    remove_jet.clear();

                    for(UInt_t i = 0; i < branchParticle -> GetEntries(); ++i)
			        {
                        GenParticle *particle = (GenParticle*) branchParticle -> At(i);
                
                        if (TMath::Abs(particle -> PID) == 11 || TMath::Abs(particle -> PID) == 12 || TMath::Abs(particle -> PID) == 13 || TMath::Abs(particle -> PID) == 14 || TMath::Abs(particle -> PID) == 15 || TMath::Abs(particle -> PID) == 16)
                        {
                            leptemp.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
                            
                            Double_t dR = 0.;
                            bool removeLep = false;
                            bool removeJet = false;

                            for (UInt_t j = 0; j < branchJet -> GetEntries(); ++j)
                            {
                                Jet *jet = (Jet*) branchJet -> At(j);

                                removeJet;
                                
                                if (jet -> PT > 20. && TMath::Abs(jet -> Eta) < 2.4)
                                {
                                    jettemp.SetPtEtaPhiE(jet -> PT, jet -> Eta, jet -> Phi, jet -> Mass);

                                    dR = jettemp.DeltaR(leptemp);

                                    if(!removeJet)
                                    {
	                                    if(TMath::Abs(particle -> PID) == 11 && dR < 0.4) !removeLep;
                                    }
        
                                    else
                                    {
	                                    remove_jet.push_back(j);
	                                }      
                                }

                            }

                            if(removeLep) continue;

                            ++n_lep;
                            lep_indices.push_back(i);
                        }
                    } // End lepton loop                                                            

                    if (n_lep == 2) // Select only events with two good lepton candidates  
                    {
                        Int_t l1_i = lep_indices.at(0); // Index of leading lepton  
                        Int_t l2_i = lep_indices.at(1); // Index of trailing lepton


                    }
                }    

            
                //TLorentzVector temp;
				//temp.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
				//Chargino += temp;
				// Fill Particle histograms                                                                       
                //histCharginoPT   -> Fill(particle -> PT);
                //histCharginoE    -> Fill(particle -> E);
                //histCharginoEta  -> Fill(particle -> Eta);
                //histCharginoPhi  -> Fill(particle -> Phi);
				//histCharginoMass -> Fill(temp.M());
            
            }

           /*  file_name << "Hists_" << fileName << ".root";
            // Save the histogram in a ROOT file  
            TFile *f = new TFile(file_name.str().c_str(), "RECREATE");
	        histCharginoPT   -> Write("", TObject::kOverwrite);
	        histCharginoE    -> Write("", TObject::kOverwrite);
	        histCharginoEta  -> Write("", TObject::kOverwrite);			
	        histCharginoPhi  -> Write("", TObject::kOverwrite);	
            histCharginoMass -> Write("", TObject::kOverwrite);		
	
            histElectronPT  -> Write("", TObject::kOverwrite);
            histElectronEta -> Write("", TObject::kOverwrite);
            histElectronPhi -> Write("", TObject::kOverwrite);	    
	
            histMuonPT  -> Write("", TObject::kOverwrite);
            histMuonEta -> Write("", TObject::kOverwrite);
            histMuonPhi -> Write("", TObject::kOverwrite);

	        histMissingETMET  -> Write("", TObject::kOverwrite);
            histMissingETEta  -> Write("", TObject::kOverwrite);
            histMissingETPhi  -> Write("", TObject::kOverwrite); */
	
        }

};

void ThirdReport_Analysis()
{
    vector<unsigned int> Runs = {3, 3, 3, 3};
    vector<string> Datasets = {"signal_try", "ttbar_try", "TW_try", "WW_try"};

    Analysis *obj1 = new Analysis();

    for (unsigned int i = 0; i < Datasets.size(); ++i)
    {
        obj1 -> CharginosAnalysis(Datasets.at(i), Runs.at(i));
    }
}
