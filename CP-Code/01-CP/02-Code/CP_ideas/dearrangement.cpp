#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<int, int> freq;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
        a.push_back(make_pair(x, i));
    }

    // checking...
    // for (auto &it : freq) {
    //     cout << it.first << " : " << it.second << endl;
    // }

    // find element with maximum frequency
    int maxi_freq = 0;
    for (auto it : freq){
        maxi_freq = max(maxi_freq, it.second);
    }
    // for (auto it = freq.begin(); it != freq.end(); it++){
    //     if (it->second > maxi_freq) maxi_freq = it->second;
    // }
    // cout << maxi_freq << endl;
    sort(a.begin(), a.end());
    auto b = a;
    // shift b with max frequency position to right
    for (int i = 0; i < n; i++){
        b[(i + maxi_freq) % n] = a[i];
    }
    // checking...
    // for (auto it : b) {
    //     cout << it.first << " : " << it.second << endl;
    // }
    int ans[n];
    for (int i = 0; i < n; i++){
        ans[a[i].second] = b[i].first;
    }
    // outputting the final answer
    for (int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}