#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, k, a[N], dp[10002][1002], tree[N], mx[N];

void build(ll node, ll st, ll end){
    if(st > end) return;
    if(st == end){
        tree[node] = a[st];
        return;
    }
    ll mid = (st + end) >> 1;
    build(node * 2, st, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

ll querry(ll node, ll st, ll end, ll l, ll r){
    if(st > end || l > r || st > r || end < l) return 0;
    if(l <= st && end <= r) return tree[node];
    ll mid = (st + end) >> 1;
    ll t = querry(node * 2, st, mid, l, r);
    ll tt = querry(node * 2 + 1, mid + 1, end, l, r);
    return max(t, tt);
}


void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    // let dp[i][k] be the max sum in the prefix of i with k length last segment.
    for(int i = 1; i <= k; ++i){
        dp[1][i] = a[1];
    }
    mx[1] = a[1];
    mx[0] = 0; 
    for(int i = 2; i <= n; ++i){
        int mxx = a[i], x = i;
        for(int j = 1; j <= min(i, (int) k); ++j){
            int cur = i, pre = i - j + 1;
            mxx = max(a[x], (ll) mxx);
            dp[i][j] = max(dp[i][j], mx[pre - 1] + j*mxx);
            mx[i] = max(mx[i], dp[i][j]);
            --x;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= min(n,k); ++i)
        ans = max(ans, dp[n][i]);
    cout << ans << "\n";
}

int main(){
    fast;
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
