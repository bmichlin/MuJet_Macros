void Efficiency_1D_Lz()
{
//=========Macro generated from canvas: effz2/effz2
//=========  (Sun May  8 16:55:36 2016) by ROOT version6.02/05
   TCanvas *effz2 = new TCanvas("effz2", "effz2",0,0,700,500);
   effz2->Range(-11,-0.125,99,1.125);
   effz2->SetFillColor(0);
   effz2->SetBorderMode(0);
   effz2->SetBorderSize(2);
   effz2->SetFrameBorderMode(0);
   effz2->SetFrameBorderMode(0);
   
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fx3003[20] = {
   2,
   6,
   10,
   14,
   18,
   22,
   26,
   30,
   34,
   38,
   42,
   46,
   50,
   54,
   58,
   62,
   66,
   70,
   74,
   78};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fy3003[20] = {
   0.9097283,
   0.8153809,
   0.7650046,
   0.6917394,
   0.6353051,
   0.5766753,
   0.5081967,
   0.4503106,
   0.3914174,
   0.3969231,
   0.403397,
   0.3928571,
   0.3674121,
   0.2946058,
   0.2642487,
   0.3287671,
   0.2980769,
   0.3448276,
   0.4457831,
   0.2727273};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_felx3003[20] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fely3003[20] = {
   0.001299055,
   0.004372458,
   0.006619056,
   0.008694134,
   0.01068309,
   0.01291034,
   0.01472358,
   0.01646336,
   0.01809214,
   0.01977928,
   0.02342616,
   0.02562195,
   0.02835329,
   0.03046796,
   0.03293235,
   0.04088671,
   0.04728892,
   0.05439592,
   0.05946284,
   0.05805191};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehx3003[20] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehy3003[20] = {
   0.001282558,
   0.004294866,
   0.006494534,
   0.008562835,
   0.01055426,
   0.01280903,
   0.01470976,
   0.01656949,
   0.01838474,
   0.02010884,
   0.02385506,
   0.02619595,
   0.02924836,
   0.03228813,
   0.0355661,
   0.04342779,
   0.05156146,
   0.05833563,
   0.0609021,
   0.06581202};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fy3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_felx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehx3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fely3003,divide_num_1D_A0_LZ_by_den_1D_A0_LZ_fehy3003);
   grae->SetName("divide_num_1D_A0_LZ_by_den_1D_A0_LZ");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003 = new TH1F("Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003","",100,0,88);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetMinimum(0);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetMaximum(1);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetDirectory(0);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->SetLineColor(ci);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetTitle("L_{Z} [cm]");
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetTitle("Efficiency");
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ3003);
   
   grae->Draw("alp");
   
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004[20] = {
   2,
   6,
   10,
   14,
   18,
   22,
   26,
   30,
   34,
   38,
   42,
   46,
   50,
   54,
   58,
   62,
   66,
   70,
   74,
   78};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004[20] = {
   0.9271922,
   0.8435628,
   0.7853122,
   0.7474325,
   0.676598,
   0.6541865,
   0.5872302,
   0.5715922,
   0.5172414,
   0.4742097,
   0.4679487,
   0.4405063,
   0.4428152,
   0.4628975,
   0.4181818,
   0.4559585,
   0.4152047,
   0.488189,
   0.4351852,
   0.3358779};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004[20] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004[20] = {
   0.001168638,
   0.004304512,
   0.006769976,
   0.008758881,
   0.01125337,
   0.01285369,
   0.01528758,
   0.01739544,
   0.02010939,
   0.02113729,
   0.02403491,
   0.02605227,
   0.02814517,
   0.03120965,
   0.03504747,
   0.03809167,
   0.0399483,
   0.04798562,
   0.05141971,
   0.04354477};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004[20] = {
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2,
   2};
   Double_t divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004[20] = {
   0.001151747,
   0.004211584,
   0.00662114,
   0.008566467,
   0.01105734,
   0.0126381,
   0.015126,
   0.01722593,
   0.02005574,
   0.02122653,
   0.02417803,
   0.02636827,
   0.02849819,
   0.03148687,
   0.03583982,
   0.03857942,
   0.04101302,
   0.0481871,
   0.05272857,
   0.04626877};
   grae = new TGraphAsymmErrors(20,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004);
   grae->SetName("divide_num_1D_A1_LZ_by_den_1D_A1_LZ");
   grae->SetTitle("num_1D_A1_LZ");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004 = new TH1F("Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004","num_1D_A1_LZ",100,0,88);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMinimum(0.228732);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMaximum(0.991945);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetDirectory(0);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetLineColor(ci);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004);
   
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
   effz2->Modified();
   effz2->cd();
   effz2->SetSelected(effz2);
}
