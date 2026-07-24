class Solution {
public:
    bool isHappy(int n) {
set<int>s;
while(n!=1){
  int sum=0;
      while(n!=0){
        int num=n%10;
        sum=sum+num*num;
        n=n/10;
      }
      if(s.count(sum)){
        return false;
      }
      n=sum;
      s.insert(n);
}
  return true; 
    }
};
