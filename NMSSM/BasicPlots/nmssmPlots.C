#include <iostream>
using namespace std;
#include <algorithm>    // std::max
#include <stdlib.h>
#include <iomanip>
#include "TMath.h"
#include <math.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include "TChain.h"
#include "TGraphErrors.h" 
#include "TCollection.h"
#include "TSystemFile.h"
#include "TSystemDirectory.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TChainElement.h" 
#include "TStyle.h"

//============= Global Variables ===========================//
TFile *BAM = new TFile("NMSSM_Plots.root","RECREATE");

//Plot initialization
//{{{

TH1F *t1_pT_ofA0 = new TH1F("t1_pT_ofA0", "t1_pT_ofA0", 120, 0, 120);
TH1F *t1_pT_ofA1 = new TH1F("t1_pT_ofA1", "t1_pT_ofA1", 120, 0, 120);
TH1F *t1_pT_ofMu0 = new TH1F("t1_pT_ofMu0", "t1_pT_ofMu0", 120, 0, 120);
TH1F *t1_pT_ofMu1 = new TH1F("t1_pT_ofMu1", "t1_pT_ofMu1", 120, 0, 120);
TH1F *t1_pT_ofMu2 = new TH1F("t1_pT_ofMu2", "t1_pT_ofMu2", 120, 0, 120);
TH1F *t1_pT_ofMu3 = new TH1F("t1_pT_ofMu3", "t1_pT_ofMu3", 120, 0, 120);

//}}}

void addfiles(TChain *ch, const TString dirname=".", const TString ext=".root")
{
	bool verbose(false);
	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();
	if (files) {
		if (verbose) std::cout << "Found files" << std::endl;
		TSystemFile *file;
		TString fname;
		TIter next(files);
		while ((file=(TSystemFile*)next())) {
			fname = file->GetName();
			if (verbose) std::cout << "found fname " << fname << std::endl;
			if (!file->IsDirectory() && fname.BeginsWith(ext)) {
				if (verbose) std::cout << "adding fname " << fname << std::endl;
				ch->Add(fname);
			}
		}
	}
}

void analyze(TString fileName){
	bool verbose(true);
	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

	// add files to the chain
	addfiles(chain, dirname, ext);

	//Initialize Variables and counters
	//{{{
	Float_t genA0_px;
	Float_t genA0_py;

	Float_t genA1_px;
	Float_t genA1_py;

Float_t genMu0_pT;
Float_t genMu1_pT;
Float_t genMu2_pT;
Float_t genMu3_pT;
	//}}}

	TObjArray *fileElements=chain->GetListOfFiles();
	TIter next(fileElements);
	TChainElement *chEl=0;

	while ((chEl=(TChainElement*)next())) {
		if (verbose) std::cout << "running on file " << chEl->GetTitle() << std::endl;
		TFile* myfile = new TFile(dirname + chEl->GetTitle());
		if (!myfile) {
			if (verbose) std::cout << "File " << chEl->GetTitle() << " does not exist" << std::endl;
			continue;
		}

		if (verbose) std::cout << "Loading directory cutFlowAnalyzerPXBL3PXFL2" << std::endl;
		myfile->cd("cutFlowAnalyzerPXBL3PXFL2");

		TTree *t = (TTree*)myfile->Get("cutFlowAnalyzerPXBL3PXFL2/Events");
		if (!t) {
			if (verbose) std::cout << "Tree cutFlowAnalyzerPXBL3PXFL2/Events does not exist" << std::endl;
			continue;
		}

		if (verbose) cout<<"  Events  "<<t->GetEntries()<<endl;

		//Pull variables from nTuple
		//{{{
		// Event info
		t->SetBranchAddress("genA0_px", &genA0_px);
		t->SetBranchAddress("genA0_py", &genA0_py);

		t->SetBranchAddress("genA1_px", &genA1_px);
		t->SetBranchAddress("genA1_py", &genA1_py);

		t->SetBranchAddress("genMu0_pT", &genMu0_pT);
		t->SetBranchAddress("genMu1_pT", &genMu1_pT);
		t->SetBranchAddress("genMu2_pT", &genMu2_pT);
		t->SetBranchAddress("genMu3_pT", &genMu3_pT);
		//}}}

		for(int k=0;k<t->GetEntries();k++){
			t->GetEntry(k);

			t1_pT_ofA0->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
			t1_pT_ofA1->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));

			t1_pT_ofMu0->Fill(genMu0_pT);
			t1_pT_ofMu1->Fill(genMu1_pT);
			t1_pT_ofMu2->Fill(genMu2_pT);
			t1_pT_ofMu3->Fill(genMu3_pT);

		} // closing for loop
		myfile->Close();
	} // closing while loop
}

