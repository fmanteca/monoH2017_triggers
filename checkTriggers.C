#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;


void checkTriggers(TString sample) { 


  // INPUT
  //------------------------------------------------------------------------------------------------
  TChain* tree = new TChain("Events");
  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017/MCl1loose2017__MCformulas/";

  TString file = "";
  file = myFolder + sample;
  tree->Add(file);


  // HISTOGRAMS
  //------------------------------------------------------------------------------------------------
  TH1F* h_drll_Mu50 = new TH1F("h_drll_Mu50","h_drll_Mu50",100,0,2*TMath::Pi());
  TH1F* h_drll_IsoMu27 = new TH1F("h_drll_IsoMu27","h_drll_IsoMu27",100,0,2*TMath::Pi());
  TH1F* h_drll_Mu17_Mu8_TrkIso = new TH1F("h_drll_Mu17_Mu8_TrkIso","h_drll_Mu17_Mu8_TrkIso",100,0,2*TMath::Pi());
  TH1F* h_mll = new TH1F("h_mll","h_mll",100,0,7000);


  // CUTS
  //------------------------------------------------------------------------------------------------
  TCut TwoLep = "nLepton == 2 && (Lepton_pdgId[0] * Lepton_pdgId[1]) == -13*13 && abs(Lepton_eta[0]) < 2.4 && abs(Lepton_eta[1]) < 2.4 && Lepton_isTightMuon_cut_Tight_HWWW[0] > 0.5 && Lepton_isTightMuon_cut_Tight_HWWW[1] > 0.5 && Lepton_pt[0] > 51. && Lepton_pt[1] > 20.";
  //TCut mZp = "abs(mll-5000) < 500";
  TCut Trig_Mu50 = "HLT_Mu50 == 1";
  TCut Trig_IsoMu27 = "HLT_IsoMu27 == 1";
  TCut Trig_Mu17_Mu8_TrkIso = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8";

  // FILL
  //------------------------------------------------------------------------------------------------
  TString deltaR = "sqrt(pow(abs(Lepton_eta[0]-Lepton_eta[1]),2) + pow(abs(Lepton_phi[0]-Lepton_phi[1]), 2))";
  TString ptll = "sqrt(pow(abs(Lepton_eta[0]-Lepton_eta[1]),2) + pow(abs(Lepton_phi[0]-Lepton_phi[1]), 2))";

  tree->Draw(deltaR +" >> h_drll_Mu50", TwoLep && Trig_Mu50);
  tree->Draw(deltaR +" >> h_drll_IsoMu27", TwoLep && Trig_IsoMu27);
  tree->Draw(deltaR +" >> h_drll_Mu17_Mu8_TrkIso", TwoLep && Trig_Mu17_Mu8_TrkIso);
  tree->Draw("mll >> h_mll", TwoLep);
  

  // OUTPUT
  //------------------------------------------------------------------------------------------------
  TFile* root_output = new TFile("output_" + sample, "recreate");
  h_drll_IsoMu27->Write();
  h_drll_Mu50->Write();
  h_drll_Mu17_Mu8_TrkIso->Write();
  h_mll->Write();
  root_output->Close();

}
