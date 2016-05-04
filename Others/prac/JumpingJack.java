package prac;

import java.math.BigDecimal;

public class JumpingJack {

	public static int maxStep(int N, int K) {
		
		// Solve for possible step for K
		if (isStepInTrajectory(K)) {
			return N*(N+1)/2 - 1;
		}
		return N*(N+1)/2;
		
	}
	
	private static boolean isStepInTrajectory(int k) {
		int c = -2*k;
		int b = 1;
		int a = 1;
		BigDecimal root1 = new BigDecimal(-1 * b + Math.sqrt(b*b - 4 * a * c));
		BigDecimal root2 = new BigDecimal(-1 * b - Math.sqrt(b*b - 4 * a * c));
		
		boolean isRoot1Long = true;
		boolean isRoot2Long = true;
		
		try {
			root1.longValueExact();			
		} catch (ArithmeticException e) {
			isRoot1Long = false;
		}
		
		try {
			root2.longValueExact();			
		} catch (ArithmeticException e) {
			isRoot2Long = false;
		}
		return isRoot1Long || isRoot2Long;
	}
	
	public static void main(String[] args) {
		System.out.println(maxStep(6, 6));

	}

}
