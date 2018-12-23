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
  TString myFolder = "/eos/cms/store/group/phys_muon/fernanpe/MonoH/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017__MCl1loose2017Pedro/";

  TString file = "";
  file = myFolder + sample + ".root";
  tree->Add(file);


  // HISTOGRAMS
  //------------------------------------------------------------------------------------------------
  TH1F* h_drll_ee_latino = new TH1F("h_drll_ee_latino","h_drll_ee_latino",50,0,TMath::Pi());
  TH1F* h_pt1_ee_latino = new TH1F("h_pt1_ee_latino","h_pt1_ee_latino",50,0,500);
  TH1F* h_pt2_ee_latino = new TH1F("h_pt2_ee_latino","h_pt2_ee_latino",50,0,300);
  TH1F* h_drll_em_latino = new TH1F("h_drll_em_latino","h_drll_em_latino",50,0,TMath::Pi());
  TH1F* h_pt1_em_latino = new TH1F("h_pt1_em_latino","h_pt1_em_latino",50,0,500);
  TH1F* h_pt2_em_latino = new TH1F("h_pt2_em_latino","h_pt2_em_latino",50,0,300);
  TH1F* h_drll_mm_latino = new TH1F("h_drll_mm_latino","h_drll_mm_latino",50,0,TMath::Pi());
  TH1F* h_pt1_mm_latino = new TH1F("h_pt1_mm_latino","h_pt1_mm_latino",50,0,500);
  TH1F* h_pt2_mm_latino = new TH1F("h_pt2_mm_latino","h_pt2_mm_latino",50,0,300);
  TH1F* h_drll_inc_latino = new TH1F("h_drll_inc_latino","h_drll_inc_latino",50,0,TMath::Pi());
  TH1F* h_pt1_inc_latino = new TH1F("h_pt1_inc_latino","h_pt1_inc_latino",50,0,500);
  TH1F* h_pt2_inc_latino = new TH1F("h_pt2_inc_latino","h_pt2_inc_latino",50,0,300);

  TH1F* h_drll_ee_new = new TH1F("h_drll_ee_new","h_drll_ee_new",50,0,TMath::Pi());
  TH1F* h_pt1_ee_new = new TH1F("h_pt1_ee_new","h_pt1_ee_new",50,0,500);
  TH1F* h_pt2_ee_new = new TH1F("h_pt2_ee_new","h_pt2_ee_new",50,0,300);
  TH1F* h_drll_em_new = new TH1F("h_drll_em_new","h_drll_em_new",50,0,TMath::Pi());
  TH1F* h_pt1_em_new = new TH1F("h_pt1_em_new","h_pt1_em_new",50,0,500);
  TH1F* h_pt2_em_new = new TH1F("h_pt2_em_new","h_pt2_em_new",50,0,300);
  TH1F* h_drll_mm_new = new TH1F("h_drll_mm_new","h_drll_mm_new",50,0,TMath::Pi());
  TH1F* h_pt1_mm_new = new TH1F("h_pt1_mm_new","h_pt1_mm_new",50,0,500);
  TH1F* h_pt2_mm_new = new TH1F("h_pt2_mm_new","h_pt2_mm_new",50,0,300);
  TH1F* h_drll_inc_new = new TH1F("h_drll_inc_new","h_drll_inc_new",50,0,TMath::Pi());
  TH1F* h_pt1_inc_new = new TH1F("h_pt1_inc_new","h_pt1_inc_new",50,0,500);
  TH1F* h_pt2_inc_new = new TH1F("h_pt2_inc_new","h_pt2_inc_new",50,0,300);


  // CUTS
  //------------------------------------------------------------------------------------------------
  TCut TwoLep = "nLepton>=2 && abs(Lepton_eta[0]) < 2.4 && abs(Lepton_eta[1]) < 2.4 && Alt$(Lepton_pt[2],0)<10. && (Lepton_isTightElectron_mvaFall17Iso_WP90[0]>0.5 || Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5) && (Lepton_isTightElectron_mvaFall17Iso_WP90[1]>0.5 || Lepton_isTightMuon_cut_Tight_HWWW[1]>0.5)";
  TCut presel_high = "Lepton_pt[0] > 52. && Lepton_pt[1] > 20.";
  TCut presel_low = "Lepton_pt[0] > 25. && Lepton_pt[1] > 20.";
  TCut ee = "Lepton_pdgId[0] * Lepton_pdgId[1] == -11*11";
  TCut em = "Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13";
  TCut mm = "Lepton_pdgId[0] * Lepton_pdgId[1] == -13*13";
  TCut inc = ee || mm || em;

  TCut Trig_SingleMu_new = "HLT_Mu50 == 1";
  TCut Trig_DoubleEle_new = "HLT_DoubleEle33_CaloIdL_MW == 1";
  TCut Trig_MuEle_new = "HLT_Mu27_Ele37_CaloIdL_MW == 1 || HLT_Mu37_Ele27_CaloIdL_MW == 1";
  TCut Trig_all_new = Trig_SingleMu_new || Trig_DoubleEle_new || Trig_MuEle_new;

  TCut Trig_SingleMu_latino = "HLT_IsoMu27 == 1";
  TCut Trig_SingleEle_latino = "HLT_Ele35_WPTight_Gsf";
  TCut Trig_DoubleEle_latino = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ == 1";
  TCut Trig_DoubleMu_latino = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8 == 1";
  TCut Trig_MuEle_latino = "HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ ==1 || HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ == 1";
  TCut Trig_all_latino = Trig_SingleMu_latino || Trig_SingleEle_latino || Trig_DoubleEle_latino || Trig_DoubleMu_latino || Trig_MuEle_latino;


  // FILL
  //------------------------------------------------------------------------------------------------
  TString deltaR = "sqrt(pow(abs(Lepton_eta[0]-Lepton_eta[1]),2) + pow(abs(Lepton_phi[0]-Lepton_phi[1]), 2))";

  tree->Draw(deltaR +" >> h_drll_ee_latino", TwoLep && Trig_all_latino && ee);
  tree->Draw("Lepton_pt[0] >> h_pt1_ee_latino", TwoLep && Trig_all_latino && ee);
  tree->Draw("Lepton_pt[1] >> h_pt2_ee_latino", TwoLep && Trig_all_latino && ee);
  tree->Draw(deltaR +" >> h_drll_em_latino", TwoLep && Trig_all_latino && em);
  tree->Draw("Lepton_pt[0] >> h_pt1_em_latino", TwoLep && Trig_all_latino && em);
  tree->Draw("Lepton_pt[1] >> h_pt2_em_latino", TwoLep && Trig_all_latino && em);
  tree->Draw(deltaR +" >> h_drll_mm_latino", TwoLep && Trig_all_latino && mm);
  tree->Draw("Lepton_pt[0] >> h_pt1_mm_latino", TwoLep && Trig_all_latino && mm);
  tree->Draw("Lepton_pt[1] >> h_pt2_mm_latino", TwoLep && Trig_all_latino && mm);
  tree->Draw(deltaR +" >> h_drll_inc_latino", TwoLep && Trig_all_latino && inc);
  tree->Draw("Lepton_pt[0] >> h_pt1_inc_latino", TwoLep && Trig_all_latino && inc);
  tree->Draw("Lepton_pt[1] >> h_pt2_inc_latino", TwoLep && Trig_all_latino && inc);

  tree->Draw(deltaR +" >> h_drll_ee_new", TwoLep && Trig_all_new && ee);
  tree->Draw("Lepton_pt[0] >> h_pt1_ee_new", TwoLep && Trig_all_new && ee);
  tree->Draw("Lepton_pt[1] >> h_pt2_ee_new", TwoLep && Trig_all_new && ee);
  tree->Draw(deltaR +" >> h_drll_em_new", TwoLep && Trig_all_new && em);
  tree->Draw("Lepton_pt[0] >> h_pt1_em_new", TwoLep && Trig_all_new && em);
  tree->Draw("Lepton_pt[1] >> h_pt2_em_new", TwoLep && Trig_all_new && em);
  tree->Draw(deltaR +" >> h_drll_mm_new", TwoLep && Trig_all_new && mm);
  tree->Draw("Lepton_pt[0] >> h_pt1_mm_new", TwoLep && Trig_all_new && mm);
  tree->Draw("Lepton_pt[1] >> h_pt2_mm_new", TwoLep && Trig_all_new && mm);
  tree->Draw(deltaR +" >> h_drll_inc_new", TwoLep && Trig_all_new && inc);
  tree->Draw("Lepton_pt[0] >> h_pt1_inc_new", TwoLep && Trig_all_new && inc);
  tree->Draw("Lepton_pt[1] >> h_pt2_inc_new", TwoLep && Trig_all_new && inc);
  

  // OUTPUT
  //------------------------------------------------------------------------------------------------
  TFile* root_output = new TFile("output_" + sample + ".root", "recreate");
  h_drll_ee_latino->Write();
  h_pt1_ee_latino->Write();
  h_pt2_ee_latino->Write();
  h_drll_em_latino->Write();
  h_pt1_em_latino->Write();
  h_pt2_em_latino->Write();
  h_drll_mm_latino->Write();
  h_pt1_mm_latino->Write();
  h_pt2_mm_latino->Write();
  h_drll_inc_latino->Write();
  h_pt1_inc_latino->Write();
  h_pt2_inc_latino->Write();
  h_drll_ee_new->Write();
  h_pt1_ee_new->Write();
  h_pt2_ee_new->Write();
  h_drll_em_new->Write();
  h_pt1_em_new->Write();
  h_pt2_em_new->Write();
  h_drll_mm_new->Write();
  h_pt1_mm_new->Write();
  h_pt2_mm_new->Write();
  h_drll_inc_new->Write();
  h_pt1_inc_new->Write();
  h_pt2_inc_new->Write();

  root_output->Close();

}
