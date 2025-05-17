class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {nums[i], i};
        sort(a.begin(), a.end());
        set<int> st{n};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            st.insert(a[i].second);
            if (a[i].first != 0) ans++;
            while (i + 1 < n && a[i].first == a[i + 1].first) {
                int nextSmallerIndex = *st.upper_bound(a[i].second);
                int nextSameGuyIndex = a[i + 1].second;
                if (nextSmallerIndex < nextSameGuyIndex) break;
                i++;
                st.insert(a[i].second);
            }
        }
        return ans;
    }
};