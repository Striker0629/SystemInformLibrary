#pragma once
#ifndef I_WMI_QUERRY_H
#define I_WMI_QUERRY_H
#include"WmiQuerry.h"

class IWmiQuerry
{
public:
	virtual void Querry(WmiCoObject* ptr_) = 0;
	virtual ~IWmiQuerry();
};

#endif // !I_WMI_QUERRY_H
