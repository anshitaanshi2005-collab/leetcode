class LRUCache {
public:

    int capacity;

    // key, value
    list<pair<int, int>> cache;

    // key -> position in the list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];

        int value = it->second;

        // Move this key to the front
        cache.erase(it);
        cache.push_front({key, value});

        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            cache.erase(mp[key]);
        }

        // Add as most recently used
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Remove least recently used item
        if (cache.size() > capacity) {

            auto last = cache.back();

            mp.erase(last.first);
            cache.pop_back();
        }
    }
};