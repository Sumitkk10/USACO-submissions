/*
ID: messiku1
LANG: C++
PROG: combo
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
    int n, ans = 0;
    cin >> n;
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                int x = min({abs(a[0] - i), i + (n - a[0]), a[0] + (n - i)});
                int y = min({abs(a[1] - j), j + (n - a[1]), a[1] + (n - j)});
                int z = min({abs(a[2] - k), k + (n - a[2]), a[2] + (n - k)});
                if(x < 3 and y < 3 and z < 3){
                    ++ans;
                    continue;
                }
                x = min({abs(b[0] - i), i + (n - b[0]), b[0] + (n - i)});
                y = min({abs(b[1] - j), j + (n - b[1]), b[1] + (n - j)});
                z = min({abs(b[2] - k), k + (n - b[2]), b[2] + (n - k)});
                if(x < 3 and y < 3 and z < 3){
                    ++ans;
                    continue;
                }
            }
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    fast;
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
