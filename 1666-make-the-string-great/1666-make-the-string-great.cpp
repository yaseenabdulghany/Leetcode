class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (char c : s) {
            if (ans.empty() || abs(ans.back() - c) != 32) {
                ans += c;
            } else {
                ans.pop_back();
            }
        }
        return ans;
    }
};