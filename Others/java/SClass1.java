public class SClass1  implements Comparable<SClass1>{
	int height;
	int weight;
	
	public SClass1(int h, int w) {
		this.height = h;
		this.weight = w;
	}
	
	@Override
	public String toString() {
		return "(" + height +", " + weight +")";
	}

	@Override
	public int compareTo(SClass1 o) {
		return this.height- o.height;
	}

}
