class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string result = "";
      unordered_map<char,int>freq;
      for(auto it:s)
      {
        freq[it]++;
      }  
      while (!freq.empty()) {
            char maxChar = '\0';  // Character with the highest frequency
            int maxFreq = 0;

            // Find the character with the highest frequency
            for (auto& pair : freq) {
                if (pair.second > maxFreq) {
                    maxFreq = pair.second;
                    maxChar = pair.first;
                }
            }

            // Append maxFreq occurrences of maxChar to result
            result.append(maxFreq, maxChar);

            // Remove the character from the map
            freq.erase(maxChar);
        }

        return result;   
      
    }
};