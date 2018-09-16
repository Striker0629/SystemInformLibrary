#ifndef PROCESSOR_INFORM_H
#define PROCESSOR_INFORM_H
#include<iostream>
#include<powerbase.h>
#include<string>
#include<fstream>
#include<unordered_map>
typedef std::unordered_map<std::string, std::string> cpu_map;
class ProcessorInform
{
	std::string cpu_id_;
	cpu_map value_map_;

public:
	ProcessorInform(const char* path = "../res/cpu.txt");
	~ProcessorInform();
	std::string& operator[](const char* string);
};

#endif // !PROCESSOR_INFORM_H
