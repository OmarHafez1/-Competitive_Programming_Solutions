//============================================================================
// Author      : Omar_Hafez
// Created     : 02 July 2023 (Sunday)  2:18:10 PM
//============================================================================

 /*   
                ________
               /        \
              / /      \ \
     ________/ /        \ \________
    /        \            /        \ 
   / /      \ \  ______  / /      \ \
  / /        \ \________/ /        \ \ 
  \            /        \            /
   \  ______  / /      \ \  ______  /    
    \________/ /        \ \________/
    /        \            /        \
   / /      \ \  ______  / /      \ \   
  / /        \ \________/ /        \ \
  \            /        \            /    
   \  ______  / /      \ \  ______  /
    \________/ /        \ \________/
             \            /     
              \  ______  / 
               \________/ 

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono; 
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using indexed_mset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define int long long

const double PI = 3.141592653589793;
const int MOD = 1e9+7; 
const int INF = 1e9;

//
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double; 

using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pull = pair<ull, ull>;
using pdb = pair<db,db>;

using vi = vector<int>;
using vl = vector<long>;
using vb = vector<bool>;
using vll = vector<ll>;
using vull = vector<ull>;
using vld = vector<ld>;
using vdb = vector<db>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpll = vector<pll>; 
using vpull = vector<pull>;
using vpdp = vector<pdb>;

#define vec vector
#define lb lower_bound
#define ub upper_bound
#define pushb(a) push_back(a)
#define pushf(a) push_front(a)
#define popb pop_back()
#define popf pop_front()

// pairs & tuples
#define fir first
#define sec second
#define tsize(t) tuple_size<decltype(t)>::value
#define tcat tuple_cat

// vectors
#define all(x) begin(x), end(x)
#define alll(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()  //C++17 
#define sor(x) sort(all(x)) 
#define sorr(x) sort(alll(x)) 
#define rsor(x) sort(all(x), greater<>()) 
#define rsorr(x) sort(alll(x), greater<>()) 
#define rsz(a, b) resize(distance(a, b))
#define eb emplace_back
#define shuffle(v) random_shuffle(all(v))
#define vmax(x) max_element(all(x))
#define vcnt(x, i) count(all(x), i)
#define uniq(x) x.resize(unique(all(x)) - x.begin())

// sets
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define ins insert
#define ers erase

#define key find_by_order
#define order order_of_key

// queue
#define qu queue
#define dqu deque
#define pqu priority_queue
template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

// maps
#define umap unordered_map

// loops
#define f0r(i,a) for(int i = 0; i < (a); ++i)
#define f1r(i,a) for(int i = 1; i < (a); ++i)
#define foor(i,a,b) for(int i = (a); i < (b); ++i)
#define r0f(i,a) for(int i = (a)-1; i >= 0; --i)
#define rof(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define fe(a,x) for(auto& a: x)

// some hacks
#define endl '\n'
#define newl cout<<endl;

// some math
#define point complex<ld>
#define degree(x) (x) * 180.0 / PI
#define radian(x) (x) * PI / 180.0
#define sinDegrees(x) sin(radian(x))
#define cosDegrees(x) cos(radian(x))
#define tanDegrees(x) tan(radian(x))
#define asinDegrees(x) dgeree(asin(x))
#define acosDegrees(x) degree(acos(x))
#define atanDegrees(x) degree(atan(x))
#define EPS 1e-8
#define is_same(a, b) (fabs(a-b) <= EPS)

// some complex
#define point complex<ld>
#define c_angle(a) (atan2((a).imag(), (a).real()))
#define c_vec(a,b) (b)-(a)
#define c_dp(a,b) (conj(a)*(b)).real() // a*b cos(T), if zero -> prep
#define c_cp(a,b) (conj(a)*(b)).imag()  // a*b sin(T), if zero -> parllel
#define c_same(p1,p2) (c_dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define c_length(a) (hypot((a).imag(), (a).real()))
#define c_distance(a, b, c) fabs(c_cp(a-b, a-c)/c_length(a-b))
#define c_normalize(a) (a)/c_length(a)
#define c_rotateO(p,ang) ((p)*exp(point(0,ang)))
#define c_rotateA(p,ang,about) (c_rotateO(vec(about,p),ang)+about)
#define c_reflectO(v,m) (conj((v)/(m))*(m))

// bits
#define cnt_1s(b) __builtin_popcountll(b)
#define begin_0s(b) __builtin_clzll(b) 
#define end_0s(b) __builtin_ctzll(b) 
#define ffno(b) find_first_not_ofll(b) 

// permutation 
#define n_perm next_permutation
#define p_perm prev_permutation 
#define vn_perm(x) next_permutation(all(x))
#define vp_perm(x) prev_permutation(all(x))

// fflush(stdout);
// cout << fixed << setprecision(10);

struct DSU {
  int N;
  vector<int> size, dsu;

  DSU(int n) {
    N = n+1;
    size = vector<int> (N, 1);
    dsu = vector<int> (N);
    for(int i = 0; i < N; i++) {
      dsu[i] = i;
    }
  }

  int root(int a) {
    while(a != dsu[a]) {
      dsu[a] = dsu[dsu[a]];
      a = dsu[a];
    }
    return a;
  }

  void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if(a == b) return;
    if(size[a] > size[b]) swap(a, b);
    dsu[a] = dsu[b];
    size[b] += size[a];
  }

  int get_size(int a) {
    return size[root(a)];
  }

  bool same_set(int a, int b) {
    return (root(a) == root(b));
  }

};

int ans = -1;

void solve(int u, int target, vector<vector<int>> &adj, map<pair<int, int>, int> &mp, int mn, vector<bool> &vis) {
    if(ans != -1) return;
    if(vis[u]) return;
    if(u == target) {
        ans = mn;
        return;
    }
    vis[u] = 1;
    fe(x, adj[u]) {
        solve(x, target, adj, mp, max(mn, mp[{x, u}]), vis);
    }
}

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    int n, m, q;
    int t = 1;
    bool fir = 1;
    while(cin >> n >> m >> q) {
        vector<tuple<int, int, int>> a;
        if(n == 0 && m == 0 && q == 0) return 0;
        if(!fir) newl;
        fir = 0;
        cout << "Case #" << t++ << endl;
        int u, v, c;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            a.emplace_back(c, u, v);
        }
        vector<tuple<int, int, int>> mst;
        sor(a);
        DSU dsu = DSU(n+1);
        map<pair<int, int>, int> mp;
        for(auto &x : a) {
            if(dsu.same_set(get<1>(x), get<2>(x))) continue;
            mst.emplace_back(x);
            dsu.unite(get<1>(x), get<2>(x));
            mp[{get<1>(x), get<2>(x)}] = get<0>(x);
            mp[{get<2>(x), get<1>(x)}] = get<0>(x);
        }
        vector<vector<int>> adj = vector<vector<int>>(n+1);
        fe(x, mst) {
            adj[get<1>(x)].push_back(get<2>(x));
            adj[get<2>(x)].push_back(get<1>(x));
        }       
        while(q--) {
            cin >> u >> v;
            vector<bool> vis(n+1);
            if(!dsu.same_set(u, v)) {
                cout << "no path" << endl;
                continue;
            }   
            ans = -1;
            solve(u, v, adj, mp, 0, vis);
            cout << ans << endl;
        }
    }

}
