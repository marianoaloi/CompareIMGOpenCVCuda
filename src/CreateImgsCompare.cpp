

#include <src/ContentFile.cpp>
#include <vector>
#include <set>
#include <string>

#include <opencv2/core.hpp> // Basic OpenCV structures
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>   // Image processing methods for the CPU
#include <opencv2/imgcodecs.hpp> // Read images

// CUDA structures and methods
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>

using namespace cv;
using namespace std;

struct BufferPSNR // Optimized CUDA versions
{                 // Data allocations are very expensive on CUDA. Use a buffer to solve: allocate once reuse later.
    cuda::GpuMat gI1, gI2, gs, t1, t2;

    cuda::GpuMat buf;
};

class CreateImgsCompare
{
    vector<ContentFile> content;

public:
    CreateImgsCompare(vector<ContentFile> &content)
    {
        this->content = content;
    }

    void createImg()
    {
        set<string> val;
        for (int i = 0; i < content.size(); i++)
        {

            cout << content[i].toString() << "\n";
        }
    }
};