class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector <int> ans;
        int carry = 0;
        for(int i = digits.size()-1; i>=0; i--){
            if(i==digits.size()-1){
                carry = (digits[i] + 1 )/10;
                ans.push_back((digits[i]+1)%10);
            }
            else{
                int dig = digits[i] + carry;
                carry = dig/10;
                ans.push_back(dig%10);
            }
        }
        if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};