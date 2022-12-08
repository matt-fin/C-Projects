//Matthew Finamore 2022
#include <iostream>
#include <vector>
using namespace std;

int main() { 
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
  int moves = (n%2 == 0);
   // The initial value of to depends on whether n is odd or even

   int close = (n % 2 == 0 ? 2 : 1), far = (n % 2 == 0 ? 1 : 2); //if n is an odd integer, far=2 & close=1. If n is even, then far=1 and close=2.
   int from = 0, to = close, candidate = 1, move = 0;
   // Initialize the towers
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);
   
   while (t[1].size() < n+1) { // While t[1] does not contain all of the rings 
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n"; // Shows the moves in relation to the ring and tower letters
      
      t[to].push_back(t[from].back()); // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[from].pop_back();

      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      if (t[(to+1) % 3].back() < t[(to+2) % 3].back())
       from = (to+1) % 3;
      else
         from = (to+2) % 3;
      candidate = t[from].back(); // candidate = the ring on top of the t[from] tower

// (Compare the candidate with the ring on the closer tower; the tower that is "closer" is dependent on whether n is odd or even)
      if (t[(from+close) % 3].back() > candidate) // To = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
         to = (from+close) % 3;
      else
         to = (from+far) % 3;
   }
   return 0;
}