#ifndef SYSTEM_INFORM_H
#define SYSTEM_INFORM_H
#include<Windows.h>
#include<driverspecs.h>
#include<wbemidl.h>
#include"ProcessorInform.h"
#include"WmiQuerry.h"
#pragma comment(lib,"wbemuuid.lib")

class SystemInform
{
	ProcessorInform cpu_inform_;
	WmiCoObject query_;
	SystemInform();
	~SystemInform();
public:
	SystemInform(const SystemInform& right) = delete;
	SystemInform& Instance();
};

#endif