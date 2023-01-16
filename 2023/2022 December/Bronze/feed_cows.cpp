#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, k;
string s;

void solve(){
	cin >> n >> k >> s;
	string ans;
	for(int i = 0; i < n; ++i)
		ans.pb('.');
	int g = -1, h = -1;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'G'){
			if(g >= i)
				continue;
			if(i + k < n){
				ans[i + k] = 'G';
				g = min(n, i + 2 * k);
			}
			else{
				g = n;
				if(ans[i] == '.')
					ans[i] = 'G';
				else
					ans[i - 1] = 'G';
			}
		}
		else{
			if(h >= i)
				continue;
			if(i + k < n){
				ans[i + k] = 'H';
				h = min(n, i + 2 * k);
			}
			else{
				h = n;
				if(ans[i] == '.')
					ans[i] = 'H';
				else
					ans[i - 1] = 'H';
			}
		}
	}
	int res = 0;
	for(auto k : ans)
		res += k != '.';
	cout << res << "\n";
	cout << ans << "\n";
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
