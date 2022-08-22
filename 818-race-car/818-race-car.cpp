class Solution {
public:
    int racecar(int target) {
      queue<pair<pair<int,int>,int>> q;       // {pos, speed, moves}
			q.push({{0,1},0});

			while(!q.empty()){
				pair<pair<int,int>,int> cur= q.front();
				q.pop();

				int new_pos = cur.first.first;
				int new_speed = cur.first.second;
				int moves = cur.second;

				if(new_pos==target)return moves;

				 if (abs(new_pos)> 2 * target) continue;

				q.push({{new_pos+new_speed,new_speed*2},moves+1});     
                
                 // REVERSE ONLY WHEN GOING AWAY FROM TARGET
				 // BY CHEAKING THE NEXT POSITION AND CURR SPEED DIRECTION
					if(new_pos+new_speed>target and new_speed>0 || new_pos+new_speed<target and new_speed<0){
						if(new_speed>0){
						q.push({{new_pos,-1},moves+1});
					}else{
						q.push({{new_pos,1},moves+1});
					}
				}
			}
			return -1;  

    }
};