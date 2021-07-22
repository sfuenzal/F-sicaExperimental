// class ROOTFile
// {
//     protected:
//         TString path;
//         TFile *f;
//     public:
//         ROOTFile(TString path_initializer) 
//         {
//             path = path_initializer;
//         }

//         void OpenROOTFile()
//         {
//             f = TFile::Open(path);
// 			//f -> ls();
//         }

//         virtual ~ROOTFile() {};
// };

// class LoopHistograms: public ROOTFile
// {
//     private:
//         TString leg_names, leg_symbols;
// 		TObject *obj;
// 		TH1 *h;
//         TKey *key;
// 		UInt_t colors;
//         UInt_t counter  = 0;
//         Char_t hname[200];
//     public:
//         LoopHistograms(TString path_initializer) : ROOTFile(path_initializer)
//         {
//             path = path_initializer;
//         }
        
//         void DrawingHistograms()
//         {
//             f = TFile::Open(path);
        
//             gROOT -> SetBatch();
//             TCanvas *c1 = new TCanvas("c1", "", 750, 960, 990, 660);
// 			c1 -> Draw();
// 			c1 -> SetLogy();
// 			THStack *hs = new THStack("hs", "");

// 			TLegend *leg = new TLegend(0.7, 0.70, 0.9, 0.89);
//   			leg -> SetBorderSize(0);
//   			leg -> SetFillColor(0);

//             gStyle -> SetPalette(1); 
//             gStyle -> SetOptStat(0);

//             c1 -> cd();
//             TIter nextkey(gDirectory -> GetListOfKeys());

// 			vector<TString> leg_names   = {"Signal", "WW", "tW", "ttbar"};
//     		vector<TString> leg_symbols = {"LEP"   , "F" , "F" , "F"};
// 			vector<UInt_t>  colors = {0, 416 - 3, 432 - 3, 632 - 3};
            
			
//             while (key = (TKey*) nextkey()) 
//             {
//                 obj = key -> ReadObj();
            
//                 if (obj -> IsA() -> InheritsFrom("TH1")) 
//                 {
//                     if (counter % 2 != 0)
// 					{
// 						h = (TH1F*) obj;
//                  		h -> GetName();
//                 		leg -> AddEntry(h -> GetName(), leg_names.at(i), leg_symbols.at(i));
// 						hs -> Add(h);
// 						h -> SetLineColor(kBlack);
// 						h -> SetFillColor(counter);
// 						hs -> Draw();
// 						h -> Draw("same");
// 						leg -> Draw();
// 						sprintf(hname, "%s_trial.png", h -> GetName());
// 						c1 -> SaveAs(hname);
//             			c1 -> Clear();
// 						c1 -> Modified();
// 					}									
//                 }
                
// 				++counter;
//             }

			
//         }

//         ~LoopHistograms() {};
// };


