/*/ Author: ShAiDSk /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
using namespace std;
using namespace chrono;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

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


// #define ShAiDSk
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
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
    }
// #else
    // #define trace(...) 1
// #endif

/*/---------------------------RNG----------------------/*/
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

/*/---------------------------Defines----------------------/*/
#define PI       3.14159265358979323846264338327950288419716939937510
#define rall(x)  ((x).rbegin()),((x).rend())
#define all(x)   ((x).begin()),((x).end())
typedef unsigned long long ull; 
#define pb       push_back
#define ppb      pop_back
typedef long double lld;
#define newline  '\n'
#define INF      1e18
typedef long long ll;
/*/--------------------------------------------------------------------------/*/
ll factorial(ll n){
    ll res = 1;
    for (int i = n; i >= 2; i--){
        res *= i;
    }
    return res;
}
vector <ll> primeFact(ll n){
    vector <ll> primes;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            // int cnt = 0;
            while (n % i == 0) {
                // cnt++;
                primes.pb(i);
                n /= i;
            }
            // trace(n);
            // cout << i << '^' << cnt << newline;
        }
    }
    if (n > 1) primes.pb(n);
    // trace(primes);
    // for (auto &it : primes) cout << it << ' ';
    // Time Complexity - O(sqrt(N));
    return primes;
}
void solve(){
    ll n; cin >> n;
    ll fact = factorial(n);
    // trace(fact);
    // primeFact(fact);
    vector <ll> ans = primeFact(fact);
    for (auto &it : ans) cout << it << ' ';
}
/*/-----------------------------Code begins----------------------------------/*/
/*/ ShAiDSk_Solve() Defination /*/
void ShAiDSk_Solve(){
    ll t = 1; // cin >> t;
    while (t--) solve();
}

/*/ mainFunction() /*/
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifdef ShAiDSk
    freopen("Error.txt", "w", stderr);
#endif 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    cout << setprecision(15) << fixed;
    cerr << setprecision(10) << fixed;
/* ShAiDSk_Solve() Call */
    ShAiDSk_Solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ShAiDSk
    cerr << "Time: " << duration . count() / 1000 << newline;
#endif
    return 0;
}