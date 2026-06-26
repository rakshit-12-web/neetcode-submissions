class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.size()!=t.size()){
            return false;
        }
        int i=s.size()-1;
        int j=t.size()-1;
        while(i>=0&&j>=0){
            if(s[i]!=t[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};
