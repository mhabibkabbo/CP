#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> a(N);
    for(int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
    
    vector<vector<ll>> dp(N+1, vector<ll> (W+1, 0));
    // dp[i][j] here i represents the item and j represents the weight
    // for each item we have to two choices 
    // we can include it or discard it 
    
    // ## Transition state
    // case #1 (exclusion) : dp[i][j] = dp[i-1][j]
    // case #2 (inclusion) : dp[i][j] = dp[i-1][j-w] + value of this current item

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= W; j++){
            ll w = a[i-1].first;
            ll v = a[i-1].second;
            dp[i][j] = max(dp[i-1][j], (j-w) < 0 ? 0 : (dp[i-1][j-w] + v));
        }
    }
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= W; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][W] << endl;
    return 0;
}