#!/bin/bash                                                                                                                                                                                                        
#SBATCH --job-name=myjob                                                                                                                                                                                            
#SBATCH -o myjob_out                                                                                                                                                                                                
#SBATCH -e myjob_err                                                                                                                                                                                                
#SBATCH --time=72:00:00                                                                                                                                                                                
#SBATCH --cpus-per-task=4                                                                                                                                                                                               
#SBATCH --mail-type=ALL                                                                                                                                                                                             
#SBATCH --mail-user=sebastian.fuenzalidg@usm.cl                                                                                                                                                                                       


echo "Program Output begins: "

for i in Analysis_Trial.C Plotting_ee.C Plotting_mumu.C Plotting_emu.C
do 
    root -q -b LastReport_$i
done
