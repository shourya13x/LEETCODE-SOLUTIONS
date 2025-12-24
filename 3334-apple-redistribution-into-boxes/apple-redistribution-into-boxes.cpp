class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<>());

        int total = 0;
        for(int i: apple) total+=i;

        int used = 0;
        for( ; used < capacity.size() ; used++){
            total -= capacity[used];
            if(total<=0) break;
        }
        return used+1;
    }
};