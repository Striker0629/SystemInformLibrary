#include "query_sink.h"

QuerySink::QuerySink():m_l_ref{0},b_done{false}
{
	InitializeCriticalSection(&thread_lock);
}

QuerySink::~QuerySink()
{
	b_done = true;
	DeleteCriticalSection(&thread_lock);
}

ULONG __stdcall QuerySink::AddRef()
{
	return InterlockedIncrement(&m_l_ref);
}

ULONG __stdcall QuerySink::Release()
{
	LONG l_ref = InterlockedDecrement(&m_l_ref);
	if (l_ref == 0)
		delete this;
	return l_ref;
}

HRESULT __stdcall QuerySink::QueryInterface(REFIID riid, void ** ppv)
{
	if (riid == IID_IUnknown || riid == IID_IWbemObjectSink)
	{
		*ppv = (IWbemObjectSink*)this;
		AddRef();
		return WBEM_S_NO_ERROR;
	}
	else return E_NOINTERFACE;
}

HRESULT __stdcall QuerySink::Indicate(LONG l_object_count, IWbemClassObject ** ap_obj_array)
{
	HRESULT hres = S_OK;
	for (int i = 0; i < l_object_count; ++i)
	{
		VARIANT var_name;
		hres = ap_obj_array[i]->Get(_bstr_t(L"Name"), 0, &var_name, 0, 0);
		if (FAILED(hres))
		{
			cerr << "Failed to get the data from the query\t"
				<< "error code=0x" << hex << hres << endl;
			return WBEM_E_FAILED;
		}
		printf("Name: %ls\n", V_BSTR(&var_name));
	}

	return WBEM_S_NO_ERROR;
}

HRESULT __stdcall QuerySink::SetStatus(LONG l_flags, HRESULT h_result, BSTR str_param, IWbemClassObject * p_obj_param)
{
	if (l_flags == WBEM_STATUS_COMPLETE)
	{
		printf("call complete.\n");
		EnterCriticalSection(&thread_lock);
		b_done = true;
		LeaveCriticalSection(&thread_lock);
	}
	else if (l_flags == WBEM_STATUS_PROGRESS)
	{
		printf("call in progress.\n");
	}
	return WBEM_S_NO_ERROR;
}

bool QuerySink::IsDone()
{
	bool done = true;
	EnterCriticalSection(&thread_lock);
	done = b_done;
	LeaveCriticalSection(&thread_lock);
	return done;

}
