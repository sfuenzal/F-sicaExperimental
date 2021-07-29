void LastReport_Plotting_Trial()
{
	TFile *f;
	TObject *obj;
	//TH1 *h1, *h2, *h3;
	TH1 *h;
    TKey *key;
	
    UInt_t counter  = 0;
    Char_t hname_aux[200];
	Char_t hname_histograms[200];
	
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
    	
						histMT2_emu_SR1_0j0t,
					  	histMET_emu_SR1_0j0t,
					  	histMT2_emu_SR1_1j0t,
    					histMET_emu_SR1_1j0t, 
    					histMT2_emu_SR2_0j0t,
    					histMET_emu_SR2_0j0t,
    					histMT2_emu_SR2_1j0t,
    					histMET_emu_SR2_1j0t,  
    					histMT2_emu_SR3_0t,
    					histMET_emu_SR3_0t 
					};

	vector<THStack*> stacks_variables;
	vector<THStack*> Stacks;

	for (UInt_t i = 0; i < sizeof(aux)/sizeof(aux[0]); ++i)
	{
		Stacks.push_back(new THStack("hs" + (TString) "_" + (TString) to_string(i), ""));
	}

	vector<TString> input_histograms_files = {"Hists_signal.root", "Hists_ttbar.root", "Hists_tW.root"};
	vector<TString> leg_names              = {"Signal", "ttbar", "tW"};
    vector<TString> leg_symbols            = {"LEP"   , "F" , "F"};
	vector<UInt_t>  colors                 = {0, 416 - 3, 432 - 3};

	THStack *hs1;
	THStack *hs2;
	THStack *hs3;
	THStack *hs4;
	THStack *hs5;
	THStack *hs6;
	THStack *hs7;
	THStack *hs8;
	THStack *hs9;
	THStack *hs10;
	THStack *hs11;
	THStack *hs12;
	THStack *hs13;
	THStack *hs14;
	THStack *hs15;
	THStack *hs16;
	THStack *hs17;
	THStack *hs18;
	THStack *hs19;
	THStack *hs20;
	THStack *hs21;
	THStack *hs22;
	THStack *hs23;
	THStack *hs24;
	THStack *hs25;
	THStack *hs26;
	THStack *hs27;
	THStack *hs28;
	THStack *hs29;
	THStack *hs30;
	THStack *hs31;

	stacks_variables.push_back(hs1);
	stacks_variables.push_back(hs2);
	stacks_variables.push_back(hs3);
	stacks_variables.push_back(hs4);
	stacks_variables.push_back(hs5);
	stacks_variables.push_back(hs6);
	stacks_variables.push_back(hs7);
	stacks_variables.push_back(hs8);
	stacks_variables.push_back(hs9);
	stacks_variables.push_back(hs10);
	stacks_variables.push_back(hs11);
	stacks_variables.push_back(hs13);
	stacks_variables.push_back(hs14);
	stacks_variables.push_back(hs15);
	stacks_variables.push_back(hs16);
	stacks_variables.push_back(hs17);
	stacks_variables.push_back(hs18);
	stacks_variables.push_back(hs19);
	stacks_variables.push_back(hs20);
	stacks_variables.push_back(hs21);
	stacks_variables.push_back(hs22);
	stacks_variables.push_back(hs23);
	stacks_variables.push_back(hs24);
	stacks_variables.push_back(hs25);
	stacks_variables.push_back(hs26);
	stacks_variables.push_back(hs27);
	stacks_variables.push_back(hs28);
	stacks_variables.push_back(hs29);
	stacks_variables.push_back(hs30);
	stacks_variables.push_back(hs31);

	for (UInt_t i = 0; i < sizeof(aux)/sizeof(aux[0]); ++i)	
	{
		TCanvas *c1 = new TCanvas("c1", "", 750, 960, 990, 660);
		c1 -> cd();
		c1 -> Draw();
		//c1 -> SetLogy();

		stacks_variables.at(i) = Stacks.at(i);

		TLegend *leg = new TLegend(0.7, 0.70, 0.9, 0.89);
  		leg -> SetBorderSize(0);
  		leg -> SetFillColor(0);
		
		for (UInt_t j = 0; j < input_histograms_files.size(); ++j)
		{
			f = TFile::Open(input_histograms_files.at(j));
    		gROOT -> SetBatch();	

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
					
					if(strcmp (hname_aux, aux[i]) == 0)
					{					
						if (input_histograms_files.at(j) == (TString) "Hists_tW.root" && leg_names.at(j) == (TString) "tW" && leg_symbols.at(j) == (TString) "F" && colors.at(j) == 432 - 3)  
						{
							leg -> AddEntry(h, leg_names.at(j), leg_symbols.at(j));
							h -> SetLineColor(kBlack);
							h -> SetFillColor(colors.at(j));
							h -> Draw("same");
							
						}

						else if (input_histograms_files.at(j) == (TString) "Hists_ttbar.root" && leg_names.at(j) == (TString) "ttbar" && leg_symbols.at(j) == (TString) "F" && colors.at(j) == 416 - 3)  
						{
							leg -> AddEntry(h, leg_names.at(j), leg_symbols.at(j));
							h -> SetLineColor(kBlack);
							h -> SetFillColor(colors.at(j));
							h -> Draw("same");
							//hs -> Add(h2);
						}

						else if (input_histograms_files.at(j) == (TString) "Hists_signal.root" && leg_names.at(j) == (TString) "Signal" && leg_symbols.at(j) == (TString) "LEP" && colors.at(j) == 0)  
						{
							leg -> AddEntry(h, leg_names.at(j), leg_symbols.at(j));
							h -> SetLineColor(kBlack);
							h -> SetFillColor(colors.at(j));
							h -> Draw("same");
						}					 		
					}

					++counter;				
        		}	
    		}
		
		}

		//stacks_variables.at(i) -> Add(h1);
		//stacks_variables.at(i) -> Add(h2);
		//stacks_variables.at(i) -> Draw();
		leg -> Draw();
		//h3 -> Draw("same:e1");
		
		c1 -> SaveAs((TString) aux[i] + (TString) ".png");
		c1 -> Clear();
		c1 -> Update();
	}
}


