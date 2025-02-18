class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string res = "";
        char idx = '1';
        st.push(idx++);
        for(auto& p:pattern){
            if(p == 'I'){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
                st.push(idx++);
            }
            else{
                st.push(idx++);
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;   
    }
};