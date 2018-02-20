#include <iostream>
#include <omp.h>

using namespace std;

int main1() {
#pragma omp parallel num_threads(10)
    {
        cout << "Hello, World! \n";
    }
    return 0;
}