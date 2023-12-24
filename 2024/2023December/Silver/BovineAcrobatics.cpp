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
		cin >> a[i] >> w[i];
		v.pb({w[i], a[i]});
	}
	sort(v.rbegin(), v.rend());
	set<pair<int, int> > s;
	s.insert({INT_MAX, m}); // weight and how many columns with that weight
	int ans = 0;
	for(auto k : v){
		int cur_w = k.F, cur_n = k.S;
		auto p = s.lower_bound({cur_w + kk, 0});
		while(p != s.end()){
			int here = (*p).S;
			if(here > cur_n){
				s.erase(p);
				s.insert({cur_w, cur_n});
				ans += cur_n;
				break;
			}
			else{
				s.erase(p);
				cur_n -= here;
				ans += here;
				s.insert({cur_w, here});
			}
			p = s.lower_bound({cur_w + kk, 0});
		}
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
