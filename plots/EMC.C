
#include "/Users/reimer/Documents/text/talk/figs/setup.h"

const int nE866 = 7;
struct {
  struct {
    double x[nE866] = {0.055, 0.046, 0.039, 0.034, 0.030, 0.026, 0.023};
    double r[nE866] = {1.059, 0.973, 0.959, 0.962, 0.979, 0.920, 0.960};
    double dr[nE866] = {0.041, 0.016, 0.014, 0.017, 0.025, 0.042, 0.099};
  } FeBe;
  struct {
    double x[nE866] = {0.055, 0.046, 0.039, 0.034, 0.030, 0.026, 0.023};
    double r[nE866] = {0.971, 0.964, 0.951, 0.944, 0.914, 0.884, 0.882};
    double dr[nE866] = {0.042, 0.015, 0.013, 0.016, 0.023, 0.040, 0.086};
  } WBe;
} E866;

const int nE772 = 9;
struct{
  struct {
    double x[nE772] = {0.041, 0.062, 0.087, 0.111, 0.136, 0.161, 0.186, 0.216, 0.269};
    double r[nE772] = {0.924, 0.958, 1.016, 1.008, 0.954, 1.065, 1.017, 1.040, 1.000};
    double dr[nE772] = {0.016, 0.013, 0.016, 0.020, 0.026, 0.043, 0.067, 0.099, 0.192};
  } WD;
  struct {
    double x[nE772] = {0.041, 0.062, 0.087, 0.111, 0.136, 0.161, 0.186, 0.219, 0.271};
    double r[nE772] = {0.954, 0.976, 1.009, 0.992, 0.984, 1.009, 0.953, 1.016, 0.984};
    double dr[nE772] = {0.014, 0.011, 0.012, 0.014, 0.018, 0.027, 0.037, 0.050, 0.088};
  } FeD;
  struct  {
    double x[nE772] = {0.041, 0.062, 0.087, 0.111, 0.136, 0.161, 0.186, 0.216, 0.269};
    double r[nE772] = {0.981, 0.974, 1.013, 1.011, 0.979, 1.049, 1.117, 1.151, 1.044};
    double dr[nE772] = {0.017, 0.014, 0.016, 0.020, 0.027, 0.044, 0.074, 0.110, 0.202};
  } CD;
} E772;

int EMC() {
  
  TCanvas *c1 = setup("onecolumn");
  c1->Draw();
  
  TH2F *myFrame = frame(0, 0.35, 0.45, 1.45, page.point10);
  myFrame->GetYaxis()->SetTitle("Cross Section Ratio");
  myFrame->GetXaxis()->SetTitle("x_{Bj}");
  myFrame->Draw("same");
  
  
  TLine *oneY = new TLine(0, 1, page.xMax, 1);
  oneY->Draw();

  TLegend *legend = new TLegend(0.15, 0.725, 0.45, 0.95);
  legend->SetBorderSize(0);
  legend->SetTextFont(133);
  legend->SetTextSize(page.point10);

  double xErrE866[nE866] =  {0};
  TGraphErrors *E866FeBe = new TGraphErrors(nE866, E866.FeBe.x, E866.FeBe.r, xErrE866, E866.FeBe.dr);
  E866FeBe->SetMarkerStyle(kOpenCircle);
  E866FeBe->SetMarkerColor(kRed);
  E866FeBe->SetName("E866FeBe");
  E866FeBe->SetMarkerSize(2);
  E866FeBe->Draw("Psame");
  
  TGraphErrors *E866WBe = new TGraphErrors(nE866, E866.WBe.x, E866.WBe.r, xErrE866, E866.WBe.dr);
  E866WBe->SetMarkerStyle(kOpenSquare);
  E866WBe->SetMarkerColor(kBlue);
  E866WBe->SetName("E866WBe");
  E866WBe->SetMarkerSize(2);
  E866WBe->Draw("Psame");

  double xOffset[nE772];
  double xDelta = 0.002;
  double xErrE772[nE772] =  {0};

  for (int i=0; i<nE772; i++) {
    xOffset[i] = E772.CD.x[i] + xDelta;
  }
  TGraphErrors *E772CD = new TGraphErrors(nE772, xOffset, E772.CD.r, xErrE772, E772.CD.dr);
  E772CD->SetMarkerStyle(kFullDiamond);
  E772CD->SetMarkerColor(kMagenta);
  E772CD->SetName("E772CD");
  E772CD->SetMarkerSize(2);
  E772CD->Draw("Psame");
  TGraphErrors *dummy3 =  (TGraphErrors*)E772CD->Clone();
  dummy3->SetMarkerStyle(kOpenDiamond);
  dummy3->SetMarkerColor(kBlack);
  dummy3->Draw("Psame");
  

  for (int i=0; i<nE772; i++) {
    xOffset[i] = E772.FeD.x[i] + 0.0;
  }
  TGraphErrors *E772FeD = new TGraphErrors(nE772, xOffset, E772.FeD.r, xErrE772, E772.FeD.dr);
  E772FeD->SetMarkerStyle(kFullCircle);
  E772FeD->SetMarkerColor(kRed);
  E772FeD->SetName("E772FeD");
  E772FeD->SetMarkerSize(2);
  E772FeD->Draw("Psame");
  TGraphErrors *dummy1 =  (TGraphErrors*)E772FeD->Clone();
  dummy1->SetMarkerStyle(kOpenCircle);
  dummy1->SetMarkerColor(kBlack);
  dummy1->Draw("Psame");
  

  for (int i=0; i<nE772; i++) {
    xOffset[i] = E772.WD.x[i] - xDelta;
  }
  TGraphErrors *E772WD = new TGraphErrors(nE772, xOffset, E772.WD.r, xErrE772, E772.WD.dr);
  E772WD->SetMarkerStyle(kFullSquare);
  E772WD->SetMarkerColor(kBlue);
  E772WD->SetName("E772WD");
  E772WD->SetMarkerSize(2);
  E772WD->Draw("Psame");
  TGraphErrors *dummy2 =  (TGraphErrors*)E772WD->Clone();
  dummy2->SetMarkerStyle(kOpenSquare);
  dummy2->SetMarkerColor(kBlack);
  dummy2->Draw("Psame");

  
  legend->AddEntry("E772CD", "E772 C/D", "lep");
  legend->AddEntry("E772FeD", "E772 Fe/D", "lep");
  legend->AddEntry("E772WD", "E772 W/D", "lep");
  legend->AddEntry("E866FeBe", "NuSea-E866 Fe/Be", "lep");
  legend->AddEntry("E866WBe", "NuSea-E866 W/Be", "lep");
  
  legend->Draw();

  c1->Print("Drell-Yan_EMC.pdf");
  c1->Print("Drell-Yan_EMC.png");

  return 1;
}
