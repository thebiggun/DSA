class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        
        char current = 'a';

        for(char c : key) {
            if(c != ' ' && m.find(c) == m.end()) {
                m[c] = current++;
            }
        }

        string decoded = "";
        for(char c : message) {
            if(c == ' ') {
                decoded += ' ';
            } else {
                decoded += m[c];
            }
        }

        return decoded;
    }
};
