#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int a[7], n = 7;
	for(int i = 0; i < 7; ++i)
		cin >> a[i];
	sort(a, a + n);
	cout << a[0] << ' ' << a[1] << ' ';
	int sum = a[0] + a[1];
	int i = 2;
	while(a[i] == sum)
		++i;
	cout << a[i];
	return 0;
}
