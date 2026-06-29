class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>>result;
       for(int i=0;i<strs.size();i++){
            vector<int>check(26,0);
            for(int j=0;j<strs[i].length();j++){
                check[strs[i][j]-'a']++;
            }
            string key = to_string(check[0]);
            for(int j=1;j<26;j++){
                key += ","+ to_string(check[j]);
            }
            result[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it = result.begin(); it != result.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
