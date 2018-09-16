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
#if 0
//	using namespace std;
//	HRESULT hr;
//	hr = CoInitializeEx(0, COINIT_MULTITHREADED);
//	if (FAILED(hr))
//	{
//		cerr << "FAILED to initialize COM library\t"<<hr<<endl;
//		return hr;
//	}
//	hr = CoInitializeSecurity(
//		NULL,
//		-1,
//		NULL,
//		NULL,
//		RPC_C_AUTHN_LEVEL_DEFAULT,
//		RPC_C_IMP_LEVEL_IMPERSONATE,
//		NULL,
//		EOAC_NONE,
//		NULL);
//	if (FAILED(hr))
//	{
//		cerr << "FAILED TO INITIALIZE SECURITY\t ErrCode=0x" << hex << hr << endl;
//		CoUninitialize();
//		return hr;
//	}
//	IWbemLocator* ploc = 0;
//	
//	hr = CoCreateInstance(CLSID_WbemLocator, 0,
//		CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&ploc);
//	if (FAILED(hr))
//	{
//		cerr << "Failed to create IWbemLocator object\t ErrCode=0x" << hex << hr << endl;
//		CoUninitialize();
//		return hr;
//	}
//	IWbemServices *psvc = 0;
//	hr = ploc->ConnectServer(
//		BSTR(L"ROOT\\CIMV2"),
//		NULL,
//		NULL,
//		0,
//		NULL,
//		0,
//		0,
//		&psvc
//	);
//	if (FAILED(hr))
//	{
//		cerr << "COULD'NOT CONNECT. Error Code=0x" << hex << hr << endl;
//		ploc->Release();
//		CoUninitialize();
//		return hr;
//	}
//	cerr << "Connected to WMI" << endl;
//	hr = CoSetProxyBlanket(psvc,
//		RPC_C_AUTHN_WINNT,
//		RPC_C_AUTHZ_NONE,
//		NULL,
//		RPC_C_AUTHN_LEVEL_CALL,
//		RPC_C_IMP_LEVEL_IMPERSONATE,
//		NULL,
//		EOAC_NONE
//	);
//	if (FAILED(hr))
//	{
//		cerr << "COULD'NOT SET PROXY BLANKET. Error code=0x" << hex 
//			<< hr << endl;
//		psvc->Release();
//		ploc->Release();
//		CoUninitialize();
//		return hr;
//	}
//	IWbemClassObject* processor=NULL;
//	//TODO GET INFORM FROM WMI;
//#ifdef ENUM_WAY
//	IEnumWbemClassObject* p_enum = NULL;
//	hr = psvc->ExecQuery(bstr_t("WQL"),
//		bstr_t("SELECT * FROM Win32_Processor"),
//		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
//		NULL,
//		&p_enum);
//	if (FAILED(hr))
//	{
//		cerr << "Query for os name failed\t Error Code=0x"
//			<< hex << hr << endl;
//		psvc->Release();
//		ploc->Release();
//		CoUninitialize();
//		
//		return 1;
//	}
//
//	IWbemClassObject* plcs_obj = NULL;
//	ULONG u_return = 0;
//	while (p_enum)
//	{
//		HRESULT hr = p_enum->Next(WBEM_INFINITE, 1,
//			&plcs_obj, &u_return);
//
//		if (0 == u_return)
//		{
//			break;
//		}
//		VARIANT vtProp;
//		hr = plcs_obj->Get(L"Name", 0, &vtProp, 0, 0);
//		plcs_obj->Get(L"AddressWidth", 0, &vtProp, 0, 0);
//		
//		wcout<<"WIDTH"<<vtProp.uiVal;
//		wcout << " OS Name:" << vtProp.bstrVal << endl;
//		wcout << vtProp.iVal<< endl;
//		VariantClear(&vtProp);
//		plcs_obj->Release();
//
//
//
//	}
//
//
//#pragma region ASYNC
//	//QuerySink* presponse_sink = new QuerySink();
//	//presponse_sink->AddRef();
//	//hr = psvc->ExecQueryAsync(
//	//	bstr_t("WQL"),
//	//	bstr_t("SELECT * FROM Win32_OperatingSystem"),
//	//	WBEM_FLAG_BIDIRECTIONAL,
//	//	NULL,
//	//	presponse_sink
//	//);
//
//	//Sleep(500);
//	//psvc->CancelAsyncCall(presponse_sink);
//#pragma endregion
//	psvc->Release();
//	ploc->Release();
//	p_enum->Release();
//	CoUninitialize();
//#else
//	BSTR path = SysAllocString(L"SELECT * FROM Win32_MotherboardDevice.DeviceID=0");
//	hr = psvc->GetObject(path, 0, 0, &processor, 0);
//	//TODO ERROR_CHECK
//
//	BSTR processor_text; 
//	processor->GetObjectText(0, &processor_text);
//	printf("%S\n\n", processor_text);
//	processor->Release();
//#endif
//
//
#endif
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

	std::cin.get();
	return 0;
}