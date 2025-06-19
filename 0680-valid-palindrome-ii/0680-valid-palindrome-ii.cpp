class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int a = 0, b = s.length() - 1;

        while (a < b) {
            if (s[a] != s[b]) {
                return isPalindrome(s, a + 1, b) || isPalindrome(s, a, b - 1);
            }
            a++;
            b--;
        }

        return true;
    }
};
