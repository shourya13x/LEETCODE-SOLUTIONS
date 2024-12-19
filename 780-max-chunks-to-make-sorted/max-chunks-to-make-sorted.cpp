class Solution {
public:
     int maxChunksToSorted(vector<int>& v) 
    {
        //sum1 is sum of 0.........i
        //co is sum of v[0],v[1].......v[i]
        int i,co=0,sum1=0,ans=0;
        for(i=0;i<v.size();i++)
        {
            sum1+=i;
            co+=v[i];
            if(sum1==co)
                ans++;
        }
        return ans;
    }
};