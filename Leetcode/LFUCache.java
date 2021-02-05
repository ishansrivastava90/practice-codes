package Leetcode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

public class LFUCache {

    private int _capacity;
    private int _currInUse;
    private HashMap<Integer, LFUEntry> _lfuMap;
    private PriorityQueue<LFUEntry> _frequencyQueue;

    public LFUCache(int capacity) {
        _capacity = capacity;
        _currInUse = 0;
        _lfuMap = new HashMap<>();
        _frequencyQueue = new PriorityQueue<>(new Comparator<LFUEntry>(){
            @Override
            public int compare(LFUEntry e1, LFUEntry e2) {
                if (e1.Counter == e2.Counter) {
                    return Long.compare(e1.TimeStamp, e2.TimeStamp);
                }
                return Integer.compare(e1.Counter, e2.Counter);
            }}
        );
    }

    public int get(int key) {
        if (_lfuMap.containsKey(key)) {
            LFUEntry updatedEntry = update(key, _lfuMap.get(key));
            return updatedEntry.Value;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (_currInUse == _capacity && !_lfuMap.containsKey(key)) {
            if (!evict()) {
                return;
            }
        }
        if (!_lfuMap.containsKey(key)) {
            _lfuMap.put(key, new LFUEntry(key, value));
        }
        LFUEntry newEntry = _lfuMap.get(key);
        newEntry.Value = value;
        update(key, newEntry);
        
        _currInUse = _lfuMap.size();
    }

    private LFUEntry update(int key, LFUEntry lfuEntry) {
        lfuEntry = lfuEntry.incrementCounter();
        _frequencyQueue.remove(lfuEntry);
        _frequencyQueue.add(lfuEntry);
        _lfuMap.put(key, lfuEntry);

        return lfuEntry;
    }

    private boolean evict() {
        LFUEntry lfuEntry = _frequencyQueue.poll();
        if (lfuEntry != null) {
            _lfuMap.remove(lfuEntry.Key);
        }
        _currInUse = _lfuMap.size();
        return _currInUse < _capacity;
    }

    private class LFUEntry {
        public int Key;
        public int Value;
        public int Counter;
        public long TimeStamp;

        public LFUEntry(int key, int value) {
            Key = key;
            Value = value;
            Counter = 0;
            TimeStamp = System.currentTimeMillis();
        }

        public LFUEntry incrementCounter() {
            this.Counter++;
            this.TimeStamp = System.currentTimeMillis();
            return this;
        }

        @Override
        public boolean equals(Object other) {
            if (other instanceof LFUEntry) {
                return this.Key == ((LFUEntry)other).Key;
            }
            return false;
        }
    }
}
