class MadgraphCardsGenerator_ttbar(object):
    def __init__(self, number_initializer):
        self.number = number_initializer
    
    def Generator(self):
        aux = ["set group_subprocesses Auto"
       ,"set ignore_six_quark_processes False"
       ,"set gauge unitary"
       ,"set complex_mass_scheme False"
       ,"import model sm"
       ,"define p = g u c d s u~ c~ d~ s~"
       ,"define j = g u c d s u~ c~ d~ s~"
       ,"define l+ = e+ mu+"
       ,"define l- = e- mu-"
       ,"define vl = ve vm vt"
       ,"define vl~ = ve~ vm~ vt~"
       ,"generate p p > t t~ > l- vl~ b b~ j j"
       ,"add process p p > t t~ > l+ vl b b~ j j"
       ,"output /data/atlas/dbetalhc/exphys/ttbar_events/ttbar" + str(self.number)
       ,"launch -i"
       ,"multi_run 1"
       ,"pythia=ON"
       ,"pgs=OFF"
       ,"delphes=ON"
       ,"set run_card ptj 40"
       ,"set cut_decays True"
       ,"set ptb 40"
       ,"set ptl 40"
       ,"set ebeam1 7000"
       ,"set ebeam2 7000"
       ,"set nevents 50000"
       ,"print_results --path=/data/atlas/dbetalhc/exphys/ttbar_events/ttbar" + str(self.number) + "/cs.txt --format=short"]
        
        return aux


class MadgraphCardsGenerator_tW(object):
    def __init__(self, number_initializer):
        self.number = number_initializer
    
    def Generator(self):
        aux = ["set group_subprocesses Auto"
       ,"set ignore_six_quark_processes False"
       ,"set gauge unitary"
       ,"set complex_mass_scheme False"
       ,"import model sm"
       ,"define p = g u c d s b u~ c~ d~ s~ b~"
       ,"define j = g u c d s u~ c~ d~ s~"
       ,"define l+ = e+ mu+"
       ,"define l- = e- mu-"
       ,"define vl = ve vm vt"
       ,"define vl~ = ve~ vm~ vt~"
       ,"generate p p > t w-"
       ,"add process p p > t~ w+"
       ,"output /data/atlas/dbetalhc/exphys/tW_events/tW" + str(self.number)
       ,"launch -i"
       ,"multi_run 1"
       ,"pythia=ON"
       ,"pgs=OFF"
       ,"delphes=ON"
       ,"set run_card ptj 40"
       ,"set cut_decays True"
       ,"set ptb 40"
       ,"set ptl 40"
       ,"set ebeam1 7000"
       ,"set ebeam2 7000"
       ,"set nevents 10000"
       ,"print_results --path=/data/atlas/dbetalhc/exphys/tW_events/tW" + str(self.number) + "/cs.txt --format=short"]
        
        return aux


class MadgraphCardsGenerator_WW(object):
    def __init__(self, number_initializer):
        self.number = number_initializer
    
    def Generator(self):
        aux = ["set group_subprocesses Auto"
       ,"set ignore_six_quark_processes False"
       ,"set gauge unitary"
       ,"set complex_mass_scheme False"
       ,"import model sm"
       ,"define p = g u c d s u~ c~ d~ s~"
       ,"define j = g u c d s u~ c~ d~ s~"
       ,"define l+ = e+ mu+"
       ,"define l- = e- mu-"
       ,"define vl = ve vm vt"
       ,"define vl~ = ve~ vm~ vt~"
       ,"generate p p > w+ w-"
       ,"output /data/atlas/dbetalhc/exphys/WW_events/WW" + str(self.number)
       ,"launch -i"
       ,"multi_run 1"
       ,"pythia=ON"
       ,"pgs=OFF"
       ,"delphes=ON"
       ,"set ptj 40"
       ,"set ptb 40"
       ,"set ptl 40"
       ,"set ebeam1 7000"
       ,"set ebeam2 7000"
       ,"set nevents 50000"
       ,"print_results --path=/data/atlas/dbetalhc/exphys/WW_events/WW" + str(self.number) + "/cs.txt --format=short"]
        
        return aux


for i in range(0, 11):
    obj = [MadgraphCardsGenerator_ttbar(i), MadgraphCardsGenerator_tW(i), MadgraphCardsGenerator_WW(i)]
    paths = ["/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/ttbar_cards/" + "ttbar" + str(i) + ".dat"
               ,"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/tW_cards/" + "tW" + str(i) + ".dat"
               ,"/user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/WW_cards/" + "WW" + str(i) + ".dat"]    
    
    for j in range(len(obj)):
        textfile = open(paths[j], "w")
        
        for k in range(len(obj[j].Generator())):
            textfile.write(obj[j].Generator()[k] + "\n")
    
        textfile.close() 
     