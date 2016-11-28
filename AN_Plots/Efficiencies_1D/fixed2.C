{
//=========Macro generated from canvas: effxy/effxy
//=========  (Tue Apr 19 11:47:51 2016) by ROOT version5.34/32
   TCanvas *effxy = new TCanvas("effxy", "effxy",0,22,700,502);
   effxy->Range(-1.65,0.803551,14.85,0.9802162);
   effxy->SetFillColor(0);
   effxy->SetBorderMode(0);
   effxy->SetBorderSize(2);
   effxy->SetFrameBorderMode(0);
   effxy->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6);
   grae->SetName("divide_num_1D_A1_LXY_by_den_1D_A1_LXY");
   grae->SetTitle("num_1D_A1_LXY");
   grae->SetFillColor(1);
   grae->SetLineColor(4);
   grae->SetMarkerColor(4);
   grae->SetMarkerStyle(21);
   grae->SetPoint(0,1,0.9499559);
   grae->SetPointError(0,1,1,0.0008287761,0.0008160815);
   grae->SetPoint(1,2.983238,0.9220732);
   grae->SetPointError(1,1,1,0.00209215,0.002042695);
   grae->SetPoint(2,5,0.8911351);
   grae->SetPointError(2,1,1,0.003222211,0.003141866);
   grae->SetPoint(3,7,0.8534163);
   grae->SetPointError(3,1,1,0.004433207,0.00432665);
   grae->SetPoint(4,9,0.838334);
   grae->SetPointError(4,1,1,0.005338825,0.005202721);
   grae->SetPoint(5,11,0.8490214);
   grae->SetPointError(5,1,1,0.00812834,0.007793347);
   
   TH1F *Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021 = new TH1F("Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021","num_1D_A1_LXY",100,0,13.2);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->SetMinimum(0.8212175);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->SetMaximum(0.9625497);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->SetDirectory(0);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->SetLineColor(ci);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_1D_A1_LXY_by_den_1D_A1_LXY30021);
   
   grae->Draw("alp");
   
   TLegend *leg = new TLegend(0.1690544,0.1476793,0.3008596,0.3333333,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(5);
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
   entry=leg->AddEntry("divide_num_1D_A1_LXY_by_den_1D_A1_LXY","#gamma_{D2}","L");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.3474499,0.9367722,0.6525501,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("num_1D_A1_LXY");
   pt->Draw();
   effxy->Modified();
   effxy->cd();
   effxy->SetSelected(effxy);
}
