#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int c1, m1, c2, m2, c3, m3;
	cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
	for(int cnt = 0; cnt < 100;){
		if(cnt % 3 == 0){
			int amt = min(m1, c2 - m2);
			m1 -= amt;
			m2 += amt;
			++cnt;
		}
		else if(cnt  % 3 == 1){
			int amt = min(m2, c3 - m3);
			m2 -= amt;
			m3 += amt;
			++cnt;
		}
		else{
			int amt = min(m3, c1 - m1);
			m3 -= amt;
			m1 += amt;
			++cnt;
		}
	}
	cout << m1 << '\n' << m2 << '\n' << m3 << '\n';
}

int main(){
	fast;
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
