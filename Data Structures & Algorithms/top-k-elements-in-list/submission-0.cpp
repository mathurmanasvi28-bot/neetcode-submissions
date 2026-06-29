class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
         // Count frequencies
        for(int num : nums){
            freq[num]++;
        }

        // Store {frequency, number}
        vector<pair<int, int>> vec;
        for(auto it : freq){
             vec.push_back({it.second, it.first});
        }
        // Sort by frequency descending
        sort(vec.begin(), vec.end(), greater<pair<int,int>>());

        vector<int> ans;
        // Take first k elements
        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    };
};