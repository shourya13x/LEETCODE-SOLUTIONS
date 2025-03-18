class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<vector<int>> table;
        for (int i = 0; i < num2.size(); i++) {
            vector<int> row;
            for (int j = 0; j < i; j++) {
                row.push_back(0);
            }
            int carry = 0;
            for (int j = 0; j < num1.size(); j++) {
                int a = num1[j] - '0';
                int b = num2[i] - '0';
                int c = a * b;
                int d = (c + carry) % 10;
                carry = (c + carry) / 10;
                row.push_back(d);
            }
            if (carry) row.push_back(carry);
            table.push_back(row);
        }
        int maxSize = 0;
        for (auto &row : table) {
            maxSize = max(maxSize, (int)row.size());
        }
        for (auto &row : table) {
            while (row.size() < maxSize) {
                row.push_back(0);
            }
        }
        string result = "";
        int carry = 0;
        for (int i = 0; i < maxSize; i++) {
            int sum = carry;
            for (int j = 0; j < table.size(); j++) {
                sum += table[j][i];
            }
            result += (sum % 10 + '0');
            carry = sum / 10;
        }
        while (carry) {
            result += (carry % 10 + '0');
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        int pos = 0;
        while (pos < result.size() && result[pos] == '0') pos++;
        result = result.substr(pos);
        return result.empty() ? "0" : result;
    }
};