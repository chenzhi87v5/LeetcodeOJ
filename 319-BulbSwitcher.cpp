//Bulb Switcher 灯泡开关                 Ignore
/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the 
third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you 
toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:
Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/

/*
这道题给了我们n个灯泡，第一次打开所有的灯泡，第二次每两个更改灯泡的状态，第三次每三个更改灯泡的状态，以此类推，第n次每n个
更改灯泡的状态。让我们求n次后，所有亮的灯泡的个数。此题是CareerCup 6.6 Toggle Lockers 切换锁的状态。

那么我们来看这道题吧，还是先枚举个小例子来分析下，比如只有5个灯泡的情况，'X'表示亮，‘√’表示灭，如下所示：

初始状态：    X    X    X    X    X

第一次：      √   √   √   √   √

第二次：      √   X    √   X    √

第三次：      √   X    X    X    √

第四次：      √   X    X    √   √

第五次：      √   X    X    √   X

那么最后我们发现五次遍历后，只有1号和4号锁是亮的，而且很巧的是它们都是平方数，是巧合吗，还是其中有什么玄机。我们仔细想想，
对于第n个灯泡，只有当次数是n的因子的之后，才能改变灯泡的状态，即n能被当前次数整除，比如当n为36时，它的因数有(1,36), (2,18),
(3,12), (4,9), (6,6), 可以看到前四个括号里成对出现的因数各不相同，括号中前面的数改变了灯泡状态，后面的数又变回去了，等于锁
的状态没有发生变化，只有最后那个(6,6)，在次数6的时候改变了一次状态，没有对应其它的状态能将其变回去了，所以锁就一直是打开状
态的。所以所有平方数都有这么一个相等的因数对，即所有平方数的灯泡都将会是打开的状态。

那么问题就简化为了求1到n之间完全平方数的个数，我们可以用force brute来比较从1开始的完全平方数和n的大小，参见代码如下：

还有一种方法更简单，我们直接对n开方，在C++里的sqrt函数返回的是一个整型数，这个整型数的平方最接近于n，即为n包含的所有完全平
方数的个数，参见代码如下：
*/
class Solution {
public:
	int bulbSwitch(int n) {
		return sqrt(n);
	}
};
