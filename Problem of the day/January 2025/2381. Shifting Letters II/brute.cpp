class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int m = s.size();

        for(auto it: shifts){
            int start = it[0];
            int end = it[1];
            int direction = it[2];

            for(int i = start; i <= end; i++){
                if(direction){
                    if(s[i] == 'z'){
                        s[i] = 'a';
                    }else{
                        s[i] = char(s[i] + 1);
                    }
                }else{
                    if(s[i] == 'a'){
                        s[i] = 'z';
                    }else{
                        s[i] = char(s[i] - 1);
                    }
                }
            }
        }
        return s;
    }
};


//Brute Force
//So all I need to do is shift each character in the range shifts[0] to shifts[1] by one, 
//Forward direction if shifts[2] = 1 
//Reverse direction if shifts[2] = 0
//TC = O(N^2)