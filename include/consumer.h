#ifndef _CONSUMER
#define _CONSUMER
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "container.h"
class consumer
{
private:
    /* data */
    std::shared_ptr<container> cter;
public:
    consumer(std::shared_ptr<container> &sls);
    void consume();
    ~consumer();
};
#endif /*_CONSUMER*/