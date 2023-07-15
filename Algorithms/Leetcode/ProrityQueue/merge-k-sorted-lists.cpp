/**
 * @problem: 23. 合并 K 个升序链表
 * @link: https://leetcode.cn/problems/merge-k-sorted-lists/
 * @category: priority queue heap 分治
 * @date: Fri Jul 14 14:58:34 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/** 分治 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
      if (aPtr->val < bPtr->val) {
        tail->next = aPtr;
        aPtr = aPtr->next;
      } else {
        tail->next = bPtr;
        bPtr = bPtr->next;
      }
      tail = tail->next;
    }
    tail-> next = aPtr ? aPtr : bPtr;
    return head.next;
  }

  ListNode* merge(vector<ListNode*>& lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size() - 1);
  }
};

/** using priority queue */
class Solution {
 public:
  struct State {
    int val;
    ListNode *ptr;
    bool operator<(const State &rhs) const {
      if (val != rhs.val) return val > rhs.val;
      return false;
    }
  };
  priority_queue<State> que;
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    for (auto node : lists)
      if (node) que.push({node->val, node});
    ListNode head, *tail = &head;
    while (que.size()) {
      auto it = que.top(); que.pop();
      tail->next = it.ptr;
      tail = tail->next;
      if (it.ptr->next) que.push({it.ptr->next->value, it.ptr->next});
    }
    return head.next;
  }
};

