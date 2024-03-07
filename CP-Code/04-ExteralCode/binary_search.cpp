#include <bits/stdc++.h>
using namespace std;

int binary_search_recursion(int n, vector <int> arr, int ele){
    int start = 0, last = n - 1;
    if (start > last) return -1;
    int mid = (start + last) / 2;
    if (arr[mid] == ele) return mid;
    if (arr[mid] > ele) last = mid - 1;
    else start = mid + 1;
    return binary_search_recursion(n, arr, ele);
}

int main()

int main(){
    int n, ele; cin >> n >> ele;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    // auto Binary_search = [&](int n, vector <int> a, int ele) -> int {
    //     int start = 0, end = n - 1;
    //     while(start <= end){
    //         int mid = (start + end) / 2;
    //         if (a[mid] == ele) return mid;
    //         if (a[mid] < ele) start = mid + 1;
    //         else end = mid - 1;
    //     }
    //     return -1;
    // };
    cout << binary_search_recursion(n, a, ele) << endl;
}