class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &it:m){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k!=0){
        ans.push_back(pq.top().second);
        k--;
        pq.pop();
                }
        return ans;
    }
};
