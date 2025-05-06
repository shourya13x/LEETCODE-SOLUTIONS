

#include <vector>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};