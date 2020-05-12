package studio4;

import java.awt.Color;

import sedgewick.StdDraw;

public class Flag {

	
	public static void main(String[] args) {

		  double[] a = {0.35,0.5,0.66,0.5};
		  double[] b = {0.5,0.6,0.5,0.4};

		
		  StdDraw.setPenColor(Color.GREEN);
		  StdDraw.filledRectangle(0.5, 0.5, 0.3, 0.2);
		  StdDraw.setPenColor(Color.YELLOW);
		  
		  StdDraw.filledPolygon(a,b);
		  StdDraw.setPenColor(Color.BLUE);
		  StdDraw.filledCircle(0.5, 0.5, 0.08);

	}

}
