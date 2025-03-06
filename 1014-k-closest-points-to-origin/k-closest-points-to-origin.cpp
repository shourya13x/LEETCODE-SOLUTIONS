class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // This Problem is same as K largest element from input list but opposite to that problem
        // we can maintain distance and points in pair data structure
        priority_queue<pair<int, vector<int>>> closestpoints; // max heap
        for(auto point:points)
        {
            int x_cord = point[0];
            int y_cord = point[1];
            int dist = x_cord*x_cord+y_cord*y_cord; // no need of sqrt
            if(closestpoints.size()<k)
            {
                closestpoints.push({dist,point});
            }
            else if(dist<closestpoints.top().first)
            {
                closestpoints.pop();
                closestpoints.push({dist,point});
            }
        }
        vector<vector<int>> resultClosePoints;
        while(k>0)
        {
            resultClosePoints.push_back(closestpoints.top().second);
            closestpoints.pop();
            k--;
        }
        return resultClosePoints;
    }
};