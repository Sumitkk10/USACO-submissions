/*
ID: messiku1
LANG: C++
PROG: friday
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool isLeap(int year){
    if(year % 100 ==0)
      return year % 400 ==0;
    else
      return year % 4 ==0;
}

void solve(){
    int period;
    cin >> period;
    int calendarDay=0;
    int freq[7]={0,0,0,0,0,0,0};
    
    int normDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leapDays[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    for(int year=1900; year<1900+period; year++){
        for(int month=0; month<12; month++){
            int weekday=(calendarDay+12)%7;
            freq[(weekday+2)%7]++;
            calendarDay += isLeap(year) ? leapDays[month]:normDays[month];
        }
    }

    for(int i=0; i<7; i++){
        cout<<freq[i];
        if(i==6) cout<<"\n";
        else cout<<" ";
    }

}

int main(){
    fast;
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
