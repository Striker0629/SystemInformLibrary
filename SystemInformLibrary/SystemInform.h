#ifndef SYSTEM_INFORM_H
#define SYSTEM_INFORM_H
#include<Windows.h>
#include<driverspecs.h>
#include<wbemidl.h>
#include"ProcessorInform.h"
#include"WmiQuerry.h"
#pragma comment(lib,"wbemuuid.lib")

class SystemInformCollection
{
	WmiCoObject query_;
	SystemInformCollection();
	~SystemInformCollection();
public:
	SystemInformCollection(const SystemInformCollection& right) = delete;
	static SystemInformCollection& Instance();
	ProcessorInform cpu_inform_;
	ProcessorInform memory_inform_;
};

#endif