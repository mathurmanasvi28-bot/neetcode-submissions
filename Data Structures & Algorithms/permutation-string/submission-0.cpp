class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        int r = s1.length()-1;
        unordered_map<char,int>checks1;
        for(int i=0;i<s1.length();i++){
            checks1[s1[i]]++;
        }
        while(r<s2.length()){
            unordered_map<char,int>checks2;
            for(int i=l;i<=r;i++){
                checks2[s2[i]]++;
            }
            if(checks1==checks2){
                return true;
            }
            l++;
            r++;
        }
        return false;
    }
};
