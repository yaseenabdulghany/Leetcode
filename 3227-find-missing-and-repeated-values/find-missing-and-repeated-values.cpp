class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        vector<int>ans;
        int cnt=0;
        map<int,int>mp;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                mp[v[i][j]]++;
                cnt++;
            }
        }
        for(auto x : mp){
            if(x.second>1)ans.push_back(x.first);
        }
        for (int i = 1; i < cnt+1; ++i) {
            if(!mp[i])ans.push_back(i);
        }
        return ans;
    }
};