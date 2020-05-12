package studio8;

import java.util.LinkedList;

public class Calendar {
	
	private LinkedList<Appointment> calendar;

	public Calendar(LinkedList<Appointment> calendar) {
		this.calendar = calendar;
	}
	
	public void addAppointment(Appointment app){
		this.calendar.add(app);
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((calendar == null) ? 0 : calendar.hashCode());
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
		Calendar other = (Calendar) obj;
		if (calendar == null) {
			if (other.calendar != null)
				return false;
		} else if (!calendar.equals(other.calendar))
			return false;
		return true;
	}

	public static void main(String[] args) {
		Date d1 = new Date(11,10,2018,false);
		Time t1 = new Time(14,30,false);
		Appointment a1 = new Appointment(d1,t1,"movie","April");
		
		Date d2 = new Date(11,11,2018,true);
		Time t2 = new Time(20,00,false);
		Appointment a2 = new Appointment(d2,t2,"forest park","Yuwen");
		
		Calendar Nov = new Calendar(new LinkedList<Appointment>());
		Nov.addAppointment(a1);
		Nov.addAppointment(a2);
		System.out.println(Nov);
		
	}

	@Override
	public String toString() {
		return "Calendar for April: " + "\n" + calendar;
	}
	

}
