//
// Created by PB020 on 2/9/2018.
//

#include <opencv2/highgui.hpp>
#include <opencv2/aruco/charuco.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
    CommandLineParser parser(argc, argv, keys);
    parser.about(about);

    if(argc < 7) {
        parser.printMessage();
        return 0;
    }

    int squaresX = parser.get<int>("w");
    int squaresY = parser.get<int>("h");
    int squareLength = parser.get<int>("sl");
    int markerLength = parser.get<int>("ml");
    int dictionaryId = parser.get<int>("d");
    int margins = squareLength - markerLength;
    if(parser.has("m")) {
        margins = parser.get<int>("m");
    }

    int borderBits = parser.get<int>("bb");
    bool showImage = parser.get<bool>("si");

    String out = parser.get<String>(0);

    if(!parser.check()) {
        parser.printErrors();
        return 0;
    }

    Ptr<aruco::Dictionary> dictionary =
            aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME(dictionaryId));

    Size imageSize;
    imageSize.width = squaresX * squareLength + 2 * margins;
    imageSize.height = squaresY * squareLength + 2 * margins;

    Ptr<aruco::CharucoBoard> board = aruco::CharucoBoard::create(squaresX, squaresY, (float)squareLength,
                                                                 (float)markerLength, dictionary);

    // show created board
    Mat boardImage;
    board->draw(imageSize, boardImage, margins, borderBits);

    if(showImage) {
        imshow("board", boardImage);
        waitKey(0);
    }

    imwrite(out, boardImage);

    return 0;
}