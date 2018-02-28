#include <iostream>
#include <omp.h>
#include <iomanip>

using namespace std;

const int N = 10001;

void fill_array(int** arr){
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++)
            arr[i][j] = rand()%100 + 1;
        }
}

void print_arr(int** a){
    for(int i = N -5 ; i < N; i++) {
        for (int j = N -5; j < N; j++) {
            cout<<setw(10)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int** A = new int*[N];
    for(int i = 0; i < N; i++)
        A[i] = new int[N];
    fill_array(A);
    int** B = new int*[N];
    for(int i = 0; i < N; i++){
        B[i] = new int[N];
        for(int j = 0; j < N; j++)
            B[i][j] = A[i][j];
    }
    double timer = omp_get_wtime();
    cout<<"Non parallel :"<<endl;
    for(int i = 2; i < N; i++)
        for(int j = 2; j < N; j++)
            A[i][j] = A[i-2][j] + A[i][j-2];
    cout<<omp_get_wtime()-timer<<endl;
    print_arr(A);

    timer = omp_get_wtime();
    for(int i = 2; i < N; i++){
#pragma omp parallel for
        for(int j = 0; j < i - 1; j++) {
            //cout<<"("<<2+j<<","<<i-j<<"),";
            B[2 + j][i - j] = B[2 + j - 2][i - j] + B[2 + j][i - j - 2];
        }
        //cout<<endl;
    }
    for(int i = 2 + 1; i < N; i++){
#pragma omp parallel for
        for(int j = 0; j < N - i; j++){
            //cout<<"("<<2+j<<","<<i-j<<"),";
            B[i + j][N - 1 - j] = B[i + j - 2][N - 1 - j] + B[i + j][N - 1 - j - 2];
        }
        //cout<<endl;
    }
    cout<<"Parallel:"<<endl;
    print_arr(B);
    cout<<omp_get_wtime()-timer<<endl;
}