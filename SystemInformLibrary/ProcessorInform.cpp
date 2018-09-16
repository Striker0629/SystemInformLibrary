#include "ProcessorInform.h"



ProcessorInform::ProcessorInform(const char* path)
{


	std::ifstream read(path);
	std::string temp;
	if (read.is_open()) {
		while (read >> temp)
		{
			value_map_[temp];
		}
		read.close();
	}

}



ProcessorInform::~ProcessorInform()
{
}

std::string & ProcessorInform::operator[](const char * string)
{
	return value_map_[string];
}

cpu_map & ProcessorInform::GetContainer()
{
	return value_map_;
}

cpu_map_it ProcessorInform::Begin() const
{
	return value_map_.cbegin();
}

cpu_map_it ProcessorInform::End() const
{
	return value_map_.end();
}
