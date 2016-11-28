void Efficiency_1D_lxy()
{
//=========Macro generated from canvas: lxy/lxy
//=========  (Wed Apr 13 15:33:32 2016) by ROOT version6.02/05
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
   0.9957627,
   0.9951198,
   0.9867485,
   0.9784082,
   0.9659514,
   0.9683771,
   0.9645681,
   0.9619127,
   0.9632664,
   0.9548882,
   0.9289272,
   0.8937729,
   0.8537938,
   0.8436523,
   0.824535,
   0.77301,
   0.2335217};
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
   0.0001822932,
   0.0004261651,
   0.0008295745,
   0.001158522,
   0.001603874,
   0.001680534,
   0.001365652,
   0.00220099,
   0.002253597,
   0.001720757,
   0.002358721,
   0.003154957,
   0.00407478,
   0.004673896,
   0.005369128,
   0.004818087,
   0.006167334};
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
   0.0001749497,
   0.000393298,
   0.0007826258,
   0.001102145,
   0.001535661,
   0.001600335,
   0.001317649,
   0.002088262,
   0.002131448,
   0.001661506,
   0.00228973,
   0.003075735,
   0.003984185,
   0.004564597,
   0.005245008,
   0.004747842,
   0.006280748};
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
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetMinimum(0.150496);
   Graph_divide_num_lxy_barrel_by_den_lxy_barrel3005->SetMaximum(1.072796);
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
   0.9929225,
   0.9901245,
   0.9762995,
   0.9549915,
   0.9472128,
   0.9430266,
   0.9419246,
   0.9466474,
   0.9427748,
   0.9216165,
   0.9060179,
   0.8652645,
   0.8196931,
   0.7821229,
   0.7483778,
   0.7019064,
   0.4117647};
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
   0.0003962079,
   0.001003934,
   0.001899759,
   0.002861315,
   0.003452852,
   0.00396938,
   0.003041629,
   0.004616176,
   0.005110198,
   0.003860403,
   0.004904599,
   0.00647684,
   0.008289229,
   0.01019637,
   0.01219338,
   0.01139988,
   0.01409846};
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
   0.0003758553,
   0.000915809,
   0.00176659,
   0.002702522,
   0.003257877,
   0.003733073,
   0.002902619,
   0.004280604,
   0.004729774,
   0.003697873,
   0.004690978,
   0.006230443,
   0.008009437,
   0.009872236,
   0.01182431,
   0.01116055,
   0.01424074};
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
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetMinimum(0.338103);
   Graph_divide_num_lxy_endcap_by_den_lxy_endcap3006->SetMaximum(1.052862);
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
