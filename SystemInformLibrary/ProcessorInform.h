#pragma once
#ifndef PROCESSOR_INFORM_H
#define PROCESSOR_INFORM_H

#include<iostream>
#include<powerbase.h>
#include<string>
class ProcessorInform
{
	std::string cpu_id_;
	std::string name_;
	std::string description_;
	uint16_t adress_width_;
	uint16_t cores_;


public:
	ProcessorInform();
	//void Querry(WmiCoObject* ptr_)override;
	~ProcessorInform();
};

#endif // !PROCESSOR_INFORM_H
