void Efficiency_1D_lxy()
{
//=========Macro generated from canvas: lxy/lxy
//=========  (Wed Apr 13 15:08:41 2016) by ROOT version6.02/05
   TCanvas *lxy = new TCanvas("lxy", "lxy",0,0,700,500);
   lxy->Range(-15,-0.15,95,1.35);
   lxy->SetFillColor(0);
   lxy->SetBorderMode(0);
   lxy->SetBorderSize(2);
   lxy->SetFrameBorderMode(0);
   lxy->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   Double_t divide_num_lxy_barrel_by_den_lxy_barrel_fx3005[17] = {
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
   Double_t divide_num_lxy_barrel_by_den_lxy_barrel_fy3005[17] = {
   0.9995878,
   0.999656,
   0.9990845,
   0.9992576,
   0.9981497,
   0.9979236,
   0.9969469,
   0.9963142,
   0.9973255,
   0.9965768,
   0.9929766,
   0.9767397,
   0.928305,
   0.9064156,
   0.8791646,
   0.7926339,
   0.2560111};
   Double_t divide_num_lxy_barrel_by_den_lxy_barrel_felx3005[17] = {
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
   Double_t divide_num_lxy_barrel_by_den_lxy_barrel_fely3005[17] = {
   5.141586e-05,
   0.0001016688,
   0.0002076468,
   0.0002357249,
   0.0004027802,
   0.0004706229,
   0.0004305853,
   0.0007718004,
   0.0007404442,
   0.000525577,
   0.0008229321,
   0.001583967,
   0.00289485,
   0.003567207,
   0.004343204,
   0.004199909,
   0.005456812};
   Double_t divide_num_lxy_barrel_by_den_lxy_barrel_fehx3005[17] = {
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
   Double_t divide_num_lxy_barrel_by_den_lxy_barrel_fehy3005[17] = {
   4.597936e-05,
   8.031467e-05,
   0.0001719185,
   0.0001835927,
   0.000335707,
   0.0003897751,
   0.0003801979,
   0.0006473277,
   0.0005925208,
   0.0004595816,
   0.0007409834,
   0.001488136,
   0.002792904,
   0.003451552,
   0.004215036,
   0.004138776,
   0.005533088};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(17,divide_num_lxy_barrel_by_den_lxy_barrel_fx3005,divide_num_lxy_barrel_by_den_lxy_barrel_fy3005,divide_num_lxy_barrel_by_den_lxy_barrel_felx3005,divide_num_lxy_barrel_by_den_lxy_barrel_fehx3005,divide_num_lxy_barrel_by_den_lxy_barrel_fely3005,divide_num_lxy_barrel_by_den_lxy_barrel_fehy3005);
   grae->SetName("divide_num_lxy_barrel_by_den_lxy_barrel");
   grae->SetTitle("num_lxy_barrel");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005 = new TH1F("Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005","num_lxy_barrel",100,0,88);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetMinimum(0.1756361);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetMaximum(1.074655);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetDirectory(0);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetLineColor(ci);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005);
   
   multigraph->Add(grae,"");
   
   Double_t divide_num_lxy_endcap_by_den_lxy_endcap_fx3006[17] = {
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
   Double_t divide_num_lxy_endcap_by_den_lxy_endcap_fy3006[17] = {
   0.9994425,
   0.998982,
   0.9976074,
   0.9973909,
   0.9926923,
   0.9908588,
   0.9887057,
   0.993483,
   0.9891697,
   0.9822362,
   0.9807595,
   0.9591572,
   0.9261142,
   0.8922914,
   0.8647249,
   0.7891156,
   0.5229821};
   Double_t divide_num_lxy_endcap_by_den_lxy_endcap_felx3006[17] = {
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
   Double_t divide_num_lxy_endcap_by_den_lxy_endcap_fely3006[17] = {
   0.000104295,
   0.0003007464,
   0.0005939603,
   0.0007699683,
   0.001382127,
   0.001727006,
   0.001462062,
   0.001918366,
   0.002674425,
   0.0021219,
   0.002442979,
   0.00388258,
   0.005541053,
   0.007602129,
   0.009268774,
   0.009047215,
   0.01211532};
   Double_t divide_num_lxy_endcap_by_den_lxy_endcap_fehx3006[17] = {
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
   Double_t divide_num_lxy_endcap_by_den_lxy_endcap_fehy3006[17] = {
   8.886969e-05,
   0.0002376357,
   0.0004845901,
   0.0006087377,
   0.00117719,
   0.001471594,
   0.00130416,
   0.00151878,
   0.002187665,
   0.001909314,
   0.00218547,
   0.003571411,
   0.005195368,
   0.007172655,
   0.008779259,
   0.008778206,
   0.01208895};
   grae = new TGraphAsymmErrors(17,divide_num_lxy_endcap_by_den_lxy_endcap_fx3006,divide_num_lxy_endcap_by_den_lxy_endcap_fy3006,divide_num_lxy_endcap_by_den_lxy_endcap_felx3006,divide_num_lxy_endcap_by_den_lxy_endcap_fehx3006,divide_num_lxy_endcap_by_den_lxy_endcap_fely3006,divide_num_lxy_endcap_by_den_lxy_endcap_fehy3006);
   grae->SetName("divide_num_lxy_endcap_by_den_lxy_endcap");
   grae->SetTitle("num_lxy_endcap");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006 = new TH1F("Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006","num_lxy_endcap",100,0,88);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetMinimum(0.4620003);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetMaximum(1.048398);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetDirectory(0);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetLineColor(ci);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006);
   
   multigraph->Add(grae,"");
   multigraph->Draw("ALP");
   multigraph->GetXaxis()->SetTitle("L_{xy} [cm]");
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
   TLegendEntry *entry=leg->AddEntry("divide_num_lxy_barrel_by_den_lxy_barrel","|#eta_{#mu}| #leq 0.9","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_lxy_endcap_by_den_lxy_endcap","|#eta_{#mu}| > 0.9","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
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
   lxy->Modified();
   lxy->cd();
   lxy->SetSelected(lxy);
}
