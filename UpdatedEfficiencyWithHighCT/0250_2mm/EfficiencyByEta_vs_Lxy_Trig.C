void EfficiencyByEta_vs_Lxy_Trig()
{
//=========Macro generated from canvas: eta_lxy_trig/eta_lxy_trig
//=========  (Mon Aug  1 18:37:47 2016) by ROOT version6.02/05
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
   0.9380665,
   0.9284627,
   0.8928,
   0.8950086,
   0.9311065};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_felx3015[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fely3015[5] = {
   0.01084505,
   0.01152172,
   0.01384255,
   0.01430283,
   0.01360493};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehx3015[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehy3015[5] = {
   0.00941606,
   0.01011988,
   0.01250556,
   0.01285251,
   0.01164488};
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
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetMinimum(0.8721049);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetMaximum(0.954335);
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
   0.7900552,
   0.8117647,
   0.7785714,
   0.7890625,
   0.7981651};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_felx3016[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fely3016[5] = {
   0.0347057,
   0.03485893,
   0.04073058,
   0.04233064,
   0.04591846};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehx3016[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehy3016[5] = {
   0.03122044,
   0.03084633,
   0.03636604,
   0.03734995,
   0.03983124};
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
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetMinimum(0.7273638);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetMaximum(0.8530881);
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
   0.9019019,
   0.880597,
   0.8685567,
   0.8633721,
   0.8271375};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_felx3017[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fely3017[5] = {
   0.01033527,
   0.01201954,
   0.01327099,
   0.01437428,
   0.01786425};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehx3017[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehy3017[5] = {
   0.009488338,
   0.01110055,
   0.01227139,
   0.01326029,
   0.01658024};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fy3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_felx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fely3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehy3017);
   grae->SetName("divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY");
   grae->SetTitle("num_Trig_LEp8_1D_A1_LXY");
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017 = new TH1F("Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017","num_Trig_LEp8_1D_A1_LXY",100,0,11);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetMinimum(0.7990616);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetMaximum(0.9216019);
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
   0.9631579,
   0.9189189,
   0.8947368,
   0.8759124,
   0.8623853};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_felx3018[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fely3018[5] = {
   0.01928057,
   0.02534493,
   0.02896636,
   0.03485718,
   0.04126073};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehx3018[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehy3018[5] = {
   0.01348852,
   0.0202239,
   0.02379369,
   0.02868759,
   0.03373267};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fy3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_felx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fely3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehy3018);
   grae->SetName("divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY");
   grae->SetTitle("num_Trig_Gp8_1D_A1_LXY");
   grae->SetLineStyle(2);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018 = new TH1F("Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018","num_Trig_Gp8_1D_A1_LXY",100,0,11);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetMinimum(0.8055724);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetMaximum(0.9921986);
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
