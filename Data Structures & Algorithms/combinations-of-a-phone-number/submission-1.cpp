#include<map>
class Solution {
public:
void solve(string digits,int index,string temp,vector<string>&ans, unordered_map<char,string>m){
    if(index>=digits.length()){
        ans.push_back(temp);
        return;
    }
char ch=digits[index];
string t=m[ch];
for(int i=0;i<t.length();i++){
    temp.push_back(t[i]);
    solve(digits,index+1,temp,ans,m);
    temp.pop_back();
}
}
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string>ans;
        string temp="";
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
         m['5']="jkl";
         m['6']="mno";
         m['7']="pqrs";
         m['8']="tuv";
          m['9']="wxyz";
        solve(digits,0,temp,ans,m);
        return ans;
    }
};