class Solution{
    public:
    bool stoneGameIX(vector<int>&stones){
        int count[3]={0};
        for(int x:stones){
            count[x%3]++;

        }
        int a=count[1];
        int b=count[2];
        int zero=count[0];
        
        if(zero%2==0){
            return a>0 && b>0;
}
else{
    return abs(a-b)>2;
}
    }
};