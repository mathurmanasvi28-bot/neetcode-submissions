using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char , char> closetoopen = {
            {')','('},{']','['},{'}','{'}
        };
        for(char c: s){
            if(closetoopen.count(c)){
                if(!st.empty() && st.top() == closetoopen[c]){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(c);
            }
        }
        return st.empty();
    }
};
