//Question here is to toggle a bit. Like if it is 0 then toggle it to 1 and vice versa.
//We can do this using the XOR operator.
//Bring 1 towards the bit which you want to toggle via left shift or right shift and then do the XOR operator.

class Solution{
    public:
    int toggleBit(int num, int k){
        return num^(1<<k);
    }
};