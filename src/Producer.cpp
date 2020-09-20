#include "Producer.h"
Producer::Producer( std::shared_ptr<container> &sls)
{
    cter=sls;
}                                   

void Producer::conduct()
{
    while (1)
    {
        /* code */
        cter.get()->pushback(rand()%10);
        // sleep(1);
    }
    
}

Producer::~Producer()
{
    cter=nullptr;
}