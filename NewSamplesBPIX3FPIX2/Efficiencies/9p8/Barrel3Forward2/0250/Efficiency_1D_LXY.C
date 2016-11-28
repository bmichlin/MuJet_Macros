void Efficiency_1D_LXY()
{
//=========Macro generated from canvas: effxy/effxy
//=========  (Mon May  9 06:18:33 2016) by ROOT version6.02/05
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
   0.9341883,
   0.8998185,
   0.8842025,
   0.8665424,
   0.8934934};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_felx3001[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fely3001[5] = {
   0.001004005,
   0.002312699,
   0.003218175,
   0.004040855,
   0.004467551};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fehx3001[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A0_LXY_by_den_1D_A0_LXY_fehy3001[5] = {
   0.0009900762,
   0.00226677,
   0.003143394,
   0.003941565,
   0.004311731};
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
   0.9502086,
   0.9218235,
   0.8905337,
   0.8519118,
   0.8380584};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_felx3002[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fely3002[5] = {
   0.0008135709,
   0.002094211,
   0.003223531,
   0.00443332,
   0.00558011};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehx3002[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehy3002[5] = {
   0.0008012683,
   0.002044777,
   0.003143614,
   0.004328058,
   0.005432025};
   grae = new TGraphAsymmErrors(5,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fx3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fy3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_felx3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehx3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fely3002,divide_num_1D_A1_LXY_by_den_1D_A1_LXY_fehy3002);
   grae->SetName("divide_num_1D_A1_LXY_by_den_1D_A1_LXY");
   grae->SetTitle("num_1D_A1_LXY");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002 = new TH1F("Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002","num_1D_A1_LXY",100,0,11);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetMinimum(0.8206251);
   Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY3002->SetMaximum(0.9628631);
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
   effxy->Modified();
   effxy->cd();
   effxy->SetSelected(effxy);
}
