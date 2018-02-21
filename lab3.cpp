#include <iostream>
#include <omp.h>

using namespace std;

int sum_critical(int a[], int size){
    double time = omp_get_wtime();
    int sum = 0;
    omp_set_num_threads(size);
#pragma omp parallel
    {
#pragma omp critical
        {
            sum += a[omp_get_thread_num()];
        }
    };
    cout<<"sum(critical) = "<<sum<<" time = "<<omp_get_wtime() - time<<endl;
    return sum;
}

int sum_reduction(int a[], int size){
    double time = omp_get_wtime();
    int sum = 0;
    omp_set_num_threads(size);
#pragma omp parallel reduction(+: sum)
        {
            sum += a[omp_get_thread_num()];
        }
    cout<<"sum(reduction) = "<<sum<<" time = "<<omp_get_wtime() - time<<endl;
    return sum;
}

int main(){
    int a[] = {2,3,4,5,6,7};
    int size = 6;
    sum_critical(a, size);
    sum_reduction(a, size);
    return 0;
}