#include <bits/stdc++.h>
#define godspeed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int a, b, ca, cb, fa;

void sublime(){
	#ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}

bool check(int mid, int waste, int rem){
	mid += waste;
	int inc = (mid / cb);
	int rem1 = rem;
	rem -= (inc * ca);
	if(rem <= 0){
		int inc = (mid / cb) - 1;
		rem1 -= (inc * ca);
		// cout <<rem << ' ';
		rem1 -= ((mid % cb) + 1);
		return rem1 <= 0; 
	}
	return false;
}

void solve(){
	cin >> a >> b >> ca >> cb >> fa;

	// need atleast fa a coins
	if(a >= fa){
		cout << "0\n";
		return;
	}
	int rem = fa - a;
	int needed = (rem + ca - 1) / ca;
	int makes = b / cb;

	if(makes >= needed){
		cout << "0\n";
		return;
	}
	rem -= (makes * ca);
	b %= cb;
	int waste = cb - b - 1;
	// in the end do +waste

	if(ca >= cb)
		cout << rem + waste << endl;
	else{
		int low = 0, high = 1000000000000000900, ans = -1;
		while(low <= high){
			int mid = (low + (high - low) / 2);
			// cout << mid << endl;
			if(check(mid, b, rem)){
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		cout << ans << '\n';
	}
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
