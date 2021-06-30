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

            // Get pointers to branches used in this analysis
	    TClonesArray *branchParticle = treeReader -> UseBranch("Particle");	                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            TClonesArray *branchElectron = treeReader -> UseBranch("Electron");
            TClonesArray *branchMuon     = treeReader -> UseBranch("Muon");
	    TClonesArray *branchMET	 = treeReader -> UseBranch("MissingET");
            TClonesArray *branchJet      = treeReader -> UseBranch("Jet");		
            TClonesArray *branchTrack    = treeReader -> UseBranch("Track");

            // Book histograms                                                                                                                                                                                                                                                                                                                                                                
	    TH1F *histCharginoPT   = new TH1F("histCharginoPT"   , "Chargino P_{T}", 50,  0, 1000);
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
            TH1F *histMissingETPhi        = new TH1F("histMissingETPhi", "#phi", 50, -5, 5);	
		
	    TH1F *histJetPT              = new TH1F("histJetPT"      , "Jet P_{T}", 50, 0, 300);
            TH1F *histJetEta             = new TH1F("histJetEta"     , "Jet #eta" , 50, -5, 5);
            TH1F *histJetPhi             = new TH1F("histJetPhi"     , "Jet #phi" , 50, -5, 5);
	    TH1F *histJetMass            = new TH1F("histJetMass"     , "Jet Mass" , 50, 0, 60);
	    TH1F *histJetDeltaEta        = new TH1F("histJetDeltaEta", "Jet #Delta #eta", 50, 0, 0.5);
            TH1F *histJetDeltaPhi        = new TH1F("histJetDeltaPhi", "Jet #Delta #phi", 50, 0, 0.5);			
            
            cout << "Number of Entries in input files: " << numberOfEntries << endl;

            // Loop over all events                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
            for(Int_t entry = 0; entry < numberOfEntries; ++entry)
            {
                // print event number in the file                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                if(entry%1000 == 0) cout << fileName << ": " << "Reading Event " << entry << endl;

                // Load selected branches with data from specified event                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                treeReader -> ReadEntry(entry);
		
		TLorentzVector Chargino (0,0,0,0);                
                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                if(branchParticle -> GetEntries() > 0)
                {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                	GenParticle* particle = (GenParticle*) branchParticle -> At(0);
			for(UInt_t i = 0; i < branchParticle -> GetEntries(); i++)
			{
				GenParticle* particle = (GenParticle*) branchParticle -> At(i);
				
				if (particle -> PID == 1000024)
				{
					TLorentzVector temp;
					temp.SetPtEtaPhiE(particle -> PT, particle -> Eta, particle -> Phi, particle -> E);
					Chargino += temp;
					// Fill Particle histograms                                                                       
                        		histCharginoPT   -> Fill(particle -> PT);
                        		histCharginoE    -> Fill(particle -> E);
                        		histCharginoEta  -> Fill(particle -> Eta);
                        		histCharginoPhi  -> Fill(particle -> Phi);
					histCharginoMass -> Fill(Chargino.M());
				}
			}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                }

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
                        //Take first muon
			//Muon *muon = (Muon*) branchMuon -> At(0);
			
			//Loop over muon objects
			for(UInt_t i = 0; i < branchMuon -> GetEntries();i++)
			{                                                                                                
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

                if(branchJet -> GetEntries() > 0)
                {
                	
			//Take first jet
			//Jet *jet = (Jet*) branchJet -> At(0);
			
			//Loop over jet objects                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                	for(UInt_t i = 0; i < branchJet -> GetEntries();i++)
			{
                        	Jet *jet = (Jet*) branchJet -> At(i);
                        	// Select those jets tagged as taus
				if(jet -> TauTag == 1)
                        	{
                  			histJetPT       -> Fill(jet -> PT);
            				histJetEta      -> Fill(jet -> Eta);       
            				histJetPhi      -> Fill(jet -> Phi);       
            				histJetMass     -> Fill(jet -> Mass);
					histJetDeltaEta -> Fill(jet -> DeltaEta);       
            				histJetDeltaPhi -> Fill(jet -> DeltaPhi);       
                        	}
                 	}
                }

    
            }

            file_name << "Hists_" << fileName << ".root";
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
            histMissingETPhi  -> Write("", TObject::kOverwrite);
		
            histJetPT	    -> Write("", TObject::kOverwrite);
            histJetEta	    -> Write("", TObject::kOverwrite);
            histJetPhi	    -> Write("", TObject::kOverwrite);
            histJetMass     -> Write("", TObject::kOverwrite);
            histJetDeltaEta -> Write("", TObject::kOverwrite);
            histJetDeltaPhi -> Write("", TObject::kOverwrite);		
	
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
