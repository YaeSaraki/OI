/**
 *\link: https://leetcode.cn/problems/contains-duplicate/ 
 * \category: hash sort array
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class MyHashSet {
 private:
  vector<list<int> > data_;
  static const int kBase_ = 13331;
  constexpr static int Hash(int key) { return key % kBase_; }

 public:
  /** Initalize the data structure. */
  MyHashSet() : data_(kBase_) {}

  void add(int key) {
    if (contains(key)) return ;
    int k = Hash(key);
    data_[k].push_back(key);    
  }

  void remove(int key) {
    if (!contains(key)) return ;
    int h = Hash(key);
    for (auto it : data_[h]) {
      if (it == key) {
       data_[h].erase(find(data_[h].begin(), data_[h].end(), it));
       return;
      }
    }
  }
  
  bool contains(int key) {
    int k = Hash(key);
    for (auto it : data_[k]) {
      if (it == key) return true;
    }
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */