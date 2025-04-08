#include <iostream>
#include <fstream>

using namespace std;
int main()
{

    cout << "achkliti liom !?";
    string food;
    cin >> food;
    ofstream myfile("food");
    myfile << food;
    myfile.close();

    ifstream rd("food");
    string line ;
    rd >> line;
    cout << "so u eated " << line ;

    rd.close();
    return 0;
}
