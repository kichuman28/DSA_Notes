class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());       //for testcase[[1,4],[0,4]]
        for(int i = 0; i < n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back(),intervals[i][1]);    //for testcase [[1,4],[2,3]]
            }
        }

        return ans;
    }  
};

//Brute Force Approach:
//I traverse through the array. Then I check if arr[i].second >= arr[i+1].first, 
//Then I create a new interval called [arr[i].first, arr[i+1].second] and push it into the answer.
//Except here when I add a new merged interval, for the future checkings I need the latest merged interval.
//So for the first time you add a merged interval, you check if 'ans' is empty or not. If it is not empty
//then you take ans.back() and then you make do with it.