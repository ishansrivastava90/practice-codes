package Others.java;

import java.util.BitSet;

public class PhoneNumAllocator {

    private int maxId;
    private BitSet idPool;
    public PhoneNumAllocator(int maxId) {
        this.maxId = maxId;
        this.idPool = new BitSet(maxId);
    }

    /**
     * Allocates an available id from the pool and returns that.
     */
    public int allocate() {
        int freeBitIndex = idPool.nextClearBit(0);
        if (freeBitIndex >= maxId) {
            return -1; // All ids assigned
        }
        idPool.set(freeBitIndex);
        return freeBitIndex;
    }

    /**
     * Returns the specified id to the availability pool.
     * @param id
     */
    public void release(int ind) {
        if (ind >= maxId) {
            return;
        }
        idPool.clear(ind);
    }

    public static void main(String[] args) {
        PhoneNumAllocator allocator = new PhoneNumAllocator(3);
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
        allocator.release(0);
        allocator.release(2);
        
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
    }
    
}
