class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int l=0;
        int r=heights.size()-1;
        while(l<r){
            int temp = min(heights[l],heights[r]);
            ans = max(ans, (temp*(r-l)));
            if(heights[l]<heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};
