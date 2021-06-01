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

class ReadingFileVariables
{
    protected:
        //file variables
        ifstream inFile1;
        string aux_string;
        //items
        double numbers_items;
        //vectors to store elements
        vector<double> numbers_vector;
        //counters
        int counter_numbers;
    public:
        ReadingFileVariables() {};
        virtual ~ ReadingFileVariables() {};
};

class ReadingFile: public ReadingFileVariables
{
    public:
        ReadingFile () {};
        
        void OpenFileOne(string aux_string)
        {
            inFile1.open(aux_string);
        }
        
        void CheckForErrorOne()
        {
            if(inFile1.fail())
            {
                cerr << "Error opening the file :(" << endl; //Error message
                exit(1);
            }
        }
        
        void ReadTheElementsOfTheFileNumbers()
        {
            counter_numbers = 0;
            
            while (!inFile1.eof())
            {
                inFile1 >> numbers_items;
                numbers_vector.push_back(numbers_items);
                ++counter_numbers;
            }

            cout << counter_numbers << " Number items found!" << endl;  
        }

        void ShowTheElementsOfTheFileNumbers()
        {
            for (int i = 0; i < numbers_vector.size(); ++i)
            {
                cout << numbers_vector.at(i) << endl;
            }        
        }

        void CloseFileOne(){inFile1.close();}

        ~ ReadingFile () {};
};

class Plot: public ReadingFile
{
    private:
        vector<double> total_vector;
        vector<double> cross_section_vector;
        vector<double> CM_energy;
    public:
        Plot () {};

        void PlotCrossSection () 
        {
            for (unsigned int i = 0; i < numbers_vector.size(); ++i)
            {
                total_vector.push_back(numbers_vector.at(i));
            }

            for (unsigned int i = 0; i < total_vector.size()/2; ++i)
            {
                cross_section_vector.push_back(total_vector.at(i));
            }

            for (unsigned int i = total_vector.size()/2; i < total_vector.size() - 1; ++i)
            {
                CM_energy.push_back(total_vector.at(i));
            }

            TGraph *g1 = new TGraph(CM_energy.size(), &CM_energy[0], &cross_section_vector[0]);
            TCanvas *c1 = new TCanvas("c1", "c1", 1024, 800);

            TF1 *f1 = new TF1("f1", "[2]*[1]*pow([0], 2)/( pow((x*x - pow([0], 2)), 2) + [1]/pow([0], 2) )", 90, 200);
           
            f1 -> SetParameter(0, 90);
            f1 -> SetParameter(2, 2.9*0.000001);                   
            g1 -> SetLineColor(21);
            g1 -> Fit("f1");
            g1 -> Draw("AP");
            g1 -> GetXaxis() -> SetTitle("#sqrt{s} [GeV]");
            g1 -> GetYaxis() -> SetTitle("#sigma(e^{-} + e^{+} -> #mu^{-} + #mu^{+})");
            g1 -> SetTitle("");

            double *nx = g1 -> GetX();
            double *ny = g1 -> GetY();

            for (unsigned int j = 0; j < CM_energy.size(); ++j) 
            {
                TMarker *m = new TMarker(nx[j], ny[j], 22);
                m -> SetMarkerSize(2);
                m -> SetMarkerColor(31 + j);
                m -> Draw();
            }

            c1 -> Print("plot_problem_3.png");
        }

        ~ Plot () {};
};

void CrossSectionPlot()
{
    Plot *File1 = new Plot();
    string NameOfFile = "cross_section.txt"; //Name of our data set that is located in our local storage drive

    File1 -> OpenFileOne(NameOfFile);
    File1 -> CheckForErrorOne();
    File1 -> ReadTheElementsOfTheFileNumbers();
    //File1 -> ShowTheElementsOfTheFileNumbers();
    File1 -> CloseFileOne();
    File1 -> PlotCrossSection();

    return 0;
}
