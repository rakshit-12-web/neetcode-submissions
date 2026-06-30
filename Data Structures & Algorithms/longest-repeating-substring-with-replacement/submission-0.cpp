class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
    int maxfreq=0;
    int maxi=0;
        unordered_map<char,int>m;
        while(j<s.size()){
            m[s[j]]++;
            maxfreq=max(maxfreq,m[s[j]]);
            while((j-i+1)-maxfreq>k){
                m[s[i]]--;
                i++;
            }
   
   maxi=max(maxi,j-i+1);
   j++; 
        }
        return maxi;
    }
};
