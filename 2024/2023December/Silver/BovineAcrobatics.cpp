#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, kk, a[N], w[N];

void solve(){
    cin >> n >> m >> kk;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> a[i];
        v.pb({w[i], a[i]});
    }
    sort(v.rbegin(), v.rend());
    set<pair<int, int> > s;
    s.insert({INT_MAX, m}); // weight and how many columns with that weight
    int ans = 0;
    for(auto k : v){
        int cur_w = k.F, cur_n = k.S, add = 0;
        auto p = s.lower_bound({cur_w + kk, 0});
        while(p != s.end()){
            int here = (*p).S;
            auto temp = p;
            if(here > cur_n){
                pair<int, int> which = *p;
                s.erase(p);
                add += cur_n;
                s.insert({which.F, which.S - cur_n});
                ans += cur_n;
                break;
            }
            else{
                ++p;
                s.erase(temp);
                cur_n -= here;
                ans += here;
                add += here;
            }
        }
        if(add)
            s.insert({cur_w, add});
    }
    cout << ans << '\n';
}

int32_t main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
