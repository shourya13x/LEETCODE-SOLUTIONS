class Solution {
public:
    int dp[71][4901];
    int helper(int i, int m, int n, vector<vector<int>>& mat, int target, int curr_sum){
        if(i == m)
            return abs(target - curr_sum);
        if(dp[i][curr_sum] != -1)
            return dp[i][curr_sum];
        int mini = INT_MAX;
        for(int j = 0 ; j < n ; j++)
            mini = min(mini, helper(i + 1, m, n, mat, target, curr_sum + mat[i][j]));
        return dp[i][curr_sum] = mini;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size(), mini = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int j = 0 ; j < n ; j++)
            mini = min(mini, helper(1, m, n, mat, target, mat[0][j]));
        return mini;
    }
};