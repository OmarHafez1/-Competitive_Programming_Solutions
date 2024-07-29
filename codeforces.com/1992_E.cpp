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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

int len(int n) {
    return (int)log10(n)+1;
}

void calculate() {
    int n;
    cin >> n;
    string s = to_string(n);
    int u;
    vector<int> w;
    int m = len(n);
    string tmp = to_string(s[0]-'0');
    int ind = 0;
    while((u = stoll(tmp)) <= 1e5+1) {
        w.push_back(u);
        ind++;
        ind %= m;
        tmp += s[ind];
    }
    vector<pair<int, int>> ans;
    for(auto &x : w) {
        for(int a = 1; a <= 10000; a++) {
            int b = n*a-x;
            if(b >= 1 && b <= min(10000ll, n*a) && len(n)*a-b == len(x)) {
                ans.push_back({a, b});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto &x : ans) {
        cout << x.first << " " << x.second << endl;
    }
}