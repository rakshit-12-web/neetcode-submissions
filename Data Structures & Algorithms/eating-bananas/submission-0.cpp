class Solution {
public:
 bool check(int k, vector<int>& piles, int h) {
    long long hours = 0;

    for (int bananas : piles) {
        hours += (bananas + k - 1) / k;   // ceil(bananas/k)
    }

    return hours <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int ans=0;
        int e=*max_element(piles.begin(),piles.end());
        while(s<=e){
       int mid=s+(e-s)/2;
       if(check(mid,piles,h)){
        ans=mid;
        e=mid-1;
       }
  else{
    s=mid+1;
  }
        }
return ans;     
    }
};
