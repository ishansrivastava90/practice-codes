import java.util.Stack;

public class ValidParentheses {

    public String convert(String parentheses) {
        Stack<String> s = new Stack<>();
        for (int i = 0; i < parentheses.length(); ++i) {
            String curr = parentheses.substring(i, i+1);
            if (curr.equals("(")) {
                s.push(curr);                
            }
            else {
                StringBuilder sb = new StringBuilder();
                while (!s.isEmpty() && !s.peek().equals("(")) {
                    String stTop = s.pop();
                    sb.insert(0, stTop); // Prepending the strings
                }
                if (s.isEmpty()) {
                    s.push(sb.toString());
                    continue;
                }

                // Not empty implies starting bracket has been found
                String stTop = s.pop();
                s.push(stTop + sb.toString() + curr);
                //System.out.println("11->"+ s.peek());
            }            
        }

        
        StringBuilder sb = new StringBuilder();
        while (!s.isEmpty()) {
            String top = s.pop();
            if (top.equals("(")) {
                continue;
            }
            sb.insert(0, top);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        ValidParentheses vp = new ValidParentheses();
        System.out.println("(()) -> " + vp.convert("(())"));        
        System.out.println("((()) -> " + vp.convert("((())"));
        System.out.println("(()(()) -> " + vp.convert("(()(())"));
        System.out.println("(()(()))) -> " + vp.convert("(()(())))"));    
    }
    
}
