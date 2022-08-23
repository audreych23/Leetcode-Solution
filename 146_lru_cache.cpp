/**
 * Time Complexity: O(1)
 * Space Complexity: O(n)
 */
// a LRUCache is a hash table with a key connected to a iterator on a list of the value so LRU and MRU can be
// organized in a way so put() and get() is O(1) (because list erase on iterator is O(1))
class LRUCache {
  // stores key and value
  list<pair<int, int>> _list;
  // stores key and iterator to look up in O(1)
  unordered_map<int, list<pair<int, int>>::iterator> _table;
  int _capacity;
public:
  LRUCache(int capacity)
  : _capacity(capacity)
  {
  }

  int get(int key) {
    auto search { _table.find(key) };
    if (search == _table.end()) return -1;
    // copy to head and delete old key to make it MRU
    _list.push_front(pair<int, int> {_table[key]->first, _table[key]->second});
    _list.erase(_table[key]);
    _table[key] = _list.begin();
    return _table[key]->second;
  }

  void put(int key, int value) {
    // head is most recently used (MRU) and tail is least recently used (LRU)
    auto search { _table.find(key) };
    if (search != _table.end()) {
      _list.erase(_table[key]);
      _list.push_front(pair<int, int> {key, value});
      _table[key] = _list.begin();
    } else {
      if (_list.size() >= _capacity) {
        // delete the LRU
        // don't use prev(_list.end());
        auto tail { _list.back() };
        auto delete_key { tail.first };
        _list.pop_back();
        _table.erase(delete_key);
      }
      _list.push_front(pair<int, int> {key, value});
      _table[key] = _list.begin();
    }
    return;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
