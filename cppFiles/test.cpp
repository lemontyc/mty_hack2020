#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>

int main(){
    
    int n,m; //rows,colums
    int counter = 0
    std::deque<int> myseats;
    int seats[10][10];
    std::pair <int,int> start( (n/2), (m/2) );
    
    for (char i = 0; i < 10; i++)
    {
        std::fill(seats[i][0],seats[0][10],0);
    }
    
    //center
    seats[start.first][start.second] = ++counter;
    // Left seat
    seats[start.first + 2][start.second] = ++counter;
    // up seat
    seats[start.first][start.second + 2] = ++counter;
    //rigth seat
    seats[start.first - 2][start.second] = ++counter;
    //bottom seat
    seats[start.first][start.second - 2] = ++counter;
    
}

