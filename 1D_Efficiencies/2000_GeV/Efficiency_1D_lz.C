void Efficiency_1D_lz()
{
//=========Macro generated from canvas: lz/lz
//=========  (Wed Apr 13 15:33:32 2016) by ROOT version6.02/05
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
   0.9886572,
   0.9622711,
   0.9474009,
   0.9356901,
   0.9314097,
   0.92324,
   0.9140195,
   0.9037642,
   0.8877944,
   0.8567794,
   0.8021858,
   0.7831197,
   0.7315789,
   0.7032609,
   0.6258865,
   0.4542484,
   0.1463415};
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
   0.0003483951,
   0.001435454,
   0.002179807,
   0.002865258,
   0.003401145,
   0.004074953,
   0.003461333,
   0.005883174,
   0.006917136,
   0.005806845,
   0.007897104,
   0.009945773,
   0.01270237,
   0.01582546,
   0.02147592,
   0.02084809,
   0.02520216};
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
   0.0003382757,
   0.001385738,
   0.002099316,
   0.002753535,
   0.003255281,
   0.003890572,
   0.003341959,
   0.005587303,
   0.006574169,
   0.005621218,
   0.007671705,
   0.009634912,
   0.01234352,
   0.01536795,
   0.0210106,
   0.02100352,
   0.0289818};
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
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetMinimum(0.03435368);
   Graph_divide_num_lz_barrel_by_den_lz_barrel3007->SetMaximum(1.075781);
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
   0.994051,
   0.9880736,
   0.9889976,
   0.9826087,
   0.9669421,
   0.9619438,
   0.9551928,
   0.9492647,
   0.9394761,
   0.9417596,
   0.9336471,
   0.9345029,
   0.903681,
   0.8919753,
   0.8846881,
   0.8579677,
   0.8368694};
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
   0.0005792055,
   0.001751509,
   0.002142128,
   0.002930644,
   0.004429316,
   0.005213538,
   0.004195961,
   0.006672743,
   0.008044048,
   0.005157889,
   0.005848744,
   0.006543277,
   0.00787259,
   0.00932409,
   0.01067236,
   0.008889446,
   0.008421034};
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
   0.0005300679,
   0.001541263,
   0.001818185,
   0.002538614,
   0.003947409,
   0.00463856,
   0.00386555,
   0.00597149,
   0.007200405,
   0.004777189,
   0.005422919,
   0.006010406,
   0.007356655,
   0.008692396,
   0.009910571,
   0.008462003,
   0.008094138};
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
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetMinimum(0.8118351);
   Graph_divide_num_lz_endcap_by_den_lz_endcap3008->SetMaximum(1.011194);
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
