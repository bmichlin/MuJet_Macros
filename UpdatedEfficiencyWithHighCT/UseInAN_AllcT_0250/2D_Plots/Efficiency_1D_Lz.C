void Efficiency_1D_Lz()
{
//=========Macro generated from canvas: effz2/effz2
//=========  (Tue Aug  2 00:21:23 2016) by ROOT version6.02/05
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
   0.9092809,
   0.8134641,
   0.7606431,
   0.6879106,
   0.6349568,
   0.5703658,
   0.5023734,
   0.4442211,
   0.3889586,
   0.3928036,
   0.4016393,
   0.3920596,
   0.375,
   0.2979592,
   0.2587065,
   0.3377483,
   0.2990654,
   0.3333333,
   0.4302326,
   0.2753623};
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
   0.00129935,
   0.004357247,
   0.006593652,
   0.008624043,
   0.01055942,
   0.01267635,
   0.01445506,
   0.01618847,
   0.01774045,
   0.01947775,
   0.0229814,
   0.02524678,
   0.02780989,
   0.03032016,
   0.03200917,
   0.04049681,
   0.04664566,
   0.0528852,
   0.05793477,
   0.05692906};
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
   0.001282935,
   0.004281235,
   0.006473542,
   0.00849819,
   0.01043388,
   0.01258694,
   0.0144512,
   0.01630409,
   0.018029,
   0.01981161,
   0.02340259,
   0.02580892,
   0.02861401,
   0.03208013,
   0.03459529,
   0.04282083,
   0.05077281,
   0.05697316,
   0.0597203,
   0.06424692};
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
   0.9265361,
   0.8412615,
   0.7824226,
   0.7435137,
   0.6746158,
   0.6499339,
   0.583042,
   0.5715884,
   0.5137085,
   0.47343,
   0.4639175,
   0.4402985,
   0.4269663,
   0.4511785,
   0.4069264,
   0.4585366,
   0.4157303,
   0.5111111,
   0.4234234,
   0.3333333};
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
   0.001171558,
   0.004300161,
   0.006745325,
   0.008683526,
   0.01114252,
   0.01268667,
   0.01508265,
   0.01718246,
   0.01971356,
   0.02077924,
   0.02357247,
   0.02581375,
   0.02736418,
   0.03033017,
   0.03398057,
   0.03692793,
   0.03912407,
   0.046628,
   0.05040151,
   0.04276895};
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
   0.001154744,
   0.004209073,
   0.006600368,
   0.008499073,
   0.01095296,
   0.01248335,
   0.0149332,
   0.01701701,
   0.01967253,
   0.02086816,
   0.02372784,
   0.02612521,
   0.0277957,
   0.03067736,
   0.03483801,
   0.03735946,
   0.04013927,
   0.04645008,
   0.05190498,
   0.04545066};
   grae = new TGraphAsymmErrors(20,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004);
   grae->SetName("divide_num_1D_A1_LZ_by_den_1D_A1_LZ");
   grae->SetTitle("num_1D_A1_LZ");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004 = new TH1F("Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004","num_1D_A1_LZ",100,0,88);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMinimum(0.2268517);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMaximum(0.9914035);
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
