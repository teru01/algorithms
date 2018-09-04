#include <stdio.h>
#define M_SIZE 200
int memo[M_SIZE];
int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int nfibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != -1) return memo[n];
    return memo[n] = nfibo(n-1) + nfibo(n-2);
}
int dp[200];
int fib(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    for(int i=0; i<M_SIZE; i++){
        memo[i] = -1;
    }
    int n = 20;
    nfibo(n);
    printf("fibo(n): %d\n", memo[n]);
    return 0;
}
