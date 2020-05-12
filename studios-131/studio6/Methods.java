package studio6;

public class Methods {

	public static int fact(int n) {
		if(n <= 0) {
			return 1;
		}
		else {
			return n*fact(n-1);
		}
	}
	
	public static int fib(int n) {
		if(n <= 1) {
			return n;
		}
		else {
			return fib(n-1) + fib(n-2);
		}
	}
	
	public static boolean isOdd(int n){
		if(n <= 0) {
			return false;
		}
		else {
			return !isOdd(n-1);
		}
	}
	
	public static int sum(int a, int b) {
		if(b <= 0) {
			return a;
		}
		else {
			return sum(a+1,b-1);
		}
	}
	
	public static int sumDownBy2(int n) {
		if(n == 0) {
			return 0;
		}
		else if(n == 1) {
			return 1;
		}
		else {
			return n + sumDownBy2(n-2);
		}
	}
	
	public static double harmonicSum(int n) {
		if(n == 1) {
			return 1;
		}
		else {
			return 1.0/n + harmonicSum(n-1);
		}
	}
	
	public static int mult(int a, int b) {
		if(b == 0) {
			return 0;
		}
		else {
			return a + mult(a, b-1);
		}
	}
	
	public static int recursive1(int x) {
		if(x > 100) {
			return x-10;
		}
		else {
			return recursive1(recursive1(x+11));
		}
	}
	
	public static int recursive2(int x, int y) {
		if(x == 0) {
			return y+1;
		}
		else {
			if(y == 0) {
				return recursive2(x-1,1);
			}
			else {
				return recursive2(x-1, recursive2(x, y-1));
			}
		}
	}
	
	public static void main(String[] args) {
		System.out.println(recursive1(99));
		System.out.println(recursive1(87));
		System.out.println();
		System.out.println(recursive2(1,0));
		System.out.println(recursive2(1,2));
		System.out.println(recursive2(2,2));
		System.out.println(recursive2(4,0));
		System.out.println(recursive2(4,1));
		System.out.println(recursive2(4,3));
	}
}
