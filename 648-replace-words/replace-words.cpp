class trie {
private:
    static const int MAX_char = 26;
    trie *child[MAX_char];
    bool isleaf{};
public:
    trie() {
        memset(child, 0, sizeof(child));
    }

    void insert(string s, int idx = 0) {
        if (idx == (int) s.size()) {
            isleaf = 1;
            return;
        }
        int pos = s[idx] - 'a';
        if (!child[pos]) {
            child[pos] = new trie();
        }
        child[pos]->insert(s, idx + 1);
    }

    bool prefix_exist(string pre, int idx = 0) {
        if (idx == (int) pre.size())return true;
        int pos = pre[idx] - 'a';
        if (!child[pos])return false;
        return child[pos]->prefix_exist(pre, idx + 1);
    }

    string smallest_prefix(string s, int idx = 0 ,string ans="") {
        if (idx == (int) s.size() || isleaf)return ans;
        int pos = s[idx] - 'a';
        if (!child[pos])return s;
        return child[pos]->smallest_prefix(s, idx + 1,ans+s[idx]);
    }

    bool word_exist(string pre, int idx = 0) {
        if (idx == (int) pre.size())return isleaf;
        int pos = pre[idx] - 'a';
        if (!child[pos])return false;
        return child[pos]->word_exist(pre, idx + 1);
    }

    string first_word_prefix(string &s){
        return smallest_prefix(s);
    }
};
class Solution {
public:
    string replaceWords(vector<string>& v, string s) {
        trie t;
        for(auto it : v)t.insert(it);
            vector<string> v2;

        string cur = "";
    for (int i = 0; i < s.size() ; ++i) {
        if(s[i]==' '){
            v2.push_back(cur);
            cur.clear();
        }
        else cur+=s[i];
    }
    v2.push_back(cur);

    string ans = "";

    for(auto cc : v2){
        ans+=t.first_word_prefix(cc);
        ans+=' ';

    }
        ans.pop_back();
        return ans;
    }
};