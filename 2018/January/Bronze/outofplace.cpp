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
    int a[n], b[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    long long int ans = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] != b[i])
            ++ans;
    cout << ans - 1 << '\n';
}

int main(){
    fast;
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
