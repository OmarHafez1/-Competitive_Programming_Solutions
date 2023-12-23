
//============================================================================
// Author      : Omar_Hafez
// Created     : 19 May 2023 (Friday)  6:14:32 PM
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
using namespace std;
#define int long long

#define endl '\n'

signed main() { 
    int s[1005][1005];
    memset(s, 0, sizeof(s));
    int t = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            t = (615949*t+797807)%1048576;
            s[i][j] = t-524288;
        }
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            s[i][j] += s[i][j-1];
        }
    }
    int ans = INT_MAX;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            int sum = 0;
            for(int k = i; k <= 1000; k++) {
                sum += s[k][k] - s[k][i-1];
                ans = min(ans, sum);
            }
        }
    }
    cout << ans;
}