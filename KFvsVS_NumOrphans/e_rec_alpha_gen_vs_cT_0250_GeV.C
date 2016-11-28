void e_rec_alpha_gen_vs_cT_0250_GeV()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Sep 26 17:01:20 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,0,700,500);
   gStyle->SetOptStat(0);
   c->Range(-0.85,-0.125,5.65,1.125);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH2F *dummy31 = new TH2F("dummy31","",20,-0.2,5,100,0,1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   dummy31->SetLineColor(ci);
   dummy31->GetXaxis()->SetTitle("c#tau [mm]");
   dummy31->GetXaxis()->SetLabelFont(42);
   dummy31->GetXaxis()->SetLabelSize(0.035);
   dummy31->GetXaxis()->SetTitleSize(0.035);
   dummy31->GetXaxis()->SetTitleFont(42);
   dummy31->GetYaxis()->SetTitle("#epsilon_{full}/#alpha_{gen}");
   dummy31->GetYaxis()->SetLabelFont(42);
   dummy31->GetYaxis()->SetLabelSize(0.035);
   dummy31->GetYaxis()->SetTitleSize(0.035);
   dummy31->GetYaxis()->SetTitleFont(42);
   dummy31->GetZaxis()->SetLabelFont(42);
   dummy31->GetZaxis()->SetLabelSize(0.035);
   dummy31->GetZaxis()->SetTitleSize(0.035);
   dummy31->GetZaxis()->SetTitleFont(42);
   dummy31->Draw("");
   
   Double_t Graph0_fx1001[13] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5,
   10,
   20,
   50,
   100};
   Double_t Graph0_fy1001[13] = {
   0.6837748,
   0.6627736,
   0.6558678,
   0.6443325,
   0.6390893,
   0.6474616,
   0.6423156,
   0.674359,
   0.6707317,
   0.7248677,
   0.7169811,
   0.6086957,
   0.7142857};
   Double_t Graph0_fex1001[13] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[13] = {
   0.003198175,
   0.003368895,
   0.003398753,
   0.003562298,
   0.004841781,
   0.007341478,
   0.01258318,
   0.01677907,
   0.02996276,
   0.03248398,
   0.0618762,
   0.1017638,
   0.1707469};
   TGraphErrors *gre = new TGraphErrors(13,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0,110);
   Graph_Graph1001->SetMinimum(0.4691217);
   Graph_Graph1001->SetMaximum(0.9228427);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw(" pl");
   
   Double_t Graph1_fx1002[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph1_fy1002[9] = {
   0.7111127,
   0.6847633,
   0.6886592,
   0.6703329,
   0.6395336,
   0.6367063,
   0.6166966,
   0.6391097,
   0.5940054};
   Double_t Graph1_fex1002[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph1_fey1002[9] = {
   0.003793945,
   0.004176028,
   0.005709174,
   0.008105038,
   0.005108695,
   0.008189397,
   0.01456681,
   0.01914917,
   0.02563435};
   gre = new TGraphErrors(9,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(7);
   gre->SetMarkerColor(7);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0,5.5);
   Graph_Graph1002->SetMinimum(0.5537175);
   Graph_Graph1002->SetMaximum(0.7295602);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw(" pl");
   
   Double_t Graph2_fx1003[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph2_fy1003[9] = {
   0.6946373,
   0.6969327,
   0.6952682,
   0.6866559,
   0.6706974,
   0.656922,
   0.6532002,
   0.6601363,
   0.6530035};
   Double_t Graph2_fex1003[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph2_fey1003[9] = {
   0.004290278,
   0.004451086,
   0.003900374,
   0.004075005,
   0.00433682,
   0.005024308,
   0.00717035,
   0.009775076,
   0.01265441};
   gre = new TGraphErrors(9,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(9);
   gre->SetMarkerColor(9);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0,5.5);
   Graph_Graph1003->SetMinimum(0.6342456);
   Graph_Graph1003->SetMaximum(0.7074873);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   gre->Draw(" pl");
   
   Double_t Graph3_fx1004[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph3_fy1004[9] = {
   0.680194,
   0.677331,
   0.6742933,
   0.6728334,
   0.6745899,
   0.6658753,
   0.6539319,
   0.6586807,
   0.6440095};
   Double_t Graph3_fex1004[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph3_fey1004[9] = {
   0.003725611,
   0.003732105,
   0.003730884,
   0.003696728,
   0.003686226,
   0.003728287,
   0.003796016,
   0.004871114,
   0.004010204};
   gre = new TGraphErrors(9,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(6);
   gre->SetMarkerColor(6);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0,1.1);
   Graph_Graph1004->SetMinimum(0.6356073);
   Graph_Graph1004->SetMaximum(0.6883116);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   gre->Draw(" pl");
   
   Double_t Graph4_fx1005[13] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5,
   10,
   20,
   50,
   100};
   Double_t Graph4_fy1005[13] = {
   0.6487701,
   0.6334738,
   0.6328369,
   0.6240102,
   0.6189653,
   0.6323495,
   0.6305996,
   0.6538462,
   0.6626016,
   0.6984127,
   0.7169811,
   0.5652174,
   0.7142857};
   Double_t Graph4_fex1005[13] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph4_fey1005[13] = {
   0.003283134,
   0.003433689,
   0.003448452,
   0.003604434,
   0.004895983,
   0.007409168,
   0.01267044,
   0.01703433,
   0.03014603,
   0.03338349,
   0.0618762,
   0.1033665,
   0.1707469};
   gre = new TGraphErrors(13,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineStyle(2);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0,110);
   Graph_Graph1005->SetMinimum(0.4195327);
   Graph_Graph1005->SetMaximum(0.9273508);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   gre->Draw(" pl");
   
   Double_t Graph5_fx1006[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph5_fy1006[9] = {
   0.7107623,
   0.6842786,
   0.6885071,
   0.6694411,
   0.6395336,
   0.6364164,
   0.6166966,
   0.6391097,
   0.5940054};
   Double_t Graph5_fex1006[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph5_fey1006[9] = {
   0.00379531,
   0.004177758,
   0.005709937,
   0.008110593,
   0.005108695,
   0.008190798,
   0.01456681,
   0.01914917,
   0.02563435};
   gre = new TGraphErrors(9,Graph5_fx1006,Graph5_fy1006,Graph5_fex1006,Graph5_fey1006);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(7);
   gre->SetLineStyle(2);
   gre->SetMarkerColor(7);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0,5.5);
   Graph_Graph1006->SetMinimum(0.5537524);
   Graph_Graph1006->SetMaximum(0.7291763);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1006->SetLineColor(ci);
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
   gre->Draw(" pl");
   
   Double_t Graph6_fx1007[9] = {
   0,
   0.05,
   0.1,
   0.2,
   0.5,
   1,
   2,
   3,
   5};
   Double_t Graph6_fy1007[9] = {
   0.6946373,
   0.6969327,
   0.6952682,
   0.6866559,
   0.6706974,
   0.656922,
   0.6532002,
   0.6601363,
   0.6530035};
   Double_t Graph6_fex1007[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph6_fey1007[9] = {
   0.004290278,
   0.004451086,
   0.003900374,
   0.004075005,
   0.00433682,
   0.005024308,
   0.00717035,
   0.009775076,
   0.01265441};
   gre = new TGraphErrors(9,Graph6_fx1007,Graph6_fy1007,Graph6_fex1007,Graph6_fey1007);
   gre->SetName("Graph6");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(9);
   gre->SetLineStyle(2);
   gre->SetMarkerColor(9);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,0,5.5);
   Graph_Graph1007->SetMinimum(0.6342456);
   Graph_Graph1007->SetMaximum(0.7074873);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1007->SetLineColor(ci);
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   gre->Draw(" pl");
   
   Double_t Graph7_fx1008[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph7_fy1008[9] = {
   0.680194,
   0.677331,
   0.6742933,
   0.6728334,
   0.6745899,
   0.6658753,
   0.6539319,
   0.6586807,
   0.6440095};
   Double_t Graph7_fex1008[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph7_fey1008[9] = {
   0.003725611,
   0.003732105,
   0.003730884,
   0.003696728,
   0.003686226,
   0.003728287,
   0.003796016,
   0.004871114,
   0.004010204};
   gre = new TGraphErrors(9,Graph7_fx1008,Graph7_fy1008,Graph7_fex1008,Graph7_fey1008);
   gre->SetName("Graph7");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetLineColor(6);
   gre->SetLineStyle(2);
   gre->SetMarkerColor(6);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(5);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,0,1.1);
   Graph_Graph1008->SetMinimum(0.6356073);
   Graph_Graph1008->SetMaximum(0.6883116);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1008->SetLineColor(ci);
   Graph_Graph1008->GetXaxis()->SetLabelFont(42);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetXaxis()->SetTitleFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetYaxis()->SetTitleFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1008);
   
   gre->Draw(" pl");
   
   TLegend *leg = new TLegend(0.5,0.3,0.85,0.6,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","m_{#gamma D}=0.250 GeV KalmanFitterVtx + VertexScan","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","m_{#gamma D}=0.400 GeV KalmanFitterVtx + VertexScan","PL");
   entry->SetLineColor(7);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(7);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","m_{#gamma D}=1.000 GeV KalmanFitterVtx + VertexScan","PL");
   entry->SetLineColor(9);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(9);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","m_{#gamma D}=8.500 GeV KalmanFitterVtx + VertexScan","PL");
   entry->SetLineColor(6);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(6);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph4","m_{#gamma D}=0.250 GeV KalmanFitterVtx","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph5","m_{#gamma D}=0.400 GeV KalmanFitterVtx","PL");
   entry->SetLineColor(7);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(7);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6","m_{#gamma D}=1.000 GeV KalmanFitterVtx","PL");
   entry->SetLineColor(9);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(9);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph7","m_{#gamma D}=8.500 GeV KalmanFitterVtx","PL");
   entry->SetLineColor(6);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(6);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(5);
   entry->SetTextFont(42);
   leg->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
