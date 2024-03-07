#include <bits/stdc++.h>
using namespace std;
#define nln '\n'

class Node{
public:
    int data;
    Node *next;
public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int> a = {1, 3, 5, 2, 8, 5};
    Node *y = new Node(a[0], nullptr);
    Node *z = new Node(a[1]);
    cout << (y -> data) << nln;
    cout << (z -> data) << nln;
    return 0;
}