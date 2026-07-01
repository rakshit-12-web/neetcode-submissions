class Solution {
public:
vector<int>l(vector<int>& h){
    vector<int>ans(h.size());
    stack<int>st;
    for(int i=0;i<h.size();i++){
        while(!st.empty()&&h[i]<=h[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>r(vector<int>& h){
    vector<int>ans(h.size());
    stack<int>st;
    for(int i=h.size()-1;i>=0;i--){
        while(!st.empty()&&h[i]<=h[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=h.size();
        }
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=l(heights);
        vector<int>right=r(heights);
int maxi=0;
        for(int i=0;i<heights.size();i++){
            int area=heights[i]*(right[i]-left[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
