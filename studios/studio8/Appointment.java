package studio8;

public class Appointment {
	
	private Date date;
	private Time time;
	private String event;
	private String person;

	public Appointment(Date date, Time time, String event, String person) {
		this.date = date;
		this.time = time;
		this.event = event;
		this.person = person;
	}
	
	public Date getDate() {
		return date;
	}

	public Time getTime() {
		return time;
	}

	public String getEvent() {
		return event;
	}

	public String getPerson() {
		return person;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((date == null) ? 0 : date.hashCode());
		result = prime * result + ((event == null) ? 0 : event.hashCode());
		result = prime * result + ((person == null) ? 0 : person.hashCode());
		result = prime * result + ((time == null) ? 0 : time.hashCode());
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
		Appointment other = (Appointment) obj;
		if (date == null) {
			if (other.date != null)
				return false;
		} else if (!date.equals(other.date))
			return false;
		if (event == null) {
			if (other.event != null)
				return false;
		} else if (!event.equals(other.event))
			return false;
		if (person == null) {
			if (other.person != null)
				return false;
		} else if (!person.equals(other.person))
			return false;
		if (time == null) {
			if (other.time != null)
				return false;
		} else if (!time.equals(other.time))
			return false;
		return true;
	}

	public static void main(String[] args) {
		Date d1 = new Date(11,10,2018,false);
		Time t1 = new Time(14,30,false);
		Appointment a1 = new Appointment(d1,t1,"movie","April");
		System.out.println(a1);
	}

	@Override
	public String toString() {
		return "\n" + "I have an appointment with " + this.getPerson() + " for " + this.getEvent() + " " + this.getTime() + " " + this.getDate();
	}

}
