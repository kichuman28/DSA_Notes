class Solution {
public:

    bool validate(string str){
        int n = str.size();

        map<char, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[str[i]]++;
        }

        for(auto it: mpp){
            if(it.second != 1) return false;
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int maxi = 0;
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = i; j < n; j++){
                str += s[j];
                if(validate(str)){
                    int len = str.size();
                    maxi = max(maxi, len);
                }
            }
        }
        return maxi;
    }
};


//BRUTE FORCE
//TC = O(N^2)