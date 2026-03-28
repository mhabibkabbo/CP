#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int m, n;
    m = s.size();
    n = t.size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // #Match
            if(s[i] == t[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]); // Transition state
        }
    }
    // Now we need to backtrack
    string ans = "";
    int i = m;
    int j = n;
    // Backtracking to get the subsequence 
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i][j-1]) j--;
        else if(dp[i][j] == dp[i-1][j]) i--; 
        else {
            ans += s[i-1];
            i--, j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}