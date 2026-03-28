// Longest Palindrome Subsequence
/* Author : theTortoise
*/
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
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    string r = s;
    reverse(r.begin(), r.end());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == r[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][n] << nl;
    int i = n, j = n;
    string ans = "";
    while(i > 0 && j > 0){
        if(s[i-1] == r[j-1]){
            ans += s[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] == dp[i][j]) i--;
        else if(dp[i][j-1] == dp[i][j]) j--;
    }

    cout << ans << nl;
}

int main(){
    fast_io

    solve();

    return 0;
}