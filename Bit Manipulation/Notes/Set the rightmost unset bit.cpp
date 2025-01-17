class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        return (n|(n+1));
    }
};


// 1.when we add 1 to a number the lsb having zero turns into one
// 2.all the numbers after that particular bit get inverted and to get the original numbers we have to perform | operation
// i.e 1011 + 1 => 1100
// now the lsb where we had zero turned into 1 and when we perform | operation gives 1111.