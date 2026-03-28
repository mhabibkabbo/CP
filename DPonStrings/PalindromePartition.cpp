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

    // Here I used the LCS trick to solve the problem

    // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // string r = s;
    // reverse(r.begin(), r.end());

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         if(i == j){
    //             dp[i][j] = 1;
    //             continue;
    //         }

    //         if(s[i] == r[j]){
    //             if(i + 1 == j) dp[i][j] = 2;
    //             else dp[i][j] = 2 + dp[i+1][j-1];
    //         }
    //     }
    // }


    // ### Another DP Approach (Rigorous DP)

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    // base case
    // dp[i][i] = 1;
    // dp[i][j], longest palindrome subsequence in this i...j interval
    for(int i = n - 1; i > 0; i--){
        for(int j = i; j < n; j++){
            
        }
    }
}

int main(){
    fast_io

    solve();

    return 0;
}