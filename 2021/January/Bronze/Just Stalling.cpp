#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100000 + 5;
const int MOD = 1e9 + 7;
int a[N], h[N], n;
long long int dp[20][1LL << 20];

long long int go(int i, long long int mask){
    if(i == n)
        return 1;
    if(dp[i][mask] != -1)
        return dp[i][mask];
    long long int ans = 0;
    for(int j = 0; j < n; ++j){
        if(mask & (1LL << j)) continue;
        if(a[j] <= h[i])
            ans += go(i + 1, (mask | (1LL << j)));
    }
    return dp[i][mask] = ans;
}

int main() {
    fast;
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    sort(a, a + n);
    sort(h, h + n);
    cout << go(0, 0) << '\n';
    return 0;
}
