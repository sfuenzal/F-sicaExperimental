class ROOTFile
{
    protected:
        TString path;
        TFile *f;
    public:
        ROOTFile(TString path_initializer) 
        {
            path = path_initializer;
        }

        void OpenROOTFile()
        {
            f = TFile::Open(path);
			f -> ls();
        }

        virtual ~ROOTFile() {};
};

class LoopHistograms: public ROOTFile
{
    private:
        TString leg_names, leg_symbols;
		TObject *obj;
		TH1 *h;
        TKey *key;
		UInt_t color;
        UInt_t counter  = 0;
        Char_t hname_aux[200];
		Char_t hname_histograms[200];
    public:
        LoopHistograms(TString path_initializer, TString leg_names_initializer, TString leg_symbols_initializer, UInt_t color_initializer) : ROOTFile(path_initializer)
        {
            path = path_initializer;
			leg_names = leg_names_initializer;
			leg_symbols = leg_symbols_initializer;
			color = color_initializer;
        }
        
        void DrawingHistograms(Char_t *hists_names)
        {
			f = TFile::Open(path);
        
            gROOT -> SetBatch();
        
			TLegend *leg = new TLegend(0.7, 0.70, 0.9, 0.89);
  			leg -> SetBorderSize(0);
  			leg -> SetFillColor(0);

            gStyle -> SetPalette(1); 
            gStyle -> SetOptStat(0);

			TIter nextkey(gDirectory -> GetListOfKeys());

            while (key = (TKey*) nextkey()) 
            {
                obj = key -> ReadObj();
            
                if (obj -> IsA() -> InheritsFrom("TH1")) 
                {
					h = (TH1F*) obj;
					sprintf(hname_aux, "%s", h -> GetName());
					
					if(strcmp (hname_aux, hists_names) == 0)
					{	
						if (path != (TString) "Hists_signal.root" && leg_names != (TString) "Signal" && leg_symbols != (TString) "LEP" && color != 0)  
						{
							//THStack *hs = new THStack("hs", "");
							leg -> AddEntry(h, leg_names, leg_symbols);
							h -> SetLineColor(kBlack);
							h -> SetFillColor(color);
							//hs -> Add(h);
							h -> Draw("same");
							//hs -> Draw("hist");
						}

						if (path == (TString) "Hists_signal.root" && leg_names == (TString) "Signal" && leg_symbols == (TString) "LEP" && color == 0)
						{
							leg -> AddEntry(h, leg_names, leg_symbols);
							h -> SetLineColor(kBlack);
							h -> SetFillColor(color);
							h -> Draw("same:e1");
						}

						leg -> Draw();
					}
				

					++counter;				
                }	
            }			
        }

        ~LoopHistograms() {};
};


