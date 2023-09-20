#include <bits/stdc++.h>
using namespace std;
#define nln '\n'
#define trace(x) cerr << #x << ": " << x << nln

int a[1000];
void f(int n){
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
}
int main(){
    int n; cin >> n;
    // a[0] = 0;
    // a[1] = 1;
    f(n);
    for (int i = 0; i < n + 1; i++){
        cout << a[i] << ' ';
    }
}