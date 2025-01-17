#include<bits/stdc++.h>
using namespace std;


string convertToBinary(int num){
    //I need to divide it by 2 until it reaches 1 and add up the remainders from bottom
    string ans = "";
    while(num != 1){
        int rem = num % 2;
        ans += char('0' + rem); // Convert remainder (0 or 1) to character
        num = num / 2;
    }
    ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    //I have to write a function to convert a number to binary;
    cout << convertToBinary(4);
}