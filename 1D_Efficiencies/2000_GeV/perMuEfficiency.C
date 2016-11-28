#include <algorithm>    // std::max
#include "TMath.h"
#include <math.h>
#include "TEfficiency.h"

///----Global Variables ----///
TFile *BAM = new TFile("PerMuEfficiency_Plots.root","RECREATE");

TH1F *num_pt_barrel = new TH1F("num_pt_barrel", "num_pt_barrel", 160, 0, 160);
TH1F *den_pt_barrel = new TH1F("den_pt_barrel", "den_pt_barrel", 160, 0, 160);

TH1F *num_pt_endcap = new TH1F("num_pt_endcap", "num_pt_endcap", 160, 0, 160);
TH1F *den_pt_endcap = new TH1F("den_pt_endcap", "den_pt_endcap", 160, 0, 160);

TH1F *num_eta_barrel = new TH1F("num_eta_barrel", "num_eta_barrel", 50, -2.5, 2.5);
TH1F *den_eta_barrel = new TH1F("den_eta_barrel", "den_eta_barrel", 50, -2.5, 2.5);

TH1F *num_eta_endcap = new TH1F("num_eta_endcap", "num_eta_endcap", 50, -2.5, 2.5);
TH1F *den_eta_endcap = new TH1F("den_eta_endcap", "den_eta_endcap", 50, -2.5, 2.5);

Float_t bins[] = {0, 2, 4, 6, 8, 10, 12, 16, 18, 20, 25, 30, 35, 40, 45, 50, 60, 80};
Int_t binnum = sizeof(bins)/sizeof(Float_t) - 1;

TH1F *num_lxy_barrel = new TH1F("num_lxy_barrel", "num_lxy_barrel", binnum, bins);
TH1F *den_lxy_barrel = new TH1F("den_lxy_barrel", "den_lxy_barrel", binnum, bins);

TH1F *num_lz_barrel = new TH1F("num_lz_barrel", "num_lz_barrel",    binnum, bins);
TH1F *den_lz_barrel = new TH1F("den_lz_barrel", "den_lz_barrel",    binnum, bins);

TH1F *num_lxy_endcap = new TH1F("num_lxy_endcap", "num_lxy_endcap", binnum, bins);
TH1F *den_lxy_endcap = new TH1F("den_lxy_endcap", "den_lxy_endcap", binnum, bins);

TH1F *num_lz_endcap = new TH1F("num_lz_endcap", "num_lz_endcap", binnum, bins);
TH1F *den_lz_endcap = new TH1F("den_lz_endcap", "den_lz_endcap", binnum, bins);

