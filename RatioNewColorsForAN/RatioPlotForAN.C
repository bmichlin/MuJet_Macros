void RatioPlotForAN(){

	TCanvas *c1 = new TCanvas("c1", "c1",0,45,1204,721);

	Double_t x0250[13]  = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0, 10.0, 20.0, 50.0, 100.0};
	Double_t y0250[13]  = {0.683775, 0.662774, 0.655868, 0.6443324658, 0.6390893383, 0.6474616293, 0.6423156444, 0.6743589744, 0.6707317073, 0.7248677249, 0.7169811321, 0.6086956522, 0.7142857143};
	Double_t ex0250[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey0250[13] = {0.00319818, 0.00336889, 0.00339875, 0.003562298191, 0.004841781223, 0.007341478091, 0.01258318311, 0.0167790677, 0.02996276036, 0.0324839811, 0.06187619842, 0.1017638475, 0.1707469442};

	Double_t  x0275[9] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0};
	Double_t  y0275[9] = {0.7021986971, 0.6933741601, 0.6750769896, 0.6632042038, 0.6514522822, 0.6503968254, 0.6724003127, 0.7352941176, 0.7543859649};
	Double_t ex0275[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey0275[9] = {0.00412661662, 0.004252457117, 0.003442511573, 0.003694330052, 0.006138947241, 0.009498972269, 0.01312352251, 0.03088853127, 0.04031539918};


	Double_t  x0300[9] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0};
	Double_t  y0300[9] = {0.7163902226, 0.7093799682, 0.6883400183, 0.6700490726, 0.6523580586, 0.7281553398, 0.6645919779, 0.6458055925, 0.6417910448};
	Double_t ex0300[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey0300[9] = {0.004708611773, 0.005725018712, 0.003885346092, 0.004288165697, 0.005095100871, 0.0438383107, 0.01241595482, 0.01745226433, 0.04142024341};

	Double_t  x0400[9] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0};
	Double_t  y0400[9] = {0.7111126682, 0.6847632897, 0.6886591669, 0.670332937, 0.6395335673, 0.6367062917, 0.6166965889, 0.6391096979, 0.5940054496};
	Double_t ex0400[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey0400[9] = {0.003793945064, 0.004176027876, 0.005709173923, 0.008105038189, 0.005108694954, 0.008189396751, 0.01456681215, 0.01914917142, 0.02563434852};

	Double_t  x0700[9] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0};
	Double_t  y0700[9] = {0.7091979175, 0.699626997, 0.6973981488, 0.69250501, 0.6624919422, 0.6523702032, 0.6395604396, 0.6584536958, 0.6545454545};
	Double_t ex0700[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey0700[9] = {0.003944803574, 0.003845758166, 0.003921780685, 0.004131523286, 0.004537717516, 0.008551743623, 0.009189157564, 0.009774266716, 0.02617630796};

	Double_t  x1000[9] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0};
	Double_t  y1000[9] = {0.6946372787, 0.6969327455, 0.6952681841, 0.6866558617, 0.6706974368, 0.656922043, 0.6532001816, 0.6601362862, 0.6530035336};
	Double_t ex1000[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey1000[9] = {0.004290277929, 0.004451085851, 0.003900374336, 0.004075004793, 0.004336819514, 0.005024307764, 0.007170349631, 0.009775076298, 0.01265441497};

	Double_t  x1500[8] = {0.0, 0.05, 0.1, 0.2, 1.0, 2.0, 3.0, 5.0};
	Double_t  y1500[8] = {0.6917146862, 0.6900423039, 0.690059727, 0.6979155864, 0.6742658423, 0.6524226712, 0.6564981949, 0.6587926509};
	Double_t ex1500[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey1500[8] = {0.004074962191, 0.004171361174, 0.006754427511, 0.004675838734, 0.005318687421, 0.006367483569, 0.006380084013, 0.008587684485};

	Double_t  x2000[12] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0, 10.0, 20.0, 100.0};
	Double_t  y2000[12] = {0.6921928646, 0.7019244476, 0.6968442096, 0.6942885916, 0.678835289, 0.6775184275, 0.6485260771, 0.6690590112, 0.6642976589, 0.6746306766, 0.6889414548, 0.7528735632};
	Double_t ex2000[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey2000[12] = {0.005639594934, 0.005461281032, 0.005492356497, 0.005525889462, 0.005619881764, 0.005792363543, 0.006562969084, 0.007671814559, 0.009655570924, 0.006327209606, 0.01125746028, 0.03269986828};

	Double_t  x8500[9] = {0.0, 0.05, 0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 5.0};
	Double_t  y8500[9] = {0.6801939765, 0.6773309541, 0.6742933198, 0.6728333747, 0.6745899102, 0.6658752968, 0.6539318688, 0.6586807388, 0.6440095398};
	Double_t ex8500[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t ey8500[9] = {0.00372561093, 0.003732104563, 0.003730884339, 0.003696727596, 0.003686225905, 0.003728287016, 0.003796016442, 0.004871113748, 0.004010204195};

	TGraphErrors *g1 = new TGraphErrors(13,x0250,y0250,ex0250,ey0250);
	TGraphErrors *g2 = new TGraphErrors(9,x0275,y0275,ex0275,ey0275);
	TGraphErrors *g3 = new TGraphErrors(9,x0300,y0300,ex0300,ey0300);
	TGraphErrors *g4 = new TGraphErrors(9,x0400,y0400,ex0400,ey0400);
	TGraphErrors *g5 = new TGraphErrors(9,x0700,y0700,ex0700,ey0700);
	TGraphErrors *g6 = new TGraphErrors(9,x1000,y1000,ex1000,ey1000);
	TGraphErrors *g7 = new TGraphErrors(8,x1500,y1500,ex1500,ey1500);
	TGraphErrors *g8 = new TGraphErrors(12,x2000,y2000,ex2000,ey2000);
	TGraphErrors *g9 = new TGraphErrors(9,x8500,y8500,ex8500,ey8500);

	//Style
	Int_t ci;      // for color index setting
	TColor *color; // for color definition with alpha
	ci = TColor::GetColor("#e41a1c");

	g1->SetLineWidth(1);
	g1->SetMarkerSize(5);
	g1->SetLineColor(ci);
	g1->SetMarkerColor(ci);
	g1->SetMarkerStyle(7);
	g1->SetFillColor(kWhite);
	g1->SetTitle("m_{#gamma D} = 0.250 GeV");

ci = TColor::GetColor("#377eb8");
	g2->SetLineWidth(1);
	g2->SetMarkerSize(5);
	g2->SetLineColor(ci);
	g2->SetMarkerColor(ci);
	g2->SetMarkerStyle(7);
	g2->SetFillColor(kWhite);
	g2->SetTitle("m_{#gamma D} = 0.275 GeV");

ci = TColor::GetColor("#4daf4a");
	g3->SetLineWidth(1);
	g3->SetMarkerSize(5);
	g3->SetLineColor(ci);
	g3->SetMarkerColor(ci);
	g3->SetMarkerStyle(7);
	g3->SetFillColor(kWhite);
	g3->SetTitle("m_{#gamma D} = 0.300 GeV");

ci = TColor::GetColor("#984ea3");
	g4->SetLineWidth(1);
	g4->SetMarkerSize(5);
	g4->SetLineColor(ci);
	g4->SetMarkerColor(ci);
	g4->SetMarkerStyle(7);
	g4->SetFillColor(kWhite);
	g4->SetTitle("m_{#gamma D} = 0.400 GeV");

ci = TColor::GetColor("#ff7f00");
	g5->SetLineWidth(1);
	g5->SetMarkerSize(5);
	g5->SetLineColor(ci);
	g5->SetMarkerColor(ci);
	g5->SetMarkerStyle(7);
	g5->SetFillColor(kWhite);
	g5->SetTitle("m_{#gamma D} = 0.700 GeV");

ci = TColor::GetColor("#999999");
	g6->SetLineWidth(1);
	g6->SetMarkerSize(5);
	g6->SetLineColor(ci);
	g6->SetMarkerColor(ci);
	g6->SetMarkerStyle(7);
	g6->SetFillColor(kWhite);
	g6->SetTitle("m_{#gamma D} = 1.000 GeV");

ci = TColor::GetColor("#a65628");
	g7->SetLineWidth(1);
	g7->SetMarkerSize(5);
	g7->SetLineColor(ci);
	g7->SetMarkerColor(ci);
	g7->SetMarkerStyle(7);
	g7->SetFillColor(kWhite);
	g7->SetTitle("m_{#gamma D} = 1.500 GeV");

ci = TColor::GetColor("#000000");
	g8->SetLineWidth(1);
	g8->SetMarkerSize(5);
	g8->SetLineColor(ci);
	g8->SetMarkerColor(ci);
	g8->SetMarkerStyle(7);
	g8->SetFillColor(kWhite);
	g8->SetTitle("m_{#gamma D} = 2.000 GeV");

ci = TColor::GetColor("#f781bf");
	g9->SetLineWidth(1);
	g9->SetMarkerSize(5);
	g9->SetLineColor(ci);
	g9->SetMarkerColor(ci);
	g9->SetMarkerStyle(7);
	g9->SetFillColor(kWhite);
	g9->SetTitle("m_{#gamma D} = 8.500 GeV");


	//Plot
	TMultiGraph *g = new TMultiGraph();
	g->Add(g1);
	g->Add(g2);
	g->Add(g3);
	g->Add(g4);
	g->Add(g5);
	g->Add(g6);
	g->Add(g7);
	g->Add(g8);
	g->Add(g9);
	g->SetTitle("CMS Simulation #sqrt{s} = 13 TeV");

	g->SetMinimum(0.0);
	g->SetMaximum(1.0);
	g->Draw("APL");

	//Legend
	TLegend *leg = new TLegend(0.6023295,0.125,0.8801997,0.420977,NULL,"brNDC");
	 leg-> SetNColumns(2);
	leg->SetBorderSize(1);
	leg->SetLineColor(0);
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	leg->SetFillColor(0);
	leg->SetFillStyle(1001);
	TLegendEntry *entry=leg->AddEntry(g1,"m_{#gamma D} = 0.250 GeV","lpf");
	              entry=leg->AddEntry(g2,"m_{#gamma D} = 0.275 GeV","lpf");
	              entry=leg->AddEntry(g3,"m_{#gamma D} = 0.300 GeV","lpf");
	              entry=leg->AddEntry(g4,"m_{#gamma D} = 0.400 GeV","lpf");
	              entry=leg->AddEntry(g5,"m_{#gamma D} = 0.700 GeV","lpf");
	              entry=leg->AddEntry(g6,"m_{#gamma D} = 1.000 GeV","lpf");
	              entry=leg->AddEntry(g7,"m_{#gamma D} = 1.500 GeV","lpf");
	              entry=leg->AddEntry(g8,"m_{#gamma D} = 2.000 GeV","lpf");
	              entry=leg->AddEntry(g9,"m_{#gamma D} = 8.500 GeV","lpf");

	leg->Draw("same");

	TPaveText *pt = new TPaveText(0.05657238,0.9051724,0.4633943,0.9597701,"blNDC");
	pt->SetName("title");
	pt->SetBorderSize(0);
	pt->SetFillColor(0);
	pt->SetFillStyle(0);
	pt->SetTextFont(42);
	pt->SetTextSize(0.04310345);
	TText *AText = pt->AddText("CMS Simulation #sqrt{s} = 13 TeV");
	pt->Draw();



}
