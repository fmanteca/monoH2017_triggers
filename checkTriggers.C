// root -l aTGCs_test.C Lepton_isTightMuon_cut_Tight_HWWW  Lepton_isTightMuon_cut_Tight_HWWW
#include "checkTriggers.h"


void checkTriggers() { 

  TChain* tree_signal = new TChain("Events");
  TChain* tree_ww = new TChain("Events");
  
  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017/MCl1loose2017__MCformulas/";
 
 TString file_signal = "";
 TString file_ww = "";

 
 file_signal = myFolder + "nanoLatino_ZprimeToMuMu_M-5000__part0.root";
 tree_signal->Add(file_signal);
 
 file_ww = myFolder + "nanoLatino_WWTo2L2Nu__part0.root";
 tree_ww->Add(file_ww);
 file_ww = myFolder + "nanoLatino_WWTo2L2Nu__part1.root";
 tree_ww->Add(file_ww);
 file_ww = myFolder + "nanoLatino_WWTo2L2Nu__part2.root";
 tree_ww->Add(file_ww);


  TH1F* h_drll_Mu50 = new TH1F("h_drll_Mu50","h_drll_Mu50",100,0,2*TMath::Pi());
  TH1F* h_drll_IsoMu27 = new TH1F("h_drll_IsoMu27","h_drll_IsoMu27",100,0,2*TMath::Pi());
  TH1F* h_met_Mu50 = new TH1F("h_met_Mu50","h_met_Mu50",100,0,300);


  // Cuts
  //------------------------------------------------------------------------------------------------
  TCut TwoLep = "nLepton == 2 && (Lepton_pdgId[0] * Lepton_pdgId[1]) == -13*13 && abs(Lepton_eta[0]) < 2.4 && abs(Lepton_eta[1]) < 2.4 && Lepton_isTightMuon_cut_Tight_HWWW[0] > 0.5 && Lepton_isTightMuon_cut_Tight_HWWW[1] > 0.5 && Lepton_pt[0] > 51. && Lepton_pt[1] > 20.";
  TCut Trig_Mu50 = "HLT_Mu50 == 1";
  TCut Trig_IsoMu27 = "HLT_IsoMu27 == 1";


  // FILL
  //------------------------------------------------------------------------------------------------
  TString deltaR = "sqrt(pow(abs(Lepton_eta[0]-Lepton_eta[1]),2) + pow(abs(Lepton_phi[0]-Lepton_phi[1]), 2))";
  TCanvas* c1 = new TCanvas("c1", "c1");

  tree_signal->Draw(deltaR +" >> h_drll_Mu50", TwoLep && Trig_Mu50);
  tree_signal->Draw(deltaR +" >> h_drll_IsoMu27", TwoLep && Trig_IsoMu27);
  





  TFile* root_output = new TFile("output.root", "recreate");
  h_drll_IsoMu27->Write();
  h_drll_Mu50->Write();
  root_output->Close();



}
