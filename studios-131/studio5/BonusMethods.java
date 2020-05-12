package studio5;

public class BonusMethods {
	
	/**
	 * 
	 * @param n an integer
	 * @return the sum of the positive integers n
	 */
	public static int sumDownBy2(int n) {
		int sum = 0;
		for(int i = n; i > 0; i = i -2) {
			sum = sum + i;
		}
		return sum;
	}
	
	/**
	 * 
	 * @param n a positive integer
	 * @return the sum of the 1/n
	 */
	public static double harmonicSum(int n) {
		double sum = 0;
		for(int i = 0; i < n; ++i) {
			sum = sum + 1.0/(i+1);
		}
		return sum;
	}
	
	/**
	 * 
	 * @param k a non-negative integer
	 * @return the sum of 1/math.pow(2,k)
	 */
	public static double geometricSum(int k) {
		double sum = 0;
		for(int i = 0; i < k + 1; ++i) {
			sum = sum + 1.0/(double)(Math.pow(2,i));
		}
		return sum;
	}
	
	/**
	 * 
	 * @param j a positive integer
	 * @param k a positive integer
	 * @return multiplication
	 */
	public static int multPos(int j, int k) {
		int sum = 0;
		for(int i=0; i<k; ++i) {
			sum = sum + j;
		}
	    return sum;
	}
	
	/**
	 * 
	 * @param j an integer
	 * @param k an integer
	 * @return multiplication
	 */
	public static int mult(int j, int k) {
		boolean check = j*k > 0;
		if(check) {
			return multPos(Math.abs(j),Math.abs(k));
		}
		else {
			return -multPos(Math.abs(j),Math.abs(k));
		}	
	}
	
	/**
	 * 
	 * @param n an integer
	 * @param k an integer ≥ 0
	 * @return n to the power of k
	 */
	public static int expt(int n, int k) {
		int sum = 1;
		for(int i=0; i<k; ++i) {
			sum = sum*n;
		}
	    return sum;
	}
	
}
