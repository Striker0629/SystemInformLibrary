#include "SystemInform.h"



SystemInformCollection::SystemInformCollection():query_{ "ROOT\\CIMV2" },cpu_table{},memory_table{"../res/memory.txt"}
{
	query_.GetData("WIN32_Processor.DeviceID='CPU0'", cpu_table.GetContainer());
	query_.GetData("WIN32_PhysicalMemory.Tag='Physical Memory 1'", memory_table.GetContainer());

}



 SystemInformCollection & SystemInformCollection::Instance()
{
	static SystemInformCollection inf;
	return inf;
}

//#pragma  warning(4219)