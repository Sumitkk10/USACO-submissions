#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
using namespace std;
const int N = 20 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    long long sum = 0;
    vector<long long int> rem[9];
    for(int i = 0; i < n; ++i){
        long long int a;
        cin >> a;
        sum += a;
        rem[sum % 7].push_back(i);
    }
    long long ans = 0;
    for(int i = 0; i <= 6; ++i){
        if(i == 0 and rem[0].size())
            ans = max(ans, rem[0][rem[0].size() - 1] + 1);
        else{
            for(int j = 1; j < rem[i].size(); ++j)
                ans = max(ans, rem[i][j] - rem[i][0]);
        }
    }
    cout << ans << '\n';
    return 0;
}
