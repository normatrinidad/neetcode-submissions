class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for (const auto& str : strs) {
            output = output + to_string(str.length()) + "#" + str;
        }

        return output;
    }

    vector<string> decode(string s) {
        int index = 0;
        vector<string> output = {};
        while (index < s.length()) {
            string number = "";
            while (s[index] != '#') {
                number+=s[index++];
            }

            int l = stoi(number);
            string original_str = s.substr(++index, l);
            output.push_back(original_str);
            index+=l;
        }

        return output;
    }
};
