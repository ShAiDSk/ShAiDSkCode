#include<stdio.h>
// int primes[1000];
int is_prime(int n){
    if (n == 1) return 1;
    for (int i = 2; i < n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    // int x = is_prime(n);
    if (is_prime(n)) printf("Yes");
    else printf("No");
    return 0;
}