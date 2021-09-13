#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

template <class T>
class KeyValueStore {
  map<int, T> commit_store;
  map<int, T> uncommit_store;
  vector<int> delete_keys;
  
  
  bool inTransaction;
  public:
    KeyValueStore() {
      inTransaction = false;
    }
  
    T get(int key) {
      
      if (inTransaction) {
        if (uncommit_store.find(key) != uncommit_store.end()) {
          return uncommit_store[key];
        }
      }
      
      for (unsigned int i = 0; i < delete_keys.size(); ++i) {
        if (delete_keys[i] == key)
          throw new invalid_argument("Key not in store");
      }
      
      if (commit_store.find(key) != commit_store.end()) {
        return commit_store[key];
      }
      
      throw new invalid_argument("Key not in store");
      
    }
  
    void insert(int key, T value) {
      if (inTransaction) {
         uncommit_store[key] = value;
      }
      else {
        commit_store[key] = value;
      }        
    }
  
    void remove(int key) {
      if (inTransaction) {
         delete_keys.push_back(key);
      }
      else {
        commit_store.erase(key);
      }
    }
  
    void begin() {
      inTransaction = true;
    }

    void commit() {
      if (inTransaction) {
        uncommit_store.insert(commit_store.begin(), commit_store.end());
        commit_store = uncommit_store;
        
        for (unsigned int i = 0; i < delete_keys.size(); ++i) {
          commit_store.erase(delete_keys[i]);
        }
        
        uncommit_store.clear();
        delete_keys.clear();
        inTransaction = false;
      }
    }
  
    void rollback() {
      uncommit_store.clear();
      delete_keys.clear();
    }
};

// Testing the code
int main() {
  KeyValueStore<int> kv;
  kv.insert(1, 1);
  kv.insert(2, 2);
  cout << kv.get(1) << endl;
  kv.begin();
  kv.insert(1, -1);
  cout << kv.get(1) << endl;
  kv.remove(2);
  kv.rollback();  
  cout << kv.get(1) << endl;
  cout << kv.get(2) << endl;
  return 0;
}
