// bfs
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
using PSI = pair<string, int>;
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n = friends.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(id);
        vis[id] = true;
        for(int i = 1; i <= level; i++){
            int qs = q.size();
            for(int j = 0; j < qs; j++){
                int u = q.front(); q.pop();
                for(int k = 0; k < friends[u].size(); k++){
                    if(vis[friends[u][k]]) continue;
                    q.push(friends[u][k]);
                    vis[friends[u][k]] = true;
                }
            }
        }
        
        unordered_map<string, int> freq;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const string& watched: watchedVideos[u]) {
                ++freq[watched];
            }
        }
        
        vector<PSI> videos(freq.begin(), freq.end());
        sort(videos.begin(), videos.end(), [](const PSI& p, const PSI& q) {
            return p.second < q.second || (p.second == q.second && p.first < q.first);
        });
        
        vector<string> ans;
        for (const PSI& video: videos) {
            ans.push_back(video.first);
        }
        return ans;
    }
};