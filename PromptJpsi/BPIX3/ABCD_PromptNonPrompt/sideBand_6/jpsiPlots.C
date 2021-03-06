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
TFile *BAM = new TFile("Jpsi_Plots.root","RECREATE");

//Plot initialization
//{{{

TH1F *t1_data_jpsi_event_failure_type = new TH1F("t1_data_jpsi_event_failure_type","t1_data_jpsi_event_failure_type",7, 0, 7);
TH1F *t1_data_jpsi_inv_mass_dimuon1   = new TH1F("t1_data_jpsi_inv_mass_dimuon1","t1_data_jpsi_inv_mass_dimuon1",75, 0, 15);
TH1F *t1_data_jpsi_inv_mass_dimuon2   = new TH1F("t1_data_jpsi_inv_mass_dimuon2","t1_data_jpsi_inv_mass_dimuon2",75, 0, 15);
TH1F *t1_data_jpsi_mass_dimuon1       = new TH1F("t1_data_jpsi_mass_dimuon1","t1_data_jpsi_mass_dimuon1",75, 0, 15);
TH1F *t1_data_jpsi_mass_dimuon2       = new TH1F("t1_data_jpsi_mass_dimuon2","t1_data_jpsi_mass_dimuon2",75, 0, 15);
TH1F *t1_data_jpsi_invmass_1plus2        = new TH1F("t1_data_jpsi_invmass_1plus2","t1_data_jpsi_invmass_1plus2",140, 0, 140);
TH1F *t1_data_jpsi_isoTk_dimuon1      = new TH1F("t1_data_jpsi_isoTk_dimuon1","t1_data_jpsi_isoTk_dimuon1",48, 0, 12);
TH1F *t1_data_jpsi_isoTk_dimuon2      = new TH1F("t1_data_jpsi_isoTk_dimuon2","t1_data_jpsi_isoTk_dimuon2",48, 0, 12);
TH1F *t1_data_jpsi_deltay             = new TH1F("t1_data_jpsi_deltay", "t1_data_jpsi_deltay", 50, 0, 5);
TH1F *t1_data_jpsi_DeltaRapidityC             = new TH1F("t1_data_jpsi_DeltaRapidityC", "t1_data_jpsi_DeltaRapidityC", 50, 0, 5);
TH1F *t1_data_jpsi_DeltaRapidityA             = new TH1F("t1_data_jpsi_DeltaRapidityA", "t1_data_jpsi_DeltaRapidityA", 50, 0, 5);

TH2F *t2_data_jpsi_inv_mass		 = new TH2F("t2_data_jpsi_inv_mass", "t2_data_jpsi_inv_mass", 100, 0, 5, 100, 0, 5);
TH2F *t2_data_jpsi_iso		 = new TH2F("t2_data_jpsi_iso", "t2_data_jpsi_iso", 48, 0, 12, 48, 0, 12);

