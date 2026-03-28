/* Author : theTortoise
*/

// Problem link & Soln : https://www.geeksforgeeks.org/dsa/count-possible-decodings-given-digit-sequence/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long LINF = 1e18;

#define read_(arr, n) for(int i = 0; i < (n); i++) cin >> arr[i]
#define print_(arr, n) for(int i = 0; i < (n); i++) cout << arr[i] << " " 
#define read__(arr, n, m) for(int i = 0; i < (n); i++) for(int j = 0; j < (m); j++) cin >> arr[i][j]
#define go(t, n) for(int i = t; i < n; i++)
#define arr(a, n) int n; cin >> n; vector<int>a(n)
#define sort_(a) sort(a.begin(), a.end());
#define test_case(tt) while(tt--) solve()
#define fast_io ios::sync_with_stdio(0); cin.tie(nullptr);
#define handle_test_case int tt; cin >> tt; while(tt--) solve()
#define nl "\n"

typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.length();

    if(s[0] == '0'){
        cout << 0 << nl;
        return;
    }

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        if(s[i-1] != '0')
            dp[i] += dp[i-1];

        int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        if(num >= 10 && num <= 26)
            dp[i] += dp[i-2];
    }

    cout << dp[n] << nl;
}

int main(){
    fast_io

    solve();

    return 0;
}