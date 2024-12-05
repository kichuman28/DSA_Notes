class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        //str1 = abc
        //str2 = ad

        int n = str1.size();
        int m = str2.size();

        int left = 0;
        int right = 0;

        int count = 0;
        while(left < n){
            if(str1[left] == str2[right] || (str1[left] + 1) == str2[right] || str1[left] == 'z' && str2[right] == 'a'){
                left++;
                right++;
            }else{
                left++;
            }
        }

        if(right == m) return true;
        return false;
    }
};