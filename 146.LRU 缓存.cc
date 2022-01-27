#include <utility>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int _capacity;
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _key_to_node;
public:
    LRUCache(int capacity) : _capacity(capacity) {

    }
    
    int get(int key) {
        auto itr = _key_to_node.find(key);
        if (itr != _key_to_node.end()) {
            _cache.splice(_cache.begin(), _cache, _key_to_node[key]);
            return _key_to_node[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto itr = _key_to_node.find(key);
        if (itr != _key_to_node.end()) {
            _cache.splice(_cache.begin(), _cache, _key_to_node[key]);
            _key_to_node[key]->second = value;
            return;
        }

        _cache.emplace_front(key, value);
        _key_to_node[key] = _cache.begin();

        if (_cache.size() > _capacity) {
            _key_to_node.erase(_cache.back().first);
            _cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */