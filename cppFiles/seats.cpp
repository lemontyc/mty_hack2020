#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>

// este es un test para 50% de capacidad
// cambios: se cerea una funcion para la l'ogica

int position(int i,int j,int n,int m){
    return i*m+j;
}


int seatsFunctions(std::vector<char>& originalVector, int percentage, int n, int m, bool second){
   
    std::stack<int> seats; 
    int center = 0;
    if (!second)
        center = position(n/2,m/2,n,m);
    else
        center = position((n+1)/2,(m+1)/2,n,m);
    
    int currentSeat = 0;


    seats.push(center);
    originalVector[center] = 0x20;
    percentage --;
    

    while (!seats.empty() && percentage > 0)
    {
        currentSeat = seats.top();
        seats.pop();
        
        // bottom seat
        if ((currentSeat + (2*m) ) <= originalVector.size() && originalVector[currentSeat + (2*m)] == 0x58 && percentage > 0)
        {
            originalVector[currentSeat + (2*m) ] = 0x20;
            seats.push(currentSeat + (2*m));
            percentage --;

        }
        
        // right seat
        if ((currentSeat/m) == ((currentSeat+2)/m) && originalVector[currentSeat+2] == 0x58 && percentage > 0)
        {
            originalVector[currentSeat+2] = 0x20;
            seats.push(currentSeat+2);
            percentage --;
            
        }

        // up seat
        if (((currentSeat/m)) == ((currentSeat-2)/m) && originalVector[currentSeat-2] == 0x58 && percentage > 0)
        {
            originalVector[currentSeat-2] = 0x20;
            seats.push(currentSeat-2);
            percentage --;

        }

        // left seat
        if ((currentSeat - (2*m) ) >= 0 && originalVector[currentSeat - (2*m)] == 0x58 && percentage > 0)
        {
            originalVector[currentSeat - (2*m)] = 0x20;
            seats.push(currentSeat - (2*m));
            percentage --;

        }
        
        // Brecking loop and returning 0
        if (percentage <= 0)
            return 0;
    }
    

    
   return percentage; 
}


int main(){

    int n,m,p; //rows,colums

    std::cin >> n >> m >> p;

    std::vector<char> myseats (n*m,0x58);

    p = (p * m* n) / 100;

    int aux = seatsFunctions(myseats,p,n,m,false);

    if (aux > 0)
    {
        seatsFunctions(myseats,aux,n,m,true);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << myseats[position(i,j,n,m)] << " ";
        }
        std::cout <<std::endl;
    }
}

