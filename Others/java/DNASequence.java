package Others.prac;

import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public final class DNASequence {
	
	private static final Map<Character, BitSet> nucletoidMap = 
		new HashMap<>();
	static {
		BitSet nucA = new BitSet(2);		
		nucletoidMap.put('A', nucA);
		
		BitSet nucC = new BitSet(2);
		nucC.set(1);
		nucletoidMap.put('C', nucC);
		
		BitSet nucG = new BitSet(2);
		nucG.set(0);
		nucletoidMap.put('G', nucG);
		
		BitSet nucT = new BitSet(2);
		nucT.set(0,2);
		nucletoidMap.put('T', nucT);
	}
			
			
	private String dna;
	
	
	public DNASequence(String dna) {
		this.dna = dna;
	}
	
	public int findRepeatingSequences(int len) {
		Map<BitSet, Integer> sequences = new HashMap<>();
		BitSet sequence = new BitSet(len * 2);
		Set<String> res = new HashSet<>();
		
		for(int i = len - 1; i < dna.length(); ++i ) {
			sequence = new BitSet(len * 2);
			sequence = formBitSequence(i - len + 1, i);
			
			if (sequences.containsKey(sequence)) {
				sequences.put(sequence, sequences.get(sequence) + 1);
				if (!res.contains(dna.substring(i - len + 1, i+1))) {
					res.add(dna.substring(i - len + 1, i+1));
				}
				
			} else {
				sequences.put(sequence, 1);
			}
			
		}
		System.out.println(res);
		return res.size();
	}

	private BitSet formBitSequence(int start, int end) {
		int bitSeqLen = 2 * (end - start + 1);
		BitSet seq = new BitSet(bitSeqLen);
		//seq.set(0, bitSeqLen -1);
		
		int ind = 0;
		for (int i = start; i <= end; ++i ) {
			System.out.println(nucletoidMap.get(dna.charAt(i)));
			seq.set(ind, nucletoidMap.get(dna.charAt(i)).get(ind%2));
			ind++;
			seq.set(ind, nucletoidMap.get(dna.charAt(i)).get(ind%2));
			ind++;
			
		}
		return seq;
	}
	
	public static void main(String [] args) {
		System.out.println(nucletoidMap);
		
		String dnaTest = "ACGACTGTAAGTAGCCTACGA";
		DNASequence dnaSeq = new DNASequence(dnaTest);
		System.out.println(dnaSeq.findRepeatingSequences(4));
	}

}
