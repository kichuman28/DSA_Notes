class Solution {
public:


    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        set<string> stt;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(words[j].size() <= words[i].size()){
                    if(words[i].find(words[j]) != string::npos){
                        stt.insert(words[j]);
                    }
                }
            }
        }

        for(auto it: stt){
            ans.push_back(it);
        }
        
        return ans;
    }
};

//Brute Force
//A string can be a subtring of another string if it's size if less than or equal to the parent string.
//So here I can use two for loops and then go through each string in the array.
//Then in the inner loop I can first check if it's size is less than or equal to the string in outer loop.
//Then I check if each letter of the word in j is there in i. If yes then I add it to a vector.
//Finally I return it. 
//TC = O(N^2).

//Optimal Method
//KMP Algorithm, check neetcode's video as well
//https://youtu.be/7K2BjgjCFDo?si=HxmyjIL-tQuVtsuj