import java.util.ArrayList;
import java.util.List;

public final class IPCompressor {
	
	private final String ip;
	private final int numIps;
	
	public IPCompressor(String ip, int numIps) {
		this.ip = ip;
		this.numIps = numIps;
	}
	
	public List<String> compress() {
		
		List<String> compRange = new ArrayList<>();
		
		int currNum = numIps;
		String currIp = ip;
		
		while (!MathUtils.isPow2(currNum)) {
			int numBits = (int) MathUtils.log2(currNum);
			compRange.add(formRangeIp(currIp, Integer.toString(numBits)));
			
			int ipsInRange = MathUtils.pow2(numBits);
			currIp = getNextIp(currIp, ipsInRange);
			currNum -= ipsInRange; 
		}
		
		if (currNum == 1) {
			compRange.add(currIp);
		}
		else {
			int numBits = (int) MathUtils.log2(currNum) + 1;
			compRange.add(formRangeIp(currIp, Integer.toString(numBits)));
		}
		
		
		return compRange;
	}

//	public String getNextIp(String currIp, int numOfIps) {
//		String [] comp = currIp.split("\\.");
//		String newIp = "";
//		int ips = numOfIps;		
//		
//		int carryOn = 0;
//		for (int ind = comp.length - 1; ind >= 0 ; --ind) {
//			
//			int compValue = Integer.parseInt(comp[ind]);
//			int divisor = MathUtils.pow2(8 * (3 - ind));
//			
//			comp[ind] = Integer.toString((compValue + carryOn + ips/ divisor) % 256);
//			carryOn = (compValue + carryOn + ips/ divisor) / 256;
//			
//			if (ind != comp.length - 1) {
//				newIp = "." + newIp;
//			}
//			newIp = comp[ind] + newIp;
//			
//		}
//		
//		return newIp;
//	}

	public String getNextIp(String currIp, int numOfIps) {
		String [] comp = currIp.split("\\.");
		
		long ipVal = (Long.parseLong(comp[0].trim()) << 24 
				   |  Long.parseLong(comp[1].trim()) << 16
				   |  Long.parseLong(comp[2].trim()) << 8
				   |  Long.parseLong(comp[3].trim()));
		
		long newIpVal = ipVal + numOfIps;
		
		return String.format("%s.%s.%s.%s", (newIpVal >> 24) & 255, (newIpVal >> 16) & 255,
				(newIpVal >> 8) & 255, newIpVal & 255);
		
			
	}

	
	
	private String formRangeIp(String ip, String suffix) {		
		return ip.trim() + "/" + suffix;
		
	}

}
