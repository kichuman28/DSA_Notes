class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> stt(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        string start = beginWord;
        stt.erase(start);
        q.push({start, 1});

        while(!q.empty()){
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(str == endWord) return steps;
            //TC = log N(for the stt.find(function)) * str.size() * 26 (alphabets) * N (the number of strings in the list) in worst case, visits ALLTHE NODES.
            //SC = O(N) for the set + O(N) for the queue 
            for(int i = 0; i < str.size(); i++){
                char original = str[i]; //this step is important. from "hot", not "dot".
                for(char ch = 'a'; ch <= 'z'; ch++){
                    str[i] = ch;
                    if(stt.find(str) != stt.end()){
                        stt.erase(str);
                        q.push({str, steps + 1});
                    }
                }
                str[i] = original;
            }
        }

        return 0;
    }
};


// Approach
// What does the problem state? Basically you have to convert the start word to the end word with the minimum no of tranformations as possible. Also each transformation must be there in the wordList or else you can't use that word. Now if you can't transform a word because it doesn't exist in wordList you return 0 as the no. of transformations. 

// Logic
// So you use BFS traversal for each letter in the word. For example, in "hot", you try to replace 'h' with all the alphabets from a to z and inbetween also check if it is present in the wordList. Here you find "dot" matches that condition. So it's a yes, you increment the no. of transformations by 1 and move on to 'o' int "hot", not from "dot". It's more recursive. Watch the video again for a solid understanding. You repeat the same until everything in "hot" is covered. Now you move to "dot" and repeat the process. Along the way if the word you get from the combinations is the end word, you return the number of steps. If you don't get it that means the end word isnt there in the list. You return 0.

// Implementation.
//(1) Here instead of using a visited array, we use a set for two reasons. This is to reduce the time complexity while searching for the word using set.find() function. We can do it linearly but it uses more TC. Hence a set.
//(2) Next for the queue we need two parameters. One of them is a string, which is the word. The second one is the number of steps. 
//(3) beginWord is like the start node. Remove it from the set like marking the firt node as visited in the vis array.
//(4) The next step is to push the first node into the array with the number of steps as 1.
//(5) Now we traverse the queue until it is empty. Take the front node. Take out the details. Pop it out
//(6) From the string we go through each letter, check all the combos from a to z, check if it is in the set, if yes then we remove it from the array and push that word into the queue and increment the number of steps by one. Also we need to convert the letter back to it's original letter because we're then going from "hot" only, not "dot".
//(7) Along the way if the string is somehow equal to the end word, then we return the number of steps.
//(8) If no string is equal to the end word then we return 0.


//TC = O(N x M)