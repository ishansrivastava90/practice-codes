import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;

/**
 *  https://leetcode.com/discuss/interview-question/483660/google-phone-currency-conversion
 *  https://leetcode.com/discuss/interview-question/1335225/Find-best-exchange-rate-from-currency1-to-currency2
    array of currency conversion rates. E.g. ['USD', 'GBP', 0.77] which means 1 USD is equal to 0.77 GBP
    an array containing a 'from' currency and a 'to' currency
    Given the above parameters, find the conversion rate that maps to the 'from' currency to the 'to' currency.
    Your return value should be a number.

    Example:
    You are given the following parameters:

    Rates: ['USD', 'JPY', 110] ['US', 'AUD', 1.45] ['JPY', 'GBP', 0.0070]
    To/From currency ['GBP', 'AUD']
    Find the rate for the 'To/From' currency. In this case, the correct result is 1.89.

    Similar ques:
    https://leetcode.com/problems/evaluate-division/

 */
public class CurrXChange {
    
    private class Rate {
        String srcCurr;
        String tCurr;
        double value;

        public Rate(String srcCurr, String tCurr, double val) {
            this.srcCurr = srcCurr;
            this.tCurr = tCurr;
            this.value = val;
        }
    }
    
    HashMap<String, List<Rate>> rateAdjMap;
    
    public CurrXChange() {
        this.rateAdjMap =  new HashMap<>();
    }


    // DFS on directed graph where edges signify rate b/w 2 currencies.
    // TODO: Possible use undirected as rate b/w A & B implies 1/rate b/w B & A 
    public double findBestRateFromXtoY(Rate[] rates, String fromCurr, String toCurr) {
        buildGraph(rates);

        Set<String> visited = new HashSet<>();
        return findBestRateFromXtoYInner(fromCurr, toCurr, visited);
    }

    private double findBestRateFromXtoYInner(String currency, String toCurr, Set<String> visited) {
        if (currency == toCurr) {
            return 1.0;
        }
        if (visited.contains(currency)) {
            return -1.0;
        }
        visited.add(currency);
        double rate = -1.0;
        for (Rate r : this.rateAdjMap.get(currency)) {
            if (visited.contains(r.tCurr)) {
                continue;
            }
            double res = findBestRateFromXtoYInner(r.tCurr, toCurr, visited);
            if (res != -1.0) {
                rate = Math.max(rate, res * r.value);
            }
        }
        visited.remove(currency);
        return rate == -1.0 ? -1.0 : rate;
    }

    // Incomplete
    // Using Djikstra's is 1 option but it can't handle negative weights. So, it will only
    // work if all rates in the graph are < 1 since log(r) < 0 and we multiply by -1 to 
    // convert to shortest path problem.
    // Negative weight cycles that infinitely reduce the path value also pose a problem.
    public List<Rate> findBestRate(Rate[] rates, String currency) {
        buildGraph(rates);
        
        HashMap<String, Double> bestRatesFromX = new HashMap<>();
        for (String c : this.rateAdjMap.keySet()) {
            bestRatesFromX.put(c, Double.MAX_VALUE);
        }

        Set<String> visited = new HashSet<String>();
        visited.add(currency);
        
        bestRatesFromX.put(currency, 0.0); // log(1)

        PriorityQueue<Rate> pq = new PriorityQueue<>((Rate r1, Rate r2) -> Double.compare(r1.value, r2.value));
        pq.add(new Rate("", currency, 0.0));

        while(!pq.isEmpty()) {
            Rate r = pq.poll();
            if (visited.contains(r.tCurr))
                continue;
            if (bestRatesFromX.get(r.tCurr) > r.value) {
                bestRatesFromX.put(r.tCurr, r.value);
            }
            visited.add(r.tCurr);

            for (Rate nextRate: rateAdjMap.get(r.tCurr)) {
                if (visited.contains(nextRate.tCurr)) {
                    continue;
                }
                // Take log and multiply by -1 to convert maximum product to shortest sum
                // w1 * w2 * w3 ==> log(w1) + log(w2) + log(w3) ==> -log(w1) + (-log(w2)) + (-log(w3))
                pq.add(new Rate("", nextRate.tCurr, r.value - Math.log(nextRate.value)));
            }
        }

        List<Rate> bestRates = new ArrayList<>();
        for (String c : bestRatesFromX.keySet()) {
            bestRates.add(new Rate(currency, c, Math.exp(-1*bestRatesFromX.get(c)));
        }
        return bestRates;
    }


    // Use Bellman Ford
    public List<Rate> findBestRateWithNegativeCycles(Rate[] rates, String currency) {
        buildGraph(rates);

        int nCurrencies = this.rateAdjMap.size(); // vertices
        int nRates = rates.length; // edges

        HashMap<String, Double> bestRatesFromX = new HashMap<>();
        for (String c : this.rateAdjMap.keySet()) {
            bestRatesFromX.put(c, Double.MAX_VALUE);
        }

        HashMap<String, String> parents = new HashMap<>();

        bestRatesFromX.put(currency, 0.0);
        parents.put(currency, null); // Root
        boolean converged = false;
        for (int i = 0; i < nCurrencies; ++i) {
            converged = true;
            for (int j = 0; j < nRates; ++j) {
                String from = rates[j].srcCurr;                
                String to = rates[j].tCurr;

                if (bestRatesFromX.get(from) - Math.log(rates[j].value) < bestRatesFromX.get(to)) {
                    bestRatesFromX.put(to, bestRatesFromX.get(from) - Math.log(rates[j].value));
                    parents.put(to, from);
                    converged = false;
                }
            }
            if (converged)
                break;
        }

        List<String> cycle = new ArrayList<>();
        for (int j = 0; j < nRates; ++j) {
            String from = rates[j].srcCurr;                
            String to = rates[j].tCurr;

            if (bestRatesFromX.get(from) - Math.log(rates[j].value) < bestRatesFromX.get(to)) {
                // Cycle detected

                cycle.add(to);
                String p = parents.get(to);
                while (p != null) {
                    cycle.add(p);
                    p = parents.get(p);
                }
                break;
            }
        }

        if (!cycle.isEmpty()) {
            for (String cycleLink : cycle) {
                System.out.println(cycleLink);
            }
            return null;
        }
        List<Rate> bestRates = new ArrayList<>();
        for (String c : bestRatesFromX.keySet()) {
            bestRates.add(new Rate(currency, c, Math.exp(-1*bestRatesFromX.get(c)));
        }
        return bestRates;
    }

    private void buildGraph(Rate[] rates) {
        this.rateAdjMap.clear();
        for (Rate r : rates) {
            String srcCurrency = r.srcCurr;
            List<Rate> srcRates = rateAdjMap.getOrDefault(srcCurrency, new ArrayList<Rate>());
            srcRates.add(r);
            rateAdjMap.put(srcCurrency, srcRates);
        }
    }
}
