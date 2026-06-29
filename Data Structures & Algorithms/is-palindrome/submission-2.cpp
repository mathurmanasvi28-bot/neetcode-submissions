class Solution {
public:
    bool isPalindrome(string s) {
        int first=0;
        int last = s.length()-1;
        while(first<last){
            if(!isalnum(s[first])){
                first++;
                continue;
            }
            if(!isalnum(s[last])){
                last--;
                continue;
            }
            if(tolower(s[first])!=tolower(s[last])){
                return false;
            }
            first++ ,last--;
        }
        return true;
    }
};
