//============================================================================
// Author      : Omar_Hafez
// Created     : 08 July 2023 (Saturday)  8:36:41 PM
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

int n, m;

int N = 201, W = -2, D = -1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dd[4] = {0, 0, 1, 1};
int xx[4] = {0, 0, 0, 1};
int yy[4] = {1, 0, 0, 0};

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N);
}

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    while(1) {
        cin >> n >> m;
        if(n == -1 && m == -1) return 0;
        vector<vector<vector<int>>> a(2, vector<vector<int>> (N+10, vector<int>(N+10)));
        int x, y, d, t;
        for(int i = 0; i < n; i++) {
            cin >> x >> y >> d >> t;
            for(int j = 0; j < t; j++) {
                if(d) {
                    a[d][y+j][x] = W; 
                } else {
                    a[d][y][x+j] = W;
                }
            }
        }
        for(int j = 0; j < m; j++) {
            cin >> x >> y >> d;
            a[d][y][x] = D;
        }
        ld tx, ty;
        cin >> tx >> ty;
        x = tx; y = ty;
        x = min(x, 200ll);
        y = min(y, 200ll);
        pdqu<tuple<int, int, int>> q;
        q.push({0, x, y});
        vector<vector<int>> dp(N+10, vector<int>(N+10, INF));
        dp[y][x] = 0;
        while(!q.empty()) {
            x = get<1>(q.top());
            y = get<2>(q.top());
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x+dx[i]; //1
                int ny = y+dy[i]; //2
                if(!ok(nx, ny) || !ok(x+xx[i], y+yy[i])) continue;
                int w = a[dd[i]][y+yy[i]][x+xx[i]];
                if(w == W) continue;
                if(w == D) w = 1;
                if(dp[y][x]+w < dp[ny][nx]) {
                    dp[ny][nx] = dp[y][x]+w;
                    q.push({dp[ny][nx], nx, ny});
                }
            }
        }
        if(dp[0][0] == INF) cout << -1; 
        else cout << dp[0][0];
        newl;
    }
}
