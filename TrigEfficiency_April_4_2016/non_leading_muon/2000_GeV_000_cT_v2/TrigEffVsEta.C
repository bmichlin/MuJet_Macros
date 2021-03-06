void TrigEffVsEta()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Apr  4 18:36:02 2016) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,22,700,500);
   c->Range(-4.5,-0.06407817,4.5,0.5767035);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   Double_t divide_etaNum_by_etaDen_fx3001[60] = {
   -2.95,
   -2.85,
   -2.75,
   -2.65,
   -2.55,
   -2.45,
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
   0.85,
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
   2.35,
   2.45,
   2.55,
   2.65,
   2.75,
   2.85,
   2.95};
   Double_t divide_etaNum_by_etaDen_fy3001[60] = {
   0,
   0,
   0,
   0,
   0.001655629,
   0.04858934,
   0.1884253,
   0.2335859,
   0.2268623,
   0.2674944,
   0.2636555,
   0.2846154,
   0.2932072,
   0.3432963,
   0.3458529,
   0.3903704,
   0.3851301,
   0.3925424,
   0.3896194,
   0.4,
   0.3973384,
   0.3997509,
   0.4045307,
   0.426259,
   0.4347305,
   0.422966,
   0.4540451,
   0.4168983,
   0.4157562,
   0.45109,
   0.4332344,
   0.4521095,
   0.4336678,
   0.4299656,
   0.4266004,
   0.4330756,
   0.4267589,
   0.4283099,
   0.4031153,
   0.3945362,
   0.3835079,
   0.4008293,
   0.4021813,
   0.3887689,
   0.3948905,
   0.3609756,
   0.3385632,
   0.2676444,
   0.2619893,
   0.2511261,
   0.2561895,
   0.2090708,
   0.2393162,
   0.1933241,
   0.03687316,
   0,
   0,
   0,
   0.002257336,
   0.002724796};
   Double_t divide_etaNum_by_etaDen_felx3001[60] = {
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
   0.05,
   0.05};
   Double_t divide_etaNum_by_etaDen_fely3001[60] = {
   0,
   0,
   0,
   0,
   0.001369654,
   0.00853534,
   0.01457407,
   0.0153079,
   0.01430752,
   0.01515584,
   0.01454176,
   0.01425258,
   0.01359,
   0.01415851,
   0.01356708,
   0.01355905,
   0.01354784,
   0.01297449,
   0.0130919,
   0.01306608,
   0.01256482,
   0.01246673,
   0.01274262,
   0.01235939,
   0.01238612,
   0.01210683,
   0.01192616,
   0.01185175,
   0.01205303,
   0.01201268,
   0.01232399,
   0.01213734,
   0.01193795,
   0.01210394,
   0.01184994,
   0.01233832,
   0.01211934,
   0.01247916,
   0.01248971,
   0.01256424,
   0.01268399,
   0.01315374,
   0.01307001,
   0.0133526,
   0.01348794,
   0.01397906,
   0.0138686,
   0.01363651,
   0.01332455,
   0.01481782,
   0.0145814,
   0.01373759,
   0.01518074,
   0.01496946,
   0.007237466,
   0,
   0,
   0,
   0.001867449,
   0.002254188};
   Double_t divide_etaNum_by_etaDen_fehx3001[60] = {
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
   0.05,
   0.05};
   Double_t divide_etaNum_by_etaDen_fehy3001[60] = {
   0.004963376,
   0.004119343,
   0.003765478,
   0.003384722,
   0.003796774,
   0.01007941,
   0.01545139,
   0.01600837,
   0.01494838,
   0.01570023,
   0.01505622,
   0.01468077,
   0.01395688,
   0.01443424,
   0.01381528,
   0.01372592,
   0.01372336,
   0.01312402,
   0.01324873,
   0.01320618,
   0.01269823,
   0.0125947,
   0.01286936,
   0.01244997,
   0.01246619,
   0.01219786,
   0.01197791,
   0.01194632,
   0.01215224,
   0.01206864,
   0.01240516,
   0.01219324,
   0.01201363,
   0.01218626,
   0.01193285,
   0.01241988,
   0.01220584,
   0.01256879,
   0.01261346,
   0.01270165,
   0.01284041,
   0.01329443,
   0.01320686,
   0.0135171,
   0.01364555,
   0.01421171,
   0.01414318,
   0.01407678,
   0.01376139,
   0.01539964,
   0.01512566,
   0.01440712,
   0.01584291,
   0.01586205,
   0.00874168,
   0.00323031,
   0.003480712,
   0.003617499,
   0.0051715,
   0.006237619};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(60,divide_etaNum_by_etaDen_fx3001,divide_etaNum_by_etaDen_fy3001,divide_etaNum_by_etaDen_felx3001,divide_etaNum_by_etaDen_fehx3001,divide_etaNum_by_etaDen_fely3001,divide_etaNum_by_etaDen_fehy3001);
   grae->SetName("divide_etaNum_by_etaDen");
   grae->SetTitle("etaNum");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   grae->SetLineColor(ci);
   
   TH1F *Graph_divide_etaNum_by_etaDen3001 = new TH1F("Graph_divide_etaNum_by_etaDen3001","etaNum",100,-3.6,3.6);
   Graph_divide_etaNum_by_etaDen3001->SetMinimum(0);
   Graph_divide_etaNum_by_etaDen3001->SetMaximum(0.5126253);
   Graph_divide_etaNum_by_etaDen3001->SetDirectory(0);
   Graph_divide_etaNum_by_etaDen3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_divide_etaNum_by_etaDen3001->SetLineColor(ci);
   Graph_divide_etaNum_by_etaDen3001->GetXaxis()->SetTitle("GEN #eta");
   Graph_divide_etaNum_by_etaDen3001->GetXaxis()->SetLabelFont(42);
   Graph_divide_etaNum_by_etaDen3001->GetXaxis()->SetLabelSize(0.035);
   Graph_divide_etaNum_by_etaDen3001->GetXaxis()->SetTitleSize(0.035);
   Graph_divide_etaNum_by_etaDen3001->GetXaxis()->SetTitleFont(42);
   Graph_divide_etaNum_by_etaDen3001->GetYaxis()->SetTitle("HLT Efficiency");
   Graph_divide_etaNum_by_etaDen3001->GetYaxis()->SetLabelFont(42);
   Graph_divide_etaNum_by_etaDen3001->GetYaxis()->SetLabelSize(0.035);
   Graph_divide_etaNum_by_etaDen3001->GetYaxis()->SetTitleSize(0.035);
   Graph_divide_etaNum_by_etaDen3001->GetYaxis()->SetTitleFont(42);
   Graph_divide_etaNum_by_etaDen3001->GetZaxis()->SetLabelFont(42);
   Graph_divide_etaNum_by_etaDen3001->GetZaxis()->SetLabelSize(0.035);
   Graph_divide_etaNum_by_etaDen3001->GetZaxis()->SetTitleSize(0.035);
   Graph_divide_etaNum_by_etaDen3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_divide_etaNum_by_etaDen3001);
   
   grae->Draw("alp");
   
   TPaveText *pt = new TPaveText(0.4275,0.94,0.5725,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("etaNum");
   pt->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
