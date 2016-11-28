{
//=========Macro generated from canvas: effz2/effz2
//=========  (Tue Jun 21 17:23:30 2016) by ROOT version5.34/36
   TCanvas *effz2 = new TCanvas("effz2", "effz2",0,22,700,502);
   effz2->Range(-6.600001,-0.125,59.4,1.125);
   effz2->SetFillColor(0);
   effz2->SetBorderMode(0);
   effz2->SetBorderSize(2);
   effz2->SetFrameBorderMode(0);
   effz2->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6);
   grae->SetName("divide_num_1D_A0_LZ_by_den_1D_A0_LZ");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineColor(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(21);
   grae->SetPoint(0,4,0.9201985);
   grae->SetPointError(0,4,4,0.001228036,0.001211153);
   grae->SetPoint(1,12,0.8177691);
   grae->SetPointError(1,4,4,0.01036578,0.009940192);
   grae->SetPoint(2,20,0.8723404);
   grae->SetPointError(2,4,4,0.02113101,0.01868509);
   grae->SetPoint(3,28,0.853211);
   grae->SetPointError(3,4,4,0.04204194,0.03472813);
   grae->SetPoint(4,36,0.8529412);
   grae->SetPointError(4,4,4,0.08724844,0.06200713);
   grae->SetPoint(5,44,1);
   grae->SetPointError(5,4,4,0.1422293,0);
   
   TH1F *Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031 = new TH1F("Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031","",100,0,52.8);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->SetMinimum(0);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->SetMaximum(1);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->SetDirectory(0);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->SetLineColor(ci);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetXaxis()->SetTitle("L_{Z} [cm]");
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetYaxis()->SetTitle("Dimuon Reconstruction Efficiency");
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_1D_A0_LZ_by_den_1D_A0_LZ30031);
   
   grae->Draw("alp");
   
   grae = new TGraphAsymmErrors(12);
   grae->SetName("divide_num_1D_A1_LZ_by_den_1D_A1_LZ");
   grae->SetTitle("num_1D_A1_LZ");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(7);
   grae->SetPoint(0,2,0.9388469);
   grae->SetPointError(0,2,2,0.001113011,0.001094562);
   grae->SetPoint(1,6,0.8984013);
   grae->SetPointError(1,2,2,0.004572801,0.00440119);
   grae->SetPoint(2,10,0.8467433);
   grae->SetPointError(2,2,2,0.009650174,0.009191971);
   grae->SetPoint(3,14,0.8);
   grae->SetPointError(3,2,2,0.01500267,0.01423481);
   grae->SetPoint(4,18,0.8165375);
   grae->SetPointError(4,2,2,0.02181929,0.02007877);
   grae->SetPoint(5,22,0.8888889);
   grae->SetPointError(5,2,2,0.02450181,0.02084199);
   grae->SetPoint(6,26,0.8686131);
   grae->SetPointError(6,2,2,0.03547676,0.02944364);
   grae->SetPoint(7,30,0.8961039);
   grae->SetPointError(7,2,2,0.04724068,0.03514081);
   grae->SetPoint(8,34,0.9032258);
   grae->SetPointError(8,2,2,0.08525764,0.05219903);
   grae->SetPoint(9,38,0.9354839);
   grae->SetPointError(9,2,2,0.0788281,0.04156066);
   grae->SetPoint(10,41.90716,0.7505274);
   grae->SetPointError(10,2,2,0.2395668,0.1596593);
   grae->SetPoint(11,46,1);
   grae->SetPointError(11,2,2,0.6016845,0);
   
   TH1F *Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042 = new TH1F("Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042","num_1D_A1_LZ",100,0,52.8);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->SetMinimum(0.3381471);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->SetMaximum(1.060168);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->SetDirectory(0);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->SetStats(0);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_1D_A1_LZ_by_den_1D_A1_LZ30042);
   
   grae->Draw("");
   TLine *line = new TLine(34.5,0,34.5,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(48.5,0,48.5,1);

   ci = TColor::GetColor("#0000ff");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   
   TLegend *leg = new TLegend(0.1690544,0.1476793,0.3008596,0.3333333,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","#gamma_{D1}","L");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","#gamma_{D2}","L");
   entry->SetLineColor(4);
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
