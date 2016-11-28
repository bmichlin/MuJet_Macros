void Efficiency_1D_lz()
{
//=========Macro generated from canvas: lz/lz
//=========  (Wed Apr 13 15:08:41 2016) by ROOT version6.02/05
   TCanvas *lz = new TCanvas("lz", "lz",0,0,700,500);
   lz->Range(-15,-0.15,95,1.35);
   lz->SetFillColor(0);
   lz->SetBorderMode(0);
   lz->SetBorderSize(2);
   lz->SetFrameBorderMode(0);
   lz->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   Double_t divide_num_lz_barrel_by_den_lz_barrel_fx3007[17] = {
   1,
   3,
   5,
   7,
   9,
   11,
   14,
   17,
   19,
   22.5,
   27.5,
   32.5,
   37.5,
   42.5,
   47.5,
   55,
   70};
   Double_t divide_num_lz_barrel_by_den_lz_barrel_fy3007[17] = {
   0.9976134,
   0.9898425,
   0.9807053,
   0.9748185,
   0.9704225,
   0.9579733,
   0.9559019,
   0.9389124,
   0.9236735,
   0.8824601,
   0.8540373,
   0.7807915,
   0.7501531,
   0.683112,
   0.6520619,
   0.4642857,
   0.0890411};
   Double_t divide_num_lz_barrel_by_den_lz_barrel_felx3007[17] = {
   1,
   1,
   1,
   1,
   1,
   1,
   2,
   1,
   1,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   5,
   10};
   Double_t divide_num_lz_barrel_by_den_lz_barrel_fely3007[17] = {
   0.0001392372,
   0.0006816345,
   0.001256656,
   0.001781536,
   0.002274641,
   0.003003798,
   0.00249921,
   0.004838817,
   0.005748537,
   0.005063788,
   0.006489606,
   0.009072593,
   0.01117414,
   0.01497828,
   0.01793516,
   0.01873799,
   0.01683477};
   Double_t divide_num_lz_barrel_by_den_lz_barrel_fehx3007[17] = {
   1,
   1,
   1,
   1,
   1,
   1,
   2,
   1,
   1,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   5,
   10};
   Double_t divide_num_lz_barrel_by_den_lz_barrel_fehy3007[17] = {
   0.0001317722,
   0.0006403966,
   0.001183361,
   0.00167016,
   0.002121975,
   0.002817651,
   0.002374325,
   0.004516744,
   0.005389598,
   0.004885486,
   0.006264259,
   0.008816593,
   0.01085913,
   0.01461952,
   0.0175288,
   0.01883584,
   0.0199323};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(17,divide_num_lz_barrel_by_den_lz_barrel_fx3007,divide_num_lz_barrel_by_den_lz_barrel_fy3007,divide_num_lz_barrel_by_den_lz_barrel_felx3007,divide_num_lz_barrel_by_den_lz_barrel_fehx3007,divide_num_lz_barrel_by_den_lz_barrel_fely3007,divide_num_lz_barrel_by_den_lz_barrel_fehy3007);
   grae->SetName("divide_num_lz_barrel_by_den_lz_barrel");
   grae->SetTitle("num_lz_barrel");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_lz_barrel_by_den_lz_barrel3007 = new TH1F("Graph_divide_num_lz_barrel_by_den_lz_barrel3007","num_lz_barrel",100,0,88);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetMinimum(0);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetMaximum(1.090299);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetDirectory(0);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetLineColor(ci);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_lz_barrel_by_den_lz_barrel3007);
   
   multigraph->Add(grae,"");
   
   Double_t divide_num_lz_endcap_by_den_lz_endcap_fx3008[17] = {
   1,
   3,
   5,
   7,
   9,
   11,
   14,
   17,
   19,
   22.5,
   27.5,
   32.5,
   37.5,
   42.5,
   47.5,
   55,
   70};
   Double_t divide_num_lz_endcap_by_den_lz_endcap_fy3008[17] = {
   0.9995613,
   0.9990253,
   0.9988703,
   0.9988802,
   0.9963925,
   0.997992,
   0.9943757,
   0.9910448,
   0.9886548,
   0.9883974,
   0.9880478,
   0.9913952,
   0.9677862,
   0.9778689,
   0.9666012,
   0.9452214,
   0.9143519};
   Double_t divide_num_lz_endcap_by_den_lz_endcap_felx3008[17] = {
   1,
   1,
   1,
   1,
   1,
   1,
   2,
   1,
   1,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   5,
   10};
   Double_t divide_num_lz_endcap_by_den_lz_endcap_fely3008[17] = {
   0.0001666583,
   0.0004802961,
   0.0006741495,
   0.0008845415,
   0.001535341,
   0.001584873,
   0.001554157,
   0.003381807,
   0.003884508,
   0.002417887,
   0.002949369,
   0.002951693,
   0.005315094,
   0.005061172,
   0.00662969,
   0.006059858,
   0.006452447};
   Double_t divide_num_lz_endcap_by_den_lz_endcap_fehx3008[17] = {
   1,
   1,
   1,
   1,
   1,
   1,
   2,
   1,
   1,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   5,
   10};
   Double_t divide_num_lz_endcap_by_den_lz_endcap_fehy3008[17] = {
   0.0001248496,
   0.0003372103,
   0.000448025,
   0.0005358545,
   0.001120516,
   0.0009607732,
   0.001244915,
   0.002542914,
   0.002986384,
   0.002032244,
   0.002413408,
   0.002266709,
   0.004626508,
   0.00420183,
   0.005633487,
   0.005513579,
   0.006054135};
   grae = new TGraphAsymmErrors(17,divide_num_lz_endcap_by_den_lz_endcap_fx3008,divide_num_lz_endcap_by_den_lz_endcap_fy3008,divide_num_lz_endcap_by_den_lz_endcap_felx3008,divide_num_lz_endcap_by_den_lz_endcap_fehx3008,divide_num_lz_endcap_by_den_lz_endcap_fely3008,divide_num_lz_endcap_by_den_lz_endcap_fehy3008);
   grae->SetName("divide_num_lz_endcap_by_den_lz_endcap");
   grae->SetTitle("num_lz_endcap");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_lz_endcap_by_den_lz_endcap3008 = new TH1F("Graph_divide_num_lz_endcap_by_den_lz_endcap3008","num_lz_endcap",100,0,88);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetMinimum(0.8987207);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetMaximum(1.008865);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetDirectory(0);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetLineColor(ci);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_lz_endcap_by_den_lz_endcap3008);
   
   multigraph->Add(grae,"");
   multigraph->Draw("ALP");
   multigraph->GetXaxis()->SetTitle("L_{z} [cm]");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("Efficiency");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.6982759,0.6701903,0.8979885,0.8794926,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03171247);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("divide_num_lz_barrel_by_den_lz_barrel","|#eta_{#mu}| #leq 0.9","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_lz_endcap_by_den_lz_endcap","|#eta_{#mu}| > 0.9","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLine *line = new TLine(34.5,0,34.5,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(46.5,0,46.5,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   lz->Modified();
   lz->cd();
   lz->SetSelected(lz);
}
