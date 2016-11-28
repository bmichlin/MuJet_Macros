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
//Plot initialization
//{{{

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

Int_t counter_gen[60][10];
Int_t counter_genlxylz[60][10];
Int_t counter_genlxylz2[60][10];
Int_t counter_rec[60][10];
Int_t counter_rec_hits[60][10];
Int_t counter_rec_dimuons[60][10];
Int_t counter_rec_dimuons2[60][10];
vector< double > ct_vector;
void setup(){
	for(int k=0;k<49;k++){
		for(int j=0;j<10;j++){
			counter_gen[k][j]=0.0;
			counter_genlxylz[k][j]=0.0;
			counter_genlxylz2[k][j]=0.0;
			counter_rec[k][j]=0.0;
			counter_rec_hits[k][j]=0.0;
			counter_rec_dimuons[k][j]=0.0;
			counter_rec_dimuons2[k][j]=0.0;
		}
	}
	ct_vector.clear();
}



double My_dPhi (double phi1, double phi2) {
	double dPhi = phi1 - phi2;
	if (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
	if (dPhi <  -TMath::Pi()) dPhi += 2*TMath::Pi();
	return abs(dPhi); //Changed to abs 1/5/2016
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


void makeLatex4(double sample_mass_double, double cTDouble0, double cTDouble1, double cTDouble2, double cTDouble3){
	char buf[456];
	char pattern[] =  "%18s %2s %12s %2s %12s %2s %12s %2s %12s %2s %12s %2s %12s %2s %12s %2s %12s %2s";
	char pattern2[] = "%30s %2s %12.3d %2s %12.3f %s %12.3f %2s %12.3d %2s %12.3f %s %12.3f %2s %12.3d %2s %12.3f %s %12.3f %2s %12.3d %2s %12.3f %s %12.3f %2s";
	char pattern4[] = "%18s %2s %2s %12.4f %12.4f %2s %2s %12.4f %12.4f %2s %2s %12.4f %12.4f %2s %2s %12.4f %12.4f %2s";
	char pattern3[] = "%50s";


	const char* const sample_mass[8]={"0.25","0.275","0.3","0.4","0.7","1.0", "2.0", "8.5"};
	const char* const sample_cT[12]={"0","0.05","0.1","0.2","0.5","1.0", "2.0", "3.0", "5.0", "10.0", "20.0", "100.0"};
	const char cutsgen0[11] = "All events";
	const char* const cutsgen[6]={"All events","$p_{T_1} > 17$ GeV, $|\\eta|< 0.9$", "$p_{T_2} > 8$ GeV,  $|\\eta|< 2.4$", "$p_{T_3} > 8$ GeV,  $|\\eta|< 2.4$", "$p_{T_4} > 8$ GeV,  $|\\eta|< 2.4$", "$L_{xy} < 9.8$ cm, $L_{z} < 48.5$ cm"};
	//const char* const cutsrec[4]={"1Rec\\_pT17\\_eta09","2Rec\\_pT8","3Rec\\_pT8","4Rec\\_pt8"};
	const char* const cutsrec[4]={"$p_{T_1} > 17$ GeV, $|\\eta|< 0.9$", "$p_{T_2} > 8$ GeV, $|\\eta|< 2.4$", "$p_{T_3} > 8$ GeV, $|\\eta|< 2.4$", "$p_{T_4} > 8$ GeV, $|\\eta|< 2.4$"};
	//const char* const cutsdim[7]={"2$\\mu_{jet}$","2$\\mu/\\mu_{jet}$","$hit_{1st pixel}$","$|\\Delta z|<0.1$","$trigger$","$mass compat.$","$Iso_{\\mu}<2 GeV$"};
	const char* const cutsdim[7]={"$N$($\\mu$-jets) $= 2$", "2$\\mu$ per $\\mu$-jet", "Inclusive hit in BPIX3/FPIX2", "$|\\Delta z|<0.1$", "$m_{\\mu\\mu_1} \\approx m_{\\mu\\mu_2}$", "$\\mu$-jet isolation $ <2$", "Fired HLT"};

	Int_t indx[4];

	cout<<"\\begin{landscape}    " << endl;
	cout<<"\\begin{table}[ht]         "<<endl;
	cout<<"\\renewcommand{\\tabcolsep}{2pt}" << endl;
	printf("\\caption{Acceptances and efficiencies (all in \\%) of the event selection requirements for several representative benchmark values of $c \\tau$ for fixed masses $m_{h_{1}} = 125$~GeV$/c^{2}$, $m_{n_{1}} = 10$~GeV$/c^{2}$,  $m_{n_{D}} = 1$~GeV$/c^{2}$ and $m_{\\gamma_D}= %2.3f $ GeV$/c^{2}$ in MC simulation of Dark SUSY signal. \\label{tab:eff_darkSUSY_mGammaD%2.3f}}", sample_mass_double, sample_mass_double);
	cout << "" << endl;
	cout<<"\\centering               "<<endl;
	cout<<"\\begin{tabular}{|l|c|c|c|c|c|c|c|c|c|c|c|c|} \\hline  "<<endl;
	printf("$m_{\gamma_D}=%2.3f$GeV & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm} & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm} & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm} & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm}   \\\\ \\hline", sample_mass_double, cTDouble0, cTDouble1, cTDouble2, cTDouble3);	
	cout << "" << endl;
	cout << "Selection  &  $N_{evts}$  &  Rel. Eff(\\%)  &  $N_{evts}$  &  Rel. Eff(\\%)  &  $N_{evts}$  &  Rel. Eff(\\%)  &$N_{evts}$&Rel. Eff(\\%) \\\\ \\hline" << endl;

	indx[0]=0;indx[1]=1;indx[2]=2;indx[3]=3; 
	printf("All events&%12.3d&&%12.3d&&%12.3d&&%12.3d& \\\\ \\hline",counter_gen[indx[0]][0], counter_gen[indx[1]][0], counter_gen[indx[2]][0], counter_gen[indx[3]][0]);

	cout << "\\multicolumn{2}{|c}{\\textbf{Basic event selections (gen):}} \\\\ \\hline" << endl;
	for(int j=1;j<5;j++){ //changed from 6 -> 5 for Lxy line

		sprintf(buf,pattern2,cutsgen[j],"&",counter_gen[indx[0]][j],"&",counter_gen[indx[0]][j]/(counter_gen[indx[0]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[0]][j]/(counter_gen[indx[0]][j-1]*1.0))*(1-(counter_gen[indx[0]][j]/(counter_gen[indx[0]][j-1]*1.0))))/(counter_gen[indx[0]][j-1]*1.0)),"&",counter_gen[indx[1]][j],"&",counter_gen[indx[1]][j]/(counter_gen[indx[1]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[1]][j]/(counter_gen[indx[1]][j-1]*1.0))*(1-(counter_gen[indx[1]][j]/(counter_gen[indx[1]][j-1]*1.0))))/(counter_gen[indx[1]][j-1]*1.0)),"&",counter_gen[indx[2]][j],"&",counter_gen[indx[2]][j]/(counter_gen[indx[2]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[2]][j]/(counter_gen[indx[2]][j-1]*1.0))*(1-(counter_gen[indx[2]][j]/(counter_gen[indx[2]][j-1]*1.0))))/(counter_gen[indx[2]][j-1]*1.0)),"&",counter_gen[indx[3]][j],"&",counter_gen[indx[3]][j]/(counter_gen[indx[3]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[3]][j]/(counter_gen[indx[3]][j-1]*1.0))*(1-(counter_gen[indx[3]][j]/(counter_gen[indx[3]][j-1]*1.0))))/(counter_gen[indx[3]][j-1]*1.0)),"\\\\");
		cout<<buf<<endl;
	}
	int j =0;
