void data_template_rapidity()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Jul 18 17:06:53 2016) by ROOT version6.02/05
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,700,500);
   c1->Range(-0.625,-1.727549,5.625,15.54794);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *t1_data_jpsi_DeltaRapidityA1 = new TH1F("t1_data_jpsi_DeltaRapidityA1","CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.83 fb^{-1}",10,0,5);
   t1_data_jpsi_DeltaRapidityA1->SetBinContent(1,6);
   t1_data_jpsi_DeltaRapidityA1->SetBinContent(2,10);
   t1_data_jpsi_DeltaRapidityA1->SetBinContent(3,4);
   t1_data_jpsi_DeltaRapidityA1->SetEntries(20);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("t1_data_jpsi_DeltaRapidityA");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 20     ");
   AText = ptstats->AddText("Mean  = 0.6604");
   AText = ptstats->AddText("RMS   = 0.4088");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   t1_data_jpsi_DeltaRapidityA1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(t1_data_jpsi_DeltaRapidityA1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   t1_data_jpsi_DeltaRapidityA1->SetLineColor(ci);
   t1_data_jpsi_DeltaRapidityA1->GetXaxis()->SetTitle("|#Delta y|");
   t1_data_jpsi_DeltaRapidityA1->GetXaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityA1->GetXaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityA1->GetXaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityA1->GetXaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityA1->GetYaxis()->SetTitle("Events/0.5 GeV");
   t1_data_jpsi_DeltaRapidityA1->GetYaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityA1->GetYaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityA1->GetYaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityA1->GetYaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityA1->GetZaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityA1->GetZaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityA1->GetZaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityA1->GetZaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityA1->Draw("EP");
   
   TH1F *t1_data_jpsi_DeltaRapidityC2 = new TH1F("t1_data_jpsi_DeltaRapidityC2","CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.83 fb^{-1}",10,0,5);
   t1_data_jpsi_DeltaRapidityC2->SetBinContent(1,2.232558);
   t1_data_jpsi_DeltaRapidityC2->SetBinContent(2,2.232558);
   t1_data_jpsi_DeltaRapidityC2->SetBinContent(3,0.8372093);
   t1_data_jpsi_DeltaRapidityC2->SetBinContent(4,0.5581396);
   t1_data_jpsi_DeltaRapidityC2->SetBinContent(5,0.2790698);
   t1_data_jpsi_DeltaRapidityC2->SetBinContent(6,0.2790698);
   t1_data_jpsi_DeltaRapidityC2->SetEntries(46);

   ci = TColor::GetColor("#000099");
   t1_data_jpsi_DeltaRapidityC2->SetLineColor(ci);
   t1_data_jpsi_DeltaRapidityC2->GetXaxis()->SetTitle("|#Delta y|");
   t1_data_jpsi_DeltaRapidityC2->GetXaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityC2->GetXaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityC2->GetXaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityC2->GetXaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityC2->GetYaxis()->SetTitle("Events/0.5 GeV");
   t1_data_jpsi_DeltaRapidityC2->GetYaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityC2->GetYaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityC2->GetYaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityC2->GetYaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityC2->GetZaxis()->SetLabelFont(42);
   t1_data_jpsi_DeltaRapidityC2->GetZaxis()->SetLabelSize(0.035);
   t1_data_jpsi_DeltaRapidityC2->GetZaxis()->SetTitleSize(0.035);
   t1_data_jpsi_DeltaRapidityC2->GetZaxis()->SetTitleFont(42);
   t1_data_jpsi_DeltaRapidityC2->Draw("same");
   
   TLegend *leg = new TLegend(0.6203438,0.5957895,0.752149,0.7810526,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("t1_data_jpsi_DeltaRapidityA","|#Delta y| Reg. A","L");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("t1_data_jpsi_DeltaRapidityC","|#Delta y| Reg. C (norm)","L");

   ci = TColor::GetColor("#000099");
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
