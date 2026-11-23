#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int TSP(int curr, int mask, vector<vector<int>>& cost,
        vector<vector<int>>& dp) {

    int n = cost.size();
    if (mask == (1 << n) - 1) {
        return cost[curr][0];
    }
    if (dp[curr][mask] != -1) {
        return dp[curr][mask];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int total = cost[curr][i] +
                TSP(i, mask | (1 << i), cost, dp);
            ans = min(ans, total);
        }
    }
    return dp[curr][mask] = ans;
}
int solveTSP(vector<vector<int>>& cost) {
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    return TSP(0, 1, cost, dp);
}
int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    cout << "Minimum TSP Cost: " << solveTSP(cost);
    return 0;
}
