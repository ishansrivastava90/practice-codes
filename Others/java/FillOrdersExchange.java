import java.util.PriorityQueue;

public class FillOrdersExchange {

    /*
    https://leetcode.com/discuss/interview-question/1052406/robinhood-telephonic-interviewreject

    Given a stream of incoming "buy" and "sell" orders (as lists of limit price, quantity, and side, like
    ["155", "3", "buy"]), determine the total quantity (or number of "shares") executed.

    A "buy" order can be executed if there is a corresponding "sell" order with a price that is less than or
    equal to the price of the "buy" order.
    Similarly, a "sell" order can be executed if there is a corresponding "buy" order with a price that is
    greater than or equal to the price of the "sell" order.
    It is possible that an order does not execute immediately if it isn't paired to a counter party. In that 
    case, you should keep track of that order and execute it at a later time when a pairing order is found.
    You should ensure that orders are filled immediately at the best possible price. That is, an order 
    should be executed when it is processed, if possible. Further, "buy" orders should execute at the 
    lowest possible price and "sell" orders at the highest possible price at the time the order is handled.

    Note that orders can be partially executed.

    --- Sample Input ---

    orders = [
    ['150', '5', 'buy'],    # Order A
    ['190', '1', 'sell'],   # Order B
    ['200', '1', 'sell'],   # Order C
    ['100', '9', 'buy'],    # Order D
    ['140', '8', 'sell'],   # Order E
    ['210', '4', 'buy'],    # Order F
    ]

    Sample Output
    9
    */

    /*
    Solution Notes:
    Buy, price  - Selling price <= price -- lowest selling price
    Sell, price - Buying price >= price -- highest buying price

    Go through saved orders
    -- Find the lowest price for buy
    */

    public static class Order {
        int price;
        int quantity;
        String type;
        public Order(String t, int price, int q) {
            this.type = t;
            this.price = price;
            this.quantity = q;
        }
    }

    public static int numOrdersFilled(Order[] orders) {

        PriorityQueue<Order> buyOrders = new PriorityQueue<>((b1, b2) ->Integer.compare(b2.price, b1.price));   // Max on top   
        PriorityQueue<Order> sellOrders = new PriorityQueue<>((s1, s2) ->Integer.compare(s1.price, s2.price));  // Min on top

        int totalOrdersFilled = 0;
        for (Order order : orders) {            
            int remaining = order.quantity;

            if (order.type.equals("buy")) {

                // Attempt to fill the order immediately by matching with available sell orders
                // in ascending order of sell price
                while(!sellOrders.isEmpty() && sellOrders.peek().price <= order.price && remaining > 0) {
                    Order sellOrder = sellOrders.peek();
                    int available = sellOrder.quantity;
                    sellOrder.quantity = Math.max(0, sellOrder.quantity - remaining);
                    remaining = Math.max(0, remaining - available);
                    if (sellOrder.quantity == 0) {
                        sellOrders.poll();
                    }
                }
                
                // Update the filled orders counter
                totalOrdersFilled +=  order.quantity - remaining;

                // Add to the waiting queue for buy orders if order is not filled completely
                if (remaining > 0) {
                    order.quantity = remaining;
                    buyOrders.add(order);
                }
            }
            else if (order.type.equals("sell")) {
                
                // Attempt to fill the order immediately by matching with available buy orders
                // in descending order of buy price
                while(!buyOrders.isEmpty() && buyOrders.peek().price >= order.price && remaining > 0) {
                    Order buyOrder = buyOrders.peek();
                    int available = buyOrder.quantity;
                    buyOrder.quantity = Math.max(0, buyOrder.quantity - remaining);
                    remaining = Math.max(0, remaining - available);
                    if (buyOrder.quantity == 0) {
                        buyOrders.poll();
                    }
                }

                // Update the filled orders counter
                totalOrdersFilled +=  order.quantity - remaining;

                // Add to the waiting queue for sell orders if order is not filled completely
                if (remaining > 0) {
                    order.quantity = remaining;
                    sellOrders.add(order);
                }
            }
        }
        return totalOrdersFilled;
    }

    public static void main(String[] args) {
        Order[] orders = new Order[] {
            new Order("buy", 150, 5),
            new Order("sell", 190, 1),
            new Order("sell", 200, 1),
            new Order("buy", 100, 9),
            new Order("sell", 140, 8),
            new Order("buy", 210, 4)
        };

        System.out.println(numOrdersFilled(orders));
    }


    
}
