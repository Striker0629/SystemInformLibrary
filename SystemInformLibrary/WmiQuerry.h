#pragma once
#ifndef WMI_QUERRY_H
#endif // !WMI_QUERRY_H
#include<Windows.h>
#include<driverspecs.h>
#include<wbemidl.h>
#include<string>
#include<iostream>
#include<unordered_map>
#include<comdef.h>
#pragma comment(lib,"wbemuuid.lib")


class WmiCoObject
{
	bool connected_;
	//std::string querry_;
	std::string root_;
	HRESULT hres_;
	IWbemLocator* ploc_;
	IWbemClassObject* object_;
	
public:
	IWbemServices* psvc_;
	WmiCoObject(const char* root);

	std::string GetData(const char * target,const char* name);
	void GetData(const char* target, std::unordered_map<std::string, std::string>& map);
	IWbemServices*  GetServices()const;
	//_bstr_t QuerryText()const;
	//void ResetQuerry(const char * new_querry_text_);

	~WmiCoObject();
};

#define WMI_QUERRY_H
