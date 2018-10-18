#include "ProcessorInform.h"



ComponentInform::ComponentInform(const char* path)
{


	std::wifstream read{ path };
	std::wstring temp;
	if (read.is_open()) {
		while (read >> temp)
		{
			value_map_[temp];
		}
		read.close();
	}

}



ComponentInform::~ComponentInform()
{
}

std::wstring & ComponentInform::operator[](const wchar_t * string)
{
	return value_map_[string];
}

ComponentMap & ComponentInform::GetContainer()
{
	return value_map_;
}

ComponentMapIt ComponentInform::Begin() const
{
	return value_map_.cbegin();
}

ComponentMapIt ComponentInform::End() const
{
	return value_map_.end();
}
