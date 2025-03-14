class Solution {
public:
    bool solve(int res,vector<int>& candies, long long k){
        long long cnt=0;

        for(auto it:candies){
            cnt+=it/res;
        }

        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long sum=0;
        for(auto it:candies){
            sum+=it;
        }
        if(sum<k){
            return 0;
        }

        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,candies,k)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;

    }
};