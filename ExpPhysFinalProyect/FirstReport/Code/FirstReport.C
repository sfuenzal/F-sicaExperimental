#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string>

#include <TTree.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TH1F.h"   
#include "TLegend.h"
#include "TFile.h"  
#include "TArrow.h"
#include "TLatex.h"
#include "TMath.h"
#include "TMultiGraph.h"

using namespace std;

class Open
{
    public:
        void OpenROOTFile()
        {
            TString path = "/user/e/exphys02/ExpPhysFinalProyect/chargino_pair_production_electron_case/Data/output_simulated_data_one/Events/";

            TChain *fChain = new TChain("LHEF");
	
            fChain -> AddFile(path + "run_01" + "/" + "unweighted_events.root");
            
	    for (unsigned int i = 0; i < 3; ++i) 
            {
                fChain -> AddFile(path + "run_01_" + to_string(i) + "/" + "unweighted_events.root");
            }

            unsigned int nentries = (unsigned int) fChain -> GetEntries();
            cout << "Total number of entries to analyse: " << nentries << endl;
            cout << "" << endl;
  
	    for(unsigned int i = 0; i < 1; ++i)
            {
                fChain -> Show(i);
            }
            
            //Need this to correctly read TTree branches
            fChain -> SetMakeClass(1);
            fChain -> SetBranchStatus("*", 0);

            //Define local variables to store tree branches 
            Int_t Particle_;
            fChain -> SetBranchStatus("Particle" , 1);
            fChain -> SetBranchAddress("Particle", &Particle_);
            
            const Int_t MaxNParticles = 50;
            Double_t E[MaxNParticles];
            Double_t Pt[MaxNParticles];
            Double_t Eta[MaxNParticles];
            Double_t Phi[MaxNParticles];
	    Double_t M[MaxNParticles];	
            Int_t PID[MaxNParticles];

            //Read TTree Branches
            fChain -> SetBranchStatus("Particle.E" , 1);
            fChain -> SetBranchAddress("Particle.E", &E);
            
            fChain -> SetBranchStatus("Particle.PT" , 1);
            fChain -> SetBranchAddress("Particle.PT", &Pt);
            
            fChain -> SetBranchStatus("Particle.Eta" , 1);
            fChain -> SetBranchAddress("Particle.Eta", &Eta);
            
            fChain -> SetBranchStatus("Particle.Phi" , 1);
            fChain -> SetBranchAddress("Particle.Phi", &Phi);
            
            fChain -> SetBranchStatus("Particle.PID" , 1);
            fChain -> SetBranchAddress("Particle.PID", &PID);
		
            fChain -> SetBranchStatus("Particle.M" , 1);
            fChain -> SetBranchAddress("Particle.M", &M);		
	   	    
            TH1F *h1 = new TH1F("h1", "Energy; E [GeV]; Events", 50, 0, 1000);
            TH1F *h2 = new TH1F("h2", "Transversal momenta; P_{T} [GeV]; Events", 50, 0, 1000);
            TH1F *h3 = new TH1F("h3", "Pseudo rapidity; #eta; Events", 50, -5, 5);
	    TH1F *h4 = new TH1F("h4", "Azimuthal angle; #phi; Events", 50, -5, 5);  
	    TH1F *h5 = new TH1F("h5", "Chargino mass; M [GeV]; Events", 50, 0, 1000);            

            //Loop over events
            for(Long64_t i = 0; i < fChain -> GetEntries(); ++i) 
            {
            	fChain -> GetEntry(i);
		TLorentzVector chargino (0,0,0,0);
                //Loop over particles
      		for (Int_t j = 0; j < Particle_; j++) 
		{
			h1 -> Fill(E[j]);
			h2 -> Fill(Pt[j]);
			h3 -> Fill(Eta[j]);
			h4 -> Fill(Phi[j]);
			cout << PID[j] << endl;
			if(std::abs(PID[j]) == 1000024)
			{
            			TLorentzVector temp;
            			temp.SetPtEtaPhiE(Pt[j], Eta[j], Phi[j], E[j]);
            			chargino += temp;
				cout << "M = " << chargino.M() << endl;
				h5 -> Fill(chargino.M());
      			}
      		}            
             }
          
         TCanvas *c1 = new TCanvas("c1", "c1", 1024, 800);
	 h1 -> Draw("e1");
         c1 -> Print("E.png");
	 
         TCanvas *c2 = new TCanvas("c2", "c2", 1024, 800);
         h2 -> Draw("e1");
       	 c2 -> Print("Pt.png");

         TCanvas *c3 = new TCanvas("c3", "c3", 1024, 800);         
         h3 -> Draw("e1");
       	 c3 -> Print("Eta.png");
         
         TCanvas *c4 = new TCanvas("c4", "c4", 1024, 800);
         h4 -> Draw("e1");
       	 c4 -> Print("Phi.png");
	
         TCanvas *c5 = new TCanvas("c5", "c5", 1024, 800);
         h5 -> Draw("e1");
         c5 -> Print("Chargino_mass.png");

       
	}
};

void FirstReport()
{
    Open *obj1 = new Open();
    obj1 -> OpenROOTFile();
}
