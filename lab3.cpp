#include <iostream>
#include <omp.h>

using namespace std;

int sum_critical(int a[], int size){
    int sum = 0;
    double time = omp_get_wtime();
#pragma omp parallel for
    for(int i = 0; i < size; i++){
#pragma omp critical{
        sum += a[i];
        };
    }

    return sum;
};

int main(){

}