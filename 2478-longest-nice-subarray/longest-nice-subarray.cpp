class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int s= 0;
        int t= 0;

        int count = 0;
        int bitwise = 0;
        while(t<nums.size()){
           while((bitwise & nums[t])!=0){
                bitwise ^= nums[s];
                s++;
           }
           bitwise |= nums[t];
           t++;
           count = max(count,t-s);
        }

        return count;
    }
};