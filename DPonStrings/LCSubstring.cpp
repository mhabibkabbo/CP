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
// it is kinda tough
typedef long long ll;
// dp[i][j] stores the longest common substring till s[i] & t[j] positions
// the difference betn common subsequence problem and this one is 
// if the character doesnt match we will reset the value to 0 
void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int res = 0;
    int a, b;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > res){
                    a = i - 1;
                    res = dp[i][j];
                }
            }
            else dp[i][j] = 0; // this is the part where it changes
        }
    }
    string ans = "";
    cout << res << nl;
    while(res > 0){
        ans += s[a--];
        res--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << nl;
}

int main(){
    fast_io

    solve();

    return 0;
}