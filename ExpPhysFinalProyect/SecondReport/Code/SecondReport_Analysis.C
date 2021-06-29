R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include <sstream>

class Analysis
{
    public:
        void CharginosAnalysis(string fileName, unsigned int nfiles)
        {
            gSystem -> AddDynamicPath("/user/e/edson/public/exp_phys/MG5_aMC_v3_1_0/Delphes/");
            gSystem -> Load("libDelphes");

            string inputpath = "/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/chargino_pair_production_electron_case/";

            std::stringstream file_name;
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

            // Get pointers to branches used in this analysis
	    TClonesArray *branchMET	 = treeReader -> UseBranch("MissingET");	                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            TClonesArray *branchElectron = treeReader -> UseBranch("Electron");
            TClonesArray *branchMuon     = treeReader -> UseBranch("Muon");
	    TClonesArray *branchParticle = treeReader -> UseBranch("Particle");	
            TClonesArray *branchJet      = treeReader -> UseBranch("Jet");

            // Book histograms                                                                                                                                                                                                                                                                                                                                                                

            TH1F *histElectronPT  = new TH1F("histElectronPT" , "Electron P_{T}", 50,  0, 300);
            TH1F *histElectronEta = new TH1F("histElectronEta", "Electron #eta" , 50, -5, 5);
            TH1F *histElectronPhi = new TH1F("histElectronPhi", "Electron #phi" , 50, -5, 5);

            TH1F *histMuonPT  = new TH1F("histMuonPT" , "Muon P_{T}", 50,  0, 300);
            TH1F *histMuonEta = new TH1F("histMuonEta", "Muon #eta" , 50, -5, 5);
            TH1F *histMuonPhi = new TH1F("histMuonPhi", "Muon #phi" , 50, -5, 5);
	                                                                                                                
            TH1F *histMissingETMET        = new TH1F("histMissingETMET", "E^{miss}_{T}", 50, 0, 300);
            TH1F *histMissingETEta        = new TH1F("histMissingETEta", "#eta", 50, -5, 5);
            TH1F *histMissingETPhi        = new TH1F("histMissingETPhi", "#phi", 50, -5, 5);	

	    TH1F *histParticlePT  = new TH1F("histParticlePT" , "Particle P_{T}", 50,  0, 1000);
            TH1F *histParticleE   = new TH1F("histParticleE"  , "Particle E"    , 50,  0, 1000);
            TH1F *histParticleEta = new TH1F("histParticleEta", "Particle #eta" , 50, -5, 5);
            TH1F *histParticlePhi = new TH1F("histParticlePhi", "Particle #phi" , 50, -5, 5);
            
            cout << "Number of Entries in input files: " << numberOfEntries << endl;

            // Loop over all events                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
            for(Int_t entry = 0; entry < numberOfEntries; ++entry)
            {
                // print event number in the file                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                if(entry%1000 == 0) cout << fileName << ": " << "Reading Event " << entry << endl;

                // Load selected branches with data from specified event                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                treeReader -> ReadEntry(entry);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                //if(branchParticle -> GetEntries() > 0)
                //{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                	//for(UInt_t i = 0; i < branchParticle -> GetEntries(); i++)
			//{
				//Particle* particle = (Particle*) branchParticle -> At(i);
				// Fill Particle histograms                                                                                          $
                        	//histParticlePT  -> Fill(particle -> PT);
                        	//histParticleE   -> Fill(particle -> E);
                        	//histParticleEta -> Fill(branchParticle -> Eta);
                        	//histParticlePhi -> Fill(branchParticle -> Phi);
			//}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                //}

                // If event contains at least 1 electron                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                if(branchElectron -> GetEntries() > 0)
                {
                	//Take first electron                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                	Electron *electron = (Electron*) branchElectron -> At(0);

                    	// Plot electron transverse momentum                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                    	histElectronPT  -> Fill(electron -> PT);
			histElectronEta -> Fill(electron -> Eta);
			histElectronPhi -> Fill(electron -> Phi);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
                }

		if(branchMuon -> GetEntries() > 0)
                {
                        for(UInt_t i = 0; i < branchMuon -> GetEntries();i++)
			{
				//Take first electron                                                                                                $
                        	Muon *muon = (Muon*) branchMuon -> At(i);

                        	// Plot electron transverse momentum                                                                                 $
                        	histMuonPT  -> Fill(muon -> PT);
                        	histMuonEta -> Fill(muon -> Eta);
                        	histMuonPhi -> Fill(muon -> Phi);
			}                                                                            
                }


                if(branchMET -> GetEntries() > 0)
                {
                	//Take the missing ET object                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                	MissingET *met = (MissingET*) branchMET -> At(0);

                    	//Plot missing ET value                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                   	histMissingETMET -> Fill(met -> MET);
                        histMissingETEta -> Fill(met -> Eta);
			histMissingETPhi -> Fill(met -> Phi);                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                }

                //if(branchJet -> GetEntries() > 0)
                //{
                	
			//Jet *jet = (Jet*) branchJet -> At(0);
			//Loop over jet objects                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                	//for(UInt_t i = 0; i < branchJet -> GetEntries();i++)


          	//{
                        	//Jet *jet = (Jet*) branchJet -> At(i);
                        	// Select those jets tagged as taus
				//if(jet -> TauTag == 1)
                        	//{
                        		// histTau -> Fill(je
                        	//}
                 	//}
                //}

    
            }

            file_name << "Hists_" << fileName << ".root";
            // Save the histogram in a ROOT file  
            TFile *f = new TFile(file_name.str().c_str(), "RECREATE");
            histElectronPT  -> Write("", TObject::kOverwrite);
            histElectronEta -> Write("", TObject::kOverwrite);
            histElectronPhi -> Write("", TObject::kOverwrite);	    
	
            histMuonPT  -> Write("", TObject::kOverwrite);
            histMuonEta -> Write("", TObject::kOverwrite);
            histMuonPhi -> Write("", TObject::kOverwrite);

	    histMissingETMET  -> Write("", TObject::kOverwrite);
            histMissingETEta -> Write("", TObject::kOverwrite);
            histMissingETPhi -> Write("", TObject::kOverwrite);
	
        }

};

void SecondReport_Analysis()
{
    unsigned int Runs = 3;
    vector<string> Datasets = {"output_simulated_data_two", "ttbar", "WW"};

    Analysis *obj1 = new Analysis();

    for (unsigned int i = 0; i < Datasets.size(); ++i)
    {
        obj1 -> CharginosAnalysis(Datasets.at(i), Runs);
    }
    
}
