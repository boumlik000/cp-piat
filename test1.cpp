// C++ program to demonstrate cin.get() 
  
#include <iostream>  
using namespace std; 
#define log(x) cout << x << endl

class Player
{
    public :
        string name;
        int x,y;
        int speed;
    
    void move(Player,int i, int j)
    {
        x = i * speed;
        y = j * speed;
    }
};


int main() 
{ 

    Player player0;

    player0.x = 4;
    player0.y = 5;
    player0.speed = 8;
    player0.name = "boumlik";


    cout<< player0.name << "(" << player0.x << "," << player0.y << ")" << " run with a speed of " << player0.speed << endl;
    player0.move(player0,10,7);
    cout<< player0.name << "(" << player0.x << "," << player0.y << ")" << " run with a speed of " << player0.speed << endl;



    return 0; 
} 
