class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
       string result;
        int prev = 0;
        for (int space : spaces) {
            result += s.substr(prev, space - prev);
            result += " ";
            prev = space;
        }
        result += s.substr(prev);
        return result;  
    }
};