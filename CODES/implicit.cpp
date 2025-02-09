#include <iostream>
#include<random>
#include <ctime>

#include <chrono>
#include "functions.h"
using namespace std;
int main(int argc, const char * argv[]) {
  cout<<"Implicit"<<endl;
    bool symm;
    int n;
  cout<<argv[1]<<endl;
     n=pow(2,atoi(argv[1]));
  float *matrix= new float[n * n];
float *transpose= new float[n * n];
initializ(matrix, n);


 auto start_cron = chrono::high_resolution_clock::now();
    matTransposeImp(matrix,transpose ,n);
  auto end_cron = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_cron - start_cron;
    cout << "Time taken by the Transposition code Implicit:" << elapsed.count() << " seconds" <<endl;   
    symm=checkSymImp(matrix, n);
    if(symm==true) cout<<"is symmetric"<<endl;
    else cout<<"is not symmetric"<<endl;
    return 0;

}






