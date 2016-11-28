void Efficiency_1D_Lz()
{
//=========Macro generated from canvas: effz2/effz2
//=========  (Mon May  9 06:59:58 2016) by ROOT version6.02/05
   TCanvas *effz2 = new TCanvas("effz2", "effz2",0,0,700,500);
   effz2->Range(-6.6,-0.125,59.4,1.125);
   effz2->SetFillColor(0);
   effz2->SetBorderMode(0);
   effz2->SetBorderSize(2);
   effz2->SetFrameBorderMode(0);
   effz2->SetFrameBorderMode(0);
   
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fx3003[12] = {
   2,
   6,
   10,
   14,
   18,
   22,
   26,
   30,
   34,
   38,
   42,
   46};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fy3003[12] = {
   0.9619457,
   0.9012275,
   0.8521709,
   0.838067,
   0.8569009,
   0.8731466,
   0.8815789,
   0.8624339,
   0.8139535,
   0.8135593,
   0.8823529,
   0.7272727};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_felx3003[12] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fely3003[12] = {
   0.0003409029,
   0.00202253,
   0.004806647,
   0.007943218,
   0.01092591,
   0.01498036,
   0.02153193,
   0.02978046,
   0.05168921,
   0.06490718,
   0.08329135,
   0.1960724};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehx3003[12] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehy3003[12] = {
   0.000338008,
   0.001986705,
   0.00468306,
   0.007648661,
   0.01029671,
   0.01367717,
   0.01880421,
   0.02555435,
   0.04344014,
   0.05264364,
   0.05543815,
   0.1443959};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(12,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fy3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_felx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fely3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehy3003);
   grae->SetName("divide_num_1D_A0_LZ_by_den_1D_A0_LZ");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003 = new TH1F("Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003","",100,0,52.8);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetMinimum(0);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetMaximum(1);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetDirectory(0);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetLineColor(ci);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetTitle("L_{Z} [cm]");
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetTitle("Efficiency");
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003);
   
   grae->Draw("alp");
   
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004[12] = {
   2,
   6,
   10,
   14,
   18,
   22,
   26,
   30,
   34,
   38,
   42,
   46};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004[12] = {
   0.9653937,
   0.9142383,
   0.8639669,
   0.8245756,
   0.8342977,
   0.890873,
   0.8517915,
   0.882716,
   0.852071,
   0.862069,
   0.8727273,
   0.8571429};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004[12] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004[12] = {
   0.0003186189,
   0.001840889,
   0.003947643,
   0.00646691,
   0.008970801,
   0.0107236,
   0.0157528,
   0.0206927,
   0.03252187,
   0.03977008,
   0.06180901,
   0.1582707};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004[12] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004[12] = {
   0.0003158285,
   0.001806154,
   0.003854893,
   0.006288236,
   0.008608356,
   0.009909343,
   0.01454299,
   0.0181311,
   0.02792132,
   0.03272694,
   0.04572118,
   0.0917089};
   grae = new TGraphAsymmErrors(12,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004);
   grae->SetName("divide_num_1D_A1_LZ_by_den_1D_A1_LZ");
   grae->SetTitle("num_1D_A1_LZ");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004 = new TH1F("Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004","num_1D_A1_LZ",100,0,52.8);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMinimum(0.6721885);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMaximum(0.9923932);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetDirectory(0);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetLineColor(ci);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004);
   
   grae->Draw("");
   
   TLegend *leg = new TLegend(0.1690544,0.1476793,0.3008596,0.3333333,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("divide_num_1D_A0_LXY_by_den_1D_A0_LXY","#gamma_{D1}","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_1D_A1_LXY_by_den_1D_A1_LXY","#gamma_{D2}","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   effz2->Modified();
   effz2->cd();
   effz2->SetSelected(effz2);
}
