class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = size(rooms);
	vector<bool>visited(n, false);
	queue<int> q;
	  q.push(0);
        visited[0]=true;
	while(!q.empty()){
		int roomIdx = q.front(); q.pop();
		for(auto adjRoom : rooms[roomIdx])
			if(!visited[adjRoom]){
                visited[adjRoom]=true;
                q.push(adjRoom);
            } 
	}

	for(auto v : visited) if(!v) return false; 
	return true;
    }
};