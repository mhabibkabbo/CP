#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // If the stone is at the i-th pos
    // it can go either in (i+1) or (i+2)th pos
    // we have to minimize the cost


    int N;
    cin >> N;
    
    vector<int> h(N);
    for(int &x : h) cin >> x;

    vector<int> dp(N+1, 0); // dp[i] will store the min cost to land on i
    // Base cases
    dp[1] = 0;
    dp[2] = abs(h[0] - h[1]);
    for(int i = 3; i <= N; i++){
        // currently i am on i 
        // i can come to i from i-1 or i-2
        dp[i] = min(dp[i-1] + abs(h[i-2] - h[i-1]), dp[i-2] + abs(h[i-1] - h[i-3]));
    }

    cout << dp[N] << endl;

    return 0;
}