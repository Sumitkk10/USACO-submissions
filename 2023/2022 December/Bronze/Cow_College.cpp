#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a, a + n + 1);
    int mx = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
        // if cost is a[i];
        int x = a[i] * (n - i + 1);
        if(x > mx){
            mx = x;
            ans = a[i];
        }
        else if(x == mx){
            if(ans > a[i])
                ans = a[i];
        }
    }
    cout << mx << ' ' << ans << "\n";
}

int32_t main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
