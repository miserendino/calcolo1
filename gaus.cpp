#include <iostream>
#include "TApplication.h"
#include <fstream>
#include "TAttFill.h"
#include "TH1I.h"
#include "TFitResultPtr.h"
#include "TCanvas.h"
#include <string>
#include "TH1.h"
#include "TAxis.h"
#include <iomanip>
#include "TFitResult.h"
#define NUMBER_OF_FILE 59

int main(int argc, char **argv){
  if(argc < 2){
    std::cerr <<"Using "<< argv[0] <<  " <input file> " << std::endl;
    return 1;
  }
 std::ifstream infile;
  infile.open(argv[1]); 
 TApplication myapp("App",0,0);
  TCanvas c1;
  c1.SetFillColor(42);
  c1.SetGrid();
  TH1I my_hist("Gaus","Speed of light experiment",5, 3e8, (3.2e8)); 
  for(int i=0; i<NUMBER_OF_FILE;++i){
    int tmp;
    infile >> tmp;
  my_hist.Fill(tmp);
  }
    TFitResultPtr r=my_hist.Fit("gaus","S");
    double chi2   = r->Chi2();
    std::cout<< std::endl;
    std::cout <<" CHISQUARED (which is called FCN evidently) = " << chi2 << 
  std::endl;
  my_hist.GetYaxis()->SetTitle("Y");
  my_hist.GetXaxis()->SetTitle("X");
  my_hist.GetXaxis()->SetRange((2e8),(3,217e8));
  my_hist.Draw();
  std::cout<<"***please select quit ROOT from the File menu to exit ROOT***"<< 
  std::endl;
  myapp.Run(true);
  infile.close();
  c1.Close();
  return 0;
}