//This is the Lxy line.  

    sprintf(buf,pattern2,cutsgen[5],"&",counter_genlxylz2[indx[0]][4],"&",counter_genlxylz2[indx[0]][4]/(counter_gen[indx[0]][4]*1.0),"$\\pm$", sqrt(counter_genlxylz2[indx[0]][4]*(counter_genlxylz2[indx[0]][4]+(counter_gen[indx[0]][4]*1.0))/pow((counter_gen[indx[0]][4]*1.0),3)),"&",counter_genlxylz2[indx[1]][4],"&",counter_genlxylz2[indx[1]][4]/(counter_gen[indx[1]][4]*1.0),"$\\pm$",sqrt(counter_genlxylz2[indx[1]][4]*(counter_genlxylz2[indx[1]][4]+(counter_gen[indx[1]][4]*1.0))/pow((counter_gen[indx[1]][4]*1.0),3)),"&",counter_genlxylz2[indx[2]][4],"&",counter_genlxylz2[indx[2]][4]/(counter_gen[indx[2]][4]*1.0),"$\\pm$",sqrt(counter_genlxylz2[indx[2]][4]*(counter_genlxylz2[indx[2]][4]+(counter_gen[indx[2]][4]*1.0))/pow((counter_gen[indx[2]][4]*1.0),3)),"&",counter_genlxylz2[indx[3]][4],"&",counter_genlxylz2[indx[3]][4]/(counter_gen[indx[3]][4]*1.0),"$\\pm$",sqrt(counter_genlxylz2[indx[3]][4]*(counter_genlxylz2[indx[3]][4]+(counter_gen[indx[3]][4]*1.0))/pow((counter_gen[indx[3]][4]*1.0),3)) ,"\\\\");

	cout<<buf<<endl;
	cout << "\\hline" << endl;	
	cout << "\\multicolumn{2}{|c}{\\textbf{Basic event selections (reco):}} \\\\ \\hline" << endl;

	for(int j=0;j<4;j++){
		if(j==0) sprintf(buf,pattern2,cutsrec[j],"&",counter_rec[indx[0]][j],"&",counter_rec[indx[0]][j]/(counter_gen[indx[0]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[0]][j]/(counter_gen[indx[0]][j]*1.0))*(1-(counter_rec[indx[0]][j]/(counter_gen[indx[0]][j]*1.0))))/(counter_gen[indx[0]][j]*1.0)),"&",counter_rec[indx[1]][j],"&",counter_rec[indx[1]][j]/(counter_gen[indx[1]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[1]][j]/(counter_gen[indx[1]][j]*1.0))*(1-(counter_rec[indx[1]][j]/(counter_gen[indx[1]][j]*1.0))))/(counter_gen[indx[1]][j]*1.0)),"&",counter_rec[indx[2]][j],"&",counter_rec[indx[2]][j]/(counter_gen[indx[2]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[2]][j]/(counter_gen[indx[2]][j]*1.0))*(1-(counter_rec[indx[2]][j]/(counter_gen[indx[2]][j]*1.0))))/(counter_gen[indx[2]][j]*1.0)),"&",counter_rec[indx[3]][j],"&",counter_rec[indx[3]][j]/(counter_gen[indx[3]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[3]][j]/(counter_gen[indx[3]][j]*1.0))*(1-(counter_rec[indx[3]][j]/(counter_gen[indx[3]][j]*1.0))))/(counter_gen[indx[3]][j]*1.0)),"\\\\");
		if(j>0) sprintf(buf,pattern2,cutsrec[j],"&",counter_rec[indx[0]][j],"&",counter_rec[indx[0]][j]/(counter_rec[indx[0]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[0]][j]/(counter_rec[indx[0]][j-1]*1.0))*(1-(counter_rec[indx[0]][j]/(counter_rec[indx[0]][j-1]*1.0))))/(counter_rec[indx[0]][j-1]*1.0)),"&",counter_rec[indx[1]][j],"&",counter_rec[indx[1]][j]/(counter_rec[indx[1]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[1]][j]/(counter_rec[indx[1]][j-1]*1.0))*(1-(counter_rec[indx[1]][j]/(counter_rec[indx[1]][j-1]*1.0))))/(counter_rec[indx[1]][j-1]*1.0)),"&",counter_rec[indx[2]][j],"&",counter_rec[indx[2]][j]/(counter_rec[indx[2]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[2]][j]/(counter_rec[indx[2]][j-1]*1.0))*(1-(counter_rec[indx[2]][j]/(counter_rec[indx[2]][j-1]*1.0))))/(counter_rec[indx[2]][j-1]*1.0)),"&",counter_rec[indx[3]][j],"&",counter_rec[indx[3]][j]/(counter_rec[indx[3]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[3]][j]/(counter_rec[indx[3]][j-1]*1.0))*(1-(counter_rec[indx[3]][j]/(counter_rec[indx[3]][j-1]*1.0))))/(counter_rec[indx[3]][j-1]*1.0)),"\\\\");
		cout<<buf<<endl;
	}
	cout << "\\hline" << endl;
	cout << "\\multicolumn{2}{|c}{\\textbf{Auxiliary event selections (reco):}} \\\\ \\hline" << endl;
	for(int j=0;j<7;j++){
		sprintf(buf,pattern2,cutsdim[j],"&",counter_rec_dimuons[indx[0]][j],"&",counter_rec_dimuons[indx[0]][j]/(counter_rec[indx[0]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[0]][j]/(counter_rec[indx[0]][3]*1.0))*(1-(counter_rec_dimuons[indx[0]][j]/(counter_rec[indx[0]][3]*1.0))))/(counter_rec[indx[0]][3]*1.0)),"&",counter_rec_dimuons[indx[1]][j],"&",counter_rec_dimuons[indx[1]][j]/(counter_rec[indx[1]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[1]][j]/(counter_rec[indx[1]][3]*1.0))*(1-(counter_rec_dimuons[indx[1]][j]/(counter_rec[indx[1]][3]*1.0))))/(counter_rec[indx[1]][3]*1.0)),"&",counter_rec_dimuons[indx[2]][j],"&",counter_rec_dimuons[indx[2]][j]/(counter_rec[indx[2]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[2]][j]/(counter_rec[indx[2]][3]*1.0))*(1-(counter_rec_dimuons[indx[2]][j]/(counter_rec[indx[2]][3]*1.0))))/(counter_rec[indx[2]][3]*1.0)),"&",counter_rec_dimuons[indx[3]][j],"&",counter_rec_dimuons[indx[3]][j]/(counter_rec[indx[3]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[3]][j]/(counter_rec[indx[3]][3]*1.0))*(1-(counter_rec_dimuons[indx[3]][j]/(counter_rec[indx[3]][3]*1.0))))/(counter_rec[indx[3]][3]*1.0)),"\\\\");

		cout<<buf<<endl;
	}
	//ratio
	cout << "\\hline" << endl;
	cout <<""<<endl;
	printf("$\\alpha_{gen}$&&%12.5f $\\pm$ %12.5f && %12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f \\\\", counter_genlxylz2[indx[0]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[0]][4])*(counter_genlxylz2[indx[0]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ), counter_genlxylz2[indx[1]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[1]][4])*(counter_genlxylz2[indx[1]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3)) )), counter_genlxylz2[indx[2]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[2]][4])*(counter_genlxylz2[indx[2]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ), counter_genlxylz2[indx[3]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[3]][4])*(counter_genlxylz2[indx[3]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) )  );
	cout << "" << endl;

	printf("$\\epsilon_{full}$&&%12.5f $\\pm$ %12.5f && %12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f \\\\", counter_rec_dimuons[indx[0]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[0]][6])*(counter_rec_dimuons[indx[0]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ), counter_rec_dimuons[indx[1]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[1]][6])*(counter_rec_dimuons[indx[1]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3)) )), counter_rec_dimuons[indx[2]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[2]][6])*(counter_rec_dimuons[indx[2]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ), counter_rec_dimuons[indx[3]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[3]][6])*(counter_rec_dimuons[indx[3]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ));
	cout<<"  \\hline  "<<endl;

	printf("$\\epsilon_{full}/\\alpha_{gen}$&&%12.5f $\\pm$ %12.5f && %12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f \\\\", (counter_rec_dimuons[indx[0]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[0]][4]/(1.0*counter_gen[indx[0]][0])),sqrt( ((counter_rec_dimuons[0][6]/(1.0*counter_genlxylz2[0][4]))*(1- (counter_rec_dimuons[0][6]/(1.0*counter_genlxylz2[0][4])) ))/(1.0*counter_genlxylz2[0][4])) , (counter_rec_dimuons[indx[1]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[1]][4]/(1.0*counter_gen[indx[0]][0])), sqrt( ((counter_rec_dimuons[1][6]/(1.0*counter_genlxylz2[1][4]))*(1- (counter_rec_dimuons[1][6]/(1.0*counter_genlxylz2[1][4])) ))/(1.0*counter_genlxylz2[1][4])), (counter_rec_dimuons[indx[2]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[2]][4]/(1.0*counter_gen[indx[0]][0])),sqrt( ((counter_rec_dimuons[2][6]/(1.0*counter_genlxylz2[2][4]))*(1- (counter_rec_dimuons[2][6]/(1.0*counter_genlxylz2[2][4])) ))/(1.0*counter_genlxylz2[2][4])) , (counter_rec_dimuons[indx[3]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[3]][4]/(1.0*counter_gen[indx[0]][0])),  sqrt( ((counter_rec_dimuons[3][6]/(1.0*counter_genlxylz2[3][4]))*(1- (counter_rec_dimuons[3][6]/(1.0*counter_genlxylz2[3][4])) ))/(1.0*counter_genlxylz2[3][4]))  );

	cout <<""<<endl;
	cout << "\\hline" << endl;
	cout<<"\\end{tabular} "<<endl;
	cout<<"\\end{table} "<<endl;


	cout<<"\\end{landscape}    " << endl;
}

