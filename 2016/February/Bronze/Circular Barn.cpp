#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100 + 5;
const int MOD = 1e9 + 7;

int main() {
    fast;
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        long long sum = 0;
        for(int j = i + 1; j < n; ++j)
            sum += (j - i) * a[j];
        for(int j = 0; j < i; ++j)
            sum += (j + 1 + (n - i - 1)) * a[j];
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
