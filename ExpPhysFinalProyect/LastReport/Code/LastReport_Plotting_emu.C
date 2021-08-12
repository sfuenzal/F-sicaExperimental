void LastReport_Plotting_emu()
{	
	UInt_t scale = 100;

	TFile *f1 = TFile::Open("Hists_signal.root", "READ");
  	TFile *f2 = TFile::Open("Hists_tW.root"    , "READ");
	TFile *f3 = TFile::Open("Hists_ttbar.root" , "READ");

    TCanvas *c = new TCanvas("c1", "c1", 1024, 800);

    TH1F *histMT2_emu_1j0t_signal    = (TH1F*) f1 -> Get("histMT2_emu_1j0t");
  	TH1F *histMT2_emu_1j0t_tW        = (TH1F*) f2 -> Get("histMT2_emu_1j0t");
	TH1F *histMT2_emu_1j0t_ttbar     = (TH1F*) f3 -> Get("histMT2_emu_1j0t");
	
    THStack *hs_histMT2_emu_1j0t = new THStack("hs_histMT2_emu_1j0t", "");
    
    TLegend *leg_histMT2_emu_1j0t = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMT2_emu_1j0t -> SetBorderSize(0);
  	leg_histMT2_emu_1j0t -> SetFillColor(0);
   
    leg_histMT2_emu_1j0t -> AddEntry(histMT2_emu_1j0t_signal  , "Signal" , "F");
	leg_histMT2_emu_1j0t -> AddEntry(histMT2_emu_1j0t_tW      , "tW"     , "F");
  	leg_histMT2_emu_1j0t -> AddEntry(histMT2_emu_1j0t_ttbar   , "ttbar"  , "F");

    c -> Draw();
  	c -> SetLogy();

    histMT2_emu_1j0t_signal   -> SetLineColor(kBlack);
	//histMT2_emu_1j0t_signal  -> Scale((histMT2_emu_1j0t_tW -> Integral() + histMT2_emu_1j0t_ttbar -> Integral())/histMT2_emu_1j0t_signal -> Integral());
	histMT2_emu_1j0t_signal  -> Scale(scale);
	histMT2_emu_1j0t_tW       -> SetLineColor(kBlack);
  	histMT2_emu_1j0t_tW       -> SetFillColor(kCyan - 3);
  	histMT2_emu_1j0t_ttbar    -> SetLineColor(kBlack);
  	histMT2_emu_1j0t_ttbar    -> SetFillColor(kRed - 3);  

	hs_histMT2_emu_1j0t -> Add(histMT2_emu_1j0t_ttbar);
    hs_histMT2_emu_1j0t -> Add(histMT2_emu_1j0t_tW);

    hs_histMT2_emu_1j0t     -> Draw("Hist");
  	hs_histMT2_emu_1j0t     -> SetTitle("m_{T2} emu trigger 1j0t");
  	hs_histMT2_emu_1j0t     -> GetXaxis() -> SetTitle("m_{T2} [GeV]");
  	hs_histMT2_emu_1j0t     -> GetYaxis() -> SetTitle("Entries");
  	hs_histMT2_emu_1j0t     -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMT2_emu_1j0t    -> Draw();
  	histMT2_emu_1j0t_signal -> Draw("same");

  	c -> SaveAs("histMT2_emu_1j0t.png");

	c -> Clear();
  	c -> Modified();

    TH1F *histMT2_emu_1j1t_signal    = (TH1F*) f1 -> Get("histMT2_emu_1j1t");
  	TH1F *histMT2_emu_1j1t_tW        = (TH1F*) f2 -> Get("histMT2_emu_1j1t");
	TH1F *histMT2_emu_1j1t_ttbar     = (TH1F*) f3 -> Get("histMT2_emu_1j1t");

    THStack *hs_histMT2_emu_1j1t = new THStack("hs_histMT2_emu_1j1t", "");
    
    TLegend *leg_histMT2_emu_1j1t = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMT2_emu_1j1t -> SetBorderSize(0);
  	leg_histMT2_emu_1j1t -> SetFillColor(0);
   
    leg_histMT2_emu_1j1t -> AddEntry(histMT2_emu_1j1t_signal  , "Signal" , "F");
	leg_histMT2_emu_1j1t -> AddEntry(histMT2_emu_1j1t_tW      , "tW"     , "F");
  	leg_histMT2_emu_1j1t -> AddEntry(histMT2_emu_1j1t_ttbar   , "ttbar"  , "F");

    c -> Draw();
  	c -> SetLogy();

    histMT2_emu_1j1t_signal   -> SetLineColor(kBlack);
	//histMT2_emu_1j1t_signal  -> Scale((histMT2_emu_1j1t_tW -> Integral() + histMT2_emu_1j1t_ttbar -> Integral())/histMT2_emu_1j1t_signal -> Integral());
	histMT2_emu_1j1t_signal  -> Scale(scale);
	histMT2_emu_1j1t_tW       -> SetLineColor(kBlack);
  	histMT2_emu_1j1t_tW       -> SetFillColor(kCyan - 3);
  	histMT2_emu_1j1t_ttbar    -> SetLineColor(kBlack);
  	histMT2_emu_1j1t_ttbar    -> SetFillColor(kRed - 3);  

	hs_histMT2_emu_1j1t -> Add(histMT2_emu_1j1t_ttbar);
    hs_histMT2_emu_1j1t -> Add(histMT2_emu_1j1t_tW);

    hs_histMT2_emu_1j1t     -> Draw("Hist");
  	hs_histMT2_emu_1j1t     -> SetTitle("m_{T2} emu trigger 1j1t");
  	hs_histMT2_emu_1j1t     -> GetXaxis() -> SetTitle("m_{T2} [GeV]");
  	hs_histMT2_emu_1j1t     -> GetYaxis() -> SetTitle("Entries");
  	hs_histMT2_emu_1j1t     -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMT2_emu_1j1t    -> Draw();
  	histMT2_emu_1j1t_signal -> Draw("same");

  	c -> SaveAs("histMT2_emu_1j1t.png");

	c -> Clear();
  	c -> Modified();

    TH1F *histMET_emu_signal    = (TH1F*) f1 -> Get("histMET_emu");
  	TH1F *histMET_emu_tW        = (TH1F*) f2 -> Get("histMET_emu");
	TH1F *histMET_emu_ttbar     = (TH1F*) f3 -> Get("histMET_emu");

    THStack *hs_histMET_emu = new THStack("hs_histMET_emu", "");
    
    TLegend *leg_histMET_emu = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMET_emu -> SetBorderSize(0);
  	leg_histMET_emu -> SetFillColor(0);
   
    leg_histMET_emu -> AddEntry(histMET_emu_signal  , "Signal" , "F");
	leg_histMET_emu -> AddEntry(histMET_emu_tW      , "tW"     , "F");
  	leg_histMET_emu -> AddEntry(histMET_emu_ttbar   , "ttbar"  , "F");

    c -> Draw();
  	c -> SetLogy();

    histMET_emu_signal   -> SetLineColor(kBlack);
	//histMET_emu_signal  -> Scale((histMET_emu_tW  -> Integral() + histMET_emu_ttbar -> Integral())/histMET_emu_signal -> Integral());
	histMET_emu_signal  -> Scale(scale);
	histMET_emu_tW       -> SetLineColor(kBlack);
  	histMET_emu_tW       -> SetFillColor(kCyan - 3);
  	histMET_emu_ttbar    -> SetLineColor(kBlack);
  	histMET_emu_ttbar    -> SetFillColor(kRed - 3);  

	hs_histMET_emu -> Add(histMET_emu_ttbar);
    hs_histMET_emu -> Add(histMET_emu_tW);

    hs_histMET_emu     -> Draw("Hist");
  	hs_histMET_emu     -> SetTitle("p^{miss}_{T} emu trigger");
  	hs_histMET_emu     -> GetXaxis() -> SetTitle("p^{miss}_{T} [GeV]");
  	hs_histMET_emu     -> GetYaxis() -> SetTitle("Entries");
  	hs_histMET_emu     -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMET_emu    -> Draw();
  	histMET_emu_signal -> Draw("same");

  	c -> SaveAs("histMET_emu.png");
}