#include <bits/stdc++.h>
#define godspeed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, a[N];

void sublime(){
	#ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}

void solve(){
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	int pre[n + 1], suf[n + 2];
	pre[0] = 0;
	suf[n + 1] = 0;
	for(int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i];
	for(int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + a[i];
	int choose = n/2 - (n & 1 ? 0 : 1);
	int elsie = 0;
	for(int i = 0; i <= choose; ++i)
		elsie = max(elsie, pre[i] + suf[n - (choose - i) + 1]);
	cout << sum - elsie << ' ' << elsie << '\n';
}

int32_t main(){
	// sublime();
	godspeed;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
