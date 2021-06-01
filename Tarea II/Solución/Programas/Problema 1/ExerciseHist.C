#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TH1F.h"   
#include "TLegend.h"
#include "TFile.h"  
#include "TArrow.h"
#include "TLatex.h"
#include "TMath.h"
#include "TMultiGraph.h"

#include <iostream>
#include <math.h>
#include <vector> 
#include <stdlib.h>
#include <string>

using namespace std;

class Histogram
{
    protected:
        vector<double> x1, x;
        //Histogram with 10 bins ranging from 0 to 100
        TH1F *h1 = new TH1F("h1", "Histogram; x; Events", 10, 0, 100);
        TGraph *g1 = new TGraph();
    public:
        Histogram () {};
        
        void FillHistogram()
        {
            //Fill the histogram with three differents numbers
            x1.push_back(11.3); x1.push_back(25.4); x1.push_back(18.1);
            
            for (unsigned int i = 0; i < x1.size(); ++i)
            {
                h1 -> Fill(x1.at(i));
            }

            //Fill the histogram with the square and square-root of all integers from 0 to 9
            x1.clear();
            
            for (unsigned int i = 0; i <= 9; ++i)
            {
                x1.push_back(pow(i, 2));
                h1 -> Fill(x1.at(i));
            }

            x1.clear();

            for (unsigned int i = 0; i <= 9; ++i)
            {
                x1.push_back(TMath::Sqrt(i));
                h1 -> Fill(x1.at(i));
            }

            //Draw the histogram
            TCanvas *c1 = new TCanvas("c1", "c1", 1024, 800);
            h1 -> Draw();

            //Derivative cuadratic function
            x1.clear();
            
            TF1 f1("func1","pow(x, 2)", 0, 10); 

            for (unsigned int i = 0; i <= 9; ++i)
            {
                x.push_back(i);
                x1.push_back(f1.Derivative(x.at(i))); //derivative cuadratic function
                g1 -> SetPoint(i, x.at(i), x1.at(i));
            }

            g1 -> Draw("same*l");
            c1 -> Print("histogram_C.png"); 

            //Mean value and rms of the derivative of the cuadratic function
            //Mean value:
            unsigned int counter1 = 0;

            for (unsigned int i = 0; i < x1.size(); ++i)
            {
                counter1 += x1.at(i);
            }

            cout << "Mean derivative square function: " << counter1/x1.size() << endl;

            //RMS:
            unsigned int counter2 = 0;

            for (unsigned int i = 0; i < x1.size(); ++i)
            {
                counter2 += pow(x1.at(i), 2); 
            }

            cout << "RMS derivative square function: " << TMath::Sqrt(counter2/x1.size()) << endl;

            double error; 
            double integral = h1 -> IntegralAndError(0, 100, error, "");
            cout << "Histogram integral +- error = " << integral << " +- " << error << endl;

            //Identify the bin with the maxmun number of entries
            for (unsigned int i = 1; i <= 10; ++i)
            {
                cout << "Bin number: " << i << " Number of entries: " << h1 -> GetBinContent(i) << endl;
            }
        }

        virtual ~Histogram () {};
};


void ExerciseHist()
{
    Histogram *obj1 = new Histogram();
    obj1 -> FillHistogram();
}
