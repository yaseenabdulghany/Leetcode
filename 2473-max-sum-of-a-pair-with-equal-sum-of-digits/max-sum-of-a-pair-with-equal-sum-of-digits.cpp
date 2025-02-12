class Solution {
    int Sumdigit(int n){
        int digitsum=0;
        while(n!=0){
        int lastdigit=n%10;
        digitsum+=lastdigit;
                n=n/10;
        }
        return digitsum;
    }
public:
   long int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp; 
        for(int i=0;i<nums.size();i++){
            mpp[Sumdigit(nums[i])].push_back(nums[i]);
        }

        int maxsum=-1;
        for(auto &[key, b]: mpp){

            sort(b.rbegin(),b.rend());
            
            if(b.size()>1) maxsum = max(maxsum,b[0]+b[1]);
            
        }

      return maxsum ;  
    }
};