#include<iostream>
#include<cmath>
#include"TCanvas.h"
#include"TGraph.h"
#include"TApplication.h"
#include"TFrame.h"
#include"TGraph.h"
#include"TAttFill.h"
#include"TGraphErrors.h"
#include"TH1.h"
#include<fstream>
#define NUMBER_OF_FILE 90

int main (int argc, char **argv)
{
  while (argc < 2){
    std::cout<< "Usage: " << argv[0] << " <input file> " << std::endl;
    return false;
  }
TApplication my_app("App",0,0);

std::ifstream input;
input.open(argv[1]);
 
double x[NUMBER_OF_FILE],y[NUMBER_OF_FILE];

  for(int i=0;i<NUMBER_OF_FILE;++i){
    input >> x[i] >> y[i];
#ifdef DEBUG
    std::cout << x[i] << '\t' << y[i] << 
    std::endl;
#endif 
  }


input.close();
 
TCanvas c1("c1","c1",800,600);
c1.SetGrid();
c1.GetFrame()->SetFillColor(21);
c1.GetFrame()->SetBorderSize(12);
c1.SetFillColor(42);
TGraph my_gr(NUMBER_OF_FILE, x, y);
std::cout << "NUMBER OF FILE CHARGED IN EACH COLUMN  == " << 
				      NUMBER_OF_FILE << std::endl;
my_gr.GetHistogram()->SetXTitle("X");
my_gr.GetHistogram()->SetYTitle("Y");
my_gr.SetMarkerColor(1);
my_gr.SetMarkerStyle(2);
my_gr.SetTitle("e/m experiment");
my_gr.Draw("AP");


std::cout << "***Please select Qiut ROOT from the File menu to exit***" << 
							    std::endl;
my_app.Run(true);
c1.Close();

return 0;
}
