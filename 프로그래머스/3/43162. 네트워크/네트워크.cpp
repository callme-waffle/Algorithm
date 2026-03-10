// #include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<int> pcg = vector<int>(n);
    for (int gid = 1; gid <= n; gid++) {
        queue<int> q; vector<bool> visited = vector<bool>(n, false);
        // cout << "GID: " << gid << endl;
        
        int id = gid-1;
        visited[id] = true;
        if (pcg[id] != 0) continue;
        
        pcg[id] = gid;
        for (int cid = 0; cid < n; cid++) if (computers[id][cid] && cid != id)
            q.push(cid);
        
        while(!q.empty()) {
            id = q.front(); q.pop();
            if (visited[id]) continue;
            
            // cout << "ㄴ visit: " << id << endl;
            
            visited[id] = true;
            if (pcg[id] != 0) pcg[id] = gid;
            
            for (int cid = 0; cid < n; cid++) 
                if (computers[id][cid] && !visited[cid])
                    q.push(cid);
        }
    }
    
    // for (int x = 0; x < pcg.size(); x++) {
        // cout << "x: " << x << " | g: " << pcg[x] << endl;
    // }
    return set<int>(pcg.begin(), pcg.end()).size();
}