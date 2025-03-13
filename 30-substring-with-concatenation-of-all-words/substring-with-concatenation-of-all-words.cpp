class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& arr) {
        map <string, int> mp, dp;
        vector <int> ans;
        string sub;
        
        int n = s.size();
        int k = arr[0].size();

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        for (int l = 0; l < k; l++) {
            vector <string> a;
        
            for (int i = l; i < n - k + 1; i += k) {    
                sub = "";

                for (int j = 0; j < k && i + j < n; j++) {
                    sub += s[i + j];
                }
                if (sub.size() == k) a.push_back(sub);    
            }
            int x = 0, y = 0;
            while (y < a.size()) {
                dp[a[y]]++;

                while(y - x + 1 > arr.size()) {
                    dp[a[x]]--;
                    x++;
                }

                int ok = 1;
                for (auto it = mp.begin(); it != mp.end(); ++it) {
                    if (it->second != dp[it->first]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) ans.push_back(l + (x * k));
                
                y++;
            }
            while(x < a.size()) {
                dp[a[x]]--;
                x++;
            }
            a.clear();
        }
        
        return ans;
    }
};