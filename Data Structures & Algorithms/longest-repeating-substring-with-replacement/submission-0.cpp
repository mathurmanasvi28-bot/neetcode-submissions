class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        vector<int>hash(26,0);
        int maxlength = 0, maxfreq=0;
        while(r<s.length()){
            hash[s[r]-'A']++;
            maxfreq = max(hash[s[r]-'A'],maxfreq);
            if((r-l+1 - maxfreq)>k){
                hash[s[l]-'A']--;
                l++;
            }
            maxlength=max(r-l+1,maxlength);
            r++;
        }
        return maxlength;
    }
};
