class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<string> ans;

        for(int i = 0; i < n; i++){
            string str1 = words1[i];
            map<int, int> mpp1;
            for(int j = 0; j < str1.size(); j++){
                mpp1[str1[j]]++;
            }

            //loop for words2
            int flag = 0;
            for(int k = 0; k < m; k++){
                map<int, int> mpp2;
                string str2 = words2[k];
                for(int l = 0; l < str2.size(); l++){
                    mpp2[str2[l]]++;
                }

                flag = 0;
                for(auto it: mpp2){
                    if(mpp2[it.first] <= mpp1[it.first]){

                    }else{
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag){
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};