////





////

void makeLatex(double sample_mass_double, double cTDouble0, double cTDouble1, double cTDouble2){

	char buf[456];
	char pattern2[] = "%30s %2s %12.3d %2s %12.3f %s %12.3f %2s %12.3d %2s %12.3f %s %12.3f %2s %12.3d %2s %12.3f %s %12.3f %2s";


	const char* const sample_mass[8]={"0.25","0.275","0.3","0.4","0.7","1.0", "2.0", "8.5"};
	const char* const sample_cT[12]={"0","0.05","0.1","0.2","0.5","1.0", "2.0", "3.0", "5.0", "10.0", "20.0", "100.0"};
	const char cutsgen0[11] = "All events";
	const char* const cutsgen[6]={"All events","$p_{T_1} > 17$ GeV, $|\\eta|< 0.9$", "$p_{T_2} > 8$ GeV,  $|\\eta|< 2.4$", "$p_{T_3} > 8$ GeV,  $|\\eta|< 2.4$", "$p_{T_4} > 8$ GeV,  $|\\eta|< 2.4$", "$L_{xy} < 9.8$ cm, $L_{z} < 48.5$ cm"};
	//const char* const cutsrec[4]={"1Rec\\_pT17\\_eta09","2Rec\\_pT8","3Rec\\_pT8","4Rec\\_pt8"};
	const char* const cutsrec[4]={"$p_{T_1} > 17$ GeV, $|\\eta|< 0.9$", "$p_{T_2} > 8$ GeV, $|\\eta|< 2.4$", "$p_{T_3} > 8$ GeV, $|\\eta|< 2.4$", "$p_{T_4} > 8$ GeV, $|\\eta|< 2.4$"};
	//const char* const cutsdim[7]={"2$\\mu_{jet}$","2$\\mu/\\mu_{jet}$","$hit_{1st pixel}$","$|\\Delta z|<0.1$","$trigger$","$mass compat.$","$Iso_{\\mu}<2 GeV$"};
	const char* const cutsdim[7]={"$N$($\\mu$-jets) $= 2$", "2$\\mu$ per $\\mu$-jet", "Inclusive hit in BPIX3/FPIX2", "$|\\Delta z|<0.1$", "$m_{\\mu\\mu_1} \\approx m_{\\mu\\mu_2}$", "$\\mu$-jet isolation $ <2$", "Fired HLT"};

	Int_t indx[4];

	cout<<"\\begin{landscape}    " << endl;
	cout<<"\\begin{table}[ht]         "<<endl;
	cout<<"\\renewcommand{\\tabcolsep}{2pt}" << endl;
	printf("\\caption{Acceptances and efficiencies (all in \\%) of the event selection requirements for several representative benchmark values of $c \\tau$ for fixed masses $m_{h_{1}} = 125$~GeV$/c^{2}$, $m_{n_{1}} = 10$~GeV$/c^{2}$,  $m_{n_{D}} = 1$~GeV$/c^{2}$ and $m_{\\gamma_D}= %2.3f $ GeV$/c^{2}$ in MC simulation of Dark SUSY signal. \\label{tab:eff_darkSUSY_mGammaD%2.3f}}", sample_mass_double, sample_mass_double);
	cout << "" << endl;
	cout<<"\\centering               "<<endl;
	cout<<"\\begin{tabular}{|l|c|c|c|c|c|c|c|c|c|} \\hline  "<<endl;
	printf("$m_{\gamma_D}=%2.3f$GeV & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm} & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm} & \\multicolumn{2}{c|}{c$\\tau$=%2.2fmm}  \\\\ \\hline", sample_mass_double, cTDouble0, cTDouble1, cTDouble2);	
	cout << "" << endl;
	cout << "Selection  &  $N_{evts}$  &  Rel. Eff(\\%)  &  $N_{evts}$  &  Rel. Eff(\\%)  &  $N_{evts}$  &  Rel. Eff(\\%)   \\\\ \\hline" << endl;

	indx[0]=0;indx[1]=1;indx[2]=2;indx[3]=3; 
	printf("All events&%12.3d&&%12.3d&&%12.3d& \\\\ \\hline",counter_gen[indx[0]][0], counter_gen[indx[1]][0], counter_gen[indx[2]][0]);

	cout << "\\multicolumn{2}{|c}{\\textbf{Basic event selections (gen):}} \\\\ \\hline" << endl;
	for(int j=1;j<5;j++){ //changed from 6 -> 5 for Lxy line

		sprintf(buf,pattern2,cutsgen[j],"&",counter_gen[indx[0]][j],"&",counter_gen[indx[0]][j]/(counter_gen[indx[0]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[0]][j]/(counter_gen[indx[0]][j-1]*1.0))*(1-(counter_gen[indx[0]][j]/(counter_gen[indx[0]][j-1]*1.0))))/(counter_gen[indx[0]][j-1]*1.0)),"&",counter_gen[indx[1]][j],"&",counter_gen[indx[1]][j]/(counter_gen[indx[1]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[1]][j]/(counter_gen[indx[1]][j-1]*1.0))*(1-(counter_gen[indx[1]][j]/(counter_gen[indx[1]][j-1]*1.0))))/(counter_gen[indx[1]][j-1]*1.0)),"&",counter_gen[indx[2]][j],"&",counter_gen[indx[2]][j]/(counter_gen[indx[2]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_gen[indx[2]][j]/(counter_gen[indx[2]][j-1]*1.0))*(1-(counter_gen[indx[2]][j]/(counter_gen[indx[2]][j-1]*1.0))))/(counter_gen[indx[2]][j-1]*1.0)),"\\\\");
		cout<<buf<<endl;
	}
	int j =0;
