// https://leetcode.com/problems/lru-cache/

class LRUCache{
public:
    struct Cache {
        Cache() = default;
        Cache(int key, int value) : key(key), value(value) {}
        int key;
        int value;
        Cache *next;
        Cache *prev;
    };

    LRUCache(int capacity) {
        capacity_ = capacity;
        head_.next = &tail_;
        tail_.prev = &head_;
    }

    int get(int key) {
        auto it = vmap_.find(key);
        if(it == vmap_.end()) {
            return -1;
        } else {
            Cache *c = it->second;
            move_cache_to_head(c);
            return c->value;
        }
    }

    void set(int key, int value) {
        auto it = vmap_.find(key);
        if(it != vmap_.end()) {
            Cache *c = it->second;
            c->value = value;
            move_cache_to_head(c);
        } else {
            if(capacity_ == vmap_.size()) {
                Cache *c = remove_last_cache();
                vmap_.erase(c->key);
                c->key = key;
                c->value = value;
                cache_push(c);
                vmap_[key] = c;
            } else {
                Cache *c = new Cache(key, value);
                cache_push(c);
                vmap_[key] = c;
            }
        }
    }

    void cache_push(Cache *c) {
        c->next = head_.next;
        head_.next = c;
        c->next->prev = c;
        c->prev = &head_;
    }

    void cache_push(int key, int value) {
        Cache *c = new Cache(key, value);
        cache_push(c);
    }

    void move_cache_to_head(Cache *c) {
        c->prev->next = c->next;
        c->next->prev = c->prev;
        cache_push(c);
    }

    Cache *remove_last_cache() {
        Cache *c = tail_.prev;
        tail_.prev = c->prev;
        c->prev->next = &tail_;
        return c;
    }

private:
    Cache head_;
    Cache tail_;
    int capacity_;
    unordered_map<int, Cache *> vmap_;
};

template<typename Key, typename Value>
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head_.next = &tail_;
        tail_.prev = &head_;
    }

    Value get(Key key) {
        auto it = vmap_.find(key);
        if(it == vmap_.end()) {
            return Value();
        } else {
            Cache *c = it->second;
            move_cache_to_head(c);
            return c->value;
        }
    }

    void set(Key key, Value value) {
        auto it = vmap_.find(key);
        if(it != vmap_.end()) {
            Cache *c = it->second;
            c->value = value;
            move_cache_to_head(c);
        } else {
            if(capacity_ == vmap_.size()) {
                Cache *c = remove_last_cache();
                vmap_.erase(c->key);
                c->key = key;
                c->value = value;
                cache_push(c);
                vmap_[key] = c;
            } else {
                Cache *c = new Cache(key, value);
                cache_push(c);
                vmap_[key] = c;
            }
        }
    }

private:
    void cache_push(Cache *c) {
        c->next = head_.next;
        head_.next = c;
        c->next->prev = c;
        c->prev = &head_;
    }

    void cache_push(Key key, Value value) {
        Cache *c = new Cache(key, value);
        cache_push(c);
    }

    void move_cache_to_head(Cache *c) {
        c->prev->next = c->next;
        c->next->prev = c->prev;
        cache_push(c);
    }

    Cache *remove_last_cache() {
        Cache *c = tail_.prev;
        tail_.prev = c->prev;
        c->prev->next = &tail_;
        return c;
    }

private:
    struct Cache {
        Cache() = default;
        Cache(Key key, Value value) : key(key), value(value) {}
        Key key;
        Value value;
        Cache *prev;
        Cache *next;
    };
    Cache head_;
    Cache tail_;
    int capacity_;
    unordered_map<Key, Cache *> vmap_;
};

template<typename Key, typename Value>
class LRUCache {
public:
    // err为当cache查找失败时返回的值
    LRUCache(int capacity, Value err) {
        err_ = err;
        capacity_ = capacity;
        head_.next = &tail_;
        tail_.prev = &head_;
    }

    Value get(Key key) {
        auto it = vmap_.find(key);
        if(it == vmap_.end()) {
            return err_;
        } else {
            Cache *c = it->second;
            move_cache_to_head(c);
            return c->value;
        }
    }

    void set(Key key, Value value) {
        auto it = vmap_.find(key);
        if(it != vmap_.end()) {
            Cache *c = it->second;
            c->value = value;
            move_cache_to_head(c);
        } else {
            if(capacity_ == vmap_.size()) {
                Cache *c = remove_last_cache();
                vmap_.erase(c->key);
                c->key = key;
                c->value = value;
                cache_push(c);
                vmap_[key] = c;
            } else {
                Cache *c = new Cache(key, value);
                cache_push(c);
                vmap_[key] = c;
            }
        }
    }

private:
    struct Cache {
        Cache() = default;
        Cache(Key key, Value value) : key(key), value(value) {}
        Key key;
        Value value;
        Cache *prev;
        Cache *next;
    };

    void cache_push(Cache *c) {
        c->next = head_.next;
        head_.next = c;
        c->next->prev = c;
        c->prev = &head_;
    }

    void cache_push(Key key, Value value) {
        Cache *c = new Cache(key, value);
        cache_push(c);
    }

    void move_cache_to_head(Cache *c) {
        c->prev->next = c->next;
        c->next->prev = c->prev;
        cache_push(c);
    }

    Cache *remove_last_cache() {
        Cache *c = tail_.prev;
        tail_.prev = c->prev;
        c->prev->next = &tail_;
        return c;
    }

private:
    Cache head_;
    Cache tail_;
    Value err_;
    int capacity_;
    unordered_map<Key, Cache *> vmap_;
};
