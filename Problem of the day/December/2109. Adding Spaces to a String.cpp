class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int i = 0;
        string str = "";
        int j = 0;
        for(j = 0; j < n; j++){
            if(j == spaces[i]){
                str += " ";
                if(i == spaces.size() - 1) break;
                i++;
            }
            str += s[j];
        }

        for(int k = j; k < n; k++){
            str += s[k];
        }

        return str;
    }
};