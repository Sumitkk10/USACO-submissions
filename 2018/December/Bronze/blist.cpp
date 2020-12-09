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
	pair<int, pair<int, int> > a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second.first >> a[i].second.second;
	long long int ans = 0;
	for(int time = 1; time <= 1000; ++time){
		long long int how_many = 0;
		for(int i = 0; i < n; ++i){
			if(a[i].first <= time and a[i].second.first >= time)
				how_many += a[i].second.second; 
		}
		ans = max(ans, how_many);
	}
	cout << ans << '\n';
}

int main(){
	fast;
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
