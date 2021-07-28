#!/bin/bash
#SBATCH -p short                                                                                                                                                                                                         
#SBATCH --job-name=myjob                                                                                                                                                                                            
#SBATCH -o myjob_out                                                                                                                                                                                                
#SBATCH -e myjob_err                                                                                                                                                                                                
#SBATCH --time=72:00:00                                                                                                                                                                                
#SBATCH --cpus-per-task=4                                                                                                                                                                                               
#SBATCH --mail-type=ALL                                                                                                                                                                                             
#SBATCH --mail-user=sebastian.fuenzalidg@usm.cl                                                                                                                                                                                       


echo "Program Output begins: "

mkdir /data/atlas/dbetalhc/exphys/ttbar_events

use gcc61
source /opt/software/root/6.10.06-gcc61/setup.sh
./mg5_aMC /user/e/exphys02/F-sicaExperimental/ExpPhysFinalProyect/CharginoPairProduction/ttbar.dat

