#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
    fast;
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    int dp[n][m];
    for(int i = 0; i < n; ++i)
        dp[i][0] = 0;
    for(int i = 0; i < m; ++i)
        dp[0][i] = 0;
    dp[0][0] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            long long ok = 0;
            for(int k = 0; k < i; ++k)
                for(int kk = 0; kk < j; ++kk)
                    if(a[k][kk] != a[i][j])
                        ok = (ok + dp[k][kk]) % MOD;
            dp[i][j] = ok;
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}
/*
4 4 4
1 1 1 1
1 3 2 1
1 2 4 1
1 1 1 1
*/
