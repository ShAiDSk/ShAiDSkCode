/*/ Author: ShAiDSk /*/
#ifndef __LOCAL_ShAiDSk__
    #pragma GCC optimize("03")
    // #pragma GCC target("avx,avx2,sse4.2,bmi,bmi2,popcnt,lzcnt") // Gives SIGILL on SPOJ
#endif
#include <bits/stdc++.h>

/*/---------------------------if has include ----------------------/*/
// #if __has_include(<atcoder/all>)
//     #include <atcoder/all>
//     using namespace atcoder;
//     // using mint = modint998244353;
//     // using mint = modint1000000007;
//     // using mint = modint;
// #endif
/*/-------------------------------------------------/*/

// https://atcoder.github.io/ac-library/production/document_en/ //! (AC(AtCoder) Library Document (production))
// #include <atcoder/all>
// https://atcoder.github.io/ac-library/document_en/modint.html //! (included in grader)
// #include <atcoder/modint>
// #include <atcoder/dsu> // For Graph or Trees
// #include <atcoder/string> // For String
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
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
// Comparator: comparing two elements
struct comp{
    template <typename T>
    bool operator()(const T &a, const T &b) const{
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};
// Sort by second element
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const pair<T1,T2> &left, const pair<T1,T2> &right) {
        Pred p;
        return p(left.second, right.second);
    }
};
/*/---------------------------Traces(Debug)----------------------/*/
// #define TRACE
// #define ShAiDSk TRACE
// #ifdef ShAiDSk
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
            //    cout << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
    }
// #else
    // #define trace(...) 1
