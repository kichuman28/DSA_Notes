class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.size();

        int count = 0;
        for(int i = 0; i < n; i++){
            string str = words[i];
            int flag = 0;
            for(int j = 0; j < m; j++){
                if(pref[j] == str[j]){
                    
                }else{
                    flag = 1;
                    break;
                }
            }
            if(!flag) count++;
        }

        return count;
    }
};