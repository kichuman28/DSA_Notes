class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0;
        int j = 0;
        while(i < n || j < n){
            while(start[i] == '_' && i < n) i++;
            while(target[j] == '_' && j < n) j++;
            if(i > n || j > n) return false;   //This is for test case start = "____", target = "L_RR"

            if(start[i] != target[j]) return false; //for this test case (start = "R_L_", target = "__LR")
            else if(start[i] == 'L' && i < j) return false;
            else if(start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }

        return true;
    }
};

//Iterate both start and end using i & j as pointers until either i reaches the end or j reaches the end
//Iterate i in start until you find a letter
//Iterate j in end until you find a letter
//If start[i] != end[j] return false
//If start[i] == "L" && i < j means the letter "L" has to move right which is impossible, so you return false
//if start[j] == "R" && i > j means the letter "R" has to move left which is impossible, so you return false

//If you complete the entire while loop, all thing are good, return true.