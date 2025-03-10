class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long cnt = 0;
        queue<int> son;
        int left = -1;
        int last[26]; 
        fill(last, last+26, -1);
        for(int right = 0; right < word.size(); ++right){
            if(isVowel(word[right])){
                last[ word[right] - 'a' ] = right;
            } else {
                son.push(right);
                if(son.size() > k){
                    left = son.front();
                    son.pop();
                }
            }
            if(son.size() == k){
                int ind = k==0 ? right : son.front();
                ind = min(ind, last['a'-'a']);
                ind = min(ind, last['e'-'a']);
                ind = min(ind, last['i'-'a']);
                ind = min(ind, last['o'-'a']);
                ind = min(ind, last['u'-'a']);
                if(ind > left) cnt += ind - left;
            }
        }
        return cnt;
    }
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};