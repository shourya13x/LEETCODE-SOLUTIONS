class Solution {
public:
    static int maxDistance(string& s, int k) {
        const int n=s.size();
        int Q1=0, Q2=0, Q3=0, Q4=0, dist=0;
        for(int i=0; i<n; i++){
            const char c=s[i];
            Q1+=(c=='N' || c=='E');
            Q2+=(c=='N' || c=='W');
            Q3+=(c=='W' || c=='S');
            Q4+=(c=='S' || c=='E');
            const int d=max(abs(Q1-Q3), abs(Q2-Q4))+2*k;
            dist=max(dist, min(d, i+1));
        }
        return dist;
    }
}; 