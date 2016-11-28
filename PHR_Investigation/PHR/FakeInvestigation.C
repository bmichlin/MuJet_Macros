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
#include "/home/bmichlin/TreeLoop/BaseBranchCheck/CMSSW_7_4_1_patch1/src/MuJetAnalysis/AnalysisRun2/scripts/LatexHelpers.h"

//============= Global Variables ===========================//
TFile *BAM = new TFile("erec_alphagen_FittedVTX_0250_GeV.root","RECREATE");

//Plot initialization
//{{{

TH2F *MassPlot_NoCuts = new TH2F("MassPlot_NoCuts", "MassPlot_NoCuts", 1000, 0, 10, 1000, 0, 10);
TH2F *MassPlot_GenFidCut = new TH2F("MassPlot_GenFidCut", "MassPlot_GenFidCut", 1000, 0, 10, 1000, 0, 10);

TH2F *RecoveredDimuonC_Reco_MassPlot = new TH2F("RecoveredDimuonC_Reco_MassPlot","RecoveredDimuonC_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *RecoveredDimuonF_Reco_MassPlot = new TH2F("RecoveredDimuonF_Reco_MassPlot","RecoveredDimuonF_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *PassWithNoPHRDimuonC_Reco_MassPlot = new TH2F("PassWithNoPHRDimuonC_Reco_MassPlot","PassWithNoPHRDimuonC_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *PassWithNoPHRDimuonF_Reco_MassPlot = new TH2F("PassWithNoPHRDimuonF_Reco_MassPlot","PassWithNoPHRDimuonF_Reco_MassPlot", 100, 0, 10, 100, 0, 10);

TH2F *RecoveredDimuonC_Reco_Lxy_vs_Mass = new TH2F("RecoveredDimuonC_Reco_Lxy_vs_Mass","RecoveredDimuonC_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *RecoveredDimuonF_Reco_Lxy_vs_Mass = new TH2F("RecoveredDimuonF_Reco_Lxy_vs_Mass","RecoveredDimuonF_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *PassWithNoPHRDimuonC_Reco_Lxy_vs_Mass = new TH2F("PassWithNoPHRDimuonC_Reco_Lxy_vs_Mass","PassWithNoPHRDimuonC_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *PassWithNoPHRDimuonF_Reco_Lxy_vs_Mass = new TH2F("PassWithNoPHRDimuonF_Reco_Lxy_vs_Mass","PassWithNoPHRDimuonF_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);

TH1F *RecoveredDimuonC_Reco_Lxy = new TH1F("RecoveredDimuonC_Reco_Lxy", "RecoveredDimuonC_Reco_Lxy", 400, 0, 80 );
TH1F *RecoveredDimuonC_Reco_Eta = new TH1F("RecoveredDimuonC_Reco_Eta", "RecoveredDimuonC_Reco_Eta", 500, -5, 5);
TH1F *RecoveredDimuonC_Reco_Phi = new TH1F("RecoveredDimuonC_Reco_Phi", "RecoveredDimuonC_Reco_Phi", 340, -3.4, 3.4);
TH1F *RecoveredDimuonC_Reco_pT = new TH1F("RecoveredDimuonC_Reco_pT", "RecoveredDimuonC_Reco_pT", 100, 0, 100);
TH2F *RecoveredDimuonC_Reco_pT_vs_Lxy = new TH2F("RecoveredDimuonC_Reco_pT_vs_Lxy", "RecoveredDimuonC_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *RecoveredDimuonC_Reco_Dimuon_Opening_Angle = new TH1F("RecoveredDimuonC_Reco_Dimuon_Opening_Angle", "RecoveredDimuonC_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *PassWithNoPHRDimuonC_Reco_Lxy = new TH1F("PassWithNoPHRDimuonC_Reco_Lxy", "PassWithNoPHRDimuonC_Reco_Lxy", 400, 0, 80 );
TH1F *PassWithNoPHRDimuonC_Reco_Eta = new TH1F("PassWithNoPHRDimuonC_Reco_Eta", "PassWithNoPHRDimuonC_Reco_Eta", 500, -5, 5);
TH1F *PassWithNoPHRDimuonC_Reco_Phi = new TH1F("PassWithNoPHRDimuonC_Reco_Phi", "PassWithNoPHRDimuonC_Reco_Phi", 340, -3.4, 3.4);
TH1F *PassWithNoPHRDimuonC_Reco_pT = new TH1F("PassWithNoPHRDimuonC_Reco_pT", "PassWithNoPHRDimuonC_Reco_pT", 100, 0, 100);
TH2F *PassWithNoPHRDimuonC_Reco_pT_vs_Lxy = new TH2F("PassWithNoPHRDimuonC_Reco_pT_vs_Lxy", "PassWithNoPHRDimuonC_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *PassWithNoPHRDimuonC_Reco_Dimuon_Opening_Angle = new TH1F("PassWithNoPHRDimuonC_Reco_Dimuon_Opening_Angle", "PassWithNoPHRDimuonC_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *PassWithNoPHRDimuonF_Reco_Lxy = new TH1F("PassWithNoPHRDimuonF_Reco_Lxy", "PassWithNoPHRDimuonF_Reco_Lxy", 400, 0, 80 );
TH1F *PassWithNoPHRDimuonF_Reco_Eta = new TH1F("PassWithNoPHRDimuonF_Reco_Eta", "PassWithNoPHRDimuonF_Reco_Eta", 500, -5, 5);
TH1F *PassWithNoPHRDimuonF_Reco_Phi = new TH1F("PassWithNoPHRDimuonF_Reco_Phi", "PassWithNoPHRDimuonF_Reco_Phi", 340, -3.4, 3.4);
TH1F *PassWithNoPHRDimuonF_Reco_pT = new TH1F("PassWithNoPHRDimuonF_Reco_pT", "PassWithNoPHRDimuonF_Reco_pT", 100, 0, 100);
TH2F *PassWithNoPHRDimuonF_Reco_pT_vs_Lxy = new TH2F("PassWithNoPHRDimuonF_Reco_pT_vs_Lxy", "PassWithNoPHRDimuonF_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *PassWithNoPHRDimuonF_Reco_Dimuon_Opening_Angle = new TH1F("PassWithNoPHRDimuonF_Reco_Dimuon_Opening_Angle", "PassWithNoPHRDimuonF_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *RecoveredDimuonF_Reco_Lxy = new TH1F("RecoveredDimuonF_Reco_Lxy", "RecoveredDimuonF_Reco_Lxy", 400, 0, 80 );
TH1F *RecoveredDimuonF_Reco_Eta = new TH1F("RecoveredDimuonF_Reco_Eta", "RecoveredDimuonF_Reco_Eta", 500, -5, 5);
TH1F *RecoveredDimuonF_Reco_Phi = new TH1F("RecoveredDimuonF_Reco_Phi", "RecoveredDimuonF_Reco_Phi", 340, -3.4, 3.4);
TH1F *RecoveredDimuonF_Reco_pT = new TH1F("RecoveredDimuonF_Reco_pT", "RecoveredDimuonF_Reco_pT", 100, 0, 100);
TH2F *RecoveredDimuonF_Reco_pT_vs_Lxy = new TH2F("RecoveredDimuonF_Reco_pT_vs_Lxy", "RecoveredDimuonF_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *RecoveredDimuonF_Reco_Dimuon_Opening_Angle = new TH1F("RecoveredDimuonF_Reco_Dimuon_Opening_Angle", "RecoveredDimuonF_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH2F *RecoveredDimuonC_Gen_MassPlot = new TH2F("RecoveredDimuonC_Gen_MassPlot","RecoveredDimuonC_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *RecoveredDimuonF_Gen_MassPlot = new TH2F("RecoveredDimuonF_Gen_MassPlot","RecoveredDimuonF_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *PassWithNoPHRDimuonC_Gen_MassPlot = new TH2F("PassWithNoPHRDimuonC_Gen_MassPlot","PassWithNoPHRDimuonC_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *PassWithNoPHRDimuonF_Gen_MassPlot = new TH2F("PassWithNoPHRDimuonF_Gen_MassPlot","PassWithNoPHRDimuonF_Gen_MassPlot", 100, 0, 10, 100, 0, 10);

TH1F *RecoveredDimuonC_Gen_Lxy = new TH1F("RecoveredDimuonC_Gen_Lxy", "RecoveredDimuonC_Gen_Lxy", 400, 0, 80 );
TH1F *RecoveredDimuonC_Gen_Eta = new TH1F("RecoveredDimuonC_Gen_Eta", "RecoveredDimuonC_Gen_Eta", 500, -5, 5);
TH1F *RecoveredDimuonC_Gen_Phi = new TH1F("RecoveredDimuonC_Gen_Phi", "RecoveredDimuonC_Gen_Phi", 340, -3.4, 3.4);
TH1F *RecoveredDimuonC_Gen_pT = new TH1F("RecoveredDimuonC_Gen_pT", "RecoveredDimuonC_Gen_pT", 100, 0, 100); 
TH2F *RecoveredDimuonC_Gen_pT_vs_Lxy = new TH2F("RecoveredDimuonC_Gen_pT_vs_Lxy", "RecoveredDimuonC_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *RecoveredDimuonC_Gen_Dimuon_Opening_Angle = new TH1F("RecoveredDimuonC_Gen_Dimuon_Opening_Angle", "RecoveredDimuonC_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *PassWithNoPHRDimuonC_Gen_Lxy = new TH1F("PassWithNoPHRDimuonC_Gen_Lxy", "PassWithNoPHRDimuonC_Gen_Lxy", 400, 0, 80 );
TH1F *PassWithNoPHRDimuonC_Gen_Eta = new TH1F("PassWithNoPHRDimuonC_Gen_Eta", "PassWithNoPHRDimuonC_Gen_Eta", 500, -5, 5);
TH1F *PassWithNoPHRDimuonC_Gen_Phi = new TH1F("PassWithNoPHRDimuonC_Gen_Phi", "PassWithNoPHRDimuonC_Gen_Phi", 340, -3.4, 3.4);
TH1F *PassWithNoPHRDimuonC_Gen_pT = new TH1F("PassWithNoPHRDimuonC_Gen_pT", "PassWithNoPHRDimuonC_Gen_pT", 100, 0, 100); 
TH2F *PassWithNoPHRDimuonC_Gen_pT_vs_Lxy = new TH2F("PassWithNoPHRDimuonC_Gen_pT_vs_Lxy", "PassWithNoPHRDimuonC_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle = new TH1F("PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle", "PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *PassWithNoPHRDimuonF_Gen_Lxy = new TH1F("PassWithNoPHRDimuonF_Gen_Lxy", "PassWithNoPHRDimuonF_Gen_Lxy", 400, 0, 80 );
TH1F *PassWithNoPHRDimuonF_Gen_Eta = new TH1F("PassWithNoPHRDimuonF_Gen_Eta", "PassWithNoPHRDimuonF_Gen_Eta", 500, -5, 5);
TH1F *PassWithNoPHRDimuonF_Gen_Phi = new TH1F("PassWithNoPHRDimuonF_Gen_Phi", "PassWithNoPHRDimuonF_Gen_Phi", 340, -3.4, 3.4);
TH1F *PassWithNoPHRDimuonF_Gen_pT = new TH1F("PassWithNoPHRDimuonF_Gen_pT", "PassWithNoPHRDimuonF_Gen_pT", 100, 0, 100); 
TH2F *PassWithNoPHRDimuonF_Gen_pT_vs_Lxy = new TH2F("PassWithNoPHRDimuonF_Gen_pT_vs_Lxy", "PassWithNoPHRDimuonF_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle = new TH1F("PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle", "PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *RecoveredDimuonF_Gen_Lxy = new TH1F("RecoveredDimuonF_Gen_Lxy", "RecoveredDimuonF_Gen_Lxy", 400, 0, 80 );
TH1F *RecoveredDimuonF_Gen_Eta = new TH1F("RecoveredDimuonF_Gen_Eta", "RecoveredDimuonF_Gen_Eta", 500, -5, 5);
TH1F *RecoveredDimuonF_Gen_Phi = new TH1F("RecoveredDimuonF_Gen_Phi", "RecoveredDimuonF_Gen_Phi", 340, -3.4, 3.4);
TH1F *RecoveredDimuonF_Gen_pT = new TH1F("RecoveredDimuonF_Gen_pT", "RecoveredDimuonF_Gen_pT", 100, 0, 100); 
TH2F *RecoveredDimuonF_Gen_pT_vs_Lxy = new TH2F("RecoveredDimuonF_Gen_pT_vs_Lxy", "RecoveredDimuonF_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *RecoveredDimuonF_Gen_Dimuon_Opening_Angle = new TH1F("RecoveredDimuonF_Gen_Dimuon_Opening_Angle", "RecoveredDimuonF_Gen_Dimuon_Opening_Angle", 400, -4, 4);

//}}}
vector<double> mGammaD_0250_eff;
vector<double> mGammaD_0275_eff;
vector<double> mGammaD_0300_eff;
vector<double> mGammaD_2000_eff;
vector<double> mGammaD_8500_eff;
vector<double> mGammaD_0400_eff;
vector<double> mGammaD_0700_eff;
vector<double> mGammaD_1000_eff;
vector<double> mGammaD_1500_eff;

vector<double> mGammaD_0250_eff_uncert;
vector<double> mGammaD_0275_eff_uncert;
vector<double> mGammaD_0300_eff_uncert;
vector<double> mGammaD_2000_eff_uncert;
vector<double> mGammaD_8500_eff_uncert;
vector<double> mGammaD_0400_eff_uncert;
vector<double> mGammaD_0700_eff_uncert;
vector<double> mGammaD_1000_eff_uncert;
vector<double> mGammaD_1500_eff_uncert;

vector<double> mGammaD_0250_cT;
vector<double> mGammaD_0275_cT;
vector<double> mGammaD_0300_cT;
vector<double> mGammaD_2000_cT;
vector<double> mGammaD_8500_cT;
vector<double> mGammaD_0400_cT;
vector<double> mGammaD_0700_cT;
vector<double> mGammaD_1000_cT;
vector<double> mGammaD_1500_cT;

vector< vector<double> > FakeStatistics;

double My_dPhi (double phi1, double phi2) {
	double dPhi = phi1 - phi2;
	if (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
	if (dPhi <  -TMath::Pi()) dPhi += 2*TMath::Pi();
	return abs(dPhi); //Changed to abs 1/5/2016
}


Int_t BikeChain(Int_t numhits, Float_t hitposx[], Float_t hitposy[], Float_t muon1posx, Float_t muon1posy, Float_t muon2posx, Float_t muon2posy,Float_t radius){

	Float_t d_m1m2=10000;
	Float_t d_m1hit=10000;
	Float_t d_m2hit=10000;
	Float_t alpha=10000;
	Float_t alpha2=10000;
	Float_t h=10000;
	Float_t h2=10000;

	Int_t pass=0;

	d_m1m2 = sqrt(pow(muon1posx-muon2posx,2) + pow(muon1posy-muon2posy,2));

	for(int i=0;i<numhits;i++){

		d_m1hit = sqrt(pow(muon1posx - hitposx[i],2) + pow(muon1posy - hitposy[i],2) );
		d_m2hit = sqrt(pow(muon2posx - hitposx[i],2) + pow(muon2posy - hitposy[i],2) );

		alpha = acos( (pow(d_m1hit,2) + pow(d_m1m2,2) - pow(d_m2hit,2) )/ (2*d_m1hit*d_m1m2));
		alpha2 = acos( (pow(d_m2hit,2) + pow(d_m1m2,2) - pow(d_m1hit,2) )/ (2*d_m2hit*d_m1m2));

		h = d_m1hit*sin(alpha);
		h2 = d_m2hit*sin(alpha2);

		if( ( (alpha<1.57 && alpha2<1.57) && h<radius) || d_m1hit<radius || d_m2hit<radius) pass=1;
	}

	return pass;

}



int MatchRECOtoGENdimuons(double etaC, double phiC, double etaF, double phiF, double etaAC, double phiAC, double etaAF, double phiAF){
	int matchInt = -999;
	//match RECO C to GEN C 
	double dphi_CC = My_dPhi(phiC, phiAC);
	double deta_CC = etaC - etaAC;
	double dR_CC   = sqrt(dphi_CC*dphi_CC + deta_CC*deta_CC); 
	//match RECO F to GEN F
	double dphi_FF = My_dPhi(phiF, phiAF);
	double deta_FF = etaF - etaAF;
	double dR_FF   = sqrt(dphi_FF*dphi_FF + deta_FF*deta_FF);
	//match RECO C to GEN F
	double dphi_CF = My_dPhi(phiC, phiAF);
	double deta_CF = etaC - etaAF;
	double dR_CF   = sqrt(dphi_CF*dphi_CF + deta_CF*deta_CF);
	//match RECO F to GEN C
	double dphi_FC = My_dPhi(phiF, phiAC);
	double deta_FC = etaF - etaAC;
	double dR_FC   = sqrt(dphi_FC*dphi_FC + deta_FC*deta_FC);

	if((dR_CC+dR_FF) <= (dR_CF+dR_FC)){
		matchInt = 0; //Then RECO C-> GEN C and RECO F->GEN F
	}else{
		matchInt = 1; //Then RECO C->GEN F and RECO F->GEN C
	}
	return matchInt;
}

TString mass_string;
TString cT_string;
TString fileName;

std::map<TString, TString > mass_strings = {
        {"0250", "0.25"}, {"0275", "0.275"}, {"0300","0.3"}, {"0400", "0.4"}, {"0700", "0.7"},
		        {"1000", "1.0"}, {"1500", "1.5"}, {"2000", "2.0"}, {"8500", "8.5"}
				};
				std::map<TString, double > cT_strings = {
				        {"000_E",0.0}, {"005_E", 0.05}, {"010_E", 0.10}, {"020_E", 0.20}, {"050_E", 0.50}, {"100_E", 1.00},
						        {"200_E", 2.00}, {"300_E", 3.00}, {"500_E", 5.00}, {"1000_", 10.0}, {"2000_", 20.0}, {"8500_", 85.0}, {"5000_", 50.0}, {"10000", 100.0}
								};

void efficiency_hitrecovery(const std::vector<std::string>& dirNames){
	bool verbose(false);
	//	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

        decodeFileNameMany(dirNames, mass_string, cT_string);
		        fileName = "DarkSUSY_mH_125_mGammaD_" + mass_string + "_cT_" + cT_string;
				cout << "fileName: " << fileName << endl;



	// add files to the chain
	addfilesMany(chain, dirNames, ext);

	//Initialize Variables and counters
	//{{{

	Int_t event;
	Int_t run;
	Int_t lumi;

	Bool_t is4GenMu;
	Bool_t is1GenMu17;
	Bool_t is2GenMu8;
	Bool_t is3GenMu8;
	Bool_t is4GenMu8;

	Bool_t is1SelMu17;
	Bool_t is2SelMu8;
	Bool_t is3SelMu8;
	Bool_t is4SelMu8;

	Bool_t is2MuJets;
	Bool_t is2DiMuons;
	Bool_t is2DiMuonsFittedVtxOK;
	//Bool_t is2DiMuonsDzOK_FittedVtx;
	Float_t diMuons_dz_FittedVtx;
	Bool_t isDiMuonHLTFired;
	Bool_t is2DiMuonsMassOK_FittedVtx;
	//Bool_t is2DiMuonsIsoTkOK_FittedVtx;
	Float_t diMuonF_IsoTk_FittedVtx;
	Float_t diMuonC_IsoTk_FittedVtx;
	Bool_t isVertexOK;

	Float_t genA0_Lxy;
	Float_t genA1_Lxy;
	Float_t genA0_Lz;
	Float_t genA1_Lz;


	Int_t diMuonC_m1_FittedVtx_hitpix;
	Int_t diMuonC_m2_FittedVtx_hitpix;
	Int_t diMuonF_m1_FittedVtx_hitpix;
	Int_t diMuonF_m2_FittedVtx_hitpix;

	Int_t diMuonC_m1_FittedVtx_hitpix_l3inc;
	Int_t diMuonC_m2_FittedVtx_hitpix_l3inc;
	Int_t diMuonF_m1_FittedVtx_hitpix_l3inc;
	Int_t diMuonF_m2_FittedVtx_hitpix_l3inc;

	Float_t genA0_eta;
	Float_t genA0_phi;
	Float_t genA1_eta;
	Float_t genA1_phi;

	Float_t selMu0_phi;
	Float_t selMu1_phi;
	Float_t selMu2_phi;
	Float_t selMu3_phi;

	Float_t selMu0_eta;
	Float_t selMu1_eta;
	Float_t selMu2_eta;
	Float_t selMu3_eta;

	Float_t genA0_m;
	Float_t genA0_px;
	Float_t genA0_py;
	Float_t genA0_pz;

	Float_t genA1_m;
	Float_t genA1_px;
	Float_t genA1_py;
	Float_t genA1_pz;

	Float_t diMuonC_FittedVtx_m;
	Float_t diMuonC_FittedVtx_px;
	Float_t diMuonC_FittedVtx_py;
	Float_t diMuonC_FittedVtx_pz;
	Float_t diMuonC_FittedVtx_eta;
	Float_t diMuonC_FittedVtx_phi;
	Float_t diMuonC_FittedVtx_Lxy;
	Float_t diMuonC_FittedVtx_L;

	Float_t diMuonF_FittedVtx_m;
	Float_t diMuonF_FittedVtx_px;
	Float_t diMuonF_FittedVtx_py;
	Float_t diMuonF_FittedVtx_pz;
	Float_t diMuonF_FittedVtx_eta;
	Float_t diMuonF_FittedVtx_phi;
	Float_t diMuonF_FittedVtx_Lxy;
	Float_t diMuonF_FittedVtx_L;

	Float_t genA0Mu0_eta;
	Float_t genA1Mu0_eta;
	Float_t genA0Mu1_eta;
	Float_t genA1Mu1_eta;


	Float_t genA0Mu0_phi;
	Float_t genA1Mu0_phi;
	Float_t genA0Mu1_phi;
	Float_t genA1Mu1_phi;

	//Vertex information
	Float_t genA0_vx;
	Float_t genA0_vy;
	Float_t genA0_vz;

	Float_t genA1_vx;
	Float_t genA1_vy;
	Float_t genA1_vz;

	Float_t genA0Mu0_vx;
	Float_t genA0Mu1_vx;
	Float_t genA1Mu0_vx;
	Float_t genA1Mu1_vx;

	Float_t genA0Mu0_vy;
	Float_t genA0Mu1_vy;
	Float_t genA1Mu0_vy;
	Float_t genA1Mu1_vy;

	Float_t genA0Mu0_vz;
	Float_t genA0Mu1_vz;
	Float_t genA1Mu0_vz;
	Float_t genA1Mu1_vz;

	Float_t diMuonC_FittedVtx_vx;
	Float_t diMuonC_FittedVtx_vy;
	Float_t diMuonC_FittedVtx_vz;

	Float_t diMuonF_FittedVtx_vx;
	Float_t diMuonF_FittedVtx_vy;
	Float_t diMuonF_FittedVtx_vz;

	//PHR
	Int_t           numhit_mu1_muJetC[100];
	Int_t           numhit_mu2_muJetC[100];
	Int_t           numhit_mu1_muJetF[100];
	Int_t           numhit_mu2_muJetF[100];

	Float_t         pixelhit_mu1_muJetC_posx[10][100];
	Float_t         pixelhit_mu1_muJetC_posy[10][100];
	Float_t         pixelhit_mu1_muJetC_errposx[10][100];
	Float_t         pixelhit_mu1_muJetC_errposy[10][100];
	Float_t         pixelhit_mu2_muJetC_posx[10][100];
	Float_t         pixelhit_mu2_muJetC_posy[10][100];
	Float_t         pixelhit_mu2_muJetC_errposx[10][100];
	Float_t         pixelhit_mu2_muJetC_errposy[10][100];
	Float_t         pixelhit_mu1_muJetF_posx[10][100];
	Float_t         pixelhit_mu1_muJetF_posy[10][100];
	Float_t         pixelhit_mu1_muJetF_errposx[10][100];
	Float_t         pixelhit_mu1_muJetF_errposy[10][100];
	Float_t         pixelhit_mu2_muJetF_posx[10][100];
	Float_t         pixelhit_mu2_muJetF_posy[10][100];
	Float_t         pixelhit_mu2_muJetF_errposx[10][100];
	Float_t         pixelhit_mu2_muJetF_errposy[10][100];

	Int_t     innerlayers_mu1_muJetC;
	Int_t     innerlayers_mu2_muJetC;
	Int_t     innerlayers_mu1_muJetF;
	Int_t     innerlayers_mu2_muJetF;

	Int_t           compdet_mu1_muJetC[10];
	Int_t           compdet_mu2_muJetC[10];
	Int_t           compdet_mu1_muJetF[10];
	Int_t           compdet_mu2_muJetF[10];


	Float_t         mj1m0posx[10][10];
	Float_t         mj1m0posy[10][10];
	Float_t         mj1m0posx_err[10][10];
	Float_t         mj1m0posy_err[10][10];
	Float_t         mj1m1posx[10][10];
	Float_t         mj1m1posy[10][10];
	Float_t         mj1m1posx_err[10][10];
	Float_t         mj1m1posy_err[10][10];
	Float_t         mj2m0posx[10][10];
	Float_t         mj2m0posy[10][10];
	Float_t         mj2m0posx_err[10][10];
	Float_t         mj2m0posy_err[10][10];
	Float_t         mj2m1posx[10][10];
	Float_t         mj2m1posy[10][10];
	Float_t         mj2m1posx_err[10][10];
	Float_t         mj2m1posy_err[10][10];

	//============= Counters ===========================//


	Int_t ev_all = 0;
	Int_t ev_isVtxOK = 0;
	Int_t ev_is2MuJets = 0;
	Int_t ev_is2DiMuons = 0;
	Int_t ev_is2DiMuonsFittedVtxOK = 0;
	Int_t ev_isPixelHitOK = 0;
	Int_t ev_is2DiMuonsDzOK_FittedVtx = 0;
	Int_t ev_is2DiMuonsMassOK_FittedVtx = 0;
	Int_t ev_is2DiMuonsIsoTkOK_FittedVtx = 0;
	Int_t ev_isDiMuonHLTFired = 0;

	Int_t c1genm = 0;
	Int_t c2genm = 0;
	Int_t c3genm = 0;
	Int_t c4genm = 0;

	Int_t c1recm = 0;
	Int_t c2recm = 0;
	Int_t c3recm = 0;
	Int_t c4recm = 0;

	Int_t uncuttableFakeCounter = 0;
	//}}}

	TObjArray *fileElements=chain->GetListOfFiles();
	TIter next(fileElements);
	TChainElement *chEl=0;

	while ((chEl=(TChainElement*)next())) {
		if (verbose) std::cout << "running on file " << chEl->GetTitle() << std::endl;
		TFile* myfile = new TFile(chEl->GetTitle());
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
		t->SetBranchAddress("event", &event);
		t->SetBranchAddress("run",   &run);
		t->SetBranchAddress("lumi",  &lumi);

		// GEN Level Selectors
		t->SetBranchAddress("is4GenMu",    &is4GenMu);
		t->SetBranchAddress("is1GenMu17",  &is1GenMu17);
		t->SetBranchAddress("is2GenMu8",   &is2GenMu8);
		t->SetBranchAddress("is3GenMu8",   &is3GenMu8);
		t->SetBranchAddress("is4GenMu8",   &is4GenMu8);

		// RECO Level Selectors
		t->SetBranchAddress("is1SelMu17",                     &is1SelMu17);
		t->SetBranchAddress("is2SelMu8",                      &is2SelMu8);
		t->SetBranchAddress("is3SelMu8",                      &is3SelMu8);
		t->SetBranchAddress("is4SelMu8",                      &is4SelMu8);

		t->SetBranchAddress("is2MuJets",                      &is2MuJets);
		t->SetBranchAddress("is2DiMuons",                     &is2DiMuons);
		t->SetBranchAddress("is2DiMuonsFittedVtxOK",          &is2DiMuonsFittedVtxOK);
		t->SetBranchAddress("diMuons_dz_FittedVtx",       &diMuons_dz_FittedVtx);
		t->SetBranchAddress("isDiMuonHLTFired",               &isDiMuonHLTFired);
		t->SetBranchAddress("is2DiMuonsMassOK_FittedVtx",     &is2DiMuonsMassOK_FittedVtx);
		t->SetBranchAddress("diMuonF_IsoTk_FittedVtx",    &diMuonF_IsoTk_FittedVtx);
		t->SetBranchAddress("diMuonC_IsoTk_FittedVtx",    &diMuonC_IsoTk_FittedVtx);
		t->SetBranchAddress("isVertexOK",                     &isVertexOK);
		t->SetBranchAddress("isDiMuonHLTFired",              &isDiMuonHLTFired);

		t->SetBranchAddress("genA0_Lxy", &genA0_Lxy);
		t->SetBranchAddress("genA0_Lz",  &genA0_Lz);
		t->SetBranchAddress("genA1_Lxy", &genA1_Lxy);
		t->SetBranchAddress("genA1_Lz",  &genA1_Lz);

		t->SetBranchAddress("diMuonC_m1_FittedVtx_hitpix", &diMuonC_m1_FittedVtx_hitpix);
		t->SetBranchAddress("diMuonC_m2_FittedVtx_hitpix", &diMuonC_m2_FittedVtx_hitpix);
		t->SetBranchAddress("diMuonF_m1_FittedVtx_hitpix", &diMuonF_m1_FittedVtx_hitpix);
		t->SetBranchAddress("diMuonF_m2_FittedVtx_hitpix", &diMuonF_m2_FittedVtx_hitpix);

		t->SetBranchAddress("diMuonC_m1_FittedVtx_hitpix_l3inc", &diMuonC_m1_FittedVtx_hitpix_l3inc);
		t->SetBranchAddress("diMuonC_m2_FittedVtx_hitpix_l3inc", &diMuonC_m2_FittedVtx_hitpix_l3inc);
		t->SetBranchAddress("diMuonF_m1_FittedVtx_hitpix_l3inc", &diMuonF_m1_FittedVtx_hitpix_l3inc);
		t->SetBranchAddress("diMuonF_m2_FittedVtx_hitpix_l3inc", &diMuonF_m2_FittedVtx_hitpix_l3inc);

		t->SetBranchAddress("genA1_phi",&genA1_phi);
		t->SetBranchAddress("genA1_eta",&genA1_eta);

		t->SetBranchAddress("genA0_phi",&genA0_phi);
		t->SetBranchAddress("genA0_eta",&genA0_eta);

		t->SetBranchAddress("selMu0_phi",&selMu0_phi);
		t->SetBranchAddress("selMu1_phi",&selMu1_phi);
		t->SetBranchAddress("selMu2_phi",&selMu2_phi);
		t->SetBranchAddress("selMu3_phi",&selMu3_phi);

		t->SetBranchAddress("selMu0_eta",&selMu0_eta);
		t->SetBranchAddress("selMu1_eta",&selMu1_eta);
		t->SetBranchAddress("selMu2_eta",&selMu2_eta);
		t->SetBranchAddress("selMu3_eta",&selMu3_eta);

		t->SetBranchAddress("genA0_m" , &genA0_m);
		t->SetBranchAddress("genA0_px", &genA0_px);
		t->SetBranchAddress("genA0_py", &genA0_py);
		t->SetBranchAddress("genA0_pz", &genA0_pz);

		t->SetBranchAddress("genA1_m" , &genA1_m);
		t->SetBranchAddress("genA1_px", &genA1_px);
		t->SetBranchAddress("genA1_py", &genA1_py);
		t->SetBranchAddress("genA1_pz", &genA1_pz);

		t->SetBranchAddress("diMuonF_FittedVtx_m", &diMuonF_FittedVtx_m);
		t->SetBranchAddress("diMuonF_FittedVtx_px", &diMuonF_FittedVtx_px);
		t->SetBranchAddress("diMuonF_FittedVtx_py", &diMuonF_FittedVtx_py);
		t->SetBranchAddress("diMuonF_FittedVtx_pz", &diMuonF_FittedVtx_pz);
		t->SetBranchAddress("diMuonF_FittedVtx_eta",&diMuonF_FittedVtx_eta);
		t->SetBranchAddress("diMuonF_FittedVtx_phi",&diMuonF_FittedVtx_phi);
		t->SetBranchAddress("diMuonF_FittedVtx_Lxy",&diMuonF_FittedVtx_Lxy);
		t->SetBranchAddress("diMuonF_FittedVtx_L",&diMuonF_FittedVtx_L);

		t->SetBranchAddress("diMuonC_FittedVtx_m", &diMuonC_FittedVtx_m);
		t->SetBranchAddress("diMuonC_FittedVtx_px", &diMuonC_FittedVtx_px);
		t->SetBranchAddress("diMuonC_FittedVtx_py", &diMuonC_FittedVtx_py);
		t->SetBranchAddress("diMuonC_FittedVtx_pz", &diMuonC_FittedVtx_pz);
		t->SetBranchAddress("diMuonC_FittedVtx_eta",&diMuonC_FittedVtx_eta);
		t->SetBranchAddress("diMuonC_FittedVtx_phi",&diMuonC_FittedVtx_phi);
		t->SetBranchAddress("diMuonC_FittedVtx_Lxy",&diMuonC_FittedVtx_Lxy);
		t->SetBranchAddress("diMuonC_FittedVtx_L",&diMuonC_FittedVtx_L);

		t->SetBranchAddress("genA0Mu0_eta",&genA0Mu0_eta);
		t->SetBranchAddress("genA1Mu0_eta",&genA1Mu0_eta);
		t->SetBranchAddress("genA0Mu1_eta",&genA0Mu1_eta);
		t->SetBranchAddress("genA1Mu1_eta",&genA1Mu1_eta);

		t->SetBranchAddress("genA0Mu0_phi",&genA0Mu0_phi);
		t->SetBranchAddress("genA1Mu0_phi",&genA1Mu0_phi);
		t->SetBranchAddress("genA0Mu1_phi",&genA0Mu1_phi);
		t->SetBranchAddress("genA1Mu1_phi",&genA1Mu1_phi);

		t->SetBranchAddress("genA0_vx", &genA0_vx); 
		t->SetBranchAddress("genA0_vy", &genA0_vy);
		t->SetBranchAddress("genA0_vz", &genA0_vz);

		t->SetBranchAddress("genA1_vx", &genA1_vx);
		t->SetBranchAddress("genA1_vy", &genA1_vy);
		t->SetBranchAddress("genA1_vz", &genA1_vz);

		t->SetBranchAddress("genA0Mu0_vx", &genA0Mu0_vx);
		t->SetBranchAddress("genA0Mu1_vx", &genA0Mu1_vx);
		t->SetBranchAddress("genA1Mu0_vx", &genA1Mu0_vx);
		t->SetBranchAddress("genA1Mu1_vx", &genA1Mu1_vx);

		t->SetBranchAddress("genA0Mu0_vy", &genA0Mu0_vy);
		t->SetBranchAddress("genA0Mu1_vy", &genA0Mu1_vy);
		t->SetBranchAddress("genA1Mu0_vy", &genA1Mu0_vy);
		t->SetBranchAddress("genA1Mu1_vy", &genA1Mu1_vy);

		t->SetBranchAddress("genA0Mu0_vz", &genA0Mu0_vz);
		t->SetBranchAddress("genA0Mu1_vz", &genA0Mu1_vz);
		t->SetBranchAddress("genA1Mu0_vz", &genA1Mu0_vz);
		t->SetBranchAddress("genA1Mu1_vz", &genA1Mu1_vz);

		t->SetBranchAddress("diMuonC_FittedVtx_vx", &diMuonC_FittedVtx_vx);
		t->SetBranchAddress("diMuonC_FittedVtx_vy", &diMuonC_FittedVtx_vy);
		t->SetBranchAddress("diMuonC_FittedVtx_vz", &diMuonC_FittedVtx_vz);

		t->SetBranchAddress("diMuonF_FittedVtx_vx", &diMuonF_FittedVtx_vx);
		t->SetBranchAddress("diMuonF_FittedVtx_vy", &diMuonF_FittedVtx_vy);
		t->SetBranchAddress("diMuonF_FittedVtx_vz", &diMuonF_FittedVtx_vz);

		//PHR
		t->SetBranchAddress("numhit_mu1_muJetC", &numhit_mu1_muJetC);
		t->SetBranchAddress("numhit_mu2_muJetC", &numhit_mu2_muJetC);
		t->SetBranchAddress("numhit_mu1_muJetF", &numhit_mu1_muJetF);
		t->SetBranchAddress("numhit_mu2_muJetF", &numhit_mu2_muJetF);

		t->SetBranchAddress("pixelhit_mu1_muJetC_posx",  &pixelhit_mu1_muJetC_posx);
		t->SetBranchAddress("pixelhit_mu1_muJetC_posy",  &pixelhit_mu1_muJetC_posy);
		t->SetBranchAddress("pixelhit_mu1_muJetC_errposx",  &pixelhit_mu1_muJetC_errposx);
		t->SetBranchAddress("pixelhit_mu1_muJetC_errposy",  &pixelhit_mu1_muJetC_errposy);
		t->SetBranchAddress("pixelhit_mu2_muJetC_posx", &pixelhit_mu2_muJetC_posx);
		t->SetBranchAddress("pixelhit_mu2_muJetC_posy",  &pixelhit_mu2_muJetC_posy);
		t->SetBranchAddress("pixelhit_mu2_muJetC_errposx", &pixelhit_mu2_muJetC_errposx);
		t->SetBranchAddress("pixelhit_mu2_muJetC_errposy",  &pixelhit_mu2_muJetC_errposy);
		t->SetBranchAddress("pixelhit_mu1_muJetF_posx",  &pixelhit_mu1_muJetF_posx);
		t->SetBranchAddress("pixelhit_mu1_muJetF_posy", &pixelhit_mu1_muJetF_posy);
		t->SetBranchAddress("pixelhit_mu1_muJetF_errposx",  &pixelhit_mu1_muJetF_errposx);
		t->SetBranchAddress("pixelhit_mu1_muJetF_errposy",  &pixelhit_mu1_muJetF_errposy);
		t->SetBranchAddress("pixelhit_mu2_muJetF_posx",  &pixelhit_mu2_muJetF_posx);
		t->SetBranchAddress("pixelhit_mu2_muJetF_posy",  &pixelhit_mu2_muJetF_posy);
		t->SetBranchAddress("pixelhit_mu2_muJetF_errposx",  &pixelhit_mu2_muJetF_errposx);
		t->SetBranchAddress("pixelhit_mu2_muJetF_errposy",  &pixelhit_mu2_muJetF_errposy);

		t->SetBranchAddress("mj1m0posx", &mj1m0posx);
		t->SetBranchAddress("mj1m0posy", &mj1m0posy);
		t->SetBranchAddress("mj1m0posx_err", &mj1m0posx_err);
		t->SetBranchAddress("mj1m0posy_err", &mj1m0posy_err);
		t->SetBranchAddress("mj1m1posx", &mj1m1posx);
		t->SetBranchAddress("mj1m1posy", &mj1m1posy);
		t->SetBranchAddress("mj1m1posx_err", &mj1m1posx_err);
		t->SetBranchAddress("mj1m1posy_err", &mj1m1posy_err);
		t->SetBranchAddress("mj2m0posx", &mj2m0posx);
		t->SetBranchAddress("mj2m0posy", &mj2m0posy);
		t->SetBranchAddress("mj2m0posx_err", &mj2m0posx_err);
		t->SetBranchAddress("mj2m0posy_err", &mj2m0posy_err);
		t->SetBranchAddress("mj2m1posx", &mj2m1posx);
		t->SetBranchAddress("mj2m1posy", &mj2m1posy);
		t->SetBranchAddress("mj2m1posx_err", &mj2m1posx_err);
		t->SetBranchAddress("mj2m1posy_err", &mj2m1posy_err);
		t->SetBranchAddress("innerlayers_mu1_muJetC", &innerlayers_mu1_muJetC);
		t->SetBranchAddress("innerlayers_mu2_muJetC", &innerlayers_mu2_muJetC);
		t->SetBranchAddress("innerlayers_mu1_muJetF", &innerlayers_mu1_muJetF);
		t->SetBranchAddress("innerlayers_mu2_muJetF", &innerlayers_mu2_muJetF);

		t->SetBranchAddress("compdet_mu1_muJetC", &compdet_mu1_muJetC);
		t->SetBranchAddress("compdet_mu2_muJetC", &compdet_mu2_muJetC);
		t->SetBranchAddress("compdet_mu1_muJetF", &compdet_mu1_muJetF);
		t->SetBranchAddress("compdet_mu2_muJetF", &compdet_mu2_muJetF);

		//}}}

		for(int k=0;k<t->GetEntries();k++){
			t->GetEntry(k);

			//PHR counters
			bool count_recovermuJetC        = false;
			bool count_recovermuJetF        = false;
			bool count_recovermuJetCANDF    = false;
			bool count_recovermuJetTotal    = false;

			ev_all++;

			if(is1GenMu17) c1genm++;
			if(is2GenMu8)  c2genm++;
			if(is3GenMu8)  c3genm++;
			if(is4GenMu8)  c4genm++;

			if(is1SelMu17) c1recm++;
			if(is2SelMu8)  c2recm++;
			if(is3SelMu8)  c3recm++;
			if(is4SelMu8)  c4recm++;

			int triggerFlag_std = 0;
			int triggerFlag_lxy = 0;
			int fakeFlag = 0;
			int realFlag = 0;
			int fakeDimuon1 = 0;
			int fakeDimuon2 = 0;

			int brokenCounter = 0;
			int fakeCounter_dimuon1 = 0;
			int fakeCounter_dimuon2 = 0;
			int fakeCounter_both = 0;

			int dimuonCRecovered = 0;
			int dimuonFRecovered = 0;
			int BothDimuonsRecovered = 0;

			//  =============  Reco information ====================//

			//Determine which events are recovered
			if(is4SelMu8 == false) continue;
			if(isVertexOK== false) continue;
			if(is2MuJets== false) continue;
			if(is2DiMuons== false) continue;
			if(is2DiMuonsFittedVtxOK){

				//======================== PHR starts at this point  ==========================================================//
				if( (diMuonC_m1_FittedVtx_hitpix_l3inc!=1&&diMuonC_m2_FittedVtx_hitpix_l3inc!=1)||(diMuonF_m1_FittedVtx_hitpix_l3inc!=1&&diMuonF_m2_FittedVtx_hitpix_l3inc!=1)){

					Float_t hitposx[100]={10000};
					Float_t hitposy[100]={10000};

					Float_t muon1posx=10000;
					Float_t muon1posy=10000;


					Float_t muon2posx=10000;
					Float_t muon2posy=10000;

					Float_t radius_rec=0.05;

					Int_t passingC=0;
					Int_t passingF=0;

					Bool_t recovery_muJetC=false;
					Bool_t recovery_muJetF=false;

					TH2F *pos_muons[5];
					TH2F *pos_hits[5];


					//=============== Recovering for event which fail muJetC  ==================//
					if((diMuonC_m1_FittedVtx_hitpix_l3inc!=1&&diMuonC_m2_FittedVtx_hitpix_l3inc!=1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc==1||diMuonF_m2_FittedVtx_hitpix_l3inc==1)){
						if(innerlayers_mu1_muJetC>0 && innerlayers_mu2_muJetC>0){

							for(int k=0;k<min(innerlayers_mu1_muJetC,innerlayers_mu2_muJetC);k++){
								for(int h=0;h<min(compdet_mu1_muJetC[k],compdet_mu2_muJetC[k]);h++){
									muon1posx = mj1m0posx[k][h];
									muon1posy = mj1m0posy[k][h];
									muon2posx = mj1m1posx[k][h];
									muon2posy = mj1m1posy[k][h];

									// sprintf(nameh,"pos_muons_ev%d_layer%d_det%d",i,k,h);
									// sprintf(nameh2,"pos_hits_ev%d_layer%d_det%d",i,k,h);
									// sprintf(namec,"position_ev%d_layer%d_det%d.pdf",i,k,d);

									// xmin = mj1m0posx[k][0]-0.3;
									// xmax = mj1m0posx[k][0]+0.3;
									// ymin = mj1m0posy[k][0]-0.3;
									// ymax = mj1m0posy[k][0]+0.3;

									// pos_muons[k] = new TH2F(nameh,"",100,xmin,xmax,100,ymin,ymax);
									// pos_muons[k]->Fill(mj1m0posx[k][0],mj1m0posy[k][0]);
									// pos_muons[k]->Fill(mj1m1posx[k][0],mj1m1posy[k][0]);

									// pos_hits[k] = new TH2F(nameh2,"",100,xmin,xmax,100,ymin,ymax);

									for(int j=0;j<numhit_mu1_muJetC[k];j++){
										hitposx[j] = pixelhit_mu1_muJetC_posx[k][j];
										hitposy[j] = pixelhit_mu1_muJetC_posy[k][j];
										//              pos_hits[k]->Fill(hitposx[j],hitposy[j]);
									}

									passingC += BikeChain(numhit_mu1_muJetC[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);

									// TCanvas *c = new TCanvas("c","c");
									// pos_muons[k]->SetFillColor(4);
									// pos_muons[k]->Draw("BOX");
									// pos_hits[k]->SetFillColor(2);
									// pos_hits[k]->Draw("BOXsame");
									// c->SaveAs(namec,"recreate");
								}
							}
						}
						if(passingC>0){ count_recovermuJetC = true;} //cout<<" Event recovered  "<<i<<endl;
					}

					//=============== Recovering for event which fail muJetF  ==================//
					if((diMuonC_m1_FittedVtx_hitpix_l3inc==1||diMuonC_m2_FittedVtx_hitpix_l3inc==1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc!=1&&diMuonF_m2_FittedVtx_hitpix_l3inc!=1)){
						if(innerlayers_mu1_muJetF>0 && innerlayers_mu2_muJetF>0){

							for(int k=0;k<min(innerlayers_mu1_muJetF,innerlayers_mu2_muJetF);k++){
								for(int h=0;h<min(compdet_mu1_muJetF[k],compdet_mu2_muJetF[k]);h++){
									muon1posx = mj2m0posx[k][h];
									muon1posy = mj2m0posy[k][h];
									muon2posx = mj2m1posx[k][h];
									muon2posy = mj2m1posy[k][h];

									for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposx[j] = pixelhit_mu1_muJetF_posx[k][j];
									for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposy[j] = pixelhit_mu1_muJetF_posy[k][j];

									passingF += BikeChain(numhit_mu1_muJetF[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
								}
							}
						}
						if(passingF>0) count_recovermuJetF = true;
					}

					//=============== Recovering for event which fail muJetF and muJetC  ==================//
					if((diMuonC_m1_FittedVtx_hitpix_l3inc!=1&&diMuonC_m2_FittedVtx_hitpix_l3inc!=1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc!=1&&diMuonF_m2_FittedVtx_hitpix_l3inc!=1)){

						if(innerlayers_mu1_muJetC>0 && innerlayers_mu2_muJetC>0){

							for(int k=0;k<min(innerlayers_mu1_muJetC,innerlayers_mu2_muJetC);k++){
								for(int h=0;h<min(compdet_mu1_muJetC[k],compdet_mu2_muJetC[k]);h++){
									muon1posx = mj1m0posx[k][h];
									muon1posy = mj1m0posy[k][h];
									muon2posx = mj1m1posx[k][h];
									muon2posy = mj1m1posy[k][h];

									for(int j=0;j<numhit_mu1_muJetC[k];j++) hitposx[j] = pixelhit_mu1_muJetC_posx[k][j];
									for(int j=0;j<numhit_mu1_muJetC[k];j++) hitposy[j] = pixelhit_mu1_muJetC_posy[k][j];

									passingC += BikeChain(numhit_mu1_muJetC[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
								}
							}
						}
						if(innerlayers_mu1_muJetF>0 && innerlayers_mu2_muJetF>0){
							for(int k=0;k<min(innerlayers_mu1_muJetF,innerlayers_mu2_muJetF);k++){
								for(int h=0;h<min(compdet_mu1_muJetF[k],compdet_mu2_muJetF[k]);h++){
									muon1posx = mj2m0posx[k][h];
									muon1posy = mj2m0posy[k][h];
									muon2posx = mj2m1posx[k][h];
									muon2posy = mj2m1posy[k][h];

									for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposx[j] = pixelhit_mu1_muJetF_posx[k][j];
									for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposy[j] = pixelhit_mu1_muJetF_posy[k][j];

									passingF += BikeChain(numhit_mu1_muJetF[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
								}
							}
						}
						if(passingC>0&&passingF>0) count_recovermuJetCANDF = true;
					}
				}

				//--------------------
				//Match Dimuons RECO-GEN
				int matchResult = MatchRECOtoGENdimuons(diMuonC_FittedVtx_eta, diMuonC_FittedVtx_phi, diMuonF_FittedVtx_eta, diMuonF_FittedVtx_phi, genA0_eta, genA0_phi, genA1_eta, genA0_phi);
				//if matchResult == 0; diMuonC -> A0, diMuonF -> A1 
				//if matchResult == 1; diMuonC -> A1, diMuonF -> A0
				//--------------------


				if(count_recovermuJetC || count_recovermuJetCANDF){ 

					RecoveredDimuonC_Reco_Lxy->Fill(diMuonC_FittedVtx_Lxy);
					RecoveredDimuonC_Reco_Eta->Fill(diMuonC_FittedVtx_eta);
					RecoveredDimuonC_Reco_Phi->Fill(diMuonC_FittedVtx_phi);
					RecoveredDimuonC_Reco_pT->Fill(sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py)); 
					RecoveredDimuonC_Reco_pT_vs_Lxy->Fill(diMuonC_FittedVtx_Lxy, sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
					RecoveredDimuonC_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonC_FittedVtx_phi,diMuonF_FittedVtx_phi)); 
					RecoveredDimuonC_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
					RecoveredDimuonC_Reco_Lxy_vs_Mass->Fill(diMuonC_FittedVtx_m, diMuonC_FittedVtx_Lxy);

					if(matchResult == 0){
						RecoveredDimuonC_Gen_Lxy->Fill(genA0_Lxy);
						RecoveredDimuonC_Gen_Eta->Fill(genA0_eta);
						RecoveredDimuonC_Gen_Phi->Fill(genA0_phi);
						RecoveredDimuonC_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						RecoveredDimuonC_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						RecoveredDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
						RecoveredDimuonC_Gen_MassPlot->Fill(genA0_m,genA1_m);
					}else{
						RecoveredDimuonC_Gen_Lxy->Fill(genA1_Lxy);
						RecoveredDimuonC_Gen_Eta->Fill(genA1_eta);
						RecoveredDimuonC_Gen_Phi->Fill(genA1_phi);
						RecoveredDimuonC_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						RecoveredDimuonC_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						RecoveredDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
						RecoveredDimuonC_Gen_MassPlot->Fill(genA1_m,genA0_m);
					}

				}
				if(diMuonC_m1_FittedVtx_hitpix_l3inc==1||diMuonC_m2_FittedVtx_hitpix_l3inc==1){ 

					PassWithNoPHRDimuonC_Reco_Lxy->Fill(diMuonC_FittedVtx_Lxy);
					PassWithNoPHRDimuonC_Reco_Eta->Fill(diMuonC_FittedVtx_eta);
					PassWithNoPHRDimuonC_Reco_Phi->Fill(diMuonC_FittedVtx_phi);
					PassWithNoPHRDimuonC_Reco_pT->Fill(sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
					PassWithNoPHRDimuonC_Reco_pT_vs_Lxy->Fill(diMuonC_FittedVtx_Lxy, sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
					PassWithNoPHRDimuonC_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonC_FittedVtx_phi,diMuonF_FittedVtx_phi));
					PassWithNoPHRDimuonC_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
					PassWithNoPHRDimuonC_Reco_Lxy_vs_Mass->Fill(diMuonC_FittedVtx_m, diMuonC_FittedVtx_Lxy);


					if(matchResult == 0){
						PassWithNoPHRDimuonC_Gen_Lxy->Fill(genA0_Lxy);
						PassWithNoPHRDimuonC_Gen_Eta->Fill(genA0_eta);
						PassWithNoPHRDimuonC_Gen_Phi->Fill(genA0_phi);
						PassWithNoPHRDimuonC_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						PassWithNoPHRDimuonC_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
						PassWithNoPHRDimuonC_Gen_MassPlot->Fill(genA0_m,genA1_m);

					}else{
						PassWithNoPHRDimuonC_Gen_Lxy->Fill(genA1_Lxy);
						PassWithNoPHRDimuonC_Gen_Eta->Fill(genA1_eta);
						PassWithNoPHRDimuonC_Gen_Phi->Fill(genA1_phi);
						PassWithNoPHRDimuonC_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						PassWithNoPHRDimuonC_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
						PassWithNoPHRDimuonC_Gen_MassPlot->Fill(genA1_m,genA0_m);

					}
				}
				if(count_recovermuJetF || count_recovermuJetCANDF){ 
					RecoveredDimuonF_Reco_Lxy->Fill(diMuonF_FittedVtx_Lxy);
					RecoveredDimuonF_Reco_Eta->Fill(diMuonF_FittedVtx_eta);
					RecoveredDimuonF_Reco_Phi->Fill(diMuonF_FittedVtx_phi);
					RecoveredDimuonF_Reco_pT->Fill(sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
					RecoveredDimuonF_Reco_pT_vs_Lxy->Fill(diMuonF_FittedVtx_Lxy, sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
					RecoveredDimuonF_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonF_FittedVtx_phi,diMuonC_FittedVtx_phi));
					RecoveredDimuonF_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
					RecoveredDimuonF_Reco_Lxy_vs_Mass->Fill(diMuonF_FittedVtx_m, diMuonF_FittedVtx_Lxy);


					if(matchResult == 0){
						RecoveredDimuonF_Gen_Lxy->Fill(genA0_Lxy);
						RecoveredDimuonF_Gen_Eta->Fill(genA0_eta);
						RecoveredDimuonF_Gen_Phi->Fill(genA0_phi);
						RecoveredDimuonF_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						RecoveredDimuonF_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						RecoveredDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
						RecoveredDimuonF_Gen_MassPlot->Fill(genA0_m,genA1_m);

					}else{
						RecoveredDimuonF_Gen_Lxy->Fill(genA1_Lxy);
						RecoveredDimuonF_Gen_Eta->Fill(genA1_eta);
						RecoveredDimuonF_Gen_Phi->Fill(genA1_phi);
						RecoveredDimuonF_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						RecoveredDimuonF_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						RecoveredDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
						RecoveredDimuonF_Gen_MassPlot->Fill(genA1_m,genA0_m);

					}

				}
				if(diMuonF_m1_FittedVtx_hitpix_l3inc==1||diMuonF_m2_FittedVtx_hitpix_l3inc==1){ 
					PassWithNoPHRDimuonF_Reco_Lxy->Fill(diMuonF_FittedVtx_Lxy);
					PassWithNoPHRDimuonF_Reco_Eta->Fill(diMuonF_FittedVtx_eta);
					PassWithNoPHRDimuonF_Reco_Phi->Fill(diMuonF_FittedVtx_phi);
					PassWithNoPHRDimuonF_Reco_pT->Fill(sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
					PassWithNoPHRDimuonF_Reco_pT_vs_Lxy->Fill(diMuonF_FittedVtx_Lxy, sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
					PassWithNoPHRDimuonF_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonF_FittedVtx_phi,diMuonC_FittedVtx_phi));
					PassWithNoPHRDimuonF_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
					PassWithNoPHRDimuonF_Reco_Lxy_vs_Mass->Fill(diMuonF_FittedVtx_m, diMuonF_FittedVtx_Lxy);

					if(matchResult == 0){
						PassWithNoPHRDimuonF_Gen_Lxy->Fill(genA0_Lxy);
						PassWithNoPHRDimuonF_Gen_Eta->Fill(genA0_eta);
						PassWithNoPHRDimuonF_Gen_Phi->Fill(genA0_phi);
						PassWithNoPHRDimuonF_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						PassWithNoPHRDimuonF_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
						PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
						PassWithNoPHRDimuonF_Gen_MassPlot->Fill(genA0_m,genA1_m);

					}else{
						PassWithNoPHRDimuonF_Gen_Lxy->Fill(genA1_Lxy);
						PassWithNoPHRDimuonF_Gen_Eta->Fill(genA1_eta);
						PassWithNoPHRDimuonF_Gen_Phi->Fill(genA1_phi);
						PassWithNoPHRDimuonF_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						PassWithNoPHRDimuonF_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
						PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
						PassWithNoPHRDimuonF_Gen_MassPlot->Fill(genA1_m,genA0_m);

					}
				}
			}
		} // closing for loop
		myfile->Close();
	} // closing while loop

	//Fill ratio reco/gen vectors to be plotted  
	//Prepare plots and plot variables.  Also Fill final information printout vectors
}


void makePlotsPretty(){
cout << "Making plots pretty" << endl;
	RecoveredDimuonC_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]"); 
	RecoveredDimuonC_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	RecoveredDimuonC_Gen_Eta->GetXaxis()->SetTitle("#eta"); 
	RecoveredDimuonC_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	RecoveredDimuonC_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]"); 
	RecoveredDimuonC_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad"); 

	RecoveredDimuonC_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]"); 
	RecoveredDimuonC_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]"); 

	RecoveredDimuonC_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]"); 
	RecoveredDimuonC_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonC_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]"); 
	RecoveredDimuonC_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	RecoveredDimuonC_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	RecoveredDimuonC_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	RecoveredDimuonF_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	RecoveredDimuonF_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	RecoveredDimuonF_Gen_Eta->GetXaxis()->SetTitle("#eta");
	RecoveredDimuonF_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	RecoveredDimuonF_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	RecoveredDimuonF_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonF_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	RecoveredDimuonF_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	RecoveredDimuonF_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	RecoveredDimuonF_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonF_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	RecoveredDimuonF_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	RecoveredDimuonF_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	RecoveredDimuonF_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	PassWithNoPHRDimuonF_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	PassWithNoPHRDimuonF_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	PassWithNoPHRDimuonF_Gen_Eta->GetXaxis()->SetTitle("#eta");
	PassWithNoPHRDimuonF_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	PassWithNoPHRDimuonF_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	PassWithNoPHRDimuonF_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonF_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonF_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	PassWithNoPHRDimuonF_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonF_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonF_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	PassWithNoPHRDimuonF_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	PassWithNoPHRDimuonF_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	PassWithNoPHRDimuonC_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	PassWithNoPHRDimuonC_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	PassWithNoPHRDimuonC_Gen_Eta->GetXaxis()->SetTitle("#eta");
	PassWithNoPHRDimuonC_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	PassWithNoPHRDimuonC_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	PassWithNoPHRDimuonC_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonC_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonC_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	PassWithNoPHRDimuonC_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonC_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonC_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	PassWithNoPHRDimuonC_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	PassWithNoPHRDimuonC_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	RecoveredDimuonC_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	RecoveredDimuonC_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	RecoveredDimuonC_Reco_Eta->GetXaxis()->SetTitle("#eta");
	RecoveredDimuonC_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	RecoveredDimuonC_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	RecoveredDimuonC_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonC_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	RecoveredDimuonC_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	RecoveredDimuonC_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	RecoveredDimuonC_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonC_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	RecoveredDimuonC_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	RecoveredDimuonC_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	RecoveredDimuonC_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	RecoveredDimuonF_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	RecoveredDimuonF_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	RecoveredDimuonF_Reco_Eta->GetXaxis()->SetTitle("#eta");
	RecoveredDimuonF_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	RecoveredDimuonF_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	RecoveredDimuonF_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonF_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	RecoveredDimuonF_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	RecoveredDimuonF_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	RecoveredDimuonF_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	RecoveredDimuonF_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	RecoveredDimuonF_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	RecoveredDimuonF_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	RecoveredDimuonF_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	PassWithNoPHRDimuonF_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	PassWithNoPHRDimuonF_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	PassWithNoPHRDimuonF_Reco_Eta->GetXaxis()->SetTitle("#eta");
	PassWithNoPHRDimuonF_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	PassWithNoPHRDimuonF_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	PassWithNoPHRDimuonF_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonF_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonF_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	PassWithNoPHRDimuonF_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	PassWithNoPHRDimuonF_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonF_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonF_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	PassWithNoPHRDimuonF_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	PassWithNoPHRDimuonF_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	PassWithNoPHRDimuonC_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	PassWithNoPHRDimuonC_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	PassWithNoPHRDimuonC_Reco_Eta->GetXaxis()->SetTitle("#eta");
	PassWithNoPHRDimuonC_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	PassWithNoPHRDimuonC_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	PassWithNoPHRDimuonC_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonC_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonC_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	PassWithNoPHRDimuonC_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	PassWithNoPHRDimuonC_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	PassWithNoPHRDimuonC_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	PassWithNoPHRDimuonC_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	PassWithNoPHRDimuonC_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	PassWithNoPHRDimuonC_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	RecoveredDimuonC_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]"); 
	RecoveredDimuonC_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]"); 

	RecoveredDimuonF_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
	RecoveredDimuonF_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

	PassWithNoPHRDimuonC_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
	PassWithNoPHRDimuonC_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

	PassWithNoPHRDimuonF_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
	PassWithNoPHRDimuonF_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

	MassPlot_NoCuts->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	MassPlot_NoCuts->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	MassPlot_GenFidCut->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	MassPlot_GenFidCut->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

}

void FakeInvestigation()
{
	std::vector< std::vector<string> > DarkSUSY_mH_125_mGammaD_v;
	cout << "Vector Created" << endl;
	readTextFileWithSamples("/fdata/hepx/store/user/bmichlin/All_0250_InclHighCT.txt", DarkSUSY_mH_125_mGammaD_v);
	cout << "Samples read" << endl;
	for(auto v: DarkSUSY_mH_125_mGammaD_v) efficiency_hitrecovery(v);
	cout << "For Loop completes" << endl;

	makePlotsPretty();
	BAM->Write();

}     
