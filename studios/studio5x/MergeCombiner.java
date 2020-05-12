package studio5x;

import cse131.NotYetImplementedException;
import lab5.Strings;

public class MergeCombiner {
	/**
	 * Produces an array which is the sorted result of merging the two specified,
	 * sorted input arrays a and b.
	 * 
	 * For example, when the arrays { "E", "G", "N" } and {"B", "I", "S" } are
	 * passed to this method, the resulting array { "B", "E", "G", "I", "N", "S" }
	 * should be returned.
	 * 
	 * If either input array a or b is unsorted, then the results are undefined.
	 * 
	 * This method must not mutate (that is: change the contents of) the input
	 * arrays a or b, nor would it have any real reason to do so.
	 * 
	 * @param a
	 *            a sorted array
	 * @param b
	 *            another sorted array
	 * @return a new array which contains the contents of both a and b, sorted.
	 */
	public static String[] createMergeCombinedArray(String[] a, String[] b) {
		String[] c = new String[a.length+b.length];
		int m = 0;
		int n = 0;
		for(int i = 0; i < c.length; ++i) {
			if(m < a.length && n < b.length) {
				if(Strings.isLessThan(a[m], b[n])) {
					c[i] = a[m];
					m = m + 1;
				}
				else {
					c[i] = b[n];
					n = n + 1;
				}
			}
			else if(m == a.length) {
				c[i] = b[n];
				n = n + 1;
			}
			else if(n == b.length){
				c[i] = a[m];
				m = m + 1;				
			}
		}
		return c;
		
	}
}
