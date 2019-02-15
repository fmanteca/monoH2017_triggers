#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
#include "TEfficiency.h"
using namespace std;


void getEff_and_plot(TString variable){

  TFile* file_data = new TFile("histos/histos_data_" + variable + ".root");
  TFile* file_mc = new TFile("histos/histos_mc_" + variable + ".root");

  TH1F* h_pass_data = (TH1F*)file_data->Get("h_pass");
  TH1F* h_total_data = (TH1F*)file_data->Get("h_total");

  TH1F* h_pass_mc = (TH1F*)file_mc->Get("h_pass");
  TH1F* h_total_mc = (TH1F*)file_mc->Get("h_total");


  TEfficiency* pEff_data = 0;
  TEfficiency* pEff_mc = 0;

  if(TEfficiency::CheckConsistency(*h_pass_data,*h_total_data))
    {
      pEff_data = new TEfficiency(*h_pass_data,*h_total_data);
    }

  if(TEfficiency::CheckConsistency(*h_pass_mc,*h_total_mc))
    {
      pEff_mc = new TEfficiency(*h_pass_mc,*h_total_mc);
    }

  TCanvas* c1 = new TCanvas("","",1000,800);

  pEff_data->SetTitle(";" + variable + ";Efficiency");
  pEff_data->SetLineWidth(3);
  pEff_data->SetLineColor(1);
  pEff_data->Draw("AP");
  pEff_mc->SetTitle(";" + variable + ";Efficiency");
  pEff_mc->SetLineWidth(3);
  pEff_mc->SetLineColor(4);
  pEff_mc->Draw("SAME");



  TLegend *legend1 = new TLegend(0.68,0.45,0.82,0.55);
  legend1->AddEntry(pEff_data, "DATA","l");
  legend1->AddEntry(pEff_mc, "MC","l");
  legend1->Draw();

  c1->SaveAs("/afs/cern.ch/user/f/fernanpe/www/190215_TriggerEff_orthogonalMethod/EfficiencyPlot_" + variable + ".png");
  //  pEff->Write();
  
  

  
  
  // PRINT VALUES

  // cout << "variable: " << variable << endl;

  // for(int i=0; i<=h_pass->GetNbinsX(); i++){
  //   cout << "Bin:(" << h_pass->GetBinLowEdge(i) << "," << h_pass->GetBinLowEdge(i+1) << ") = " << pEff->GetEfficiency(i) << " - " << pEff->GetEfficiencyErrorLow(i) << " + " << pEff->GetEfficiencyErrorUp(i) << endl;
  // }
}
