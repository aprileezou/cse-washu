package studio2;

import cse131.ArgsProcessor;

public class Ruin {

	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		int startAmount = ap.nextInt("How many amount of money you want to start with?");
		double winChance = ap.nextDouble("What is the probability of winning?");
		int winAmount = ap.nextInt("What is the amount of money to win?");
		int totalPlays = ap.nextInt("How many times for simulation?");

		double lossChance = 1.0 - winChance;
		double ruin = 0;
		if (winChance != lossChance) {
			ruin = (Math.pow((lossChance/winChance), startAmount)-Math.pow((lossChance/winChance), winAmount))/(1-Math.pow((lossChance/winChance), winAmount));
		}
		else {
			ruin = 1 - startAmount/winAmount;
		}
		
		int m = 0;

		for (int i = 0; i < totalPlays; i = i + 1) {
			int leftAmount = startAmount;
			for (int j = 1; leftAmount < winAmount && leftAmount > 0; j = j + 1) {
				if (Math.random() < winChance) {
					leftAmount = leftAmount + 1;
					if (leftAmount == winAmount) {
						System.out.println("Simulation " + i + ": " + j + " rounds       WIN");
					}
				}
				else {
					leftAmount = leftAmount - 1;
					if (leftAmount == 0) {
						System.out.println("Simulation " + (i+1) + ": " + (j+1) + " rounds       LOSE");
						m = m + 1;
						
					}
				}
			}
		}
		
		System.out.println("Losses: " + m + "      Simulations: " + totalPlays);
		System.out.println("Actual Ruin Rate: " + m/totalPlays + "       Expected Ruin Rate: " + ruin);

	}
}
