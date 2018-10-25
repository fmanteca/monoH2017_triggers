#define checkTriggers_cxx
#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;

void checkTriggers() {
  
  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511;  // [GeV]
  const Double_t lumi = 41.3; // [fb-1]

  Int_t nLepton;
  tree_signal->SetBranchAddress("nLepton",&nLepton);
  Int_t nCleanJet;
  tree_signal->SetBranchAddress("nCleanJet",&nCleanJet);
  Int_t Lepton_muonIdx[200];
  tree_signal->SetBranchAddress("Lepton_muonIdx",&Lepton_muonIdx);
  Int_t Lepton_electronIdx[200];
  tree_signal->SetBranchAddress("Lepton_electronIdx",&Lepton_electronIdx);
  Int_t CleanJet_jetIdx[200];
  tree_signal->SetBranchAddress("CleanJet_jetIdx",&CleanJet_jetIdx);
  Int_t Lepton_pdgId[200];
  tree_signal->SetBranchAddress("Lepton_pdgId",&Lepton_pdgId);
  Int_t Lepton_isTightMuon_cut_Tight_HWWW[200];
  tree_signal->SetBranchAddress("Lepton_isTightMuon_cut_Tight_HWWW",&Lepton_isTightMuon_cut_Tight_HWWW);
  Float_t Lepton_pt[200];
  tree_signal->SetBranchAddress("Lepton_pt",&Lepton_pt);
  Float_t Lepton_eta[200];
  tree_signal->SetBranchAddress("Lepton_eta",&Lepton_eta);
  Float_t Lepton_phi[200];
  tree_signal->SetBranchAddress("Lepton_phi",&Lepton_phi);
  Float_t MET_pt;
  tree_signal->SetBranchAddress("MET_pt",&MET_pt);
  Float_t MET_phi;
  tree_signal->SetBranchAddress("MET_phi",&MET_phi);
  Float_t TkMET_pt;
  tree_signal->SetBranchAddress("TkMET_pt",&TkMET_pt);
  Float_t TkMET_phi;
  tree_signal->SetBranchAddress("TkMET_phi",&TkMET_phi);
  Float_t Jet_btagCSVV2[200];
  tree_signal->SetBranchAddress("Jet_btagCSVV2",&Jet_btagCSVV2);
  Float_t CleanJet_pt[200];
  tree_signal->SetBranchAddress("CleanJet_pt",&CleanJet_pt);
  Float_t CleanJet_eta[200];
  tree_signal->SetBranchAddress("CleanJet_eta",&CleanJet_eta);
  Float_t puWeight;
  tree_signal->SetBranchAddress("puWeight",&puWeight);
  Float_t baseW;
  tree_signal->SetBranchAddress("baseW",&baseW);
  Float_t Generator_weight;
  tree_signal->SetBranchAddress("Generator_weight",&Generator_weight);

  Float_t mass_1;
  Float_t mass_2;
  TLorentzVector lep1;
  TLorentzVector lep2;
  TLorentzVector ll;


  //LIST OF TRIGGERS:
  //--------------------------------------------------------------------------------------------------------------------------

  //FOR monoH, available on full2017:
  Int_t HLT_Mu50; //m
  tree_signal->SetBranchAddress("HLT_Mu50", &HLT_Mu50);
  Int_t HLT_DoubleEle33_CaloIdL_MW; //ee
  tree_signal->SetBranchAddress("HLT_DoubleEle33_CaloIdL_MW", &HLT_DoubleEle33_CaloIdL_MW);

  //FOR monoH, available from 2017D on:
  Int_t HLT_Mu37_TkMu27; //mm
  tree_signal->SetBranchAddress("HLT_Mu37_TkMu27", &HLT_Mu37_TkMu27);
  Int_t HLT_DoubleEle25_CaloIdL_MW; //ee
  tree_signal->SetBranchAddress("HLT_DoubleEle25_CaloIdL_MW", &HLT_DoubleEle25_CaloIdL_MW);
  Int_t HLT_DoubleEle27_CaloIdL_MW; //ee
  tree_signal->SetBranchAddress("HLT_DoubleEle27_CaloIdL_MW", &HLT_DoubleEle27_CaloIdL_MW);
  Int_t HLT_Ele27_Ele37_CaloIdL_MW; //ee
  tree_signal->SetBranchAddress("HLT_Ele27_Ele37_CaloIdL_MW", &HLT_Ele27_Ele37_CaloIdL_MW);
  Int_t HLT_Mu27_Ele37_CaloIdL_MW; //em
  tree_signal->SetBranchAddress("HLT_Mu27_Ele37_CaloIdL_MW", &HLT_Mu27_Ele37_CaloIdL_MW);
  Int_t HLT_Mu37_Ele27_CaloIdL_MW; //em
  tree_signal->SetBranchAddress("HLT_Mu37_Ele27_CaloIdL_MW", &HLT_Mu37_Ele27_CaloIdL_MW);


  //Latinos
  Int_t HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  tree_signal->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
  Int_t HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
  tree_signal->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
  Int_t HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
  tree_signal->SetBranchAddress("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
  Int_t HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
  tree_signal->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
  Int_t HLT_Ele35_WPTight_Gsf;
  tree_signal->SetBranchAddress("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf);
  Int_t HLT_IsoMu27;
  tree_signal->SetBranchAddress("HLT_IsoMu27", &HLT_IsoMu27);





}
