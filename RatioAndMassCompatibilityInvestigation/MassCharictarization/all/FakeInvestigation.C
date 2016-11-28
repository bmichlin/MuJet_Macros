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
#include "/home/bmichlin/TreeLoop/BaseBranchCheck/CMSSW_7_4_1_patch1/src/MuJetAnalysis/AnalysisRun2/scripts/Helpers.h"

//============= Global Variables ===========================//
TFile *BAM = new TFile("erec_alphagen_FittedVTX_0250_GeV.root","RECREATE");

//Plot initialization
//{{{

TH2F *MassPlot_NoCuts = new TH2F("MassPlot_NoCuts", "MassPlot_NoCuts", 1000, 0, 10, 1000, 0, 10);
TH2F *MassPlot_GenFidCut = new TH2F("MassPlot_GenFidCut", "MassPlot_GenFidCut", 1000, 0, 10, 1000, 0, 10);



TH2F *HighMassDimuonC_Reco_MassPlot = new TH2F("HighMassDimuonC_Reco_MassPlot","HighMassDimuonC_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *HighMassDimuonF_Reco_MassPlot = new TH2F("HighMassDimuonF_Reco_MassPlot","HighMassDimuonF_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *LowMassDimuonC_Reco_MassPlot = new TH2F("LowMassDimuonC_Reco_MassPlot","LowMassDimuonC_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *LowMassDimuonF_Reco_MassPlot = new TH2F("LowMassDimuonF_Reco_MassPlot","LowMassDimuonF_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *CorridorDimuonC_Reco_MassPlot = new TH2F("CorridorDimuonC_Reco_MassPlot","CorridorDimuonC_Reco_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *CorridorDimuonF_Reco_MassPlot = new TH2F("CorridorDimuonF_Reco_MassPlot","CorridorDimuonF_Reco_MassPlot", 100, 0, 10, 100, 0, 10);

TH2F *HighMassDimuonC_Reco_Lxy_vs_Mass = new TH2F("HighMassDimuonC_Reco_Lxy_vs_Mass","HighMassDimuonC_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *HighMassDimuonF_Reco_Lxy_vs_Mass = new TH2F("HighMassDimuonF_Reco_Lxy_vs_Mass","HighMassDimuonF_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *LowMassDimuonC_Reco_Lxy_vs_Mass = new TH2F("LowMassDimuonC_Reco_Lxy_vs_Mass","LowMassDimuonC_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *LowMassDimuonF_Reco_Lxy_vs_Mass = new TH2F("LowMassDimuonF_Reco_Lxy_vs_Mass","LowMassDimuonF_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *CorridorDimuonC_Reco_Lxy_vs_Mass = new TH2F("CorridorDimuonC_Reco_Lxy_vs_Mass","CorridorDimuonC_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);
TH2F *CorridorDimuonF_Reco_Lxy_vs_Mass = new TH2F("CorridorDimuonF_Reco_Lxy_vs_Mass","CorridorDimuonF_Reco_Lxy_vs_Mass", 100, 0, 10, 400, 0, 80);

TH1F *HighMassDimuonC_Reco_Lxy = new TH1F("HighMassDimuonC_Reco_Lxy", "HighMassDimuonC_Reco_Lxy", 400, 0, 80 );
TH1F *HighMassDimuonC_Reco_Eta = new TH1F("HighMassDimuonC_Reco_Eta", "HighMassDimuonC_Reco_Eta", 500, -5, 5);
TH1F *HighMassDimuonC_Reco_Phi = new TH1F("HighMassDimuonC_Reco_Phi", "HighMassDimuonC_Reco_Phi", 340, -3.4, 3.4);
TH1F *HighMassDimuonC_Reco_pT = new TH1F("HighMassDimuonC_Reco_pT", "HighMassDimuonC_Reco_pT", 100, 0, 100);
TH2F *HighMassDimuonC_Reco_pT_vs_Lxy = new TH2F("HighMassDimuonC_Reco_pT_vs_Lxy", "HighMassDimuonC_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *HighMassDimuonC_Reco_Dimuon_Opening_Angle = new TH1F("HighMassDimuonC_Reco_Dimuon_Opening_Angle", "HighMassDimuonC_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *LowMassDimuonC_Reco_Lxy = new TH1F("LowMassDimuonC_Reco_Lxy", "LowMassDimuonC_Reco_Lxy", 400, 0, 80 );
TH1F *LowMassDimuonC_Reco_Eta = new TH1F("LowMassDimuonC_Reco_Eta", "LowMassDimuonC_Reco_Eta", 500, -5, 5);
TH1F *LowMassDimuonC_Reco_Phi = new TH1F("LowMassDimuonC_Reco_Phi", "LowMassDimuonC_Reco_Phi", 340, -3.4, 3.4);
TH1F *LowMassDimuonC_Reco_pT = new TH1F("LowMassDimuonC_Reco_pT", "LowMassDimuonC_Reco_pT", 100, 0, 100);
TH2F *LowMassDimuonC_Reco_pT_vs_Lxy = new TH2F("LowMassDimuonC_Reco_pT_vs_Lxy", "LowMassDimuonC_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *LowMassDimuonC_Reco_Dimuon_Opening_Angle = new TH1F("LowMassDimuonC_Reco_Dimuon_Opening_Angle", "LowMassDimuonC_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *LowMassDimuonF_Reco_Lxy = new TH1F("LowMassDimuonF_Reco_Lxy", "LowMassDimuonF_Reco_Lxy", 400, 0, 80 );
TH1F *LowMassDimuonF_Reco_Eta = new TH1F("LowMassDimuonF_Reco_Eta", "LowMassDimuonF_Reco_Eta", 500, -5, 5);
TH1F *LowMassDimuonF_Reco_Phi = new TH1F("LowMassDimuonF_Reco_Phi", "LowMassDimuonF_Reco_Phi", 340, -3.4, 3.4);
TH1F *LowMassDimuonF_Reco_pT = new TH1F("LowMassDimuonF_Reco_pT", "LowMassDimuonF_Reco_pT", 100, 0, 100);
TH2F *LowMassDimuonF_Reco_pT_vs_Lxy = new TH2F("LowMassDimuonF_Reco_pT_vs_Lxy", "LowMassDimuonF_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *LowMassDimuonF_Reco_Dimuon_Opening_Angle = new TH1F("LowMassDimuonF_Reco_Dimuon_Opening_Angle", "LowMassDimuonF_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *HighMassDimuonF_Reco_Lxy = new TH1F("HighMassDimuonF_Reco_Lxy", "HighMassDimuonF_Reco_Lxy", 400, 0, 80 );
TH1F *HighMassDimuonF_Reco_Eta = new TH1F("HighMassDimuonF_Reco_Eta", "HighMassDimuonF_Reco_Eta", 500, -5, 5);
TH1F *HighMassDimuonF_Reco_Phi = new TH1F("HighMassDimuonF_Reco_Phi", "HighMassDimuonF_Reco_Phi", 340, -3.4, 3.4);
TH1F *HighMassDimuonF_Reco_pT = new TH1F("HighMassDimuonF_Reco_pT", "HighMassDimuonF_Reco_pT", 100, 0, 100);
TH2F *HighMassDimuonF_Reco_pT_vs_Lxy = new TH2F("HighMassDimuonF_Reco_pT_vs_Lxy", "HighMassDimuonF_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *HighMassDimuonF_Reco_Dimuon_Opening_Angle = new TH1F("HighMassDimuonF_Reco_Dimuon_Opening_Angle", "HighMassDimuonF_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *CorridorDimuonF_Reco_Lxy = new TH1F("CorridorDimuonF_Reco_Lxy", "CorridorDimuonF_Reco_Lxy", 400, 0, 80 );
TH1F *CorridorDimuonF_Reco_Eta = new TH1F("CorridorDimuonF_Reco_Eta", "CorridorDimuonF_Reco_Eta", 500, -5, 5);
TH1F *CorridorDimuonF_Reco_Phi = new TH1F("CorridorDimuonF_Reco_Phi", "CorridorDimuonF_Reco_Phi", 340, -3.4, 3.4);
TH1F *CorridorDimuonF_Reco_pT = new TH1F("CorridorDimuonF_Reco_pT", "CorridorDimuonF_Reco_pT", 100, 0, 100);
TH2F *CorridorDimuonF_Reco_pT_vs_Lxy = new TH2F("CorridorDimuonF_Reco_pT_vs_Lxy", "CorridorDimuonF_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *CorridorDimuonF_Reco_Dimuon_Opening_Angle = new TH1F("CorridorDimuonF_Reco_Dimuon_Opening_Angle", "CorridorDimuonF_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *CorridorDimuonC_Reco_Lxy = new TH1F("CorridorDimuonC_Reco_Lxy", "CorridorDimuonC_Reco_Lxy", 400, 0, 80 );
TH1F *CorridorDimuonC_Reco_Eta = new TH1F("CorridorDimuonC_Reco_Eta", "CorridorDimuonC_Reco_Eta", 500, -5, 5);
TH1F *CorridorDimuonC_Reco_Phi = new TH1F("CorridorDimuonC_Reco_Phi", "CorridorDimuonC_Reco_Phi", 340, -3.4, 3.4);
TH1F *CorridorDimuonC_Reco_pT = new TH1F("CorridorDimuonC_Reco_pT", "CorridorDimuonC_Reco_pT", 100, 0, 100);
TH2F *CorridorDimuonC_Reco_pT_vs_Lxy = new TH2F("CorridorDimuonC_Reco_pT_vs_Lxy", "CorridorDimuonC_Reco_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *CorridorDimuonC_Reco_Dimuon_Opening_Angle = new TH1F("CorridorDimuonC_Reco_Dimuon_Opening_Angle", "CorridorDimuonC_Reco_Dimuon_Opening_Angle", 400, -4, 4);

TH2F *HighMassDimuonC_Gen_MassPlot = new TH2F("HighMassDimuonC_Gen_MassPlot","HighMassDimuonC_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *HighMassDimuonF_Gen_MassPlot = new TH2F("HighMassDimuonF_Gen_MassPlot","HighMassDimuonF_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *LowMassDimuonC_Gen_MassPlot = new TH2F("LowMassDimuonC_Gen_MassPlot","LowMassDimuonC_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *LowMassDimuonF_Gen_MassPlot = new TH2F("LowMassDimuonF_Gen_MassPlot","LowMassDimuonF_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *CorridorDimuonC_Gen_MassPlot = new TH2F("CorridorDimuonC_Gen_MassPlot","CorridorDimuonC_Gen_MassPlot", 100, 0, 10, 100, 0, 10);
TH2F *CorridorDimuonF_Gen_MassPlot = new TH2F("CorridorDimuonF_Gen_MassPlot","CorridorDimuonF_Gen_MassPlot", 100, 0, 10, 100, 0, 10);

TH1F *HighMassDimuonC_Gen_Lxy = new TH1F("HighMassDimuonC_Gen_Lxy", "HighMassDimuonC_Gen_Lxy", 400, 0, 80 );
TH1F *HighMassDimuonC_Gen_Eta = new TH1F("HighMassDimuonC_Gen_Eta", "HighMassDimuonC_Gen_Eta", 500, -5, 5);
TH1F *HighMassDimuonC_Gen_Phi = new TH1F("HighMassDimuonC_Gen_Phi", "HighMassDimuonC_Gen_Phi", 340, -3.4, 3.4);
TH1F *HighMassDimuonC_Gen_pT = new TH1F("HighMassDimuonC_Gen_pT", "HighMassDimuonC_Gen_pT", 100, 0, 100); 
TH2F *HighMassDimuonC_Gen_pT_vs_Lxy = new TH2F("HighMassDimuonC_Gen_pT_vs_Lxy", "HighMassDimuonC_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *HighMassDimuonC_Gen_Dimuon_Opening_Angle = new TH1F("HighMassDimuonC_Gen_Dimuon_Opening_Angle", "HighMassDimuonC_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *LowMassDimuonC_Gen_Lxy = new TH1F("LowMassDimuonC_Gen_Lxy", "LowMassDimuonC_Gen_Lxy", 400, 0, 80 );
TH1F *LowMassDimuonC_Gen_Eta = new TH1F("LowMassDimuonC_Gen_Eta", "LowMassDimuonC_Gen_Eta", 500, -5, 5);
TH1F *LowMassDimuonC_Gen_Phi = new TH1F("LowMassDimuonC_Gen_Phi", "LowMassDimuonC_Gen_Phi", 340, -3.4, 3.4);
TH1F *LowMassDimuonC_Gen_pT = new TH1F("LowMassDimuonC_Gen_pT", "LowMassDimuonC_Gen_pT", 100, 0, 100); 
TH2F *LowMassDimuonC_Gen_pT_vs_Lxy = new TH2F("LowMassDimuonC_Gen_pT_vs_Lxy", "LowMassDimuonC_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *LowMassDimuonC_Gen_Dimuon_Opening_Angle = new TH1F("LowMassDimuonC_Gen_Dimuon_Opening_Angle", "LowMassDimuonC_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *LowMassDimuonF_Gen_Lxy = new TH1F("LowMassDimuonF_Gen_Lxy", "LowMassDimuonF_Gen_Lxy", 400, 0, 80 );
TH1F *LowMassDimuonF_Gen_Eta = new TH1F("LowMassDimuonF_Gen_Eta", "LowMassDimuonF_Gen_Eta", 500, -5, 5);
TH1F *LowMassDimuonF_Gen_Phi = new TH1F("LowMassDimuonF_Gen_Phi", "LowMassDimuonF_Gen_Phi", 340, -3.4, 3.4);
TH1F *LowMassDimuonF_Gen_pT = new TH1F("LowMassDimuonF_Gen_pT", "LowMassDimuonF_Gen_pT", 100, 0, 100); 
TH2F *LowMassDimuonF_Gen_pT_vs_Lxy = new TH2F("LowMassDimuonF_Gen_pT_vs_Lxy", "LowMassDimuonF_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *LowMassDimuonF_Gen_Dimuon_Opening_Angle = new TH1F("LowMassDimuonF_Gen_Dimuon_Opening_Angle", "LowMassDimuonF_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *HighMassDimuonF_Gen_Lxy = new TH1F("HighMassDimuonF_Gen_Lxy", "HighMassDimuonF_Gen_Lxy", 400, 0, 80 );
TH1F *HighMassDimuonF_Gen_Eta = new TH1F("HighMassDimuonF_Gen_Eta", "HighMassDimuonF_Gen_Eta", 500, -5, 5);
TH1F *HighMassDimuonF_Gen_Phi = new TH1F("HighMassDimuonF_Gen_Phi", "HighMassDimuonF_Gen_Phi", 340, -3.4, 3.4);
TH1F *HighMassDimuonF_Gen_pT = new TH1F("HighMassDimuonF_Gen_pT", "HighMassDimuonF_Gen_pT", 100, 0, 100); 
TH2F *HighMassDimuonF_Gen_pT_vs_Lxy = new TH2F("HighMassDimuonF_Gen_pT_vs_Lxy", "HighMassDimuonF_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *HighMassDimuonF_Gen_Dimuon_Opening_Angle = new TH1F("HighMassDimuonF_Gen_Dimuon_Opening_Angle", "HighMassDimuonF_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *CorridorDimuonF_Gen_Lxy = new TH1F("CorridorDimuonF_Gen_Lxy", "CorridorDimuonF_Gen_Lxy", 400, 0, 80 );
TH1F *CorridorDimuonF_Gen_Eta = new TH1F("CorridorDimuonF_Gen_Eta", "CorridorDimuonF_Gen_Eta", 500, -5, 5);
TH1F *CorridorDimuonF_Gen_Phi = new TH1F("CorridorDimuonF_Gen_Phi", "CorridorDimuonF_Gen_Phi", 340, -3.4, 3.4);
TH1F *CorridorDimuonF_Gen_pT = new TH1F("CorridorDimuonF_Gen_pT", "CorridorDimuonF_Gen_pT", 100, 0, 100); 
TH2F *CorridorDimuonF_Gen_pT_vs_Lxy = new TH2F("CorridorDimuonF_Gen_pT_vs_Lxy", "CorridorDimuonF_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *CorridorDimuonF_Gen_Dimuon_Opening_Angle = new TH1F("CorridorDimuonF_Gen_Dimuon_Opening_Angle", "CorridorDimuonF_Gen_Dimuon_Opening_Angle", 400, -4, 4);

TH1F *CorridorDimuonC_Gen_Lxy = new TH1F("CorridorDimuonC_Gen_Lxy", "CorridorDimuonC_Gen_Lxy", 400, 0, 80 );
TH1F *CorridorDimuonC_Gen_Eta = new TH1F("CorridorDimuonC_Gen_Eta", "CorridorDimuonC_Gen_Eta", 500, -5, 5);
TH1F *CorridorDimuonC_Gen_Phi = new TH1F("CorridorDimuonC_Gen_Phi", "CorridorDimuonC_Gen_Phi", 340, -3.4, 3.4);
TH1F *CorridorDimuonC_Gen_pT = new TH1F("CorridorDimuonC_Gen_pT", "CorridorDimuonC_Gen_pT", 100, 0, 100); 
TH2F *CorridorDimuonC_Gen_pT_vs_Lxy = new TH2F("CorridorDimuonC_Gen_pT_vs_Lxy", "CorridorDimuonC_Gen_pT_vs_Lxy", 100,0,100,400,0,80);
TH1F *CorridorDimuonC_Gen_Dimuon_Opening_Angle = new TH1F("CorridorDimuonC_Gen_Dimuon_Opening_Angle", "CorridorDimuonC_Gen_Dimuon_Opening_Angle", 400, -4, 4);


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
	{"000_",0.0}, {"005_", 0.05}, {"010_", 0.10}, {"020_", 0.20}, {"050_", 0.50}, {"100_", 1.00},
	{"200_", 2.00}, {"300_", 3.00}, {"500_", 5.00}, {"1000", 10.0}, {"2000", 20.0}, {"8500", 85.0}
};

void efficiency_hitrecovery(const std::vector<std::string>& dirNames){
	bool verbose(false);
	//	TString dirname(fileName);
	TChain* chain = new TChain("dummy");
	TString ext("out_ana_");

	decodeFileNameMany(dirNames, mass_string, cT_string);
	fileName = "DarkSUSY_mH_125_mGammaD_" + mass_string + "_cT_" + cT_string;

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
		//}}}

		for(int k=0;k<t->GetEntries();k++){
			t->GetEntry(k);

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

			//  =============  Reco information ====================//

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

			//Find leftmost boundary
			double left  = (1/413.)*((387.*mass_double) - 52);
			//Find rightmost boundary
			double right = (1/387.)*((413*mass_double) + 52);
			//Find topmost boundary
			double top   = (1/387.)*((413*mass_double) + 52);
			//find bottommost boundary
			double bottom= (1/413.)*((387*mass_double) - 52);

			if(diMuonC_FittedVtx_m < 0 && diMuonF_FittedVtx_m < 0) continue;

			//--------------------
			//Match Dimuons RECO-GEN
			int matchResult = MatchRECOtoGENdimuons(diMuonC_FittedVtx_eta, diMuonC_FittedVtx_phi, diMuonF_FittedVtx_eta, diMuonF_FittedVtx_phi, genA0_eta, genA0_phi, genA1_eta, genA0_phi);
			//if matchResult == 0; diMuonC -> A0, diMuonF -> A1 
			//if matchResult == 1; diMuonC -> A1, diMuonF -> A0
			//--------------------


			int corridorCounter_C = 0;
			int corridorCounter_F = 0;

			if(diMuonC_FittedVtx_m > right){ //high mass diMuonC
				corridorCounter_C++;

				HighMassDimuonC_Reco_Lxy->Fill(diMuonC_FittedVtx_Lxy);
				HighMassDimuonC_Reco_Eta->Fill(diMuonC_FittedVtx_eta);
				HighMassDimuonC_Reco_Phi->Fill(diMuonC_FittedVtx_phi);
				HighMassDimuonC_Reco_pT->Fill(sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py)); 
				HighMassDimuonC_Reco_pT_vs_Lxy->Fill(diMuonC_FittedVtx_Lxy, sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
				HighMassDimuonC_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonC_FittedVtx_phi,diMuonF_FittedVtx_phi)); 
				HighMassDimuonC_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
				HighMassDimuonC_Reco_Lxy_vs_Mass->Fill(diMuonC_FittedVtx_m, diMuonC_FittedVtx_Lxy);

				if(matchResult == 0){
					HighMassDimuonC_Gen_Lxy->Fill(genA0_Lxy);
					HighMassDimuonC_Gen_Eta->Fill(genA0_eta);
					HighMassDimuonC_Gen_Phi->Fill(genA0_phi);
					HighMassDimuonC_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					HighMassDimuonC_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					HighMassDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
					HighMassDimuonC_Gen_MassPlot->Fill(genA0_m,genA1_m);
				}else{
					HighMassDimuonC_Gen_Lxy->Fill(genA1_Lxy);
					HighMassDimuonC_Gen_Eta->Fill(genA1_eta);
					HighMassDimuonC_Gen_Phi->Fill(genA1_phi);
					HighMassDimuonC_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					HighMassDimuonC_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					HighMassDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
					HighMassDimuonC_Gen_MassPlot->Fill(genA1_m,genA0_m);
				}

			}
			if(diMuonC_FittedVtx_m < left){ //low mass diMuonC
				corridorCounter_C++;

				LowMassDimuonC_Reco_Lxy->Fill(diMuonC_FittedVtx_Lxy);
				LowMassDimuonC_Reco_Eta->Fill(diMuonC_FittedVtx_eta);
				LowMassDimuonC_Reco_Phi->Fill(diMuonC_FittedVtx_phi);
				LowMassDimuonC_Reco_pT->Fill(sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
				LowMassDimuonC_Reco_pT_vs_Lxy->Fill(diMuonC_FittedVtx_Lxy, sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
				LowMassDimuonC_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonC_FittedVtx_phi,diMuonF_FittedVtx_phi));
				LowMassDimuonC_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
				LowMassDimuonC_Reco_Lxy_vs_Mass->Fill(diMuonC_FittedVtx_m, diMuonC_FittedVtx_Lxy);


				if(matchResult == 0){
					LowMassDimuonC_Gen_Lxy->Fill(genA0_Lxy);
					LowMassDimuonC_Gen_Eta->Fill(genA0_eta);
					LowMassDimuonC_Gen_Phi->Fill(genA0_phi);
					LowMassDimuonC_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					LowMassDimuonC_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					LowMassDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
					LowMassDimuonC_Gen_MassPlot->Fill(genA0_m,genA1_m);

				}else{
					LowMassDimuonC_Gen_Lxy->Fill(genA1_Lxy);
					LowMassDimuonC_Gen_Eta->Fill(genA1_eta);
					LowMassDimuonC_Gen_Phi->Fill(genA1_phi);
					LowMassDimuonC_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					LowMassDimuonC_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					LowMassDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
					LowMassDimuonC_Gen_MassPlot->Fill(genA1_m,genA0_m);

				}
			}
			if(diMuonF_FittedVtx_m > top){ //high mass diMuonF
				corridorCounter_F++;
				HighMassDimuonF_Reco_Lxy->Fill(diMuonF_FittedVtx_Lxy);
				HighMassDimuonF_Reco_Eta->Fill(diMuonF_FittedVtx_eta);
				HighMassDimuonF_Reco_Phi->Fill(diMuonF_FittedVtx_phi);
				HighMassDimuonF_Reco_pT->Fill(sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
				HighMassDimuonF_Reco_pT_vs_Lxy->Fill(diMuonF_FittedVtx_Lxy, sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
				HighMassDimuonF_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonF_FittedVtx_phi,diMuonC_FittedVtx_phi));
				HighMassDimuonF_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
				HighMassDimuonF_Reco_Lxy_vs_Mass->Fill(diMuonF_FittedVtx_m, diMuonF_FittedVtx_Lxy);


				if(matchResult == 0){
					HighMassDimuonF_Gen_Lxy->Fill(genA0_Lxy);
					HighMassDimuonF_Gen_Eta->Fill(genA0_eta);
					HighMassDimuonF_Gen_Phi->Fill(genA0_phi);
					HighMassDimuonF_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					HighMassDimuonF_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					HighMassDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
					HighMassDimuonF_Gen_MassPlot->Fill(genA0_m,genA1_m);

				}else{
					HighMassDimuonF_Gen_Lxy->Fill(genA1_Lxy);
					HighMassDimuonF_Gen_Eta->Fill(genA1_eta);
					HighMassDimuonF_Gen_Phi->Fill(genA1_phi);
					HighMassDimuonF_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					HighMassDimuonF_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					HighMassDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
					HighMassDimuonF_Gen_MassPlot->Fill(genA1_m,genA0_m);

				}

			}
			if(diMuonF_FittedVtx_m < left){ //low mass diMuonF
				corridorCounter_F++;
				LowMassDimuonF_Reco_Lxy->Fill(diMuonF_FittedVtx_Lxy);
				LowMassDimuonF_Reco_Eta->Fill(diMuonF_FittedVtx_eta);
				LowMassDimuonF_Reco_Phi->Fill(diMuonF_FittedVtx_phi);
				LowMassDimuonF_Reco_pT->Fill(sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
				LowMassDimuonF_Reco_pT_vs_Lxy->Fill(diMuonF_FittedVtx_Lxy, sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
				LowMassDimuonF_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonF_FittedVtx_phi,diMuonC_FittedVtx_phi));
				LowMassDimuonF_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
				LowMassDimuonF_Reco_Lxy_vs_Mass->Fill(diMuonF_FittedVtx_m, diMuonF_FittedVtx_Lxy);

				if(matchResult == 0){
					LowMassDimuonF_Gen_Lxy->Fill(genA0_Lxy);
					LowMassDimuonF_Gen_Eta->Fill(genA0_eta);
					LowMassDimuonF_Gen_Phi->Fill(genA0_phi);
					LowMassDimuonF_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					LowMassDimuonF_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					LowMassDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
					LowMassDimuonF_Gen_MassPlot->Fill(genA0_m,genA1_m);

				}else{
					LowMassDimuonF_Gen_Lxy->Fill(genA1_Lxy);
					LowMassDimuonF_Gen_Eta->Fill(genA1_eta);
					LowMassDimuonF_Gen_Phi->Fill(genA1_phi);
					LowMassDimuonF_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					LowMassDimuonF_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					LowMassDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
					LowMassDimuonF_Gen_MassPlot->Fill(genA1_m,genA0_m);

				}
			}

			if(corridorCounter_C == 0){ //DimuonC in corridor
				CorridorDimuonC_Reco_Lxy->Fill(diMuonC_FittedVtx_Lxy);
				CorridorDimuonC_Reco_Eta->Fill(diMuonC_FittedVtx_eta);
				CorridorDimuonC_Reco_Phi->Fill(diMuonC_FittedVtx_phi);
				CorridorDimuonC_Reco_pT->Fill(sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
				CorridorDimuonC_Reco_pT_vs_Lxy->Fill(diMuonC_FittedVtx_Lxy, sqrt(diMuonC_FittedVtx_px*diMuonC_FittedVtx_px+diMuonC_FittedVtx_py*diMuonC_FittedVtx_py));
				CorridorDimuonC_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonC_FittedVtx_phi,diMuonF_FittedVtx_phi));
				CorridorDimuonC_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
				CorridorDimuonC_Reco_Lxy_vs_Mass->Fill(diMuonC_FittedVtx_m, diMuonC_FittedVtx_Lxy);


				if(matchResult == 0){
					CorridorDimuonC_Gen_Lxy->Fill(genA0_Lxy);
					CorridorDimuonC_Gen_Eta->Fill(genA0_eta);
					CorridorDimuonC_Gen_Phi->Fill(genA0_phi);
					CorridorDimuonC_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					CorridorDimuonC_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					CorridorDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
					CorridorDimuonC_Gen_MassPlot->Fill(genA0_m,genA1_m);

				}else{
					CorridorDimuonC_Gen_Lxy->Fill(genA1_Lxy);
					CorridorDimuonC_Gen_Eta->Fill(genA1_eta);
					CorridorDimuonC_Gen_Phi->Fill(genA1_phi);
					CorridorDimuonC_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					CorridorDimuonC_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					CorridorDimuonC_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
					CorridorDimuonC_Gen_MassPlot->Fill(genA1_m,genA0_m);
				}
			}
			if(corridorCounter_F == 0){ //DimuonF in corridor
				CorridorDimuonF_Reco_Lxy->Fill(diMuonF_FittedVtx_Lxy);
				CorridorDimuonF_Reco_Eta->Fill(diMuonF_FittedVtx_eta);
				CorridorDimuonF_Reco_Phi->Fill(diMuonF_FittedVtx_phi);
				CorridorDimuonF_Reco_pT->Fill(sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
				CorridorDimuonF_Reco_pT_vs_Lxy->Fill(diMuonF_FittedVtx_Lxy, sqrt(diMuonF_FittedVtx_px*diMuonF_FittedVtx_px+diMuonF_FittedVtx_py*diMuonF_FittedVtx_py));
				CorridorDimuonF_Reco_Dimuon_Opening_Angle->Fill(My_dPhi(diMuonF_FittedVtx_phi,diMuonC_FittedVtx_phi));
				CorridorDimuonF_Reco_MassPlot->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);
				CorridorDimuonF_Reco_Lxy_vs_Mass->Fill(diMuonF_FittedVtx_m, diMuonF_FittedVtx_Lxy);


				if(matchResult == 0){
					CorridorDimuonF_Gen_Lxy->Fill(genA0_Lxy);
					CorridorDimuonF_Gen_Eta->Fill(genA0_eta);
					CorridorDimuonF_Gen_Phi->Fill(genA0_phi);
					CorridorDimuonF_Gen_pT->Fill(sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					CorridorDimuonF_Gen_pT_vs_Lxy->Fill(genA0_Lxy, sqrt(genA0_px*genA0_px+genA0_py*genA0_py));
					CorridorDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA0_phi,genA1_phi));
					CorridorDimuonF_Gen_MassPlot->Fill(genA0_m,genA1_m);

				}else{
					CorridorDimuonF_Gen_Lxy->Fill(genA1_Lxy);
					CorridorDimuonF_Gen_Eta->Fill(genA1_eta);
					CorridorDimuonF_Gen_Phi->Fill(genA1_phi);
					CorridorDimuonF_Gen_pT->Fill(sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					CorridorDimuonF_Gen_pT_vs_Lxy->Fill(genA1_Lxy, sqrt(genA1_px*genA1_px+genA1_py*genA1_py));
					CorridorDimuonF_Gen_Dimuon_Opening_Angle->Fill(My_dPhi(genA1_phi,genA0_phi));
					CorridorDimuonF_Gen_MassPlot->Fill(genA1_m,genA0_m);

				}
			}

			MassPlot_NoCuts->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);

			if(fabs(genA0_Lxy)<9.8 && fabs(genA1_Lxy)<9.8 && fabs(genA0_Lz)<48.5 && fabs(genA1_Lz)<48.5) MassPlot_GenFidCut->Fill(diMuonC_FittedVtx_m,diMuonF_FittedVtx_m);


		} // closing for loop
		myfile->Close();
	} // closing while loop

	//Fill ratio reco/gen vectors to be plotted  
	//Prepare plots and plot variables.  Also Fill final information printout vectors
	//{{{

	double cT_double; 
	if(cT_string == "000_") cT_double = 0;
	if(cT_string == "005_") cT_double = 0.05;
	if(cT_string == "010_") cT_double = 0.1;
	if(cT_string == "020_") cT_double = 0.2;
	if(cT_string == "050_") cT_double = 0.5;
	if(cT_string == "100_") cT_double = 1.0;
	if(cT_string == "200_") cT_double = 2.0;
	if(cT_string == "300_") cT_double = 3.0;
	if(cT_string == "500_") cT_double = 5.0;
	if(cT_string == "1000") cT_double = 10.0;
	if(cT_string == "2000") cT_double = 20.0;


	//}}}
}


void makePlotsPretty(){
	HighMassDimuonC_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]"); 
	HighMassDimuonC_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	HighMassDimuonC_Gen_Eta->GetXaxis()->SetTitle("#eta"); 
	HighMassDimuonC_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	HighMassDimuonC_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]"); 
	HighMassDimuonC_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad"); 

	HighMassDimuonC_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]"); 
	HighMassDimuonC_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]"); 

	HighMassDimuonC_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]"); 
	HighMassDimuonC_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonC_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]"); 
	HighMassDimuonC_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	HighMassDimuonC_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	HighMassDimuonC_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	HighMassDimuonF_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	HighMassDimuonF_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	HighMassDimuonF_Gen_Eta->GetXaxis()->SetTitle("#eta");
	HighMassDimuonF_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	HighMassDimuonF_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	HighMassDimuonF_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonF_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	HighMassDimuonF_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	HighMassDimuonF_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	HighMassDimuonF_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonF_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	HighMassDimuonF_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	HighMassDimuonF_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	HighMassDimuonF_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	LowMassDimuonF_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	LowMassDimuonF_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	LowMassDimuonF_Gen_Eta->GetXaxis()->SetTitle("#eta");
	LowMassDimuonF_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	LowMassDimuonF_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	LowMassDimuonF_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonF_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonF_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	LowMassDimuonF_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	LowMassDimuonF_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonF_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonF_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	LowMassDimuonF_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	LowMassDimuonF_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	LowMassDimuonC_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	LowMassDimuonC_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	LowMassDimuonC_Gen_Eta->GetXaxis()->SetTitle("#eta");
	LowMassDimuonC_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	LowMassDimuonC_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	LowMassDimuonC_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonC_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonC_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	LowMassDimuonC_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	LowMassDimuonC_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonC_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonC_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	LowMassDimuonC_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	LowMassDimuonC_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	CorridorDimuonC_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	CorridorDimuonC_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	CorridorDimuonC_Gen_Eta->GetXaxis()->SetTitle("#eta");
	CorridorDimuonC_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	CorridorDimuonC_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	CorridorDimuonC_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonC_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonC_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	CorridorDimuonC_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	CorridorDimuonC_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonC_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonC_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	CorridorDimuonC_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	CorridorDimuonC_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	CorridorDimuonF_Gen_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	CorridorDimuonF_Gen_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	CorridorDimuonF_Gen_Eta->GetXaxis()->SetTitle("#eta");
	CorridorDimuonF_Gen_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	CorridorDimuonF_Gen_Phi->GetXaxis()->SetTitle("#phi [rad]");
	CorridorDimuonF_Gen_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonF_Gen_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonF_Gen_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	CorridorDimuonF_Gen_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");    
	CorridorDimuonF_Gen_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonF_Gen_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonF_Gen_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	CorridorDimuonF_Gen_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	CorridorDimuonF_Gen_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	HighMassDimuonC_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	HighMassDimuonC_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	HighMassDimuonC_Reco_Eta->GetXaxis()->SetTitle("#eta");
	HighMassDimuonC_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	HighMassDimuonC_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	HighMassDimuonC_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonC_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	HighMassDimuonC_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	HighMassDimuonC_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	HighMassDimuonC_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonC_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	HighMassDimuonC_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	HighMassDimuonC_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	HighMassDimuonC_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	HighMassDimuonF_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	HighMassDimuonF_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	HighMassDimuonF_Reco_Eta->GetXaxis()->SetTitle("#eta");
	HighMassDimuonF_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	HighMassDimuonF_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	HighMassDimuonF_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonF_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	HighMassDimuonF_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	HighMassDimuonF_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	HighMassDimuonF_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	HighMassDimuonF_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	HighMassDimuonF_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	HighMassDimuonF_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	HighMassDimuonF_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	LowMassDimuonF_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	LowMassDimuonF_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	LowMassDimuonF_Reco_Eta->GetXaxis()->SetTitle("#eta");
	LowMassDimuonF_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	LowMassDimuonF_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	LowMassDimuonF_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonF_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonF_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	LowMassDimuonF_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	LowMassDimuonF_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonF_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonF_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	LowMassDimuonF_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	LowMassDimuonF_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	LowMassDimuonC_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	LowMassDimuonC_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	LowMassDimuonC_Reco_Eta->GetXaxis()->SetTitle("#eta");
	LowMassDimuonC_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	LowMassDimuonC_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	LowMassDimuonC_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonC_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonC_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	LowMassDimuonC_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	LowMassDimuonC_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	LowMassDimuonC_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	LowMassDimuonC_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	LowMassDimuonC_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	LowMassDimuonC_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	CorridorDimuonC_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	CorridorDimuonC_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	CorridorDimuonC_Reco_Eta->GetXaxis()->SetTitle("#eta");
	CorridorDimuonC_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	CorridorDimuonC_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	CorridorDimuonC_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonC_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonC_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	CorridorDimuonC_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	CorridorDimuonC_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonC_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonC_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	CorridorDimuonC_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	CorridorDimuonC_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

	CorridorDimuonF_Reco_Lxy->GetXaxis()->SetTitle("L_{XY} [cm]");
	CorridorDimuonF_Reco_Lxy->GetYaxis()->SetTitle("Events / 0.2 cm");

	CorridorDimuonF_Reco_Eta->GetXaxis()->SetTitle("#eta");
	CorridorDimuonF_Reco_Eta->GetYaxis()->SetTitle("Events / 0.02 cm");

	CorridorDimuonF_Reco_Phi->GetXaxis()->SetTitle("#phi [rad]");
	CorridorDimuonF_Reco_Phi->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonF_Reco_pT->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonF_Reco_pT->GetYaxis()->SetTitle("Events / 1 [GeV]");

	CorridorDimuonF_Reco_Dimuon_Opening_Angle->GetXaxis()->SetTitle("#Delta#phi Between Dimuons [rads]");
	CorridorDimuonF_Reco_Dimuon_Opening_Angle->GetYaxis()->SetTitle("Events / 0.02 rad");

	CorridorDimuonF_Reco_pT_vs_Lxy->GetXaxis()->SetTitle("p_{T} [GeV]");
	CorridorDimuonF_Reco_pT_vs_Lxy->GetYaxis()->SetTitle("L_{XY} [cm]");

	CorridorDimuonF_Reco_MassPlot->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
	CorridorDimuonF_Reco_MassPlot->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

HighMassDimuonC_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]"); 
HighMassDimuonC_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]"); 

HighMassDimuonF_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
HighMassDimuonF_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

LowMassDimuonC_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
LowMassDimuonC_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

LowMassDimuonF_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
LowMassDimuonF_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

CorridorDimuonC_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
CorridorDimuonC_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

CorridorDimuonF_Reco_Lxy_vs_Mass->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");  
CorridorDimuonF_Reco_Lxy_vs_Mass->GetYaxis()->SetTitle("L_{XY} [cm]");                  

MassPlot_NoCuts->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
MassPlot_NoCuts->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

MassPlot_GenFidCut->GetXaxis()->SetTitle("Mass #mu#mu_{1} [GeV/c^{2}]");
MassPlot_GenFidCut->GetYaxis()->SetTitle("Mass #mu#mu_{2} [GeV/c^{2}]");

}

void FakeInvestigation()
{
	std::vector< std::vector<string> > DarkSUSY_mH_125_mGammaD_v;
	cout << "Vector Created" << endl;
	readTextFileWithSamples("/fdata/hepx/store/user/bmichlin/ExtFidCut_UnHardCodeCuts_SampleList.txt", DarkSUSY_mH_125_mGammaD_v);
	cout << "Samples read" << endl;
	for(auto v: DarkSUSY_mH_125_mGammaD_v) efficiency_hitrecovery(v);
	cout << "For Loop completes" << endl;

	makePlotsPretty();
	BAM->Write();

}     
