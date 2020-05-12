package studio6;

import java.awt.Color;

import sedgewick.StdDraw;

public class CantorStool {
	public static void recursiveCantor(double x, double y, double hw, double hh) {
		if(hw < 1.0/9.0) {
			StdDraw.setPenColor(Color.GRAY);
			StdDraw.filledRectangle(x-2.0/3.0*hw, y-hh, hw/3, hh*2);
			StdDraw.filledRectangle(x+2.0/3.0*hw, y-hh, hw/3, hh*2);
			StdDraw.setPenColor(Color.BLACK);
			StdDraw.rectangle(x-2.0/3.0*hw, y-hh, hw/3, hh*2);
			StdDraw.rectangle(x+2.0/3.0*hw, y-hh, hw/3, hh*2);
			return;
		}

		StdDraw.setPenColor(Color.GRAY);
		StdDraw.filledRectangle(x, y, hw, hh);
		StdDraw.setPenColor(Color.BLACK);
		StdDraw.rectangle(x, y, hw, hh);

		recursiveCantor(x-2.0/3.0*hw, y-3.0/2.0*hh, hw/3, hh/2);
		recursiveCantor(x+2.0/3.0*hw, y-3.0/2.0*hh, hw/3, hh/2);

	}


	public static void main(String[] args) {
		StdDraw.setXscale(-1, +1);
		StdDraw.setYscale(-1, +1);
		recursiveCantor(0, 0.5, 1, 0.5);
	}
}