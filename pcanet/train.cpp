#include <opencv2\opencv.hpp>
#include "PCANet.h"

#include <iostream>
using std::cout;
using std::endl;

//random 2 11 [4 28][4 23] accuracy: 0.945 11 / 200 time: 84.499

int main(int argc, char** argv)
{
    std::vector<cv::Mat> images;
    bool randomProjection = true;
    if (! randomProjection)
    {
        cv::String dir = "funneled";
        //cv::String dir = "lfw3d_9000";
        std::vector<cv::String> files;
        glob(dir,files,true);
        if (files.empty())
        {
            cout << " - no input!" << endl;
            return 1;
        }

        for (size_t i=0; i<777; ++i)
        {
            size_t z = cv::theRNG().uniform(0,files.size());
            cv::Mat im = cv::imread(files[z],0);
            im.convertTo(im,CV_32F);
            images.push_back(im);
        }
    }

    PCANet pcaNet(11);
    pcaNet.addStage(6,28);
    pcaNet.addStage(6,23);

    cout << "PCANet train " << pcaNet.settings() << endl;
    int64 e1 = cv::getTickCount();

    if (randomProjection)
        pcaNet.waveProjection();
        //pcaNet.randomProjection();
    else
        pcaNet.trainPCA(images, false);

    cv::String fn("pcanet.xml");
    int64 e2 = cv::getTickCount();
    double time = (e2 - e1) / cv::getTickFrequency();
    cout << " PCANet Training time: " << time << endl;
    pcaNet.save(fn);
    // save filter visualization as well.
    pcaNet.saveFilterVis("filters.png");

    cv::namedWindow("im",0);
    cv::Mat im=cv::imread("filters.png");
    cv::imshow("im",im);
    cv::waitKey(); 
    return 0;
}
