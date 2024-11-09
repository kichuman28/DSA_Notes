class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> stt(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord); //This is the first word we're pushing into here
        int level = 0;
        q.push({beginWord});

        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();

            if(vec.size() > level){ //Here if new level change happens, that means all possible combinations with the words in usedOnLevel is achieved so we remove those words form the unordered set.
                level++;
                for(auto it : usedOnLevel){
                    stt.erase(it);
                }
                usedOnLevel.clear(); //For imprroving TC, we don't need to check for already removed words. So just clearing it out to make it better.
            }

            string word = vec.back();

            if(word == endWord){
                if(ans.size() == 0){//If we reach a combo where the back() is the endWord then it means we have reached our target. Next we check if it's the first word in the ans array or not. If yes then we add it to ans. The reason for this check is written in the statement below
                    ans.push_back(vec);
                }else if(vec.size() == ans[0].size()){//Sometimes there can be combos with endWord with size greater than the ones we got before. We don't need that. Hence this check. 
                    ans.push_back(vec); 
                }
            }

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(stt.find(word) != stt.end()){ //word = "lot"
                        vec.push_back(word);  //We got[hit, hot, lot]. 
                        q.push(vec);//queue consists of [{hit, hot, lot}].
                        usedOnLevel.push_back(word); //add 'lot' to usedOnLevel to mark in the set later on.
                        vec.pop_back(); //[hit, hot]. We did this so we can add [hit, hot, dot] which we'll get in the next iteration. If we don't pop back then it'll go like [hit, hot, lot, dot]  which is wrong. We'll lose that particular combination. 
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};


//What does the question want us to do? Basically you need to return an array of array of all the combinations you took to transform from the startWord to the endWord by storing it in an array. 

// Logic : It's almost the same code as Word Ladder 1 with minor differences. 
//(1) Here instead of storing the string and no. of steps in the queue, you need to store the vector of strings in the queue. 
//(2) Instead of the concept of visited array, you use an undordered set consisting of the words from the wordList. The you push the start word into the queue inside an array. You also need another vector called usedOnLevel to store all the words which you used so that you can remove them from the set later on. This happens after all the combinations in a level is found. For knowing which level it is you need a varianble called level=0. You also need a vector of vector 'ans' to store all the combos. 
//(3) Next you start traversing the queue until it is empty. First thing you do is take the front element, i.e the first vector and then pop it out.
//(4) Then you check if it is a new level by checking it's size with the 'level' variable. If it is more then you delete all the words in the set which is there in the usedOnLevel vector.
//(5)Next you take the back element in the vector and do the same thing you did on word ladder 1. check for possibilites from a to z. If any new combos are found which exists on the wordList, then push_back it to the front() vector, then push that front() vector to the queue, then add that word to the usedOnLevel vector and then pop that same word from the front() vector to get other possibilities as well.
//(6) Keep on doing this until the end word is reached. If the end word is reached by comparing it to the word you took from the back() of the array from front() array, then add it to ans. For the other combos, check if that vector's size is the same as the first vector in ans, if yes then add it. Because you don't want bigger combinations. 
//(7) Return the ans.