#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if(a > b)
		swap(a, b);
	if(x > y)
		swap(x, y);
	cout << min(b - a, abs(x - a) + abs(y - b));
}

int main(){
	fast;
	// freopen("teleport.in", "r", stdin);
	// freopen("teleport.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
