package finalproject;

import java.util.Arrays;

import cse131.NotYetImplementedException;

/**
 * @author Mariah Yelenick and Adam Kern
 * @version 11/18/18
 */
public class Ship {
	
	private int topLeftX;
	private int topLeftY;
	private int length;
	private boolean isHorizontal;
	private boolean[] ship;
	
	/**
	 * Create an instance of the ship class, recording all necessary information into
	 * any instance variables you choose to create
	 * 
	 * @param topLeftX the x coordinate of the ship's uppermost, leftmost space
	 * @param topLeftY the y coordinate of the ship's uppermost, leftmost space
	 * @param length the number of spaces the ship occupies
	 * @param isHorizontal if true, the ship is placed horizontally, else the ship is placed vertically
	 */
	public Ship(int topLeftX, int topLeftY, int length, boolean isHorizontal) {
//		int[][] ship = new int[topLeftX+length][topLeftY+length];
//		if(isHorizontal) {
//			for(int i = topLeftX; i < topLeftX+length; ++i) {
//				ship[i][topLeftY] = 1;
//			}
//		} else {
//			for(int j = topLeftY; j < topLeftY+length; ++j) {
//				ship[topLeftX][j] = 1;
//			}
//		}
		this.ship = new boolean[length];
		this.topLeftX = topLeftX;
		this.topLeftY = topLeftY;
		this.length = length;
		this.isHorizontal = isHorizontal;
	}
		
	public int getTopLeftX() {
		return topLeftX;
	}

	public int getTopLeftY() {
		return topLeftY;
	}

	public int getLength() {
		return length;
	}

	public boolean isHorizontal() {
		return isHorizontal;
	}

	public boolean[] getShip() {
		return ship;
	}

	/**
	 * Check if the ship has been sunk
	 * This should only be true if the ship was hit in all the spaces it occupies
	 * 
	 * @return true if the ship has been sunk
	 */
	public boolean isSunk() {
//		if(this.isHorizontal()) {
//			for(int i = this.topLeftX; i < this.topLeftX+this.length; ++i) {
//				if(this.ship[i][this.topLeftY] == 1) {
//					return false;
//				}
//			}
//		} else {
//			for(int j = topLeftY; j < topLeftY+length; ++j) {
//				if(this.ship[this.topLeftX][j] == 1) {
//					return false;
//				}
//			}
//		}
//		return true;
		for(int i = 0; i < this.length; ++i) {
			if(this.ship[i] == false) {
				return false;
			}
		}
		return true;
	}
	
	/**
	 * Check if the ship occupies a space at (x, y)
	 * Note: Be sure to update the hits array so that you can check if the ship is sunk!
	 * 
	 * @param x the x coordinate to shoot at
	 * @param y the y coordinate to shoot at
	 * @return true if this ship occupies that spot (hit), false otherwise (miss)
	 */
	public boolean isHit(int x, int y) {
//		if(this.getShip()[x][y] == 1) {
//			this.getShip()[x][y] = -1;
//			return true;
//		} else {
//			return false;
//		}
		if(this.isHorizontal()) {
			if((y == this.topLeftY) && (x < this.topLeftX + this.length) && (x >= this.topLeftX)) {
				this.ship[x-this.topLeftX] = true;
				return true;
			} else {
				return false;
			}
		} else {
			if((x == this.topLeftX) && (y < this.topLeftY + this.length) && (y >= this.topLeftY)) {
				this.ship[y-this.topLeftY] = true;
				return true;
			} else {
				return false;
			}
		}
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Ship other = (Ship) obj;
		if (isHorizontal != other.isHorizontal)
			return false;
		if (length != other.length)
			return false;
		if (!Arrays.equals(ship, other.ship))
			return false;
		if (topLeftX != other.topLeftX)
			return false;
		if (topLeftY != other.topLeftY)
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "Ship [topLeftX=" + topLeftX + ", topLeftY=" + topLeftY + ", length=" + length + ", isHorizontal="
				+ isHorizontal + ", ship=" + Arrays.toString(ship) + "]";
	}
	
	
}
