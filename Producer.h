#include <memory>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "container.h"

class Producer
{
private:
    /* data */
    std::shared_ptr<container> cter;
public:
    Producer(std::shared_ptr<container> sls);
    void conduct();  
    
    ~Producer();
};

Producer::Producer( std::shared_ptr<container> sls)
{
    cter=sls;
}   

void Producer::conduct()
{
    while (1)
    {
        /* code */
        cter.get()->pushback(rand()%10);
        sleep(1);
    }
    
}

Producer::~Producer()
{
    cter=nullptr;
}
