#include "opencv2/opencv.hpp"

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::ml;

void read_pca(PCA &pca, FILE *f)
{
    int mr,mc;
    fread(&mr, sizeof(int), 1, f);
    fread(&mc, sizeof(int), 1, f);
    pca.mean.create(mr,mc,CV_32F);
    fread(pca.mean.ptr<float>(), mc*mr, 1, f);
    cerr << "mean" << pca.mean.size() << endl;

    int er, ec;
    fread(&er, sizeof(int), 1, f);
    fread(&ec, sizeof(int), 1, f);
    pca.eigenvectors.create(er,ec,CV_32F);
    fread(pca.eigenvectors.ptr<float>(), 1, ec*er, f);
    cerr << "mean" << pca.eigenvectors.size() << endl;
}
int t()
{
    FILE * f = fopen("../face3/data/pca.hdlbpu.bin","rb");
    CV_Assert(f!=0);
    for (int i=0; i<20; i++)
    {
        PCA p;
        read_pca(p,f);
    }
    return fclose(f);
}

void write_pca(PCA &pca, FILE *f)
{
    int mr = pca.mean.rows;
    fwrite(&mr, sizeof(int), 1, f);
    int mc = pca.mean.cols;
    fwrite(&mc, sizeof(int), 1, f);
    fwrite(pca.mean.ptr<float>(), mc*mr, 1, f);
    fflush(f);
    cerr << "##";

    // will have to transpose later !
    int er = pca.eigenvectors.rows;
    fwrite(&er, sizeof(int), 1, f);
    int ec = pca.eigenvectors.cols;
    fwrite(&ec, sizeof(int), 1, f);
    fwrite(pca.eigenvectors.ptr<float>(), 1, ec*er, f);
}
int main( int argc, char *argv[] )
{
    return t();
    
    FILE * f = fopen("pca.hdlbpu.bin","wb");
    
    FileStorage fs("../face3/data/hdlbp_pca2.xml.gz",FileStorage::READ);
    CV_Assert(fs.isOpened());
    FileNode pnodes = fs["hdlbp"];
    int i=0;
    for (FileNodeIterator it=pnodes.begin(); it!=pnodes.end(); ++it)
    {
        PCA p;
        p.read(*it);
        write_pca(p,f);
    }
    fs.release();
    fclose(f);
    cerr << "!!";
    return 0;
}
