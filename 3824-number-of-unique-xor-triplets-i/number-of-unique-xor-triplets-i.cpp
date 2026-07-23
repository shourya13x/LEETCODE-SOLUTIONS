class Solution {
public:
    int uniqueXorTriplets(vector<int>& arr) {
        int len = (int)arr.size();
        if (len == 1) return 1;
        if (len == 2) return 2;

        int bit = 0;
        while ((1 << (bit + 1)) <= len) {
            ++bit;
        }

        int ans = 1 << (bit + 1);
        return ans;
    }
};