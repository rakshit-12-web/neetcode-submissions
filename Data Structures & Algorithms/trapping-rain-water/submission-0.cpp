class Solution {
public:
vector<int>left(vector<int>& height,int n){
    vector<int>l(n);
    l[0]=height[0];
    for(int i=1;i<n;i++){
         l[i]=max(l[i-1],height[i]);
    }
    return l;
}
vector<int>right(vector<int>& height,int n){
    vector<int>l(n);
    l[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
         l[i]=max(l[i+1],height[i]);
    }
    return l;
}
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax=left(height,n);
        vector<int>rightmax=right(height,n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi+=min(leftmax[i],rightmax[i])-height[i];
        }
        return maxi;
    }
};