package finalproject;

import cse131.ArgsProcessor;
import cse131.NotYetImplementedException;
import finalproject.tests.FeedOnePlayerBattleship;

public class OnePlayerBattleship implements Battleship {

	private ArgsProcessor ap;
	private Player p1;
	private int height;
	private int width;
	private int numShips;
	private boolean randomShips;
	private String name;
	
	/**
	 * The main method that gets the starting parameters for a game,
	 * creates an instance of the OnePlayerBattleship class,
	 * and plays the game!
	 * @param args
	 */
	public static void main(String[] args) {
		ArgsProcessor ap = new ArgsProcessor(args);
		
		String name = ap.nextString("What is the player's name?");
		int length = ap.nextInt("What is the length of the board?");
		int width = ap.nextInt("What is the width of the board?");
		int numShips = ap.nextInt("How many ships should each player have?");
		boolean randomShips = ap.nextBoolean("Should the ships be placed randomly? Type true or false");
		Battleship bs = new OnePlayerBattleship(length, width, randomShips, numShips, name, ap);
		Player winner = bs.play();
		System.out.println(winner.getName() + " won!");
	}
	
	/**
	 * Create an instance of the OnePlayerBattleship class
	 * Create a player with the given name
	 * Place all ships, randomly or manually
	 * 
	 * NOTE: We've created the player for you, in order to deal with the ArgsProcessor that needs to be passed
	 * 
	 * @param width width of the board (# cols)
	 * @param height height of the board (# rows)
	 * @param randomShips whether or not the ships should be placed randomly
	 * @param playerName the name of the Player who will be playing the game
	 */
	public OnePlayerBattleship(int width, int height, boolean randomShips, int numShips, String playerName, ArgsProcessor ap) {
		p1 = new HumanPlayer(playerName, width, height, ap); // DON'T CHANGE THIS
		this.ap = ap;
		this.width = width;
		this.height = height;
		this.randomShips = randomShips;
		this.numShips = numShips;
	}

	@Override
	public Player play() {
//		int length = (int)(Math.random()*(this.width+this.height)/2);
//		int length = 4;
		int length = (this.width+this.height)/4;
		for(int i = 0; i < this.numShips; ++i) {
			if(this.randomShips) {
				this.p1.addRandomShip(length);
			} else {
				Ship s = this.p1.decideShipPlacement(length);
				this.p1.addShip(s);
			}
		}
		while(this.p1.numShipsStillAfloat() > 0) {
			turn(this.p1);
		}
		return this.p1;
	}

	@Override
	public boolean turn(Player p) {
		int c = p.numShipsStillAfloat();
		p.printRadar();
		int[] firepoint = p.getTargetLocation();
		int x = firepoint[0];
		int y = firepoint[1];
		boolean isHit = p.respondToFire(x, y);
		p.recordHitOrMiss(x, y, isHit);
		if(c > p.numShipsStillAfloat()) {
			System.out.println("You sunk my battleship!");
		}
		if(p.numShipsStillAfloat() == 0) {
			return true;
		}
		return false;
	}
	
	/**
	 * We've implemented this for you since there's only one player, you can leave this alone!
	 */
	@Override
	public Player getPlayerOne() {
		return p1;
	}

	/**
	 * We've implemented this for you since there's only one player, you can leave this alone!
	 */
	@Override
	public Player getPlayerTwo() {
		return null;
	}

}
