/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
	In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
	In this case, you should ignore redundant slashes and return "/home/foo".
*/

//1-:按照题意解
//很有实际价值的项目
class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dirs; //当做栈来使用,把每次目录项依次存入

		for (auto i = path.begin(); i != path.end();) {
			i++;

			auto j = find(i, path.end(), '/');  //使用STL find 返回一个迭代器指向输入序列 第一个等于 '/' 元素
			auto dir = string(i, j); // 注意 string(i, j)以区间  i j 的字符作为dir字符串

			if (!dir.empty() && dir != ".") { // 当有连续的'///'时,dir为空
				if (dir == "..") {
					if (!dirs.empty())
						dirs.pop_back();
				} else {
					dirs.push_back(dir);
				}
			}
			i = j;
		}

		stringstream out;         //stringstream流 使用 //也可以直接使用string
		if (dirs.empty()) {
			out << "/";
		} else {
			for (auto dir : dirs) {
				out << "/" << dir; 
			}
		}

		return out.str();  //stringstream变为string
	}
};
