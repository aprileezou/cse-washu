package studio5;

public class Methods {
	
	/**
	 * Implemented correctly
	 * @param x one thing to add
	 * @param y the other thing to add
	 * @return the sum
	 */
	public static int sum(int x, int y) {
		return x+y;
	}
	
	/**
	 * 
	 * @param x one factor
	 * @param y another factor
	 * @return the product of the factors
	 */
	public static int mpy(int x, int y) {
		return x*y;  // FIXME
	}
	
	/**
	 * 
	 * @param x one factor
	 * @param y another factor
	 * @param z one more factor
	 * @return the average of the factors
	 */
	public static double avg3(int x, int y, int z) {
		return (x+y+z)/3;
	}
	
	/**
	 * 
	 * @param array a list of doubles
	 * @return the sum of all doubles in array
	 */	
	public static double sumArray(double[]array) {
		double sum = 0;
		for (int i=0; i < array.length; ++i) {
			sum = sum + array[i];
		}
		return sum;
	}
	
	/**
	 * 
	 * @param array a list of doubles
	 * @return the average of all doubles in array
	 */
	public static double average(double[]array) {
		double sum = 0;
		for (int i=0; i < array.length; ++i) {
			sum = sum + array[i];
		}
		return sum/array.length;
	}
	
	/**
	 * 
	 * @param x one factor
	 * @param y another factor
	 * @return x to the power of y
	 */
	public static double power(double x, double y) {
		return Math.pow(x, y);
	}
	
	/**
	 * 
	 * @param s a string
	 * @return the pig one
	 */
	public static String pig(String s) {
		String a = s.substring(0,1);
		String b = s.substring(1);
		return (b + a + "ay");
	}
  


}
