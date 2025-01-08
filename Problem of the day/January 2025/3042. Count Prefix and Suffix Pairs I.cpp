class Solution {
public:

    bool valid(string str1, string str2){
        int n = str2.size();
        int m = str1.size();

        for(int i = 0; i < m; i++){
            if(str1[i] != str2[i]){
                return false;
            }
        }

        int rev = n-1;
        for(int i = m-1;  i >= 0; i--){
            if(str1[i] != str2[rev]){
                return false;
            }
            rev--;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(valid(words[i], words[j])){
                    count++;
                }
            }
        }

        return count;
    }
};


//BRUTE FORCE
//Use two for loops
//Go through each pair, check if words[i].size() < words[j].size()
//Then check for each character from front and behind simulataneously using i & n-i-1.
//If true increment count
//return count.

//OPTIMAL 
//Learn about KMP algorithm