#include <iostream>

class BoardCreation;
class BoardDetection;

using namespace std;

int main(int argc, char *argv[]){
    cout << "Creating ChArUco Board" << endl;
    int createBoard(argc, reinterpret_cast<char*>(argv));
    cout << "Board Created, Detecting Board" << endl;
    int detectBoard(argc, reinterpret_cast<char*>(argv));
}