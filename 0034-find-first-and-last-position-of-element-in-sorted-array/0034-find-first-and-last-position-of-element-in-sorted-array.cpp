class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int ans = -1;
        int mid;
        vector <int> res;
        while(s<=e){
            mid = s + ((e-s)/2);
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        if(ans==-1) return {-1,-1};
        res.push_back(ans);
        s = 0;
        e = nums.size()-1;
        while(s<=e){
            mid = s + ((e-s)/2);
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        res.push_back(ans);
        return res;
    }
};