
#include <iostream>

#include "computer_assemble.h"
#include "Intel.h"
#include "kingston.h"
#include "Nvdia.h"
using namespace std;




// --------- 实现层  -------



// --------- 实现层(end)  -------


//高层业务逻辑层
int main(void)
{
	CPU *intelCPU = new IntelCPU;
	Card* intelCard = new IntelCard;
	Memory *intelMem = new IntelMem;

#if 0

	cout << "第一台电脑" << endl;
	intelCPU->caculate();
	intelCard->display();
	intelMem->storage();
#endif
	Computer *computer1 = new Computer(intelCPU, intelCard, intelMem);
	computer1->work();
	//delete computer1;



	//组装第二台
	cout << "0000 " << endl;

	Card* nvdiaCard = new NvdiaCard;
	Memory *kingstonMem = new KingstonMem; //两个具体的产品拿到了

	Computer *computer2 = new Computer(intelCPU, nvdiaCard, kingstonMem);
	computer2->work();
	delete computer2;


	//delete intelCard;
	//delete intelCPU;
	//delete intelMem;





	Computer *computer3 = new Computer(new IntelCPU, new IntelCard, new IntelMem);
	
	computer3->work();

	delete computer3;
	return 0;
}
