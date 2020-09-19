#ifndef _PRODUCER
#define _PRODUCER

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
    Producer(std::shared_ptr<container> &sls);
    void conduct();  
    
    ~Producer();
};

#endif /*Producer*/