#ifndef PROCESSOR_INFORM_H
#define PROCESSOR_INFORM_H
#include<iostream>
#include<powerbase.h>
#include<string>
#include<fstream>
#include<unordered_map>
typedef std::unordered_map<std::string, std::string> cpu_map;
typedef std::unordered_map<std::string, std::string>::const_iterator cpu_map_it;
class ProcessorInform
{

	cpu_map value_map_;

public:
	ProcessorInform(const char* path = "../res/cpu.txt");
	~ProcessorInform();
	std::string& operator[](const char* string);
	cpu_map& GetContainer();
	cpu_map_it Begin()const;
	cpu_map_it End() const;
};

#endif // !PROCESSOR_INFORM_H
