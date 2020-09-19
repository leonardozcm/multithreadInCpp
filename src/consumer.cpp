#include "consumer.h"
consumer::consumer(std::shared_ptr<container> sls)
{
    cter=sls;
}

void consumer::consume(){
    while (1)
    {
        cter.get()->pop();
        sleep(1);
    }
    
}

consumer::~consumer()
{
}