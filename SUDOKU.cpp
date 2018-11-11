#include <iostream>
#include<bits/stdc++.h>
#include<time.h>
#define UNASSIGNED 0
#define N 9
using namespace std;

void delay(int number_of_milliseconds)
{


    clock_t start_time = clock();
    while (clock() < start_time +number_of_milliseconds)
        ;
}
void star()
{
   for (int i=0;i<=19;i++)
    {  delay(200);
     cout<<"*"<<" ";
    }
cout<<endl;

}
bool FUL(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool InRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool InCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool InBox(int grid[N][N], int br, int bc, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+br][col+bc] == num)
                return true;
    return false;
}

bool IsSafe(int grid[N][N], int row, int col, int num)
{

    return !InRow(grid, row, num) &&
           !InCol(grid, col, num) &&
           !InBox(grid, row - row%3 , col - col%3, num);
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FUL(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {

        if (IsSafe(grid, row, col, num))
        {

            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
void PrintGrid(int grid[N][N])
{ system("CLS");
   star();
    for (int row = 1; row <= N; row++)
    {
       for (int col = 1; col <= N; col++)
        {cout<<grid[row-1][col-1]<<"   ";
        if(col%3==0)
            cout<<"  ";
        }
        cout<<endl;
        if(row%3==0)
           {
              star();
           }

    }


}


int main()
{
    int grid[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            grid[i][j]=0;
    }
    int t;
    cout<<"ENTER NO. OF DEFAULTS INPUT ";
    cin>>t;
    cout<<endl;
    while(t--)
    {
        int row,col,value;
        cout<<"ENTER ROW OF PREDEFINED DATA ";
        cin>>row;
        cout<<"\nENTER COL OF PREDEFINED DATA ";
        cin>>col;
        cout<<"\nENTER VALUE OF PREDEFINED DATA";
        cin>>value;
        cout<<endl;
        grid[row-1][col-1]=value;
    }
    PrintGrid(grid);
    cout<<"\n\n";
    cout<<"SOLVED GRID \n\n";
    if (SolveSudoku(grid) == true)
          PrintGrid(grid);
    else
    return 0;
}

