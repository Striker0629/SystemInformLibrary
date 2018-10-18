#ifndef PROCESSOR_INFORM_H
#define PROCESSOR_INFORM_H
#include<iostream>
#include<powerbase.h>
#include<string>
#include<fstream>
#include<unordered_map>
typedef std::unordered_map<std::wstring, std::wstring> ComponentMap;
typedef std::unordered_map<std::wstring, std::wstring>::const_iterator ComponentMapIt;
class ComponentInform
{

	ComponentMap value_map_;

public:
	ComponentInform(const char* path = "../res/cpu.txt");
	~ComponentInform();
	std::wstring& operator[](const wchar_t* string);
	ComponentMap& GetContainer();
	ComponentMapIt Begin()const;
	ComponentMapIt End() const;
	inline bool IsEmpty()const
	{
		return value_map_.empty();
	}
};

#endif // !PROCESSOR_INFORM_H
