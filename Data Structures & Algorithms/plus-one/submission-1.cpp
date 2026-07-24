class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      long long val=0;
        for(int i=0;i<digits.size();i++){
          val=val*10+digits[i];
        }
        
        val=val+1;
        vector<int>ans;
        while(val!=0){
          int num=val%10;
          ans.push_back(num);
          val=val/10;
                }
                 reverse(ans.begin(),ans.end());
                 return ans;
    }
};
