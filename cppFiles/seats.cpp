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


int seatsFunctions(std::vector<int>& originalVector, int percentage, int n, int m){
   
    std::stack<int> seats; 
    int center = position(n/2,m/2,n,m);
    int currentSeat = 0;
    int counter = 1;

    seats.push(center);
    originalVector[center] = counter++;
    std::cout << "holix" << originalVector[center] << std::endl;
    std::cout << "holox" << center << std::endl;

    percentage--;

    while (!seats.empty() && percentage > 0)
    {
        currentSeat = seats.top();
        seats.pop();
        
        // bottom seat
        if ((currentSeat + (2*m) ) <= originalVector.size() && originalVector[currentSeat] == 0 && percentage > 0)
        {
            originalVector[currentSeat + (2*m) ] = counter++;
            seats.push(currentSeat + (2*m));
        }
        
        // right seat
        if ((currentSeat/m) == ((currentSeat+2)/m) && originalVector[currentSeat] == 0 && percentage > 0)
        {
            originalVector[currentSeat+2] = counter++;
            seats.push(currentSeat+2);
        }

        // up seat
        if (((currentSeat/m)) == ((currentSeat-2)/m) && originalVector[currentSeat] == 0 && percentage > 0)
        {
            originalVector[currentSeat-2] = counter++;
            seats.push(currentSeat-2);
        }

        // left seat
        if ((currentSeat - (2*m) ) >= 0 && originalVector[currentSeat] == 0 && percentage > 0)
        {
            originalVector[currentSeat - (2*m)] = counter++;
            seats.push(currentSeat - (2*m));
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

    std::vector<int> myseats (n*m,0);

    int aux = seatsFunctions(myseats,p,n-1,m-1);

    if (aux > 0)
    {
        seatsFunctions(myseats,aux,n,m);
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

