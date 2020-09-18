#include "container.h"

container::container(int maxContain)
{
    slots=new int[maxContain];
    rear=0;
    sem_init(&mutex,0,1);
    sem_init(&items,0,0);
    sem_init(&block,0,maxContain);
}

void container::pushback(int item){
    sem_wait(&block);
    sem_wait(&mutex);
    slots[++rear]=item;
    sem_post(&mutex);
    sem_post(&items);
    
}

void container::pop(){
    sem_wait(&items);
    sem_wait(&mutex);
    int head=slots[0];
    for (int i = 0; i < rear; i++)
    {
        /* code */
        slots[i]=slots[i+1];
    }
    slots[rear]=0;
    rear--;
    std::cout<<std::this_thread::get_id()<<" consume "<<head<<" [";
    for (int i = 0; i < rear; i++)
    {
        /* code */
        std::cout<<i<<",";
    }
    std::cout<<"]\n";
    sem_post(&mutex);
    sem_post(&block);
    

}

container::~container()
{
    delete slots;
}
