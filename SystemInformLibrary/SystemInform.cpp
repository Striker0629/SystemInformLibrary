#include "SystemInform.h"



SystemInform::SystemInform():cpu_inform_{},query_{"ROOT\CIMV2"}
{

}


SystemInform::~SystemInform()
{
}

SystemInform & SystemInform::Instance()
{
	static SystemInform inf;
	return inf;
	// TODO: �������� ����� �������� return
}

//#pragma  warning(4219)