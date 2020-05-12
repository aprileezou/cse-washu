package studio6;

import cse131.NotYetImplementedException;
import sedgewick.StdDraw;

public class Circles {
	private static void recursiveCircles(double xCenter, double yCenter, double radius) {
		if(radius < 0.015) {
			return;
		}
		StdDraw.circle(xCenter, yCenter, radius);
		StdDraw.pause(500);
		recursiveCircles(xCenter-radius, yCenter, radius/3);
		recursiveCircles(xCenter+radius, yCenter, radius/3);
		recursiveCircles(xCenter, yCenter+radius, radius/3);
		recursiveCircles(xCenter, yCenter-radius, radius/3);
	}

	public static void main(String[] args) {
		StdDraw.setXscale(-1, +1);
		StdDraw.setYscale(-1, +1);
		recursiveCircles(0, 0, 0.5);
	}
}
