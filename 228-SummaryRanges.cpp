/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

//按照题意解
/*
C++ int与string的转化

int转化为string
~~~~
使用itoa   char *itoa( int value, char *string,int radix)
使用sprintf  int sprintf( char *buffer, const char *format, [ argument] … );
使用stringstream 
  int aa = 30;
  stringstream ss;
  ss<<aa; 
  string s1 = ss.str();
  cout<<s1<<endl; // 30

  string s2;
  ss>>s2;
  cout<<s2<<endl; // 30

string转化为int
~~~~
使用strtol（string to long）  
使用sscanf
使用stringstream
string s = "17";

stringstream ss;
ss<<s;

 int i;
 ss>>i;
 cout<<i<<endl; // 17
*/
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		if (nums.size() == 0)
			return res;
		if (nums.size() == 1) {
			stringstream ss;
			string s;
			ss << nums[0];
			ss >> s;
			res.push_back(s);
			return res;
		}

		int begin = nums[0], end = nums[0];
		
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == end || nums[i] == end + 1) {
				end = nums[i];
			} else {
				res.push_back(format(begin, end));
				begin = end = nums[i];
			}
		}
		res.push_back(format(begin, end));
		
		return res;
	}
private:
	//格式化函数
	string format(int begin, int end) {
		char buffer[32];
		if (begin == end) {
			sprintf(buffer, "%d", begin);
		} else {
			sprintf(buffer, "%d->%d", begin, end);
		}

		return string(buffer);
	}
};
