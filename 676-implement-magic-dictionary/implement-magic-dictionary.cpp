class trie {
private:
    static const int chars = 26;
    trie* child[chars];
    bool isleaf{};
public:
    trie(){
        memset(child,0, sizeof(child));
    }

    void insert(string str) {
        trie* cur = this;

        for (int idx = 0; idx < (int) str.size(); ++idx) {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                cur->child[ch] = new trie();
            cur = cur->child[ch];
        }
        cur->isleaf = true;
    }

    bool prefix_exist(string pre, int idx = 0) {
        if (idx == pre.size()) return true;
        int pos = pre[idx] - 'a' ;
        if (!child[pos])return false;
        return child[pos]->prefix_exist(pre, idx + 1);
    }

    bool word_exist(string str) {
        trie* cur = this;
        for (int idx = 0; idx < (int) str.size(); ++idx) {
            int ch = str[idx] - 'a';
            if (!cur->child[ch])
                return false;	// such path don't exist
            cur = cur->child[ch];
        }
        return cur->isleaf;
    }

    void get_all_strings(vector<string> &res , string cur = ""){
        if(isleaf)res.push_back(cur);
        for (int i = 0; i < chars; ++i) {
            if(child[i]) child[i]->get_all_strings(res,cur+(char)(i+'a'));
        }
    }

    void auto_complete(const string &str, vector<string>&res){
        trie* cur = this ;
        for (int i = 0; i < (int)str.size(); ++i) {
            int pos = str[i] - 'a' ;
            if(!child[pos])return;
            cur = cur -> child[pos];
        }
        cur->get_all_strings(res,str);
    }

    bool word_exist_with_1_change(string str) {
        for (int i = 0; i < (int) str.size(); ++i) {
            char cur = str[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == cur)
                    continue;
                str[i] = ch;
                if (word_exist(str))
                    return true;
            }
            str[i] = cur;
        }
        return false;
    }
};
class MagicDictionary {
public:
    trie t;

    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (int i = 0; i < (int) dictionary.size(); ++i) {
            t.insert(dictionary[i]);
        }

    }

    bool search(string str) {
        return t.word_exist_with_1_change(str);
    }
};