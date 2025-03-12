class Solution {
public:
    int maximumCount(vector<int>& v) {
        int pos = 0,neg=0 ;
        for(auto x : v){
            if(x>0)pos++;
            else if(x<0)neg++;
        }
        return max(pos,neg);
    }
};