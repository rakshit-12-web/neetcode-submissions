class Solution {
public:

    string encode(vector<string>& strs) {
       string ans = "";

        for (string s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }

        return ans;
    }

    vector<string> decode(string s) {
         vector<string> ans;
        int i = 0;

        while (i < s.size()) {

            // Find '#'
            int j = i;
            while (s[j] != '#')
                j++;

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract the string
            ans.push_back(s.substr(j + 1, len));

            // Move to next encoded string
            i = j + 1 + len;
        }

        return ans;
     
    }
};
