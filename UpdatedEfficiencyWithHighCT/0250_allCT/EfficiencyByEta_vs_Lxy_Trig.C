void EfficiencyByEta_vs_Lxy_Trig()
{
//=========Macro generated from canvas: eta_lxy_trig/eta_lxy_trig
//=========  (Mon Aug  1 19:08:13 2016) by ROOT version6.02/05
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
   0.9411753,
   0.9085421,
   0.8958285,
   0.8835782,
   0.9069767};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_felx3015[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fely3015[5] = {
   0.00105993,
   0.002464722,
   0.003402772,
   0.004219443,
   0.004667564};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehx3015[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY_fehy3015[5] = {
   0.001042484,
   0.002407207,
   0.003308902,
   0.004093125,
   0.00447134};
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
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetMinimum(0.8730729);
   Graph_divide_num_Trig_LEp8_1D_A0_LXY_by_den_Trig_LEp8_1D_A0_LXY3015->SetMaximum(0.9485037);
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
   0.90389,
   0.8611872,
   0.83159,
   0.7896652,
   0.8265957};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_felx3016[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fely3016[5] = {
   0.002784302,
   0.006297094,
   0.008997411,
   0.01157339,
   0.01323865};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehx3016[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY_fehy3016[5] = {
   0.002715082,
   0.006071683,
   0.00864007,
   0.01113798,
   0.01251429};
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
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetMinimum(0.7652405);
   Graph_divide_num_Trig_Gp8_1D_A0_LXY_by_den_Trig_Gp8_1D_A0_LXY3016->SetMaximum(0.9194564);
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
   0.950841,
   0.9190796,
   0.8859306,
   0.8449711,
   0.8240298};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_felx3017[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fely3017[5] = {
   0.0008932686,
   0.002360191,
   0.003622144,
   0.005021734,
   0.006428836};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehx3017[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehy3017[5] = {
   0.0008782748,
   0.002299939,
   0.003526244,
   0.004894619,
   0.006252911};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fy3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_felx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehx3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fely3017,divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY_fehy3017);
   grae->SetName("divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY");
   grae->SetTitle("num_Trig_LEp8_1D_A1_LXY");
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017 = new TH1F("Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017","num_Trig_LEp8_1D_A1_LXY",100,0,11);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetMinimum(0.8041891);
   Graph_divide_num_Trig_LEp8_1D_A1_LXY_by_den_Trig_LEp8_1D_A1_LXY3017->SetMaximum(0.9651311);
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
   0.9467447,
   0.9337274,
   0.9078875,
   0.8760331,
   0.8900862};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_felx3018[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fely3018[5] = {
   0.002029835,
   0.004683804,
   0.00730195,
   0.009701895,
   0.0112481};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehx3018[5] = {
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehy3018[5] = {
   0.001960641,
   0.004404378,
   0.006833859,
   0.009113608,
   0.01036382};
   grae = new TGraphAsymmErrors(5,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fy3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_felx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehx3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fely3018,divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY_fehy3018);
   grae->SetName("divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY");
   grae->SetTitle("num_Trig_Gp8_1D_A1_LXY");
   grae->SetLineStyle(2);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018 = new TH1F("Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018","num_Trig_Gp8_1D_A1_LXY",100,0,11);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetMinimum(0.8580937);
   Graph_divide_num_Trig_Gp8_1D_A1_LXY_by_den_Trig_Gp8_1D_A1_LXY3018->SetMaximum(0.9569427);
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
