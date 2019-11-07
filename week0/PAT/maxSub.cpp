#include <iostream>
const int NUM = 100000;
int maxSubSum(const int a[], int n);
int main(){
    int a[NUM];
    int n;
    std::cin >> n;
    for( int i = 0; i < n; i++){
        scanf("%d", a + i); // std::cin >> a[i];
    }
    int max = maxSubSum(a, n);
    std::cout << max;
    return 0;
}
int maxSubSum(const int a[], int n){
    int currentSum = 0;
    int maxSum = 0;
    for (int i = 0; i < n; i++){
        currentSum += a[i];
        if (currentSum > maxSum)
            maxSum = currentSum;
        else if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}
