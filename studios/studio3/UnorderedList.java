package studio3;

import java.util.LinkedList;
import java.util.List;

public class UnorderedList<T extends Comparable<T>> implements PriorityQueue<T> {

	public LinkedList<T> list;
	
	public UnorderedList() {
		list = new LinkedList<T>();
	}
	
	@Override
	public boolean isEmpty() {
		if (this.list.isEmpty() == true) {
			return true;
		}
		return false;
	}

	@Override
	public void insert(T thing) {
		this.list.add(thing);
	}

	@Override
	public T extractMin() {
		T min = this.list.getFirst();
		for(T thing: this.list) {
			if(thing.compareTo(min)<0) {
				min = thing;
			}
		}
		this.list.remove(min);
		return min;
	}
	
	public static void main(String[] args) {
//		Integer a = 1;
//		Integer b = 5;
//		Double a = 3.14159269;
//		Double b = 2.7182818;
		String a = "Hello world!";
		String b = "goodbye, world!";
		System.out.println(a.compareTo(b));
	}

}
