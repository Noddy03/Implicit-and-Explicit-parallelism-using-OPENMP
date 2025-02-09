#include <omp.h>
#define max 5000
using namespace std; 

float randon_float(){
    return ((float)rand() / RAND_MAX) * (10 - 1) + 1;
}

void initializ(float *ma,int n){
    cerr<<"matrix initialization"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ma[i*n + j]=randon_float();
        }
    }
}

void stampa(float *ma,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< ma[i*n + j]<<" ";
        }
        cout<<endl;
    }
}

void matTranspose(float *matrix,float *trans,int n){ 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            trans[j * n + i]=matrix[i * n + j];
        }
    }
}
bool checkSym(float *ma,int n){
    bool check=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ma[j * n + i]!=ma[i * n + j]) {
                check=false;
            }
        }
      
    }
    return check;
}

void  matTransposeImp(float *ma,float *trans,int n){

    //divide the matrix in 4 submatrixes
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            trans[j * n + i]=ma[i * n + j];
        }
    }
    for(int i=n/2;i<n;i++){
        for(int j=0;j<n;j++){
            trans[j * n + i]=ma[i * n + j];
        }
    }  
}

bool checkSymImp(float *ma,int n){
    bool check=true;

    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            if(ma[i * n + j]!=ma[j * n + i]) {
                check=false;
            }
        }
    }

    for(int i=n/2;i<n;i++){
        for(int j=0;j<n;j++){
            if(ma[i * n + j]!=ma[j * n + i]) {
                check=false;
            }
        }
    }
  
    return check;
}
