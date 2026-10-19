#include <bits/stdc++.h>
#define godspeed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int k, n;
string s;

void sublime(){
	#ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}

void solve(){
	cin >> n >> s;
	if(n & 1){
		cout << "-1\n";
		return;
	}

	// str len is 3(n)
	// cout << "2\n";
	int i = 0, j = (n*3)/2;
	vector<int> ans(3*n);
	bool ok = 0;
	while(i < (3*n)/2 or j < 3*n){
		string lft, rgt;
		lft.push_back(s[i]);
		lft.push_back(s[i + 1]);
		lft.push_back(s[i + 2]);
		rgt.push_back(s[j]);
		rgt.push_back(s[j + 1]);
		rgt.push_back(s[j + 2]);
		if(lft == rgt){
			ans[i] = 1;
			ans[i + 1] = 1;
			ans[i + 2] = 1;
			ans[j] = 1;
			ans[j + 1] = 1;
			ans[j + 2] = 1;
		}
		else{
			ok = 1;
			if(lft == "COW" and rgt == "WCO"){
				ans[i] = 1;
				ans[i + 1] = 1;
				ans[i + 2] = 2;
				ans[j] = 2;
				ans[j + 1] = 1;
				ans[j + 2] = 1;
			}
			else if(lft == "WCO" and rgt == "COW"){
				ans[i] = 2;
				ans[i + 1] = 1;
				ans[i + 2] = 1;
				ans[j] = 1;
				ans[j + 1] = 1;
				ans[j + 2] = 2;
			}
			else if(lft == "COW" and rgt == "OWC"){
				ans[i] = 2;
				ans[i + 1] = 1;
				ans[i + 2] = 1;
				ans[j] = 1;
				ans[j + 1] = 1;
				ans[j + 2] = 2;
			}
			else if(lft == "OWC" and rgt == "COW"){
				ans[i] = 1;
				ans[i + 1] = 1;
				ans[i + 2] = 2;
				ans[j] = 2;
				ans[j + 1] = 1;
				ans[j + 2] = 1;
			}
			if(lft == "OWC" and rgt == "WCO"){
				ans[i] = 2;
				ans[i + 1] = 1;
				ans[i + 2] = 1;
				ans[j] = 1;
				ans[j + 1] = 1;
				ans[j + 2] = 2;
			}
			else if(lft == "WCO" and rgt == "OWC"){
				ans[i] = 1;
				ans[i + 1] = 1;
				ans[i + 2] = 2;
				ans[j] = 2;
				ans[j + 1] = 1;
				ans[j + 2] = 1;
			}
		}
		i += 3;
		j += 3;
	}
	cout << (ok ? "2\n" : "1\n");
	for(int i = 0; i < 3*n; ++i){
		if(i == 3 * n - 1)
			cout << ans[i];
		else
			cout << ans[i] << ' ';
	}
	cout << endl;
}

int32_t main(){
	// sublime();
	godspeed;
	int t = 1;
	cin >> t >> k;
	while(t--)
		solve();
	return 0;
}
