package scheduler;

import java.util.Comparator;

public class Event {

	public static final int end = 0;
	public int start;

	public Event(int scheduleStart, int scheduleEnd) {
		// TODO Auto-generated constructor stub
	}
	
	public static final Comparator<Event> compareOnStartTime() {
		return new Comparator<Event>() {

			@Override
			public int compare(Event e1, Event e2) {
				return e1.start - e2.start;
			}
		};
	}
	
	public static final Comparator<Event> compareOnEndTime() {
		return new Comparator<Event>() {

			@Override
			public int compare(Event e1, Event e2) {
				return e1.end - e2.end;
			}
		};
	}
	
}