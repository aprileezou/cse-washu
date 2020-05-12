<<<<<<< HEAD
package studio7;

public class Point {

	public int x;
	public int y;

	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}

//     @Override
//	 public int hashCode() {
//    	 
//	}
//	
//
//	@Override
//	public boolean equals(Object obj) {
//		if (this == obj)
//			return true;
//		if (obj == null)
//			return false;
//		if (getClass() != obj.getClass())
//			return false;
//		Point other = (Point) obj;
//		if (x != other.x)
//			return false;
//		if (y != other.y)
//			return false;
//		return true;
//	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Point other = (Point) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "Point [x=" + x + ", y=" + y + "]";
	}
}
=======
package studio7;

public class Point {

	public int x;
	public int y;

	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}

    // @Override
	// public int hashCode() {
	// compute a hashcode here!
	//}
	

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Point other = (Point) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "Point [x=" + x + ", y=" + y + "]";
	}

}
>>>>>>> branch 'master' of https://aprileezou@bitbucket.org/cse247-s19/cse247-s19-students-jingxuan.zou.git
