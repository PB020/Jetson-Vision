#include <iostream>
#include <JetsonVision.h>

class BoardCreation;
class BoardDetection;

using namespace std;

int main(int argc, char** argv[]){
    cout << "Creating ChArUco Board" << endl;
    int BoardCreation::createBoard(argc, *argv);
    cout << "Board Created, Detecting Board" << endl;
    int BoardDetection::detectBoard(argc, *argv);
}