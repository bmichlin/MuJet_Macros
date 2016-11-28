#!/usr/bin/expect -f

#1. Must have 'RAW_RECO' directory in MuJetAnalysis in CMSSW_7_4_1_patch1/src/ on site you which to submit jobs from
#2. If username and storage site username differ, there may be problems.  I have not tested this, yet.
#3. Lines 75 and 81 must be altered to point to the crab_projects DIGI-HLT directory

set timeout 86400

send_user "Site to submit CRAB3 jobs from on (ie: lxplus.cern.ch, login02.brazos.tamu.edu, etc.):"
expect_user -re "(.*)\n" {set SITE $expect_out(1,string)}

send_user "Path to CMSSW_7_4_1_patch1 on site (ie /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_4_1_patch1/):"
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


#set lifetimes [list 500]
#set lifetimes [list 000 005 010 020 050 100 200 300]
set lifetimes [list 200 100 050 020 010 500]
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
	send "cd RAW_RECO/\r";
	expect "$ ";
	send "cmsDriver.py DisplacedMuJet_Run2_cfi -s RAW2DIGI,L1Reco,RECO --datatier RECO --conditions MCRUN2_74_V9 --magField 38T_PostLS1 --eventcontent RECOSIM --customise=SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1 --fileout out_reco.root -n 10 --no_exec \r";
	expect "$ ";
	set timeout 120;
	send "mv DisplacedMuJet_Run2_cfi_RAW2DIGI_L1Reco_RECO.py RAW2DIGI_L1Reco_RECO_MCRUN2_mGammaD_$mGammaD\_cT_$CT\_74_V9_cfg.py\r";
	expect "$ ";
#Get the publish location
	send "crab status -d /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_4_1_patch1/src/MuJetAnalysis/DIGI_HLT/crab_projects/crab_DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_DIGI_L1_DIGI2RAW_HLT_PU_MCRUN2_74_V9_v1 \r";
	expect "Enter GRID pass phrase for this identity:";
	send "$GRIDPASSWORD\r";
	expect "Enter GRID pass phrase:";
	send "$GRIDPASSWORD\r";
	expect "$ ";
	send "crab status -d /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_4_1_patch1/src/MuJetAnalysis/DIGI_HLT/crab_projects/crab_DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_DIGI_L1_DIGI2RAW_HLT_PU_MCRUN2_74_V9_v1 > PublishLocation_mGammaD_$mGammaD\_cT_$CT.txt \r";
	expect "$ ";
	send "sed -i '/Output dataset:/!d' PublishLocation_mGammaD_$mGammaD\_cT_$CT.txt \r";
	expect "$ ";
	send "sed -i 's/Output dataset://g' PublishLocation_mGammaD_$mGammaD\_cT_$CT.txt \r";
	expect "$ ";
	send "sed -i 's/\^\[ \\t\]\*//' PublishLocation_mGammaD_$mGammaD\_cT_$CT.txt \r";
	set timeout 86400;
	expect "$ ";
#Make CRAB3 config file
	expect "$ ";

	send "echo \"from WMCore.Configuration import Configuration\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config = Configuration()\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.section_(\\\"General\\\")\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.requestName = 'DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_RAW2DIGI_L1Reco_RECO_MCRUN2_74_V9_v1'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.workArea = 'crab_projects'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.General.transferOutputs = True\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.section_(\\\"JobType\\\")\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.JobType.pluginName = 'Analysis'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.JobType.psetName = 'RAW2DIGI_L1Reco_RECO_MCRUN2_mGammaD_$mGammaD\_cT_$CT\_74_V9_cfg.py'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.section_(\\\"Data\\\")\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.inputDataset = '\$(cat PublishLocation_mGammaD_$mGammaD\_cT_$CT.txt)'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.inputDBS = 'phys03'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.splitting = 'FileBased'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.unitsPerJob = 1\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.outLFNDirBase = '/store/user/$USER/'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.publication = True\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.Data.publishDataName = 'DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_RAW2DIGI_L1Reco_RECO_MCRUN2_74_V9_v1'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	send "echo \"config.section_(\\\"Site\\\")\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";
	set timeout 120;
	send "echo \"config.Site.storageSite = '$OUTPUT'\" >> RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
	expect "$ ";

	#Submit CRAB3 job
	send "crab submit -c RAW_RECO_CRAB3_$mGammaD\_13TeV_cT_$CT.py\r";
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