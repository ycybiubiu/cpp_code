#include<iostream>
using namespace std;
class MainBoard
{
public:
	virtual void basemodule() = 0;
};
class CPU
{
public:
	virtual void MainFrequency() = 0;
};
class GPU
{
public:
	virtual void DisplayMemory() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};
class RAM
{
public:
	virtual void storage() = 0;
};
class Power
{
public:
	virtual void power() = 0;
	
};
class HeatSink
{
public:
	virtual void type() = 0;
};
class PCCase
{
public:
	virtual void size() = 0;
};
class Computer
{
public:
	Computer(MainBoard* mb, CPU* cpu, GPU* gpu, Memory* memory, RAM* ram, Power* power, HeatSink* hs, PCCase* pccase)
	{
		m_mb = mb;
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
		m_ram = ram;
		m_power = power;
		m_hs = hs;
		m_pccase = pccase;
		//提供工作函数
	}
	~Computer()
	{
		//释放主板零件
		if(m_mb!=NULL)
		{
			delete m_mb;
			m_mb = NULL;
		}
		//释放CPU零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//释GPU零件
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		//释放硬盘零件
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
		//释放内存零件
		if (m_ram != NULL)
		{
			delete m_ram;
			m_ram = NULL;
		}
		//释放电源零件
		if (m_power != NULL)
		{
			delete m_power;
			m_power = NULL;
		}
		//释放散热零件
		if (m_hs != NULL)
		{
			delete m_hs;
			m_hs = NULL;
		}
		//释放机箱零件
		if (m_pccase != NULL)
		{
			delete m_pccase;
			m_pccase = NULL;
		}
	}
	void work()
	{
		m_mb->basemodule();

		m_cpu->MainFrequency();

		m_gpu->DisplayMemory();

		m_memory->storage();

		m_ram->storage();

		m_power->power();

		m_hs->type();

		m_pccase->size();
	}
private:
	//零件指针
	MainBoard* m_mb;
	CPU* m_cpu;
	GPU* m_gpu;
	Memory* m_memory;
	RAM* m_ram;
	Power* m_power;
	HeatSink* m_hs;
	PCCase* m_pccase;
};

//具体厂商
class MSIMainBoard :public MainBoard
{
public:
	virtual void basemodule()
	{
		cout << "MSI Edge Ti B760m" << endl;
	}
};
class IntelCPU:public CPU
{
public:
	virtual void MainFrequency()
	{
		cout << "12700KF:5.0GHz" << endl;
	}
};
class NVIDIAGPU :public GPU
{
public:
	virtual void DisplayMemory()
	{
		cout << "电竞判客4080duper:16GB" << endl;
	}
}; 
class ADATAMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "威刚翼龙S70:2TB" << endl;
	}
};
class ADATARAM :public RAM
{
public:
	virtual void storage()
	{
		cout << "威刚龙耀D500G:16GB*2,6400MHz" << endl;
	}
};
class ApexPower:public Power
{
public:
	virtual void power()
	{
		cout << "艾湃电竞GTR白色金牌全模组:850W" << endl;
	}

};
class ThermaltakeHeatSink:public HeatSink
{
public:
	virtual void type()
	{
		cout << "利民 FROZEN WARFRAME PRO 360 WHITE水冷" << endl;
	}
};
class AgioPCCase :public PCCase
{
public:
	virtual void size()
	{
		cout << "爱国者星璨岚机箱" << endl;
	}
};
void test06()
{
	//电脑零件
	MainBoard* mainboard = new MSIMainBoard;
	CPU* intelcpu = new IntelCPU;
	GPU* nvidiagpu = new NVIDIAGPU;
	Memory* adatamemory = new ADATAMemory;
	RAM* adataram = new ADATARAM;
	Power* apexpower = new ApexPower;
	HeatSink* tlheatsink = new ThermaltakeHeatSink;
	PCCase* agiocase = new AgioPCCase;
	//创建电脑
	Computer* computer1 = new Computer(mainboard, intelcpu, nvidiagpu, adatamemory, adataram, apexpower, tlheatsink, agiocase);
	computer1->work();
	delete computer1;
}

int main()
{
	test06();
	system("pause");
	return 0;
}