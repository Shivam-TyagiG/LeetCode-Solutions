class Solution {
private:
    using Manager = int;
    using Time = int;
    pair<Time, Manager> moveUnderHead(vector<int>& manager, vector<int>& informTime, int v) {
        if (manager[manager[v]] != -1) { 
            // we are not under Head manager
            auto timeManager = moveUnderHead(manager, informTime, manager[v]);  // compress path
            informTime[v] += timeManager.first;
            manager[v] = timeManager.second;
        }
        return {informTime[v], manager[v]};
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int result = 0;
        for (int i=0; i<n; ++i) {
            if (i==headID) continue;
            auto a = moveUnderHead(manager, informTime, i);
            result = max(result, a.first);
        }
        
        return result + informTime[headID];
    }
};