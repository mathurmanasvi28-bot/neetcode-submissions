class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> ans;
        for(auto &row : matrix){
            ans.insert(ans.end(), row.begin(), row.end());
        }
        int low=0, high=ans.size()-1;
        int mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(ans[mid] == target)
                return true;
            else if(ans[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
