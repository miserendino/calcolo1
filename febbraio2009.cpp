#include <iostream>
#include "lib.hpp"
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

int main(){
unsigned int prova = conta();
std::cout << prova << std::endl;
double x[200],y[200];
loadR2(x,y,200);
TApplication my_app("App",0,0);

 
TCanvas c1("c1","c1",800,600);
c1.SetGrid();
c1.GetFrame()->SetFillColor(21);
c1.GetFrame()->SetBorderSize(12);
c1.SetFillColor(42);
TGraph my_gr(prova/2, x, y);
std::cout << "NUMBER OF FILE CHARGED IN EACH COLUMN  == " << 
				      prova/2 << std::endl;
my_gr.GetHistogram()->SetXTitle("X");
my_gr.GetHistogram()->SetYTitle("Y");
my_gr.SetMarkerColor(2);
my_gr.SetMarkerStyle(2);
my_gr.SetTitle("linear fit");
my_gr.Draw("AP");
my_gr.Fit("pol1");

std::cout << "***Please select Qiut ROOT from the File menu to exit***" << 
							    std::endl;
my_app.Run(false);
c1.Close();

return 0;

 
}
