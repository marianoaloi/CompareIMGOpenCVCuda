

#include "src/CreateBaseImg.h"

const std::string CreateBaseImg::DESTINE_FOLDER = "imgStable";
const int CreateBaseImg::SIZE_IMG = 64;

string CreateBaseImg::get_filename(string file_path)
{
    // Find the last occurrence of the '/' character in the file path.
    size_t pos = file_path.rfind('/');

    // If the '/' character is not found in the file path, then the filename is
    // the entire file path.
    if (pos == string::npos)
    {
        return file_path;
    }

    // Return the substring of the file path that starts after the last '/'
    // character.
    return file_path.substr(pos + 1);
}

void CreateBaseImg::saveDefaultFile(string original, string target)
{

    Mat imgOri = imread(original, cv::IMREAD_GRAYSCALE);
    Mat imgTrg = Mat::zeros(Size(CreateBaseImg::SIZE_IMG, CreateBaseImg::SIZE_IMG), CV_8UC3);
    resize(imgOri, imgTrg, Size(CreateBaseImg::SIZE_IMG, CreateBaseImg::SIZE_IMG), cv::INTER_LINEAR);
    imgOri = imgTrg;
    imgTrg = Mat::zeros(imgOri.size(), CV_8UC3);

    // Define the region of interest (ROI) that you want to crop from the image.
    Rect roi(10, 10, imgOri.cols - 20, imgOri.rows - 20);

    // Copy the ROI from the original image to the new image.
    copyMakeBorder(imgOri(roi), imgTrg, 10, 10, 10, 10, BORDER_CONSTANT, 0);

    imwrite(target, imgTrg);
}

string CreateBaseImg::findImg(string pathStr)
{

    std::filesystem::path path = pathStr;
    path = path.parent_path();
    path = path.parent_path();

    path.append(CreateBaseImg::DESTINE_FOLDER);
    if (!filesystem::exists(path))
    {
        filesystem::create_directories(path);
    }
    string filename = CreateBaseImg::get_filename(pathStr);
    path = path.append(filename+".jpg");
    if (!filesystem::exists(path))
    {
        CreateBaseImg::saveDefaultFile(pathStr, path.string());
    }

    return path.string();
}