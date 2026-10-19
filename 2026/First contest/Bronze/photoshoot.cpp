#include <bits/stdc++.h>
#define godspeed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 5e2 + 5, MOD = 1e9 + 7;
int n, k, q, a[N][N], pre[N][N];

void sublime(){
	#ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}

void solve(){
	cin >> n >> k >> q;
	int ans = 0;
	while(q--){
		int r, c, v;
		cin >> r >> c >> v;
		int before = a[r][c];
		for(int i = r; i < min(n + 1, r + k); ++i){
			for(int j = c; j < min(n + 1, c + k); ++j){
				pre[i][j] -= before;
				pre[i][j] += v;
				ans = max(ans, pre[i][j]);
			}
		}
		a[r][c] = v;
		cout << ans << '\n';
	}
}

int32_t main(){
	// sublime();
	godspeed;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
