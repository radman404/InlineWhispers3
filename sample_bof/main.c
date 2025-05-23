#include <windows.h>
#include "beacon.h"
#include "syscalls-aio.h"

void go(char* args, int length) {
    HANDLE hProcess;
    OBJECT_ATTRIBUTES oa = {sizeof(oa)};

    NTSTATUS status = Sw3NtCreateProcessEx(&hProcess, PROCESS_ALL_ACCESS, &oa, 
        (HANDLE)(LONG_PTR)-1, 0, NULL, NULL, NULL, 0);

    if (status == 0) {
        BeaconPrintf(CALLBACK_OUTPUT, "[+] NtCreateProcessEx successful");
    } else {
        BeaconPrintf(CALLBACK_ERROR, "[-] NtCreateProcessEx failed: 0x%X\n", status);
        return;
    }
}
