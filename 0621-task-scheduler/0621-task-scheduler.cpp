class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;

        
        for(char ch : tasks) {
            mp[ch]++;
        }

        
        priority_queue<int> pq;

        for(auto it : mp) {
            pq.push(it.second);
        }

        int time = 0;

        while(!pq.empty()) {

            vector<int> temp;
            int cycle = n + 1;

            
            while(cycle > 0 && !pq.empty()) {

                int freq = pq.top();
                pq.pop();

                freq--;

                if(freq > 0) {
                    temp.push_back(freq);
                }

                time++;
                cycle--;
            }

            
            for(int x : temp) {
                pq.push(x);
            }

            
            if(!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};