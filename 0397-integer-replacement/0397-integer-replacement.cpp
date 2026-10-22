class Solution {
public:
    int integerReplacement(int n) {
        long long x=n;
        int count=0;
       while(x!=1){
        if(x%2==0){
            x=x/2;
        }
        else if(x==3||x%4==1){
            x=x-1;
        }
        else{
            x=x+1;
        }
      count++;
       }
       return count;
    }
};