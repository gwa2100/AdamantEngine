#include <iostream>
#include "AdamantEngine.h"

using namespace std;

class CApp2 : public CApp
{

};



int main(int argc, char* argv[])
{
    CApp2 theApp;
    return theApp.OnExecute();
}
