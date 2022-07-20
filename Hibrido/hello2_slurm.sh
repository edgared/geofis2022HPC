#!/bin/bash

#SBATCH --job-name=hello
#SBATCH --output=hello.out
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2
#SBATCH --partition=mycluster

cd $SLURM_SUBMIT_DIR

mpirun ./hello
