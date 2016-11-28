#include <TH1.h>

//TH1D *mGammaD_0250_Fitted_dz_plot = new TH1D("mGammaD_0250_Fitted_dz_plot", "mGammaD_0250_Fitted_dz_plot", 150, -0.15, 0.15);
//TH1D *mGammaD_0275_Fitted_Iso_plot = new TH1D("mGammaD_0275_Fitted_Iso_plot", "mGammaD_0275_Fitted_Iso_plot", 100, 0, 100);
// TH1D *mGammaD_0275_Fitted_Iso_zoom_plot = new TH1D("mGammaD_0275_Fitted_Iso_zoom_plot", "mGammaD_0275_Fitted_Iso_zoom_plot", 100, 0, 10);

TH1D *iso_fom = new TH1D("iso_fom", "iso_fom", 100, 0, 10);
TH1D *dz_fom = new TH1D("dz_fom", "dz_fom", 150, -0.15, 0.15);

void analyze_iso(TH1D* signal, TH1D* background){

	//There are 100 xbins.  From 0-10.  Each bin is 0.1 GeV wide.
	for(int xbin = 0; xbin < 100; xbin++){ //loop over x-bins
	double sig  = signal->GetBinContent(xbin);
	double back = background->GetBinContent(xbin);
		if(sig == 0 || back == 0) continue;

	//FOM
	double fom = sig/sqrt(sig+back);
	iso_fom->SetBinContent(xbin, fom);
	
	}
}

void analyze_dz(TH1D* signal, TH1D* background){

	//There are 150 xbins.  From -0.15 - 0.15.
	for(int xbin = 0; xbin < 150; xbin++){ //loop over x-bins
		double sig  = signal->GetBinContent(xbin);
		double back = background->GetBinContent(xbin);
		//FOM
		double fom = sig/sqrt(sig+back);
		dz_fom->SetBinContent(xbin, fom);
	}
}    

void runAll(){
	analyze_iso(mGammaD_0250_Fitted_Iso_zoom_plot, bbar_Iso_zoom_plot);
	analyze_dz(mGammaD_0250_Fitted_dz_plot, bbar_Fitted_dz_plot);
	
	TCanvas *m = new TCanvas("m", "m", 700, 500);
	gStyle->SetOptStat(0);
	iso_fom->SetMarkerStyle(20);
	iso_fom->Draw("P");
	m->SaveAs("isoFOM.C");
	m->SaveAs("isoFOM.pdf");
	m->SaveAs("isoFOM.png");

	TCanvas *m1 = new TCanvas("m1", "m1", 700, 500);
	gStyle->SetOptStat(0);
	dz_fom->SetMarkerStyle(20);
	dz_fom->Draw("P");
	m1->SaveAs("dzFOM.C");
	m1->SaveAs("dzFOM.pdf");
	m1->SaveAs("dzFOM.png");
}

