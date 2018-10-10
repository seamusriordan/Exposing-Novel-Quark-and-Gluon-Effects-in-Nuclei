//#include "setup.h"

pageStruct page;

TCanvas *setup(float xPage, float yPage, float xPixel, float yPixel){
  
  page.point10 = trunc(xPixel/xPage*2.54/72 * 0.9) * 10 ; //pixels per point the 0.9 is arbitrary
  
  TStyle *myStyle = new TStyle("myStyle", "myStyle");
  myStyle->SetPaperSize(xPage, yPage); // this gives the size in cm of the image on paper when printed with no maginifaction
  myStyle->SetEndErrorSize(page.point10/5);
  myStyle->SetCanvasColor(kWhite);

  TCanvas *c1 = new TCanvas("c1", "c1", 850, 850); // this gives the resolution in pixels, absolute
  c1->SetTopMargin(0.025);
  c1->SetRightMargin(0.025);
  gROOT->SetStyle("myStyle");

  page.xPage = xPage;
  page.yPage = yPage;
  page.xPixel = xPixel;
  page.yPixel = yPixel;

  return c1;
  
}
TCanvas *setup(string size){
  float xPage, yPage, xPixel, yPixel;
  size=toLower(size);
  if (size == "onecolumn") {
    xPage = 8.5;
    yPage = 8.5;
    xPixel = 850;
    yPixel = 850;
  } else if (size == "rectangle") {
    xPage = 8.5;
    yPage = 4.5;
    xPixel = 850;
    yPixel = 450;
  } else if (size == "twocolumn") {
    xPage = 18;
    yPage = 8.5;
    xPixel = 1800;
    yPixel = 850;
  }
  return setup (xPage, yPage, xPixel, yPixel);
}

TH2F *frame(float xMin, float xMax, float yMin, float yMax, int txtSize) {

  TH2F *frame = new TH2F("Frame", "Frame", 100, xMin, xMax, 100, yMin, yMax);
  frame->SetTitle("");
  frame->SetStats(FALSE);
  frame->GetYaxis()->CenterTitle();
  // note that if the precision is "3" (last digit in font number) then the size is in pixels.
  frame->GetYaxis()->SetLabelFont(133);
  frame->GetYaxis()->SetTitleFont(133);
  frame->GetYaxis()->SetLabelSize(txtSize);
  frame->GetYaxis()->SetTitleSize(txtSize);
  frame->GetXaxis()->CenterTitle();
  frame->GetXaxis()->SetLabelFont(133);
  frame->GetXaxis()->SetTitleFont(133);
  frame->GetXaxis()->SetLabelSize(txtSize);
  frame->GetXaxis()->SetTitleSize(txtSize);

  page.xMax = xMax;
  page.yMax = yMax;
  page.xMin = xMin;
  page.yMin = yMin;

  return frame;
}
