#include <iostream>
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
#include "/home/bmichlin/TreeLoop/BaseBranchCheck/CMSSW_7_4_1_patch1/src/MuJetAnalysis/AnalysisRun2/scripts/Helpers.h"
using namespace std;

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


TString mass_string;
TString cT_string;
TString fileName;

std::map<TString, TString > mass_strings = {
  {"0250", "0.25"}, {"0275", "0.275"}, {"0300","0.3"}, {"0400", "0.4"}, {"0700", "0.7"},
  {"1000", "1.0"}, {"1500", "1.5"}, {"2000", "2.0"}, {"8500", "8.5"}
};
std::map<TString, double > cT_strings = {
  {"000_",0.0}, {"005_", 0.05}, {"010_", 0.10}, {"020_", 0.20}, {"050_", 0.50}, {"100_", 1.00},
  {"200_", 2.00}, {"300_", 3.00}, {"500_", 5.00}, {"1000", 10.0}, {"2000", 20.0}, {"8500", 85.0}
};



void cutflow(const std::vector<std::string>& dirNames){
	bool verbose(false);
//	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

decodeFileNameMany(dirNames, mass_string, cT_string);
    fileName = "DarkSUSY_mH_125_mGammaD_" + mass_string + "_cT_" + cT_string;

	// add files to the chain
addfilesMany(chain, dirNames, ext);

  // TFile *f[10];

  // f[0] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_000_Evt_80k_PATANA_UnHardCode_v4.root");
  // f[1] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_005_Evt_80k_PATANA_UnHardCode_v4.root");
  // f[2] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_010_Evt_80k_PATANA_UnHardCode_v4.root");
  // f[3] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_050_Evt_80k_PATANA_UnHardCode_v4.root");
  // f[4] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_100_Evt_80k_PATANA_UnHardCode_v4.root");
  // f[5] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_300_Evt_80k_PATANA_UnHardCode_v4.root");
  // f[6] = new TFile("DarkSUSY_mH_125_mGammaD_0250_cT_500_Evt_80k_PATANA_UnHardCode_v4_merged.root");
  
  Bool_t   is4GenMu8;
  Float_t  genA0_Lz;
  Float_t  genA0_Lxy;
  Float_t  genA1_Lz;
  Float_t  genA1_Lxy; 
  
  Bool_t    is4SelMu8;
  Bool_t    is2DiMuons;
  Bool_t    is2DiMuonsFittedVtxOK;
  Bool_t    isDiMuonHLTFired;
  Bool_t    is2DiMuonsMassOK_FittedVtx;
  Float_t   diMuonC_IsoTk_FittedVtx;
  Float_t   diMuonF_IsoTk_FittedVtx;
  Float_t   diMuonC_FittedVtx_eta;
  Float_t   diMuonF_FittedVtx_eta;
  Float_t   diMuonC_FittedVtx_Lxy;
  Float_t   diMuonF_FittedVtx_Lxy;
  
  Int_t     diMuonC_m1_FittedVtx_hitpix_l3inc;
  Int_t     diMuonC_m2_FittedVtx_hitpix_l3inc;
  Int_t     diMuonF_m1_FittedVtx_hitpix_l3inc;
  Int_t     diMuonF_m2_FittedVtx_hitpix_l3inc;

  Int_t     diMuonC_m1_FittedVtx_hitpix_l2inc;
  Int_t     diMuonC_m2_FittedVtx_hitpix_l2inc;
  Int_t     diMuonF_m1_FittedVtx_hitpix_l2inc;
  Int_t     diMuonF_m2_FittedVtx_hitpix_l2inc;

  Int_t     diMuonC_m1_FittedVtx_hitpix;
  Int_t     diMuonC_m2_FittedVtx_hitpix;
  Int_t     diMuonF_m1_FittedVtx_hitpix;
  Int_t     diMuonF_m2_FittedVtx_hitpix;
  
  Int_t     innerlayers_mu1_muJetC;
  Int_t     innerlayers_mu2_muJetC;
  Int_t     innerlayers_mu1_muJetF;
  Int_t     innerlayers_mu2_muJetF;

  Int_t           compdet_mu1_muJetC[10];
  Int_t           compdet_mu2_muJetC[10];
  Int_t           compdet_mu1_muJetF[10];
  Int_t           compdet_mu2_muJetF[10];
  
  
  Float_t     diMuons_dz_FittedVtx;
  
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
   

  Int_t count_recovermuJetC[10]={0};
  Int_t count_recovermuJetF[10]={0};
  Int_t count_recovermuJetCANDF[10]={0};
  
  Int_t count_gen[10]={0};
  Int_t count_rec[10]={0};
  Int_t count_rec_fail[10]={0};


  Int_t totev[10]={0};
  Int_t count_is4SelMu8[10]={0};
  Int_t count_is2DiMuons[10]={0};
  Int_t count_is2DiMuonsFittedVtxOK[10]={0};
  Int_t count_isDiMuonHLTFired[10]={0};
  Int_t count_is2DiMuonsMassOK[10]={0};
  Int_t count_IsoTk[10]={0};
  Int_t count_dz[10]={0};
  Int_t count_fakemit[10]={0};
  Int_t count_pixelhit[10]={0};


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
    myfile->cd("cutFlowAnalyzer");
    
    TTree *t = (TTree*)myfile->Get("cutFlowAnalyzer/Events");
    if (!t) {
      if (verbose) std::cout << "Tree cutFlowAnalyzerPXBL3PXFL2/Events does not exist" << std::endl;
      continue;
    }
    
    if (verbose) cout<<"  Events  "<<t->GetEntries()<<endl;
    
    //Pull variables from nTuple
    
    t->SetBranchAddress("is4GenMu8", &is4GenMu8);
    t->SetBranchAddress("genA0_Lz", &genA0_Lz);
    t->SetBranchAddress("genA0_Lxy", &genA0_Lxy);
    t->SetBranchAddress("genA1_Lz", &genA1_Lz);
    t->SetBranchAddress("genA1_Lxy", &genA1_Lxy);

    t->SetBranchAddress("is4SelMu8", &is4SelMu8);
    t->SetBranchAddress("is2DiMuons",&is2DiMuons);
    t->SetBranchAddress("is2DiMuonsFittedVtxOK", &is2DiMuonsFittedVtxOK);
    t->SetBranchAddress("isDiMuonHLTFired", &isDiMuonHLTFired);
    t->SetBranchAddress("is2DiMuonsMassOK_FittedVtx", &is2DiMuonsMassOK_FittedVtx);
    t->SetBranchAddress("diMuonC_IsoTk_FittedVtx", &diMuonC_IsoTk_FittedVtx);
    t->SetBranchAddress("diMuonF_IsoTk_FittedVtx", &diMuonF_IsoTk_FittedVtx);
    t->SetBranchAddress("diMuons_dz_FittedVtx", &diMuons_dz_FittedVtx);

    t->SetBranchAddress("diMuonC_FittedVtx_eta",&diMuonC_FittedVtx_eta);
    t->SetBranchAddress("diMuonF_FittedVtx_eta",&diMuonF_FittedVtx_eta);
    t->SetBranchAddress("diMuonC_FittedVtx_Lxy",&diMuonC_FittedVtx_Lxy);
    t->SetBranchAddress("diMuonF_FittedVtx_Lxy",&diMuonF_FittedVtx_Lxy);
      
    
    t->SetBranchAddress("diMuonC_m1_FittedVtx_hitpix_l3inc", &diMuonC_m1_FittedVtx_hitpix_l3inc);
    t->SetBranchAddress("diMuonC_m2_FittedVtx_hitpix_l3inc", &diMuonC_m2_FittedVtx_hitpix_l3inc);
    t->SetBranchAddress("diMuonF_m1_FittedVtx_hitpix_l3inc", &diMuonF_m1_FittedVtx_hitpix_l3inc);
    t->SetBranchAddress("diMuonF_m2_FittedVtx_hitpix_l3inc", &diMuonF_m2_FittedVtx_hitpix_l3inc);

    t->SetBranchAddress("diMuonC_m1_FittedVtx_hitpix_l2inc", &diMuonC_m1_FittedVtx_hitpix_l2inc);
    t->SetBranchAddress("diMuonC_m2_FittedVtx_hitpix_l2inc", &diMuonC_m2_FittedVtx_hitpix_l2inc);
    t->SetBranchAddress("diMuonF_m1_FittedVtx_hitpix_l2inc", &diMuonF_m1_FittedVtx_hitpix_l2inc);
    t->SetBranchAddress("diMuonF_m2_FittedVtx_hitpix_l2inc", &diMuonF_m2_FittedVtx_hitpix_l2inc);


    t->SetBranchAddress("diMuonC_m1_FittedVtx_hitpix", &diMuonC_m1_FittedVtx_hitpix);
    t->SetBranchAddress("diMuonC_m2_FittedVtx_hitpix", &diMuonC_m2_FittedVtx_hitpix);
    t->SetBranchAddress("diMuonF_m1_FittedVtx_hitpix", &diMuonF_m1_FittedVtx_hitpix);
    t->SetBranchAddress("diMuonF_m2_FittedVtx_hitpix", &diMuonF_m2_FittedVtx_hitpix);

  
    t->SetBranchAddress("innerlayers_mu1_muJetC", &innerlayers_mu1_muJetC);
    t->SetBranchAddress("innerlayers_mu2_muJetC", &innerlayers_mu2_muJetC);
    t->SetBranchAddress("innerlayers_mu1_muJetF", &innerlayers_mu1_muJetF);
    t->SetBranchAddress("innerlayers_mu2_muJetF", &innerlayers_mu2_muJetF);

    t->SetBranchAddress("compdet_mu1_muJetC", &compdet_mu1_muJetC);
    t->SetBranchAddress("compdet_mu2_muJetC", &compdet_mu2_muJetC);
    t->SetBranchAddress("compdet_mu1_muJetF", &compdet_mu1_muJetF);
    t->SetBranchAddress("compdet_mu2_muJetF", &compdet_mu2_muJetF);
    
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
    
    Int_t nentries = t->GetEntries();
    
    // Int_t fail_mujetCORF=0;
    // Int_t fail_mujetC=0;
    // Int_t fail_mujetF=0;
    // Int_t fail_mujetCANDF=0;

    // char nameh[80];
    // char nameh2[80];
    // char namec[80];
    // Float_t xmin;
    // Float_t xmax;
    // Float_t ymin;
    // Float_t ymax;

    for(int i=0;i<nentries;i++){
      
      t->GetEntry(i);
      
      // totev[p]++;
      
      // if(is4GenMu8){
      // 	if(genA0_Lxy<4.4 && fabs(genA0_Lz)<34.5 && genA1_Lxy<4.4 && fabs(genA1_Lz)<34.5){   // first pixel layer
      // 	  //	if(genA0_Lxy<9.8 && fabs(genA0_Lz)<48.5 && genA1_Lxy<9.8 && fabs(genA1_Lz)<48.5){  // third pixel layer
      // 	  count_gen[p]++;
      // 	}
      // }
      
      // if(is4SelMu8){        // is 4 reco muons
      // 	count_is4SelMu8[p]++;
      // 	if(is2DiMuons){    // is 2 dimuons
      // 	  count_is2DiMuons[p]++;
      // 	  if(is2DiMuonsFittedVtxOK){  // is 2 dimuons with fittedvtxok
      // 	    count_is2DiMuonsFittedVtxOK[p]++;
      // 	    if(isDiMuonHLTFired){     // trigger
      // 	      count_isDiMuonHLTFired[p]++;
      // 	      if(is2DiMuonsMassOK_FittedVtx){  // mass compatibility
      // 		count_is2DiMuonsMassOK[p]++;
      // 		if(diMuonC_IsoTk_FittedVtx<2.0 && diMuonF_IsoTk_FittedVtx<2.0){  // isolation
      // 		  count_IsoTk[p]++;
      // 		  if(diMuons_dz_FittedVtx<0.1){  //dz cut
      // 		    count_dz[p]++;
      // 		    if( ((pow(diMuonC_FittedVtx_eta,2)/pow(2.88,2)) + (pow(diMuonC_FittedVtx_Lxy,2)/pow(8.20,2)) <= 1) || (diMuonC_FittedVtx_Lxy < 0) ){
      // 		      if( ((pow(diMuonF_FittedVtx_eta,2)/pow(2.88,2)) + (pow(diMuonF_FittedVtx_Lxy,2)/pow(8.20,2)) <= 1) || (diMuonF_FittedVtx_Lxy < 0) ){
      // 			count_fakemit[p]++;
			
      // 			if( (diMuonC_m1_FittedVtx_hitpix==1||diMuonC_m2_FittedVtx_hitpix==1)&&(diMuonF_m1_FittedVtx_hitpix==1||diMuonF_m2_FittedVtx_hitpix==1)){
      // 			  //		    if( (diMuonC_m1_FittedVtx_hitpix_l3inc==1||diMuonC_m2_FittedVtx_hitpix_l3inc==1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc==1||diMuonF_m2_FittedVtx_hitpix_l3inc==1)){
      // 			  count_pixelhit[p]++;
      // 			  count_rec[p]++;
      // 			}
			

      // 			//======================== PHR starts at this point  ==========================================================//
			
      // 			if( (diMuonC_m1_FittedVtx_hitpix!=1&&diMuonC_m2_FittedVtx_hitpix!=1)||(diMuonF_m1_FittedVtx_hitpix!=1&&diMuonF_m2_FittedVtx_hitpix!=1)){
      // 			  //		    if( (diMuonC_m1_FittedVtx_hitpix_l3inc!=1&&diMuonC_m2_FittedVtx_hitpix_l3inc!=1)||(diMuonF_m1_FittedVtx_hitpix_l3inc!=1&&diMuonF_m2_FittedVtx_hitpix_l3inc!=1)){
      // 			  count_rec_fail[p]++;
      // 			  fail_mujetCORF++;
			  
      // 			  Float_t hitposx[100]={10000};
      // 			  Float_t hitposy[100]={10000};
			  
      // 			  Float_t muon1posx=10000;
      // 			  Float_t muon1posy=10000;
			  
      // 			  Float_t muon2posx=10000;
      // 			  Float_t muon2posy=10000;
			  
      // 			  Float_t radius_rec=0.05;
			  
      // 			  Int_t passingC=0;
      // 			  Int_t passingF=0;
			  
      // 			  Bool_t recovery_muJetC=false;
      // 			  Bool_t recovery_muJetF=false;
			  
      // 			  TH2F *pos_muons[5];
      // 			  TH2F *pos_hits[5];
			  
			  
      // 			  //=============== Recovering for event which fail muJetC  ==================//
      // 			  if((diMuonC_m1_FittedVtx_hitpix!=1&&diMuonC_m2_FittedVtx_hitpix!=1)&&(diMuonF_m1_FittedVtx_hitpix==1||diMuonF_m2_FittedVtx_hitpix==1)){
      // 			    //		    if((diMuonC_m1_FittedVtx_hitpix_l3inc!=1&&diMuonC_m2_FittedVtx_hitpix_l3inc!=1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc==1||diMuonF_m2_FittedVtx_hitpix_l3inc==1)){
      // 			    //		      cout<<"  Event failing muJetC   "<<i<<endl;
      // 			    fail_mujetC++;
      // 			    if(innerlayers_mu1_muJetC>0 && innerlayers_mu2_muJetC>0){
			      
      // 			      for(int k=0;k<min(innerlayers_mu1_muJetC,innerlayers_mu2_muJetC);k++){
      // 				for(int h=0;h<min(compdet_mu1_muJetC[k],compdet_mu2_muJetC[k]);h++){
      // 				  muon1posx = mj1m0posx[k][h];
      // 				  muon1posy = mj1m0posy[k][h];
      // 				  muon2posx = mj1m1posx[k][h];
      // 				  muon2posy = mj1m1posy[k][h];
				
      // 				  // sprintf(nameh,"pos_muons_ev%d_layer%d_det%d",i,k,h);
      // 				  // sprintf(nameh2,"pos_hits_ev%d_layer%d_det%d",i,k,h);
      // 				  // sprintf(namec,"position_ev%d_layer%d_det%d.pdf",i,k,d);
				
      // 				  // xmin = mj1m0posx[k][0]-0.3;
      // 				  // xmax = mj1m0posx[k][0]+0.3;
      // 				  // ymin = mj1m0posy[k][0]-0.3;
      // 				  // ymax = mj1m0posy[k][0]+0.3;
				
      // 				  // pos_muons[k] = new TH2F(nameh,"",100,xmin,xmax,100,ymin,ymax);
      // 				  // pos_muons[k]->Fill(mj1m0posx[k][0],mj1m0posy[k][0]);
      // 				  // pos_muons[k]->Fill(mj1m1posx[k][0],mj1m1posy[k][0]);
				
      // 				  // pos_hits[k] = new TH2F(nameh2,"",100,xmin,xmax,100,ymin,ymax);
				
      // 				  for(int j=0;j<numhit_mu1_muJetC[k];j++){
      // 				    hitposx[j] = pixelhit_mu1_muJetC_posx[k][j];
      // 				    hitposy[j] = pixelhit_mu1_muJetC_posy[k][j];
      // 				    //			    pos_hits[k]->Fill(hitposx[j],hitposy[j]);
      // 				  }
				  
      // 				  passingC += BikeChain(numhit_mu1_muJetC[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
				  
      // 				  // TCanvas *c = new TCanvas("c","c");
      // 				  // pos_muons[k]->SetFillColor(4);
      // 				  // pos_muons[k]->Draw("BOX");
      // 				  // pos_hits[k]->SetFillColor(2);
      // 				  // pos_hits[k]->Draw("BOXsame");
      // 				  // c->SaveAs(namec,"recreate");
      // 				}
      // 			      }
      // 			    }
      // 			    if(passingC>0){ count_recovermuJetC[p]++;} //cout<<" Event recovered  "<<i<<endl;}
      // 			  }

      // 			  //=============== Recovering for event which fail muJetF  ==================//
      // 			  if((diMuonC_m1_FittedVtx_hitpix==1||diMuonC_m2_FittedVtx_hitpix==1)&&(diMuonF_m1_FittedVtx_hitpix!=1&&diMuonF_m2_FittedVtx_hitpix!=1)){
      // 			    //		    if((diMuonC_m1_FittedVtx_hitpix_l3inc==1||diMuonC_m2_FittedVtx_hitpix_l3inc==1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc!=1&&diMuonF_m2_FittedVtx_hitpix_l3inc!=1)){
      // 			    fail_mujetF++;
      // 			    if(innerlayers_mu1_muJetF>0 && innerlayers_mu2_muJetF>0){
			
      // 			      for(int k=0;k<min(innerlayers_mu1_muJetF,innerlayers_mu2_muJetF);k++){
      // 				for(int h=0;h<min(compdet_mu1_muJetF[k],compdet_mu2_muJetF[k]);h++){
      // 				  muon1posx = mj2m0posx[k][h];
      // 				  muon1posy = mj2m0posy[k][h];
      // 				  muon2posx = mj2m1posx[k][h];
      // 				  muon2posy = mj2m1posy[k][h];
				  
      // 				  for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposx[j] = pixelhit_mu1_muJetF_posx[k][j];
      // 				  for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposy[j] = pixelhit_mu1_muJetF_posy[k][j];
				  
      // 				  passingF += BikeChain(numhit_mu1_muJetF[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
      // 				}
      // 			      }
      // 			    }
      // 			    if(passingF>0) count_recovermuJetF[p]++;
      // 			  }

      // 			  //=============== Recovering for event which fail muJetF and muJetC  ==================//
      // 			  if((diMuonC_m1_FittedVtx_hitpix!=1&&diMuonC_m2_FittedVtx_hitpix!=1)&&(diMuonF_m1_FittedVtx_hitpix!=1&&diMuonF_m2_FittedVtx_hitpix!=1)){
      // 			    //if((diMuonC_m1_FittedVtx_hitpix_l3inc!=1&&diMuonC_m2_FittedVtx_hitpix_l3inc!=1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc!=1&&diMuonF_m2_FittedVtx_hitpix_l3inc!=1)){
      // 			    fail_mujetCANDF++;
		      
      // 			    if(innerlayers_mu1_muJetC>0 && innerlayers_mu2_muJetC>0){
			
      // 			      for(int k=0;k<min(innerlayers_mu1_muJetC,innerlayers_mu2_muJetC);k++){
      // 				for(int h=0;h<min(compdet_mu1_muJetC[k],compdet_mu2_muJetC[k]);h++){
      // 				  muon1posx = mj1m0posx[k][h];
      // 				  muon1posy = mj1m0posy[k][h];
      // 				  muon2posx = mj1m1posx[k][h];
      // 				  muon2posy = mj1m1posy[k][h];
				
      // 				  for(int j=0;j<numhit_mu1_muJetC[k];j++) hitposx[j] = pixelhit_mu1_muJetC_posx[k][j];
      // 				  for(int j=0;j<numhit_mu1_muJetC[k];j++) hitposy[j] = pixelhit_mu1_muJetC_posy[k][j];
			  
      // 				  passingC += BikeChain(numhit_mu1_muJetC[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
      // 				}
      // 			      }
      // 			    }
      // 			    if(innerlayers_mu1_muJetF>0 && innerlayers_mu2_muJetF>0){
			
      // 			      for(int k=0;k<min(innerlayers_mu1_muJetF,innerlayers_mu2_muJetF);k++){
      // 				for(int h=0;h<min(compdet_mu1_muJetF[k],compdet_mu2_muJetF[k]);h++){
      // 				  muon1posx = mj2m0posx[k][h];
      // 				  muon1posy = mj2m0posy[k][h];
      // 				  muon2posx = mj2m1posx[k][h];
      // 				  muon2posy = mj2m1posy[k][h];
				  
      // 				  for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposx[j] = pixelhit_mu1_muJetF_posx[k][j];
      // 				  for(int j=0;j<numhit_mu1_muJetF[k];j++) hitposy[j] = pixelhit_mu1_muJetF_posy[k][j];
				  
      // 				  passingF += BikeChain(numhit_mu1_muJetF[k],hitposx,hitposy,muon1posx,muon1posy,muon2posx,muon2posy,radius_rec);
      // 				}
      // 			      }
      // 			    }
      // 			    if(passingC>0&&passingF>0) count_recovermuJetCANDF[p]++;
      // 			  }
      // 			}
      // 		      }
      // 		    }
      // 		  }
      // 		}
      // 	      }
      // 	    }
      // 	  }
      // 	}
      // }
    }
      
  //   cout<<" Total Events            "<<totev[p]<<endl;
  //   cout<<" Gen (fiducial)          "<<count_gen[p]<<endl;
  //   cout<<" is4SelMu8               "<<count_is4SelMu8[p]<<"     Rel. Eff  "<<count_is4SelMu8[p]/(1.0*totev[p])<<endl;
  //   cout<<" is2DiMuons              "<<count_is2DiMuons[p]<<"    Rel. Eff  "<<count_is2DiMuons[p]/(1.0*count_is4SelMu8[p])<<endl;
  //   cout<<" is2DiMuonsFittedVtxOK   "<<count_is2DiMuonsFittedVtxOK[p]<<"    Rel. Eff  "<<count_is2DiMuonsFittedVtxOK[p]/(1.0*count_is2DiMuons[p])<<endl;
  //   cout<<" isDiMuonHLTFired        "<<count_isDiMuonHLTFired[p]<<"     Rel. Eff  "<<count_isDiMuonHLTFired[p]/(1.0*count_is2DiMuonsFittedVtxOK[p])<<endl;
  //   cout<<" is2DiMuonsMassOK        "<<count_is2DiMuonsMassOK[p]<<"     Rel. Eff  "<<count_is2DiMuonsMassOK[p]/(1.0*count_isDiMuonHLTFired[p])<<endl;
  //   cout<<" IsoTk                   "<<count_IsoTk[p]<<"     Rel. Eff  "<<count_IsoTk[p]/(1.0*count_is2DiMuonsMassOK[p])<<endl;
  //   cout<<" dz                      "<<count_dz[p]<<"      Rel. Eff   "<<count_dz[p]/(1.0*count_IsoTk[p])<<endl;
  //   cout<<" fakem                   "<<count_fakemit[p]<<"      Rel. Eff   "<<count_fakemit[p]/(1.0*count_dz[p])<<endl;
  //   cout<<" pixelhit                "<<count_pixelhit[p]<<"     Rel. Eff "<<count_pixelhit[p]/(1.0*count_fakemit[p])<<endl;
  //   cout<<"  eps/alpha              "<<count_pixelhit[p]/(1.0*count_gen[p])<<endl;
  //   cout<<"====================================="<<endl;
  //   cout<<"==== PHR ============================"<<endl;
  //   cout<<" rec events               "<<count_rec[p]<<endl;
  //   cout<<" rec events fail          "<<count_rec_fail[p]<<endl;
  //   cout<<" fail MuJetCORF           "<<fail_mujetCORF<<endl;
  //   cout<<" fail MuJetC              "<<fail_mujetC<<endl;
  //   cout<<" fail MuJetF              "<<fail_mujetF<<endl;
  //   cout<<" fail MuJetCANDF          "<<fail_mujetCANDF<<endl;
  //   cout<<"  recovered events C      "<<count_recovermuJetC[p]<<endl;
  //   cout<<"  recovered events F      "<<count_recovermuJetF[p]<<endl;
  //   cout<<"  recovered events CANDF  "<<count_recovermuJetCANDF[p]<<endl;
  // }

  // Float_t ctau[7]={0.0,0.05,0.1,0.5,1.0,3.0,5.0};
  // Float_t eps_recovsalpha[7]={0.0};
  // Float_t eps_recovsalpha_recover[7]={0.0};
  
  // Float_t count_rec_plusrecover[7]={0.0};
  
  // for(int l=0;l<7;l++){
  //   count_rec_plusrecover[l] = count_rec[l]+(count_recovermuJetC[l]+count_recovermuJetF[l]+count_recovermuJetCANDF[l]);
  //   eps_recovsalpha[l] = count_rec[l]/(1.0*count_gen[l]);
  //   eps_recovsalpha_recover[l] = count_rec_plusrecover[l]/(1.0*count_gen[l]);
  // }
  
  // TGraph *gr_eps = new TGraph(7,ctau,eps_recovsalpha);
  // TGraph *gr_eps_recover = new TGraph(7,ctau,eps_recovsalpha_recover);
  
  // TH2F *dummy3 = new TH2F("","",100,-0.2,5.2,100,0.0,1.0);
  
  
  // TCanvas *c = new TCanvas("c","c",700,500);
  // dummy3->GetXaxis()->SetTitle("c#tau [mm]");
  // dummy3->GetYaxis()->SetTitle("#epsilon_{rec}/#alpha_{gen}");
  // dummy3->Draw();
  // gr_eps->Draw("PL");
  // gr_eps_recover->Draw("PL");
  // gr_eps_recover->SetLineStyle(2);
  // c->SaveAs("ratio_mD025.pdf","recreate");
  // c->SaveAs("ratio_mD025.png","recreate");
  }
}


#ifndef __CINT__

int main(){


  std::vector< std::vector<string> > DarkSUSY_mH_125_mGammaD_v;
  readTextFileWithSamples("/fdata/hepx/store/user/bmichlin/ExtFidCut_UnHardCodeCuts_ONLY_0250_SampleList.txt", DarkSUSY_mH_125_mGammaD_v);
  cout << "Samples read" << endl;
  for(auto v: DarkSUSY_mH_125_mGammaD_v) cutflow(v);
  cout << "For Loop completes" << endl;


}

#endif
