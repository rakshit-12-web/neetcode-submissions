class Solution {
public:
bool check(string&s1,string&s2,int j,int i){
    string temp=s2.substr(i,j-i+1);
  sort(temp.begin(),temp.end());
  if(s1==temp){
    return true;
  }
  return false;

}
    bool checkInclusion(string s1, string s2) {
        int i=0;
        int j=0;
        int k=s1.size();
         sort(s1.begin(),s1.end());
        while(j<s2.size()){
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(check(s1,s2,j,i)){
                    return true;
                };
                i++;
                j++;
            }
        }
        return false;
    }
};
