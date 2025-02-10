class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=n*(n-1LL)/2;
        map<int, int> freq;
        for(int i=0; i<n; i++)
            freq[nums[i]-i]++;
        for(auto& [x, f]: freq){
            if (f>1)
                cnt-=f*(f-1LL)/2;
        }
        return cnt;
    }
};