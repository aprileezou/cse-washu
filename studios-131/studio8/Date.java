package studio8;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import exercises8.Point;

public class Date implements Working{
	
	private final int month;
	private final int day;
	private final int year;
	private final boolean isHoliday;
	
	public Date(int month, int day, int year, boolean isHoliday) {
		this.month = month;
		this.day = day;
		this.year = year;
		this.isHoliday = isHoliday;
	}

	public int getMonth() {
		return month;
	}

	public int getDay() {
		return day;
	}

	public int getYear() {
		return year;
	}

	public boolean isHoliday() {
		return isHoliday;
	}
	
	public boolean isEarlierThan(Date other) {
		if(this.getYear()*365 + this.getMonth()*12 + this.getDay()*1 <
				other.getYear()*365 + other.getMonth()*12 + other.getDay()*1) {
			return true;
		}
		else {
			return false;
		}
	}

	public static void main(String[] args) {
		Date date1 = new Date(3,19,1996,false);
		Date date2 = new Date(6,5,1995,false);
		System.out.println(date1.equals(date2));
		System.out.println(date1.isEarlierThan(date2));
		
		Date date3 = new Date(3,19,1996,false);
		Date date4 = new Date(6,1,1995,true);
		Date date5 = new Date(10,1,1996,true);
		
		List<Date> dateList = new LinkedList<Date>();
		dateList.add(date1);
		dateList.add(date2);
		dateList.add(date3);
		dateList.add(date4);
		dateList.add(date5);
		dateList.add(new Date(8,1,1995,true));
		dateList.add(date1);
		
		System.out.println("Date List has " + dateList);
		
		HashSet<Date> set = new HashSet<Date>();
		set.add(date1);
		set.add(date2);
		set.add(date1);
		System.out.println("Date Set has " + set);
	}

	@Override
	public String toString() {
		if (this.isHoliday) {
			return "on " + month + "/" + day + "/" + year + ", which is a holiday";
		}
		else {
			return "on " + month + "/" + day + "/" + year + ", which is not a holiday";
		}
		
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + day;
		result = prime * result + month;
		result = prime * result + year;
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
		Date other = (Date) obj;
		if (day != other.day)
			return false;
		if (month != other.month)
			return false;
		if (year != other.year)
			return false;
		return true;
	}

	@Override
	public boolean amWorking() {
		if(this.getDay()%2 == 0) {
			return false;
		}
		return true;
	}

}
