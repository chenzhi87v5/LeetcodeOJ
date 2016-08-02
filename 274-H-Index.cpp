//H-Index 求H指数             Ignore
/*
    Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute 
the researcher's h-index.
   According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h 
citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had 
received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the 
remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
Hint:
	An easy approach is to sort the array first.
	What are the possible values of h-index?
	A faster approach is to use extra space.
*/
/*论文H指数

LeetCode上的题目描述并不是很清楚，详情请查看题目中的维基百科链接。
H-Index的核心计算方法如下：
	1、将某作者的所有文章的引用频次按照从大到小的位置排列
	2、从前到后，找到最后一个满足条件的位置，其条件为：
		此位置是数组的第x个，其值为y，必须满足 x >= y;
        至此，思路已经形成。即先排序，然后从前向后遍历即可。
*/
//sort(beg, end, greater<int>()); 排序
class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.size() == 0) {
			return 0;
		}

		sort(citations.begin(), citations.end(), greater<int>());   //greater<int>() 函数  精辟

		for (int i = 0; i < citations.size(); i++) {
			if (i >= citations[i]) {
				return i;
			}
		}
		return citations.size();  
	}
};
