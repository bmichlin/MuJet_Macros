void Lxy_fit()
{
//=========Macro generated from canvas: c/
//=========  (Mon Jul 18 16:37:27 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "",0,0,700,500);
   gStyle->SetOptStat(0);
   c->Range(-0.475,-2.029663,0.9138889,18.26697);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLeftMargin(0.126);
   c->SetRightMargin(0.154);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH1F *t1_data_regionA_dimuon1_lxy1 = new TH1F("t1_data_regionA_dimuon1_lxy1","CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.83 fb^{-1}",25,-0.3,0.7);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(8,12);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(9,3);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(11,1);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(13,1);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(14,1);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(17,1);
   t1_data_regionA_dimuon1_lxy1->SetBinContent(18,1);
   t1_data_regionA_dimuon1_lxy1->SetEntries(20);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   t1_data_regionA_dimuon1_lxy1->SetLineColor(ci);
   t1_data_regionA_dimuon1_lxy1->GetXaxis()->SetTitle("#mu#mu_{1} L_{XY} [cm]");
   t1_data_regionA_dimuon1_lxy1->GetXaxis()->SetLabelFont(42);
   t1_data_regionA_dimuon1_lxy1->GetXaxis()->SetLabelSize(0.035);
   t1_data_regionA_dimuon1_lxy1->GetXaxis()->SetTitleSize(0.035);
   t1_data_regionA_dimuon1_lxy1->GetXaxis()->SetTitleFont(42);
   t1_data_regionA_dimuon1_lxy1->GetYaxis()->SetTitle("Events/0.04 GeV");
   t1_data_regionA_dimuon1_lxy1->GetYaxis()->SetLabelFont(42);
   t1_data_regionA_dimuon1_lxy1->GetYaxis()->SetLabelSize(0.035);
   t1_data_regionA_dimuon1_lxy1->GetYaxis()->SetTitleSize(0.035);
   t1_data_regionA_dimuon1_lxy1->GetYaxis()->SetTitleOffset(0.94);
   t1_data_regionA_dimuon1_lxy1->GetYaxis()->SetTitleFont(42);
   t1_data_regionA_dimuon1_lxy1->GetZaxis()->SetLabelFont(42);
   t1_data_regionA_dimuon1_lxy1->GetZaxis()->SetLabelSize(0.035);
   t1_data_regionA_dimuon1_lxy1->GetZaxis()->SetTitleSize(0.035);
   t1_data_regionA_dimuon1_lxy1->GetZaxis()->SetTitleFont(42);
   t1_data_regionA_dimuon1_lxy1->Draw("Ep");
   
   TH1F *Fraction fit to hist: t1_data_regionA_dimuon1_lxy2 = new TH1F("Fraction fit to hist: t1_data_regionA_dimuon1_lxy2","t1_data_regionA_dimuon1_lxy",25,-0.3,0.7);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(1,3.291198e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(2,2.771535e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(3,2.598314e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(4,3.984082e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(5,2.944756e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(6,4.157303e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(7,5.889513e-09);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(8,7.300669);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(9,2.539363);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(10,0.9522611);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(11,1.269682);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(12,1.587102);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(13,0.6348408);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(14,0.9522611);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(15,0.3174204);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(16,0.6348408);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(17,0.9522611);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(18,0.3174204);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(19,0.3174204);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(20,0.3174204);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(21,0.9522611);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(23,0.3174204);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetBinContent(25,0.6348408);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetEntries(25);

   ci = TColor::GetColor("#000099");
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->SetLineColor(ci);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetXaxis()->SetLabelFont(42);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetXaxis()->SetLabelSize(0.035);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetXaxis()->SetTitleSize(0.035);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetXaxis()->SetTitleFont(42);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetYaxis()->SetLabelFont(42);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetYaxis()->SetLabelSize(0.035);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetYaxis()->SetTitleSize(0.035);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetYaxis()->SetTitleFont(42);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetZaxis()->SetLabelFont(42);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetZaxis()->SetLabelSize(0.035);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetZaxis()->SetTitleSize(0.035);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->GetZaxis()->SetTitleFont(42);
   Fraction fit to hist: t1_data_regionA_dimuon1_lxy2->Draw("same");
   
   TLegend *leg = new TLegend(0.4,0.6,0.8,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("t1_data_regionA_dimuon1_lxy","DATA (Region A)","PL");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Fraction fit to hist: t1_data_regionA_dimuon1_lxy","(prompt + non-prompt) J#psi J#psi","FL");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.93,0.935,1.47,1,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextAlign(22);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.15,0.9163333,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("CMS 2015  #sqrt{s} = 13 TeV  L_{int} = 2.83 fb^{-1}");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
