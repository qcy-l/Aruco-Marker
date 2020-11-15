#include "opencv2/opencv.hpp"
#include "aruco/aruco.h"


int main(int argc, char* argv[]){
    aruco::Dictionary dict = aruco::Dictionary::loadPredefined(aruco::Dictionary::ARUCO_MIP_16h3);
    cv::Mat img;
    std::string id_text;
    
    if (argc > 1){
        id_text = argv[1];
        int id = std::stoi(id_text);
        img = dict.getMarkerImage_id(id, 14, false, false);
    }
    else{
        id_text = "1";
        img = dict.getMarkerImage_id(1, 14, false, false);
    }
    std::string name = std::string("marker") + id_text + std::string(".jpg");

    cv::imwrite(name.c_str(), img);
    return 0;
}
