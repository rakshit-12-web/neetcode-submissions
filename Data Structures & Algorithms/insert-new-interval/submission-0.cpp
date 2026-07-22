class Solution {
public:
    vector<int> mergeTwo(vector<int>& one, vector<int>& two) {

        int j1 = one[0];
        int j2 = one[1];
        int k1 = two[0];
        int k2 = two[1];

        // no overlap
        if (j2 < k1) {
            return {-1, -1};
        }

        // overlap
        return {min(j1, k1), max(j2, k2)};
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      intervals.push_back({newInterval[0],newInterval[1]});
        sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;

        vector<int> curr = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {

            vector<int> temp = mergeTwo(curr, intervals[i]);

            if(temp[0] == -1) {     // no overlap
                ans.push_back(curr);
                curr = intervals[i];
            }
            else {                  // overlap
                curr = temp;
            }
        }

        ans.push_back(curr);

        return ans;
    
    }
};