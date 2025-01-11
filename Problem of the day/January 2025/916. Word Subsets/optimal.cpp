class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<string> ans;

        map<char, int> mpp2;
        for(int i = 0; i < m; i++){
            string str = words2[i];
            map<char, int> temp;
            for(auto it: str){
                temp[it]++;
            }

            for(auto it: temp){
                mpp2[it.first] = max(mpp2[it.first],temp[it.first]);
            }
        }


        for(int i = 0; i < n; i++){
            map<char, int> mpp1;
            string str = words1[i];
            for(auto it: str){
                mpp1[it]++;
            }

            int flag = 0;
            for(auto it: mpp2){
                if(mpp2[it.first] <= mpp1[it.first]){

                }else{
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                ans.push_back(str);
            }
        }
        return ans;
    }
};

//OPTIMAL
//Since I am getting  a TLE because I am making a hashmap for everywords in words2 n times, what I can do is create a hash
//map which merges all characters(finds max occurence) in words2. Then I can check whether each of it's value is less than or equal to the words
//in words1.
