class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element1;
        int element2;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < n; i++){
            if(count1 == 0 && nums[i] != element2){
                element1 = nums[i];
                count1 = 1;
            }else if(count2 == 0 && nums[i] != element1){ //the and condition is an edge case incase the new element 
                element2 = nums[i];                       //is equal to the first element or vice versa. Both the elements
                count2 = 1;                               //should not be the same.
            }else if(element1 == nums[i]){
                count1++;
            }else if(element2 == nums[i]){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        //Why we are not returning like {element1, element2}? At max there can be 2 elements. Not necessary that there must
        //always be 2 elements. So we check the count again, check if it is greater than n/3, and then add it to a 
        //vector and return it.
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == element1)  count1++;
            if(nums[i] == element2)  count2++;
        }
        vector<int> temp;

        int mini = n / 3;
        if (count1 > mini) temp.push_back(element1);
        if (count2 > mini) temp.push_back(element2);
        return temp;
    }
};

//Brute Force:
//Same approach as the majority element 1. Here if the freq is greater than n/3 you add it to a vector & return it.

//Optimal Method:
//One thing you should know before attempting this is that there can be only a maximum of 2 integers as the answer.
//Suppose n = 8 and you need elements that repeat more than 8/3 times = 2.6 ~ 3 times. So if more than 2 elements appear
//than 8/3 times then it means there are 3+3+3 = 9 elements, which is impossible as n = 8. So only 2 elements can exist
//which occurs more than n/3 times.
//This is the same concept for Majority Element 1 as well.
//Now here we have to replicate the same problem using Moore's voting algorithm, except cover some edge cases.
//In the first problem, we used the count approach, same here except do it for the 2 elements simultaneosly. 