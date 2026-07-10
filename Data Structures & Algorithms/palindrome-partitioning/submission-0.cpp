class Solution {
public:
 int isValid(int idx,int i,string&s){
    int st=idx;
    int e=i;
    while(st<=e){
        if(s[st]!=s[e]){
            return false;
        }
        st++;
        e--;
    }
    return true;
 }
void solve(int idx,   vector<string>&temp,vector<vector<string>>&ans,string&s){
    if(idx==s.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=idx;i<s.size();i++){
        if(isValid(idx,i,s)){
            temp.push_back(s.substr(idx,i-idx+1));
            solve(i+1,temp,ans,s);
            temp.pop_back();
                    }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
         vector<string>temp;
         solve(0,temp,ans,s);
        return ans;
    }
};