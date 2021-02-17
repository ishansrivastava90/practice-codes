package Leetcode;

import java.util.Map;

import java.util.HashMap;

public class ExamRoom {

    private class Seat {
        int Predecessor;
        int Successor;

        public Seat(int p, int s) {
            Predecessor = p;
            Successor = s;
        }
    }

    private Map<Integer,Seat> SeatChart; 
    int StartSeat;
    int TotalSeats;
    public ExamRoom(int N) {
        SeatChart = new HashMap<>();
        StartSeat = -1; // Room is empty;
        TotalSeats = N;
    }

    // Seats an incoming student in the room.
    public int seat() {
        if (SeatChart.isEmpty()) {
            SeatChart.put(0, new Seat(-1, -1)); // Hypothetical successor to make the math work out!
            StartSeat = 0;
            //printSeatChart();
            return StartSeat;
        }

        int maximumDist = Integer.MIN_VALUE;
        int beginSeat = -1;
        int endSeat = -1;
        
        int prevSeat = StartSeat;
        int currSeat;
        while (SeatChart.containsKey(prevSeat) && (currSeat = SeatChart.get(prevSeat).Successor) != -1) { // Reached the end of seating chart;
            // if (currSeat == -1) {
            //     // Reached the end of the seating chart
            //     break;
            // }
            int currDistance = getDistanceFromClosestSeat(prevSeat, currSeat);
            if (currDistance > maximumDist) {
                maximumDist = currDistance;
                beginSeat = prevSeat;
                endSeat = currSeat;
            }
            prevSeat = currSeat;
        }

        int incomingSeat = -1;
        if (endSeat != -1 && beginSeat != -1) {
            incomingSeat = (int)(endSeat - (endSeat - beginSeat)/2.0); // will downcast to use floor value
        }

        //Compare start and end distance if 1st and last seats are not occupied
        if (StartSeat > 0 && StartSeat - 0 >= maximumDist) {
            maximumDist = StartSeat - 0;
            incomingSeat = 0;
            beginSeat = -1;
            endSeat = StartSeat;
        }
        if ((prevSeat < TotalSeats - 1) && (TotalSeats - 1 - prevSeat > maximumDist)) {
            maximumDist = TotalSeats - 1 - prevSeat;
            incomingSeat = TotalSeats - 1;
            beginSeat = prevSeat;
            endSeat = -1;
        }

        assert incomingSeat != -1;

        //Update the seatchart
        SeatChart.put(incomingSeat, new Seat(beginSeat, endSeat));
        if (beginSeat != -1)
            SeatChart.get(beginSeat).Successor = incomingSeat;
        if (endSeat != -1)
            SeatChart.get(endSeat).Predecessor = incomingSeat;

        // Update the start seat
        if (incomingSeat != -1 && incomingSeat < StartSeat)
            StartSeat = incomingSeat;

        //printSeatChart();

        return incomingSeat;
    }

    // Frees up a seat after the student leaves
    public void leave(int seat) {
        if (!SeatChart.containsKey(seat)) {
            return; // Seat was already empty
        }

        Seat leavingSeat = SeatChart.get(seat);
        if (leavingSeat.Predecessor != -1) {
            SeatChart.get(leavingSeat.Predecessor).Successor = leavingSeat.Successor;
        }
        if (leavingSeat.Successor != -1) {
            SeatChart.get(leavingSeat.Successor).Predecessor = leavingSeat.Predecessor;
        }

        // Also update if leaving seat is the start seat
        if (seat == StartSeat) {
            StartSeat = leavingSeat.Successor;
        }
        SeatChart.remove(seat);

        //printSeatChart();
    }

    private int getDistanceFromClosestSeat(int seat1, int seat2) {
        if (seat1 > seat2) {
            int b = seat2;
            seat2 = seat1;
            seat1 = b;
        }

        int potentialSeat = (int)(seat2 - (seat2 - seat1)/2.0);
        return Math.min(seat2 - potentialSeat, potentialSeat - seat1);
    }
    private void printSeatChart() {
        System.out.println("StartSeat: " + StartSeat);

        int prevSeat = StartSeat;
        int currSeat;
        System.out.println(StartSeat + " ==> [" + SeatChart.get(StartSeat).Predecessor +", " + SeatChart.get(StartSeat).Successor +"]");
        while (SeatChart.containsKey(prevSeat) && (currSeat = SeatChart.get(prevSeat).Successor) != -1) { // Reached the end of seating chart;        
            System.out.println(currSeat + " ==> [" + SeatChart.get(currSeat).Predecessor +", " + SeatChart.get(currSeat).Successor +"]");
            prevSeat = currSeat;
        }
    }

    public static void main(String[] args) {
        ExamRoom ex = new ExamRoom(10);
        System.out.println(ex.seat());
        System.out.println(ex.seat());
        System.out.println(ex.seat());
        System.out.println(ex.seat());
        ex.leave(4);
        System.out.println(ex.seat());
    }
    
}
