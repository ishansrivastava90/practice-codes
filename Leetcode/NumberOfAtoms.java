import java.lang.System;
import java.util.AbstractMap.SimpleEntry;
import java.util.Stack;
import java.util.TreeMap;

public class NumberOfAtoms {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        //System.out.println(countOfAtoms("H2O"));
        System.out.println(countOfAtoms("Mg(OH)2"));
        System.out.println(countOfAtoms("K4(ON(SO3)2)2"));
        
        return;    
    }

    public static String countOfAtoms(String formula) {
        Stack<SimpleEntry<String, Integer>> elementStack = new Stack<SimpleEntry<String,Integer>>();
        TreeMap<String, Integer> results = new TreeMap<>();
        
        // Populate the stack
        int i = 0;
        int openBrackets = 0;
        while(i <  formula.length()) {
            
            if (formula.charAt(i) == '(') {
                openBrackets++;
                elementStack.push(new SimpleEntry<String, Integer>("(", -1));
                i++;
            }
            else if (formula.charAt(i) == ')') {
                SimpleEntry<Integer, Integer> atomicCount = getAtomicCount(formula, i + 1);
                elementStack.push(new SimpleEntry<String, Integer>(")", atomicCount.getKey()));
                openBrackets--;
                resolveBrackets(elementStack);
                i = i + atomicCount.getValue() + 1;
                
                
            }
            else if (Character.isUpperCase(formula.charAt(i))) {
                String element = getElement(formula, i);
                SimpleEntry<Integer,Integer> atomicCount = getAtomicCount(formula, i + element.length());
                if (openBrackets > 0) {
                    elementStack.push(new SimpleEntry<String, Integer>(element, atomicCount.getKey()));
                }
                else {
                    if (!results.containsKey(element)) {
                        results.put(element, 0);
                    }
                    results.put(element, results.get(element) + atomicCount.getKey());
                }            
                i = i + element.length() + atomicCount.getValue();

            }
        }
        
        assert openBrackets == 0;

        // pop the stack
        while (!elementStack.empty()) {
            String element = elementStack.peek().getKey();
            Integer atomicity = elementStack.peek().getValue();
            if (!results.containsKey(element)) {
                results.put(element, 0);
            }
            results.put(element, results.get(element) + atomicity);
            elementStack.pop();
        }

        // Compile the results.
        String outputFormula = "";
        for (String element : results.keySet()) { // sorted by key
            outputFormula += element;
            int atomicity = results.get(element);
            if (atomicity > 1) {
                outputFormula += atomicity;
            }
        }
        return outputFormula;
    }

    
    private static void resolveBrackets(Stack<SimpleEntry<String, Integer>> elementStack) {
        // assert top element is always closing bracket
        assert elementStack.peek().getKey() == ")";
        Integer bracketAtomicMultiplier = elementStack.peek().getValue();
        elementStack.pop();

        Stack<SimpleEntry<String, Integer>> holdingStack = new Stack<SimpleEntry<String, Integer>>();
        while(!elementStack.empty()) {

            if (elementStack.peek().getKey() == "(") {
                elementStack.pop();
                break;
            }
            SimpleEntry<String, Integer> expandedElement = new SimpleEntry<>(
                elementStack.peek().getKey(),
                elementStack.peek().getValue() * bracketAtomicMultiplier
            );
            holdingStack.push(expandedElement);
            elementStack.pop();
        }

        while (!holdingStack.empty()) {
            elementStack.push(holdingStack.peek());
            holdingStack.pop();
        }
    }

    private static String getElement(String formula, int i) {
        int endIndex = i + 1;
        while (endIndex < formula.length() 
            && !Character.isUpperCase(formula.charAt(endIndex))
            && !Character.isDigit(formula.charAt(endIndex))
            && formula.charAt(endIndex) != '('
            && formula.charAt(endIndex) != ')') {
            endIndex++;
        }
        return formula.substring(i, endIndex);
    }

    private static SimpleEntry<Integer, Integer> getAtomicCount(String formula, int i) {
        int endIndex = i;
        while (endIndex < formula.length() 
            && Character.isDigit(formula.charAt(endIndex))
            && formula.charAt(endIndex) != '('
            && formula.charAt(endIndex) != ')') {
            endIndex++;
        }
        return endIndex == i
            ? new SimpleEntry<Integer,Integer>(1, 0)
            : new SimpleEntry<Integer, Integer>(Integer.valueOf(formula.substring(i, endIndex)), endIndex - i);
    }

}