//This is the Lxy line
	sprintf(buf,pattern2,cutsgen[5],"&",counter_genlxylz2[indx[0]][4],"&",counter_genlxylz2[indx[0]][4]/(counter_gen[indx[0]][4]*1.0),"$\\pm$", sqrt(counter_genlxylz2[indx[0]][4]*(counter_genlxylz2[indx[0]][4]+(counter_gen[indx[0]][4]*1.0))/pow((counter_gen[indx[0]][4]*1.0),3)),"&",counter_genlxylz2[indx[1]][4],"&",counter_genlxylz2[indx[1]][4]/(counter_gen[indx[1]][4]*1.0),"$\\pm$",sqrt(counter_genlxylz2[indx[1]][4]*(counter_genlxylz2[indx[1]][4]+(counter_gen[indx[1]][4]*1.0))/pow((counter_gen[indx[1]][4]*1.0),3)),"&",counter_genlxylz2[indx[2]][4],"&",counter_genlxylz2[indx[2]][4]/(counter_gen[indx[2]][4]*1.0),"$\\pm$",sqrt(counter_genlxylz2[indx[2]][4]*(counter_genlxylz2[indx[2]][4]+(counter_gen[indx[2]][4]*1.0))/pow((counter_gen[indx[2]][4]*1.0),3)),"\\\\");
	cout<<buf<<endl;
	cout << "\\hline" << endl;	
	cout << "\\multicolumn{2}{|c}{\\textbf{Basic event selections (reco):}} \\\\ \\hline" << endl;

	for(int j=0;j<4;j++){
		if(j==0) sprintf(buf,pattern2,cutsrec[j],"&",counter_rec[indx[0]][j],"&",counter_rec[indx[0]][j]/(counter_gen[indx[0]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[0]][j]/(counter_gen[indx[0]][j]*1.0))*(1-(counter_rec[indx[0]][j]/(counter_gen[indx[0]][j]*1.0))))/(counter_gen[indx[0]][j]*1.0)),"&",counter_rec[indx[1]][j],"&",counter_rec[indx[1]][j]/(counter_gen[indx[1]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[1]][j]/(counter_gen[indx[1]][j]*1.0))*(1-(counter_rec[indx[1]][j]/(counter_gen[indx[1]][j]*1.0))))/(counter_gen[indx[1]][j]*1.0)),"&",counter_rec[indx[2]][j],"&",counter_rec[indx[2]][j]/(counter_gen[indx[2]][j]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[2]][j]/(counter_gen[indx[2]][j]*1.0))*(1-(counter_rec[indx[2]][j]/(counter_gen[indx[2]][j]*1.0))))/(counter_gen[indx[2]][j]*1.0)),"\\\\");

		if(j>0) sprintf(buf,pattern2,cutsrec[j],"&",counter_rec[indx[0]][j],"&",counter_rec[indx[0]][j]/(counter_rec[indx[0]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[0]][j]/(counter_rec[indx[0]][j-1]*1.0))*(1-(counter_rec[indx[0]][j]/(counter_rec[indx[0]][j-1]*1.0))))/(counter_rec[indx[0]][j-1]*1.0)),"&",counter_rec[indx[1]][j],"&",counter_rec[indx[1]][j]/(counter_rec[indx[1]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[1]][j]/(counter_rec[indx[1]][j-1]*1.0))*(1-(counter_rec[indx[1]][j]/(counter_rec[indx[1]][j-1]*1.0))))/(counter_rec[indx[1]][j-1]*1.0)),"&",counter_rec[indx[2]][j],"&",counter_rec[indx[2]][j]/(counter_rec[indx[2]][j-1]*1.0),"$\\pm$",sqrt( ( (counter_rec[indx[2]][j]/(counter_rec[indx[2]][j-1]*1.0))*(1-(counter_rec[indx[2]][j]/(counter_rec[indx[2]][j-1]*1.0))))/(counter_rec[indx[2]][j-1]*1.0)),"\\\\");
		cout<<buf<<endl;
	}
	cout << "\\hline" << endl;
	cout << "\\multicolumn{2}{|c}{\\textbf{Auxiliary event selections (reco):}} \\\\ \\hline" << endl;
	for(int j=0;j<7;j++){
		sprintf(buf,pattern2,cutsdim[j],"&",counter_rec_dimuons[indx[0]][j],"&",counter_rec_dimuons[indx[0]][j]/(counter_rec[indx[0]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[0]][j]/(counter_rec[indx[0]][3]*1.0))*(1-(counter_rec_dimuons[indx[0]][j]/(counter_rec[indx[0]][3]*1.0))))/(counter_rec[indx[0]][3]*1.0)),"&",counter_rec_dimuons[indx[1]][j],"&",counter_rec_dimuons[indx[1]][j]/(counter_rec[indx[1]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[1]][j]/(counter_rec[indx[1]][3]*1.0))*(1-(counter_rec_dimuons[indx[1]][j]/(counter_rec[indx[1]][3]*1.0))))/(counter_rec[indx[1]][3]*1.0)),"&",counter_rec_dimuons[indx[2]][j],"&",counter_rec_dimuons[indx[2]][j]/(counter_rec[indx[2]][3]*1.0),"$\\pm$",sqrt( ( (counter_rec_dimuons[indx[2]][j]/(counter_rec[indx[2]][3]*1.0))*(1-(counter_rec_dimuons[indx[2]][j]/(counter_rec[indx[2]][3]*1.0))))/(counter_rec[indx[2]][3]*1.0)),"\\\\");

		cout<<buf<<endl;
	}
	//ratio
	cout << "\\hline" << endl;
	cout <<""<<endl;
	printf("$\\alpha_{gen}$&&%12.5f $\\pm$ %12.5f && %12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f \\\\", counter_genlxylz2[indx[0]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[0]][4])*(counter_genlxylz2[indx[0]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ), counter_genlxylz2[indx[1]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[1]][4])*(counter_genlxylz2[indx[1]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3)) )), counter_genlxylz2[indx[2]][4]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_genlxylz2[indx[2]][4])*(counter_genlxylz2[indx[2]][4]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) )  );
	cout << "" << endl;

	printf("$\\epsilon_{full}$&&%12.5f $\\pm$ %12.5f && %12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f  \\\\", counter_rec_dimuons[indx[0]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[0]][6])*(counter_rec_dimuons[indx[0]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ), counter_rec_dimuons[indx[1]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[1]][6])*(counter_rec_dimuons[indx[1]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3)) )), counter_rec_dimuons[indx[2]][6]/(1.0*counter_gen[indx[0]][0]), sqrt( (counter_rec_dimuons[indx[2]][6])*(counter_rec_dimuons[indx[2]][6]+counter_gen[indx[0]][0])/(1.0*(pow(counter_gen[indx[0]][0],3))) ));
	cout<<"  \\hline  "<<endl;

	printf("$\\epsilon_{full}/\\alpha_{gen}$&&%12.5f $\\pm$ %12.5f && %12.5f $\\pm$ %12.5f &&%12.5f $\\pm$ %12.5f  \\\\", (counter_rec_dimuons[indx[0]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[0]][4]/(1.0*counter_gen[indx[0]][0])),sqrt( ((counter_rec_dimuons[0][6]/(1.0*counter_genlxylz2[0][4]))*(1- (counter_rec_dimuons[0][6]/(1.0*counter_genlxylz2[0][4])) ))/(1.0*counter_genlxylz2[0][4])) , (counter_rec_dimuons[indx[1]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[1]][4]/(1.0*counter_gen[indx[0]][0])), sqrt( ((counter_rec_dimuons[1][6]/(1.0*counter_genlxylz2[1][4]))*(1- (counter_rec_dimuons[1][6]/(1.0*counter_genlxylz2[1][4])) ))/(1.0*counter_genlxylz2[1][4])), (counter_rec_dimuons[indx[2]][6]/(1.0*counter_gen[indx[0]][0]))/(counter_genlxylz2[indx[2]][4]/(1.0*counter_gen[indx[0]][0])),sqrt( ((counter_rec_dimuons[2][6]/(1.0*counter_genlxylz2[2][4]))*(1- (counter_rec_dimuons[2][6]/(1.0*counter_genlxylz2[2][4])) ))/(1.0*counter_genlxylz2[2][4])));

	cout <<""<<endl;
	cout << "\\hline" << endl;
	cout<<"\\end{tabular} "<<endl;
	cout<<"\\end{table} "<<endl;
	cout<<"\\end{landscape}    " << endl;
}

