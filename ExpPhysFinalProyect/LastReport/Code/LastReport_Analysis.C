R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "ExRootAnalysis/ExRootTreeReader.h"
#include "CalcGenericMT2/MT2_ROOT.h"
#include <sstream>

class Analysis
{
    private:
        array<Float_t, 3000> electronPT, electronEta, electronPhi;
        array<Float_t, 3000> muonPT, muonEta, muonPhi;
        array<Float_t, 3000> missingMET, missingEta, missingPhi;
        array<Float_t, 3000> jetPT, jetEta, jetPhi, jetMass;
        array<UInt_t, 3000> jetBTag;
        bool electronTrigger = false;
        bool muonTrigger = false;
        bool jetTrigger = false; 
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
            TH1F *histMT2_ee_SR1_0j0t   = new TH1F("histMT2_ee_SR1_0j0t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_SR1_0j0t   = new TH1F("histMET_ee_SR1_0j0t"  , "p^{miss}_{T} ee", 15, 0, 1000);
            TH1F *histMT2_ee_SR1_1j0t   = new TH1F("histMT2_ee_SR1_1j0t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_SR1_1j0t   = new TH1F("histMET_ee_SR1_1j0t"  , "p^{miss}_{T} ee", 15, 0, 1000);
            
            TH1F *histMT2_ee_SR2_0j0t   = new TH1F("histMT2_ee_SR2_0j0t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_SR2_0j0t   = new TH1F("histMET_ee_SR2_0j0t"  , "p^{miss}_{T} ee", 15, 0, 1000);
            TH1F *histMT2_ee_SR2_1j0t   = new TH1F("histMT2_ee_SR2_1j0t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_SR2_1j0t   = new TH1F("histMET_ee_SR2_1j0t"  , "p^{miss}_{T} ee", 15, 0, 1000);

            TH1F *histMT2_ee_SR3_0t   = new TH1F("histMT2_ee_SR3_0j0t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_SR3_0t   = new TH1F("histMET_ee_SR3_0j0t"  , "p^{miss}_{T} ee", 15, 0, 1000);

            //CRs
            TH1F *histMT2_ee_CR1_1t   = new TH1F("histMT2_ee_CR1_1t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_CR1_1t   = new TH1F("histMET_ee_CR1_1t"  , "p^{miss}_{T} ee", 15, 0, 1000);

            TH1F *histMT2_ee_CR2_1t   = new TH1F("histMT2_ee_CR2_1t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_CR2_1t   = new TH1F("histMET_ee_CR2_1t"  , "p^{miss}_{T} ee", 15, 0, 1000);

            TH1F *histMT2_ee_CR3_1t   = new TH1F("histMT2_ee_CR3_1t"  , "MT2 ee"         , 10, 0, 1000);
            TH1F *histMET_ee_CR3_1t   = new TH1F("histMET_ee_CR3_1t"  , "p^{miss}_{T} ee", 15, 0, 1000);

            // mumu trigger histograms
            //SRs
            TH1F *histMT2_mumu_SR1_0j0t   = new TH1F("histMT2_mumu_SR1_0j0t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_SR1_0j0t   = new TH1F("histMET_mumu_SR1_0j0t"  , "p^{miss}_{T} mumu", 15, 0, 1000);
            TH1F *histMT2_mumu_SR1_1j0t   = new TH1F("histMT2_mumu_SR1_1j0t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_SR1_1j0t   = new TH1F("histMET_mumu_SR1_1j0t"  , "p^{miss}_{T} mumu", 15, 0, 1000);
            
            TH1F *histMT2_mumu_SR2_0j0t   = new TH1F("histMT2_mumu_SR2_0j0t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_SR2_0j0t   = new TH1F("histMET_mumu_SR2_0j0t"  , "p^{miss}_{T} mumu", 15, 0, 1000);
            TH1F *histMT2_mumu_SR2_1j0t   = new TH1F("histMT2_mumu_SR2_1j0t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_SR2_1j0t   = new TH1F("histMET_mumu_SR2_1j0t"  , "p^{miss}_{T} mumu", 15, 0, 1000);

            TH1F *histMT2_mumu_SR3_0t   = new TH1F("histMT2_mumu_SR3_0j0t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_SR3_0t   = new TH1F("histMET_mumu_SR3_0j0t"  , "p^{miss}_{T} mumu", 15, 0, 1000);

            //CRs
            TH1F *histMT2_mumu_CR1_1t   = new TH1F("histMT2_mumu_CR1_1t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_CR1_1t   = new TH1F("histMET_mumu_CR1_1t"  , "p^{miss}_{T} mumu", 15, 0, 1000);

            TH1F *histMT2_mumu_CR2_1t   = new TH1F("histMT2_mumu_CR2_1t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_CR2_1t   = new TH1F("histMET_mumu_CR2_1t"  , "p^{miss}_{T} mumu", 15, 0, 1000);

            TH1F *histMT2_mumu_CR3_1t   = new TH1F("histMT2_mumu_CR3_1t"  , "MT2 mumu"         , 10, 0, 1000);
            TH1F *histMET_mumu_CR3_1t   = new TH1F("histMET_mumu_CR3_1t"  , "p^{miss}_{T} mumu", 15, 0, 1000);

            // emu trigger histograms
            //SRs
            TH1F *histMT2_emu_SR1_0j0t   = new TH1F("histMT2_emu_SR1_0j0t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_SR1_0j0t   = new TH1F("histMET_emu_SR1_0j0t"  , "p^{miss}_{T} emu", 15, 0, 1000);
            TH1F *histMT2_emu_SR1_1j0t   = new TH1F("histMT2_emu_SR1_1j0t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_SR1_1j0t   = new TH1F("histMET_emu_SR1_1j0t"  , "p^{miss}_{T} emu", 15, 0, 1000);
            
            TH1F *histMT2_emu_SR2_0j0t   = new TH1F("histMT2_emu_SR2_0j0t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_SR2_0j0t   = new TH1F("histMET_emu_SR2_0j0t"  , "p^{miss}_{T} emu", 15, 0, 1000);
            TH1F *histMT2_emu_SR2_1j0t   = new TH1F("histMT2_emu_SR2_1j0t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_SR2_1j0t   = new TH1F("histMET_emu_SR2_1j0t"  , "p^{miss}_{T} emu", 15, 0, 1000);

            TH1F *histMT2_emu_SR3_0t   = new TH1F("histMT2_emu_SR3_0j0t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_SR3_0t   = new TH1F("histMET_emu_SR3_0j0t"  , "p^{miss}_{T} emu", 15, 0, 1000);

            //CRs
            TH1F *histMT2_emu_CR1_1t   = new TH1F("histMT2_emu_CR1_1t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_CR1_1t   = new TH1F("histMET_emu_CR1_1t"  , "p^{miss}_{T} emu", 15, 0, 1000);

            TH1F *histMT2_emu_CR2_1t   = new TH1F("histMT2_emu_CR2_1t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_CR2_1t   = new TH1F("histMET_emu_CR2_1t"  , "p^{miss}_{T} emu", 15, 0, 1000);

            TH1F *histMT2_emu_CR3_1t   = new TH1F("histMT2_emu_CR3_1t"  , "MT2 emu"         , 10, 0, 1000);
            TH1F *histMET_emu_CR3_1t   = new TH1F("histMET_emu_CR3_1t"  , "p^{miss}_{T} emu", 15, 0, 1000);
            
            // Loop over all events
            for(UInt_t entry = 0; entry < numberOfEntries; ++entry)
            {
                // print event number in the file
                if(entry%1000 == 0) cout << path << ": " << "Reading Event " << entry << endl;

                // Load selected branches with data from specified event
                treeReader -> ReadEntry(entry); 

                if(branchElectron -> GetEntries() > 0) 
                {
                    Electron  *electron = (Electron*)  branchElectron -> At(0);
                    electronPT.fill(electron -> PT);
                    electronEta.fill(electron -> Eta);
                    electronPhi.fill(electron -> Phi);
                    !electronTrigger;            
                }

                if(branchMuon -> GetEntries() > 0) 
                {
                    Muon *muon = (Muon*) branchMuon -> At(0);
                    muonPT.fill(muon -> PT);
                    muonEta.fill(muon -> Eta);
                    muonPhi.fill(muon -> Phi);
                    !muonTrigger;             
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
                    jetPhi.fill(jet -> Phi);
                    jetMass.fill(jet -> Mass);
                    jetBTag.fill(jet -> BTag);
                    !jetTrigger;                               
                }

                //ee trigger
                if (!electronTrigger)
                {
                    TLorentzVector l1_ee, l2_ee, Missing_ee, dileptons_ee;

                    if (electronPT.at(entry) >= 25 && TMath::Abs(electronEta.at(entry)) < 2.4)
                    {
                        l1_ee. SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0); //use setptetaphiM
                        
                        if (electronPT.at(entry) >= 20 && TMath::Abs(electronEta.at(entry)) < 2.4)
                        {
                            l2_ee. SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);     
                            dileptons_ee = l1_ee + l2_ee;
                            Float_t Mll_ee = TMath::Abs(dileptons_ee.M()*pow(10,7));
                            Missing_ee.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);

                            if (Mll_ee >= 20 && Missing_ee.Pt() >= 140)
                            {
                                if (jetTrigger && jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_ee = Missing_ee.Pt();
                                    ComputeMT2 calcMT2_ee = ComputeMT2(l1_ee, l2_ee, Missing_ee);       
                                    Float_t MT2_ee = calcMT2_ee.Compute();

                                    //SR1
                                    if (PT_miss_ee >= 140 && PT_miss_ee < 200)
                                    { 
                                        histMT2_ee_SR1_0j0t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_SR1_0j0t -> Fill(MT2_ee, weights);
                                    }

                                    //SR2
                                    if (PT_miss_ee >= 200 && PT_miss_ee < 300)
                                    { 
                                        histMT2_ee_SR2_0j0t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_SR2_0j0t -> Fill(MT2_ee, weights);
                                    }
                                }

                                if (!jetTrigger && jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_ee = Missing_ee.Pt();
                                    ComputeMT2 calcMT2_ee = ComputeMT2(l1_ee, l2_ee, Missing_ee);       
                                    Float_t MT2_ee = calcMT2_ee.Compute();
                                
                                    //SR1
                                    if (PT_miss_ee >= 140 && PT_miss_ee < 200)
                                    { 
                                        histMT2_ee_SR1_1j0t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_SR1_1j0t -> Fill(MT2_ee, weights);
                                    }

                                    //SR2
                                    if (PT_miss_ee >= 200 && PT_miss_ee < 300)
                                    { 
                                        histMT2_ee_SR2_1j0t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_SR2_1j0t -> Fill(MT2_ee, weights);
                                    }
                                }

                                if (jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_ee = Missing_ee.Pt();
                                    ComputeMT2 calcMT2_ee = ComputeMT2(l1_ee, l2_ee, Missing_ee);       
                                    Float_t MT2_ee = calcMT2_ee.Compute();
                                
                                    //SR3
                                    if (PT_miss_ee >= 300)
                                    { 
                                        histMT2_ee_SR3_0t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_SR3_0t -> Fill(MT2_ee, weights);
                                    }
                                }

                                if (jetBTag.at(entry) == 1)
                                {
                                    Float_t PT_miss_ee = Missing_ee.Pt();
                                    ComputeMT2 calcMT2_ee = ComputeMT2(l1_ee, l2_ee, Missing_ee);       
                                    Float_t MT2_ee = calcMT2_ee.Compute();
                                
                                    //CR1
                                    if (PT_miss_ee >= 140 && PT_miss_ee < 200)
                                    { 
                                        histMT2_ee_CR1_1t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_CR1_1t -> Fill(MT2_ee, weights);
                                    }

                                    //CR2
                                    if (PT_miss_ee >= 200 && PT_miss_ee < 300)
                                    { 
                                        histMT2_ee_CR2_1t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_CR2_1t -> Fill(MT2_ee, weights);
                                    }

                                    //CR3
                                    if (PT_miss_ee >= 300)
                                    { 
                                        histMT2_ee_CR3_1t -> Fill(PT_miss_ee, weights);
                                        histMET_ee_CR3_1t -> Fill(MT2_ee, weights);
                                    }
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
                        l1_mumu. SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);
                        
                        if (electronPT.at(entry) >= 20 && TMath::Abs(electronEta.at(entry)) < 2.4)
                        {
                            l2_mumu. SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);     
                            dileptons_mumu = l1_mumu + l2_mumu;
                            Float_t Mll_mumu = TMath::Abs(dileptons_mumu.M()*pow(10,7));
                            Missing_mumu.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);
                            
                            if (Mll_mumu >= 20 && Missing_mumu.Pt() >= 140)
                            {
                                if (jetTrigger && jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_mumu = Missing_mumu.Pt();
                                    ComputeMT2 calcMT2_mumu = ComputeMT2(l1_mumu, l2_mumu, Missing_mumu);       
                                    Float_t MT2_mumu = calcMT2_mumu.Compute();

                                    //SR1
                                    if (PT_miss_mumu >= 140 && PT_miss_mumu < 200)
                                    { 
                                        histMT2_mumu_SR1_0j0t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_SR1_0j0t -> Fill(MT2_mumu, weights);
                                    }

                                    //SR2
                                    if (PT_miss_mumu >= 200 && PT_miss_mumu < 300)
                                    {    
                                        histMT2_mumu_SR2_0j0t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_SR2_0j0t -> Fill(MT2_mumu, weights);
                                    }
                                }

                                if (!jetTrigger && jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_mumu = Missing_mumu.Pt();
                                    ComputeMT2 calcMT2_mumu = ComputeMT2(l1_mumu, l2_mumu, Missing_mumu);       
                                    Float_t MT2_mumu = calcMT2_mumu.Compute();
                                
                                    //SR1
                                    if (PT_miss_mumu >= 140 && PT_miss_mumu < 200)
                                    { 
                                        histMT2_mumu_SR1_1j0t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_SR1_1j0t -> Fill(MT2_mumu, weights);
                                    }

                                    //SR2
                                    if (PT_miss_mumu >= 200 && PT_miss_mumu < 300)
                                    { 
                                        histMT2_mumu_SR2_1j0t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_SR2_1j0t -> Fill(MT2_mumu, weights);
                                    }
                                }

                                if (jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_mumu = Missing_mumu.Pt();
                                    ComputeMT2 calcMT2_mumu = ComputeMT2(l1_mumu, l2_mumu, Missing_mumu);       
                                    Float_t MT2_mumu = calcMT2_mumu.Compute();
                                
                                    //SR3
                                    if (PT_miss_mumu >= 300)
                                    { 
                                        histMT2_mumu_SR3_0t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_SR3_0t -> Fill(MT2_mumu, weights);
                                    }
                                }

                                if (jetBTag.at(entry) == 1)
                                {
                                    Float_t PT_miss_mumu = Missing_mumu.Pt();
                                    ComputeMT2 calcMT2_mumu = ComputeMT2(l1_mumu, l2_mumu, Missing_mumu);       
                                    Float_t MT2_mumu = calcMT2_mumu.Compute();
                                
                                    //CR1
                                    if (PT_miss_mumu >= 140 && PT_miss_mumu < 200)
                                    { 
                                        histMT2_mumu_CR1_1t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_CR1_1t -> Fill(MT2_mumu, weights);
                                    }

                                    //CR2
                                    if (PT_miss_mumu >= 200 && PT_miss_mumu < 300)
                                    { 
                                        histMT2_mumu_CR2_1t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_CR2_1t -> Fill(MT2_mumu, weights);
                                    }

                                    //CR3
                                    if (PT_miss_mumu >= 300)
                                    { 
                                        histMT2_mumu_CR3_1t -> Fill(PT_miss_mumu, weights);
                                        histMET_mumu_CR3_1t -> Fill(MT2_mumu, weights);
                                    }
                                } 
                            }       
                        }
                    }            
                }



                //emu trigger
                if (!electronTrigger || !muonTrigger)
                {
                    TLorentzVector l1_emu, l2_emu, Missing_emu, dileptons_emu;

                    if (electronPT.at(entry) >= 25 && TMath::Abs(electronEta.at(entry)) < 2.4)
                    {
                        l1_emu. SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);
                        
                        if (electronPT.at(entry) >= 20 && TMath::Abs(electronEta.at(entry)) < 2.4)
                        {
                            l2_emu. SetPtEtaPhiM(electronPT.at(entry), electronEta.at(entry), electronPhi.at(entry), 0);     
                            dileptons_emu = l1_emu + l2_emu;
                            Float_t Mll_emu = TMath::Abs(dileptons_emu.M()*pow(10,7));
                            Missing_emu.SetPtEtaPhiM(missingMET.at(entry), missingEta.at(entry), missingPhi.at(entry), 0.);
                            
                            if (Mll_emu >= 20 && Missing_emu.Pt() >= 140 )
                            {
                                if (jetTrigger && jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_emu = Missing_emu.Pt();
                                    ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                    Float_t MT2_emu = calcMT2_emu.Compute();

                                    //SR1
                                    if (PT_miss_emu >= 140 && PT_miss_emu < 200)
                                    { 
                                        histMT2_emu_SR1_0j0t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_SR1_0j0t -> Fill(MT2_emu, weights);
                                    }

                                    //SR2
                                    if (PT_miss_emu >= 200 && PT_miss_emu < 300)
                                    { 
                                        histMT2_emu_SR2_0j0t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_SR2_0j0t -> Fill(MT2_emu, weights);
                                    }
                                }

                                if (!jetTrigger && jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_emu = Missing_emu.Pt();
                                    ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                    Float_t MT2_emu = calcMT2_emu.Compute();
                                
                                    //SR1
                                    if (PT_miss_emu >= 140 && PT_miss_emu < 200)
                                    { 
                                        histMT2_emu_SR1_1j0t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_SR1_1j0t -> Fill(MT2_emu, weights);
                                    }

                                    //SR2
                                    if (PT_miss_emu >= 200 && PT_miss_emu < 300)
                                    { 
                                        histMT2_emu_SR2_1j0t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_SR2_1j0t -> Fill(MT2_emu, weights);
                                    }
                                }

                                if (jetBTag.at(entry) == 0)
                                {
                                    Float_t PT_miss_emu = Missing_emu.Pt();
                                    ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                    Float_t MT2_emu = calcMT2_emu.Compute();
                                
                                    //SR3
                                    if (PT_miss_emu >= 300)
                                    { 
                                        histMT2_emu_SR3_0t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_SR3_0t -> Fill(MT2_emu, weights);
                                    }
                                }

                                if (jetBTag.at(entry) == 1)
                                {
                                    Float_t PT_miss_emu = Missing_emu.Pt();
                                    ComputeMT2 calcMT2_emu = ComputeMT2(l1_emu, l2_emu, Missing_emu);       
                                    Float_t MT2_emu = calcMT2_emu.Compute();
                                
                                    //CR1
                                    if (PT_miss_emu >= 140 && PT_miss_emu < 200)
                                    { 
                                        histMT2_emu_CR1_1t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_CR1_1t -> Fill(MT2_emu, weights);
                                    }

                                    //CR2
                                    if (PT_miss_emu >= 200 && PT_miss_emu < 300)
                                    { 
                                        histMT2_emu_CR2_1t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_CR2_1t -> Fill(MT2_emu, weights);
                                    }

                                    //CR3
                                    if (PT_miss_emu >= 300)
                                    { 
                                        histMT2_emu_CR3_1t -> Fill(PT_miss_emu, weights);
                                        histMET_emu_CR3_1t -> Fill(MT2_emu, weights);
                                    }
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

            missingMET.fill(0); 
            missingEta.fill(0); 
            missingPhi.fill(0);

            jetPT.fill(0); 
            jetEta.fill(0);
            jetPhi.fill(0);
            jetMass.fill(0);
            jetBTag.fill(0);
            
 
            file_name << "Hists_" << hist_names << ".root";
            TFile *f = new TFile(file_name.str().c_str(), "RECREATE");
            
            //ee trigger
            //SRs
            histMT2_ee_SR1_0j0t -> Write("", TObject::kOverwrite); 
            histMET_ee_SR1_0j0t -> Write("", TObject::kOverwrite); 
            histMT2_ee_SR1_1j0t -> Write("", TObject::kOverwrite);
            histMET_ee_SR1_1j0t -> Write("", TObject::kOverwrite);
            
            histMT2_ee_SR2_0j0t -> Write("", TObject::kOverwrite);
            histMET_ee_SR2_0j0t -> Write("", TObject::kOverwrite);
            histMT2_ee_SR2_1j0t -> Write("", TObject::kOverwrite);
            histMET_ee_SR2_1j0t -> Write("", TObject::kOverwrite);

            histMT2_ee_SR3_0t -> Write("", TObject::kOverwrite);
            histMET_ee_SR3_0t -> Write("", TObject::kOverwrite);

            //CRs
            histMT2_ee_CR1_1t -> Write("", TObject::kOverwrite);
            histMET_ee_CR1_1t -> Write("", TObject::kOverwrite);

            histMT2_ee_CR2_1t -> Write("", TObject::kOverwrite);
            histMET_ee_CR2_1t -> Write("", TObject::kOverwrite);

            histMT2_ee_CR3_1t -> Write("", TObject::kOverwrite);
            histMET_ee_CR3_1t -> Write("", TObject::kOverwrite);

            //mumu trigger
            //SRs
            histMT2_mumu_SR1_0j0t -> Write("", TObject::kOverwrite); 
            histMET_mumu_SR1_0j0t -> Write("", TObject::kOverwrite); 
            histMT2_mumu_SR1_1j0t -> Write("", TObject::kOverwrite);
            histMET_mumu_SR1_1j0t -> Write("", TObject::kOverwrite);
            
            histMT2_mumu_SR2_0j0t -> Write("", TObject::kOverwrite);
            histMET_mumu_SR2_0j0t -> Write("", TObject::kOverwrite);
            histMT2_mumu_SR2_1j0t -> Write("", TObject::kOverwrite);
            histMET_mumu_SR2_1j0t -> Write("", TObject::kOverwrite);

            histMT2_mumu_SR3_0t -> Write("", TObject::kOverwrite);
            histMET_mumu_SR3_0t -> Write("", TObject::kOverwrite);

            //CRs
            histMT2_mumu_CR1_1t -> Write("", TObject::kOverwrite);
            histMET_mumu_CR1_1t -> Write("", TObject::kOverwrite);

            histMT2_mumu_CR2_1t -> Write("", TObject::kOverwrite);
            histMET_mumu_CR2_1t -> Write("", TObject::kOverwrite);

            histMT2_mumu_CR3_1t -> Write("", TObject::kOverwrite);
            histMET_mumu_CR3_1t -> Write("", TObject::kOverwrite);

            //emu trigger
            //SRs
            histMT2_emu_SR1_0j0t -> Write("", TObject::kOverwrite); 
            histMET_emu_SR1_0j0t -> Write("", TObject::kOverwrite); 
            histMT2_emu_SR1_1j0t -> Write("", TObject::kOverwrite);
            histMET_emu_SR1_1j0t -> Write("", TObject::kOverwrite);
            
            histMT2_emu_SR2_0j0t -> Write("", TObject::kOverwrite);
            histMET_emu_SR2_0j0t -> Write("", TObject::kOverwrite);
            histMT2_emu_SR2_1j0t -> Write("", TObject::kOverwrite);
            histMET_emu_SR2_1j0t -> Write("", TObject::kOverwrite);

            histMT2_emu_SR3_0t -> Write("", TObject::kOverwrite);
            histMET_emu_SR3_0t -> Write("", TObject::kOverwrite);

            //CRs
            histMT2_emu_CR1_1t -> Write("", TObject::kOverwrite);
            histMET_emu_CR1_1t -> Write("", TObject::kOverwrite);

            histMT2_emu_CR2_1t -> Write("", TObject::kOverwrite);
            histMET_emu_CR2_1t -> Write("", TObject::kOverwrite);

            histMT2_emu_CR3_1t -> Write("", TObject::kOverwrite);
            histMET_emu_CR3_1t -> Write("", TObject::kOverwrite);
        }

        virtual ~Analysis() 
        {
            
        };
};

void LastReport_Analysis()
{
    vector<UInt_t> Runs  = {3, 3, 3};
    vector<TString> Datasets   = {"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/signal_try/Events/"
                                  ,"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/ttbar_try/Events/"
                                  ,"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/tW_try/Events/"
                                 };
    vector<TString> Hist_names = {"signal", "ttbar", "tW"};
    vector<Float_t> Weights    = {1       , 1      ,  1};

    Analysis *obj1 = new Analysis();

    for (UInt_t i = 0; i < Datasets.size(); ++i)
    {
        obj1 -> CharginosAnalysis(Datasets.at(i), Hist_names.at(i), Runs.at(i), Weights.at(i));
    }
}
