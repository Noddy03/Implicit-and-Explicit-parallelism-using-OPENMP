# Implicit-and-Explicit-parallelism-using-OPENMP

This project aim is to understand the implicit and explicit parallelism in order to optimize two different problems , the transpose and the symmetric check  of a square matrix.  Analyze the performance and compare it with the sequential code.  
# The Repository 
The repository constains all the necessary files whoose methodologies have benn described in the paper. In the CODES folder are located all the source codes files. In the DATA AND GRAPHICS folder are located all the data and graphics whoose done for the project as stated in the paper. 
# Instructions for the reproducibility
After have uploaded the the CODES folder and the main.pbs file, it's compulsory to execude the command
```
chmod +x main.pbs
```
this will allow the file to be executed. 
After have done that execute the command
```
qsub main.pbs
```
 This will start the simulations on the short_cpuQ with 1 selected node, 32 ncpus, 64 ompthreads and 512mb of memory.
All the parameters are already assigned. At the end of the simulations a text file named 
### "matrix_parallel.txt" 
will appear which will contain all the datas concerning the time it took to compute the matrix transposition.
The pbs script contains the necessary modules for copilig the files, module load gcc91 version g++-9.1.0. 
All the files will be compiled before running. Inside there is a for loop which will run the files increasing the matrix size. 

