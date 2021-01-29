#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100000 + 5;
const int MOD = 1e9 + 7;

int main() {
    fast;
    int n;
    cin >> n;
    int a[n], even = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        even += (a[i] % 2 == 0);
    }
    int odd = n - even;
    if(even == odd)
        cout << 2 * odd << '\n';
    else if(even > odd)
        cout << 2 * odd + 1 << '\n';
    else{
        int diff = odd - even;
        int ans = 2 * even;
        odd -= even;
        int ct = 0;
        while(odd > 0){
            if(ct % 2 == 0)
                odd -= 2;
            else
                --odd;
            if(odd >= 0)
                ++ct;
        }
        if(odd == -1)
            --ct;
        cout << ans + ct << '\n';
    }
    return 0;
}