void LastReport_Plotting()
{
	vector<TString> input_histograms_files = {"Hists_signal.root", "Hists_ttbar.root", "Hists_tW.root"};
	vector<TString> leg_names              = {"Signal", "ttbar", "tW"};
    vector<TString> leg_symbols            = {"LEP"   , "F" , "F"};
	vector<UInt_t>  colors                 = {0, 416 - 3, 432 - 3};

	Char_t histMT2_ee_SR1_0j0t[] = "histMT2_ee_SR1_0j0t";
	Char_t histMET_ee_SR1_0j0t[] = "histMET_ee_SR1_0j0t";
	Char_t histMT2_ee_SR1_1j0t[] = "histMT2_ee_SR1_1j0t";
    Char_t histMET_ee_SR1_1j0t[] = "histMET_ee_SR1_1j0t";  
    Char_t histMT2_ee_SR2_0j0t[] = "histMT2_ee_SR2_0j0t";  
    Char_t histMET_ee_SR2_0j0t[] = "histMET_ee_SR2_0j0t";  
    Char_t histMT2_ee_SR2_1j0t[] = "histMT2_ee_SR2_1j0t";  
    Char_t histMET_ee_SR2_1j0t[] = "histMET_ee_SR2_1j0t";  
    Char_t histMT2_ee_SR3_0t[] = "histMT2_ee_SR3_0t";  
    Char_t histMET_ee_SR3_0t[] = "histMET_ee_SR3_0t";     
    Char_t histMT2_ee_CR1_1t[] = "histMT2_ee_CR1_1t";  
    Char_t histMET_ee_CR1_1t[] = "histMET_ee_CR1_1t";  
    Char_t histMT2_ee_CR2_1t[] = "histMT2_ee_CR2_1t";  
    Char_t histMET_ee_CR2_1t[] = "histMET_ee_CR2_1t";  
    Char_t histMT2_ee_CR3_1t[] = "histMT2_ee_CR3_1t";  
    Char_t histMET_ee_CR3_1t[] = "histMET_ee_CR3_1t";  

            
    Char_t histMT2_mumu_SR1_0j0t [] = "histMT2_mumu_SR1_0j0t";  
    Char_t histMET_mumu_SR1_0j0t [] = "histMET_mumu_SR1_0j0t";  
    Char_t histMT2_mumu_SR1_1j0t [] = "histMT2_mumu_SR1_1j0t"; 
    Char_t histMET_mumu_SR1_1j0t [] = "histMET_mumu_SR1_1j0t";   
    Char_t histMT2_mumu_SR2_0j0t [] = "histMT2_mumu_SR2_0j0t"; 
    Char_t histMET_mumu_SR2_0j0t [] = "histMET_mumu_SR2_0j0t"; 
    Char_t histMT2_mumu_SR2_1j0t [] = "histMT2_mumu_SR2_1j0t"; 
    Char_t histMET_mumu_SR2_1j0t [] = "histMET_mumu_SR2_1j0t"; 
	Char_t histMT2_mumu_SR3_0t [] = "histMT2_mumu_SR3_0t"; 
    Char_t histMET_mumu_SR3_0t [] = "histMET_mumu_SR3_0t"; 
    Char_t histMT2_mumu_CR1_1t [] = "histMT2_mumu_CR1_1t"; 
    Char_t histMET_mumu_CR1_1t [] = "histMET_mumu_CR1_1t"; 
    Char_t histMT2_mumu_CR2_1t [] = "histMT2_mumu_CR2_1t"; 
    Char_t histMET_mumu_CR2_1t [] = "histMET_mumu_CR2_1t"; 
    Char_t histMT2_mumu_CR3_1t [] = "histMT2_mumu_CR3_1t";
    Char_t histMET_mumu_CR3_1t [] = "histMET_mumu_CR3_1t"; 

         
    Char_t histMT2_emu_SR1_0j0t [] = "histMT2_emu_SR1_0j0t";  
    Char_t histMET_emu_SR1_0j0t [] = "histMET_emu_SR1_0j0t";
    Char_t histMT2_emu_SR1_1j0t [] = "histMT2_emu_SR1_1j0t";  
    Char_t histMET_emu_SR1_1j0t [] = "histMET_emu_SR1_1j0t";  
    Char_t histMT2_emu_SR2_0j0t [] = "histMT2_emu_SR2_0j0t";  
    Char_t histMET_emu_SR2_0j0t [] = "histMET_emu_SR2_0j0t";  
    Char_t histMT2_emu_SR2_1j0t [] = "histMT2_emu_SR2_1j0t";  
    Char_t histMET_emu_SR2_1j0t [] = "histMET_emu_SR2_1j0t"; 
    Char_t histMT2_emu_SR3_0t [] = "histMT2_emu_SR3_0t";  
    Char_t histMET_emu_SR3_0t [] = "histMET_emu_SR3_0t";  
    Char_t histMT2_emu_CR1_1t [] = "histMT2_emu_CR1_1t";  
    Char_t histMET_emu_CR1_1t [] = "histMET_emu_CR1_1t"; 
    Char_t histMT2_emu_CR2_1t [] = "histMT2_emu_CR2_1t";  
    Char_t histMET_emu_CR2_1t [] = "histMET_emu_CR2_1t";  
    Char_t histMT2_emu_CR3_1t [] = "histMT2_emu_CR3_1t";  
    Char_t histMET_emu_CR3_1t [] = "histMET_emu_CR3_1t";  


	Char_t *aux[] = { 	histMT2_ee_SR1_0j0t,
					  	histMET_ee_SR1_0j0t,
					  	histMT2_ee_SR1_1j0t,
    					histMET_ee_SR1_1j0t, 
    					histMT2_ee_SR2_0j0t,
    					histMET_ee_SR2_0j0t,
    					histMT2_ee_SR2_1j0t,
    					histMET_ee_SR2_1j0t,  
    					histMT2_ee_SR3_0t,
    					histMET_ee_SR3_0t,    
    					histMT2_ee_CR1_1t,
    					histMET_ee_CR1_1t,  
    					histMT2_ee_CR2_1t, 
    					histMET_ee_CR2_1t,
    					histMT2_ee_CR3_1t,  
    					histMET_ee_CR3_1t,


						histMT2_mumu_SR1_0j0t,
					  	histMET_mumu_SR1_0j0t,
					  	histMT2_mumu_SR1_1j0t,
    					histMET_mumu_SR1_1j0t, 
    					histMT2_mumu_SR2_0j0t,
    					histMET_mumu_SR2_0j0t,
    					histMT2_mumu_SR2_1j0t,
    					histMET_mumu_SR2_1j0t,  
    					histMT2_mumu_SR3_0t,
    					histMET_mumu_SR3_0t,    
    					histMT2_mumu_CR1_1t,
    					histMET_mumu_CR1_1t,  
    					histMT2_mumu_CR2_1t, 
    					histMET_mumu_CR2_1t,
    					histMT2_mumu_CR3_1t,  
    					histMET_mumu_CR3_1t,

						histMT2_emu_SR1_0j0t,
					  	histMET_emu_SR1_0j0t,
					  	histMT2_emu_SR1_1j0t,
    					histMET_emu_SR1_1j0t, 
    					histMT2_emu_SR2_0j0t,
    					histMET_emu_SR2_0j0t,
    					histMT2_emu_SR2_1j0t,
    					histMET_emu_SR2_1j0t,  
    					histMT2_emu_SR3_0t,
    					histMET_emu_SR3_0t,    
    					histMT2_emu_CR1_1t,
    					histMET_emu_CR1_1t,  
    					histMT2_emu_CR2_1t, 
    					histMET_emu_CR2_1t,
    					histMT2_emu_CR3_1t,  
    					histMET_emu_CR3_1t  
					};

	for (UInt_t i = 0; i < input_histograms_files.size(); ++i)
	{
		ROOTFile *obj1 = new ROOTFile(input_histograms_files.at(i));
    	obj1 -> OpenROOTFile();
	}

	for (UInt_t i = 0; i < sizeof(aux)/sizeof(aux[0]); ++i)
	{
		TCanvas *c1 = new TCanvas("c1", "", 750, 960, 990, 660);
		c1 -> Draw();
		c1 -> SetLogy();

		for (UInt_t j = 0; j < input_histograms_files.size(); ++j)
		{    	
			LoopHistograms *obj2 = new LoopHistograms(input_histograms_files.at(j), leg_names.at(j), leg_symbols.at(j), colors.at(j));
    		obj2 -> DrawingHistograms(aux[i]);
		} 							
	
		c1 -> SaveAs((TString) aux[i] + (TString) ".png");
		c1 -> Clear();
	}
}


