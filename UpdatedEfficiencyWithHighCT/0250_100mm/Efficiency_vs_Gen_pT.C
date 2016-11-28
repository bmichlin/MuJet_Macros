void Efficiency_vs_Gen_pT()
{
//=========Macro generated from canvas: effpt/effpt
//=========  (Mon Aug  1 18:48:54 2016) by ROOT version6.02/05
   TCanvas *effpt = new TCanvas("effpt", "effpt",0,0,700,500);
   effpt->Range(2.999999,-0.1375,141,1.2375);
   effpt->SetFillColor(0);
   effpt->SetBorderMode(0);
   effpt->SetBorderSize(2);
   effpt->SetFrameBorderMode(0);
   effpt->SetFrameBorderMode(0);
   
   Double_t divide_num_1D_A0_pT_by_den_1D_A0_pT_fx3005[34] = {
   26.5,
   28.5,
   29.5,
   30.5,
   33.5,
   34.5,
   35.5,
   37.5,
   39.5,
   40.5,
   41.5,
   42.5,
   43.5,
   44.5,
   45.5,
   46.5,
   48.5,
   49.5,
   50.5,
   51.5,
   52.5,
   53.5,
   54.5,
   56.5,
   57.5,
   59.5,
   60.5,
   65.5,
   66.5,
   68.5,
   69.5,
   76.5,
   103.5,
   117.5};
   Double_t divide_num_1D_A0_pT_by_den_1D_A0_pT_fy3005[34] = {
   0,
   1,
   0,
   1,
   1,
   0,
   1,
   0.6666667,
   1,
   1,
   0.5,
   1,
   1,
   1,
   0.6666667,
   1,
   1,
   0.5,
   1,
   0.5,
   1,
   1,
   1,
   1,
   0,
   1,
   1,
   1,
   0.5,
   1,
   1,
   0,
   1,
   1};
   Double_t divide_num_1D_A0_pT_by_den_1D_A0_pT_felx3005[34] = {
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t divide_num_1D_A0_pT_by_den_1D_A0_pT_fely3005[34] = {
   0,
   0.6016845,
   0,
   0.6016845,
   0.4586417,
   0,
   0.2642294,
   0.4145347,
   0.6016845,
   0.4586417,
   0.4172485,
   0.8413447,
   0.8413447,
   0.8413447,
   0.4145347,
   0.4586417,
   0.6016845,
   0.4172485,
   0.8413447,
   0.4172485,
   0.4586417,
   0.4586417,
   0.8413447,
   0.6016845,
   0,
   0.8413447,
   0.8413447,
   0.8413447,
   0.4172485,
   0.8413447,
   0.8413447,
   0,
   0.8413447,
   0.8413447};
   Double_t divide_num_1D_A0_pT_by_den_1D_A0_pT_fehx3005[34] = {
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t divide_num_1D_A0_pT_by_den_1D_A0_pT_fehy3005[34] = {
   0.8413447,
   0,
   0.8413447,
   0,
   0,
   0.8413447,
   0,
   0.2773754,
   0,
   0,
   0.4172485,
   0,
   0,
   0,
   0.2773754,
   0,
   0,
   0.4172485,
   0,
   0.4172485,
   0,
   0,
   0,
   0,
   0.8413447,
   0,
   0,
   0,
   0.4172485,
   0,
   0,
   0.8413447,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(34,divide_num_1D_A0_pT_by_den_1D_A0_pT_fx3005,divide_num_1D_A0_pT_by_den_1D_A0_pT_fy3005,divide_num_1D_A0_pT_by_den_1D_A0_pT_felx3005,divide_num_1D_A0_pT_by_den_1D_A0_pT_fehx3005,divide_num_1D_A0_pT_by_den_1D_A0_pT_fely3005,divide_num_1D_A0_pT_by_den_1D_A0_pT_fehy3005);
   grae->SetName("divide_num_1D_A0_pT_by_den_1D_A0_pT");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005 = new TH1F("Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005","",100,16.8,127.2);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->SetMinimum(0);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->SetMaximum(1.1);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->SetDirectory(0);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->SetLineColor(ci);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetYaxis()->SetTitle("Efficiency");
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A0_pT_by_den_1D_A0_pT3005);
   
   grae->Draw("alp");
   
   Double_t divide_num_1D_A1_pT_by_den_1D_A1_pT_fx3006[20] = {
   18.5,
   19.5,
   21.5,
   22.5,
   23.5,
   24.5,
   25.5,
   26.5,
   27.5,
   28.5,
   29.5,
   30.5,
   31.5,
   32.5,
   34.5,
   35.5,
   36.5,
   37.5,
   41.5,
   42.5};
   Double_t divide_num_1D_A1_pT_by_den_1D_A1_pT_fy3006[20] = {
   1,
   1,
   1,
   1,
   0.6666667,
   0.625,
   0.6666667,
   0.2,
   1,
   1,
   1,
   0.8,
   0.6666667,
   1,
   0.8,
   1,
   1,
   1,
   1,
   1};
   Double_t divide_num_1D_A1_pT_by_den_1D_A1_pT_felx3006[20] = {
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t divide_num_1D_A1_pT_by_den_1D_A1_pT_fely3006[20] = {
   0.8413447,
   0.8413447,
   0.6016845,
   0.6016845,
   0.4145347,
   0.2349465,
   0.4145347,
   0.1660393,
   0.6016845,
   0.4586417,
   0.6016845,
   0.3242506,
   0.4145347,
   0.6016845,
   0.3242506,
   0.6016845,
   0.6016845,
   0.8413447,
   0.8413447,
   0.8413447};
   Double_t divide_num_1D_A1_pT_by_den_1D_A1_pT_fehx3006[20] = {
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t divide_num_1D_A1_pT_by_den_1D_A1_pT_fehy3006[20] = {
   0,
   0,
   0,
   0,
   0.2773754,
   0.1960756,
   0.2773754,
   0.3242506,
   0,
   0,
   0,
   0.1660393,
   0.2773754,
   0,
   0.1660393,
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(20,divide_num_1D_A1_pT_by_den_1D_A1_pT_fx3006,divide_num_1D_A1_pT_by_den_1D_A1_pT_fy3006,divide_num_1D_A1_pT_by_den_1D_A1_pT_felx3006,divide_num_1D_A1_pT_by_den_1D_A1_pT_fehx3006,divide_num_1D_A1_pT_by_den_1D_A1_pT_fely3006,divide_num_1D_A1_pT_by_den_1D_A1_pT_fehy3006);
   grae->SetName("divide_num_1D_A1_pT_by_den_1D_A1_pT");
   grae->SetTitle("num_1D_A1_pT");

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006 = new TH1F("Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006","num_1D_A1_pT",100,15.5,45.5);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->SetMinimum(0);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->SetMaximum(1.096604);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->SetDirectory(0);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->SetLineColor(ci);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetXaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetXaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetYaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetYaxis()->SetTitleFont(42);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetZaxis()->SetLabelFont(42);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_num_1D_A1_pT_by_den_1D_A1_pT3006);
   
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
   effpt->Modified();
   effpt->cd();
   effpt->SetSelected(effpt);
}
