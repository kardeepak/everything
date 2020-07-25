#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long int LL;


LL solve() {
	LL n, m; cin >> n >> m;
	LL cost[n+1];
	for(int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	LL dp[n+1][m+1]; memset(dp, 0, sizeof(dp));
	LL ans = -1;
	for(LL i = 1; i <= n; i++) {
		for(LL j = 1; j <= m; j++) {
			if(i == 1) {
				dp[i][j] = (j == m ? 0 : -1);
			}
			else if(j == m) {
				if(cost[i] != 0) {
					
				}
				else {
					dp[i][j] = -1;
				}
			}
			else if(i-1 > 0 && j+1 <= m) {
				dp[i][j] = dp[i-1][j+1];
			}

			if(i == n && dp[i][j] != -1) {
				ans = dp[i][j];
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;

	}
	return ans;
}

int main() {
	LL t; cin >> t;
	for(LL c = 1; c <= t; c++) {
		LL ans = solve();
		cout << "Case #" << c << ": " << ans << endl;
	}
}
