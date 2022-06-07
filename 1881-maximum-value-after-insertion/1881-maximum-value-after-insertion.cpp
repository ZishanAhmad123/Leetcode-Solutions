class Solution
{
    public:
        string maxValue(string n, int x)
        { 
            bool f=false;
            
            int len=n.size();
		string res="";
		char X = (char)(x+48);
		if (n[0] == '-') {
			res += '-';
			for (int i = 1; i < len; i++) {
				if (n[i] <= X) {
					res += n[i];
				}
				else if ((n[i] > X)) {
					res += X;
					res += n.substr(i, len - i + 1);
					break;
                    f=true;
				}
			}
			if (res.size() == len) { res += X; }
		}
		else {
			for (int i = 0; i < len; i++) {
				if (n[i] >= X) {
					res += n[i];
				}
				else if((n[i] < X)){
					res += X;
					res += n.substr(i, len - i + 1);
					break;
                    f=true;
				}
			}
			if (res.size() == len) { res += X; }
		}
		return res;
            }
        };