void norm_data_sps_dps()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Jul 18 17:26:34 2016) by ROOT version6.02/05
   TCanvas *c1 = new TCanvas("c1", "c1",1,1,700,476);
   c1->Range(-0.625,-4.213275,5.625,8.772776);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *t1_data_jpsi_DeltaRapidityA3 = new TH1F("t1_data_jpsi_DeltaRapidityA3","CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.83 fb^{-1}",10,0,5);
   t1_data_jpsi_DeltaRapidityA3->SetBinContent(1,0.7906976);
   t1_data_jpsi_DeltaRapidityA3->SetBinContent(2,4.790698);
   t1_data_jpsi_DeltaRapidityA3->SetBinContent(3,2.046512);
   t1_data_jpsi_DeltaRapidityA3->SetBinContent(4,-1.302326);
   t1_data_jpsi_DeltaRapidityA3->SetBinContent(5,-0.6511628);
   t1_data_jpsi_DeltaRapidityA3->SetBinContent(6,-0.6511628);
   t1_data_jpsi_DeltaRapidityA3->SetEntries(5.023256);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("t1_data_jpsi_DeltaRapidityA");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 5      ");
   AText = ptstats->AddText("Mean  =  0.162");
   AText = ptstats->AddText("RMS   =  1.129");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   t1_data_jpsi_DeltaRapidityA3->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(t1_data_jpsi_DeltaRapidityA3);
   t1_data_jpsi_DeltaRapidityA3->GetXaxis()->SetTitle("|#Delta y|");
   t1_data_jpsi_DeltaRapidityA3->GetXaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityA3->GetXaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityA3->GetXaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityA3->GetXaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityA3->GetYaxis()->SetTitle("Events/0.5 GeV");
   t1_data_jpsi_DeltaRapidityA3->GetYaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityA3->GetYaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityA3->GetYaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityA3->GetYaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityA3->GetZaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityA3->GetZaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityA3->GetZaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityA3->GetZaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityA3->Draw("EP");
   
   TH1F *t1_sps_jpsi_DeltaRapidity4 = new TH1F("t1_sps_jpsi_DeltaRapidity4","t1_sps_jpsi_DeltaRapidity",10,0,5);
   t1_sps_jpsi_DeltaRapidity4->SetBinContent(1,4.368217);
   t1_sps_jpsi_DeltaRapidity4->SetBinContent(2,4.585271);
   t1_sps_jpsi_DeltaRapidity4->SetBinContent(3,3.662791);
   t1_sps_jpsi_DeltaRapidity4->SetBinContent(4,1.031008);
   t1_sps_jpsi_DeltaRapidity4->SetBinContent(5,0.3527132);
   t1_sps_jpsi_DeltaRapidity4->SetEntries(516);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   t1_sps_jpsi_DeltaRapidity4->SetLineColor(ci);
   t1_sps_jpsi_DeltaRapidity4->GetXaxis()->SetLabelFont(42);
   t1_sps_jpsi_DeltaRapidity4->GetXaxis()->SetLabelSize(0.035);
   t1_sps_jpsi_DeltaRapidity4->GetXaxis()->SetTitleSize(0.035);
   t1_sps_jpsi_DeltaRapidity4->GetXaxis()->SetTitleFont(42);
   t1_sps_jpsi_DeltaRapidity4->GetYaxis()->SetLabelFont(42);
   t1_sps_jpsi_DeltaRapidity4->GetYaxis()->SetLabelSize(0.035);
   t1_sps_jpsi_DeltaRapidity4->GetYaxis()->SetTitleSize(0.035);
   t1_sps_jpsi_DeltaRapidity4->GetYaxis()->SetTitleFont(42);
   t1_sps_jpsi_DeltaRapidity4->GetZaxis()->SetLabelFont(42);
   t1_sps_jpsi_DeltaRapidity4->GetZaxis()->SetLabelSize(0.035);
   t1_sps_jpsi_DeltaRapidity4->GetZaxis()->SetTitleSize(0.035);
   t1_sps_jpsi_DeltaRapidity4->GetZaxis()->SetTitleFont(42);
   t1_sps_jpsi_DeltaRapidity4->Draw("same");
   
   TH1F *t1_dps_jpsi_DeltaRapidity5 = new TH1F("t1_dps_jpsi_DeltaRapidity5","t1_dps_jpsi_DeltaRapidity",10,0,5);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(1,1.352217);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(2,1.789413);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(3,2.384258);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(4,2.767007);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(5,2.353378);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(6,1.704086);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(7,0.9450894);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(8,0.5550267);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(9,0.1478988);
   t1_dps_jpsi_DeltaRapidity5->SetBinContent(10,0.001625261);
   t1_dps_jpsi_DeltaRapidity5->SetEntries(17228);

   ci = TColor::GetColor("#ff0000");
   t1_dps_jpsi_DeltaRapidity5->SetLineColor(ci);
   t1_dps_jpsi_DeltaRapidity5->GetXaxis()->SetLabelFont(42);
   t1_dps_jpsi_DeltaRapidity5->GetXaxis()->SetLabelSize(0.035);
   t1_dps_jpsi_DeltaRapidity5->GetXaxis()->SetTitleSize(0.035);
   t1_dps_jpsi_DeltaRapidity5->GetXaxis()->SetTitleFont(42);
   t1_dps_jpsi_DeltaRapidity5->GetYaxis()->SetLabelFont(42);
   t1_dps_jpsi_DeltaRapidity5->GetYaxis()->SetLabelSize(0.035);
   t1_dps_jpsi_DeltaRapidity5->GetYaxis()->SetTitleSize(0.035);
   t1_dps_jpsi_DeltaRapidity5->GetYaxis()->SetTitleFont(42);
   t1_dps_jpsi_DeltaRapidity5->GetZaxis()->SetLabelFont(42);
   t1_dps_jpsi_DeltaRapidity5->GetZaxis()->SetLabelSize(0.035);
   t1_dps_jpsi_DeltaRapidity5->GetZaxis()->SetTitleSize(0.035);
   t1_dps_jpsi_DeltaRapidity5->GetZaxis()->SetTitleFont(42);
   t1_dps_jpsi_DeltaRapidity5->Draw("same");
   
   TLegend *leg = new TLegend(0.6203438,0.5957895,0.752149,0.7810526,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("t1_data_jpsi_DeltaRapidityA","DATA (After subtraction)","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("t1_sps_jpsi_DeltaRapidity","J#psi J#psi MC SPS","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("t1_dps_jpsi_DeltaRapidity","J#psi J#psi MC DPS","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.1832471,0.9161864,0.8167529,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.83 fb^{-1}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
