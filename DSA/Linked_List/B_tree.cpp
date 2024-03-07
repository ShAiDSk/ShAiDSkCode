#include <bits/stdc++.h>
using namespace std;
#define nln '\n'
#define trace(x) cerr << #x << ' ' << x << nln
const N = 1e5 + 5;

class b_tree{
public:
    int data;
    b_tree *next;
public:
    b_tree(int new_data){
        data = new_data;
        b_tree -> next = nullptr;
    }
    b_tree(int new_data, b_tree *new_next){
        data = new_data;
        b_tree -> new_next = new_next;
    }
    b_tree(int new_data[], b_tree *new_next){
        for (int i = 0; i < new_data.length(); i++){
            b_tree *temp = 
        }
        b_tree -> new_next = new_next;
    }
};

int main(){
    vector <int> a[N];
    for (auto &it : a){
        for (auto it : i) cin >> i;
    }
    for (auto it : a){
        for (auto it : i){
            cout << i << ' ';
        }
        cout << nln;
    }
    for (int i = 0; i < a.size(); i++){
        
    }
}