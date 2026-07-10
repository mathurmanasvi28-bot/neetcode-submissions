class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>maap;
        for(int i=0; i<nums.size();i++){
            if(maap.find(target-nums[i]) != maap.end()){
                return {maap[target - nums[i]], i};
            }
            maap[nums[i]] = i;
        }
        return {};
    }
};
