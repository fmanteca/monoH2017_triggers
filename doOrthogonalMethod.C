#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;

#include <sstream>

// return number of samples that contain a certain String

Int_t counter_files(TString myFolder, TString Contain){
  cout << "Counting " +Contain+ " files in " + myFolder << endl;
  TSystemDirectory dir(myFolder, myFolder);
  TList *files = dir.GetListOfFiles(); 
  Int_t counter_files = 0;
    if (files) {
      TSystemFile *file;
      TString fname; 
      TIter next(files); 
      while ((file=(TSystemFile*)next())) {
	fname = file->GetName();
	if (!file->IsDirectory() && fname.Contains(Contain)) {
	  counter_files++;
	}
      }
    }
    cout << "Done" << endl;
    return counter_files;
}



void doOrthogonalMethod(TString data_mc, TString variable){

  
  //BINNING
  //------------------------------------------------------------------------------------------------

  if(variable == "pt1"){

    const Int_t nbins = 13;
    Float_t edges[nbins+1]={15.,20.,22.,24.,26.,30.,35.,40.,45.,50.,55.,70.,100.,200};  

    TH1D* h_pass = new TH1D("h_pass", "h_pass", nbins, edges);
    TH1D* h_total = new TH1D("h_total", "h_total", nbins, edges);
    
  }else if(variable == "pt2"){

    const Int_t nbins = 13;
    Float_t edges[nbins+1]={15.,20.,22.,24.,26.,30.,35.,40.,45.,50.,55.,70.,100.,200};  

    TH1D* h_pass = new TH1D("h_pass", "h_pass", nbins, edges);
    TH1D* h_total = new TH1D("h_total", "h_total", nbins, edges);

  }else if(variable == "eta1"){

    const Int_t nbins = 13;
    Float_t edges[nbins+1]={-2.5,-2.1,-1.6,-1.2,-0.8,-0.3,-0.2,0.2,0.3,0.8,1.2,1.6,2.1,2.5};  

    TH1D* h_pass = new TH1D("h_pass", "h_pass", nbins, edges);
    TH1D* h_total = new TH1D("h_total", "h_total", nbins, edges);

  }else if(variable == "eta2"){

    const Int_t nbins = 13;
    Float_t edges[nbins+1]={-2.5,-2.1,-1.6,-1.2,-0.8,-0.3,-0.2,0.2,0.3,0.8,1.2,1.6,2.1,2.5};  

    TH1D* h_pass = new TH1D("h_pass", "h_pass", nbins, edges);
    TH1D* h_total = new TH1D("h_total", "h_total", nbins, edges);

  }else if(variable == "MET"){

    const Int_t nbins = 13;
    Float_t edges[nbins+1]={0.,25.,50.,60.,70.,80.,90.,100.,120.,150.,180.,220.,300.,500.};  

    TH1D* h_pass = new TH1D("h_pass", "h_pass", nbins, edges);
    TH1D* h_total = new TH1D("h_total", "h_total", nbins, edges);

  }else if(variable == "drll"){

    const Int_t nbins = 9;
    Float_t edges[nbins+1]={0.,0.4,0.8,1.2,1.6,2.0,2.5,3.0,3.5,5.0};  

    TH1D* h_pass = new TH1D("h_pass", "h_pass", nbins, edges);
    TH1D* h_total = new TH1D("h_total", "h_total", nbins, edges);

  }
  
  
  // INPUT
  //------------------------------------------------------------------------------------------------

  TChain* tree = new TChain("Events");
  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__l2loose__l2tightOR2017/";
  TString myFolder_mc = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017__btagPerEvent__l2loose__l2tightOR2017/";
  TString file = "";


  if(data_mc == "data"){

    Int_t MET_RunB_files = counter_files(myFolder, "MET_Run2017B");
    Int_t MET_RunC_files = counter_files(myFolder, "MET_Run2017C");
    Int_t MET_RunD_files = counter_files(myFolder, "MET_Run2017D");
    Int_t MET_RunE_files = counter_files(myFolder, "MET_Run2017E");
    Int_t MET_RunF_files = counter_files(myFolder, "MET_Run2017F");


    for(int i=0; i<MET_RunB_files; i++){
      file = myFolder + "nanoLatino_MET_Run2017B-31Mar2018-v1__part" + Form("%d",i)  + ".root";
      tree->Add(file);
    }
    for(int i=0; i<MET_RunC_files; i++){
      file = myFolder + "nanoLatino_MET_Run2017C-31Mar2018-v1__part" + Form("%d",i)  + ".root";
      tree->Add(file);
    }
    for(int i=0; i<MET_RunD_files; i++){
      file = myFolder + "nanoLatino_MET_Run2017D-31Mar2018-v1__part" + Form("%d",i)  + ".root";
      tree->Add(file);
    }
    for(int i=0; i<MET_RunE_files; i++){
      file = myFolder + "nanoLatino_MET_Run2017E-31Mar2018-v1__part" + Form("%d",i)  + ".root";
      tree->Add(file);
  }
    for(int i=0; i<MET_RunF_files; i++){
      file = myFolder + "nanoLatino_MET_Run2017F-31Mar2018-v1__part" + Form("%d",i)  + ".root";
      tree->Add(file);
    }
    

  }else if(data_mc == "mc"){
    
    Int_t DY_files = counter_files(myFolder_mc, "DYJetsToLL_M-50__");

    for(int i=0; i<DY_files; i++){
      file = myFolder_mc + "nanoLatino_DYJetsToLL_M-50__part" + Form("%d",i)  + ".root";
      tree->Add(file);
    }


  }



  //OFFLINE SELECTION
  //------------------------------------------------------------------------------------------------

  TCut TwoLep = "nLepton>=2 && abs(Lepton_eta[0]) < 2.5 && abs(Lepton_eta[1]) < 2.5 && Alt$(Lepton_pt[2],0)<10. && (Lepton_isTightElectron_mvaFall17Iso_WP90[0]>0.5 || Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5) && (Lepton_isTightElectron_mvaFall17Iso_WP90[1]>0.5 || Lepton_isTightMuon_cut_Tight_HWWW[1]>0.5)";
  TCut ee = "Lepton_pdgId[0] * Lepton_pdgId[1] == -11*11";
  TCut em = "Lepton_pdgId[0] * Lepton_pdgId[1] == -11*13";
  TCut mm = "Lepton_pdgId[0] * Lepton_pdgId[1] == -13*13";
  TCut inc = ee || mm || em;
  TCut ExtraCuts = "mll > 20.";
  TCut offline = TwoLep && inc && ExtraCuts;


  //TRIGGER SETS
  //------------------------------------------------------------------------------------------------

  TCut Trig_SingleMu_new = "HLT_Mu50 == 1";
  TCut Trig_DoubleEle_new = "HLT_DoubleEle33_CaloIdL_MW == 1";
  //TCut Trig_MuEle_new = "HLT_Mu27_Ele37_CaloIdL_MW == 1 || HLT_Mu37_Ele27_CaloIdL_MW == 1";
  //TCut Trig_all_new = Trig_SingleMu_new || Trig_DoubleEle_new || Trig_MuEle_new;
  TCut Trig_all_new = Trig_SingleMu_new || Trig_DoubleEle_new;

  TCut Trig_SingleMu_latino = "HLT_IsoMu27 == 1";
  TCut Trig_SingleEle_latino = "HLT_Ele35_WPTight_Gsf";
  TCut Trig_DoubleEle_latino = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ == 1";
  TCut Trig_DoubleMu_latino = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8 == 1";
  TCut Trig_MuEle_latino = "HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ ==1 || HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ == 1";
  TCut Trig_all_latino = Trig_SingleMu_latino || Trig_SingleEle_latino || Trig_DoubleEle_latino || Trig_DoubleMu_latino || Trig_MuEle_latino;

  TCut Trig_all = Trig_all_new || Trig_all_latino; 

  
  //  TCut Trig_PFMET = "HLT_PFMET200_NotCleaned ==  1 || HLT_PFMET200_HBHECleaned == 1 || HLT_PFMET250_HBHECleaned == 1 || HLT_PFMET300_HBHECleaned == 1 || HLT_PFMET200_HBHE_BeamHaloCleaned == 1 || HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned == 1";
  //TCut Trig_PFMET = "";
  //TCut Trig_HT_PFMET = "HLT_PFHT500_PFMET100_PFMHT100_IDTight == 1 || HLT_PFHT500_PFMET110_PFMHT110_IDTight == 1 || HLT_PFHT700_PFMET85_PFMHT85_IDTight == 1 || HLT_PFHT700_PFMET95_PFMHT95_IDTight == 1 || HLT_PFHT800_PFMET75_PFMHT75_IDTight == 1 || HLT_PFHT800_PFMET85_PFMHT85_IDTight == 1 || HLT_PFMET110_PFMHT110_IDTight == 1 || HLT_PFMET120_PFMHT120_IDTight == 1 || HLT_PFMET130_PFMHT130_IDTight == 1 || HLT_PFMET140_PFMHT140_IDTight == 1 || HLT_PFMET120_PFMHT120_IDTight_PFHT60 == 1 || HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60 == 1 || HLT_PFMETTypeOne110_PFMHT110_IDTight == 1 || HLT_PFMETTypeOne120_PFMHT120_IDTight == 1 || HLT_PFMETTypeOne130_PFMHT130_IDTight == 1 || HLT_PFMETTypeOne140_PFMHT140_IDTight == 1 || HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60 == 1 ";
  TCut Trig_HT_PFMET = "HLT_PFHT500_PFMET100_PFMHT100_IDTight == 1 || HLT_PFHT500_PFMET110_PFMHT110_IDTight == 1 || HLT_PFHT700_PFMET85_PFMHT85_IDTight == 1 || HLT_PFHT700_PFMET95_PFMHT95_IDTight == 1 || HLT_PFHT800_PFMET75_PFMHT75_IDTight == 1 || HLT_PFHT800_PFMET85_PFMHT85_IDTight == 1 || HLT_PFMET110_PFMHT110_IDTight == 1 || HLT_PFMET120_PFMHT120_IDTight == 1 || HLT_PFMET130_PFMHT130_IDTight == 1 || HLT_PFMET140_PFMHT140_IDTight == 1 || HLT_PFMETTypeOne110_PFMHT110_IDTight == 1 || HLT_PFMETTypeOne120_PFMHT120_IDTight == 1 || HLT_PFMETTypeOne130_PFMHT130_IDTight == 1 || HLT_PFMETTypeOne140_PFMHT140_IDTight == 1";
  //TCut Trig_MET = Trig_PFMET || Trig_HT_PFMET;
  TCut Trig_MET = Trig_HT_PFMET;
  
  

  // FILL
  //------------------------------------------------------------------------------------------------

  if(variable == "pt1"){
    
    tree->Draw("Lepton_pt[0] >> h_pass", Trig_all && Trig_MET && offline);
    tree->Draw("Lepton_pt[0] >> h_total", Trig_MET && offline);
  
  }else if(variable == "pt2"){

    tree->Draw("Lepton_pt[1] >> h_pass", Trig_all && Trig_MET && offline);
    tree->Draw("Lepton_pt[1] >> h_total", Trig_MET && offline);

  }else if(variable == "eta1"){

    tree->Draw("Lepton_eta[0] >> h_pass", Trig_all && Trig_MET && offline);
    tree->Draw("Lepton_eta[0] >> h_total", Trig_MET && offline);

  }else if(variable == "eta2"){

    tree->Draw("Lepton_eta[1] >> h_pass", Trig_all && Trig_MET && offline);
    tree->Draw("Lepton_eta[1] >> h_total", Trig_MET && offline);

  }else if(variable == "MET"){

    tree->Draw("MET_pt >> h_pass", Trig_all && Trig_MET && offline);
    tree->Draw("MET_pt >> h_total", Trig_MET && offline);

  }else if(variable == "drll"){

    TString deltaR = "sqrt(pow(abs(Lepton_eta[0]-Lepton_eta[1]),2) + pow(abs(Lepton_phi[0]-Lepton_phi[1]), 2))";
    tree->Draw(deltaR + " >> h_pass", Trig_all && Trig_MET && offline);
    tree->Draw(deltaR + " >> h_total", Trig_MET && offline);

  }

  
  // OUTPUT
  //------------------------------------------------------------------------------------------------
  TFile* root_output = new TFile("histos/histos_" + data_mc + "_"+ variable + ".root", "recreate");
  h_pass->Write();
  h_total->Write();

}
