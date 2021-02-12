#include<iostream>
#include<stdlib.h>

using namespace std;

class sudo
{
public:
    sudo(char c[]);
};
sudo::sudo(char c[])
{
    system(c);
}
