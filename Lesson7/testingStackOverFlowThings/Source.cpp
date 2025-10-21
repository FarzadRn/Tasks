#include <iostream>
class player
{
public:
    short a = 0;
    int b;
    player() {
        std::cout << "Player contructed\n";
    }
    ~player()
    {
        std::cout << "Player destructed" << '\n';
    }

    void print()
    {
       
        std::cout << "I'm printed " << a<< std::endl;
    }


};
player* boo()
{
    player a;
    return &a;
}

int main()
{

    //int a = 5;
    //int* p = &a;
   player* ptrTemp = nullptr;
     {
       // player p;
        player* ptr = boo();
        
        char ptr2[] = { "hello" };
      
        ptrTemp = ptr;
     
        int v1 = 1, v2 = 2, v3 = 3;
        int bob[100] = { 0 };
        ptr->print();
        delete ptr;
        ptr = nullptr;
     }
   int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
   // std::cout << *ptrTemp;
}