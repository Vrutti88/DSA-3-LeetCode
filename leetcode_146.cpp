class LRUCache {
public:
    int capacity;

    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];

        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});

        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();

        if (cache.size() > capacity) {
            int oldKey = cache.back().first;

            cache.pop_back();
            mp.erase(oldKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
