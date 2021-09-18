#include "computer_assemble.h"
Computer::Computer(CPU *cpu, Card *card, Memory *mem) //cpu = new IntelCPU
{
    this->cpu = cpu;
    this->card = card;
    this->mem = mem;
}

//给电脑提供一个工作的方法
void Computer::work()
{
    cpu->caculate(); //发生多态
    card->display(); //发生多态
    mem->storage();//发生多态
}

Computer::~Computer()
{
    if (cpu != NULL) {
            delete cpu;
            cpu = NULL;
    }
    if (card != NULL) {
        delete card;
        card = NULL;
    }
    if (mem != NULL) {
        delete mem;
        mem = NULL;
    }
}