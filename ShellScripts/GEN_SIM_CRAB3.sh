#!/usr/bin/expect -f

#1. Must have 'GEN_SIM' directory in MuJetAnalysis in CMSSW_7_1_15_patch1/src/ on site you which to submit jobs from
#2. Must have lhe files in MuJetAnalysis/DarkSusySamples_LHE_13TeV/DarkSUSY_mH_125/mGammaD_$mGammaD
#3. If username and storage site username differ, there may be problems.  I have not tested this, yet.

set timeout 86400

send_user "Site to submit CRAB3 jobs from on (ie: lxplus.cern.ch, login02.brazos.tamu.edu, etc.):"
expect_user -re "(.*)\n" {set SITE $expect_out(1,string)}

send_user "Path to CMSSW_7_1_15_patch1 on site (ie /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_1_15_patch1/):"
expect_user -re "(.*)\n" {set PATH $expect_out(1,string)}

send_user "Site Username: "
expect_user -re "(.*)\n" {set USER $expect_out(1,string)}

send_user "mGammaD GeV (XXXX): "
expect_user -re "(.*)\n" {set mGammaD $expect_out(1,string)}

send_user "Site to save output to (T3_US_TAMU, T2_CERN_CH, T3_US_FNALLPC, etc): "
expect_user -re "(.*)\n" {set OUTPUT $expect_out(1,string)}

stty -echo
send_user "Site Password: "
expect_user -re "(.*)\n" {set PASSWORD $expect_out(1,string)}

stty -echo
send_user "GRID Password: "
expect_user -re "(.*)\n" {set GRIDPASSWORD $expect_out(1,string)}


#set lifetimes [list 050 100 200 300 500]
#set lifetimes [list 000 005 010 020 050 100 200 300 500]
set lifetimes [list 500]
# These are the liftimes used formated as X.XX mm (e.g.: 010 === 0.10 mm)


set timeout 10;
spawn ssh -X -Y $USER@$SITE 
expect "Password: ";
send "$PASSWORD\r";
expect "$ ";
send "cd $PATH \r";
set timeout 86400; 
expect "$ ";
send "cd src/ \r";
set timeout 10;
expect "$ ";
send "cmsenv \r"
expect "$ ";
send "voms-proxy-init -out \${HOME}/.x509up_u\${UID} \r";
expect "$ ";
send "$GRIDPASSWORD\r";
expect "$ ";
send "export X509_USER_PROXY=\${HOME}/.x509up_u\${UID} \r";
expect "$ ";
send "source /cvmfs/cms.cern.ch/crab3/crab.sh \r";
expect "$ ";
send "cmsenv\r"
expect "$ ";
set timeout 86400;
send "cd MuJetAnalysis/ \r";

foreach CT $lifetimes {
	expect "$ ";
	send "cd DarkSusySamples_LHE_13TeV/DarkSUSY_mH_125/mGammaD_$mGammaD/cT_$CT \r";
	expect "$ ";
	send "tar -zxvf DarkSUSY_mH_125_mGammaD_$mGammaD\_13TeV_cT_$CT\_madgraph452_bridge224_events80k.lhe.tar.gz \r";
	expect "$ ";
	send "mv *.lhe DarkSUSY_mH_125_mGammaD_$mGammaD\_13TeV_cT_$CT\_madgraph452_bridge224_events80k.lhe \r";
	expect "$ ";
	send "mv DarkSUSY_mH_125_mGammaD_$mGammaD\_13TeV_cT_$CT\_madgraph452_bridge224_events80k.lhe ../../../../GEN_SIM/\r";
	expect "$ ";
	send "cd ../../../../GEN_SIM/\r";
	expect "$ ";
	send "cmsDriver.py MuJetAnalysis/GenProduction/Pythia8HadronizerFilter_13TeV_cfi -s GEN,SIM --mc --datatier GEN-SIM --beamspot NominalCollision2015 --conditions MCRUN2_71_V1::All --magField 38T_PostLS1 --eventcontent RAWSIM --customise=SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1 --python_filename DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_madgraph452_bridge224_LHE_pythia8_cfi_GEN_SIM.py --filetype LHE --filein file:DarkSUSY_mH_125_mGammaD_$mGammaD\_13TeV_cT_$CT\_madgraph452_bridge224_events80k.lhe --fileout out_sim.root -n 10 --no_exec \r";
	expect "$ ";
#Make CRAB3 config file
	send "echo \"from CRABClient.UserUtilities import config, getUsernameFromSiteDB\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config = config()\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.requestName = 'DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.workArea = 'crab_projects'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.transferOutputs = True\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.transferLogs = False\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.JobType.pluginName = 'PrivateMC'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.JobType.psetName = 'DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_madgraph452_bridge224_LHE_pythia8_cfi_GEN_SIM.py'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.JobType.inputFiles = \['DarkSUSY_mH_125_mGammaD_$mGammaD\_13TeV_cT_$CT\_madgraph452_bridge224_events80k.lhe'\]\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.primaryDataset = 'DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.splitting = 'EventBased'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.unitsPerJob = 800\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.totalUnits = 80000\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.outLFNDirBase = '/store/user/$USER/'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.publication = True\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.publishDataName = 'DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_MG452_BR224_LHE_pythia8_GEN_SIM_MCRUN2_71_V1_v1'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	set timeout 120;
	send "echo \"config.Site.storageSite = '$OUTPUT'\" >> GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	#Submit CRAB3 job
	send "crab submit -c GEN_SIM_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "Enter GRID pass phrase for this identity:";
	send "$GRIDPASSWORD\r";
	expect "Enter GRID pass phrase for this identity:";
	send "$GRIDPASSWORD\r";
	expect "$ ";
	send "cd .\r";
	expect "$ ";
	send "cd ../\r";
	expect "$ ";
	send "cd .\r";
	set timeout 86400;
}

exit
