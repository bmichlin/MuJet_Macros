void Efficiency_1D_LXY()
{
//=========Macro generated from canvas: effxy/effxy
//=========  (Mon Aug  1 23:45:26 2016) by ROOT version6.02/05
   TCanvas *effxy = new TCanvas("effxy", "effxy",0,0,700,500);
   effxy->Range(-1.375,-0.125,12.375,1.125);
   effxy->SetFillColor(0);
   effxy->SetBorderMode(0);
   effxy->SetBorderSize(2);
   effxy->SetFrameBorderMode(0);
   effxy->SetFrameBorderMode(0);
   
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fx3001[5] = {
   1,
   3,
   5,
   7,
   9};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fy3001[5] = {
   0.9341505,
   0.8997514,
   0.8841243,
   0.8665257,
   0.8924793};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_felx3001[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fely3001[5] = {
   0.001003823,
   0.00230882,
   0.00320931,
   0.00402482,
   0.004469562};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fehx3001[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fehy3001[5] = {
   0.0009899076,
   0.002263076,
   0.003134989,
   0.003926315,
   0.004315216};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fx3001,divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fy3001,divide_num_1D_A0_LXY_by_den_1D_A0_LXY_felx3001,divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fehx3001,divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fely3001,divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fehy3001);
   grae->SetName("divide_num_1D_A0_LXY_by_den_1D_A0_LXY");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001 = new TH1F("Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001","",100,0,11);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->SetMinimum(0);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->SetMaximum(1);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->SetDirectory(0);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->SetLineColor(ci);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetXaxis()->SetTitle("L_{XY} [cm]");
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetYaxis()->SetTitle("Efficiency");
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A0_LXY_by_den_1D_A0_LXY3001);
   
   grae->Draw("alp");
   
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fx3002[5] = {
   1,
   3,
   5,
   7,
   9};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fy3002[5] = {
   0.950111,
   0.9217948,
   0.889911,
   0.8509987,
   0.8367782};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_felx3002[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fely3002[5] = {
   0.0008139992,
   0.002092569,
   0.003219453,
   0.004424423,
   0.005574153};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehx3002[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehy3002[5] = {
   0.0008017087,
   0.00204323,
   0.003140237,
   0.004320349,
   0.005427813};
   grae = new TGraphAsymmErrors(5,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fx3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fy3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_felx3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehx3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fely3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehy3002);
   grae->SetName("divide_num_1D_A1_LXY_by_den_1D_A1_LXY");
   grae->SetTitle("num_1D_A1_LXY");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002 = new TH1F("Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002","num_1D_A1_LXY",100,0,11);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetMinimum(0.8192332);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetMaximum(0.9628836);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetDirectory(0);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetLineColor(ci);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002);
   
   grae->Draw("same");
   
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
   effxy->Modified();
   effxy->cd();
   effxy->SetSelected(effxy);

   TLine *line = new TLine(4.0,0,4.0,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(6.9,0,6.9,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();

   line = new TLine(9.8,0,9.8,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();


}
