#!/usr/bin/expect -f

#1. Must have 'DIGI_HLT' directory in MuJetAnalysis in CMSSW_7_4_1_patch1/src/ on site you which to submit jobs from
#2. If username and storage site username differ, there may be problems.  I have not tested this, yet.
#3. Lines 75 and 81 must be altered to point to the crab_projects GEN-SIM directory.

set timeout 86400

send_user "Site to resubmit CRAB3 jobs from (ie: lxplus.cern.ch, login02.brazos.tamu.edu, etc.):"
expect_user -re "(.*)\n" {set SITE $expect_out(1,string)}

send_user "Path to CMSSW_7_4_1_patch1 on site (ie /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_4_1_patch1/):"
expect_user -re "(.*)\n" {set PATH $expect_out(1,string)}

send_user "Site Username: "
expect_user -re "(.*)\n" {set USER $expect_out(1,string)}

send_user "mGammaD GeV (XXXX) to resubmit: "
expect_user -re "(.*)\n" {set mGammaD $expect_out(1,string)}

#send_user "Lifetime (XXX) to resubmit: "
#expect_user -re "(.*)\n" {set LIFE $expect_out(1,string)}

send_user "Site to save output to (T3_US_TAMU, T2_CERN_CH, T3_US_FNALLPC, etc): "
expect_user -re "(.*)\n" {set OUTPUT $expect_out(1,string)}

stty -echo
send_user "Site Password: "
expect_user -re "(.*)\n" {set PASSWORD $expect_out(1,string)}

stty -echo
send_user "GRID Password: "
expect_user -re "(.*)\n" {set GRIDPASSWORD $expect_out(1,string)}


set lifetimes [list 500 000 010 050 100 200 300]

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
	set timeout 120;
	send "cd DIGI_HLT/\r";
	expect "$ ";
#Get the publish location
	send "crab status -d /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_4_1_patch1/src/MuJetAnalysis/DIGI_HLT/crab_projects/crab_DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_DIGI_L1_DIGI2RAW_HLT_PU_MCRUN2_74_V9_v1\r";
	expect "Enter GRID pass phrase for this identity:";
	send "$GRIDPASSWORD\r";
	expect "Enter GRID pass phrase:";
	send "$GRIDPASSWORD\r";
	expect "$ ";
	send "crab resubmit -d /afs/cern.ch/work/b/bmichlin/public/withTAMU/DarkSUSYSampleGeneration/CMSSW_7_4_1_patch1/src/MuJetAnalysis/DIGI_HLT/crab_projects/crab_DarkSUSY_mH_125_mGammaD_$mGammaD\_cT_$CT\_13TeV_DIGI_L1_DIGI2RAW_HLT_PU_MCRUN2_74_V9_v1\r";
	expect "$ ";
	set timeout 86400;
	expect "$ ";
	send "cd .\r";
	expect "$ ";
	send "cd ../\r";
	expect "$ ";
	send "cd .\r";
}

exit