int regionA = 0;
int regionB = 0;
int regionC = 0;
int regionD = 0;
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
	bool verbose(false);
	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

	// add files to the chain
	addfiles(chain, dirname, ext);

	//Initialize Variables and counters
	//{{{
	Float_t jpsi_event_failure_type;
	Float_t jpsi_inv_mass_dimuon1;
	Float_t jpsi_inv_mass_dimuon2;
	Float_t jpsi_mass_dimuon1;
	Float_t jpsi_mass_dimuon2;
	Float_t jpsi_isoTk_dimuon1;
	Float_t jpsi_isoTk_dimuon2;
	Float_t jpsi_Lxy_dimuon1;
	Float_t jpsi_Lxy_dimuon2;
	Float_t jpsi_L_dimuon1;
	Float_t jpsi_L_dimuon2;
	Float_t jpsi_px_dimuon1;
	Float_t jpsi_px_dimuon2;
	Float_t jpsi_py_dimuon1;
	Float_t jpsi_py_dimuon2;
	Float_t jpsi_pz_dimuon1;
	Float_t jpsi_pz_dimuon2;
	Int_t   jpsi_trigger;
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

		TTree *t = (TTree*)myfile->Get("cutFlowAnalyzerPXBL3PXFL2/Jpsi_Events");
		if (!t) {
			if (verbose) std::cout << "Tree cutFlowAnalyzerPXBL3PXFL2/Jpsi_Events does not exist" << std::endl;
			continue;
		}

		if (verbose) cout<<"  Events  "<<t->GetEntries()<<endl;

		//Pull variables from nTuple
		//{{{
		// Event info
		t->SetBranchAddress("jpsi_event_failure_type", &jpsi_event_failure_type);
		t->SetBranchAddress("jpsi_inv_mass_dimuon1", &jpsi_inv_mass_dimuon1);
		t->SetBranchAddress("jpsi_inv_mass_dimuon2", &jpsi_inv_mass_dimuon2);
		t->SetBranchAddress("jpsi_mass_dimuon1", &jpsi_mass_dimuon1);
		t->SetBranchAddress("jpsi_mass_dimuon2", &jpsi_mass_dimuon2);
		t->SetBranchAddress("jpsi_isoTk_dimuon1", &jpsi_isoTk_dimuon1 );
		t->SetBranchAddress("jpsi_isoTk_dimuon2", &jpsi_isoTk_dimuon2 );
		t->SetBranchAddress("jpsi_Lxy_dimuon1", &jpsi_Lxy_dimuon1 );
		t->SetBranchAddress("jpsi_Lxy_dimuon2", &jpsi_Lxy_dimuon2 );
		t->SetBranchAddress("jpsi_L_dimuon1", &jpsi_L_dimuon1 );
		t->SetBranchAddress("jpsi_L_dimuon2", &jpsi_L_dimuon2 );
		t->SetBranchAddress("jpsi_px_dimuon1", &jpsi_px_dimuon1);
		t->SetBranchAddress("jpsi_px_dimuon2", &jpsi_px_dimuon2);
		t->SetBranchAddress("jpsi_py_dimuon1", &jpsi_py_dimuon1);
		t->SetBranchAddress("jpsi_py_dimuon2", &jpsi_py_dimuon2);
		t->SetBranchAddress("jpsi_pz_dimuon1", &jpsi_pz_dimuon1);
		t->SetBranchAddress("jpsi_pz_dimuon2", &jpsi_pz_dimuon2);
		t->SetBranchAddress("jpsi_trigger", &jpsi_trigger );
		//}}}

		for(int k=0;k<t->GetEntries();k++){
			t->GetEntry(k);
			t1_data_jpsi_event_failure_type->Fill(jpsi_event_failure_type);

			if(jpsi_trigger == 1){ //Make sure that the event fired the trigger. 0 to turn the trigger off for MC
				//cout << "Trigger was fired" << endl;

				if(jpsi_inv_mass_dimuon1 >= 0 && jpsi_inv_mass_dimuon2 >= 0){//Make sure that the nTuple was filled
					//cout << "nTuple was filled.  Filling plots." << endl;

					t1_data_jpsi_inv_mass_dimuon1->Fill(jpsi_inv_mass_dimuon1);  
					t1_data_jpsi_inv_mass_dimuon2->Fill(jpsi_inv_mass_dimuon2); 
					t1_data_jpsi_mass_dimuon1->Fill(jpsi_mass_dimuon1);      
					t1_data_jpsi_mass_dimuon2->Fill(jpsi_mass_dimuon2);      
					t2_data_jpsi_inv_mass->Fill(jpsi_inv_mass_dimuon1, jpsi_inv_mass_dimuon2);

					//Fill system inv mass here
					double p1 = sqrt(jpsi_px_dimuon1*jpsi_px_dimuon1+jpsi_py_dimuon1*jpsi_py_dimuon1+jpsi_pz_dimuon1*jpsi_pz_dimuon1);
					double p2 = sqrt(jpsi_px_dimuon2*jpsi_px_dimuon2+jpsi_py_dimuon2*jpsi_py_dimuon2+jpsi_pz_dimuon2*jpsi_pz_dimuon2);

					double e1 = sqrt(p1*p1 + jpsi_inv_mass_dimuon1*jpsi_inv_mass_dimuon1);
					double e2 = sqrt(p2*p2 + jpsi_inv_mass_dimuon2*jpsi_inv_mass_dimuon2);

					t1_data_jpsi_invmass_1plus2->Fill(sqrt( ((p1+p2)*(p1+p2)) - (e1+e2)*(e1-e2) ));

					//Fill rapidity
					double num1 = e1 + jpsi_pz_dimuon1;
					double num2 = e2 + jpsi_pz_dimuon2;

					double den1 = e1 - jpsi_pz_dimuon1;
					double den2 = e2 - jpsi_pz_dimuon2;

					double arg1 = num1/den1;
					double arg2 = num2/den2;

					double ln1 = log(arg1);
					double ln2 = log(arg2);

					double y1 = (0.5)*ln1;
					double y2 = (0.5)*ln2;

					double dy = fabs(y1-y2);
					//cout << "px, py, pz, p1, m1, e, num, den, ln, y: " << jpsi_px_dimuon1 << ", " << jpsi_py_dimuon1 << ", " << jpsi_pz_dimuon1 << ", " << p1 << ", " << jpsi_inv_mass_dimuon1 << ", " << e1 << ", " << num1 << ", " << den1 << ", " << ln1 << ", " << y1 << endl;
					t1_data_jpsi_deltay->Fill(dy);

					//isolation
					if(jpsi_isoTk_dimuon1 >= 0 && jpsi_isoTk_dimuon2 >= 0){

						t1_data_jpsi_isoTk_dimuon1->Fill(jpsi_isoTk_dimuon1); 
						t1_data_jpsi_isoTk_dimuon2->Fill(jpsi_isoTk_dimuon2);     
						t2_data_jpsi_iso->Fill(jpsi_isoTk_dimuon1, jpsi_isoTk_dimuon2);
					}
				}
				//Begin ABCD method to separate prompt and non-prompt Jpsis in data

				//Clean data
				if(jpsi_inv_mass_dimuon1 > 3.3 || jpsi_inv_mass_dimuon1 < 2.8 || jpsi_inv_mass_dimuon2 > 3.3 || jpsi_inv_mass_dimuon2 < 2.8) continue;
				if(jpsi_isoTk_dimuon1 < 0 || jpsi_isoTk_dimuon2 < 0 || jpsi_isoTk_dimuon1 > 6 || jpsi_isoTk_dimuon2 > 6) continue;


				//---Rapidity for DPS/SPS
				double p1 = sqrt(jpsi_px_dimuon1*jpsi_px_dimuon1+jpsi_py_dimuon1*jpsi_py_dimuon1+jpsi_pz_dimuon1*jpsi_pz_dimuon1);
				double p2 = sqrt(jpsi_px_dimuon2*jpsi_px_dimuon2+jpsi_py_dimuon2*jpsi_py_dimuon2+jpsi_pz_dimuon2*jpsi_pz_dimuon2);

				double e1 = sqrt(p1*p1 + jpsi_inv_mass_dimuon1*jpsi_inv_mass_dimuon1);
				double e2 = sqrt(p2*p2 + jpsi_inv_mass_dimuon2*jpsi_inv_mass_dimuon2);

				double num1 = e1 + jpsi_pz_dimuon1;
				double num2 = e2 + jpsi_pz_dimuon2;

				double den1 = e1 - jpsi_pz_dimuon1;
				double den2 = e2 - jpsi_pz_dimuon2;

				double arg1 = num1/den1;
				double arg2 = num2/den2;

				double ln1 = log(arg1);
				double ln2 = log(arg2);

				double y1 = (0.5)*ln1;
				double y2 = (0.5)*ln2;

				double dy = fabs(y1-y2);


				//Count number of entries in each region
				if(jpsi_isoTk_dimuon1 <= 2 && jpsi_isoTk_dimuon2 <= 2){ regionA++; t1_data_jpsi_DeltaRapidityA->Fill(dy); }
				if(jpsi_isoTk_dimuon1 <= 2 && jpsi_isoTk_dimuon2 > 2 ) regionB++;
				if(jpsi_isoTk_dimuon1 > 2  && jpsi_isoTk_dimuon2 > 2 ){ regionC++; t1_data_jpsi_DeltaRapidityC->Fill(dy);}
				if(jpsi_isoTk_dimuon1 > 2  && jpsi_isoTk_dimuon2 <= 2) regionD++;


			}

		} // closing for loop
		myfile->Close();
	} // closing while loop
}

