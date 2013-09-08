//Joshua Herman
//sudukoSolver.cpp

//type ./a.out to run it

#include <iostream>
using namespace std;
#include "sudukoSolver.h"

int main()
{
  
  //create 2d array for board
  Suduko suduko;
  int option;
  cout<<"1.  Insert coords and numbers"<<endl
      <<"2.  Type out grid format (type 0 for blank space)"<<endl
      <<"Option: ";
  cin>>option;
  if(option==1)
    suduko.insert();
  if(option==2)
    suduko.typeGrid();
  cout<<"Numbers Given"<<endl;
  cout<<suduko<<endl;
  cout<<"--------------------------"<<endl;
  if(suduko.trys(0,0))
  {
    cout<<suduko<<endl;
  }
  else
    cout<<"fail"<<endl;
  return 0;
}

