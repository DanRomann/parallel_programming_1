#include <iostream>
#include <iomanip>
#include <omp.h>

using namespace std;

void time_test(int count){
    double timer = omp_get_wtime();
    cout<<setw(5)<<count<<"|";
#pragma omp parallel for schedule(static, count)
    for(int i = 0; i < 10000; i++){}
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, count)
    for(int i = 0; i < 10000; i++){}
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(guided, count)
    for(int i = 0; i < 10000; i++){}
    cout<<setw(12)<<omp_get_wtime() - timer<<"|"<<endl;
}

int main2(){
    cout<<setw(6)<<"n|"<<setw(13)<<"static|"<<setw(13)<<"dynamic|"<<setw(13)<<"guided|"<<endl;
    time_test(1);
    time_test(10);
    time_test(100);
    time_test(1000);
}