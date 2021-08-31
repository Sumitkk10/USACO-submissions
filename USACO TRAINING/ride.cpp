/*
ID: messiku1
LANG: C++
PROG: ride
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string a, b;
    cin >> a >> b;
    ll ans = 1, ans1 = 1;
    for(auto k : a)
        ans = (ans * (k - 'A' + 1)) % 47;
    for(auto k : b)
        ans1 = (ans1 * (k - 'A' + 1)) % 47;
    cout << (ans % 47 == ans1 % 47 ? "GO\n" : "STAY\n");
}

int main(){
    fast;
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
