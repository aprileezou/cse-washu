package studio3;

import cse131.ArgsProcessor;

public class SieveOfEratosthenes {

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		int n = ap.nextInt("How many numbers do you want to run?");
		int[] content = new int[n];
		for(int i = 0; i < n; i++) {
			content[i] = i + 2;
		}
		System.out.print("Primes under " + n + " = ");
		// for(int i = 0; i < n; i++) {
		// if(content[i] != 0) {
		// for(int j = n-1; j > i; j--) {
		// if(content[j] % content[i] == 0) {
		// content[j] = 0;
		// }
		// }
		// }
		// }
		for(int i = 0; i < n; i++) {
			if(content[i] != 0) {
				for(int j = i + content[i]; j < n; j = j + content[i]) {
					content[j] = 0;
				}
			}
		}
		// for(int i=0;i<n;i++) {
		// if(content[i] !=0) {
		// for(int j = 1;j<=((n-1) / content[i]);j++) {
		// content[i + content[i] * j]= 0 ;
		// }
		// }
		// }
		int max = 0;
		for(int i = 0; i < n; i++) {
			if(content[i] != 0) {
				max = i;
			}
		}
		for(int i = 0; i < max; i++) {
			if(content[i] != 0) {
				System.out.print(content[i] + ", ");
			}
		}
		System.out.print(content[max]);
	}

}


