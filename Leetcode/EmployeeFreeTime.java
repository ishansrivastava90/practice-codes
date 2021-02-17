package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Set;

public class EmployeeFreeTime {

    /*
    https://aaronice.gitbook.io/lintcode/sweep-line/employee-free-time
    We are given a list scheduleof employees, which represents the working time for each employee.
    Each employee has a list of non-overlappingIntervals, and these intervals are in sorted order.
    Return the list of finite intervals representing common, positive-length free time forallemployees, also in sorted order.
    */

    static class Interval {
        long StTime;
        long EndTime;
        int EmplId;

        public Interval(long st, long end, int employeeId) {
            StTime = st;
            EndTime = end;
            EmplId = employeeId;
        }

        @Override
        public boolean equals(Object other) {
            if (other == null || !(other instanceof Interval)) {
                return false;
            }
            
            Interval otherInterval = (Interval)other;
            return this.StTime == otherInterval.StTime
                && this.EndTime == otherInterval.EndTime;
        }
    }

    public static void main(String[] args) {
        // TestCase 1
        //[[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
        List<List<Interval>> intervals = new ArrayList<>();
        intervals.add(Arrays.asList(new Interval(1, 3, 0), new Interval(6, 7, 0)));
        intervals.add(Arrays.asList(new Interval(2, 4, 1)));        
        intervals.add(Arrays.asList(new Interval(2, 5, 2), new Interval(9, 12, 2)));

        List<Interval> result = getFreeIntervals(intervals);
        if (result.isEmpty())
        {
            System.out.println("HOLA!");
        }
        for (Interval i : result) {
            System.out.println(String.format(Locale.ROOT, "[%s, %s]", i.StTime, i.EndTime));
        }

        // Testcase 2
        //[[[1,2],[5,6]],[[1,3]],[[4,10]]]
        intervals.clear();        
        intervals.add(Arrays.asList(new Interval(1, 2, 0), new Interval(5, 6, 0)));
        intervals.add(Arrays.asList(new Interval(1, 3, 1)));        
        intervals.add(Arrays.asList(new Interval(4, 10, 2)));
        
        result = getFreeIntervals(intervals);
        if (result.isEmpty())
        {
            System.out.println("HOLA!");
        }
        for (Interval i : result) {
            System.out.println(String.format(Locale.ROOT, "[%s, %s]", i.StTime, i.EndTime));
        }

    }

    public static List<Interval> getFreeIntervals(List<List<Interval>> employeeSchedules) {

        // Convert Work hours into free time ranges
        List<Interval> globalFreeIntervals = new ArrayList<Interval>();
        int employeeId = 0;
        for (List<Interval> emp : employeeSchedules) {
            //List<Interval> freeTimes = new ArrayList<Interval>();
            long stTime = -1;
            for (Interval interval : emp) {
                long endTime = interval.StTime;
                //System.out.println("(" + stTime +", " + endTime +")");
                if (stTime < endTime) {
                    globalFreeIntervals.add(new Interval(stTime, endTime, employeeId));
                }
                stTime = interval.EndTime;
            }
            globalFreeIntervals.add(new Interval(stTime, Long.MAX_VALUE, employeeId));
            employeeId++;
        }

        // Sort all intervals by End time asc, then start time desc
        globalFreeIntervals.sort(new Comparator<Interval>(){
            @Override
            public int compare(Interval i1, Interval i2) {
                if (i1.EndTime == i2.EndTime) {
                    return i1.StTime == i2.StTime
                        ? 0
                        : i1.StTime < i2.StTime ? 1 : -1;
                }
                return i1.EndTime > i2.EndTime ? 1 : -1;
            }
        });

        globalFreeIntervals.sort((i1, i2) -> i1.EndTime > i2.EndTime ? 1 : -1);

        for (Interval i : globalFreeIntervals) {
            System.out.println(String.format(Locale.ROOT, "[%s, %s]", i.StTime, i.EndTime));
        }

        List<Interval> commonFreeIntervals = new ArrayList<Interval>();
        int totalEmpl = employeeSchedules.size();
        Set<Integer> inclEmployees = new HashSet<>();

        long currStTime = -1;
        long prevEndTime = -1;
        // Iterate through sorted intervals and compare
        for (int i = 0; i < globalFreeIntervals.size(); ++i) {
            //Interval j = findShortestInterval(i.EndTime, globalFreeIntervals);
            Interval currInterval = globalFreeIntervals.get(i);
            
            if (currInterval.EndTime == prevEndTime) {
                continue; // Any common interval would have already been found;
            }
            inclEmployees.clear();
            inclEmployees.add(currInterval.EmplId);

            Interval shortestInterval = null;
            for (int j = 0; j < globalFreeIntervals.size(); ++j) {
                Interval innerInterval = globalFreeIntervals.get(j);
                if (innerInterval.StTime < currInterval.EndTime) {
                    if(innerInterval.StTime >= currStTime) {
                        shortestInterval = shortestInterval == null
                            ? innerInterval
                            : innerInterval.StTime > shortestInterval.StTime ? innerInterval : shortestInterval;
                    }

                    // Track employees
                    inclEmployees.add(innerInterval.EmplId);
                }
            }
            System.out.println("Size of inclEmployees "+ inclEmployees.size());

            // Include in result if all employees had common interval
            if (inclEmployees.size() == totalEmpl && shortestInterval != null) {
                
            System.out.println("Shortest Interval "+ shortestInterval.StTime);
                Interval freeInterval = new Interval(shortestInterval.StTime, currInterval.EndTime, -1); // emplId doesn't matter;
                currStTime = currInterval.EndTime;

                if (freeInterval.StTime != -1 && freeInterval.EndTime != Long.MAX_VALUE) {
                    commonFreeIntervals.add(freeInterval);
                }
            };
            prevEndTime = currInterval.EndTime;
        }
        return commonFreeIntervals;
    }
    
}
