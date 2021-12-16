#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
vector<int> a, b;
map<long long, bool> mp;

long long go(int day, long long quan_a, long long quan_b){
	if(day == 5){
		// ending day just see wheater quan_a is different or not.
		if(mp[quan_a])
			return 0;
		mp[quan_a] = true;
		// cout << quan_a << endl;
		return 1;
	}
	long long ans = 0;
	if(day % 2){
		for(int i = 0; i < a.size(); ++i){
			vector<int> temp, before = a;
			for(int j = 0; j < a.size(); ++j){
				if(j == i) continue;
				temp.push_back(a[j]);
			}
			int x = a[i];
			b.push_back(x);
			a = temp;
			ans += go(day + 1, quan_a - x, quan_b + x);
			b.pop_back();
			a = before;
		}
	}
	else{
		for(int i = 0; i < b.size(); ++i){
			vector<int> temp, before = b;
			for(int j = 0; j < b.size(); ++j){
				if(j == i) continue;
				temp.push_back(b[j]);
			}
			int x = b[i];
			a.push_back(x);
			b = temp;
			ans += go(day + 1, quan_a + x, quan_b - x);
			a.pop_back();
			b = before;
		}
	}
	return ans;
}

void solve(){
	for(int i = 1; i <= 10; ++i){
		int x;
		cin >> x;
		a.push_back(x);
	}
	for(int i = 1; i <= 10; ++i){
		int x;
		cin >> x;
		b.push_back(x);
	}
	cout << go(1, 1000, 1000) << '\n';
}

int main() {
	fast;
	freopen("backforth.in", "r", stdin);
   	freopen("backforth.out", "w", stdout);
   	int t = 1;
	while(t--)
		solve();
	return 0;
}
