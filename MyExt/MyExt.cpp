#include "dbgext.h"
HRESULT CALLBACK
helloworld(PDEBUG_CLIENT pDebugClient, PCSTR args) {
	UNREFERENCED_PARAMETER(args);
	IDebugControl* pDebugControl;
	if (SUCCEEDED(pDebugClient->QueryInterface(__uuidof(IDebugControl),
		(void **)&pDebugControl))) {
		pDebugControl->Output(DEBUG_OUTPUT_NORMAL, "Hello World!\n");
		pDebugControl->Release();
	}
	return S_OK;
}