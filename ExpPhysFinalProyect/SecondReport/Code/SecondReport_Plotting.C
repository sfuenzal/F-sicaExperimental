void SecondReport_Plotting()
{
	TFile *f1 = TFile::Open("Hists_output_simulated_data_two.root", "READ");
  	TFile *f2 = TFile::Open("Hists_WW.root"                       , "READ");
  	TFile *f3 = TFile::Open("Hists_ttbar.root"                    , "READ");

	TCanvas *c = new TCanvas("c1", "c1", 1024, 800);

	// Electrons
	// Hist Electron PT  

  	TH1F *histElectronPT_Data  = (TH1F*) f1 -> Get("histElectronPT");
  	TH1F *histElectronPT_WW = (TH1F*) f2 -> Get("histElectronPT");
  	TH1F *histElectronPT_ttbar    = (TH1F*) f3 -> Get("histElectronPT");

  	THStack *hs_histElectronPT = new THStack("hs_histElectronPT", "");

  	TLegend *leg_histElectronPT = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histElectronPT -> SetBorderSize(0);
  	leg_histElectronPT -> SetFillColor(0);

  	leg_histElectronPT -> AddEntry(histElectronPT_Data , "Data" , "F");
  	leg_histElectronPT -> AddEntry(histElectronPT_WW, "WW", "F");
  	leg_histElectronPT -> AddEntry(histElectronPT_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histElectronPT_Data  -> SetLineColor(kBlue);
  	histElectronPT_Data  -> Scale((histElectronPT_WW -> Integral() + histElectronPT_ttbar -> Integral())/histElectronPT_Data -> Integral());
  	histElectronPT_WW -> SetLineColor(kBlack);
  	histElectronPT_WW -> SetFillColor(kGreen);
  	histElectronPT_ttbar    -> SetLineColor(kBlack);
  	histElectronPT_ttbar    -> SetFillColor(kRed);

  	hs_histElectronPT -> Add(histElectronPT_WW);
  	hs_histElectronPT -> Add(histElectronPT_ttbar);

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
  	TH1F *histElectronEta_WW = (TH1F*) f2 -> Get("histElectronEta");
  	TH1F *histElectronEta_ttbar    = (TH1F*) f3 -> Get("histElectronEta");

  	THStack *hs_histElectronEta = new THStack("hs_histElectronEta", "");

  	TLegend *leg_histElectronEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histElectronEta -> SetBorderSize(0);
  	leg_histElectronEta -> SetFillColor(0);

  	leg_histElectronEta -> AddEntry(histElectronEta_Data , "Data" , "F");
  	leg_histElectronEta -> AddEntry(histElectronEta_WW, "WW", "F");
  	leg_histElectronEta -> AddEntry(histElectronEta_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histElectronEta_Data  -> SetLineColor(kBlue);
  	histElectronEta_Data  -> Scale((histElectronEta_WW -> Integral() + histElectronEta_ttbar -> Integral())/histElectronEta_Data -> Integral());
  	histElectronEta_WW -> SetLineColor(kBlack);
  	histElectronEta_WW -> SetFillColor(kGreen);
  	histElectronEta_ttbar    -> SetLineColor(kBlack);
  	histElectronEta_ttbar    -> SetFillColor(kRed);

  	hs_histElectronEta -> Add(histElectronEta_WW);
  	hs_histElectronEta -> Add(histElectronEta_ttbar);

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
  	TH1F *histElectronPhi_WW = (TH1F*) f2 -> Get("histElectronPhi");
  	TH1F *histElectronPhi_ttbar    = (TH1F*) f3 -> Get("histElectronPhi");

  	THStack *hs_histElectronPhi = new THStack("hs_histElectronPhi", "");

  	TLegend *leg_histElectronPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histElectronPhi -> SetBorderSize(0);
  	leg_histElectronPhi -> SetFillColor(0);

  	leg_histElectronPhi -> AddEntry(histElectronPhi_Data , "Data" , "F");
  	leg_histElectronPhi -> AddEntry(histElectronPhi_WW, "WW", "F");
  	leg_histElectronPhi -> AddEntry(histElectronPhi_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histElectronPhi_Data  -> SetLineColor(kBlue);
  	histElectronPhi_Data  -> Scale((histElectronPhi_WW -> Integral() + histElectronPhi_ttbar -> Integral())/histElectronPhi_Data -> Integral());
  	histElectronPhi_WW -> SetLineColor(kBlack);
  	histElectronPhi_WW -> SetFillColor(kGreen);
  	histElectronPhi_ttbar    -> SetLineColor(kBlack);
  	histElectronPhi_ttbar    -> SetFillColor(kRed);

  	hs_histElectronPhi -> Add(histElectronPhi_WW);
  	hs_histElectronPhi -> Add(histElectronPhi_ttbar);

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
  	TH1F *histMuonPT_WW = (TH1F*) f2 -> Get("histMuonPT");
  	TH1F *histMuonPT_ttbar    = (TH1F*) f3 -> Get("histMuonPT");

  	THStack *hs_histMuonPT = new THStack("hs_histMuonPT", "");

  	TLegend *leg_histMuonPT = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMuonPT -> SetBorderSize(0);
  	leg_histMuonPT -> SetFillColor(0);

  	leg_histMuonPT -> AddEntry(histMuonPT_Data , "Data" , "F");
  	leg_histMuonPT -> AddEntry(histMuonPT_WW, "WW", "F");
  	leg_histMuonPT -> AddEntry(histMuonPT_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMuonPT_Data  -> SetLineColor(kBlue);
  	histMuonPT_Data  -> Scale((histMuonPT_WW -> Integral() + histMuonPT_ttbar -> Integral())/histMuonPT_Data -> Integral());
  	histMuonPT_WW -> SetLineColor(kBlack);
  	histMuonPT_WW -> SetFillColor(kGreen);
  	histMuonPT_ttbar    -> SetLineColor(kBlack);
  	histMuonPT_ttbar    -> SetFillColor(kRed);

  	hs_histMuonPT -> Add(histMuonPT_WW);
  	hs_histMuonPT -> Add(histMuonPT_ttbar);

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
  	TH1F *histMuonEta_WW = (TH1F*) f2 -> Get("histMuonEta");
  	TH1F *histMuonEta_ttbar    = (TH1F*) f3 -> Get("histMuonEta");

  	THStack *hs_histMuonEta = new THStack("hs_histMuonEta", "");

  	TLegend *leg_histMuonEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMuonEta -> SetBorderSize(0);
  	leg_histMuonEta -> SetFillColor(0);

  	leg_histMuonEta -> AddEntry(histMuonEta_Data , "Data" , "F");
  	leg_histMuonEta -> AddEntry(histMuonEta_WW, "WW", "F");
  	leg_histMuonEta -> AddEntry(histMuonEta_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMuonEta_Data  -> SetLineColor(kBlue);
  	histMuonEta_Data  -> Scale((histMuonEta_WW -> Integral() + histMuonEta_ttbar -> Integral())/histMuonEta_Data -> Integral());
  	histMuonEta_WW -> SetLineColor(kBlack);
  	histMuonEta_WW -> SetFillColor(kGreen);
  	histMuonEta_ttbar    -> SetLineColor(kBlack);
  	histMuonEta_ttbar    -> SetFillColor(kRed);

  	hs_histMuonEta -> Add(histMuonEta_WW);
  	hs_histMuonEta -> Add(histMuonEta_ttbar);

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
  	TH1F *histMuonPhi_WW = (TH1F*) f2 -> Get("histMuonPhi");
  	TH1F *histMuonPhi_ttbar    = (TH1F*) f3 -> Get("histMuonPhi");

  	THStack *hs_histMuonPhi = new THStack("hs_histMuonPhi", "");

  	TLegend *leg_histMuonPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMuonPhi -> SetBorderSize(0);
  	leg_histMuonPhi -> SetFillColor(0);

  	leg_histMuonPhi -> AddEntry(histMuonPhi_Data , "Data" , "F");
  	leg_histMuonPhi -> AddEntry(histMuonPhi_WW, "WW", "F");
  	leg_histMuonPhi -> AddEntry(histMuonPhi_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMuonPhi_Data  -> SetLineColor(kBlue);
  	histMuonPhi_Data  -> Scale((histMuonPhi_WW -> Integral() + histMuonPhi_ttbar -> Integral())/histMuonPhi_Data -> Integral());
  	histMuonPhi_WW -> SetLineColor(kBlack);
  	histMuonPhi_WW -> SetFillColor(kGreen);
  	histMuonPhi_ttbar    -> SetLineColor(kBlack);
  	histMuonPhi_ttbar    -> SetFillColor(kRed);

  	hs_histMuonPhi -> Add(histMuonPhi_WW);
  	hs_histMuonPhi -> Add(histMuonPhi_ttbar);

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
  	TH1F *histMissingETMET_WW = (TH1F*) f2 -> Get("histMissingETMET");
  	TH1F *histMissingETMET_ttbar    = (TH1F*) f3 -> Get("histMissingETMET");

  	THStack *hs_histMissingETMET = new THStack("hs_histMissingETMET", "");

  	TLegend *leg_histMissingETMET = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMissingETMET -> SetBorderSize(0);
  	leg_histMissingETMET -> SetFillColor(0);

  	leg_histMissingETMET -> AddEntry(histMissingETMET_Data , "Data" , "F");
  	leg_histMissingETMET -> AddEntry(histMissingETMET_WW, "WW", "F");
  	leg_histMissingETMET -> AddEntry(histMissingETMET_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMissingETMET_Data  -> SetLineColor(kBlue);
  	histMissingETMET_Data  -> Scale((histMissingETMET_WW -> Integral() + histMissingETMET_ttbar -> Integral())/histMissingETMET_Data -> Integral());
  	histMissingETMET_WW -> SetLineColor(kBlack);
  	histMissingETMET_WW -> SetFillColor(kGreen);
  	histMissingETMET_ttbar    -> SetLineColor(kBlack);
  	histMissingETMET_ttbar    -> SetFillColor(kRed);

  	hs_histMissingETMET -> Add(histMissingETMET_WW);
  	hs_histMissingETMET -> Add(histMissingETMET_ttbar);

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
  	TH1F *histMissingETEta_WW = (TH1F*) f2 -> Get("histMissingETEta");
  	TH1F *histMissingETEta_ttbar    = (TH1F*) f3 -> Get("histMissingETEta");

  	THStack *hs_histMissingETEta = new THStack("hs_histMissingETEta", "");

  	TLegend *leg_histMissingETEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMissingETEta -> SetBorderSize(0);
  	leg_histMissingETEta -> SetFillColor(0);

  	leg_histMissingETEta -> AddEntry(histMissingETEta_Data , "Data" , "F");
  	leg_histMissingETEta -> AddEntry(histMissingETEta_WW, "WW", "F");
  	leg_histMissingETEta -> AddEntry(histMissingETEta_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMissingETEta_Data  -> SetLineColor(kBlue);
  	histMissingETEta_Data  -> Scale((histMissingETEta_WW -> Integral() + histMissingETEta_ttbar -> Integral())/histMissingETEta_Data -> Integral());
  	histMissingETEta_WW -> SetLineColor(kBlack);
  	histMissingETEta_WW -> SetFillColor(kGreen);
  	histMissingETEta_ttbar    -> SetLineColor(kBlack);
  	histMissingETEta_ttbar    -> SetFillColor(kRed);

  	hs_histMissingETEta -> Add(histMissingETEta_WW);
  	hs_histMissingETEta -> Add(histMissingETEta_ttbar);

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
  	TH1F *histMissingETPhi_WW = (TH1F*) f2 -> Get("histMissingETPhi");
  	TH1F *histMissingETPhi_ttbar    = (TH1F*) f3 -> Get("histMissingETPhi");

  	THStack *hs_histMissingETPhi = new THStack("hs_histMissingETPhi", "");

  	TLegend *leg_histMissingETPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histMissingETPhi -> SetBorderSize(0);
  	leg_histMissingETPhi -> SetFillColor(0);

  	leg_histMissingETPhi -> AddEntry(histMissingETPhi_Data , "Data" , "F");
  	leg_histMissingETPhi -> AddEntry(histMissingETPhi_WW, "WW", "F");
  	leg_histMissingETPhi -> AddEntry(histMissingETPhi_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histMissingETPhi_Data  -> SetLineColor(kBlue);
  	histMissingETPhi_Data  -> Scale((histMissingETPhi_WW -> Integral() + histMissingETPhi_ttbar -> Integral())/histMissingETPhi_Data -> Integral());
  	histMissingETPhi_WW -> SetLineColor(kBlack);
  	histMissingETPhi_WW -> SetFillColor(kGreen);
  	histMissingETPhi_ttbar    -> SetLineColor(kBlack);
  	histMissingETPhi_ttbar    -> SetFillColor(kRed);

  	hs_histMissingETPhi -> Add(histMissingETPhi_WW);
  	hs_histMissingETPhi -> Add(histMissingETPhi_ttbar);

  	hs_histMissingETPhi -> Draw("Hist");
  	hs_histMissingETPhi -> SetTitle("MissingET #phi");
  	hs_histMissingETPhi -> GetXaxis()->SetTitle("#phi");
  	hs_histMissingETPhi -> GetYaxis()->SetTitle("Entries");
  	hs_histMissingETPhi -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histMissingETPhi -> Draw();
  	histMissingETPhi_Data -> Draw("same:e1");

	c -> SaveAs("histMissingETPhi.png");

    // Jet
	// Hist Jet PT 

  	TH1F *histJetPT_Data  = (TH1F*) f1 -> Get("histJetPT");
  	TH1F *histJetPT_WW = (TH1F*) f2 -> Get("histJetPT");
  	TH1F *histJetPT_ttbar    = (TH1F*) f3 -> Get("histJetPT");

  	THStack *hs_histJetPT = new THStack("hs_histJetPT", "");

  	TLegend *leg_histJetPT = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histJetPT -> SetBorderSize(0);
  	leg_histJetPT -> SetFillColor(0);

  	leg_histJetPT -> AddEntry(histJetPT_Data , "Data" , "F");
  	leg_histJetPT -> AddEntry(histJetPT_WW, "WW", "F");
  	leg_histJetPT -> AddEntry(histJetPT_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histJetPT_Data  -> SetLineColor(kBlue);
  	histJetPT_Data  -> Scale((histJetPT_WW -> Integral() + histJetPT_ttbar -> Integral())/histJetPT_Data -> Integral());
  	histJetPT_WW -> SetLineColor(kBlack);
  	histJetPT_WW -> SetFillColor(kGreen);
  	histJetPT_ttbar    -> SetLineColor(kBlack);
  	histJetPT_ttbar    -> SetFillColor(kRed);

  	hs_histJetPT -> Add(histJetPT_WW);
  	hs_histJetPT -> Add(histJetPT_ttbar);

  	hs_histJetPT -> Draw("Hist");
  	hs_histJetPT -> SetTitle("Jet P_{T}");
  	hs_histJetPT -> GetXaxis() -> SetTitle("P_{T} [GeV]");
  	hs_histJetPT -> GetYaxis() -> SetTitle("Entries");
  	hs_histJetPT -> GetYaxis() -> SetTitleOffset(1.4);
  	leg_histJetPT -> Draw();
  	histJetPT_Data -> Draw("same:e1");

  	c -> SaveAs("histJetPT.png");

	// Hist Jet Eta  

	c -> Clear();
  	c -> Modified();

	TH1F *histJetEta_Data  = (TH1F*) f1 -> Get("histJetEta");
  	TH1F *histJetEta_WW = (TH1F*) f2 -> Get("histJetEta");
  	TH1F *histJetEta_ttbar    = (TH1F*) f3 -> Get("histJetEta");

  	THStack *hs_histJetEta = new THStack("hs_histJetEta", "");

  	TLegend *leg_histJetEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histJetEta -> SetBorderSize(0);
  	leg_histJetEta -> SetFillColor(0);

  	leg_histJetEta -> AddEntry(histJetEta_Data , "Data" , "F");
  	leg_histJetEta -> AddEntry(histJetEta_WW, "WW", "F");
  	leg_histJetEta -> AddEntry(histJetEta_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histJetEta_Data  -> SetLineColor(kBlue);
  	histJetEta_Data  -> Scale((histJetEta_WW -> Integral() + histJetEta_ttbar -> Integral())/histJetEta_Data -> Integral());
  	histJetEta_WW -> SetLineColor(kBlack);
  	histJetEta_WW -> SetFillColor(kGreen);
  	histJetEta_ttbar    -> SetLineColor(kBlack);
  	histJetEta_ttbar    -> SetFillColor(kRed);

  	hs_histJetEta -> Add(histJetEta_WW);
  	hs_histJetEta -> Add(histJetEta_ttbar);

  	hs_histJetEta -> Draw("Hist");
  	hs_histJetEta -> SetTitle("Jet #eta");
  	hs_histJetEta -> GetXaxis()->SetTitle("#eta");
  	hs_histJetEta -> GetYaxis()->SetTitle("Entries");
  	hs_histJetEta -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histJetEta -> Draw();
  	histJetEta_Data -> Draw("same:e1");

	c -> SaveAs("histJetEta.png");

	// Hist Jet Phi  

	c -> Clear();
  	c -> Modified();

	TH1F *histJetPhi_Data  = (TH1F*) f1 -> Get("histJetPhi");
  	TH1F *histJetPhi_WW = (TH1F*) f2 -> Get("histJetPhi");
  	TH1F *histJetPhi_ttbar    = (TH1F*) f3 -> Get("histJetPhi");

  	THStack *hs_histJetPhi = new THStack("hs_histJetPhi", "");

  	TLegend *leg_histJetPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histJetPhi -> SetBorderSize(0);
  	leg_histJetPhi -> SetFillColor(0);

  	leg_histJetPhi -> AddEntry(histJetPhi_Data , "Data" , "F");
  	leg_histJetPhi -> AddEntry(histJetPhi_WW, "WW", "F");
  	leg_histJetPhi -> AddEntry(histJetPhi_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histJetPhi_Data  -> SetLineColor(kBlue);
  	histJetPhi_Data  -> Scale((histJetPhi_WW -> Integral() + histJetPhi_ttbar -> Integral())/histJetPhi_Data -> Integral());
  	histJetPhi_WW -> SetLineColor(kBlack);
  	histJetPhi_WW -> SetFillColor(kGreen);
  	histJetPhi_ttbar    -> SetLineColor(kBlack);
  	histJetPhi_ttbar    -> SetFillColor(kRed);

  	hs_histJetPhi -> Add(histJetPhi_WW);
  	hs_histJetPhi -> Add(histJetPhi_ttbar);

  	hs_histJetPhi -> Draw("Hist");
  	hs_histJetPhi -> SetTitle("Jet #phi");
  	hs_histJetPhi -> GetXaxis()->SetTitle("#phi");
  	hs_histJetPhi -> GetYaxis()->SetTitle("Entries");
  	hs_histJetPhi -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histJetPhi -> Draw();
  	histJetPhi_Data -> Draw("same:e1");

	c -> SaveAs("histJetPhi.png");

	// Hist Jet Mass  

	c -> Clear();
  	c -> Modified();

	TH1F *histJetMass_Data  = (TH1F*) f1 -> Get("histJetMass");
  	TH1F *histJetMass_WW = (TH1F*) f2 -> Get("histJetMass");
  	TH1F *histJetMass_ttbar    = (TH1F*) f3 -> Get("histJetMass");

  	THStack *hs_histJetMass = new THStack("hs_histJetMass", "");

  	TLegend *leg_histJetMass = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histJetMass -> SetBorderSize(0);
  	leg_histJetMass -> SetFillColor(0);

  	leg_histJetMass -> AddEntry(histJetMass_Data , "Data" , "F");
  	leg_histJetMass -> AddEntry(histJetMass_WW, "WW", "F");
  	leg_histJetMass -> AddEntry(histJetMass_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histJetMass_Data  -> SetLineColor(kBlue);
  	histJetMass_Data  -> Scale((histJetMass_WW -> Integral() + histJetMass_ttbar -> Integral())/histJetMass_Data -> Integral());
  	histJetMass_WW -> SetLineColor(kBlack);
  	histJetMass_WW -> SetFillColor(kGreen);
  	histJetMass_ttbar    -> SetLineColor(kBlack);
  	histJetMass_ttbar    -> SetFillColor(kRed);

  	hs_histJetMass -> Add(histJetMass_WW);
  	hs_histJetMass -> Add(histJetMass_ttbar);

  	hs_histJetMass -> Draw("Hist");
  	hs_histJetMass -> SetTitle("Jet #Mass");
  	hs_histJetMass -> GetXaxis()->SetTitle("#Mass");
  	hs_histJetMass -> GetYaxis()->SetTitle("Entries");
  	hs_histJetMass -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histJetMass -> Draw();
  	histJetMass_Data -> Draw("same:e1");

	c -> SaveAs("histJetMass.png");

	// Hist Jet DeltaEta  

	c -> Clear();
  	c -> Modified();

	TH1F *histJetDeltaEta_Data  = (TH1F*) f1 -> Get("histJetDeltaEta");
  	TH1F *histJetDeltaEta_WW = (TH1F*) f2 -> Get("histJetDeltaEta");
  	TH1F *histJetDeltaEta_ttbar    = (TH1F*) f3 -> Get("histJetDeltaEta");

  	THStack *hs_histJetDeltaEta = new THStack("hs_histJetDeltaEta", "");

  	TLegend *leg_histJetDeltaEta = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histJetDeltaEta -> SetBorderSize(0);
  	leg_histJetDeltaEta -> SetFillColor(0);

  	leg_histJetDeltaEta -> AddEntry(histJetDeltaEta_Data , "Data" , "F");
  	leg_histJetDeltaEta -> AddEntry(histJetDeltaEta_WW, "WW", "F");
  	leg_histJetDeltaEta -> AddEntry(histJetDeltaEta_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histJetDeltaEta_Data  -> SetLineColor(kBlue);
  	histJetDeltaEta_Data  -> Scale((histJetDeltaEta_WW -> Integral() + histJetDeltaEta_ttbar -> Integral())/histJetDeltaEta_Data -> Integral());
  	histJetDeltaEta_WW -> SetLineColor(kBlack);
  	histJetDeltaEta_WW -> SetFillColor(kGreen);
  	histJetDeltaEta_ttbar    -> SetLineColor(kBlack);
  	histJetDeltaEta_ttbar    -> SetFillColor(kRed);

  	hs_histJetDeltaEta -> Add(histJetDeltaEta_WW);
  	hs_histJetDeltaEta -> Add(histJetDeltaEta_ttbar);

  	hs_histJetDeltaEta -> Draw("Hist");
  	hs_histJetDeltaEta -> SetTitle("Jet #DeltaEta");
  	hs_histJetDeltaEta -> GetXaxis()->SetTitle("#DeltaEta");
  	hs_histJetDeltaEta -> GetYaxis()->SetTitle("Entries");
  	hs_histJetDeltaEta -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histJetDeltaEta -> Draw();
  	histJetDeltaEta_Data -> Draw("same:e1");

	c -> SaveAs("histJetDeltaEta.png");





	// Hist Jet DeltaPhi  

	c -> Clear();
  	c -> Modified();

	TH1F *histJetDeltaPhi_Data  = (TH1F*) f1 -> Get("histJetDeltaPhi");
  	TH1F *histJetDeltaPhi_WW = (TH1F*) f2 -> Get("histJetDeltaPhi");
  	TH1F *histJetDeltaPhi_ttbar    = (TH1F*) f3 -> Get("histJetDeltaPhi");

  	THStack *hs_histJetDeltaPhi = new THStack("hs_histJetDeltaPhi", "");

  	TLegend *leg_histJetDeltaPhi = new TLegend(0.7, 0.70, 0.9, 0.89);
  	leg_histJetDeltaPhi -> SetBorderSize(0);
  	leg_histJetDeltaPhi -> SetFillColor(0);

  	leg_histJetDeltaPhi -> AddEntry(histJetDeltaPhi_Data , "Data" , "F");
  	leg_histJetDeltaPhi -> AddEntry(histJetDeltaPhi_WW, "WW", "F");
  	leg_histJetDeltaPhi -> AddEntry(histJetDeltaPhi_ttbar   , "ttbar"   , "F");

  	c -> Draw();
  	c -> SetLogy();
  	
	histJetDeltaPhi_Data  -> SetLineColor(kBlue);
  	histJetDeltaPhi_Data  -> Scale((histJetDeltaPhi_WW -> Integral() + histJetDeltaPhi_ttbar -> Integral())/histJetDeltaPhi_Data -> Integral());
  	histJetDeltaPhi_WW -> SetLineColor(kBlack);
  	histJetDeltaPhi_WW -> SetFillColor(kGreen);
  	histJetDeltaPhi_ttbar    -> SetLineColor(kBlack);
  	histJetDeltaPhi_ttbar    -> SetFillColor(kRed);

  	hs_histJetDeltaPhi -> Add(histJetDeltaPhi_WW);
  	hs_histJetDeltaPhi -> Add(histJetDeltaPhi_ttbar);

  	hs_histJetDeltaPhi -> Draw("Hist");
  	hs_histJetDeltaPhi -> SetTitle("Jet #DeltaPhi");
  	hs_histJetDeltaPhi -> GetXaxis()->SetTitle("#DeltaPhi");
  	hs_histJetDeltaPhi -> GetYaxis()->SetTitle("Entries");
  	hs_histJetDeltaPhi -> GetYaxis()->SetTitleOffset(1.4);
  	leg_histJetDeltaPhi -> Draw();
  	histJetDeltaPhi_Data -> Draw("same:e1");

	c -> SaveAs("histJetDeltaPhi.png");

}


