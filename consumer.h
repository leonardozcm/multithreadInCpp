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
    consumer(std::shared_ptr<container> sls);
    void consume();
    ~consumer();
};

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
