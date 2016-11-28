void Efficiency_1D_eta()
{
//=========Macro generated from canvas: eta/eta
//=========  (Wed Apr 13 15:08:41 2016) by ROOT version6.02/05
   TCanvas *eta = new TCanvas("eta", "eta",0,0,700,500);
   eta->Range(-3.3,-0.15,3.3,1.35);
   eta->SetFillColor(0);
   eta->SetBorderMode(0);
   eta->SetBorderSize(2);
   eta->SetFrameBorderMode(0);
   eta->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   Double_t divide_num_eta_barrel_by_den_eta_barrel_fx3003[18] = {
   -0.85,
   -0.75,
   -0.65,
   -0.55,
   -0.45,
   -0.35,
   -0.25,
   -0.15,
   -0.05,
   0.05,
   0.15,
   0.25,
   0.35,
   0.45,
   0.55,
   0.65,
   0.75,
   0.85};
   Double_t divide_num_eta_barrel_by_den_eta_barrel_fy3003[18] = {
   0.9770314,
   0.9755708,
   0.9722154,
   0.9746485,
   0.9732323,
   0.9760396,
   0.9767176,
   0.9733318,
   0.972547,
   0.9726533,
   0.9753881,
   0.9758364,
   0.9757623,
   0.9731849,
   0.9716241,
   0.9751799,
   0.9741205,
   0.9779165};
   Double_t divide_num_eta_barrel_by_den_eta_barrel_felx3003[18] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t divide_num_eta_barrel_by_den_eta_barrel_fely3003[18] = {
   0.001086046,
   0.001056875,
   0.001094964,
   0.001035998,
   0.001044283,
   0.000988869,
   0.00102401,
   0.001037339,
   0.001030293,
   0.001032868,
   0.0009996094,
   0.001044575,
   0.0009935271,
   0.001036783,
   0.001092989,
   0.001035215,
   0.001071475,
   0.001049284};
   Double_t divide_num_eta_barrel_by_den_eta_barrel_fehx3003[18] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t divide_num_eta_barrel_by_den_eta_barrel_fehy3003[18] = {
   0.001039141,
   0.001014949,
   0.001055331,
   0.0009970892,
   0.001006803,
   0.0009513274,
   0.0009827026,
   0.001000208,
   0.0009946753,
   0.0009969402,
   0.0009622557,
   0.001003156,
   0.0009560612,
   0.0009998893,
   0.001054299,
   0.0009955565,
   0.001030757,
   0.001003718};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(18,divide_num_eta_barrel_by_den_eta_barrel_fx3003,divide_num_eta_barrel_by_den_eta_barrel_fy3003,divide_num_eta_barrel_by_den_eta_barrel_felx3003,divide_num_eta_barrel_by_den_eta_barrel_fehx3003,divide_num_eta_barrel_by_den_eta_barrel_fely3003,divide_num_eta_barrel_by_den_eta_barrel_fehy3003);
   grae->SetName("divide_num_eta_barrel_by_den_eta_barrel");
   grae->SetTitle("num_eta_barrel");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_eta_barrel_by_den_eta_barrel3003 = new TH1F("Graph_divide_num_eta_barrel_by_den_eta_barrel3003","num_eta_barrel",100,-1.08,1.08);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetMinimum(0.9696922);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetMaximum(0.9797591);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetDirectory(0);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetLineColor(ci);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_eta_barrel_by_den_eta_barrel3003);
   
   multigraph->Add(grae,"");
   
   Double_t divide_num_eta_endcap_by_den_eta_endcap_fx3004[30] = {
   -2.35,
   -2.25,
   -2.15,
   -2.05,
   -1.95,
   -1.85,
   -1.75,
   -1.65,
   -1.55,
   -1.45,
   -1.35,
   -1.25,
   -1.15,
   -1.05,
   -0.95,
   0.95,
   1.05,
   1.15,
   1.25,
   1.35,
   1.45,
   1.55,
   1.65,
   1.75,
   1.85,
   1.95,
   2.05,
   2.15,
   2.25,
   2.35};
   Double_t divide_num_eta_endcap_by_den_eta_endcap_fy3004[30] = {
   0.9880823,
   0.975923,
   0.9825109,
   0.9733714,
   0.9778641,
   0.9805112,
   0.981079,
   0.9765828,
   0.976961,
   0.9700044,
   0.9530246,
   0.9494752,
   0.9607295,
   0.9701427,
   0.9815212,
   0.9820256,
   0.9744927,
   0.9537989,
   0.9491312,
   0.9569921,
   0.9685544,
   0.9810668,
   0.9789679,
   0.9833157,
   0.9792312,
   0.9796417,
   0.9861042,
   0.9755614,
   0.9867139,
   0.9820022};
   Double_t divide_num_eta_endcap_by_den_eta_endcap_felx3004[30] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t divide_num_eta_endcap_by_den_eta_endcap_fely3004[30] = {
   0.004744964,
   0.005170007,
   0.003926353,
   0.003992587,
   0.003294798,
   0.002796744,
   0.002438669,
   0.002444881,
   0.002166116,
   0.00221406,
   0.002577287,
   0.002537128,
   0.00226048,
   0.001899012,
   0.001463336,
   0.001436595,
   0.001791421,
   0.002396244,
   0.002586825,
   0.002442785,
   0.002337632,
   0.00202303,
   0.002331941,
   0.002355251,
   0.002826,
   0.003266215,
   0.003126632,
   0.004645374,
   0.004353273,
   0.005649797};
   Double_t divide_num_eta_endcap_by_den_eta_endcap_fehx3004[30] = {
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05};
   Double_t divide_num_eta_endcap_by_den_eta_endcap_fehy3004[30] = {
   0.003527677,
   0.004335764,
   0.00326626,
   0.00351199,
   0.002898827,
   0.00246988,
   0.002178231,
   0.002228159,
   0.00199094,
   0.002070937,
   0.002452719,
   0.002424658,
   0.002145273,
   0.001791823,
   0.001361329,
   0.001335564,
   0.001680209,
   0.002286229,
   0.00247084,
   0.002320322,
   0.002185779,
   0.001839208,
   0.002113588,
   0.002083004,
   0.002510576,
   0.002847767,
   0.002598295,
   0.00396504,
   0.003379377,
   0.004429293};
   grae = new TGraphAsymmErrors(30,divide_num_eta_endcap_by_den_eta_endcap_fx3004,divide_num_eta_endcap_by_den_eta_endcap_fy3004,divide_num_eta_endcap_by_den_eta_endcap_felx3004,divide_num_eta_endcap_by_den_eta_endcap_fehx3004,divide_num_eta_endcap_by_den_eta_endcap_fely3004,divide_num_eta_endcap_by_den_eta_endcap_fehy3004);
   grae->SetName("divide_num_eta_endcap_by_den_eta_endcap");
   grae->SetTitle("num_eta_endcap");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(2);
   
   TH1F *Graph_divide_num_eta_endcap_by_den_eta_endcap3004 = new TH1F("Graph_divide_num_eta_endcap_by_den_eta_endcap3004","num_eta_endcap",100,-2.88,2.88);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetMinimum(0.9420378);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetMaximum(0.9961166);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetDirectory(0);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetLineColor(ci);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_eta_endcap_by_den_eta_endcap3004);
   
   multigraph->Add(grae,"");
   multigraph->Draw("ALP");
   multigraph->GetXaxis()->SetTitle("#eta");
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
   TLegendEntry *entry=leg->AddEntry("divide_num_eta_barrel_by_den_eta_barrel","|#eta_{#mu}| #leq 0.9","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("divide_num_eta_endcap_by_den_eta_endcap","|#eta_{#mu}| > 0.9","L");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   eta->Modified();
   eta->cd();
   eta->SetSelected(eta);
}