void getCorrAndStats(){
	cout << "Correlation factor between IsoTK of dimuon1 and 2: " << t2_data_jpsi_iso->GetCorrelationFactor() << endl;
	cout << "Number of data events in region A, B, C, D       : " << regionA << ", " << regionB << ", " << regionC << ", " << regionD << endl;
	double na_prompt = regionA - regionB*((double)regionD/regionC);
	double one = sqrt(regionA)*sqrt(regionA);
	double twoNum = (sqrt(regionD)*sqrt(regionD))*(regionB*regionB);
	double twoDen = regionC*regionC;
	double threeNum = sqrt(regionC)*sqrt(regionC)*regionB*regionB*regionD*regionD;
	double threeDen = pow(regionC,4);
	double fourNum = sqrt(regionB)*sqrt(regionB)*regionD*regionD;
	double fourDen = regionC*regionC;

	double statUncert = sqrt(one+(twoNum/twoDen)+(threeNum/threeDen)+(fourNum/fourDen));
	cout << "Estimated number of prompt Jpsi in region A      : " << na_prompt << " +/- " << statUncert << endl;
	double na_nonprompt = regionB*((double)regionD/regionC);
	double uncert_non = sqrt((twoNum/twoDen)+(threeNum/threeDen)+(fourNum/fourDen)); 
	cout << "Estimated number of non-prompt Jpsi in region A  : " << na_nonprompt << " +/- " << uncert_non << endl;
}

