package studio6;

public class Beer {

	public static String bottlesOfBeer(int n) {
		if(n == 0) {
			return "";
		}
		else {
			return n + " bottles of beer on the wall, " + n + 
					" bottles of beer; you take one down, pass it around, " + (n-1) + 
					" bottles of beer on the wall." + "\n" + bottlesOfBeer(n-1);
		}
	}
	
	public static void main(String[] args) {
		System.out.println(bottlesOfBeer(5));

	}

}
