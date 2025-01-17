#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string str){
    int n = str.size();
    int ans = 0;
    int exp = n-1;
    for(int i = 0; i < n; i++){
        if(str[i] == '1') ans += pow(2, exp);
        exp--;
    }
    
    return ans;
}


int main(){
    //Function to convert binary to decimal
    cout << binaryToDecimal("111");
}


// Alternate way 
// #include<bits/stdc++.h>
// using namespace std;

// int binaryToDecimal(string str){
//     int n = str.size();
//     int ans = 0;
//     int exp = 1;
//     for(int i = 0; i < n; i++){
//         if(str[i] == '1') ans += exp;
//         exp = exp * 2;
//     }
    
//     return ans;
// }


// int main(){
//     //Function to convert binary to decimal
//     cout << binaryToDecimal("111");
// }