void makePlotsPretty(){

	TCanvas *c1 = new TCanvas("c1","c1",700,500);
	t1_data_jpsi_event_failure_type->Draw();
	c1->SaveAs("Event_Failure_Type.pdf");
	c1->Clear();

	t1_data_jpsi_inv_mass_dimuon1->GetXaxis()->SetTitle("m_{#mu#mu_{1}} [GeV/c^{2}]");
	t1_data_jpsi_inv_mass_dimuon1->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_inv_mass_dimuon1->DrawNormalized();
	c1->SaveAs("InvMass1.pdf");
	c1->Clear();

	t1_data_jpsi_inv_mass_dimuon2->GetXaxis()->SetTitle("m_{#mu#mu_{2}} [GeV/c^{2}]");
	t1_data_jpsi_inv_mass_dimuon2->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_inv_mass_dimuon2->DrawNormalized();
	c1->SaveAs("InvMass2.pdf");
	c1->Clear();

	t1_data_jpsi_mass_dimuon1->GetXaxis()->SetTitle("m_{#mu#mu_{1}} [GeV/c^{2}]");
	t1_data_jpsi_mass_dimuon1->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_mass_dimuon1->DrawNormalized();
	c1->SaveAs("Mass1.pdf");
	c1->Clear();

	t1_data_jpsi_mass_dimuon2->GetXaxis()->SetTitle("m_{#mu#mu_{2}} [GeV/c^{2}]");
	t1_data_jpsi_mass_dimuon2->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_mass_dimuon2->DrawNormalized();
	c1->SaveAs("Mass2.pdf");
	c1->Clear();

	t1_data_jpsi_invmass_1plus2->GetXaxis()->SetTitle("m_{#mu#mu_{1} + #mu#mu_{2}} [GeV/c^{2}]");
	t1_data_jpsi_invmass_1plus2->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_invmass_1plus2->DrawNormalized();
	c1->SaveAs("InvMass1plus2.pdf");
	c1->Clear();

	t1_data_jpsi_isoTk_dimuon1->GetXaxis()->SetTitle("Iso_{#mu#mu_{1}} [GeV/c]");
	t1_data_jpsi_isoTk_dimuon1->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_isoTk_dimuon1->DrawNormalized();
	c1->SaveAs("IsoTk_1.pdf");
	c1->Clear();

	t1_data_jpsi_isoTk_dimuon2->GetXaxis()->SetTitle("Iso_{#mu#mu_{2}} [GeV/c]");
	t1_data_jpsi_isoTk_dimuon2->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_isoTk_dimuon2->DrawNormalized();
	c1->SaveAs("IsoTk_2.pdf");
	c1->Clear();

	t1_data_jpsi_deltay->GetXaxis()->SetTitle("|#Delta y|");
	t1_data_jpsi_deltay->GetYaxis()->SetTitle("Fraction of Events");
	t1_data_jpsi_deltay->DrawNormalized();
	c1->SaveAs("deltaY.pdf");
	c1->Clear();

	t2_data_jpsi_inv_mass->GetXaxis()->SetTitle("m_{#mu#mu_{1}} [GeV/c^{2}]");
	t2_data_jpsi_inv_mass->GetYaxis()->SetTitle("m_{#mu#mu_{2}} [GeV/c^{2}]");
	gPad->SetLogz(1);
	t2_data_jpsi_inv_mass->Draw("colz");
	c1->SaveAs("2D_invMass.pdf");
	c1->Clear();

	t2_data_jpsi_iso->GetXaxis()->SetTitle("Iso_{#mu#mu_{1}} [GeV/c]");
	t2_data_jpsi_iso->GetYaxis()->SetTitle("Iso_{#mu#mu_{2}} [GeV/c]");
	gPad->SetLogz(1);
	t2_data_jpsi_iso->Draw("colz");
	c1->SaveAs("2D_iso.pdf");
	c1->Clear();

}


