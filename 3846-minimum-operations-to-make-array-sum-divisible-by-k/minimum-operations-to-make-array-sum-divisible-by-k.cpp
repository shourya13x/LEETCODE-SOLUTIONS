class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int totalSum = 0;
        if (nums.size() == 0)
            return 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        int remainder = totalSum % k;
        return remainder;
    }
    
};