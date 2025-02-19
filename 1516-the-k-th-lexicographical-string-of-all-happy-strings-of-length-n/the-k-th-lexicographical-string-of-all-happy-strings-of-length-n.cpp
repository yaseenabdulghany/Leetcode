class Solution {
    void rec(int n,string t,string &ans,string curr,int& k) {
        if(curr.length() == n) {
            k--;
            if(k == 0) {
                ans = curr;
            }
            return;
        }
        bool flag = false;
        for(int i = 0; i<3;i++) {
            if(curr.empty()) {
                curr += t[i];
                rec(n,t,ans,curr,k);
                curr.pop_back();
            }
            else {
                char ch = curr.back();
                if(ch != t[i]) {
                    curr += t[i];
                    rec(n,t,ans,curr,k);
                    curr.pop_back();
                }
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        string s = "";
        string t = "abc";
        string ans = "";
        rec(n,t,ans,s,k);
        return ans;
    }
};