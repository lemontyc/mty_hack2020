#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
#include <stack>

int main(){
    
    int n,m,p; //rows,colums
    int counter = 1;
    std::stack<std::pair<int,int>> myseats;
    int seats[10][10];

    std::cin >> n >> m >> p;
    n--;
    m--;

    std::pair <int,int> center;
    std::pair <int,int> currentSeat;
    
    for (char i = 0; i < 10; i++)
    {
        for (char j = 0; j < 10; j++)
        {
            seats[i][j] = 0;
        }
        
    }

    myseats.push(std::pair<int,int>((n/2),(m/2)));

    seats[n/2][n/2] = counter++;
    p--;
     
    while ((!myseats.empty()) && (p > 0))
    {   
        center = myseats.top();
        myseats.pop();

        // Left seat
        if( center.first + 2 <= n && seats[center.first + 2][center.second] == 0 && p > 0){
            seats[center.first + 2][center.second] = counter++;
            // Saving actual seat
            currentSeat.first = center.first + 2;
            currentSeat.second = center.second;
            myseats.push(currentSeat);
            p--;
        }

        // up seat
        if (center.second + 2 <= m && seats[center.first][center.second + 2] == 0 && p > 0){
            seats[center.first][center.second + 2] = counter++;
            currentSeat.first = center.first;
            currentSeat.second = center.second + 2;
            myseats.push(currentSeat);
            p--;
        }
        //rigth seat
        if (center.first - 2 >= 0 && seats[center.first - 2][center.second] == 0 && p > 0){
            seats[center.first - 2][center.second] = counter++;
            currentSeat.first = center.first - 2;
            currentSeat.second = center.second;
            myseats.push(currentSeat);
            p--;
        }
        //bottom seat
        if (center.second - 2 >= 0 && seats[center.first][center.second - 2] == 0 && p > 0){
            seats[center.first][center.second - 2] = counter++;
            currentSeat.first = center.first;
            currentSeat.second = center.second - 2;
            myseats.push(currentSeat); 
            p--;
        }
    } 

    for (char i = 0; i < 10; i++)
    {
        for (char j = 0; j < 10; j++)
        {
            std::cout << seats[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

    
}

