class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1;
        long long e = *max_element(piles.begin(), piles.end());
        long long ans = e;
        while(s<=e){
            long long mid = s+(e-s)/2;
            long long count = 0;
            for(int i:piles){
                if(i%mid == 0){
                    count += i/mid;
                }
                else{
                    count += i/mid + 1;
                }
            }
            if(count<=h){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return (int)ans;
    }
};