#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define endl '\n'

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define EPS .0000001
#define MOD 1e9+7
#define PI 3.14159265358979323846

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(all(x), greater<>())

#define uset unordered_set
#define mset multiset
#define umset unordered_multiset

template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

void calculate();

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

#define N 200005

int a[N];

void calculate() {
    string s;
    cin >> s;
    int val = 0, ans = 0;
    int ind = 0;
    for(int i = 0; i <= s.size()/2; i++) a[i] = 0;
    for(int i = 1; i < s.size(); i++) {
        val += pow(-1, s[i-1] == ')');
        ans += a[val];
        a[val]++;
        while(ind*2 < val) {
            a[ind++] = 0;
        }
        ind = min(ind, val);
    }
    cout << ans << endl;

}