/**
 * @problem: 数组中的第K个最大元素
 * @link: https://leetcode.cn/problems/kth-largest-element-in-an-array
 * @category: array qsort heap priority queue
 * @date: Fri Jul 14 16:07:56 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>

using namespace std;

/** using heap */
class Solution {
public:
  void maxHeapify(vector<int> &nums, int root, int heap_size) {
    int l = root * 2 + 1, r = root * 2 + 2, largest = root;
    if (l < heap_size && nums[l] > nums[largest]) largest = l;
    if (r < heap_size && nums[r] > nums[largest]) largest = r;
    if (largest != root) {
      swap(nums[root], nums[largest]);
      maxHeapify(nums, largest, heap_size);
    }
  }

  void buildMaxHeap(vector<int> &nums, int heap_size) {
    for (int i = heap_size / 2; ~i; --i) maxHeapify(nums, i, heap_size);
  }

  int findKthLargest(vector<int>& nums, int k) {
    int heap_size = nums.size();
    buildMaxHeap(nums, heap_size);
    for (int i = nums.size() - 1; i > nums.size() - k; --i) {
      nums[0] = nums[i];
      --heap_size;
      maxHeapify(nums, 0, heap_size);
    }
    return nums[0];
  }
};

/** using qsort */
class Solution2 {
public:
  int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    while (left < right) {
      while (left < right && nums[right] >= pivot) --right;
      nums[left] = nums[right];
      while (left < right && nums[left] <= pivot) ++left;
      nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
  }

  int quickSort(vector<int> &nums, int left, int right, int k) {
    int mid = partition(nums, left, right);
    if (mid == k) return nums[k];
    else if (mid > k) return quickSort(nums, left, mid - 1, k);
    else return quickSort(nums, mid + 1, right, k);
  }

  int findKthLargest(vector<int>& nums, int k) {
    return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
  }
};
