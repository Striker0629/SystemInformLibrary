#ifndef QUERYSINK_H
#define QUERYSINK_H
#define _WIN32_DCOM
#include<iostream>
#include<comdef.h>
#include<WbemIdl.h>
using namespace std;
#pragma comment(lib,"wbemuuid.lib")

class QuerySink :public IWbemObjectSink
{
	LONG m_l_ref;
	bool b_done;
	CRITICAL_SECTION thread_lock;
public:
	QuerySink();
	~QuerySink();
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,
		void** ppv);
	virtual HRESULT STDMETHODCALLTYPE Indicate(LONG l_object_count,
		IWbemClassObject __RPC_FAR *__RPC_FAR*ap_obj_array);
	virtual HRESULT STDMETHODCALLTYPE SetStatus(LONG l_flags,
		HRESULT h_result, BSTR str_param, IWbemClassObject __RPC_FAR *p_obj_param);
	bool IsDone();
};


#endif //QUERYSINK_H

