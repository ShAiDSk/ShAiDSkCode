#include <bits/stdc++.h>
using namespace std;
#define nln '\n';

int main(){
    // vector <int> a = {4, 2, 5, 3, 9, 6, 4};
    vector<pair<int, int>> a {{1, 2}, {4, 3}, {2, 5}, {5, 9}};
    // always remember if the ele1 before ele2 return true else return false
    auto comp = [&](int ele1, int ele2) -> bool {
        // return (ele1 <= ele2? true : false);
        if (ele1 < ele2) return false;
        return true;
    };
    // sort(a.begin(), a.end(), comp);
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    for (auto &it : a) cout << it.first << ' ' << it.second << ' ';
    cout << nln;
    return 0;
}