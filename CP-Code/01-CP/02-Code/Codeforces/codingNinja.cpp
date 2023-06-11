#include <bits/stdc++.h>
using namespace std;
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    auto lower_bound = [&]() -> int {
        int low = 0, high = n - 1, ans = n;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (arr[mid] >= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    };
    auto upper_bound = [&]() -> int {
        int low = 0, high = n - 1, ans = n;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (arr[mid] > k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    };
    int lb = lower_bound();
    if (lb == n || arr[lb] != k) return {-1, -1};
    return {lb, upper_bound() - 1};
}
int main(){
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (auto &it : a) cin >> it;
    firstAndLastPosition(a, n, k);
}