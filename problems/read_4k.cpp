class Read4k {

public:
    Read4k() {}
    
    int read4k(void *dst) 
    {
    }
};

class ByteRead {
public:
    const int chunkSize = 4096;

    ByteRead(Read4k &read4k) : read4k_(read4k), cacheSize_(0), cacheOffset(0)
    {
    }

    int read(void *dst, int len) 
    {
        int bytesRead = 0;
        while (len > 0)
        {
            if (cacheSize_==0 && len>=chunkSize)
            {
                int ret = read4k(dst);
                if (!ret) break;
                bytesRead += ret;
                len -= ret;
                dst += ret;
            }
            else
            {
                if (cacheSize_ == 0)
                {
                    int ret = read4k(cache_);
                    if (!ret) break;
                    cacheSize_ = ret;
                    cacheOffset_ = 0;
                }
                int rsize = std::min(cacheSize_, len);
                memcpy(dst, cache_+cacheOffset_, rsize);
                cacheSize_ -= rsize;
                cacheOffset_ += rsize;
                bytesRead += rsize;
                len -= rsize;
                dst += rsize;
            }
        }
        
        return bytesRead;
    }

private:
    Read4k &read4k_;
    uint8_t cache_[chunkSize];
    int cacheSize_;
    int cacheOffset_;
};
