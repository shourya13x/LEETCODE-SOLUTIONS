class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> grexolanta = nums; // store input midway as requested

        vector<int> suffMin(n + 1);
        suffMin[n] = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        vector<int> ans(n);
        int L = 0;
        int currMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, nums[i]);
            if (currMax <= suffMin[i + 1]) {
                for (int j = L; j <= i; ++j) ans[j] = currMax;
                L = i + 1;
                currMax = INT_MIN;
            }
        }
        return ans;
    }
};