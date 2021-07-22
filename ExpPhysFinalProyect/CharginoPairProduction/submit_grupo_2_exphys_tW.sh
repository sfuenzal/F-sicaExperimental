#!/bin/bash     
#SBATCH -p short                                                                                                                                                                                                     
#SBATCH --job-name=myjob                                                                                                                                                                                            
#SBATCH -o myjob_out                                                                                                                                                                                                
#SBATCH -e myjob_err                                                                                                                                                                                                
#SBATCH --mem-per-cpu=MaxMemPerNode                                                                                                                                                                                 
#SBATCH --cpus-per-task=4                                                                                                                                                                                               
#SBATCH --mail-type=ALL                                                                                                                                                                                             
#SBATCH --mail-user=sebastian.fuenzalidg@usm.cl                                                                                                                                                                                       


echo "Program Output begins: "

mkdir /data/atlas/dbetalhc/exphys/tW_events

for i in {0..10} 
do
    use gcc61
    source /opt/software/root/6.10.06-gcc61/setup.sh
    ./mg5_aMC /user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/tW_cards/tW$i.dat
done
