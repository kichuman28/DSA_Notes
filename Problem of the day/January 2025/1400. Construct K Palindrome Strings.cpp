class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        //Base case: k should be less than or equal to n. I can only divide s into k pal strings, not more.
        if(k > n) return false;

        //Checking is count of char with odd freq < k
        map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }

        int count = 0;
        for(auto it: mpp){
            if(it.second % 2 != 0) count++;
            if(count > k) return false;
        }

        return true;

    }
};


//INTUITION
// Now say any character has even count,
// example : aaaa (It's always a palindrome in itself), Even if I divide into 2, it will be always a palindrome(aa,aa 2 palindromes)
// even if I divide into 4 , it will remain a palindrome(Each character a palindrome)

// In general an even count character, can help in forming any number of palindromes from 1 to its length
// Example : aaaa

// 4 palindromes(a,a,a,a)
// 3 palindromes(a,aaa)
// 2 palindromes(aa,aa)
// 1 palindrome(aaaa)
// That's from where we think of base case as
// if k>s.length() cant even form more palindromes than length return false
// if k==length return true

//Now for characters with odd counts. take string "aabbcde" for example, k = 2
//Notice that I need to use ALL CHARACTERS IN THE STRING TO MAKE K PALINDROMIC STRINGS.
//Since there is a character with an odd count, possible combinations such that it fits inside k substrings is
//'abcba' + 'd' + 'e'. But since k = 2, I only need 2 strings. But I cannot make it into 2 because I the number of characters with odd freq is greater than k. I cannot fit in one more odd freq char into abcba to make it palindrome.
//Athayath for each char with odd freq, I will need to make it individual in order for it to count as a substring.
//I mean this would've been fine if k was 3. But it's not. So from this we can deduce that if the count of char with odd
//freq is greater than k, we cannot make k palindromic substrings. It should always be less than k.
