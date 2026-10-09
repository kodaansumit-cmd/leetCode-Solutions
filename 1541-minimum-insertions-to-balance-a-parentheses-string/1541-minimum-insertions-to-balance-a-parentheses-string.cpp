class Solution {
public:
    int minInsertions(string s) {
        
        int need=0;
        int ans=0;

        for (char c:s){
        if(c=='('){
            need+=2;
            if(
             need % 2==1){
                ans++;
                need--;
             }
        }
 else{
                    need--;

                     if(need<0){
                    ans++;
                    need=1;
                }
                }
            }
       return ans+need;
    }
};