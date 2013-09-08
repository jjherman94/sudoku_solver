//Joshua Herman
//sudukoSolver.h

#ifndef SUDUKOSOLVER_H
#define SUDUKOSOLVER_H

#include <iostream>
using namespace std;
class Suduko
{
  private:
    int **m_suduko;
    bool **m_given;
    
  public:
    //constructor
    Suduko()
    {
      m_suduko=new int *[9];
      for(int k=0; k<9; k++)
        m_suduko[k]=new int [9];
      
      m_given=new bool *[9];
      for(int k=0; k<9; k++)
        m_given[k]=new bool [9];
        
      for (int i=0; i < 9; i++)
      {
        for (int k=0; k < 9; k++)
        {
          m_suduko[k][i]=0;
          m_given[k][i]=false;
        }
      }      
    }
    
    //deconstructor
    ~Suduko()
    {
      for(int k=0; k<9; k++)
        delete [] m_suduko[k];
      delete [] m_suduko;
      m_suduko=NULL;
      
      for(int k=0; k<9; k++)
        delete [] m_given[k];
      delete [] m_given;
      m_given=NULL;
    }
    
    void insert()
    {
      int numToInput, xInput, yInput, tempNum;
      bool numWorks;
      do
      {
        cout<<"Input the number of values you want to assign"<<endl;
        cin>>numToInput;
        if(numToInput>81 || numToInput<0)
          cout<<"Invalid number given try again"
      }while(numToInput>81 || numToInput<0)
      cout<<"Input the coords then the number"<<endl;
      for(int i=0; i<numToInput; i++)
      {
        do
        {
          numWorks=true;
          cin>>xInput>>yInput>>tempNum;
          xInput=xInput-1;
          yInput=yInput-1;
          if(xInput>8 || xInput<0 || yInput>8 || yInput<0
             || tempNum<1 || tempNum>9)
          {
            cout<<"Invalid number given try again"<<endl;
            numWorks=false;
          }
          else
          {
            m_suduko[xInput][yInput]=tempNum;
            
            numWorks=valid(xInput, yInput);
            if(numWorks)
              m_given[xInput][yInput]=true;
            if(!numWorks)
            {
              cout<<"Invalid number given try again"<<endl;
              m_suduko[xInput][yInput]=0;
              m_given[xInput][yInput]=false;
            }
          }
        }while(!numWorks);
      }
      return;
    }
    
    void typeGrid()
    {
      bool correct;
      cout<<"Input grid of suduko"<<endl;
      for(int y=0; y<9; y++)
      {
        for(int x=0; x<9; x++)
        {
          cin>>m_suduko[x][y];
          if(m_suduko[x][y]!=0)
            m_given[x][y]=true;
        }
      }
      
      for(int y=0; y<9; y++)
      {
        for(int x=0; x<9; x++)
        {         
          if(m_suduko[x][y]!=0 && correct)
            correct=valid(x,y);
        }
      }
      if(!correct)
        cout<<"Invalid numbers given try again"<<endl;
      typeGrid();
      return;
    }
    
    
    bool valid(const int & xCoord, const int & yCoord)
    {
      //check row
      for(int i=0; i<9; i++)
      {
        if(m_suduko[xCoord][yCoord]==m_suduko[i][yCoord]
           && xCoord!=i)
          return false;
      }
      //check column
      for(int k=0; k<9; k++)
      {
        if(m_suduko[xCoord][yCoord]==m_suduko[xCoord][k]
           && yCoord!=k)
          return false;
      }
      
      //check 3x3 box
      for(int i=xCoord-xCoord%3; i<=(xCoord-xCoord%3+2); i++)
      {
        for(int j=yCoord-yCoord%3; j<=(yCoord-yCoord%3+2); j++)
        {
          if(m_suduko[xCoord][yCoord]==m_suduko[i][j]
             && !(xCoord==i && yCoord==j))
          {
            return false;
          }
        } 
      }
      return true;
    }
    
    bool trys(int xCoord, int yCoord)
    {
      bool ask;
      int x=xCoord, y=yCoord;
      if(!m_given[xCoord][yCoord])
      {
        for(int i=1; i<=9; i++)
        {
          m_suduko[xCoord][yCoord]=i;
          if(valid(xCoord, yCoord))
          {
            if(xCoord==8 && yCoord==8)
              return true;
            else
            {
              if(xCoord==8)
              {
                x=0;
                y=yCoord+1;
              }
              else
                x=xCoord+1;
              ask=trys(x,y);
              if(ask)
                return true;
            }
          }
        }    
        
      }
      else if(m_given[xCoord][yCoord])
      {
        if(xCoord==8 && yCoord==8)
          return true;
        else
        {
          if(xCoord==8)
          {
            x=0;
            y=yCoord+1;
          }
          else
            x=xCoord+1;
          ask=trys(x,y);
          if(ask)
            return true;
        }
      }
      if(!m_given[xCoord][yCoord])
        m_suduko[xCoord][yCoord]=0;
      return false;
    }

  friend ostream& operator<< (ostream& out, const Suduko & board)
  {
    for (int i=0; i < 9; i++)
    {
      for (int k=0; k < 9; k++)
      {
        out<<board.m_suduko[k][i]<<" ";
        if(k==2||k==5)
          out<<"  ";
      }
      out<<endl;
      if(i==2||i==5)
        out<<endl;
    }
    return out;
  }

};
#endif
