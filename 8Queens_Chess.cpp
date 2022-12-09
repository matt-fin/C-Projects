//Matthew Finamore 2021
#include <iostream>
using namespace std;
int main() {
  int b[8][8] = {0}; 
  int row, col = 0;
  int solution = 0;
  b[0][0] = 1;
nextColumn: //next column
  col++;
  
  if(col == 8){
    goto print; //check to see if we're in column 8, because then theres a solution
  } 
  row = -1; //brings the code to -1
nextRow:
  row++;
  if(row == 8){   //check to see if we're in row 8
    goto backtrack; // because if we're in row 8 we have to backtrack
  }   // because if we are, there is no valid location for the queen in that column

    for(int i=0; i<col; i++){ //row test
      if(b[row][i]==1) goto nextRow; // if we pass the row test, do the diagonal tests
    }
    for(int j=1; (row-j)>=0 && (col-j)>=0; j++){ //up diagonal test
      if(b[row-j][col-j]==1) goto nextRow;
    }
    for(int k=1; (row+k)<8 && (col-k)> -1; k++){ //down diagonal test
      if(b[row+k][col-k]==1) goto nextRow;
    }
      b[row][col]=1; //place a queen
      goto nextColumn; //next column 

    goto nextRow;
    b[row][col] = 1;   // only if we pass all our tests do we then place the queen
    goto nextColumn; //go to the next column and start again

backtrack:
  col--; //go back a column
  if(col==-1){
     return 0;
  }  //we need to check if we're in column -1
  row = 0; //because if we are, we've found all solutions
  while(b[row][col]!=1){  //if we're not in column -1
    row++;  // we need to find the queen in our current column
  }
  b[row][col]=0;   // erase that queen (change the 1 to a 0) and move to the next now
  goto nextRow;

print:
  solution++; //iterate the solution # every time it runs the loop
  cout<<"Solution: " << solution << endl;
  for(int l=0; l<8;l++){ 
    for(int m=0; m<8; m++){
       cout<<b[l][m]<< " "; // go through the rows and print each value in an 8x8 diagram 92 times
    }
    cout<<endl;
  }
goto backtrack; //brings the code back to the 'backtrack' statement until all runs are complete

return 0;
}