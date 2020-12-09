#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    pair<int, int> a[n];
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        for(int j = a[i].first + 1; j <= a[i].second; ++j)
            mp[j]++;
    }
    sort(a, a + n);
    long long int ans = 0;
    for(int i = 0; i < n; ++i){
        int x = a[i].first, y = a[i].second;
        for(int j = x + 1; j <= y; ++j)
            mp[j]--;
        long long int cnt = 0;
        for(int j = 0; j <= 1000; ++j)
            if(mp[j] > 0)
                ++cnt;
        ans = max(ans, cnt);
        for(int j = x + 1; j <= y; ++j)
            mp[j]++;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
