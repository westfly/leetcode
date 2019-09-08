#include "code_utils.h"
int minCostClimbingStairs(vector<int>& cost) {
	int dp[cost.size() + 1];
	dp[0] = 0;
	dp[1] = 0;
	// dp[i]= min(dp[i-1] + cost[i-1], dp[i-2]+cost[i-2])
	for (size_t i = 2; i <= cost.size(); ++i) {
		dp[i] = std::min(dp[i-1] + cost[i-1],
						 dp[i-2] + cost[i-2]);
	}
	return dp[cost.size()];
}
int minCostClimbingStairsOpt(vector<int>& cost) {
	int a = 0, b = 0;
	// dp[i]= min(dp[i-1] + cost[i-1], dp[i-2]+cost[i-2])
	for (size_t i = 2; i <= cost.size(); ++i) {
		int c = std::min(a, b) + cost[i -2];
        a = b;
        b = c;
	}
	return b;
}

int minCostClimbingStairs2(vector<int>& cost) {
    int n = cost.size();
	int dp[n];
	dp[0] = cost[0];
	dp[1] = cost[1];
    // 边界
	for (int i = 2; i < n; ++i) {
		dp[i] = cost[i] + std::min(dp[i-1], dp [i - 2]);
	}
	return std::min(dp[n - 1], dp[n - 2]);
}
