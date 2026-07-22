class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ans(nums.begin(),nums.end());
        
        int maxlength = 0;
        for(int i=0; i<nums.size();i++){
            if(ans.find(nums[i]-1)==ans.end()){
                int count =1;
                int current = nums[i];
                while(ans.find(current+1)!=ans.end()){
                    count++;
                    current++;
                }
                maxlength = max(count,maxlength);
            }
        }
        return maxlength;
    }
};
