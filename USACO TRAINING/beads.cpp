/*
ID: messiku1
LANG: C++
PROG: beads
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main(){
    fast;
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n, ans = 2;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s + s;
    int left[1000][4], right[1000][4];
    left[0][0] = 0;
    left[0][1] = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == 'r'){
            left[i][0] = left[i - 1][0] + 1;
            left[i][1] = 0;
        }
        else if(s[i] == 'b'){
            left[i][1] = left[i - 1][1] + 1;
            left[i][0] = 0;
        }
        else{
            left[i][0] = left[i - 1][0] + 1;
            left[i][1] = left[i - 1][1] + 1;
        }
        // cout << left[i][0] << ' ' << left[i][1] << "\n";
    }
    right[s.size()][0] = 0;
    right[s.size()][1] = 0;
    for(int i = s.size() - 1; i >= 1; --i){
        if(s[i] == 'r'){
            right[i][0] = right[i + 1][0] + 1;
            right[i][1] = 0;
        }
        else if(s[i] == 'b'){
            right[i][1] = right[i + 1][1] + 1;
            right[i][0] = 0;
        }
        else{
            right[i][0] = right[i + 1][0] + 1;
            right[i][1] = right[i + 1][1] + 1;
        }
    }
    for(int i = 1; i < s.size(); ++i){
        ans = max(ans, max(left[i - 1][0], left[i - 1][1]) + max(right[i][0], right[i][1]));
        ans = max(ans, max(left[i][0], left[i][1]) + max(right[i + 1][0], right[i + 1][1]));
    }
    cout << min(ans, n) << "\n";
    return 0;
}
