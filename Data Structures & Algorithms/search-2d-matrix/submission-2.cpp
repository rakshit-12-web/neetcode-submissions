class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row=m.size();
        int col=m[0].size();
        int s=0;
        int e=(row*col)-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int no=m[mid/col][mid%col];
            if(target==no){
                return true;
            }
            else if(target>no){
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
return false;   
        
    }
};
