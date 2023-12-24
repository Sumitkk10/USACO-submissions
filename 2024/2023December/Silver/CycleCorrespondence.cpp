#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[k], b[k], pos[n + 1];
    set<int> s;
    memset(pos, -1, sizeof pos);
    for(int i = 0; i < k; ++i){
        cin >> a[i];
        pos[a[i]] = i;
        s.insert(a[i]);
    }
    int cnt[n + 1];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < k; ++i){
        cin >> b[i];
        if(pos[b[i]] != -1){
            if(pos[b[i]] < i)
                cnt[k - i + pos[b[i]]]++;
            else
                cnt[pos[b[i]] - i]++;
        }
        s.insert(b[i]);
    }
    int mx = 0;
    for(int i = 0; i <= n; ++i)
        mx = max(mx, cnt[i]);
    memset(cnt, 0, sizeof cnt);
    int j = 0;
    for(int i = k - 1; i >= 0; --i){
        if(pos[b[i]] != -1){
            if(pos[b[i]] < j)
                cnt[k - j + pos[b[i]]]++;
            else
                cnt[pos[b[i]] - j]++;
        }
        ++j;
    }
    for(int i = 0; i <= n; ++i)
        mx = max(mx, cnt[i]);
    int ans = n - s.size();
    cout << ans + mx << '\n';
}

int32_t main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
