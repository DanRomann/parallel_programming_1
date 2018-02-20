#include <iostream>
#include <omp.h>
#include <time.h>

using namespace std;

void test(int count){
#pragma omp parallel{
    #pragma omp for schedule(static, 1)
    for
    };
}

int main(){
    double wall_timer;
#pragma omp parallel
{
    #pragma omp for private(value)
    for(int i = 0; i < 10; i++){
        value++;
        cout<<value<<endl;
        }
    };
    cout<<value<<endl;
    return 0;
}

