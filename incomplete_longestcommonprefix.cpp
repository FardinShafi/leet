#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count=0;
        int k=0;
        int prevcount=0;
        if (strs.empty()){
            return "";
        }
        
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                string s=strs[k];
                string t=strs[i];
                if(s[0]!=t[0]){
                    return "";
                }
                else if(j!=0 && s[j-1]!=t[j-1]){
                    break;
                }
                else if(i==0 || s[j]==t[j]){
                    count=j;
                }
                
                
            }
            if(count==prevcount || count<prevcount){
                    prevcount=count;
                    k=i;
                }
            
        }
        // cout<<count+1<<endl;
        string substr = strs[0].substr(0, count+1);
        return substr;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> strs = {"caaaaa", "caaa","caaaaa"};
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}