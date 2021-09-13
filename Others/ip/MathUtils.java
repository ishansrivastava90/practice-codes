public final class MathUtils {
	
	public static double log2(int num) {
		return 31 - Integer.numberOfLeadingZeros(num);
	}

	public static int pow2(int exp) {
		if (exp == 0) return 1;
		return 2 << (exp - 1);
	}

	public static boolean isPow2(int num) {		
		return num != 0 && (num & (num-1)) == 0;
	}

}