double My_dPhi (double phi1, double phi2) {
	double dPhi = phi1 - phi2;
	if (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
	if (dPhi <  -TMath::Pi()) dPhi += 2*TMath::Pi();
	return fabs(dPhi);
}

bool deltaR(double genEta, double genPhi, double eta0, double phi0, double eta1, double phi1, double eta2, double phi2, double eta3, double phi3){

	bool match = false;

	double dphi0 = My_dPhi(genPhi, phi0);
	double deta0 = genEta - eta0;
	double dr0 = sqrt(dphi0*dphi0 + deta0*deta0);

	double dphi1 = My_dPhi(genPhi, phi1);
	double deta1 = genEta - eta1;
	double dr1 = sqrt(dphi1*dphi1 + deta1*deta1);

	double dphi2 = My_dPhi(genPhi, phi2);
	double deta2 = genEta - eta2;
	double dr2 = sqrt(dphi2*dphi2 + deta2*deta2);

	double dphi3 = My_dPhi(genPhi, phi3);
	double deta3 = genEta - eta3;
	double dr3 = sqrt(dphi3*dphi3 + deta3*deta3);

	if(dr0 <= 0.1 || dr1 <= 0.1 || dr2 <= 0.1 || dr3 <= 0.1) match = true;

	return match;
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

void create_eff_pergamD2DLxyLz(TString fileName){


	//bool verbose(true);
	bool verbose(false);
	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

	//Get the sample mass
	TString str = fileName;
	TString str2 = "DarkSUSY_mH_125_mGammaD_";
	Ssiz_t first = str.Index(str2);
	Ssiz_t last = str.Index("_cT_");
	TSubString mass_string = (str(first+str2.Length(),4));
	///Get the sample cT
	TString str3 = "_cT_";
	TSubString cT_string = (str(last+str3.Length(),4));

	// add files to the chain
	addfiles(chain, dirname, ext);


	Bool_t is1GenMu17;
	Bool_t is2GenMu8;
	Bool_t is3GenMu8;
	Bool_t is4GenMu8;

	Bool_t is1SelMu17;
	Bool_t is2SelMu8;
	Bool_t is3SelMu8;
	Bool_t is4SelMu8;

	Int_t npatm;


	Float_t genA0_Lxy;
	Float_t genA1_Lxy;

	Float_t genA0_Lz;
	Float_t genA1_Lz;

	Float_t selMu0_phi;
	Float_t selMu1_phi;
	Float_t selMu2_phi;
	Float_t selMu3_phi;

	Float_t selMu0_eta;
	Float_t selMu1_eta;
	Float_t selMu2_eta;
	Float_t selMu3_eta;

	Float_t genA0_eta;
	Float_t genA0_phi;
	Float_t genA1_eta;
	Float_t genA1_phi;

	Float_t muJetC_muon1_track_minchi2;
	Float_t muJetC_muon2_track_minchi2;
	Float_t muJetF_muon1_track_minchi2;
	Float_t muJetF_muon2_track_minchi2;

	Int_t event;
	Int_t ev2dim;
	Int_t ev2mj;

	Bool_t isVtxOK;
	Bool_t is2DimDzOK;
	Bool_t is2DimVtxOK;
	Bool_t is2DimHLTFired;
	Bool_t is2DimIsoTkOK;
	Bool_t is2DimMassOK;

	Float_t genA0_px;
	Float_t genA0_py;
	Float_t genA1_px;
	Float_t genA1_py;

	Bool_t isDiMuonHLTFired;


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

	Float_t genA0Mu0_px;
	Float_t genA1Mu0_px;
	Float_t genA0Mu1_px;
	Float_t genA1Mu1_px;

	Float_t genA0Mu0_py;
	Float_t genA1Mu0_py;
	Float_t genA0Mu1_py;
	Float_t genA1Mu1_py;


	Float_t genMu0_pT;
	Float_t genMu1_pT;
	Float_t genMu2_pT;
	Float_t genMu3_pT;

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

		if (verbose) std::cout << "Loading directory cutFlowAnalyzer" << std::endl;
		myfile->cd("cutFlowAnalyzer");

		TTree *t = (TTree*)myfile->Get("cutFlowAnalyzer/Events");
		if (!t) {
			if (verbose) std::cout << "Tree cutFlowAnalyzer/Events does not exist" << std::endl;
			continue;
		}

		if (verbose) cout<<"  Events  "<<t->GetEntries()<<endl;




		t->SetBranchAddress("event",&event);

		t->SetBranchAddress("is1GenMu17",&is1GenMu17);
		t->SetBranchAddress("is2GenMu8",&is2GenMu8);
		t->SetBranchAddress("is3GenMu8",&is3GenMu8);
		t->SetBranchAddress("is4GenMu8",&is4GenMu8);

		t->SetBranchAddress("is1SelMu17",&is1SelMu17);
		t->SetBranchAddress("is2SelMu8",&is2SelMu8);
		t->SetBranchAddress("is3SelMu8",&is3SelMu8);
		t->SetBranchAddress("is4SelMu8",&is4SelMu8);

		t->SetBranchAddress("isVertexOK",&isVtxOK);

		//t->SetBranchAddress("is4GenMu8",&is4GenMu8);

		t->SetBranchAddress("genA0_Lxy", &genA0_Lxy);
		t->SetBranchAddress("genA0_Lz",  &genA0_Lz);
		t->SetBranchAddress("genA1_Lxy", &genA1_Lxy);
		t->SetBranchAddress("genA1_Lz",  &genA1_Lz);


		t->SetBranchAddress("selMu0_phi",&selMu0_phi);
		t->SetBranchAddress("selMu1_phi",&selMu1_phi);
		t->SetBranchAddress("selMu2_phi",&selMu2_phi);
		t->SetBranchAddress("selMu3_phi",&selMu3_phi);

		t->SetBranchAddress("selMu0_eta",&selMu0_eta);
		t->SetBranchAddress("selMu1_eta",&selMu1_eta);
		t->SetBranchAddress("selMu2_eta",&selMu2_eta);
		t->SetBranchAddress("selMu3_eta",&selMu3_eta);


		t->SetBranchAddress("genA1_phi",&genA1_phi);
		t->SetBranchAddress("genA1_eta",&genA1_eta);

		t->SetBranchAddress("genA0_phi",&genA0_phi);
		t->SetBranchAddress("genA0_eta",&genA0_eta);


		t->SetBranchAddress("diMuonC_FittedVtx_px", &diMuonC_FittedVtx_px);
		t->SetBranchAddress("diMuonC_FittedVtx_py", &diMuonC_FittedVtx_py);
		t->SetBranchAddress("diMuonF_FittedVtx_px", &diMuonF_FittedVtx_px);
		t->SetBranchAddress("diMuonF_FittedVtx_py", &diMuonF_FittedVtx_py);

		t->SetBranchAddress("genA0_px", & genA0_px);
		t->SetBranchAddress("genA0_py", & genA0_py);
		t->SetBranchAddress("genA1_px", & genA1_px);
		t->SetBranchAddress("genA1_py", & genA1_py);

		t->SetBranchAddress("genA0Mu0_eta",&genA0Mu0_eta);
		t->SetBranchAddress("genA1Mu0_eta",&genA1Mu0_eta);
		t->SetBranchAddress("genA0Mu1_eta",&genA0Mu1_eta);
		t->SetBranchAddress("genA1Mu1_eta",&genA1Mu1_eta);

		t->SetBranchAddress("genA0Mu0_phi",&genA0Mu0_phi);
		t->SetBranchAddress("genA1Mu0_phi",&genA1Mu0_phi);
		t->SetBranchAddress("genA0Mu1_phi",&genA0Mu1_phi);
		t->SetBranchAddress("genA1Mu1_phi",&genA1Mu1_phi);

		t->SetBranchAddress("genA0Mu0_px",&genA0Mu0_px);
		t->SetBranchAddress("genA1Mu0_px",&genA1Mu0_px);
		t->SetBranchAddress("genA0Mu1_px",&genA0Mu1_px);
		t->SetBranchAddress("genA1Mu1_px",&genA1Mu1_px);

		t->SetBranchAddress("genA0Mu0_py",&genA0Mu0_py);
		t->SetBranchAddress("genA1Mu0_py",&genA1Mu0_py);
		t->SetBranchAddress("genA0Mu1_py",&genA0Mu1_py);
		t->SetBranchAddress("genA1Mu1_py",&genA1Mu1_py);

		t->SetBranchAddress("genMu0_pT",    &genMu0_pT);
		t->SetBranchAddress("genMu1_pT",    &genMu1_pT);
		t->SetBranchAddress("genMu2_pT",    &genMu2_pT);
		t->SetBranchAddress("genMu3_pT",    &genMu3_pT);

		t->SetBranchAddress("isDiMuonHLTFired",               &isDiMuonHLTFired);

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

		Int_t nentries = t->GetEntries();

		for(int k=0;k<nentries;k++){
			t->GetEntry(k);
			//Loop for Efficienies
			if(isDiMuonHLTFired == 1){ //Make sure that the event fired the HLT
				if(is4GenMu8==true){ //This contains all of the pT and eta requirements on the muons.
					//Denominators go here
					double pt00 = sqrt(genA0Mu0_px*genA0Mu0_px + genA0Mu0_py*genA0Mu0_py);
					double pt01 = sqrt(genA0Mu1_px*genA0Mu1_px + genA0Mu1_py*genA0Mu1_py);
					double pt10 = sqrt(genA1Mu0_px*genA1Mu0_px + genA1Mu0_py*genA1Mu0_py);
					double pt11 = sqrt(genA1Mu1_px*genA1Mu1_px + genA1Mu1_py*genA1Mu1_py);

					if(fabs(genA0Mu0_eta) <= 0.9){
						den_pt_barrel->Fill(pt00);
						den_eta_barrel->Fill(genA0Mu0_eta);
						den_lxy_barrel->Fill(genA0_Lxy);
						den_lz_barrel->Fill(genA0_Lz);
					}else{ 
						den_pt_endcap->Fill(pt00);
						den_eta_endcap->Fill(genA0Mu0_eta);
						den_lxy_endcap->Fill(genA0_Lxy);
						den_lz_endcap->Fill(genA0_Lz);
					}
					if(fabs(genA0Mu1_eta) <= 0.9){
						den_pt_barrel->Fill(pt01);
						den_eta_barrel->Fill(genA0Mu1_eta);
						den_lxy_barrel->Fill(genA0_Lxy);
						den_lz_barrel->Fill(genA0_Lz);
					}else{ 
						den_pt_endcap->Fill(pt01);
						den_eta_endcap->Fill(genA0Mu1_eta);
						den_lxy_endcap->Fill(genA0_Lxy);
						den_lz_endcap->Fill(genA0_Lz);
					}
					if(fabs(genA1Mu0_eta) <= 0.9){
						den_pt_barrel->Fill(pt10);
						den_eta_barrel->Fill(genA1Mu0_eta);
						den_lxy_barrel->Fill(genA1_Lxy);
						den_lz_barrel->Fill(genA1_Lz);
					}else{
						den_pt_endcap->Fill(pt10);
						den_eta_endcap->Fill(genA1Mu0_eta);
						den_lxy_endcap->Fill(genA1_Lxy);
						den_lz_endcap->Fill(genA1_Lz);
					}
					if(fabs(genA1Mu1_eta) <= 0.9){
						den_pt_barrel->Fill(pt11);
						den_eta_barrel->Fill(genA1Mu1_eta);
						den_lxy_barrel->Fill(genA1_Lxy);
						den_lz_barrel->Fill(genA1_Lz);
					}else{
						den_pt_endcap->Fill(pt11);
						den_eta_endcap->Fill(genA1Mu1_eta);
						den_lxy_endcap->Fill(genA1_Lxy);
						den_lz_endcap->Fill(genA1_Lz);
					}

					//Begin looking for deltaR matches and filling numerators
					bool match00 = deltaR(genA0Mu0_eta, genA0Mu0_phi, selMu0_eta, selMu0_phi, selMu1_eta, selMu1_phi, selMu2_eta, selMu2_phi, selMu3_eta, selMu3_phi);
					bool match01 = deltaR(genA0Mu1_eta, genA0Mu1_phi, selMu0_eta, selMu0_phi, selMu1_eta, selMu1_phi, selMu2_eta, selMu2_phi, selMu3_eta, selMu3_phi);
					bool match10 = deltaR(genA1Mu0_eta, genA1Mu0_phi, selMu0_eta, selMu0_phi, selMu1_eta, selMu1_phi, selMu2_eta, selMu2_phi, selMu3_eta, selMu3_phi);
					bool match11 = deltaR(genA1Mu1_eta, genA1Mu1_phi, selMu0_eta, selMu0_phi, selMu1_eta, selMu1_phi, selMu2_eta, selMu2_phi, selMu3_eta, selMu3_phi);

					if(match00){
						if(fabs(genA0Mu0_eta) <= 0.9){
							num_pt_barrel->Fill(pt00);
							num_eta_barrel->Fill(genA0Mu0_eta);
							num_lxy_barrel->Fill(genA0_Lxy);
							num_lz_barrel->Fill(genA0_Lz);
						}else{
							num_pt_endcap->Fill(pt00);
							num_eta_endcap->Fill(genA0Mu0_eta);
							num_lxy_endcap->Fill(genA0_Lxy);
							num_lz_endcap->Fill(genA0_Lz);
						}
					}
					if(match01){
						if(fabs(genA0Mu1_eta) <= 0.9){
							num_pt_barrel->Fill(pt01);
							num_eta_barrel->Fill(genA0Mu1_eta);
							num_lxy_barrel->Fill(genA0_Lxy);
							num_lz_barrel->Fill(genA0_Lz);
						}else{
							num_pt_endcap->Fill(pt01);
							num_eta_endcap->Fill(genA0Mu1_eta);
							num_lxy_endcap->Fill(genA0_Lxy);
							num_lz_endcap->Fill(genA0_Lz);
						}
					}
					if(match10){
						if(fabs(genA1Mu0_eta) <= 0.9){
							num_pt_barrel->Fill(pt10);
							num_eta_barrel->Fill(genA1Mu0_eta);
							num_lxy_barrel->Fill(genA1_Lxy);
							num_lz_barrel->Fill(genA1_Lz);
						}else{
							num_pt_endcap->Fill(pt10);
							num_eta_endcap->Fill(genA1Mu0_eta);
							num_lxy_endcap->Fill(genA1_Lxy);
							num_lz_endcap->Fill(genA1_Lz);
						}
					}
					if(match11){
						if(fabs(genA1Mu1_eta) <= 0.9){
							num_pt_barrel->Fill(pt11);
							num_eta_barrel->Fill(genA1Mu1_eta);
							num_lxy_barrel->Fill(genA1_Lxy);
							num_lz_barrel->Fill(genA1_Lz);
						}else{
							num_pt_endcap->Fill(pt11);
							num_eta_endcap->Fill(genA1Mu1_eta);
							num_lxy_endcap->Fill(genA1_Lxy);
							num_lz_endcap->Fill(genA1_Lz);
						}
					}

				} //GEN level pT and eta req cut 
			}// trigger loop 
		} //for loop
		myfile->Close();
	} //While loop
} //Method loop


void makePlots(){

	//Detector geometry
	TLine *pixel_1 = new TLine(4.3, 0, 4.3, 1);
	TLine *pixel_2 = new TLine(7.2, 0, 7.2, 1);
	TLine *pixel_3 = new TLine(11, 0, 11, 1);
	TLine *tracker_innerbarrel = new TLine(23.9, 0, 23.9, 1); 
	TLine *tracker_outerbarrel = new TLine(60.5, 0, 60.5, 1);

	TLine *pixel_endcap_1 = new TLine(34.5, 0, 34.5, 1);
	TLine *pixel_endcap_2 = new TLine(46.5, 0, 46.5, 1);

	//Blue Lines
	pixel_1->SetLineStyle(2);
	pixel_2->SetLineStyle(2);
	pixel_3->SetLineStyle(2);
	pixel_endcap_1->SetLineStyle(2);
	pixel_endcap_2->SetLineStyle(2);

	pixel_1->SetLineColor(kBlue);
	pixel_2->SetLineColor(kBlue);
	pixel_3->SetLineColor(kBlue);
	pixel_endcap_1->SetLineColor(kBlue);
	pixel_endcap_2->SetLineColor(kBlue);

	//Green Lines
	tracker_innerbarrel->SetLineStyle(2);
	tracker_outerbarrel->SetLineStyle(2);

	tracker_innerbarrel->SetLineColor(kGreen);
	tracker_outerbarrel->SetLineColor(kGreen);

	//Efficiency plots

	pt_barrel  = new TGraphAsymmErrors(num_pt_barrel, den_pt_barrel);
	eta_barrel = new TGraphAsymmErrors(num_eta_barrel, den_eta_barrel);
	lxy_barrel = new TGraphAsymmErrors(num_lxy_barrel, den_lxy_barrel);
	lz_barrel  = new TGraphAsymmErrors(num_lz_barrel, den_lz_barrel);
	pt_endcap  = new TGraphAsymmErrors(num_pt_endcap, den_pt_endcap);
	eta_endcap = new TGraphAsymmErrors(num_eta_endcap, den_eta_endcap);
	lxy_endcap = new TGraphAsymmErrors(num_lxy_endcap, den_lxy_endcap);
	lz_endcap  = new TGraphAsymmErrors(num_lz_endcap, den_lz_endcap);

	pt_barrel ->SetMarkerColor(kRed); 
	eta_barrel->SetMarkerColor(kRed); 
	lxy_barrel->SetMarkerColor(kRed); 
	lz_barrel ->SetMarkerColor(kRed); 
	pt_endcap ->SetMarkerColor(kBlue); 
	eta_endcap->SetMarkerColor(kBlue); 
	lxy_endcap->SetMarkerColor(kBlue); 
	lz_endcap ->SetMarkerColor(kBlue); 

	pt_barrel ->SetMarkerStyle(2); 
	eta_barrel->SetMarkerStyle(2); 
	lxy_barrel->SetMarkerStyle(2); 
	lz_barrel ->SetMarkerStyle(2); 
	pt_endcap ->SetMarkerStyle(2); 
	eta_endcap->SetMarkerStyle(2); 
	lxy_endcap->SetMarkerStyle(2); 
	lz_endcap ->SetMarkerStyle(2); 

	pt_barrel ->SetLineColor(kRed); 
	eta_barrel->SetLineColor(kRed); 
	lxy_barrel->SetLineColor(kRed); 
	lz_barrel ->SetLineColor(kRed); 
	pt_endcap ->SetLineColor(kBlue); 
	eta_endcap->SetLineColor(kBlue); 
	lxy_endcap->SetLineColor(kBlue); 
	lz_endcap ->SetLineColor(kBlue); 

	pt_barrel ->SetLineStyle(1); 
	eta_barrel->SetLineStyle(1); 
	lxy_barrel->SetLineStyle(1); 
	lz_barrel ->SetLineStyle(1); 
	pt_endcap ->SetLineStyle(2); 
	eta_endcap->SetLineStyle(2); 
	lxy_endcap->SetLineStyle(2); 
	lz_endcap ->SetLineStyle(2); 

	pt_barrel ->SetLineWidth(2);
	eta_barrel->SetLineWidth(2);
	lxy_barrel->SetLineWidth(2);
	lz_barrel ->SetLineWidth(2);
	pt_endcap ->SetLineWidth(2);
	eta_endcap->SetLineWidth(2);
	lxy_endcap->SetLineWidth(2);
	lz_endcap ->SetLineWidth(2);

TCanvas *pt = new TCanvas("pt", "pt", 700, 500);
TMultiGraph *mg_pt = new TMultiGraph();
mg_pt->Add(pt_barrel);
mg_pt->Add(pt_endcap);

TLegend *ptleg = new TLegend(0.6982759,0.6701903,0.8979885,0.8794926);
ptleg->SetBorderSize(0);
ptleg->SetFillColor(0);
ptleg->SetTextSize(0.03171247);
ptleg->AddEntry(pt_barrel, "|#eta_{#mu}| #leq 0.9","L");
ptleg->AddEntry(pt_endcap, "|#eta_{#mu}| > 0.9","L");
mg_pt->Draw("ALP");
mg_pt->GetXaxis()->SetTitle("p_{T} [GeV]");
mg_pt->GetYaxis()->SetTitle("Efficiency");
mg_pt->SetMinimum(0.);
mg_pt->SetMaximum(1.2);
ptleg->Draw("same");

pt->SaveAs("Efficiency_1D_pT.pdf");
pt->SaveAs("Efficiency_1D_pT.png");
pt->SaveAs("Efficiency_1D_pT.C");

TCanvas *eta = new TCanvas("eta", "eta", 700, 500);
TMultiGraph *mg_eta = new TMultiGraph();
mg_eta->Add(eta_barrel);
mg_eta->Add(eta_endcap);

TLegend *etaleg = new TLegend(0.6982759,0.6701903,0.8979885,0.8794926);
etaleg->SetBorderSize(0);
etaleg->SetFillColor(0);
etaleg->SetTextSize(0.03171247);
etaleg->AddEntry(eta_barrel, "|#eta_{#mu}| #leq 0.9","L");
etaleg->AddEntry(eta_endcap, "|#eta_{#mu}| > 0.9","L");
mg_eta->Draw("ALP");
mg_eta->GetXaxis()->SetTitle("#eta");
mg_eta->GetYaxis()->SetTitle("Efficiency");
mg_eta->SetMinimum(0.);
mg_eta->SetMaximum(1.2);
etaleg->Draw("same");

eta->SaveAs("Efficiency_1D_eta.pdf");
eta->SaveAs("Efficiency_1D_eta.png");
eta->SaveAs("Efficiency_1D_eta.C");

TCanvas *lxy = new TCanvas("lxy", "lxy", 700, 500);
TMultiGraph *mg_lxy = new TMultiGraph();
mg_lxy->Add(lxy_barrel);
mg_lxy->Add(lxy_endcap);

TLegend *lxyleg = new TLegend(0.6982759,0.6701903,0.8979885,0.8794926);
lxyleg->SetBorderSize(0);
lxyleg->SetFillColor(0);
lxyleg->SetTextSize(0.03171247);
lxyleg->AddEntry(lxy_barrel, "|#eta_{#mu}| #leq 0.9","L");
lxyleg->AddEntry(lxy_endcap, "|#eta_{#mu}| > 0.9","L");
mg_lxy->Draw("ALP");
mg_lxy->GetXaxis()->SetTitle("L_{xy} [cm]");
mg_lxy->GetYaxis()->SetTitle("Efficiency");
mg_lxy->SetMinimum(0.);
mg_lxy->SetMaximum(1.2);
lxyleg->Draw("same");
pixel_1->Draw("same");
pixel_2->Draw("same");
pixel_3->Draw("same");
tracker_innerbarrel->Draw("same");
tracker_outerbarrel->Draw("same");

lxy->SaveAs("Efficiency_1D_lxy.pdf");
lxy->SaveAs("Efficiency_1D_lxy.png");
lxy->SaveAs("Efficiency_1D_lxy.C");

TCanvas *lz = new TCanvas("lz", "lz", 700, 500);
TMultiGraph *mg_lz = new TMultiGraph();
mg_lz->Add(lz_barrel);
mg_lz->Add(lz_endcap);

TLegend *lzleg = new TLegend(0.6982759,0.6701903,0.8979885,0.8794926);
lzleg->SetBorderSize(0);
lzleg->SetFillColor(0);
lzleg->SetTextSize(0.03171247);
lzleg->AddEntry(lz_barrel, "|#eta_{#mu}| #leq 0.9","L");
lzleg->AddEntry(lz_endcap, "|#eta_{#mu}| > 0.9","L");
mg_lz->Draw("ALP");
mg_lz->GetXaxis()->SetTitle("L_{z} [cm]");
mg_lz->GetYaxis()->SetTitle("Efficiency");
mg_lz->SetMinimum(0.);
mg_lz->SetMaximum(1.2);
lzleg->Draw("same");
pixel_endcap_1->Draw("same");
pixel_endcap_2->Draw("same");

lz->SaveAs("Efficiency_1D_lz.pdf");
lz->SaveAs("Efficiency_1D_lz.png");
lz->SaveAs("Efficiency_1D_lz.C");
}

void perMuEfficiency(){

	//These cT's should be in order.
	
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_000_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_005_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_005_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_010_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_010_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_020_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_020_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_050_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_050_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_100_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_100_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_200_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_200_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_300_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_300_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_500_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_2000_13TeV_cT_500_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");

	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_1000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_2000_cT_2000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");

/*

	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_000_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f//");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_005_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_005_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_010_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_010_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_020_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_020_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_050_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_050_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_100_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_100_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_200_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_200_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_300_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_300_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/dildick/DarkSUSY_mH_125_mGammaD_0250_cT_500_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0250_13TeV_cT_500_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_1000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_2000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	   */
/*
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_005_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_010_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_020_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_050_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_100_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_200_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_300_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_500_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");

	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_1000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_0250_cT_2000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
*/
	/*
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN_71_v1_v2/asdf/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_005_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_005_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_010_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_010_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_020_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_020_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_050_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_050_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_100_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_100_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_200_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_200_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_300_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_300_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/bmichlin/DarkSUSY_mH_125_mGammaD_8500_cT_500_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_8500_13TeV_cT_500_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/226daabb7c2674ae5cd9e5d6ac58846b/");



	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_000_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_005_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_005_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_010_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_010_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_020_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_020_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_050_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_050_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_100_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_100_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_200_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_200_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/jrorie/DarkSUSY_mH_125_mGammaD_0275_cT_300_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v4/DarkSUSY_mH_125_mGammaD_0275_13TeV_cT_300_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/f543ab33d972fd2ae528b8fb60581c3f/");



	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/castaned/DarkSUSY_mH_125_mGammaD_0300_cT_000_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0300_13TeV_cT_000_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/d0f588fd6866a3a3094022dcf1ebdad3/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/castaned/DarkSUSY_mH_125_mGammaD_0300_cT_010_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0300_13TeV_cT_010_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/d0f588fd6866a3a3094022dcf1ebdad3/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/castaned/DarkSUSY_mH_125_mGammaD_0300_cT_020_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0300_13TeV_cT_020_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/d0f588fd6866a3a3094022dcf1ebdad3/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/castaned/DarkSUSY_mH_125_mGammaD_0300_cT_050_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0300_13TeV_cT_050_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/d0f588fd6866a3a3094022dcf1ebdad3/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/castaned/DarkSUSY_mH_125_mGammaD_0300_cT_200_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0300_13TeV_cT_200_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/d0f588fd6866a3a3094022dcf1ebdad3/");
	   create_eff_pergamD2DLxyLz("/fdata/hepx/store/user/castaned/DarkSUSY_mH_125_mGammaD_0300_cT_500_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1/DarkSUSY_mH_125_mGammaD_0300_13TeV_cT_500_madgraph452_bridge224_LHE_pythia8_741p1_PAT_ANA/d0f588fd6866a3a3094022dcf1ebdad3/");
	   */


	makePlots();

	BAM->Write();
}
