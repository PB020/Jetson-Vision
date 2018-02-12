//
// Created by PB020 on 2/12/18.
//

#ifndef JETSON_VISION_JETSONVISION_H
#define JETSON_VISION_JETSONVISION_H
using namespace std;

class BoardCreation
{
public:
    int createBoard(argc, argv);
};

class BoardDetection
{
public:
    int detectBoard(argc, argv);
};

class JetsonVision: public BoardCreation, BoardDetection
{
public:
    virtual void main(argc, argv)
    {

    }
};

#endif //JETSON_VISION_JETSONVISION_H
