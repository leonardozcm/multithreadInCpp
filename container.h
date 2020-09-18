#include <semaphore.h>
#include<thread>
#include <iostream>
class container
{
private:
    /* data */
    int maxContain;
    int* slots;
    int rear;
    sem_t mutex;
    sem_t items;
    sem_t block;
public:
    container(int maxContain);
    void pushback(int item);
    void pop();
    ~container();
};