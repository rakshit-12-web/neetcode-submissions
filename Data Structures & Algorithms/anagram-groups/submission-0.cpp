class Solution {
public:
int check(string s,string t){
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>str;
        vector<int>visited(strs.size(),-1);
        for(int i=0;i<strs.size();i++){
            vector<string>s;
            if(visited[i]==-1){
            s.push_back(strs[i]);
            for(int j=i+1;j<strs.size();j++){
            if(check(strs[i],strs[j])){
            s.push_back(strs[j]);
            visited[j]=1;
            }
            }
            }
            if(!s.empty()){
            str.push_back(s);
            }
        }
        return str;
    }
};
