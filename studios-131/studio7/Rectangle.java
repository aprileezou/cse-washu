package studio7;

public class Rectangle {

	//has a 
	//wigth
	//length
	private double wigth;
	private double length;
	private double xaxis;
	private double yaxis;


	public Rectangle(double wigth, double length, double xaxis, double yaxis) {
		super();
		this.wigth = wigth;
		this.length=length;
		this.xaxis=xaxis;
		this.yaxis=yaxis;
	}
	//area
	public double getArea() {
		return this.wigth*this.length;
	}
	//perimeter
	public double getPerimeter() {
		return 2*(this.wigth+this.length);
	}
	//compare the area
	public boolean larger(Rectangle x) {
		return x.getArea()<this.getArea();
	}
	//square of not
	public boolean isSquare() {
		return this.wigth==this.length;
	}

	//90
	public Rectangle inverseRec() {
		return new Rectangle(length,wigth,xaxis,yaxis);
	}

	//upper left hand (a,b)
	public boolean isInside(double xaxis2, double yaxis2) {
		boolean ain=xaxis2<(xaxis+wigth)&&xaxis2>xaxis;
		boolean bin=yaxis2>(yaxis-length)&&yaxis2<yaxis;
		return ain&&bin;
	}

	//intersection
	public boolean inter(Rectangle y) {
		boolean pa=isInside(y.xaxis,y.yaxis);
		boolean pb=isInside(y.xaxis+y.wigth,y.yaxis+y.length);
		boolean pc=isInside(y.xaxis,y.yaxis+y.length);
		boolean pd=isInside(y.xaxis+y.wigth,y.yaxis);
		return pa||pb||pc||pd;
	}

}
