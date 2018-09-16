#define _WIN32_DCOM
#include<iostream>
#include<Windows.h>
#include<driverspecs.h>
#include<wbemidl.h>
#include<chrono>
#include<algorithm>
#include<unordered_map>
#include"SystemInform.h"
#pragma comment(lib,"wbemuuid.lib")




int main()
{
	ProcessorInform obj;

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
	std::cin.get();
	return 0;
}