package studio9;

import java.util.HashMap;
import java.util.Map;

import lab7.Student;

public class UniversityDatabase {
	
	private final Map<String, Student> map;

	public UniversityDatabase() {
		this.map = new HashMap<String, Student>();
	}

	public void addStudent(String accountName, Student student) {
		this.map.put(accountName, student);
	}
	
	public int getStudentCount() {
		return this.map.size();
	}
	
	public String lookupFullName(String accountName) {
		if(this.map.get(accountName) == null) {
			return null;
		} else {
			return this.map.get(accountName).getFullName();
		}		
	}
	
	public double getTotalBearBucks() {
		double sum = 0;
		for(String account:map.keySet()) {
			sum = sum + this.map.get(account).getBearBucksBalance();
		}
		return sum;
	}
	

}
