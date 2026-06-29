class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int i=0;
        int j=0;
        unordered_map<char,int>m;
        while(j<s.size()){
            m[s[j]]++;
        if(m[s[j]]>1){
            while(i<j&&m[s[j]]>1){
                m[s[i]]--;
                i++;
            }
        }
        maxi=max(maxi,j-i+1);
        j++;
        }
        return maxi;
    }
};
