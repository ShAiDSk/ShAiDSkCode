#include <bits/stdc++.h>
using namespace std;
#define nln '\n'
#define trace(x) cerr << #x << ": " << x << nln

int main(){
    for (int i = 1; i <= 10; i++){
        cout << "Multiplication Table: " << i << nln;
        for (int j = 1; j <= 10; j++){
            cout << i << " * " << j << ": " << i * j << nln;
        }
        cout << nln;
    }
}