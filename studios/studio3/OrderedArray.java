package studio3;

public class OrderedArray<T extends Comparable<T>> implements PriorityQueue<T> {

	public T[] array;
	private int size;
	
	@SuppressWarnings("unchecked")
	public OrderedArray(int maxSize) {
		array = (T[]) new Comparable[maxSize];
		size = 0;
	}
	
	@Override
	public boolean isEmpty() {
		if(this.size == 0) {
			return true;
		}
		return false;
	}

	@Override
	public void insert(T thing) {
		this.size = this.size + 1;
		int location = 0;
		for(T othing: this.array) {
			if(othing.compareTo(thing)>0) {
				location = 
			}
		}
		
	}
	
	@Override
	public T extractMin() {
		T
	}

}
