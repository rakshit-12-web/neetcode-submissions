class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
      
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
          int j=0;
        int i=0;
        int startindex=0;
        int mini=INT_MAX;
        int count=m.size();
        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                  count--;
                }
            }
         while(count==0){
            if(mini>j-i+1){
                mini=j-i+1;
                startindex=i;
            }
         if(m.find(s[i])!=m.end()){
            m[s[i]]++;
            if(m[s[i]]>0){
                count++;
            }
            }        
         i++;
         }
         j++;
        }
        if(mini==INT_MAX){
            return "";
        }
return s.substr(startindex,mini);
    }
};