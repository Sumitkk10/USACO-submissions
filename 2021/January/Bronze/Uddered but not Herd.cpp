#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100000 + 5;
const int MOD = 1e9 + 7;

int main() {
    fast;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < b.size();){
        for(int j = 0; j < a.size(); ++j)
            if(b[i] == a[j])
                ++i;
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}