void ThirdReport_Plotting()
{
	//vector<TString> input_histograms = {"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/ThirdReport/Code/Hists_signal_try.root",
										//"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/ThirdReport/Code/Hists_ttbar_try.root",
										//"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/ThirdReport/Code/Hists_TW_try.root",
										//"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/ThirdReport/Code/Hists_WW_try.root",};
								
	// TString input_histogram = "/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/ThirdReport/Code/Hists_signal_try.root";

	// ROOTFile *obj1 = new ROOTFile(input_histogram);
    // obj1 -> OpenROOTFile();

    // LoopHistograms *obj2 = new LoopHistograms(input_histogram);
    // obj2 -> DrawingHistograms();
	

	
	TFile *f1 = TFile::Open("Hists_signal_try.root", "READ");
  	TFile *f2 = TFile::Open("Hists_WW_try.root"    , "READ");
  	TFile *f3 = TFile::Open("Hists_TW_try.root"    , "READ");
	TFile *f4 = TFile::Open("Hists_ttbar_try.root" , "READ");

	TCanvas *c = new TCanvas("c1", "c1", 1024, 800);

  	TH1F *histMT2_Signal   = (TH1F*) f1 -> Get("histMT2");
  	TH1F *histMT2_WW       = (TH1F*) f2 -> Get("histMT2");
  	TH1F *histMT2_TW       = (TH1F*) f3 -> Get("histMT2");
	TH1F *histMT2_ttbar    = (TH1F*) f4 -> Get("histMT2");

  	THStack *hs_histMT2 = new THStack("hs_histMT2", "");

  	TLegend *leg_histMT2 = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMT2 -> SetBorderSize(0);
  	leg_histMT2 -> SetFillColor(0);

  	leg_histMT2 -> AddEntry(histMT2_Signal , "Signal" , "LEP");
  	leg_histMT2 -> AddEntry(histMT2_WW, "WW", "F");
	leg_histMT2 -> AddEntry(histMT2_TW, "tW", "F");
  	leg_histMT2 -> AddEntry(histMT2_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMT2_Signal  -> SetLineColor(kBlack);
  	histMT2_Signal  -> Scale((histMT2_WW -> Integral() + histMT2_TW -> Integral() + histMT2_ttbar -> Integral())/histMT2_Signal -> Integral());
  	histMT2_WW -> SetLineColor(kBlack);
  	histMT2_WW -> SetFillColor(kGreen - 3);
	histMT2_TW -> SetLineColor(kBlack);
  	histMT2_TW -> SetFillColor(kCyan - 3);
  	histMT2_ttbar    -> SetLineColor(kBlack);
  	histMT2_ttbar    -> SetFillColor(kRed - 3);

  	hs_histMT2 -> Add(histMT2_WW);
  	hs_histMT2 -> Add(histMT2_TW);
	hs_histMT2 -> Add(histMT2_ttbar);

  	hs_histMT2 -> Draw("Hist");
  	//hs_histMT2 -> SetTitle("MT2");
  	hs_histMT2 -> GetXaxis() -> SetTitle("m_{T2} [GeV]");
  	hs_histMT2 -> GetYaxis() -> SetTitle("Entries");
  	hs_histMT2 -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMT2 -> Draw();
  	histMT2_Signal -> Draw("same:e1");

  	c -> SaveAs("histMT2.png");

	c -> Clear();
  	c -> Modified();

	TH1F *histMET_Signal   = (TH1F*) f1 -> Get("histMET");
  	TH1F *histMET_WW       = (TH1F*) f2 -> Get("histMET");
  	TH1F *histMET_TW       = (TH1F*) f3 -> Get("histMET");
	TH1F *histMET_ttbar    = (TH1F*) f4 -> Get("histMET");

  	THStack *hs_histMET = new THStack("hs_histMET", "");

  	TLegend *leg_histMET = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMET -> SetBorderSize(0);
  	leg_histMET -> SetFillColor(0);

  	leg_histMET -> AddEntry(histMET_Signal , "Signal" , "LEP");
  	leg_histMET -> AddEntry(histMET_WW, "WW", "F");
	leg_histMET -> AddEntry(histMET_TW, "tW", "F");
  	leg_histMET -> AddEntry(histMET_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMET_Signal  -> SetLineColor(kBlack);
  	histMET_Signal  -> Scale((histMET_WW -> Integral() + histMET_TW -> Integral() + histMET_ttbar -> Integral())/histMET_Signal -> Integral());
  	histMET_WW -> SetLineColor(kBlack);
  	histMET_WW -> SetFillColor(kGreen - 3);
	histMET_TW -> SetLineColor(kBlack);
  	histMET_TW -> SetFillColor(kCyan - 3);
  	histMET_ttbar    -> SetLineColor(kBlack);
  	histMET_ttbar    -> SetFillColor(kRed - 3);

  	hs_histMET -> Add(histMET_WW);
  	hs_histMET -> Add(histMET_TW);
	hs_histMET -> Add(histMET_ttbar);

  	hs_histMET -> Draw("Hist");
  	//hs_histMET -> SetTitle("MET");
  	hs_histMET -> GetXaxis() -> SetTitle("p^{T}_{miss} [GeV]");
  	hs_histMET -> GetYaxis() -> SetTitle("Entries");
  	hs_histMET -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMET -> Draw();
  	histMET_Signal -> Draw("same:e1");

  	c -> SaveAs("histPTMiss.png");

}


