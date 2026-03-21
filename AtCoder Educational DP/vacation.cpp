#include <bits/stdc++.h>
using namespace std;

// you can solve this problem without dp 
// can be done in O(1)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(3));
    for(int i = 0; i < N; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    vector<vector<int>> dp(N, vector<int>(3));

    // base case
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i = 1; i < N; i++){
        dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << '\n';
}