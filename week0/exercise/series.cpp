#include "series.h"
/*clock_t start, stop;
double duration;*/
static clock_t start, stop;
static double duration;
extern const int MAX_N = 101;
const int MAX_K = 1e5;
double test = 10;
double f_1(int n, double a[], double x){

    double p = a[0];
    for (int i = 0; i < n; i++)
        p += pow(x, i)/a[i];
    return p;
}

double f_2(int n, double a[], double x){
    double p = a[n];
    for(int i = n; i > 0; i--)
        p = a[i-1] + x * p;
    return p;
}

void duration1(){
    double a[MAX_N];
    *a = 1;
    for (int i = 1; i < MAX_N; i++)
        a[i] = 1/static_cast<double>(i);
    start = clock();
    for (int i = 0; i <= MAX_K; i++) {
        f_1(MAX_N-1, a, 1.1);
    }
    stop = clock();
    duration = static_cast<double>(stop - start)/static_cast<double>(CLK_TCK * MAX_K);
    std::cout << "f_1 consumes time " << duration << std::endl;

}

void duration2(){
    double a[MAX_N];
    *a = 1;
    for (int i = 1; i < MAX_N; i++)
        a[i] = 1/static_cast<double>(i);
    start = clock();
    for (int i = 0; i <= MAX_K; i++) {
        f_2(MAX_N-1, a, 1.1);
    }
    stop = clock();
    duration = static_cast<double>(stop - start)/static_cast<double>(CLK_TCK * MAX_K);
    std::cout << "f_2 consumes time " << duration << std::endl;


}