// #endif
/*/---------------------------------RNG--------------------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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
#define cerr(x) cout << #x << " : " << (x) << '\n'
#define out(x) cout << #x << " : " << (x) << ' '
const long double PI = acos(-1.0); // 3.14159265358979323846264338327950288419716939937510
#define rall(x)  ((x).rbegin()),((x).rend())
#define popcount(x) __builtin_popcountll(x)
#define all(x)   ((x).begin()),((x).end())
typedef long long ll;
typedef unsigned long long ull; 
typedef long double lld;
const int INF = int(1e9);
const ll INF64 = ll(1e18); // 9223372036854775807LL
#define IntMax   2147483647 // 2147483647 = INT_MAX
#define IntMin   -2147483647 // -2147483647 = INT_MIN
// const int Modint = int(1e9) + 7; // 998244353
const ll Modint = 998244353;
#define ef       emplace_front
#define eb       emplace_back
#define pf       push_front
#define pb       push_back
#define ppf      pop_front
#define ppb      pop_back
const lld EPS = 1e-9;
#define nln      '\n'
/*/---------------------------Helping Functions------------------------------/*/
struct Help{
    template<typename T>
    void swap(T &a, T &b) {a = (a ^ b); b = (a ^ b); a = (a ^ b);}
    template<typename T>
    void Cases(T t) {cout << "Case #" << t << ": ";}
    template<typename T>
    T lcm(T a, T b) {return ((a * b) / __gcd(a, b));}
    template<typename T>
    bool revsort(T a, T b) {return a > b;}
    // Sieve of Eratosthenes to check is prime or not
    template<typename T>
    vector<T> sieve(T n){
        T*arr = new T[n + 1]();
        vector<T> vect;
        for (T i = 2; i <= n; i++){
            if (arr[i] == 0){
                vect.push_back(i);
                for (T j = 2 * i; j <= n; j += i){
                    arr[j] = 1;
                }
            }
        }
        return vect;
    }
    // Decimal to Binary Converter
    template<typename T>
    string to_binary(T n){
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
    template<typename T>
    T power(T base, T pow){
        if (pow == 0) return 1;
        else if (base == 1) return base;
        else return base * power(base, pow - 1);
    }
    // Binary Exponentiation
    template<typename T>
    T binExpo(T a, T b){
        if (b == 0) return 1;
        T x = binExpo(a, b/2);
        if (b % 2 == 0) return (x * x);
        return (x * x * a);
    }
    // getUnique Number.
    template<typename T>
    void getUnique(vector <T> &a) {
        sort(all(a));
        a.erase(unique(all(a)), a.end());
    }
    template<typename T>
    T x(T n, T digit){
        if (n == 1) return digit;
        digit *= digit;
        return x(n - 1, digit);
    }
    template<typename T>
    T gcd(T a, T b){
        T temp = a + b;
        a = (a > b)? a : b;
        b = temp - a;
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    /** Computes a^b modulo MOD in O(log MOD) time.**/
    template<typename T>
    T expo(T a, T b, T mod){
        a %= mod;
        T res = 1;
        while (b > 0){
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    template<typename T>
    T mminvprime(T a, T b){
        return expo(a, b - 2, b);
    }
    template<typename T>
    T mod_add(T a, T b, T mod){
        a = a % mod;
        b = b % mod;
        return (((a + b) % mod) + mod) % mod;
    }
    template<typename T>
    T mod_mul(T a, T b, T mod){
        a = a % mod;
        b = b % mod;
        return (((a * b) % mod) + mod) % mod;
    }
    template<typename T>
    T mod_sub(T a, T b, T mod){
        a = a % mod;
        b = b % mod;
        return (((a - b) % mod) + mod) % mod;
    }
    template<typename T>
    T mod_div(T a, T b, T mod){
        a = a % mod;
        b = b % mod;
        return (mod_mul(a, mminvprime(b, mod), mod) + mod) % mod;
    } //only for prime m
    template<typename T>
    T binomial(T a, T b, T mod){
        if (a == 0 || b == a) return 1;
        return(binomial(a - 1, b - 1, mod) + binomial(a - 1, b, mod)) % mod;
    }
};
/*/-----------------------------Code begins----------------------------------/*/
// Set OutPut:
template <typename T> void cerrSet(set <T> s){
    for (auto set = s.begin(); set != s.end(); set++){
        if (set == s.begin()) out(*set);
        else cout << *set << ' ';
    }
    cout << nln;
}
// Vector of array Output: It takes len and vector of array.
template <typename T> void cerrVectArr(int n, vector <T> a[]){
    for (int i = 0; i < n; i++){
        for (auto &it : a[i]) cout << it << ' ';
        cout << nln;
    }
}
template <typename T, typename... Args>
void arguments(T t, Args... args){
    cerr << t << nln;
    arguments(args...);
}
struct range{
    int l, r, ind;
    bool operator < (const range &other){
        if (l == other.l) return r > other.r;
        return l < other.l;
    }
};
/*/---------------------Debug or TRACE Interactive problems------------------------/*/
//* Debug or TRACE Interactive problems
struct Interator{
    int n;
    vector <int> a;
    int limitQueries = 0, queries = 0;
    Interator(int nGiven){
        n = nGiven;
        a.resize(n);
        for (int i = 0; i < n; i++){
            a[i] = random_long(1, 100);
        }
        cout << "Hidden Array: ";
        for (auto &it : a) cout << it << ' ';
        cout << endl;
    }
    // Queries or Input form codeforces
    int query(int l, int r){
        assert(l >= 1 && r <= n && l < r);
        int sum = 0;
        for (int i = l; i <= r; i++) sum += a[i - 1];
        return sum;
    }
    // Checking the output is correct or not.
    bool correctOutput(vector <int> output){
        assert(output.size() == n && output == a);
        return true;
    }
};
/*/------------------------------Global-Defines-------------------------------/*/
const int N = 1e5 + 10, M = 1e5 + 10, X = 1e5 + 10;
// int dp[N + 1];
vector<int> dp(N + 1);
// vector<vector<int>> dp(N, vector<int>(M + 1, 0));
vector<int> edges[N + 1]; // Array of vector.
vector<int> graph[N + 1];
vector<int> visited(N, 0);
/*/--------------------------------------------------------------------------/*/
struct Answer{
    Help H; // Interator codeforces = Interator(5);
    int get(char c){
        // return (int(c) - 'a' + 1);
        // return 'A' <= c and c <= 'Z'; // Check is_uppercase
        // return '0' <= c and c <= '9'; // Check is_digit
        return (int(c) - '0');
    }
    // dfs on Tree or Graph.
    int dfs(int node, int parent){
        return 0;
    }
    // Predicate function
    bool check(void){
        return false;
    }
    void Solve(int tc){
        //* /mnt/c/Users/91956/ShAiDSkCode/CP-Code/01-CP/02-Code/AtCoder
        // `{`:ÃƒÂ¢Ã‹â€ Ã¢â€šÂ¬:x:ÃƒÂ¢Ã‹â€ Ã¢â€šÂ¬:`}` || `{`:Ã¢Ë†â‚¬:x:Ã¢Ë†â‚¬:`}`
        auto let = [&](int x) -> int {
            return (x > 0 ? 1 : -1);
        };
        // Predicate function
        auto Helper = [&]() -> void {
            return;
        };
        // dfs on Tree or Graph.
        auto dfs = [&](auto dfs, int node, int parent) -> void {
            cout << node << ' ';
            for (auto &it : edges[node]){
                if (it != parent){
                    dfs(dfs, it, node);
                }
            }
        };
        // Disjoint Set Union
        auto dsu = [&]() -> void {
            return;
        };
        // for "for_each(all(a), element)" loop.
        auto element = [&](const int x) -> void {cout << x << ' ';};
        /*/-------------------------------------------------------/*/
        /*
            !Author: ShAiDSk
            ?Problem_name: B - Round-Robin Tournament 
            *Location: https://atcoder.jp/contests/abc323/tasks/abc323_b
        */ 
        /*/-------------------------------------------------------/*/
        // its.shaidsk.coder
        int n;
        string t;
        cin >> n >> t;
        vector<string> s(n);
        for (auto &it : s) cin >> it;
        vector<int> ans;
        int len = t.length();
        char a = t[0], b = t[len - 1];
        for (int i = 0; i < n; i++){
            // trace(a, b);
            if (s[i] == t){
                ans.pb(i + 1);
            }
            else if (a + s[i] == t || s[i] + b == t){
                ans.pb(i + 1);
            }
            trace(a + s[i]);
            trace(s[i] + b);
        }
        trace(ans);
    }
};
/*/--------------------------------------------------------------------------/*/
/*/ ShAiDSk_Solve() Definition /*/
void ShAiDSk_Solve(){
    int tc = 1; // cin >> tc;
    // while (tc--){Answer a; a.Solve();}
    for (int i = 1; i <= tc; i++){Answer a; a.Solve(i);}
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
    cerr << "Time: " << duration.count() / 1000 << " milliseconds" << nln;
#endif
    return 0;
}