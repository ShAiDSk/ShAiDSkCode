#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
             // 0  1  2  3  4  5  6  7  8  9
    int a[n] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    auto binary_search = [&]() -> int {
        int ans = -1;
        int low = 0, hi = n;
        while (low <= hi){
            // int mid = low + hi >> 1;
            int mid = low + ((hi - low) >> 1);
            if (a[mid] == 1){
                ans = mid;
                hi = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    };
    cout << binary_search();
    return 0;
}