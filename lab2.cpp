#include <iostream>
#include <iomanip>
#include <omp.h>
#include <unistd.h>

using namespace std;

void time_test(){
    double timer = omp_get_wtime();
    cout<<setw(5)<<1<<"|";
#pragma omp parallel for schedule(static)
    for(int i = 0; i < 100; i++){}
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for(int i = 0; i < 100; i++){
    }
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for(int i = 0; i < 100; i++){
    }
    cout<<setw(12)<<omp_get_wtime() - timer<<"|"<<endl;
}
void time_test_own(){
    double timer = omp_get_wtime();
    cout<<setw(5)<<2<<"|";
#pragma omp parallel for schedule(static)
    for(int i = 0; i < 100; i++){
        if(i%2 == 1)
            sleep(1);
    }
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for(int i = 0; i < 100; i++){
        if(i%2 == 1)
            sleep(1);
    }
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for(int i = 0; i < 100; i++){
        if(i%2 == 1)
            sleep(1);
    }
    cout<<setw(12)<<omp_get_wtime() - timer<<"|"<<endl;
}
void time_first_half(){
    double timer = omp_get_wtime();
    cout<<setw(5)<<3<<"|";
#pragma omp parallel for schedule(static)
    for(int i = 0; i < 100; i++){
        if (i < 50)
            sleep(1);
    }
    cout<<setw(12);
    cout<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for(int i = 0; i < 100; i++){
        if (i < 50)
            sleep(1);
    }
    cout<<setw(12)<<omp_get_wtime() - timer<<"|";
    timer = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for(int i = 0; i < 100; i++){
        if (i < 50)
            sleep(1);
    }
    cout<<setw(12);
    cout<<omp_get_wtime() - timer<<"|"<<endl;
}

int main2(){
    cout<<setw(6)<<"n|"<<setw(13)<<"static|"<<setw(13)<<"dynamic|"<<setw(13)<<"guided|"<<endl;
    time_test();
    time_test_own();
    time_first_half();

}