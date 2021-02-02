#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100002;
long long n, k, a[N], dp[N][21][3];

long long int go(int i, int moves, int cur){
    if(moves > k)
        return INT_MIN;
    if(i == n + 1)
        return 0;
    long long ans = INT_MIN;
    if(dp[i][moves][cur] != -1)
        return dp[i][moves][cur];
    if(i == 0){
        ans = max(ans, go(i + 1, moves, 0));
        ans = max(ans, go(i + 1, moves, 1));
        ans = max(ans, go(i + 1, moves, 2));
    }
    else if(cur == 0){
        int ok = 0;
        if(a[i] == 1)
            ok = 1;
        ans = max(ans, go(i + 1, moves, cur) + ok);
        ans = max(ans, go(i + 1, moves + 1, 1) + ok);
        ans = max(ans, go(i + 1, moves + 1, 2) + ok);
    }
    else if(cur == 1){
        int ok = 0;
        if(a[i] == 2)
            ok = 1;
        ans = max(ans, go(i + 1, moves, cur) + ok);
        ans = max(ans, go(i + 1, moves + 1, 0) + ok);
        ans = max(ans, go(i + 1, moves + 1, 2) + ok);
    }
    else{
        int ok = 0;
        if(a[i] == 0)
            ok = 1;
        ans = max(ans, go(i + 1, moves, cur) + ok);
        ans = max(ans, go(i + 1, moves + 1, 1) + ok);
        ans = max(ans, go(i + 1, moves + 1, 0) + ok);
    }
    return dp[i][moves][cur] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        char x;
        cin >> x;
        // paper -> 0, hoof -> 1, scissors -> 2;
        if(x == 'P')
            a[i] = 0;
        else if(x == 'H')
            a[i] = 1;
        else
            a[i] = 2;
    }
    cout << go(0, 0, 0);
}

int main() {
    fast;
    int t = 1;
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    while(t--)
        solve();
    return 0;
}
