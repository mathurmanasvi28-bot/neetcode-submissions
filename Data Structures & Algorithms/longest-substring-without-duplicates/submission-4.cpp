class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int maxlength =0;
        unordered_set <char>check;
        while(r<s.length()){
            
            if(check.find(s[r]) == check.end()){
                check.insert(s[r]);
                maxlength = max(maxlength,r-l+1);
            }else{
                while(check.find(s[r]) != check.end()){
                    check.erase(s[l]);
                    
                    l++;
                }
            }
            check.insert(s[r]);
            r++;
        }
        return maxlength;
    }
};
