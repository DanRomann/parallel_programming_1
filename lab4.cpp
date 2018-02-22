#include <iostream>
#include <omp.h>

using namespace std;

int main4(){
    omp_set_num_threads(4);
#pragma omp parallel
    {
        cout<<"Message 1 \n";
        cout<<"Message 2 \n";
#pragma omp barrier
        cout<<"Message 3 \n";
    };
    return 0;
}