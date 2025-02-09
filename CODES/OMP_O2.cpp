#include <iostream>
#include<random>
#include <ctime>
#ifdef _OPENMP
	#include <omp.h>
#endif
#include <chrono>
#include "functions.h"
using namespace std;
bool checkSymOMP(float *matrix,int n,int thr);
void matTransposeOMP(float *matrix,float *trans,int n,int thr);
int main(int argc, const char * argv[]) {

    bool symm;
    int n,thr;
  cout<<argv[1]<<endl;
     n=pow(2,atoi(argv[1]));
  float *matrix= new float[n * n];
float *transpose= new float[n * n];

   
initializ(matrix, n);
for(int i=1;i<=64;i *=2){
  cout<<"Number of threads: "<<i<<endl;
auto start_cron = chrono::high_resolution_clock::now();
     matTransposeOMP(matrix,transpose ,n,i);
 auto end_cron = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_cron - start_cron; 
    cout << "Time taken by the Transposition code OMP: " << elapsed.count() << " seconds" <<endl;    
   symm=checkSymOMP(matrix, n,i);
   if(symm==true) cout<<"is symmetric"<<endl;
    else cout<<"is not symmetric"<<endl;
} 

return 0;
}

void matTransposeOMP(float *matrix,float *trans,int n, int thr){
    //divide the matrix in 2 submatrixes and parallalize
    #ifdef _OPENMP 
#pragma omp parallel num_threads(thr) 
{   
 #pragma omp unroll(4) schedule(dynamic)
  #pragma omp for 
    for(int i=0;i<n/2;i+=4){
        for(int j=0;j<n;j+=4){
         trans[j * n + i]=matrix[i * n + j];
        trans[j * n + i+1]=matrix[i * n + j+1];
         trans[j * n + i+2]=matrix[i * n + j+2];
     trans[j * n + i+3]=matrix[i * n + j+3];
        }
    }  
    #pragma omp unroll(4)  schedule(dynamic)
      #pragma omp for 
    for(int i=n/2;i<n;i+=4){
        for(int j=0;j<n;j+=4){
             trans[j * n + i]=matrix[i * n + j];
        trans[j * n + i+1]=matrix[i * n + j+1];
         trans[j * n + i+2]=matrix[i * n + j+2];
         trans[j * n + i+3]=matrix[i * n + j+3];
        }
    }  

}  
#endif

}
 

bool checkSymOMP(float *matrix,int n,int thr){
  bool check=true;
  #ifdef _OPENMP
#pragma omp parallel num_threads(thr) 
{
   #pragma omp unroll(4) schedule(dynamic)
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            if(matrix[j * n + i]!=matrix[i * n + j]) {
                check=false;
            }
        }
    }
     #pragma omp unroll(4) schedule(dynamic)
    for(int i=n/2;i<n;i++){
        for(int j=0;j<n;j++){   
           if(matrix[j * n + i]!=matrix[i * n + j]) {
                check=false;
            }
        }
    }
}
#endif
    return check;
}
