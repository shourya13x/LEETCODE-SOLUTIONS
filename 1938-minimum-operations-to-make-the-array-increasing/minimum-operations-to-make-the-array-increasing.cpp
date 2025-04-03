class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation = 0;
        
        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] >=nums[j]) {
                    int diff=nums[i]-nums[j]+1;
                   nums[j]+=diff;
                operation+=diff;
                } 
                
            }
        }
        return operation;
    }
};