void makePlotsPretty(){

	TCanvas *c1 = new TCanvas("c1","c1",700,500);
	gStyle->SetOptStat(0);
	t1_pT_ofA0->SetTitle("CMS Simulation #sqrt{s} = 13 TeV");
	t1_pT_ofA0->GetXaxis()->SetTitle("p_{T} of a_{1} GeV/c");
	t1_pT_ofA0->GetYaxis()->SetTitle("1/N #times dN/dp_{T}, 1/(1 GeV/c)");
	t1_pT_ofA0->SetLineColor(kRed);
	t1_pT_ofA0->DrawNormalized();
	t1_pT_ofA1->SetLineColor(kBlue);
	t1_pT_ofA1->SetLineStyle(2);
	t1_pT_ofA1->DrawNormalized("same");

	TLegend *leg = new TLegend(0.6174785,0.7405063,0.8997135,0.9008439,NULL,"brNDC");
	leg->AddEntry("t1_pT_ofA0", "leading a_{1}", "L");
	leg->AddEntry("t1_pT_ofA1", "next-to-leading a_{1}", "L");
	leg->Draw("same");
	c1->SaveAs("NMMSM_pTofA.pdf");
	c1->SaveAs("NMMSM_pTofA.png");
	c1->SaveAs("NMMSM_pTofA.C");
	c1->Clear();

   t1_pT_ofMu3->SetTitle("CMS Simulation #sqrt{s} = 13 TeV");
   t1_pT_ofMu3->GetXaxis()->SetTitle("p_{T} of #mu GeV/c");
   t1_pT_ofMu3->GetYaxis()->SetTitle("1/N #times dN/dp_{T}, 1/(1 GeV/c)");
   t1_pT_ofMu3->SetLineStyle(3);
   t1_pT_ofMu3->SetLineColor(kBlack);
   t1_pT_ofMu2->SetLineStyle(2);
   t1_pT_ofMu2->SetLineColor(kGreen);
   t1_pT_ofMu1->SetLineStyle(4);
   t1_pT_ofMu1->SetLineColor(kRed);
   t1_pT_ofMu0->SetLineColor(kBlue);

   t1_pT_ofMu3->DrawNormalized();
   t1_pT_ofMu2->DrawNormalized("same");
   t1_pT_ofMu1->DrawNormalized("same");
   t1_pT_ofMu0->DrawNormalized("same");

   TLegend *leg2 = new TLegend(0.7320917,0.7822222,0.8997135,0.9,NULL,"brNDC");
   leg2->AddEntry("t1_pT_ofMu0", "1st (leading) #mu", "L");
   leg2->AddEntry("t1_pT_ofMu1", "2nd #mu", "L");
   leg2->AddEntry("t1_pT_ofMu2", "3nd #mu", "L");
   leg2->AddEntry("t1_pT_ofMu3", "4th #mu", "L");
   leg2->Draw("same");

   c1->SaveAs("NMMSM_pTofMu.pdf");
   c1->SaveAs("NMMSM_pTofMu.png");
   c1->SaveAs("NMMSM_pTofMu.C");
   c1->Clear();

}


void nmssmPlots()
{
	cout << "Begin plotting NMSSM" << endl;
	analyze("/fdata/hepx/store/user/bmichlin/NMSSM_mH_125_mA_2_ForAN_Plots/");
	makePlotsPretty();
	BAM->Write();
}

