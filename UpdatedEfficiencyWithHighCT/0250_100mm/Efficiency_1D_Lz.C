void Efficiency_1D_Lz()
{
//=========Macro generated from canvas: effz2/effz2
//=========  (Mon Aug  1 18:48:54 2016) by ROOT version6.02/05
   TCanvas *effz2 = new TCanvas("effz2", "effz2",0,0,700,500);
   effz2->Range(-2.2,-0.125,19.8,1.125);
   effz2->SetFillColor(0);
   effz2->SetBorderMode(0);
   effz2->SetBorderSize(2);
   effz2->SetFrameBorderMode(0);
   effz2->SetFrameBorderMode(0);
   
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fx3003[4] = {
   2,
   6,
   10,
   14};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fy3003[4] = {
   0.9166667,
   0.3333333,
   0,
   0};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_felx3003[4] = {
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fely3003[4] = {
   0.09950718,
   0.2773754,
   0,
   0};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehx3003[4] = {
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehy3003[4] = {
   0.05363915,
   0.4145347,
   0.8413447,
   0.8413447};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fy3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_felx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fely3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehy3003);
   grae->SetName("divide_num_1D_A0_LZ_by_den_1D_A0_LZ");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003 = new TH1F("Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003","",100,0,17.6);
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
   
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004[6] = {
   2,
   6,
   10,
   14,
   18,
   22};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004[6] = {
   0.6818182,
   0.7142857,
   1,
   1,
   0,
   1};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004[6] = {
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004[6] = {
   0.1287501,
   0.2599379,
   0.3688776,
   0.6016845,
   0,
   0.8413447};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004[6] = {
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004[6] = {
   0.1090792,
   0.182129,
   0,
   0,
   0.8413447,
   0};
   grae = new TGraphAsymmErrors(6,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004);
   grae->SetName("divide_num_1D_A1_LZ_by_den_1D_A1_LZ");
   grae->SetTitle("num_1D_A1_LZ");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004 = new TH1F("Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004","num_1D_A1_LZ",100,0,26.4);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMinimum(0);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMaximum(1.1);
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
