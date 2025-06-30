class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>arr(numRows);
        if (numRows == 1 || numRows >= s.size()) return s;
        int i = 0, row = 0;
        bool direction = 1;
        while(true){
            if(direction == 1){
                while(row<numRows && i<s.size()){
                    arr[row++] += s[i++];
                }
                row = numRows-2;
            }
            else{
                while(row>=0 && i<s.size()){
                    arr[row--] += s[i++];
                }
                row = 1;
            }
            if(i>=s.size()) break;
            direction = !direction;
        }
        string ans;
        for(string s:arr){
            ans+=s;
        }
        return ans;
    }
};