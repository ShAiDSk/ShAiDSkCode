/*/ Author: ShAiDSk /*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
/*/---------------------------From(PBDS)----------------------/*/
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>; 

/*/---------------------------IO(Debugging)----------------------/*/
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
istream& operator >> (istream &is, T_container &v) { 
   for (T &it : v) is >> it; return is;
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
   return os << '(' << p.first << ", " << p.second << ')'; 
}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator << (ostream &os, const T_container &v) { 
   os << '{'; string sep; 
   for (const T &x : v) os << sep << x, sep = ", "; 
   return os << '}'; 
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{"; string sep;
    while(!U.empty()){
        out << sep << U.front(); sep = ", "; U.pop();
    }
    return (out << "}");
}
/*/---------------------------Traces(Debug)----------------------/*/
#define TRACE
#define ShAiDSk TRACE
#ifdef ShAiDSk
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << '\n';
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
         int count_open = 0, len = 1;
         for(int k = 1; ; ++k){
            char cur = *(names + k);
            count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));
            if (cur == ',' && count_open == 0){
               const char* comma = names + k;
               cerr.write(names, len) << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
    }
#else
    #define trace(...) 1
#endif
/*/---------------------------------RNG--------------------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
/*/---------------------------Defines && Typedefs----------------------/*/
#define PI       3.14159265358979323846264338327950288419716939937510
#define rall(x)  ((x).rbegin()),((x).rend())
#define all(x)   ((x).begin()),((x).end())
#define INF      9223372036854775807LL
typedef unsigned long long ull; 
#define pb       push_back
#define ppb      pop_back
typedef long double lld;
#define newline  '\n'
typedef long long ll;
/*/--------------------Helping Functions------------------------------/*/
struct Help{
    vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
    void swap(ll &a, ll &b) {a = (a ^ b); b = (a ^ b); a = (a ^ b);}
    void google(int t) {cout << "Case #" << t << ": ";}
    ll lcm(ll a, ll b) {return ((a * b) / __gcd(a, b));}
    bool revsort(ll a, ll b) {return a > b;}
    // Decimal to Binary Converter
    string to_binary(int n){
        string s;
        while (n > 0){
            // if (n % 2) s += '1';
            // else s += '0';
            s += (n % 2 ? '1' : '0');
            n >>= 1; // n /= 2;
        }
        reverse(all(s));
        return s;
    }
    // Power of a number.
    ll power(int base, int pow){
        if (pow == 0) return 1;
        else if (base == 1) return base;
        else return base * power(base, pow - 1);
    }
    // getUnique Number.
    void getUnique(vector <int> &a) {
        sort(all(a));
        a.erase(unique(all(a)), a.end());
    }
    ll x(ll n, ll digit){
        if (n == 1) return digit;
        digit *= digit;
        return x(n - 1, digit);
    }
    ll gcd(ll a, ll b){
        ll temp = a + b;
        a = (a > b)? a : b;
        b = temp - a;
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
};
/*/-----------------------------Code begins----------------------------------/*/
struct comp{
    template <typename T>
    bool operator()(const T &a, const T &b) const{
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};
template <typename T> void out(T t){cerr << t << newline;}
template <typename T, typename... Args>
void out(T t, Args... args){
    cerr << t << newline;
    out(args...);
}
struct Answer{
    int get(char c){
        return (int(c) - 'a' + 1);
    }
    // it will print all the subsequence of required sum.
    void printSubSequenceRequiredSum(int ind, vector <int> &ds, int sum, int requiredSum, vector <int> a, int n){
        if (ind == n){
            if (sum == requiredSum){
                for (auto &it : ds) cout << it << ' ';
                cout << newline;
            }
            return;
        }
        ds.pb(a[ind]);
        sum += a[ind];
        printSubSequenceRequiredSum(ind + 1, ds, sum, requiredSum, a, n);
        sum -= a[ind];
        ds.ppb();
        // Not Pick Recursion call
        printSubSequenceRequiredSum(ind + 1, ds, sum, requiredSum, a, n);
    }
    // it will print a single subsequence of required sum.
    bool printSingeSubSequenceRequiredSum(int ind, vector <int> &ds, int sum, int requiredSum, vector <int> a, int n){
        if (ind == n){
            // condition satisfied.
            if (sum == requiredSum){
                for (auto &it : ds) cout << it << ' ';
                cout << newline;
                return true;
            }
            // condition not satisfied.
            return false;
        }
        ds.pb(a[ind]);
        sum += a[ind];
        if (printSingeSubSequenceRequiredSum(ind + 1, ds, sum, requiredSum, a, n) == true){
            return true;
        }
        sum -= a[ind];
        ds.ppb();
        if (printSingeSubSequenceRequiredSum(ind + 1, ds, sum, requiredSum, a, n) == true){
            return true;
        }
        return false;
    }
    // counting the number of subsequence of the required sum.
    int cntSubSequenceRequiredSum(int ind, int sum, int requiredSum, vector <int> a, int n){
        if (ind == n){
            if (sum == requiredSum) return 1;
            else return 0;
        }
        sum += a[ind];
        int l = cntSubSequenceRequiredSum(ind + 1, sum, requiredSum, a, n);
        sum -= a[ind];
        int r = cntSubSequenceRequiredSum(ind + 1, sum, requiredSum, a, n);
        return l + r;
    }
    void Solve(){
        //* /mnt/c/Users/91956/OneDrive/Desktop/ShAiDSkCode/CP-Code/05-Recursion/Recursion-Striver
        // g++ 07-print-all-patterns.cpp -o 07-print-all-patterns.out; ./07-print-all-patterns.out < in > out; cat cerr.txt; echo "Local Output"; cat out
        Help h;
        int n, requiredSum; cin >> n >> requiredSum;
        vector <int> a(n);
        for (auto &it : a) cin >> it;
        vector <int> ds;
        // it will print all the subsequence of required sum.
        printSubSequenceRequiredSum(0, ds, 0, requiredSum, a, n);
        // it will print a single subsequence of required sum.
        printSingeSubSequenceRequiredSum(0, ds, 0, requiredSum, a, n);
        // count the number of subsequence of the required sum.
        cout << cntSubSequenceRequiredSum(0, 0, requiredSum, a, n) << newline;
    }
};
/*/--------------------------------------------------------------------------/*/
/*/ ShAiDSk_Solve() Definition /*/
void ShAiDSk_Solve(){
    int tc = 1; // cin >> tc;
    while (tc--){Answer a; a.Solve();}
}
/*/ MainFunction() /*/
signed main(int argc, char **argv, char **envp){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifdef ShAiDSk
    freopen("cerr.txt", "w", stderr);
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#endif
    auto start1 = high_resolution_clock::now();
    cout << setprecision(15) << fixed; cerr << setprecision(10) << fixed;
/* ShAiDSk_Solve() Call */
    ShAiDSk_Solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ShAiDSk
    cerr << "Time: " << duration.count() / 1000 << " milliseconds" << newline;
#endif
    return 0;
}