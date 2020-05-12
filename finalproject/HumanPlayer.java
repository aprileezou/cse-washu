package finalproject;

import java.util.Arrays;
import java.util.LinkedList;

import cse131.ArgsProcessor;
import cse131.NotYetImplementedException;

public class HumanPlayer implements Player {

	private final ArgsProcessor ap; // Don't change this!
	private String name;
	private int height;
	private int width;
	private LinkedList<Ship> shiplist;
	private boolean[][] board;
	private int[][] radar;

	/**
	 * Creates an instance of the HumanPlayer class
	 * Note that we already dealt with taking in an ArgsProcessor object
	 * 		We know you've never seen this before, which is why it's given to you
	 * 		You can treat this ArgsProcessor (ap) throughout the HumanPlayer class
	 * 			like any other ArgsProcessor you've used in 131
	 * We leave the rest of the constructor to you
	 * 
	 * @param name the name of the player
	 * @param height the height of the board
	 * @param width the width of the board
	 * @param ap the ArgsProcessor object
	 */
	public HumanPlayer(String name, int height, int width, ArgsProcessor ap) {
		this.ap = ap;
		this.name = name;
		this.height = height;
		this.width = width;
		this.shiplist = new LinkedList<Ship>();
		this.board = new boolean[height][width];
		this.radar = new int[height][width];
	}

	@Override
	public boolean addShip(Ship s) {
		if(this.isValidShipToAdd(s)) {
			shiplist.add(s);
			for(int i = 0; i < s.getLength(); ++i) {
				if(s.isHorizontal()) {
					this.board[s.getTopLeftY()][s.getTopLeftX()+i] = true;
				} else {
					this.board[s.getTopLeftY()+i][s.getTopLeftX()] = true;
				}
			}
			return true;
		}
		return false;
	}

	@Override
	public int[] getTargetLocation() {
		int x = ap.nextInt("What is the x coordinate for the fire point?");
		int y = ap.nextInt("What is the y coordinate for the fire point?");
		while(x < 0 || x > this.width-1 || y < 0 || y > this.height-1) {
			x = ap.nextInt("Oops! Something wrong! New x coordinate for the fire point?");
			y = ap.nextInt("Oops! Something wrong! New y coordinate for the fire point?");
		}
		return new int[] {x,y};
	}

	@Override
	public void recordHitOrMiss(int x, int y, boolean isHit) {
		if(isHit) {
			this.radar[y][x] = -1;
		} else {
			this.radar[y][x] = 1;
		}
	}

	@Override
	public Ship decideShipPlacement(int length) {
		int x = ap.nextInt("What is the top left x?");
		int y = ap.nextInt("What is the top left y?");
		boolean h = ap.nextBoolean("Is the ship horizontal?");
		Ship n = new Ship(x, y, length, h);
		while(this.isValidShipToAdd(n) == false) {
			x = ap.nextInt("What is the top left x?");
			y = ap.nextInt("What is the top left y?");
			h = ap.nextBoolean("Is the ship horizontal?");
			n = new Ship(x, y, length, h);
		}
		return n;
	}

	@Override
	public String getName() {
		return this.name;
	}

	@Override
	public boolean respondToFire(int x, int y) {
		for(int i = 0; i < this.shiplist.size(); ++i) {
			if(this.shiplist.get(i).isHit(x, y)) {
				return true;
			}
		}
		return false;
	}

	@Override
	public int numShipsStillAfloat() {
		int c = 0;
		for(int i = 0; i < this.shiplist.size(); ++i) {
			if(this.shiplist.get(i).isSunk() == false) {
				c = c + 1;
			}
		}
		return c;
	}

	@Override
	public boolean addRandomShip(int length) {
		int a = -1;
		int b = 0;
		boolean d = true;
		Ship r = new Ship(a, b, length, d);
		while(this.addShip(r) == false) {
			a = (int)(Math.random()*this.width);
			b = (int)(Math.random()*this.height);
			d = true;
			if(Math.random() < 0.5) {
				d = false;
			}
			r = new Ship(a, b, length, d);
		}
		return true;

	}

	@Override
	public boolean isValidShipToAdd(Ship s) {
		if(s.getTopLeftX() < 0 || s.getTopLeftY() < 0) {
			return false;
		}
		if(s.isHorizontal()) {
//			if(s.getTopLeftX() + s.getLength() > this.width) {
//				return false;
//			}
			for(int i = s.getTopLeftX(); i < s.getTopLeftX() + s.getLength(); ++i) {
				if(i > this.width-1) {
					return false;
				}
				if(this.board[s.getTopLeftY()][i]) {
					return false;
				} 
			}
		} else {
//			if(s.getTopLeftY() + s.getLength() > this.height) {
//				return false;
//			}
			for(int i = s.getTopLeftY(); i < s.getTopLeftY() + s.getLength(); ++i) {
				if(i > this.height-1) {
					return false;
				}
				if(this.board[i][s.getTopLeftX()]) {
					return false;
				} 
			}
		}
		return true;
	}

	@Override
	public void printRadar() {
		//		for(int i = 0; i < this.height; ++i) {
		//			for(int j = 0; j < this.width; ++j) {
		//				if(!this.radar[i][j]) {
		//					System.out.print(".");
		//				}
		//				if(this.board[i][j] && this.radar[i][j]) {
		//					System.out.print("X");
		//				}
		//				if(!this.board[i][j] && this.radar[i][j]) {
		//					System.out.print("o");
		//			}
		//		}
		for(int i = 0; i < this.height; ++i) {
			for(int j = 0; j < this.width; ++j) {
				if(this.radar[i][j] == 0) {
					System.out.print(".");
				}
				else if(this.radar[i][j] == 1) {
					System.out.print("o");
				}
				else {
					System.out.print("X");
				}
			}
			System.out.println();
		}
		System.out.println("---------");
	}
}
