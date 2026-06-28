class Solution {
public:
char valid(char s){
    if(s>='A'&&s<='Z'){
        return s-'A'+'a';
    }
    return s;
}
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') ||
   (s[i]>='A' && s[i]<='Z') ||
   (s[i]>='0' && s[i]<='9'))
{
    temp.push_back(valid(s[i]));
}
        }
        int st=0;
        int e=temp.size()-1;
        while(st<e){
            if(temp[st]!=temp[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};
