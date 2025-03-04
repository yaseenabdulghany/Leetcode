class Solution {
public:
    unordered_map<string, int> mp;
    bool solve(vector<long long>& res, int idx, int n) {
        if(idx == 0) {
            if(res[idx] == n || n == 0) return 1;
            else return 0;
        }
        string curr = to_string(idx) + "_" + to_string(n);
        if(mp.find(curr) != mp.end()) return mp[curr];
        bool ntake = solve(res, idx - 1, n);
        bool take = false;
        if(res[idx] <= n) {
            take = solve(res, idx - 1, n - res[idx]);
        }
        return mp[curr] = take || ntake;
    }
    bool checkPowersOfThree(int n) {
        vector<long long> res(17, 0);
        for(int i = 0; i <= 16; i++) {
            res[i] = pow(3, i);
            if(res[i] > n) break;
        }
        return solve(res, 16, n);
    }
};