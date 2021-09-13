using System;
using System.Collections.Generic;

namespace c_ 
{
     public static class FindNumber
     {
        public static int findNum(List<int> arr, int k)
        {
            foreach (var item in arr) 
            {
                if (item == k) {
                    Console.WriteLine("YES");
                    return k;
                }
            }
            Console.WriteLine("NO");
            return -1;
        }
    }
}