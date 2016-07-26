//Bulls and Cows 公母牛游戏
/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess 
what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess 
match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number 
but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive 
the secret number.

For example:
Secret number:  "1807"
Friend's guess: "7810"

Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to 
indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:
Secret number:  "1123"
Friend's guess: "0111"

In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

//使用map 细节实现注意
/*
这道题提出了一个叫公牛母牛的游戏，其实就是之前文曲星上有的猜数字的游戏，有一个四位数字，你猜一个结果，然后根据你猜的结果和
真实结果做对比，提示有多少个数字和位置都正确的叫做bulls，还提示有多少数字正确但位置不对的叫做cows，根据这些信息来引导我们继
续猜测正确的数字。这道题并没有让我们实现整个游戏，而只用实现一次比较即可。给出两个字符串，让我们找出分别几个bulls和cows。这
题需要用哈希表，来建立数字和其出现次数的映射。 
*/
class Solution {
public:
	string getHint(string secret, string guess) {
		int cntA = 0, cntB = 0;           
		unordered_map<char, int> hash;           //记录char出现的次数
		vector<bool> tag(secret.size(), false);  //判断位置匹配状态
		
		for (auto a : secret) {
			++hash[a];
		}

		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i]) {
				++cntA;
				--hash[secret[i]];
				tag[i] = true;
			}
		}

		for (int i = 0; i < guess.size(); i++) {
			if (!tag[i] && hash[guess[i]] > 0) {
				++cntB;
				--hash[guess[i]];
			}
		}

		return to_string(cntA) + "A" + to_string(cntB) + "B";   //int 转 string
	}
};
