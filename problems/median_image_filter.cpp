

#include <vector>



class Image
{
public:
    int w;
    int h;

    std::vector<char> image;

    Image(int width, int height, int init) : image(width*height, init)
    {
        w = width;
        h = height;
    }

    char &operator()(int row, int col)
    {
        return image[row*w + col];
    }
};


Image &medianFilter( Image &im_in, Image &im_out, int k)
{
    int w = im_in.w;
    int h = im_in.h;
    if (k%2==0)
        return im_out;

    for (int y=0; y<h; y++)
    {
        for (int x=0; x<w; x++)
        {
            std::vector<int> v;
            for (int ky=std::max(0,y-k/2); ky<=std::min(h-1,y+k/2); ++ky)
            {
                for (int kx=std::max(0,x-k/2); ky<=std::min(w-1,x+k/2); ++kx)
                {
                    v.push_back(im_in(y,x));
                }
            }
            std::sort(v.begin(), v.end());

            if (v.size()%2 == 1)
                im_out(y,x) = v[v.size()/2];
            else
                im_out(y,x) = (static_cast<int>(v[v.size()/2]) + static_cast<int>(v[v.size()/2-1]))/2;

        }
    }

    return im_out;
} 



int main()
{



    return 0;
}
