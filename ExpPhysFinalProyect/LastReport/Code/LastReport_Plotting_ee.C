void LastReport_Plotting_ee()
{
    UInt_t scale = 100;
	
	TFile *f1 = TFile::Open("Hists_signal.root", "READ");
  	TFile *f2 = TFile::Open("Hists_tW.root"    , "READ");
	TFile *f3 = TFile::Open("Hists_ttbar.root" , "READ");

    TCanvas *c = new TCanvas("c1", "c1", 1024, 800);

    TH1F *histMT2_ee_1j0t_signal    = (TH1F*) f1 -> Get("histMT2_ee_1j0t");
  	TH1F *histMT2_ee_1j0t_tW        = (TH1F*) f2 -> Get("histMT2_ee_1j0t");
	TH1F *histMT2_ee_1j0t_ttbar     = (TH1F*) f3 -> Get("histMT2_ee_1j0t");

    THStack *hs_histMT2_ee_1j0t = new THStack("hs_histMT2_ee_1j0t", "");
    
    TLegend *leg_histMT2_ee_1j0t = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMT2_ee_1j0t -> SetBorderSize(0);
  	leg_histMT2_ee_1j0t -> SetFillColor(0);
   
    leg_histMT2_ee_1j0t -> AddEntry(histMT2_ee_1j0t_signal  , "Signal" , "F");
	leg_histMT2_ee_1j0t -> AddEntry(histMT2_ee_1j0t_tW      , "tW"     , "F");
  	leg_histMT2_ee_1j0t -> AddEntry(histMT2_ee_1j0t_ttbar   , "ttbar"  , "F");

    c -> Draw();
  	c -> SetLogy();

    histMT2_ee_1j0t_signal   -> SetLineColor(kBlack);
	//histMT2_ee_1j0t_signal  -> Scale((histMT2_ee_1j0t_tW -> Integral() + histMT2_ee_1j0t_ttbar -> Integral())/histMT2_ee_1j0t_signal -> Integral());
	histMT2_ee_1j0t_signal  -> Scale(scale);
	histMT2_ee_1j0t_tW       -> SetLineColor(kBlack);
  	histMT2_ee_1j0t_tW       -> SetFillColor(kCyan - 3);
  	histMT2_ee_1j0t_ttbar    -> SetLineColor(kBlack);
  	histMT2_ee_1j0t_ttbar    -> SetFillColor(kRed - 3);  

	hs_histMT2_ee_1j0t -> Add(histMT2_ee_1j0t_ttbar);
    hs_histMT2_ee_1j0t -> Add(histMT2_ee_1j0t_tW);

    hs_histMT2_ee_1j0t     -> Draw("Hist");
  	hs_histMT2_ee_1j0t     -> SetTitle("m_{T2} ee trigger 1j0t");
  	hs_histMT2_ee_1j0t     -> GetXaxis() -> SetTitle("m_{T2} [GeV]");
  	hs_histMT2_ee_1j0t     -> GetYaxis() -> SetTitle("Entries");
  	hs_histMT2_ee_1j0t     -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMT2_ee_1j0t    -> Draw();
  	histMT2_ee_1j0t_signal -> Draw("same");

  	c -> SaveAs("histMT2_ee_1j0t.png");

	c -> Clear();
  	c -> Modified();

    TH1F *histMT2_ee_1j1t_signal    = (TH1F*) f1 -> Get("histMT2_ee_1j1t");
  	TH1F *histMT2_ee_1j1t_tW        = (TH1F*) f2 -> Get("histMT2_ee_1j1t");
	TH1F *histMT2_ee_1j1t_ttbar     = (TH1F*) f3 -> Get("histMT2_ee_1j1t");

    THStack *hs_histMT2_ee_1j1t = new THStack("hs_histMT2_ee_1j1t", "");
    
    TLegend *leg_histMT2_ee_1j1t = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMT2_ee_1j1t -> SetBorderSize(0);
  	leg_histMT2_ee_1j1t -> SetFillColor(0);
   
    leg_histMT2_ee_1j1t -> AddEntry(histMT2_ee_1j1t_signal  , "Signal" , "F");
	leg_histMT2_ee_1j1t -> AddEntry(histMT2_ee_1j1t_tW      , "tW"     , "F");
  	leg_histMT2_ee_1j1t -> AddEntry(histMT2_ee_1j1t_ttbar   , "ttbar"  , "F");

    c -> Draw();
  	c -> SetLogy();

    histMT2_ee_1j1t_signal   -> SetLineColor(kBlack);
	//histMT2_ee_1j1t_signal  -> Scale((histMT2_ee_1j1t_tW -> Integral() + histMT2_ee_1j1t_ttbar -> Integral())/histMT2_ee_1j1t_signal -> Integral());
	histMT2_ee_1j1t_signal -> Scale(scale);
	histMT2_ee_1j1t_tW       -> SetLineColor(kBlack);
  	histMT2_ee_1j1t_tW       -> SetFillColor(kCyan - 3);
  	histMT2_ee_1j1t_ttbar    -> SetLineColor(kBlack);
  	histMT2_ee_1j1t_ttbar    -> SetFillColor(kRed - 3);  

	hs_histMT2_ee_1j1t -> Add(histMT2_ee_1j1t_ttbar);
    hs_histMT2_ee_1j1t -> Add(histMT2_ee_1j1t_tW);

    hs_histMT2_ee_1j1t     -> Draw("Hist");
  	hs_histMT2_ee_1j1t     -> SetTitle("m_{T2} ee trigger 1j1t");
  	hs_histMT2_ee_1j1t     -> GetXaxis() -> SetTitle("m_{T2} [GeV]");
  	hs_histMT2_ee_1j1t     -> GetYaxis() -> SetTitle("Entries");
  	hs_histMT2_ee_1j1t     -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMT2_ee_1j1t    -> Draw();
  	histMT2_ee_1j1t_signal -> Draw("same");

  	c -> SaveAs("histMT2_ee_1j1t.png");

	c -> Clear();
  	c -> Modified();

    TH1F *histMET_ee_signal    = (TH1F*) f1 -> Get("histMET_ee");
  	TH1F *histMET_ee_tW        = (TH1F*) f2 -> Get("histMET_ee");
	TH1F *histMET_ee_ttbar     = (TH1F*) f3 -> Get("histMET_ee");

    THStack *hs_histMET_ee = new THStack("hs_histMET_ee", "");
    
    TLegend *leg_histMET_ee = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMET_ee -> SetBorderSize(0);
  	leg_histMET_ee -> SetFillColor(0);
   
    leg_histMET_ee -> AddEntry(histMET_ee_signal  , "Signal" , "F");
	leg_histMET_ee -> AddEntry(histMET_ee_tW      , "tW"     , "F");
  	leg_histMET_ee -> AddEntry(histMET_ee_ttbar   , "ttbar"  , "F");

    c -> Draw();
  	c -> SetLogy();

    histMET_ee_signal   -> SetLineColor(kBlack);
	//histMET_ee_signal  -> Scale((histMET_ee_tW -> Integral() + histMET_ee_ttbar -> Integral())/histMET_ee_signal -> Integral());
	histMET_ee_signal -> Scale(scale);
	histMET_ee_tW       -> SetLineColor(kBlack);
  	histMET_ee_tW       -> SetFillColor(kCyan - 3);
  	histMET_ee_ttbar    -> SetLineColor(kBlack);
  	histMET_ee_ttbar    -> SetFillColor(kRed - 3);  

	hs_histMET_ee -> Add(histMET_ee_ttbar);
    hs_histMET_ee -> Add(histMET_ee_tW);

    hs_histMET_ee     -> Draw("Hist");
  	hs_histMET_ee     -> SetTitle("p^{miss}_{T} ee trigger");
  	hs_histMET_ee     -> GetXaxis() -> SetTitle("p^{miss}_{T} [GeV]");
  	hs_histMET_ee     -> GetYaxis() -> SetTitle("Entries");
  	hs_histMET_ee     -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMET_ee    -> Draw();
  	histMET_ee_signal -> Draw("same");

  	c -> SaveAs("histMET_ee.png");
}