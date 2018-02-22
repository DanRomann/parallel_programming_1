#include <iostream>
#include <omp.h>
#include <iomanip>

using namespace std;

const int N = 10;

void print_arr(int a[N][N]){
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<setw(4)<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int A[N][N] = {{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},
                   {1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},
                   {1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4}};
    cout<<"Non parallel :"<<endl;
    for(int i = 2; i < N; i++)
        for(int j = 2; j < N; j++)
            A[i][j] = A[i-2][j] + A[i][j-2];
    print_arr(A);

    int B[N][N] = {{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},
                   {1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4},
                   {1,2,3,4,5,6,7,8,2,4},{1,2,3,4,5,6,7,8,2,4}};

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
}