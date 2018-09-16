#include "ProcessorInform.h"



ProcessorInform::ProcessorInform(const char* path = "../res/cpu.txt")
{

	cpu_id_ = "CPU0";
	std::ifstream read(path);
	std::string temp;
	if (read.is_open()) {
		while (read >> temp)
		{
			value_map_[temp];
		}
		read.close();
	}
	for (auto&& i : value_map_)
		std::cerr << i.first << std::endl;

}



ProcessorInform::~ProcessorInform()
{
}

std::string & ProcessorInform::operator[](const char * string)
{
	return value_map_[string];
}
