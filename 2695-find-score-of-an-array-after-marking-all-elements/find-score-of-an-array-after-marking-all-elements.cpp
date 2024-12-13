class Solution {
public:
    long long findScore(vector<int>& nums) {
         long long ans=0;
        vector<pair<int,int>> num;
        
        for(int i=0;i<nums.size();i++){
            num.push_back({nums[i],i+1});
        }
        sort(num.begin(),num.end());
        
        vector<int> vis(nums.size()+2,0); // so one need to add corner indexes
        
        for(auto &it: num){
            if(vis[it.second]==1) continue;
            
            ans+= it.first;
            
            vis[it.second]=1;
            vis[it.second-1]=1;
            vis[it.second+1]=1;
        }
        
        return ans; 
    }
};