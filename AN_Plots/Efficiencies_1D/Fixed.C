{
//=========Macro generated from canvas: eta_lz_trig/eta_lz_trig
//=========  (Tue Apr 19 11:45:01 2016) by ROOT version5.34/32
   TCanvas *eta_lz_trig = new TCanvas("eta_lz_trig", "eta_lz_trig",0,22,525,500);
   eta_lz_trig->Range(-9.375001,-0.0892326,59.375,1.171984);
   eta_lz_trig->SetFillColor(0);
   eta_lz_trig->SetBorderMode(0);
   eta_lz_trig->SetBorderSize(2);
   eta_lz_trig->SetFrameBorderMode(0);
   eta_lz_trig->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6);
   grae->SetName("divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ");
   grae->SetTitle("num_Trig_LEp8_1D_A0_LZ");
   grae->SetFillColor(1);
   grae->SetLineColor(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(2);
   grae->SetPoint(0,1,0.9299476);
   grae->SetPointError(0,1,1,0.001416198,0.001390479);
   grae->SetPoint(1,3,0.9074284);
   grae->SetPointError(1,1,1,0.004152633,0.003995378);
   grae->SetPoint(2,5,0.9047619);
   grae->SetPointError(2,1,1,0.006772112,0.006380372);
   grae->SetPoint(3,7,0.9151744);
   grae->SetPointError(3,1,1,0.009439135,0.008613832);
   grae->SetPoint(4,9,0.9208443);
   grae->SetPointError(4,1,1,0.01640877,0.01398048);
   grae->SetPoint(5,11,0.95);
   grae->SetPointError(5,1,1,0.0462531,0.02708906);
   
   TH1F *Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191 = new TH1F("Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191","num_Trig_LEp8_1D_A0_LZ",100,0,13.2);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->SetMinimum(0.8900799);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->SetMaximum(0.984999);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->SetDirectory(0);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->SetLineColor(ci);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_Trig_LEp8_1D_A0_LZ_by_den_Trig_LEp8_1D_A0_LZ30191);
   
   multigraph->Add(grae,"");
   
   grae = new TGraphAsymmErrors(15);
   grae->SetName("divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ");
   grae->SetTitle("num_Trig_LEp8_1D_A1_LZ");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(2);
   grae->SetPoint(0,1,0.9425803);
   grae->SetPointError(0,1,1,0.001323707,0.00129598);
   grae->SetPoint(1,3,0.9096066);
   grae->SetPointError(1,1,1,0.004047138,0.003893715);
   grae->SetPoint(2,5,0.9078715);
   grae->SetPointError(2,1,1,0.005758937,0.005461696);
   grae->SetPoint(3,7,0.8843188);
   grae->SetPointError(3,1,1,0.008686035,0.008172659);
   grae->SetPoint(4,9,0.8583732);
   grae->SetPointError(4,1,1,0.01162023,0.01090432);
   grae->SetPoint(5,11,0.8333333);
   grae->SetPointError(5,1,1,0.01636128,0.01522541);
   grae->SetPoint(6,14,0.8028478);
   grae->SetPointError(6,2,2,0.01405474,0.01336418);
   grae->SetPoint(7,17,0.7985348);
   grae->SetPointError(7,1,1,0.02724516,0.02489844);
   grae->SetPoint(8,19,0.7777778);
   grae->SetPointError(8,1,1,0.03536417,0.03201292);
   grae->SetPoint(9,22.5,0.8529412);
   grae->SetPointError(9,2.5,2.5,0.02177924,0.01954816);
   grae->SetPoint(10,27.5,0.8697917);
   grae->SetPointError(10,2.5,2.5,0.02898951,0.02473847);
   grae->SetPoint(11,32.5,0.8941176);
   grae->SetPointError(11,2.5,2.5,0.04460075,0.03378062);
   grae->SetPoint(12,37.5,0.9111111);
   grae->SetPointError(12,2.5,2.5,0.06471996,0.04205252);
   grae->SetPoint(13,42.5,0.7777778);
   grae->SetPointError(13,2.5,2.5,0.1411451,0.1031167);
   grae->SetPoint(14,47.5,1);
   grae->SetPointError(14,2.5,2.5,0.3688776,0);
   
   TH1F *Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202 = new TH1F("Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202","num_Trig_LEp8_1D_A1_LZ",100,0,55);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->SetMinimum(0.5942347);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->SetMaximum(1.036888);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->SetDirectory(0);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->SetLineColor(ci);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_Trig_LEp8_1D_A1_LZ_by_den_Trig_LEp8_1D_A1_LZ30202);
   
   multigraph->Add(grae,"");
   
   grae = new TGraphAsymmErrors(15);
   grae->SetName("divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ");
   grae->SetTitle("num_Trig_Gp8_1D_A0_LZ");
   grae->SetFillColor(1);
   grae->SetLineColor(2);
   grae->SetLineStyle(2);
   grae->SetMarkerColor(2);
   grae->SetMarkerStyle(2);
   grae->SetPoint(0,1,0.9074686);
   grae->SetPointError(0,1,1,0.004503448,0.00431933);
   grae->SetPoint(1,3,0.8762958);
   grae->SetPointError(1,1,1,0.009270561,0.008729903);
   grae->SetPoint(2,5,0.8683673);
   grae->SetPointError(2,1,1,0.01170184,0.01091502);
   grae->SetPoint(3,7,0.8103933);
   grae->SetPointError(3,1,1,0.01584207,0.01492926);
   grae->SetPoint(4,9,0.8143133);
   grae->SetPointError(4,1,1,0.01869919,0.01741602);
   grae->SetPoint(5,11,0.8025316);
   grae->SetPointError(5,1,1,0.02208995,0.02046387);
   grae->SetPoint(6,14,0.7879342);
   grae->SetPointError(6,2,2,0.01893276,0.01782616);
   grae->SetPoint(7,17,0.7826087);
   grae->SetPointError(7,1,1,0.04086862,0.03637119);
   grae->SetPoint(8,19,0.8671875);
   grae->SetPointError(8,1,1,0.03706856,0.03061698);
   grae->SetPoint(9,22.5,0.8944724);
   grae->SetPointError(9,2.5,2.5,0.0264867,0.02207874);
   grae->SetPoint(10,27.5,0.8461538);
   grae->SetPointError(10,2.5,2.5,0.04749383,0.03884423);
   grae->SetPoint(11,32.5,0.8604651);
   grae->SetPointError(11,2.5,2.5,0.07403573,0.05391832);
   grae->SetPoint(12,37.5,0.8846154);
   grae->SetPointError(12,2.5,2.5,0.09964539,0.0621244);
   grae->SetPoint(13,42.5,1);
   grae->SetPointError(13,2.5,2.5,0.1232221,0);
   grae->SetPoint(14,47.5,1);
   grae->SetPointError(14,2.5,2.5,0.4586417,0);
   
   TH1F *Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213 = new TH1F("Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213","num_Trig_Gp8_1D_A0_LZ",100,0,55);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->SetMinimum(0.4954942);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->SetMaximum(1.045864);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->SetDirectory(0);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->SetLineColor(ci);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_Trig_Gp8_1D_A0_LZ_by_den_Trig_Gp8_1D_A0_LZ30213);
   
   multigraph->Add(grae,"");
   
   grae = new TGraphAsymmErrors(10);
   grae->SetName("divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ");
   grae->SetTitle("num_Trig_Gp8_1D_A1_LZ");
   grae->SetFillColor(1);
   grae->SetLineStyle(2);
   grae->SetMarkerStyle(2);
   grae->SetPoint(0,1,0.9396562);
   grae->SetPointError(0,1,1,0.00274513,0.002635457);
   grae->SetPoint(1,3,0.9179229);
   grae->SetPointError(1,1,1,0.008732,0.007995389);
   grae->SetPoint(2,5,0.8989474);
   grae->SetPointError(2,1,1,0.01578446,0.01397905);
   grae->SetPoint(3,7,0.8838384);
   grae->SetPointError(3,1,1,0.02742635,0.0231329);
   grae->SetPoint(4,9,0.9101124);
   grae->SetPointError(4,1,1,0.04133953,0.03050087);
   grae->SetPoint(5,11,0.7142857);
   grae->SetPointError(5,1,1,0.1688772,0.1312299);
   grae->SetPoint(6,14,0.5);
   grae->SetPointError(6,2,2,0.4172485,0.4172485);
   grae->SetPoint(7,17,1);
   grae->SetPointError(7,1,1,0.8413447,0);
   grae->SetPoint(8,19,1);
   grae->SetPointError(8,1,1,0.6016845,0);
   grae->SetPoint(9,27.5,1);
   grae->SetPointError(9,2.5,2.5,0.8413447,0);
   
   TH1F *Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224 = new TH1F("Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224","num_Trig_Gp8_1D_A1_LZ",100,0,33);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->SetMinimum(0);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->SetMaximum(1.091725);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->SetDirectory(0);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->SetLineColor(ci);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetXaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetXaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetYaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetYaxis()->SetTitleFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetZaxis()->SetLabelFont(42);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_divide_num_Trig_Gp8_1D_A1_LZ_by_den_Trig_Gp8_1D_A1_LZ30224);
   
   multigraph->Add(grae,"");
   multigraph->Draw("ALP");
   multigraph->GetXaxis()->SetTitle("L_{Z} [cm]");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("Efficiency");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   TLine *line = new TLine(34.5,0,34.5,1);
   line->SetLineColor(4);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(46.5,0,46.5,1);
   line->SetLineColor(4);
   line->SetLineStyle(2);
   line->Draw();
   
   TLegend *leg = new TLegend(0.6389685,0.2447257,0.8381089,0.4535865,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03171247);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","|#eta_{#gamma D}| #leq 0.9 A0","L");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","|#eta_{#gamma D}| > 0.9 A0","L");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","|#eta_{#gamma D}| #leq 0.9 A1","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL","|#eta_{#gamma D}| > 0.9 A1","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   eta_lz_trig->Modified();
   eta_lz_trig->cd();
   eta_lz_trig->SetSelected(eta_lz_trig);
}