///

int p = -1;
void efficiency_hitrecovery(const std::vector<std::string>& dirNames){
	bool verbose(false);
	//	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

	decodeFileNameMany(dirNames, mass_string, cT_string);
	//fileName = "DarkSUSY_mH_125_mGammaD_" + mass_string + "_cT_" + cT_string;

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
	Float_t diMuons_dz_FittedVtx;
	Bool_t isDiMuonHLTFired;
	Bool_t is2DiMuonsMassOK_FittedVtx;
	//Bool_t is2DiMuonsIsoTkOK_FittedVtx;
	Float_t diMuonF_IsoTk_FittedVtx;
	Float_t diMuonC_IsoTk_FittedVtx;
	Bool_t isVertexOK;

	Float_t genA0_Lxy_rdet;
	Float_t genA1_Lxy_rdet;
	Float_t genA0_Lz_rdet;
	Float_t genA1_Lz_rdet;


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

	//============= Counters ===========================//


	Int_t ev_all = 0;
	Int_t ev_isVtxOK = 0;
	Int_t ev_is2MuJets = 0;
	Int_t ev_is2DiMuons = 0;
	Int_t ev_is2DiMuonsFittedVtxOK = 0;
	Int_t ev_isPixelHitOK = 0;
	Int_t ev_is2DiMuonsMassOK_FittedVtx = 0;
	Int_t ev_isDiMuonHLTFired = 0;

	Int_t c1genm = 0;
	Int_t c2genm = 0;
	Int_t c3genm = 0;
	Int_t c4genm = 0;
	Int_t ev_4gmlxylzcut = 0;

	Int_t c1recm = 0;
	Int_t c2recm = 0;
	Int_t c3recm = 0;
	Int_t c4recm = 0;

	Int_t uncuttableFakeCounter = 0;
	//}}}

	TObjArray *fileElements=chain->GetListOfFiles();
	TIter next(fileElements);
	TChainElement *chEl=0;

	p++;
	//cout << "p: " << p << endl;
	//if(p == 0 || p%3 == 0) setup(); //reset vectors for every 4th cT for tables.

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

		t->SetBranchAddress("genA0_Lxy", &genA0_Lxy_rdet);
		t->SetBranchAddress("genA0_Lz",  &genA0_Lz_rdet);
		t->SetBranchAddress("genA1_Lxy", &genA1_Lxy_rdet);
		t->SetBranchAddress("genA1_Lz",  &genA1_Lz_rdet);

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
		//}}}
		for(int k=0;k<t->GetEntries();k++){
			t->GetEntry(k);
			counter_gen[p][0]++;

			counter_genlxylz[p][0]++;
			if(is1GenMu17) counter_gen[p][1]++;
			if(is2GenMu8) counter_gen[p][2]++;
			if(is3GenMu8) counter_gen[p][3]++;
			if(is4GenMu8) counter_gen[p][4]++;

			if(genA0_Lxy_rdet<9.8 && fabs(genA0_Lz_rdet)<48.5 && genA1_Lxy_rdet<9.8 && fabs(genA1_Lz_rdet)<48.5){
				if(is1GenMu17) counter_genlxylz[p][1]++;
				if(is2GenMu8) counter_genlxylz[p][2]++;
				if(is3GenMu8) counter_genlxylz[p][3]++;
				if(is4GenMu8) counter_genlxylz[p][4]++;
			}

			if(genA0_Lxy_rdet<9.8 && fabs(genA0_Lz_rdet)<48.5 && genA1_Lxy_rdet<9.8 && fabs(genA1_Lz_rdet)<48.5){
				if(is1GenMu17) counter_genlxylz2[p][1]++;
				if(is2GenMu8) counter_genlxylz2[p][2]++;
				if(is3GenMu8) counter_genlxylz2[p][3]++;
				if(is4GenMu8) counter_genlxylz2[p][4]++;
			}

			if(is1SelMu17) counter_rec[p][0]++;
			if(is2SelMu8)  counter_rec[p][1]++;
			if(is3SelMu8)  counter_rec[p][2]++;
			if(is4SelMu8)  counter_rec[p][3]++;

			//Auxilary cuts
			if(is4SelMu8 == false) continue;
			if(isVertexOK && is2MuJets){
				counter_rec_dimuons[p][0]++;
				if(is2DiMuonsFittedVtxOK && is2DiMuons){
					counter_rec_dimuons[p][1]++;
					if( (diMuonC_m1_FittedVtx_hitpix_l3inc==1||diMuonC_m2_FittedVtx_hitpix_l3inc==1)&&(diMuonF_m1_FittedVtx_hitpix_l3inc==1||diMuonF_m2_FittedVtx_hitpix_l3inc==1) ){
						counter_rec_dimuons[p][2]++;
						if(diMuons_dz_FittedVtx <= 0.1 && diMuons_dz_FittedVtx >= -10){
							counter_rec_dimuons[p][3]++;
							if(is2DiMuonsMassOK_FittedVtx){
								counter_rec_dimuons[p][4]++;
								if(diMuonF_IsoTk_FittedVtx >= 0 && diMuonC_IsoTk_FittedVtx >= 0  && diMuonC_IsoTk_FittedVtx<=2.0 && diMuonF_IsoTk_FittedVtx<=2.0){
									counter_rec_dimuons[p][5]++;
									if(isDiMuonHLTFired){
										counter_rec_dimuons[p][6]++;
									}
								}
							}
						}
					}
				}
				counter_rec_dimuons2[p][1]++;
				if(diMuons_dz_FittedVtx <= 0.1 && diMuons_dz_FittedVtx >= -10){
					counter_rec_dimuons2[p][2]++;
					if(isDiMuonHLTFired){
						counter_rec_dimuons2[p][3]++;
						if(is2DiMuonsMassOK_FittedVtx){
							counter_rec_dimuons2[p][4]++;
							if(diMuonF_IsoTk_FittedVtx >= 0 && diMuonC_IsoTk_FittedVtx >= 0  && diMuonC_IsoTk_FittedVtx<=2.0 && diMuonF_IsoTk_FittedVtx<=2.0){
								counter_rec_dimuons2[p][5]++;
							}
						}
					}
				}
			}//2mu jets
		}//closing for loop

		myfile->Close();
	} // closing while loop
	double cT_double;
	
	//cout << "cTstring, massString: " << cT_string << ", " << mass_string << endl;
	
	if(cT_string == "000_E") cT_double = 0;
	if(cT_string == "005_E") cT_double = 0.05;
	if(cT_string == "010_E") cT_double = 0.1;
	if(cT_string == "020_E") cT_double = 0.2;
	if(cT_string == "050_E") cT_double = 0.5;
	if(cT_string == "100_E") cT_double = 1.0;
	if(cT_string == "200_E") cT_double = 2.0;
	if(cT_string == "300_E") cT_double = 3.0;
	if(cT_string == "500_E") cT_double = 5.0;
	if(cT_string == "1000_") cT_double = 10.0;
	if(cT_string == "2000_") cT_double = 20.0;
	if(cT_string == "5000_") cT_double = 50.0;
	if(cT_string == "10000") cT_double = 100.0;

	double mass_double;
	if(mass_string == "0250") mass_double = 0.25;
	if(mass_string == "0275") mass_double = 0.275;
	if(mass_string == "0300") mass_double = 0.30;
	if(mass_string == "2000") mass_double = 2.0;
	if(mass_string == "8500") mass_double = 8.5;
	if(mass_string == "0400") mass_double = 0.4;
	if(mass_string == "0700") mass_double = 0.7;
	if(mass_string == "1000") mass_double = 1.0;
	if(mass_string == "1500") mass_double = 1.5;

	//cout << "cT_double, mass_double: " << cT_double << ", " << mass_double << endl;

	ct_vector.push_back(cT_double);
	
	//Most samples have 9 cT.  3 cT per table
	if(p%3 == 2 && (cT_double != 10.0 && cT_double != 20.0 && cT_double != 50.0 && cT_double != 100.0)){
	//cout << "makeLatex (massdouble, cT0, cT1, cT2) : " << mass_double << ", " << ct_vector[0] << ", " << ct_vector[1] << ", " << ct_vector[2] << endl;
		makeLatex(mass_double, ct_vector[0], ct_vector[1], ct_vector[2]);
		p = -1;
		setup();
	}
	//0.25 GeV and 2.0 GeV have 13 cT.  Make the last 4 cT their own table.
	if(cT_double == 100.0){
	//cout << "makeLatex2 (massdouble, cT0, cT1, cT2, cT3) : " << mass_double << ", " << ct_vector[0] << ", " << ct_vector[1] << ", " << ct_vector[2] << ", " << ct_vector[3] << endl;
		makeLatex4(mass_double, ct_vector[0], ct_vector[1], ct_vector[2], ct_vector[3]);
		p = -1;
		setup();
	}
}

void makeCutflowLatex()
{
		setup(); //initial setup
	std::vector< std::vector<string> > DarkSUSY_mH_125_mGammaD_v;
//	cout << "Vector Created" << endl;
	readTextFileWithSamples("/fdata/hepx/store/user/bmichlin/FullSampleList_InclHighCT.txt", DarkSUSY_mH_125_mGammaD_v);
//	cout << "Samples read" << endl;
	for(auto v: DarkSUSY_mH_125_mGammaD_v) efficiency_hitrecovery(v);
//	cout << "For Loop completes" << endl;
	//makeLatex();

}     
