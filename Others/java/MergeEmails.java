import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.lang.String;

public class MergeEmails
{  
    public static HashMap<String, List<Set<String>>> merge(List<List<String>> contacts) {
        HashMap<String, List<Set<String>>> mp = new HashMap<String, List<Set<String>>>();
        for (List<String> contact: contacts) {
            if (contact.size() < 2) {
                continue;
            }
            String name = contact.get(0);
            Set<String> emails = new TreeSet<String>(contact.subList(1, contact.size()));
            if (!mp.containsKey(name)) {
                List<Set<String>> emailList = new ArrayList<Set<String>>();
                emailList.add(emails);
                mp.put(name, emailList);
            }
            else {
                // Name exists, Iterate through all sets and union them if intersection
                List<Set<String>> newEmailList = new ArrayList<Set<String>>();
                for (Set<String> mergedEmails : mp.get(name)) {
                    boolean intersects = false;
                    for (String email : mergedEmails) {
                        if (emails.contains(email)) {
                            emails.addAll(mergedEmails);
                            intersects = true;
                            break;
                        }
                    }
                    if (!intersects) {
                        newEmailList.add(mergedEmails);
                    }
                }
                newEmailList.add(emails);
                mp.put(name, newEmailList);
            }
        }
        return mp;
    }

    public static void main(String[] args) {
        List<List<String>> contacts = new ArrayList<>();
        contacts.add(Arrays.asList("A", "a1", "a2"));
        contacts.add(Arrays.asList("B", "a1", "b1"));
        contacts.add(Arrays.asList("A", "a3", "a4" ,"a5"));
        contacts.add(Arrays.asList("A", "a1", "a5", "a6"));
        contacts.add(Arrays.asList("A", "b1", "b2"));

        HashMap<String, List<Set<String>>> mp = merge(contacts);

        for(String name : mp.keySet()) {
            for (Set<String> emails : mp.get(name)) {
                System.out.println(name +"-> " + emails.toString());
            }
        }
    }
}