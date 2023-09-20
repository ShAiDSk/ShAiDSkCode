#include<stdio.h>

int a[1000];
void f(int n){
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    f(n);
    for (int i = 0; i < n + 1; i++){
        printf("%d ", a[i]);
    }
    return 0;
}