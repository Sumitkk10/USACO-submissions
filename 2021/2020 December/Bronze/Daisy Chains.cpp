#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n;
	cin >> n;
	long long int pre_sum[n + 1], a[n + 1];
	pre_sum[0] = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pre_sum[i] = pre_sum[i - 1] + a[i];
	}
	long long int ans = n;
	for(int len = 2; len <= n; ++len){
		for(int i = 1; i <= n - len + 1; ++i){
			int sum = pre_sum[i + len - 1] - pre_sum[i - 1];
			for(int j = i; j < i + len; ++j){
				if(a[j]*len == sum){
					++ans;
					break;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
