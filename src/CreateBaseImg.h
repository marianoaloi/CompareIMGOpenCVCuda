#include <string>

#include <opencv2/core.hpp> // Basic OpenCV structures
#include <opencv2/imgproc.hpp>// Image processing methods for the CPU
#include <opencv2/imgcodecs.hpp>// Read images


#include <filesystem>


using namespace std;
using namespace cv;

#pragma once

class CreateBaseImg
{

private:

    static string get_filename(string file_path) ;
    static void saveDefaultFile(string original,string target) ;

public:
    static string findImg(string path);
    static const std::string DESTINE_FOLDER;
    static const int SIZE_IMG;
};