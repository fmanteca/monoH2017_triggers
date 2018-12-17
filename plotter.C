#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;


void plotter(Int_t Nsame, TString variable, TString channel, TString sample1, TString sample2, TString sample3, TString sample4, TString Type) { 

  if(Nsame == 2){

    TFile* file = new TFile("output_nanoLatino_monoH_" + sample1 + ".root");

    if(variable == "drll"){
      if(channel == "ee"){
	TH1F* h_1 = (TH1F*)file->Get("h_drll_ee_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_drll_ee_new");
      }else if(channel == "em"){
	TH1F* h_1 = (TH1F*)file->Get("h_drll_em_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_drll_em_new");
      }else if(channel=="mm"){
	TH1F* h_1 = (TH1F*)file->Get("h_drll_mm_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_drll_mm_new");
      }else if(channel=="inc"){
	TH1F* h_1 = (TH1F*)file->Get("h_drll_inc_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_drll_inc_new");
      }
    }else if(variable == "pt1"){
      if(channel == "ee"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt1_ee_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt1_ee_new");
      }else if(channel == "em"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt1_em_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt1_em_new");
      }else if(channel=="mm"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt1_mm_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt1_mm_new");
      }else if(channel=="inc"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt1_inc_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt1_inc_new");
      }
    }else if(variable == "pt2"){
      if(channel == "ee"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt2_ee_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt2_ee_new");
      }else if(channel == "em"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt2_em_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt2_em_new");
      }else if(channel=="mm"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt2_mm_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt2_mm_new");
      }else if(channel=="inc"){
	TH1F* h_1 = (TH1F*)file->Get("h_pt2_inc_latino");
	TH1F* h_2 = (TH1F*)file->Get("h_pt2_inc_new");
      }
    }

    gStyle->SetOptStat(0);
    TCanvas* c1 = new TCanvas("c1", "Title", 800, 800);

    c1->cd();
    h_1->GetYaxis()->SetLabelSize(0.045); 
    h_1->GetXaxis()->SetTitle(variable);
    h_1->Draw();
    h_1->SetLineColor(4);
    h_1->SetLineWidth(2);
    h_1->SetMarkerStyle(20);
    h_1->SetMarkerColor(4);

    h_2->Draw("SAME HIST");
    h_2->SetLineColor(2);
    h_2->SetLineWidth(2);
    
    legend1 = new TLegend(0.57,0.76,0.87,0.86);
    legend1->AddEntry(h_1,"Latino Triggers","l");
    legend1->AddEntry(h_2,"New triggers","l");
    legend1->Draw();
                                                           
    c1->SaveAs("/afs/cern.ch/user/f/fernanpe/www/monoH_privateMC/latinos_vs_new_" + sample1 + "_" + variable + "_" + channel + ".png");

  }

  
  else if(Nsame == 4){

    TFile* file1 = new TFile("output_nanoLatino_monoH_" + sample1 + ".root");
    TFile* file2 = new TFile("output_nanoLatino_monoH_" + sample2 + ".root");
    TFile* file3 = new TFile("output_nanoLatino_monoH_" + sample3 + ".root");
    TFile* file4 = new TFile("output_nanoLatino_monoH_" + sample4 + ".root");

    if(variable == "drll"){
      if(channel == "ee" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_ee_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_ee_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_ee_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_ee_latino");
      }else if(channel == "em" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_em_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_em_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_em_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_em_latino");
      }else if(channel=="mm" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_mm_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_mm_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_mm_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_mm_latino");
      }else if(channel=="inc" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_inc_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_inc_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_inc_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_inc_latino");
      }
      if(channel == "ee" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_ee_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_ee_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_ee_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_ee_new");
      }else if(channel == "em" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_em_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_em_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_em_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_em_new");
      }else if(channel=="mm" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_mm_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_mm_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_mm_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_mm_new");
      }else if(channel=="inc" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_drll_inc_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_drll_inc_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_drll_inc_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_drll_inc_new");
      }
    }else if(variable == "pt1"){
      if(channel == "ee" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_ee_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_ee_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_ee_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_ee_latino");
      }else if(channel == "em" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_em_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_em_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_em_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_em_latino");
      }else if(channel=="mm" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_mm_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_mm_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_mm_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_mm_latino");
      }else if(channel=="inc" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_inc_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_inc_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_inc_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_inc_latino");
      }
      if(channel == "ee" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_ee_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_ee_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_ee_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_ee_new");
      }else if(channel == "em" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_em_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_em_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_em_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_em_new");
      }else if(channel=="mm" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_mm_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_mm_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_mm_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_mm_new");
      }else if(channel=="inc" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt1_inc_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt1_inc_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt1_inc_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt1_inc_new");
      }
    }else if(variable == "pt2"){
      if(channel == "ee" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_ee_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_ee_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_ee_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_ee_latino");
      }else if(channel == "em" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_em_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_em_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_em_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_em_latino");
      }else if(channel=="mm" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_mm_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_mm_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_mm_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_mm_latino");
      }else if(channel=="inc" && Type == "latino"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_inc_latino");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_inc_latino");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_inc_latino");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_inc_latino");
      }
      if(channel == "ee" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_ee_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_ee_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_ee_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_ee_new");
      }else if(channel == "em" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_em_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_em_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_em_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_em_new");
      }else if(channel=="mm" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_mm_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_mm_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_mm_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_mm_new");
      }else if(channel=="inc" && Type == "new"){
	TH1F* h_1 = (TH1F*)file1->Get("h_pt2_inc_new");
	TH1F* h_2 = (TH1F*)file2->Get("h_pt2_inc_new");
	TH1F* h_3 = (TH1F*)file3->Get("h_pt2_inc_new");
	TH1F* h_4 = (TH1F*)file4->Get("h_pt2_inc_new");
      }
    }

    gStyle->SetOptStat(0);
    TCanvas* c1 = new TCanvas("c1", "Title", 800, 800);

    c1->cd();
    h_1->GetYaxis()->SetLabelSize(0.045); 
    h_1->GetXaxis()->SetTitle(variable);
    h_1->Draw();
    h_1->SetLineColor(4);
    h_1->SetLineWidth(2);

    h_2->Draw("SAME HIST");
    h_2->SetLineColor(2);
    h_2->SetLineWidth(2);

    h_3->Draw("SAME HIST");
    h_3->SetLineColor(3);
    h_3->SetLineWidth(2);

    h_4->Draw("SAME HIST");
    h_4->SetLineColor(1);
    h_4->SetLineWidth(2);
    
    legend1 = new TLegend(0.48,0.68,0.87,0.86);
    legend1->AddEntry(h_1, sample1,"l");
    legend1->AddEntry(h_2, sample2,"l");
    legend1->AddEntry(h_3, sample3,"l");
    legend1->AddEntry(h_4, sample4,"l");
    legend1->Draw();
                                                           
    c1->SaveAs("/afs/cern.ch/user/f/fernanpe/www/monoH_privateMC/" + variable + "_" + Type + "_" + channel + ".png");



  }



}
