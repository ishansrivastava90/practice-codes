package Others.java;

import java.util.BitSet;

public class PhoneNumAllocatorTree {

    /* This implementation optimizes the bitset approach where allocation is O(n) where n is the max Id starting from 0.
    
       Using a heap structure we narrow down the area with available ids. The total space required is -
       1 (root) + 2 + 4 + ... + n/2 + n (leaves) => 2n - 1 (GP sum with total log2(n) + 1 elements)
        
    */
    private int maxId;
    private BitSet idPool;
    public PhoneNumAllocatorTree(int maxId) {
        this.maxId = maxId;
        this.idPool = new BitSet(2 * maxId - 1);
    }

    /**
     * Allocates an available id from the pool and returns that.
     */
    public int allocate() {
        int freeBitIndex = nextAvailableBit();
        if (freeBitIndex == -1) {
            return -1; // All ids assigned
        }
        idPool.set(freeBitIndex);        
        setBitsInTree(freeBitIndex);

        return freeBitIndex + 1 - maxId;
    }

    /**
     * Returns the specified id to the availability pool.
     * @param id
     */
    public void release(int ind) {        
        if (ind >= maxId) {
            return;
        }
        int expandedInd = ind + maxId - 1;
        idPool.clear(expandedInd);
        setBitsInTree(expandedInd);
    }

    private int nextAvailableBit() {
        int currInd = 0;
        if (idPool.get(0)) {//Check root
            return -1; 
        }

        boolean noBitsAvailable = false;
        int idSize = 2 * maxId - 1;

        while (currInd < idSize) {
            int leftChild = 2 * currInd + 1;
            int rightChild = 2 * currInd + 2;
            if (leftChild < idSize && !idPool.get(leftChild)) {
                currInd = leftChild;
            }
            else if (rightChild < idSize && !idPool.get(rightChild)) {
                currInd = rightChild;
            }
            else {
                noBitsAvailable = leftChild < idSize || rightChild < idSize;
                break;
            }
        }
        if (noBitsAvailable) {
            return -1;
        }
        return currInd;
    }

    private void setBitsInTree(int ind) {
        int child = ind;
        int parent = (child - 1)/2;
        while (parent > 0) {
            
            int leftChild = child % 2 == 0 ? child - 1 : child;
            int rightChild = child % 2 == 0 ? child : child + 1;
            idPool.set(parent, idPool.get(leftChild) && idPool.get(rightChild));

            child = parent;
            parent = (child -1)/2;
        }
        idPool.set(0, idPool.get(1) && idPool.get(2)); //For the root
    }

    public static void main(String[] args) {
        PhoneNumAllocatorTree allocator = new PhoneNumAllocatorTree(3);
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());        
        System.out.println(allocator.allocate());
        allocator.release(0);
        
        System.out.println(allocator.allocate());
        System.out.println(allocator.allocate());
    }
    
}
