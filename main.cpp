#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRU_Cache {
private:
    // Using pair to store both key and value in the list
    list<pair<int, string>> L;  
    unordered_map<int, list<pair<int, string>>::iterator> M;
    int capacity;

public:
    LRU_Cache(int cap) {
        if (cap > 0) {
            capacity = cap;
        } else {
            cout << "ERROR: LRU Capacity must be more than 0, please reinitialize the cache" << endl;
            capacity = 0;
        }
    }

    int size() {
        return capacity;
    }

    void feedin(int key, string data) {
        if (M.find(key) != M.end()) {
            // Key exists, remove the old entry
            L.erase(M[key]);
        } else if (L.size() >= capacity) {
            // Cache is full, remove least recently used
            int last_key = L.back().first;
            L.pop_back();
            M.erase(last_key);
        }
        
        // Add new entry to front
        L.push_front({key, data});
        M[key] = L.begin();
    }

    string gettin(int key) {
        if (M.find(key) == M.end()) {
            return "0";  // Key not found
        }
        
        // Move accessed item to front (mark as most recently used)
        L.splice(L.begin(), L, M[key]);
        return M[key]->second;
    }

    void display() {  // Helper function to display cache contents
        for (const auto& item : L) {
            cout << "Key: " << item.first << ", Value: " << item.second << endl;
        }
    }
};

int main() {
    LRU_Cache lru1(2);
    cout << "The size of this LRU Cache is: " << lru1.size() << endl;
    
    lru1.feedin(1, "beta");
    lru1.feedin(3, "alpha");
    lru1.feedin(8, "gamma");
    
    cout << lru1.gettin(1) << endl;  // Should output: "0" (evicted)
    cout << lru1.gettin(3) << endl;  // Should output: "alpha"
    cout << lru1.gettin(6) << endl;  // Should output: "0" (never inserted)
    cout << lru1.gettin(8) << endl;  // Should output: "gamma"
    
    return 0;
}
