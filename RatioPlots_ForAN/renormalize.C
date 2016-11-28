void renormalizeScale(TH2F * plot, int binx, int biny){

double integral = 0;
double maxValue = 0;
for(int x = 0; x < binx; x++){
for(int y =0; y < biny; y++){

if(plot->GetBinContent(x, y) > maxValue) maxValue = plot->GetBinContent(x, y);

//integral += plot->GetBinContent(x, y);
}
}
double scale = 1.0/(maxValue*1.0);

/////
plot->Scale(scale);
plot->SetTitle("");
plot->Draw("colz");

/////

TF1 *eta1 = new TF1("eta1","x*0.974168",0,80);
eta1->SetFillColor(1);
eta1->SetFillStyle(0);
eta1->SetLineWidth(3);
eta1->SetLineColor(kBlack);
eta1->Draw("same");

TF1 *eta2 = new TF1("eta2","x*0.469642",0,80);
eta2->SetFillColor(1);
eta2->SetFillStyle(0);
eta2->SetLineWidth(3);
eta2->SetLineColor(kBlack);
eta2->Draw("same");

TLine *line1 = new TLine(0,9.8,46.5,9.8);
line1->SetLineWidth(5);
line1->SetLineStyle(2);
line1->SetLineColor(kBlack);
TLine *line2 = new TLine(46.5, 0, 46.5,9.8);
line2->SetLineWidth(5);
line2->SetLineStyle(2);
line2->SetLineColor(kBlack);

line1->Draw("same");
line2->Draw("same");

//double scale = 1.0/(integral*1.0);
//return scale;

c1->SaveAs(Form("effA1_%d_%d.pdf",binx,biny));
}
