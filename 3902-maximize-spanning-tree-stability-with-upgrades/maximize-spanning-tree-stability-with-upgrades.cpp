typedef long long ll;
class Solution {
public:
    vector<ll> par;
    vector<ll> rnk;
    void makeset(ll n)
    {
        par.resize(n);
        rnk.resize(n, 1);
        for (ll i = 1; i < n; i++)
            par[i] = i;
    }
    ll findset(ll x)
    {
        if (par[x] == x)
            return x;
        return (par[x] = findset(par[x]));
    }
    void unionset(ll x, ll y)
    {
        ll a = findset(x);
        ll b = findset(y);
        if (a == b)
            return;
        if (rnk[a] > rnk[b])
        {
            rnk[a] += rnk[b];
            par[b] = a;
        }
        else
        {
            rnk[b] += rnk[a];
            par[a] = b;
        }
    }
    bool checker(vector<vector<ll>> &tempedges,ll mid, ll k){
        bool ans = true;
        for(auto i: tempedges){
            ll s = i[0];
            ll u = i[1];
            ll v = i[2];
            if(findset(u)!=findset(v)){
                if(s<mid){
                    if(k>0){
                        s*=2;
                        k--;
                    }
                    else{
                        ans=false;
                        break;
                    }
                }
                if(s<mid){
                    ans = false;
                    break;
                }
                else{
                    unionset(u,v);
                    // k--;
                }
            }
        }
        return ans;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        makeset(n);
        vector<vector<ll>> tempedges;
        ll res = LLONG_MAX;
        for(auto &edge: edges){
            ll u = edge[0];
            ll v = edge[1];
            ll s = edge[2];
            ll must = edge[3];
            if(must==1){
                if(findset(u)==findset(v))
                    return -1;
                unionset(u,v);
                res = min(res,s);
            }
            else{
                tempedges.push_back({s,u,v});
            }
        }
        ll lo = 0;
        ll hi = res;
        ll answer = lo;
        vector<ll> pc=par;
        vector<ll> rc=rnk;
        sort(tempedges.rbegin(),tempedges.rend());
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            bool ans = checker(tempedges,mid,k);
            par = pc;
            rnk = rc;
            if(ans){
                lo = mid+1;
                answer=mid;
            }
            else{
                hi = mid-1;
            }
        }
        for(auto &i: tempedges){
            ll u = i[1];
            ll v = i[2];
            if(findset(u)!=findset(v)){
                unionset(u,v);
            }
        }
        if(rnk[findset(0)]!=n)
        return -1;
        return (int)answer;
        // sort(tempedges.rbegin(),tempedges.rend());
        // for(auto &e: tempedges){
        //     ll u = e[1];
        //     ll v = e[2];
        //     ll s = e[0];
        //     if((findset(u)!=findset(v))&&(k>0)){
        //         unionset(u,v);
        //         res = min(res,2*s);
        //         k--;
        //     }
        // }
    }
};