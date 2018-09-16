#include "SystemInform.h"



SystemInformCollection::SystemInformCollection():query_{ "ROOT\\CIMV2" },cpu_inform_{},memory_inform_{"../res/memory.txt"}
{
	query_.GetData("WIN32_Processor.DeviceID='CPU0'", cpu_inform_.GetContainer());
	query_.GetData("WIN32_PhysicalMemory.Tag='Physical Memory 1'", memory_inform_.GetContainer());
	//for (auto it = cpu_inform_.Begin(); it != cpu_inform_.End(); ++it)
	//	std::cerr << it->first << '\t' <<it->second << std::endl;
}


SystemInformCollection::~SystemInformCollection()
{
}

 SystemInformCollection & SystemInformCollection::Instance()
{
	static SystemInformCollection inf;
	return inf;
}

//#pragma  warning(4219)