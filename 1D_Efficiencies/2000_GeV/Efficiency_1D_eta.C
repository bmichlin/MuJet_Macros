void Efficiency_1D_eta()
{
//=========Macro generated from canvas: eta/eta
//=========  (Wed Apr 13 15:33:32 2016) by ROOT version6.02/05
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
   0.9639531,
   0.9606008,
   0.9568353,
   0.9534752,
   0.9585429,
   0.9547056,
   0.9483397,
   0.948807,
   0.9525355,
   0.9517033,
   0.9473658,
   0.9455919,
   0.9531125,
   0.9557743,
   0.9549629,
   0.95906,
   0.9616707,
   0.960975};
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
   0.001545517,
   0.001510845,
   0.001519636,
   0.001559624,
   0.001470092,
   0.001535227,
   0.001660109,
   0.001624224,
   0.001526342,
   0.001543498,
   0.001633725,
   0.001698923,
   0.001543556,
   0.001517635,
   0.001548493,
   0.001496398,
   0.001483848,
   0.001600293};
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
   0.001485479,
   0.001458224,
   0.001471042,
   0.001512207,
   0.001422667,
   0.001487991,
   0.001611918,
   0.001577622,
   0.00148179,
   0.001498754,
   0.0015879,
   0.001651095,
   0.00149745,
   0.00147033,
   0.001500181,
   0.001446685,
   0.001431638,
   0.001540881};
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
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetMinimum(0.9417384);
   Graph_divide_num_eta_barrel_by_den_eta_barrel3003->SetMaximum(0.9675932);
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
   0.9616162,
   0.9628339,
   0.960452,
   0.953271,
   0.9418848,
   0.9611354,
   0.9636429,
   0.964723,
   0.9552058,
   0.9451686,
   0.9164602,
   0.928629,
   0.9418605,
   0.9583038,
   0.9527991,
   0.9585895,
   0.9529938,
   0.9341151,
   0.9109701,
   0.918353,
   0.943619,
   0.9596009,
   0.9631401,
   0.9621922,
   0.9626834,
   0.9491264,
   0.9537534,
   0.9380379,
   0.9485714,
   0.9414062};
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
   0.01070786,
   0.007623546,
   0.00634468,
   0.005881953,
   0.005859533,
   0.004471707,
   0.003908512,
   0.003438873,
   0.003454984,
   0.003473588,
   0.003845235,
   0.003419209,
   0.00306187,
   0.00251879,
   0.002327915,
   0.002173943,
   0.002638839,
   0.003227609,
   0.003783107,
   0.003795872,
   0.003486043,
   0.003310498,
   0.003438642,
   0.003895495,
   0.004297444,
   0.005482948,
   0.006098658,
   0.007905717,
   0.008596466,
   0.01230979};
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
   0.008626922,
   0.006452261,
   0.005547539,
   0.005283901,
   0.005374322,
   0.004047272,
   0.003557846,
   0.003155387,
   0.003226276,
   0.003283565,
   0.003694285,
   0.003277704,
   0.002921224,
   0.002384928,
   0.002226057,
   0.002072461,
   0.002508558,
   0.003090299,
   0.003646343,
   0.003645089,
   0.003299885,
   0.003077952,
   0.003166438,
   0.003559253,
   0.00388856,
   0.004997664,
   0.005453121,
   0.007106262,
   0.007493341,
   0.01042538};
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
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetMinimum(0.9008813);
   Graph_divide_num_eta_endcap_by_den_eta_endcap3004->SetMaximum(0.9765487);
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
