class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        st.push(0);
        vector<int>ans(temperatures.size(),0);
        for(int i = 1; i<temperatures.size(); i++){
            int t = temperatures[i];
            while(!st.empty() && t>temperatures[st.top()]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
    }
};
