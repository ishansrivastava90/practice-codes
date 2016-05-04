package scheduler;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public final class EventScheduler {
	
	private List<Event> events;
	private int scheduleStart;
	private int scheduleEnd;
	
	public EventScheduler(int start, int end, List<Event> events) {
		this.scheduleStart = start;
		this.scheduleEnd = end;
		
		
		this.events = events;
		Collections.sort(this.events, Event.compareOnStartTime());
		
		if (events.isEmpty()) {
			events.add(new Event(scheduleStart, scheduleEnd));
			return;
		}
		
		events.add(0, new Event(scheduleStart, events.get(0).start));
		events.add(new Event(events.get(events.size()-1).end, scheduleEnd));
	}
	
	public List<Event> getAvailableEventSlots(int duration) {
		List<Event> availableEvents = new ArrayList<>();
		
		for (int ind = 1; ind < events.size(); ++ind) {
			if (events.get(ind).start - events.get(ind-1).end >= duration) {
				availableEvents.add(events.get(ind));
			}			
		}
		return availableEvents;
	}
	
	public boolean bookSlot(Event slot) {
		// Input sanitation
		
		return false;
	}

}
