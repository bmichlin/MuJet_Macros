void Efficiency_1D_Lz()
{
//=========Macro generated from canvas: effz2/effz2
//=========  (Sun May  8 19:50:17 2016) by ROOT version6.02/05
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
   0.9497664,
   0.8352369,
   0.7736465,
   0.7221919,
   0.6691032,
   0.6171026,
   0.5654461,
   0.5178942,
   0.4762987,
   0.4686089,
   0.4431231,
   0.4425587,
   0.405892,
   0.3758099,
   0.4025157,
   0.4159292,
   0.406953,
   0.4180328,
   0.47851,
   0.3972603};
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
   0.0003776813,
   0.001888041,
   0.00298084,
   0.00401093,
   0.004987718,
   0.006106336,
   0.007164392,
   0.008180106,
   0.00915224,
   0.01029833,
   0.01152114,
   0.01297343,
   0.01437161,
   0.01630869,
   0.01788339,
   0.02144608,
   0.02301524,
   0.02687419,
   0.02806515,
   0.02992261};
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
   0.0003750213,
   0.001870947,
   0.002953553,
   0.003975951,
   0.004950413,
   0.006070055,
   0.007137535,
   0.008170677,
   0.009167905,
   0.01032461,
   0.01158129,
   0.01305032,
   0.01453004,
   0.01658584,
   0.0181373,
   0.02175603,
   0.02341281,
   0.02734502,
   0.02819466,
   0.03066678};
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
   0.9573101,
   0.8647871,
   0.8094263,
   0.7594678,
   0.709336,
   0.6761062,
   0.6352834,
   0.6164713,
   0.5701079,
   0.5601436,
   0.5403409,
   0.4993113,
   0.4912718,
   0.482438,
   0.4975124,
   0.5185185,
   0.4965398,
   0.561753,
   0.5085158,
   0.4255319};
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
   0.00034533,
   0.001831806,
   0.00296606,
   0.004092631,
   0.005186162,
   0.006345238,
   0.007421347,
   0.008614674,
   0.00993463,
   0.01076547,
   0.01218346,
   0.01346069,
   0.01481538,
   0.01654968,
   0.01824037,
   0.02041332,
   0.02163608,
   0.0232458,
   0.02586487,
   0.02658272};
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
   0.0003426925,
   0.001811262,
   0.002931503,
   0.004046101,
   0.005132765,
   0.00628202,
   0.007358555,
   0.008543423,
   0.00987956,
   0.01071034,
   0.01213654,
   0.01346167,
   0.0148303,
   0.01658711,
   0.01824677,
   0.02035398,
   0.02164854,
   0.02298903,
   0.02582145,
   0.02699879};
   grae = new TGraphAsymmErrors(20,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fy3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_felx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehx3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fely3004,divide_num_1D_A1_LZ_by_den_1D_A1_LZ_fehy3004);
   grae->SetName("divide_num_1D_A1_LZ_by_den_1D_A1_LZ");
   grae->SetTitle("num_1D_A1_LZ");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004 = new TH1F("Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004","num_1D_A1_LZ",100,0,88);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMinimum(0.3430788);
   Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ3004->SetMaximum(1.013523);
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
