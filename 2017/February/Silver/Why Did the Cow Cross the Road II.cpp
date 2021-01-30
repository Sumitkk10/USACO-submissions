#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
using namespace std;
const int N = 20 + 5;
const int MOD = 1e9 + 7;
unordered_map<long long int, int> mp;

int main(){
    fast;
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    long long n, k, b;
    cin >> n >> k >> b;
    long long a[b];
    for(int i = 0; i < b; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    long long ans = 0;
    for(int i = 1; i <= k; ++i)
        ans += mp[i];
    long long mn = ans;
    for(int i = k + 1; i <= n; ++i){
        if(mp[i - k]) --ans;
        if(mp[i]) ++ans;
        mn = min(mn, ans);
    }
    cout << mn << "\n";
    return 0;
}
/*
10 6 5
2
10
1
5
9
 */