void jpsiPlots()
{
	cout << "Begin plotting Jpsi" << endl;

	//analyze("/fdata/hepx/store/user/bmichlin/DPS_BPIX3/LowPT_Thresholds/Combined/"); //DPS MC
	//analyze("/fdata/hepx/store/user/bmichlin/SPS_BPIX3/LowPT_Threshold/"); //SPS MC
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015C_763_patTuple_cutana_mujets_Run2015C_ReReco_AOD_V1/160715_213415/0000/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_763_patTuple_cutana_mujets_Run2015D_ReReco_AOD_V1/160715_213318/0000/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_763_patTuple_cutana_mujets_Run2015D_ReReco_AOD_V1/160715_213318/0001/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_763_patTuple_cutana_mujets_Run2015D_ReReco_AOD_V1/160715_213318/0002/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_763_patTuple_cutana_mujets_Run2015D_ReReco_AOD_V1/160715_213318/0003/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_763_patTuple_cutana_mujets_Run2015D_ReReco_AOD_V1/160715_213318/0004/"); //Data

	//old
	/*
	//analyze("/afs/cern.ch/work/b/bmichlin/public/withTAMU/JPSI_Estimation/CMSSW_7_4_12_patch4/src/MuJetAnalysis/AnalysisRun2/scripts/JpsiAnalysis/DPS/DPS_data/"); //DPS MC
	//analyze("/fdata/hepx/store/user/bmichlin/SPS_SLURM_v1/"); //SPS MC
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v3_v27/160316_215529/0000/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v4_v27/160316_215441/0000/"); //Data
	analyze("/fdata/hepx/store/user/bmichlin/MuOnia/DoubleJpsi_2015D_7412p4_patTuple_cutana_mujets_Run2015D_v4_v27/160316_215441/0001/"); //Data
	*/

	getCorrAndStats();
	makePlotsPretty();
	BAM->Write();
}

