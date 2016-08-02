//Add Digits 加数字

/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
Hint:
	A naive implementation of the above process is trivial. Could you come up with other methods?
	What are all the possible results?
	How do they occur, periodically or randomly?
	You may find this Wikipedia article useful.
*/
/*道题让我们求数根，所谓树根，就是将大于10的数的各个位上的数字相加，若结果还大于10的话，则继续相加，直到数字小于10为止。
那么根据这个性质，我们可以写出一个解法如下： */
class Solution {
public:
	int addDigits(int num) {
		while (num / 10 > 0) {
			int sum = 0;
			while (num > 0) {
				sum += num % 10;
				num /= 10;	
			}	
			num = sum;
		}				            }
		return num;
	}
};

//法二：找数学规律

/*但是这个解法在出题人看来又trivial又naive，需要想点高逼格的解法，一行搞定碉堡了，那么我们先来观察1到20的所有的树根：
1     1
2     2
3     3
4     4
5     5
6     6
7     7
8     8    
9     9    
10    1
11    2
12    3    
13    4
14    5
15    6
16    7
17    8
18    9
19    1
20    2
根据上面的列举，我们可以得出规律，每9个一循环，所有大于9的数的树根都是对9取余，那么对于等于9的数对9取余就是0了，为了得到其
本身，而且同样也要对大于9的数适用，我们就用(n-1)%9+1这个表达式来包括所有的情况，所以解法如下：*/

class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;	
	}
};
