#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct p_pump {
    int p_amt;
    int next_dist;
} p_pump;

int main() {

    int num_p;
    cin >> num_p;

    p_pump p;
    vector<p_pump> pumps(num_p + 1);

    int a,b;
    for (int i = 0; i < num_p; ++i) { 
        scanf("%d%d",&a, &b);

        pumps.push_back(p_pump());
        pumps[i].p_amt = a;
        pumps[i].next_dist = b;

        pumps.push_back(p);

    }

    for (int i = 0; i < num_p; ++i) {
        cout << pumps[i].p_amt <<" " << pumps[i].next_dist <<endl;
    }

    int start = 0;
    int current = 0;
    int total_dist = 0;
    int total_petrol =0;

    bool trip_completed = false;

    while(!trip_completed && start < num_p ) {
        cout <<start << " "<< current;
        cout << total_dist + pumps[current].next_dist<< " " <<total_petrol + pumps[current].p_amt<< endl;
        if (total_dist + pumps[current].next_dist > total_petrol + pumps[current].p_amt ) {
            if (start != current) {
                total_dist -= pumps[start].next_dist;
                total_petrol -= pumps[start].p_amt;
            }
            cout<<"fsdf"<<endl;
            start += 1;            
            current = (start > current) ? start : current;
            continue;
        }

        total_dist += pumps[current].next_dist;
        total_petrol += pumps[current].p_amt;

        cout << total_dist<< " " << total_petrol<<endl;

        current = (current + 1) % num_p;

        if (current == start) {
            trip_completed = true;  
        }        
    }
    cout << start <<endl;

    return 0;
}

