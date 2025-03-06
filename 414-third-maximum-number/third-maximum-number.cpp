class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max || nums[i] == max2 || nums[i] == max3)
                continue;
            if (nums[i] > max) {
                max3 = max2;
                max2 = max;
                max = nums[i];
            } else if (nums[i] > max2 && nums[i] != max) {
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] > max3 && nums[i] != max && nums[i] != max2) {
                max3 = nums[i];
            }
        }
        if (nums.size() < 3) {
            return max;
        }
        return (max3 == LONG_MIN) ? max : max3;
    }
};