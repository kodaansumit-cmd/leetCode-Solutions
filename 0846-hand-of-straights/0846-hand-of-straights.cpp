class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        map<int,int> mp;

        
        for(int x : hand)
            mp[x]++;

        while(!mp.empty())
        {
            int start = mp.begin()->first; 

            for(int i = 0; i < groupSize; i++)
            {
                int curr = start + i;

                
                if(mp.find(curr) == mp.end())
                    return false;

                mp[curr]--;

                if(mp[curr] == 0)
                    mp.erase(curr);
            }
        }

        return true;
    }
};