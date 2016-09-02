/* 堆排序 By chenzhi 2016.8.10 Baidu_interview
 *
 * 堆积排序(Heapsort)是指利用堆积树（堆）这种数据结构所设计的一种排序算法。堆积树是一个近似完整二叉树的结构，并同时满足堆积属性
 * :即子结点的键值或索引总是小于（或者大于）它的父结点。
 * 
 * 在堆积树的数据结构中，堆积树中的最大值总是位于根节点。堆积树中定义以下几种操作：
 * 1.最大堆积调整（max_heapify）：将堆积树的末端子结点作调整,使得子结点永远小于父结点
 * 2.建立最大堆积（build_max_heap）：将堆积树所有数据重新排序
 * 3.堆积排序（heap_sort）：移除位在第一个数据的根结点,并做最大堆积调整的递归运算
 *
 * 时间复杂度 O(nlogn) 堆排序是不稳定的排序算法
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void max_heapify(vector<int> &nums, int parent, int heap_size) {
	int left_son = parent * 2 + 1;
	int right_son = left_son + 1;
	int largest = parent;

	if (left_son <= heap_size && nums[left_son] > nums[largest]) {
		largest = left_son;
	}
	if (right_son <= heap_size && nums[right_son] > nums[largest]) { 
		largest = right_son;
	}

	if (largest != parent) {
		swap(nums[parent], nums[largest]);
		max_heapify(nums, largest, heap_size); 
	}
}

void build_max_heap(vector<int> &nums, int heap_size){
	for (int i = heap_size / 2; i >= 0; i--) {
		max_heapify(nums, i, heap_size);
	}
}

void heap_sort(vector<int> &nums, int heap_size) {
	build_max_heap(nums, heap_size); 
	for (int i = heap_size; i >= 0; i--) {
		swap(nums[0], nums[i]);
		heap_size--;
		max_heapify(nums, 0, heap_size);
	}
}

/*测试函数*/
int main() {
	vector<int> nums = {46,79,56,38,40,84};
	heap_sort(nums, nums.size() - 1);
	//reverse(a.begin(), a.end());	
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}
