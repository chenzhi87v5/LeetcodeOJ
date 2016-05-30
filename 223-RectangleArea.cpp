/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

......图
......图

Assume that the total area is never beyond the maximum possible value of int.
*/

//数学题，求矩形覆盖面积。因为只有两个矩形，所以直接算结果 = 两个矩形的面积 - 相交的面积

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int res = (D - B) * (C - A) + (H - F) * (G - E);
		int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H);
		
		if (D1 <= B1 || C1 <= A1)  //面积不相交
			return res;
		
		return res - (D1 - B1) * (C1 - A1); //面积相交
	}
};
