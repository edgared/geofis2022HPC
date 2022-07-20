#!/bin/bash

#SBATCH --nodes=2
#SBATCH --ntasks-per-node=1
#SBATCH --partition=mycluster

cd $SLURM_SUBMIT_DIR

mpirun ./hello
