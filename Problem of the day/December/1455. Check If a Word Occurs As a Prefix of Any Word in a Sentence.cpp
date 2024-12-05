class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        //Step 1: I need to add the individual words in sentence to an array
        vector<string> arr;
        string str = "";
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                arr.push_back(str);
                str = "";
                continue;
            }
            str += sentence[i];
        }
        arr.push_back(str);

        int n = arr.size();
        int m = searchWord.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            if(arr[i].size() >= m){
                for(int j = 0; j < m; j++){
                    if(searchWord[j] == arr[i][j]){
                        count++;
                    }
                }                
            }
            if(count == m) return i + 1;
        }


        return -1;
    }
};