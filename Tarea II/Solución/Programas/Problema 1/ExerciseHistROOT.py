import ROOT
import numpy as np

class Histogram:
    def __init__(self, data1, data2):
        hist = ROOT.TH1F("variable", "Histogram; x; events", 10, 0, 100)
        g1 = ROOT.TGraph()

        for i in range(data1.size):
            hist.Fill(data1[i])

        for i in range(data2.size):
            g1.SetPoint(i, i, data2[i])

        print('Histogram integral: ' + str(hist.Integral()))
        
        for i in range(1, 11):
            print("Bin number: " + str(i) + ' Number of entries: ' + str(hist.GetBinContent(i)))

        c1 = ROOT.TCanvas("c1", "c1", 1024, 800)
        hist.Draw()
        g1.Draw("same*l")
        c1.Print("histogram_python_ROOT.png")

class MeanAndRMS:
    def __init__(self, data):
        counter1 = 0
        for i in range(0, data.size):
            counter1 += data[i]
        mean = counter1/data.size
        print('Mean derivative square function: ' + str(mean))

        counter2 = 0
        for i in range(0, data.size):
            counter2 += data[i]**2
        RMS = np.sqrt(counter2/data.size)
        print('RMS derivative square function: ' + str(RMS))

data_list_1 = [11.3, 25.4, 18.1]
data_list_2 = []

for i in range(0, 10):
    data_list_1.append(i**2)
    data_list_1.append(np.sqrt(i))

f1 = ROOT.TF1("func1","x**2", 0, 10)

for i in range(0, 10):
    data_list_2.append(f1.Derivative(i))

data_np_array_1 = np.array(data_list_1)
data_np_array_2 = np.array(data_list_2)

obj1 = Histogram(data_np_array_1, data_np_array_2)
obj2 = MeanAndRMS(data_np_array_2)
        
