#include "WmiQuerry.h"



WmiCoObject::WmiCoObject(const char* root) :
	root_{ root },
	hres_{ 0 },
	connected_{ false },
	ploc_{ nullptr },
	psvc_{ nullptr },
	object_{ nullptr }
{
	hres_ = CoInitializeEx(0, COINIT_MULTITHREADED);
	if (FAILED(hres_))throw;
	hres_ = CoInitializeSecurity
	(
		NULL,
		-1,
		NULL,
		NULL,
		RPC_C_AUTHN_LEVEL_DEFAULT,
		RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL,
		EOAC_NONE,
		NULL
	);
	if (FAILED(hres_))throw;

	hres_ = CoCreateInstance(
		CLSID_WbemLocator, 0,
		CLSCTX_INPROC_SERVER,
		IID_IWbemLocator,
		reinterpret_cast<LPVOID*>(&ploc_));
	if (FAILED(hres_))throw;

	hres_ = ploc_->ConnectServer
	(
		_com_util::ConvertStringToBSTR(root_.c_str()),
		NULL,
		NULL,
		0,
		NULL,
		0,
		0,
		&psvc_
	);
	if (FAILED(hres_))throw;

	hres_ = CoSetProxyBlanket(
		psvc_,
		RPC_C_AUTHN_WINNT,
		RPC_C_AUTHZ_NONE,
		NULL,
		RPC_C_AUTHN_LEVEL_CALL,
		RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL,
		EOAC_NONE
	);
	if (FAILED(hres_))throw;
	connected_ = true;

}

std::string WmiCoObject::GetData(const char* target, const char* name)
{
	HRESULT hres;
	IWbemClassObject* plcs_obj = nullptr;
	hres = psvc_->GetObject(_com_util::ConvertStringToBSTR(target), 0, NULL, &plcs_obj, NULL);

	CIMTYPE types;
	VARIANT value;
	VariantInit(&value);
	HRESULT res = plcs_obj->Get(_com_util::ConvertStringToBSTR(name), 0, &value, &types, NULL);
	std::string result;
	if (FAILED(res))throw;
	if (types != CIM_ILLEGAL)
	{

		switch (types)
		{
		case CIM_REAL32:
			result = std::to_string(value.fltVal);
			break;
		case CIM_UINT32:
			result = std::to_string(value.uintVal);
			break;
		case CIM_SINT32:
			result = std::to_string(value.intVal);
			break;
		case CIM_STRING:
			char* print = _com_util::ConvertBSTRToString(value.bstrVal);
			result.append(print);
			delete[]print;
			break;
		}
	}
	return result;

}

void WmiCoObject::GetData(const char* target, std::unordered_map<std::string, std::string>& map)
{
	HRESULT hres;
	IWbemClassObject* plcs_obj = nullptr;
	hres = psvc_->GetObject(_com_util::ConvertStringToBSTR(target), 0, NULL, &plcs_obj, NULL);

	CIMTYPE types;
	VARIANT value;
	VariantInit(&value);
	for (auto it = map.begin(); it != map.end(); ++it) {
		HRESULT res = plcs_obj->Get(_com_util::ConvertStringToBSTR(it->first.c_str()), 0, &value, &types, NULL);
		
		if (FAILED(res))throw;
		if (types != CIM_ILLEGAL)
		{

			switch (types)
			{
			case CIM_REAL32:
				
				it->second = std::to_string(value.fltVal);
				break;
			case CIM_UINT32:
				
				it->second = std::to_string(value.uintVal);
				break;
			case CIM_SINT32:
				
				it->second = std::to_string(value.intVal);
				break;
			case CIM_STRING:
				char* print = _com_util::ConvertBSTRToString(value.bstrVal);
				it->second = print;
				//delete[]print;
				break;
			}
		}
	}

}



IWbemServices *  WmiCoObject::GetServices() const
{
	return psvc_;
}

//_bstr_t WmiCoObject::QuerryText() const
//{
//	return _bstr_t(querry_.c_str());
//}
//
//
//void WmiCoObject::ResetQuerry(const char* new_querry_text_)
//{
//	querry_ = new_querry_text_;
//}

WmiCoObject::~WmiCoObject()
{
	psvc_->Release();
	ploc_->Release();
	CoUninitialize();
}
