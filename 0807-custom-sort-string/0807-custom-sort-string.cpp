string OrderCopy;
class Solution {
public:
    static bool cmp(char c1, char c2){
        return OrderCopy.find(c1)< OrderCopy.find(c2);
    }
    string customSortString(string order, string s) {
        OrderCopy = order;
        sort(s.begin(), s.end(),cmp);
        return s;
    }
};