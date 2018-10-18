#define _WIN32_DCOM
#include<iostream>
#include<Windows.h>
#include<driverspecs.h>
#include<wbemidl.h>
#include<chrono>
#include<algorithm>
#include<iterator>
#include<unordered_map>
#include"SystemInform.h"

#include<tchar.h>
#include<io.h>
#include <fcntl.h>

int main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	SetConsoleCP(1200);
	//WmiCoObject object{ "ROOT\\CIMV2" };
	//std::wstring str = L"Привет Мир";
	//std::wcout << str << std::endl;
	try
	{
		
		for (auto it = SystemInformCollection::Instance().cpu_table.Begin(); it != SystemInformCollection::Instance().cpu_table.End(); ++it)
			std::wcout << it->first << '\t' << it->second << std::endl;
		if (SystemInformCollection::Instance().memory_table.IsEmpty())
		{
			std::cout << "MEMORY TABLE EMPTY!!!" << std::endl;
		}
		else {
			std::wcout << std::endl;
			for (auto it = SystemInformCollection::Instance().memory_table.Begin(); it != SystemInformCollection::Instance().memory_table.End(); ++it)
				std::wcout << it->first << '\t' << it->second << std::endl;
		}
	}
	catch (...)
	{
		std::cerr << "ERROR" << std::endl;
	}
	
	/*ProcessorInform obj;*/

#ifdef TEST
	WmiCoObject object{ "ROOT\\CIMV2" };
	auto value_map = std::make_unique<std::unordered_map<std::string, std::string>>();
	(*value_map)["Name"];
	(*value_map)["NumberOfCores"];
	(*value_map)["Manufacturer"];
	auto time_point1 = std::chrono::high_resolution_clock::now();
	
	object.GetData("Win32_Processor.DeviceID='CPU0'", *value_map);

	//std::for_each(value_map->begin(), value_map->end(), [&](auto&& map_iter)
	//{
	//	map_iter.second = object.GetData("Win32_Processor.DeviceID='CPU0'", map_iter.first.c_str());
	//});

	/*for (auto it = value_map->begin(); it != value_map->end(); ++it)
	{

			it->second=object.GetData("Win32_Processor.DeviceID='CPU0'",it->first.c_str());
	}*/
	auto time_point2 = std::chrono::high_resolution_clock::now();
	std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(time_point2 - time_point1).count() << std::endl;
	for (auto&& i : *value_map)
	{
		std::cerr << i.first << '\t' << i.second << std::endl;
	}
	/*std::cerr << res << std::endl;*/
	/*ProcessorInform inform;
	inform.Querry(&object);*/
#endif
	std::wcin.get();
	return 0;
}