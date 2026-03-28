#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<double> p(N); 
    for(double &x : p) cin >> x;

    vector<vector<double>> dp(N+1, vector<double>(N+1, 0));
    dp[0][0] = 1.0;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= i; j++){
            if(j > 0) dp[i][j] += dp[i-1][j-1] * p[i-1]; // head
            dp[i][j] += dp[i-1][j] * (1 - p[i-1]);       // tail
        }
    }

    double ans = 0;
    int start = (N + 1)/2;
    for(int j = start; j <= N; j++)
        ans += dp[N][j];

    cout << fixed << setprecision(10) << ans << endl;


    // Memory optimization Version
    // Idea : Since it only depends on the previous state
    // We can actually make the 2D DP on 1D.

    // dp[j] = probability of getting j heads after tossing coins so far
    // for(int i = 0; i < N; i++) {
    //     for(int j = i+1; j >= 1; j--) { 
    //         dp[j] = dp[j-1]*p[i] + dp[j]*(1-p[i]);
    //     }
    //     dp[0] *= (1-p[i]); 
    // }

    return 0;
}