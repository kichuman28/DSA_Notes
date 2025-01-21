class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        return ((1 << k) & n);
    }
};


//Basically we are bringing that 1 to that bit which we want to change by left shifting and
//we do an AND operation. If the bit is set then we get a 1, if not we get a zero. 
//We can do by right shift logic also where we right shift that bit buy k bits, do an AND 
//operation by 1 and check the same.