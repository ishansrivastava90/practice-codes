public class test {

	public static void main(String [] args) {
		IPCompressor compressor = new IPCompressor("127.255.255.255",  8);
		System.out.println(compressor.getNextIp("127.255.255.255", 45));
		System.out.println(compressor.compress());
	}
}
