public class MaxBinaryGap {
		
	public static int findMaxGap(int num) {
		if (num == 0) {
			return 0;
		}
		
		int [] prevInds = {-1, -1};
		
		int gap = 0;
		int end = (int) (MathUtils.log2(num) + 2);
		for (int i = 0; i < end; ++i) {
			int currBit = num & 1;
			System.out.println(num);
			if (prevInds[currBit] != -1 && i - prevInds[currBit] -1 > gap) {
				gap = i - prevInds[currBit] - 1;
			}
			prevInds[currBit] = i;
			num = num >> 1;
		}
		return gap;
	}
	
	
	public static void main (String [] args) {
		
		int N = 9;
		System.out.println(findMaxGap(N));
	}

}
