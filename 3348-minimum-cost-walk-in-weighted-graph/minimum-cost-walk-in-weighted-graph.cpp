class DSU{
    public:
    vector<int> parent;
    vector<int> ans;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        ans.resize(n, -1);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        return findParent(parent[u]);
    }
    void insert(int u, int v, int wt){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv){
            ans[pu] = ans[pu] & wt;
            return;
        } 
        if(rank[pu] > rank[pv]){
            ans[pu] = ans[pu] & wt & ans[pv];
            parent[pv] = pu; 
        }else if(rank[pu] < rank[pv]){
            ans[pv] = ans[pv] & wt & ans[pu];
            parent[pu] = pv;
        }else{
            ans[pu] = ans[pu] & wt & ans[pv];
            parent[pv] = pu;
            rank[pu] += 1;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto edge : edges){
            dsu.insert(edge[0], edge[1], edge[2]);
        }
        vector<int> ans;
        for(auto q : query){
            int pu = dsu.findParent(q[0]);
            int pv = dsu.findParent(q[1]);
            if(pu != pv) ans.push_back(-1);
            else ans.push_back(dsu.ans[pu]);
        }
        return ans;
    }
};