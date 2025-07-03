class Solution {
public:
    char kthCharacter(int k) {
        // Convert to 0-based indexing
        k--;
        
        // Count the number of 1s in the binary representation of k
        int operations = 0;
        int temp = k;
        
        // Count set bits using bit manipulation
        while (temp > 0) {
            operations += temp & 1;  // Add 1 if the least significant bit is 1
            temp >>= 1;              // Right shift to check the next bit
        }
        
        // Start with 'a' and add the number of operations
        // This gives us the final character after all transformations
        return 'a' + operations;
    }
};