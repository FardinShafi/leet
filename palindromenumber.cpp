#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x!= 0)){
            return false;
        }
        int reverse;

        while(x>reverse){
            reverse = reverse *10 + x % 10;
            x=x/10;
        }
        if(x==reverse || x==reverse/10){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(123)<<endl;
}