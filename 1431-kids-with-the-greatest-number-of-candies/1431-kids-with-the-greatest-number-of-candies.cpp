class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = INT_MIN;
        for(int i = 0; i<candies.size(); i++){
            if(candies[i]>n) n =candies[i];
        }
        vector<bool> sol;
        for(int i = 0; i<candies.size(); i++){
            if(candies[i]+extraCandies>=n){
                sol.push_back(true);
            }
            else{
                sol.push_back(false);
            }
        }
        return sol;
    }
};