#include <bits/stdc++.h>
using namespace std;
#define nln "\n"
#define trace(x) cerr << #x << ": " << x << nln;
#define all(x) ((x).begin()),((x).end())

auto to_binary(int n){
    string s = "";
    while (n > 0){
        s += (n & 1? "1" : "0");
        n /= 2;
        // trace(n);
    }
    reverse(s.begin(), s.end());
    return s;
};

int main (){
    int n; cin >> n;
    string s; cin >> s;
    // Lambda function
    // auto to_binary = [&] (int n) -> string {
    //     string s = "";
    //     while (n > 0){
    //         s += (n & 1? "1" : "0");
    //         n /= 2;
    //         // trace(n);
    //     }
    //     reverse(s.begin(), s.end());
    //     return s;
    // };
    auto to_decimal = [&](string s) -> int {
        reverse(all(s));
        int ans = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1'){
                ans += pow(2, i);
            }
            // trace(ans);
        }
        return ans;
    };
    cout << to_binary(n) << nln;
    cout << to_decimal(s) << nln;
    return 0;
}