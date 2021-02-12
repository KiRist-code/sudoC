#include<iostream>
#include<stdlib.h>

using namespace std;

class sudo
{
    private:
        char* command;
    public:
        sudo(char* c);
};
sudo::sudo(char* c)
{
    c = command;
    system(c);
}
