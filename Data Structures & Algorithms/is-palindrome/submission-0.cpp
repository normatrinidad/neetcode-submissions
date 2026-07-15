class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](unsigned char c) {
            return !isalnum(c);
        });

        int begin = 0;
        int end = s.size() - 1;

        while(begin < end) {
            if (tolower(s[begin]) != tolower(s[end])) {
                return false;
            } 

            begin++;
            end--;
        }

        return true;
    }
};
