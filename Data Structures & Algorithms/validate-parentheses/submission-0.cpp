class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (auto c : s) {
            if (c == '('|| c == '{' || c == '[') {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                char top = parentheses.top();
                parentheses.pop();

                if (c == ')' && top != '(') {
                    return false;
                }

                if (c == '}' && top != '{') {
                    return false;
                }

                if (c == ']' && top != '[') {
                    return false;
                }
            }
        }

        if (!parentheses.empty()) {
            return false;
        }

        return true;
    }
};
