package studio8;

import java.util.HashSet;
import java.util.Set;

public class Time implements Working{
	
	private final int hour;
	private final int minute;
	private final boolean isTwelve;
	
	public Time(int hour, int minute, boolean isTwelve) {
		this.hour = hour;
		this.minute = minute;
		this.isTwelve = isTwelve;
	}

	public int getHour() {
		return hour;
	}

	public int getMinute() {
		return minute;
	}

	public boolean isTwelve() {
		return isTwelve;
	}
	
	public boolean isEarilierThan(Time other) {
		if(this.getHour()*60 + this.getMinute()*1 < other.getHour()*60 + other.getMinute()*1) {
			return true;
		}
		else {
			return false;
		}
	}

	public static void main(String[] args) {
		Time time1 = new Time(3,19,false);
		Time time2 = new Time(3,20,true);
		System.out.println(time1.equals(time2));
		System.out.println(time1.isEarilierThan(time2));
		
		Set<Time> timeSet = new HashSet<Time>();
		timeSet.add(new Time(3,19,false));
		timeSet.add(new Time(3,19,false));
		System.out.println("Time Set has " + timeSet);
	}

	@Override
	public String toString() {
		if(this.isTwelve) {
			return "at " + hour + ":" + minute + " (12-hour)";
		}
		else {
			return "at " + hour + ": " + minute + " (24-hour)";
		}
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + hour;
		result = prime * result + (isTwelve ? 1231 : 1237);
		result = prime * result + minute;
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
		Time other = (Time) obj;
		if (hour != other.hour)
			return false;
		if (isTwelve != other.isTwelve)
			return false;
		if (minute != other.minute)
			return false;
		return true;
	}

	@Override
	public boolean amWorking() {
		if(this.getHour()>9 && this.getHour()<17) {
			return true;
		}
		return false;
	}
	
}
