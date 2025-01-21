//Logic is there in the image, check it out.
//Basically too unset the rightmost set bit, all we have to do it do an AND operation on N & N-1.

class Solution{
    public:
        int unsetRightmostBit(int num){
            return (num&(num-1));
        }
};