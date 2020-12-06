class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        size_ = 0;
    }
    
    int get(int key) {
        if (map_.find(key) != map_.end())
        {            
            // Need to mark as most recently used
            std::list<pair<int,int>>::iterator lit = map_[key];
            int value = (*lit).second;
            list_.erase(lit);
            list_.push_back(make_pair(key,value));
            map_[key] = std::prev(list_.end());
            
            return value;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (map_.find(key) != map_.end())
        {
            // Mark key as most recent
            std::list<pair<int,int>>::iterator lit = map_[key];
            list_.erase(lit);
            list_.push_back(make_pair(key,value));
            
            // Update key that already exists
            map_[key] = std::prev(list_.end());
        }
        else
        {
            // Need to add key
            if (size_ < capacity_)
            {
                list_.push_back(make_pair(key,value));
                map_[key] = std::prev(list_.end());
                size_++;
            }
            else
            {
                // Evict LRU key
                int lru = list_.front().first;
                list_.pop_front();
                map_.erase(lru);
                
                // Add new key
                list_.push_back(make_pair(key,value));
                map_[key] = std::prev(list_.end());
            }
        }
    }
    
private:    
    int capacity_;
    int size_;
    
    std::unordered_map<int, std::list<pair<int,int>>::iterator> map_;
    std::list<pair<int,int>> list_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
