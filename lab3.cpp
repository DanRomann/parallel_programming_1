#include <iostream>
#include <omp.h>

using namespace std;

int sum_critical(int a[], int size){
    double time = omp_get_wtime();
    int sum = 0;
    omp_set_num_threads(4);
#pragma omp parallel for
    for(int i = 0; i < size; i++)
    {
#pragma omp critical
        {
            sum += a[i];
        }
    };
    cout<<"sum(critical) = "<<sum<<" time = "<<omp_get_wtime() - time<<endl;
    return sum;
}

int sum_reduction(int a[], int size){
    double time = omp_get_wtime();
    int sum = 0;
    omp_set_num_threads(4);
#pragma omp parallel for reduction(+: sum)
    for (int i=0;i<size;i++)
    {
            sum += a[i];
        }
    cout<<"sum(reduction) = "<<sum<<" time = "<<omp_get_wtime() - time<<endl;
    return sum;
}

int m1ain1(){
    int a[] = {2,3,4,5,6,7};
    int size = 6;
    sum_critical(a, size);
    sum_reduction(a, size);
    return 0;
}