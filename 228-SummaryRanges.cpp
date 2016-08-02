//Summary Ranges 总结区间

/*Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].*/

/*C++ int与string的转化:
~~~~~~~~~~~~~~~
int转化为string:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1.使用itoa   char *itoa( int value, char *string,int radix)
2.使用sprintf
3.使用stringstream 
  int aa = 30;
  stringstream ss;
  ss<<aa; 
  string s1 = ss.str();
  cout<<s1<<endl; // 30

  string s2;
  ss>>s2;
  cout<<s2<<endl; // 30
4.to_string(int);
~~~~~~~~~~~~~~~
string转化为int:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1.使用strtol（string to long）  
2.使用stringstream
string s = "17";

stringstream ss;
ss<<s;

 int i;
 ss>>i;
 cout<<i<<endl; // 17

3.atoi(string.c_str());
  atoll(string.c_str());*/

/*这道题给定我们一个有序数组，让我们总结区间，具体来说就是让我们找出连续的序列，然后首尾两个数字之间用个“->"来连接，那么我
只需遍历一遍数组即可，每次检查下一个数是不是递增的，如果是，则继续往下遍历，如果不是了，我们还要判断此时是一个数还是一个序
列，一个数直接存入结果，序列的话要存入首尾数字和箭头“->"。我们需要两个变量i和j，其中i是连续序列起始数字的位置，j是连续数
列的长度，当j为1时，说明只有一个数字，若大于1，则是一个连续序列，代码如下： */

//to_string()函数
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int i = 0, n = nums.size();
		
		while (i < n) {
			int j = 1;
			while (i + j < n && nums[i + j] - nums[i] == j) ++j;
			res.push_back(j <= 1 ? to_string(nums[i]) : 
					to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
			i += j;
		}
		
		return res;
	}
}

