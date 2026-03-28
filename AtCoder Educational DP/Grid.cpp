#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    vector<string> g(H);
    for(int i = 0; i < H; i++) cin >> g[i];
    vector<vector<int>>dp(H+1, vector<int>(W+1, 0));

    // Base case
    if(g[0][0] == '.') dp[1][1] = 1;
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(i == 1 && j == 1) continue;
            if(g[i-1][j-1] == '#') continue; // '#' means total path 0
            int m = i - 1;
            int n = j - 1;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    // for(int i = 0; i <= H; i++){
    //     for(int j = 0; j <= W; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[H][W] << endl;
    return 0;
}