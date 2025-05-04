class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size()-1;
        int ans = INT_MIN;
        while(s<e){
            int min = (height[s]<height[e])?height[s]:height[e];
            ans = (ans<(min*(e-s)))?(min*(e-s)):ans;
            if(height[s]<height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};