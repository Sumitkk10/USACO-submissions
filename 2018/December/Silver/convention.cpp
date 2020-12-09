#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int m, k;
int a[N], n;

bool check(long long int diff){
    int buses = 1, pre = 0;
    for(int i = 1; i < n; ++i){
        if(a[i] - a[pre] > diff or i + 1 - pre > k){
            buses++;
            pre = i;
        }
    }
    return (buses <= m);
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long long int low = 0, high = 1e9, ans;
    while(low <= high){
        long long int mid = (low + high) / 2;
        if(check(mid)){
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
