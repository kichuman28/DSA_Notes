class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> ban;
        for(int i = 0; i < banned.size(); i++){
            if(banned[i] <= n) ban.insert(banned[i]);
        }

        int sum = 0;
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(ban.find(i) == ban.end()){
                sum += i;
                if(sum <= maxSum){
                    count++;
                }else{
                    break;
                }
            }
        }

        return count;
    }
};

//Approach
//Step 1: Create a hash array which keeps track of the banned integers. Then I traverse through the hashmap and if there is
//any integer whose value is 0, then it means those the numbers which are not banned. 
//Step 2: Now store those numbers in an array. Then find the sum individually until the sum exceeds the maxSum. We also
//keep a track of it using a count variable. The moment it breaks you return the count.