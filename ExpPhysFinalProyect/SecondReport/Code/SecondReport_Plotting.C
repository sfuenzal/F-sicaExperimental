void SecondReport_Plotting()
{
	TFile *f1 = TFile::Open("Hists_output_simulated_data_two.root", "READ");
  	TFile *f2 = TFile::Open("Hists_ttbar.root"                    , "READ");
  	TFile *f3 = TFile::Open("Hists_WW.root"                       , "READ");

	TCanvas *c = new TCanvas("c1", "c1", 1024, 800);

	// Electrons
	// Hist Electron PT  

  	TH1F *histElectronPT_Data  = (TH1F*) f1 -> Get("histElectronPT");
  	TH1F *histElectronPT_ttbar = (TH1F*) f2 -> Get("histElectronPT");
  	TH1F *histElectronPT_WW    = (TH1F*) f3 -> Get("histElectronPT");

  	THStack *hs_histElectronPT = new THStack("hs_histElectronPT", "");

  	TLegend *leg_histElectronPT = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histElectronPT -> SetBorderSize(0);
  	leg_histElectronPT -> SetFillColor(0);

  	leg_histElectronPT -> AddEntry(histElectronPT_Data , "Data" , "F");
  	leg_histElectronPT -> AddEntry(histElectronPT_ttbar, "ttbar", "F");
  	leg_histElectronPT -> AddEntry(histElectronPT_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histElectronPT_Data  -> SetLineColor(kBlue);
  	histElectronPT_Data  -> Scale((histElectronPT_ttbar -> Integral() + histElectronPT_WW -> Integral())/histElectronPT_Data -> Integral());
  	histElectronPT_ttbar -> SetLineColor(kBlack);
  	histElectronPT_ttbar -> SetFillColor(kGreen);
  	histElectronPT_WW    -> SetLineColor(kBlack);
  	histElectronPT_WW    -> SetFillColor(kRed);

  	hs_histElectronPT -> Add(histElectronPT_ttbar);
  	hs_histElectronPT -> Add(histElectronPT_WW);

  	hs_histElectronPT -> Draw("Hist");
  	hs_histElectronPT -> SetTitle("Electron P_{T}");
  	hs_histElectronPT -> GetXaxis() -> SetTitle("p_{T} [GeV]");
  	hs_histElectronPT -> GetYaxis() -> SetTitle("Entries");
  	hs_histElectronPT -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histElectronPT -> Draw();
  	histElectronPT_Data -> Draw("same:e1");

  	c -> SaveAs("histElectronPT.png");

	// Hist Electron Eta  

	c -> Clear();
  	c -> Modified();

	TH1F *histElectronEta_Data  = (TH1F*) f1 -> Get("histElectronEta");
  	TH1F *histElectronEta_ttbar = (TH1F*) f2 -> Get("histElectronEta");
  	TH1F *histElectronEta_WW    = (TH1F*) f3 -> Get("histElectronEta");

  	THStack *hs_histElectronEta = new THStack("hs_histElectronEta", "");

  	TLegend *leg_histElectronEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histElectronEta -> SetBorderSize(0);
  	leg_histElectronEta -> SetFillColor(0);

  	leg_histElectronEta -> AddEntry(histElectronEta_Data , "Data" , "F");
  	leg_histElectronEta -> AddEntry(histElectronEta_ttbar, "ttbar", "F");
  	leg_histElectronEta -> AddEntry(histElectronEta_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histElectronEta_Data  -> SetLineColor(kBlue);
  	histElectronEta_Data  -> Scale((histElectronEta_ttbar -> Integral() + histElectronEta_WW -> Integral())/histElectronEta_Data -> Integral());
  	histElectronEta_ttbar -> SetLineColor(kBlack);
  	histElectronEta_ttbar -> SetFillColor(kGreen);
  	histElectronEta_WW    -> SetLineColor(kBlack);
  	histElectronEta_WW    -> SetFillColor(kRed);

  	hs_histElectronEta -> Add(histElectronEta_ttbar);
  	hs_histElectronEta -> Add(histElectronEta_WW);

  	hs_histElectronEta -> Draw("Hist");
  	hs_histElectronEta -> SetTitle("Electron #eta");
  	hs_histElectronEta -> GetXaxis()->SetTitle("#eta");
  	hs_histElectronEta -> GetYaxis()->SetTitle("Entries");
  	hs_histElectronEta -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histElectronEta -> Draw();
  	histElectronEta_Data -> Draw("same:e1");

	c -> SaveAs("histElectronEta.png");

	// Hist Electron Phi  

	c -> Clear();
  	c -> Modified();

	TH1F *histElectronPhi_Data  = (TH1F*) f1 -> Get("histElectronPhi");
  	TH1F *histElectronPhi_ttbar = (TH1F*) f2 -> Get("histElectronPhi");
  	TH1F *histElectronPhi_WW    = (TH1F*) f3 -> Get("histElectronPhi");

  	THStack *hs_histElectronPhi = new THStack("hs_histElectronPhi", "");

  	TLegend *leg_histElectronPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histElectronPhi -> SetBorderSize(0);
  	leg_histElectronPhi -> SetFillColor(0);

  	leg_histElectronPhi -> AddEntry(histElectronPhi_Data , "Data" , "F");
  	leg_histElectronPhi -> AddEntry(histElectronPhi_ttbar, "ttbar", "F");
  	leg_histElectronPhi -> AddEntry(histElectronPhi_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histElectronPhi_Data  -> SetLineColor(kBlue);
  	histElectronPhi_Data  -> Scale((histElectronPhi_ttbar -> Integral() + histElectronPhi_WW -> Integral())/histElectronPhi_Data -> Integral());
  	histElectronPhi_ttbar -> SetLineColor(kBlack);
  	histElectronPhi_ttbar -> SetFillColor(kGreen);
  	histElectronPhi_WW    -> SetLineColor(kBlack);
  	histElectronPhi_WW    -> SetFillColor(kRed);

  	hs_histElectronPhi -> Add(histElectronPhi_ttbar);
  	hs_histElectronPhi -> Add(histElectronPhi_WW);

  	hs_histElectronPhi -> Draw("Hist");
  	hs_histElectronPhi -> SetTitle("Electron #phi");
  	hs_histElectronPhi -> GetXaxis()->SetTitle("#phi");
  	hs_histElectronPhi -> GetYaxis()->SetTitle("Entries");
  	hs_histElectronPhi -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histElectronPhi -> Draw();
  	histElectronPhi_Data -> Draw("same:e1");

	c -> SaveAs("histElectronPhi.png");

	// Muons
	// Hist Muon PT  

  	TH1F *histMuonPT_Data  = (TH1F*) f1 -> Get("histMuonPT");
  	TH1F *histMuonPT_ttbar = (TH1F*) f2 -> Get("histMuonPT");
  	TH1F *histMuonPT_WW    = (TH1F*) f3 -> Get("histMuonPT");

  	THStack *hs_histMuonPT = new THStack("hs_histMuonPT", "");

  	TLegend *leg_histMuonPT = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMuonPT -> SetBorderSize(0);
  	leg_histMuonPT -> SetFillColor(0);

  	leg_histMuonPT -> AddEntry(histMuonPT_Data , "Data" , "F");
  	leg_histMuonPT -> AddEntry(histMuonPT_ttbar, "ttbar", "F");
  	leg_histMuonPT -> AddEntry(histMuonPT_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMuonPT_Data  -> SetLineColor(kBlue);
  	histMuonPT_Data  -> Scale((histMuonPT_ttbar -> Integral() + histMuonPT_WW -> Integral())/histMuonPT_Data -> Integral());
  	histMuonPT_ttbar -> SetLineColor(kBlack);
  	histMuonPT_ttbar -> SetFillColor(kGreen);
  	histMuonPT_WW    -> SetLineColor(kBlack);
  	histMuonPT_WW    -> SetFillColor(kRed);

  	hs_histMuonPT -> Add(histMuonPT_ttbar);
  	hs_histMuonPT -> Add(histMuonPT_WW);

  	hs_histMuonPT -> Draw("Hist");
  	hs_histMuonPT -> SetTitle("Muon P_{T}");
  	hs_histMuonPT -> GetXaxis() -> SetTitle("p_{T} [GeV]");
  	hs_histMuonPT -> GetYaxis() -> SetTitle("Entries");
  	hs_histMuonPT -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMuonPT -> Draw();
  	histMuonPT_Data -> Draw("same:e1");

  	c -> SaveAs("histMuonPT.png");

	// Hist Muon Eta  

	c -> Clear();
  	c -> Modified();

	TH1F *histMuonEta_Data  = (TH1F*) f1 -> Get("histMuonEta");
  	TH1F *histMuonEta_ttbar = (TH1F*) f2 -> Get("histMuonEta");
  	TH1F *histMuonEta_WW    = (TH1F*) f3 -> Get("histMuonEta");

  	THStack *hs_histMuonEta = new THStack("hs_histMuonEta", "");

  	TLegend *leg_histMuonEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMuonEta -> SetBorderSize(0);
  	leg_histMuonEta -> SetFillColor(0);

  	leg_histMuonEta -> AddEntry(histMuonEta_Data , "Data" , "F");
  	leg_histMuonEta -> AddEntry(histMuonEta_ttbar, "ttbar", "F");
  	leg_histMuonEta -> AddEntry(histMuonEta_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMuonEta_Data  -> SetLineColor(kBlue);
  	histMuonEta_Data  -> Scale((histMuonEta_ttbar -> Integral() + histMuonEta_WW -> Integral())/histMuonEta_Data -> Integral());
  	histMuonEta_ttbar -> SetLineColor(kBlack);
  	histMuonEta_ttbar -> SetFillColor(kGreen);
  	histMuonEta_WW    -> SetLineColor(kBlack);
  	histMuonEta_WW    -> SetFillColor(kRed);

  	hs_histMuonEta -> Add(histMuonEta_ttbar);
  	hs_histMuonEta -> Add(histMuonEta_WW);

  	hs_histMuonEta -> Draw("Hist");
  	hs_histMuonEta -> SetTitle("Muon #eta");
  	hs_histMuonEta -> GetXaxis()->SetTitle("#eta");
  	hs_histMuonEta -> GetYaxis()->SetTitle("Entries");
  	hs_histMuonEta -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histMuonEta -> Draw();
  	histMuonEta_Data -> Draw("same:e1");

	c -> SaveAs("histMuonEta.png");

	// Hist Muon Phi  

	c -> Clear();
  	c -> Modified();

	TH1F *histMuonPhi_Data  = (TH1F*) f1 -> Get("histMuonPhi");
  	TH1F *histMuonPhi_ttbar = (TH1F*) f2 -> Get("histMuonPhi");
  	TH1F *histMuonPhi_WW    = (TH1F*) f3 -> Get("histMuonPhi");

  	THStack *hs_histMuonPhi = new THStack("hs_histMuonPhi", "");

  	TLegend *leg_histMuonPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMuonPhi -> SetBorderSize(0);
  	leg_histMuonPhi -> SetFillColor(0);

  	leg_histMuonPhi -> AddEntry(histMuonPhi_Data , "Data" , "F");
  	leg_histMuonPhi -> AddEntry(histMuonPhi_ttbar, "ttbar", "F");
  	leg_histMuonPhi -> AddEntry(histMuonPhi_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMuonPhi_Data  -> SetLineColor(kBlue);
  	histMuonPhi_Data  -> Scale((histMuonPhi_ttbar -> Integral() + histMuonPhi_WW -> Integral())/histMuonPhi_Data -> Integral());
  	histMuonPhi_ttbar -> SetLineColor(kBlack);
  	histMuonPhi_ttbar -> SetFillColor(kGreen);
  	histMuonPhi_WW    -> SetLineColor(kBlack);
  	histMuonPhi_WW    -> SetFillColor(kRed);

  	hs_histMuonPhi -> Add(histMuonPhi_ttbar);
  	hs_histMuonPhi -> Add(histMuonPhi_WW);

  	hs_histMuonPhi -> Draw("Hist");
  	hs_histMuonPhi -> SetTitle("Muon #phi");
  	hs_histMuonPhi -> GetXaxis()->SetTitle("#phi");
  	hs_histMuonPhi -> GetYaxis()->SetTitle("Entries");
  	hs_histMuonPhi -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histMuonPhi -> Draw();
  	histMuonPhi_Data -> Draw("same:e1");

	c -> SaveAs("histMuonPhi.png");

	// MissingET
	// Hist MissingET MET 

  	TH1F *histMissingETMET_Data  = (TH1F*) f1 -> Get("histMissingETMET");
  	TH1F *histMissingETMET_ttbar = (TH1F*) f2 -> Get("histMissingETMET");
  	TH1F *histMissingETMET_WW    = (TH1F*) f3 -> Get("histMissingETMET");

  	THStack *hs_histMissingETMET = new THStack("hs_histMissingETMET", "");

  	TLegend *leg_histMissingETMET = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMissingETMET -> SetBorderSize(0);
  	leg_histMissingETMET -> SetFillColor(0);

  	leg_histMissingETMET -> AddEntry(histMissingETMET_Data , "Data" , "F");
  	leg_histMissingETMET -> AddEntry(histMissingETMET_ttbar, "ttbar", "F");
  	leg_histMissingETMET -> AddEntry(histMissingETMET_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMissingETMET_Data  -> SetLineColor(kBlue);
  	histMissingETMET_Data  -> Scale((histMissingETMET_ttbar -> Integral() + histMissingETMET_WW -> Integral())/histMissingETMET_Data -> Integral());
  	histMissingETMET_ttbar -> SetLineColor(kBlack);
  	histMissingETMET_ttbar -> SetFillColor(kGreen);
  	histMissingETMET_WW    -> SetLineColor(kBlack);
  	histMissingETMET_WW    -> SetFillColor(kRed);

  	hs_histMissingETMET -> Add(histMissingETMET_ttbar);
  	hs_histMissingETMET -> Add(histMissingETMET_WW);

  	hs_histMissingETMET -> Draw("Hist");
  	hs_histMissingETMET -> SetTitle("MissingET E^{miss}_{T}");
  	hs_histMissingETMET -> GetXaxis() -> SetTitle("E^{miss}_{T} [GeV]");
  	hs_histMissingETMET -> GetYaxis() -> SetTitle("Entries");
  	hs_histMissingETMET -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histMissingETMET -> Draw();
  	histMissingETMET_Data -> Draw("same:e1");

  	c -> SaveAs("histMissingETMET.png");

	// Hist MissingET Eta  

	c -> Clear();
  	c -> Modified();

	TH1F *histMissingETEta_Data  = (TH1F*) f1 -> Get("histMissingETEta");
  	TH1F *histMissingETEta_ttbar = (TH1F*) f2 -> Get("histMissingETEta");
  	TH1F *histMissingETEta_WW    = (TH1F*) f3 -> Get("histMissingETEta");

  	THStack *hs_histMissingETEta = new THStack("hs_histMissingETEta", "");

  	TLegend *leg_histMissingETEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMissingETEta -> SetBorderSize(0);
  	leg_histMissingETEta -> SetFillColor(0);

  	leg_histMissingETEta -> AddEntry(histMissingETEta_Data , "Data" , "F");
  	leg_histMissingETEta -> AddEntry(histMissingETEta_ttbar, "ttbar", "F");
  	leg_histMissingETEta -> AddEntry(histMissingETEta_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMissingETEta_Data  -> SetLineColor(kBlue);
  	histMissingETEta_Data  -> Scale((histMissingETEta_ttbar -> Integral() + histMissingETEta_WW -> Integral())/histMissingETEta_Data -> Integral());
  	histMissingETEta_ttbar -> SetLineColor(kBlack);
  	histMissingETEta_ttbar -> SetFillColor(kGreen);
  	histMissingETEta_WW    -> SetLineColor(kBlack);
  	histMissingETEta_WW    -> SetFillColor(kRed);

  	hs_histMissingETEta -> Add(histMissingETEta_ttbar);
  	hs_histMissingETEta -> Add(histMissingETEta_WW);

  	hs_histMissingETEta -> Draw("Hist");
  	hs_histMissingETEta -> SetTitle("MissingET #eta");
  	hs_histMissingETEta -> GetXaxis()->SetTitle("#eta");
  	hs_histMissingETEta -> GetYaxis()->SetTitle("Entries");
  	hs_histMissingETEta -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histMissingETEta -> Draw();
  	histMissingETEta_Data -> Draw("same:e1");

	c -> SaveAs("histMissingETEta.png");

	// Hist MissingET Phi  

	c -> Clear();
  	c -> Modified();

	TH1F *histMissingETPhi_Data  = (TH1F*) f1 -> Get("histMissingETPhi");
  	TH1F *histMissingETPhi_ttbar = (TH1F*) f2 -> Get("histMissingETPhi");
  	TH1F *histMissingETPhi_WW    = (TH1F*) f3 -> Get("histMissingETPhi");

  	THStack *hs_histMissingETPhi = new THStack("hs_histMissingETPhi", "");

  	TLegend *leg_histMissingETPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMissingETPhi -> SetBorderSize(0);
  	leg_histMissingETPhi -> SetFillColor(0);

  	leg_histMissingETPhi -> AddEntry(histMissingETPhi_Data , "Data" , "F");
  	leg_histMissingETPhi -> AddEntry(histMissingETPhi_ttbar, "ttbar", "F");
  	leg_histMissingETPhi -> AddEntry(histMissingETPhi_WW   , "WW"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMissingETPhi_Data  -> SetLineColor(kBlue);
  	histMissingETPhi_Data  -> Scale((histMissingETPhi_ttbar -> Integral() + histMissingETPhi_WW -> Integral())/histMissingETPhi_Data -> Integral());
  	histMissingETPhi_ttbar -> SetLineColor(kBlack);
  	histMissingETPhi_ttbar -> SetFillColor(kGreen);
  	histMissingETPhi_WW    -> SetLineColor(kBlack);
  	histMissingETPhi_WW    -> SetFillColor(kRed);

  	hs_histMissingETPhi -> Add(histMissingETPhi_ttbar);
  	hs_histMissingETPhi -> Add(histMissingETPhi_WW);

  	hs_histMissingETPhi -> Draw("Hist");
  	hs_histMissingETPhi -> SetTitle("MissingET #phi");
  	hs_histMissingETPhi -> GetXaxis()->SetTitle("#phi");
  	hs_histMissingETPhi -> GetYaxis()->SetTitle("Entries");
  	hs_histMissingETPhi -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histMissingETPhi -> Draw();
  	histMissingETPhi_Data -> Draw("same:e1");

	c -> SaveAs("histMissingETPhi.png");



}
