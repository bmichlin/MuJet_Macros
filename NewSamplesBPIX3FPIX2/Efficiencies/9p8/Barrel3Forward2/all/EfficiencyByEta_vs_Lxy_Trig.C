void EfficiencyByEta_vs_Lxy_Trig()
{
//=========Macro generated from canvas: eta_lxy_trig/eta_lxy_trig
//=========  (Mon May  9 06:59:58 2016) by ROOT version6.02/05
   TCanvas *eta_lxy_trig = new TCanvas("eta_lxy_trig", "eta_lxy_trig",0,0,700,500);
   eta_lxy_trig->Range(-1.875,-0.125,11.875,1.125);
   eta_lxy_trig->SetFillColor(0);
   eta_lxy_trig->SetBorderMode(0);
   eta_lxy_trig->SetBorderSize(2);
   eta_lxy_trig->SetFrameBorderMode(0);
   eta_lxy_trig->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fx3015[5] = {
   1,
   3,
   5,
   7,
   9};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fy3015[5] = {
   0.9742583,
   0.9540823,
   0.9243555,
   0.8879237,
   0.8602223};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_felx3015[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fely3015[5] = {
   0.0002573788,
   0.0007720472,
   0.001288298,
   0.00183892,
   0.002446851};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehx3015[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehy3015[5] = {
   0.0002549099,
   0.0007599881,
   0.001268637,
   0.001813159,
   0.00241184};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fx3015,divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fy3015,divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_felx3015,divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehx3015,divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fely3015,divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehy3015);
   grae->SetName("divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY");
   grae->SetTitle("num_Trig_LEp8_1D_A0_LXY");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015 = new TH1F("Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015","num_Trig_LEp8_1D_A0_LXY",100,0,11);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetMinimum(0.8461017);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetMaximum(0.986187);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetDirectory(0);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetLineColor(ci);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015);
   
   multigraph->Add(grae,"");
   
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fx3016[5] = {
   1,
   3,
   5,
   7,
   9};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fy3016[5] = {
   0.9608403,
   0.9234379,
   0.8743532,
   0.8333801,
   0.7889624};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_felx3016[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fely3016[5] = {
   0.0006037831,
   0.001979816,
   0.003360832,
   0.004530533,
   0.006030143};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehx3016[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehy3016[5] = {
   0.000595051,
   0.001934553,
   0.003286652,
   0.00443554,
   0.005908598};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fx3016,divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fy3016,divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_felx3016,divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehx3016,divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fely3016,divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehy3016);
   grae->SetName("divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY");
   grae->SetTitle("num_Trig_Gp8_1D_A0_LXY");

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016 = new TH1F("Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016","num_Trig_Gp8_1D_A0_LXY",100,0,11);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetMinimum(0.7650819);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetMaximum(0.9792857);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetDirectory(0);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetLineColor(ci);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016);
   
   multigraph->Add(grae,"");
   
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fx3017[5] = {
   1,
   3,
   5,
   7,
   9};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fy3017[5] = {
   0.9723991,
   0.9512116,
   0.9125674,
   0.8642376,
   0.8236069};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_felx3017[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fely3017[5] = {
   0.0002494781,
   0.0008069219,
   0.001427047,
   0.002099236,
   0.002869486};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehx3017[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehy3017[5] = {
   0.0002473161,
   0.0007945599,
   0.001406471,
   0.002072459,
   0.00283361};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fy3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_felx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fely3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehy3017);
   grae->SetName("divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY");
   grae->SetTitle("num_Trig_LEp8_1D_A1_LXY");
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017 = new TH1F("Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017","num_Trig_LEp8_1D_A1_LXY",100,0,11);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetMinimum(0.8055465);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetMaximum(0.9878373);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetDirectory(0);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetLineColor(ci);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017);
   
   multigraph->Add(grae,"");
   
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fx3018[5] = {
   1,
   3,
   5,
   7,
   9};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fy3018[5] = {
   0.9733318,
   0.9635692,
   0.9357225,
   0.9020265,
   0.8655425};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_felx3018[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fely3018[5] = {
   0.0004868327,
   0.001444671,
   0.002601731,
   0.003808307,
   0.005275159};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehx3018[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehy3018[5] = {
   0.0004784156,
   0.001392561,
   0.002509061,
   0.00368326,
   0.005109427};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fy3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_felx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fely3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehy3018);
   grae->SetName("divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY");
   grae->SetTitle("num_Trig_Gp8_1D_A1_LXY");
   grae->SetLineStyle(2);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018 = new TH1F("Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018","num_Trig_Gp8_1D_A1_LXY",100,0,11);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetMinimum(0.848913);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetMaximum(0.9851645);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetDirectory(0);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetLineColor(ci);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018);
   
   multigraph->Add(grae,"");
   multigraph->Draw("ALP");
   multigraph->GetXaxis()->SetTitle("L_{XY} [cm]");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("Efficiency");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.5866762,0.2447257,0.7858166,0.4535865,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03171247);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("divide_num_LEp8_1D_A0_LXY_by_den_LEp8_1D_A0_LXY","|#eta_{#gamma D}| #leq 0.9 A0","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_Gp8_1D_A0_LXY_by_den_Gp8_1D_A0_LXY","|#eta_{#gamma D}| > 0.9 A0","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_LEp8_1D_A1_LXY_by_den_LEp8_1D_A1_LXY","|#eta_{#gamma D}| #leq 0.9 A1","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_Gp8_1D_A1_LXY_by_den_Gp8_1D_A1_LXY","|#eta_{#gamma D}| > 0.9 A1","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLine *line = new TLine(4.3,0,4.3,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(7.2,0,7.2,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(11,0,11,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(23.9,0,23.9,1);

   ci = TColor::GetColor("#00ff00");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(60.5,0,60.5,1);

   ci = TColor::GetColor("#00ff00");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   eta_lxy_trig->Modified();
   eta_lxy_trig->cd();
   eta_lxy_trig->SetSelected(eta_lxy_trig);
}
