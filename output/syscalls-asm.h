#pragma once
#include <windows.h>

#if _WIN64





#define Sw3ZwAccessCheck Sw3NtAccessCheck
__asm__("Sw3NtAccessCheck: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x090BDE162 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x090BDE162 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWorkerFactoryWorkerReady Sw3NtWorkerFactoryWorkerReady
__asm__("Sw3NtWorkerFactoryWorkerReady: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B198C761 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B198C761 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAcceptConnectPort Sw3NtAcceptConnectPort
__asm__("Sw3NtAcceptConnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02ABE2B30 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02ABE2B30 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMapUserPhysicalPagesScatter Sw3NtMapUserPhysicalPagesScatter
__asm__("Sw3NtMapUserPhysicalPagesScatter: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x019A82701 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x019A82701 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForSingleObject Sw3NtWaitForSingleObject
__asm__("Sw3NtWaitForSingleObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AA974ACB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA974ACB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCallbackReturn Sw3NtCallbackReturn
__asm__("Sw3NtCallbackReturn: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CA9EEB09 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CA9EEB09 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReadFile Sw3NtReadFile
__asm__("Sw3NtReadFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x052D55A76 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x052D55A76 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeviceIoControlFile Sw3NtDeviceIoControlFile
__asm__("Sw3NtDeviceIoControlFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04AD55862 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04AD55862 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWriteFile Sw3NtWriteFile
__asm__("Sw3NtWriteFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09E05AED2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09E05AED2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRemoveIoCompletion Sw3NtRemoveIoCompletion
__asm__("Sw3NtRemoveIoCompletion: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x002986257 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x002986257 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReleaseSemaphore Sw3NtReleaseSemaphore
__asm__("Sw3NtReleaseSemaphore: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F7649DAB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F7649DAB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReplyWaitReceivePort Sw3NtReplyWaitReceivePort
__asm__("Sw3NtReplyWaitReceivePort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07AF2887C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07AF2887C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReplyPort Sw3NtReplyPort
__asm__("Sw3NtReplyPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x022B42B28 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x022B42B28 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationThread Sw3NtSetInformationThread
__asm__("Sw3NtSetInformationThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x014469558 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x014469558 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetEvent Sw3NtSetEvent
__asm__("Sw3NtSetEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CB6BEADD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CB6BEADD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwClose Sw3NtClose
__asm__("Sw3NtClose: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0028DF4DD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0028DF4DD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryObject Sw3NtQueryObject
__asm__("Sw3NtQueryObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03EA6CBDE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03EA6CBDE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationFile Sw3NtQueryInformationFile
__asm__("Sw3NtQueryInformationFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0583D26E6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0583D26E6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenKey Sw3NtOpenKey
__asm__("Sw3NtOpenKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02522D15D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02522D15D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnumerateValueKey Sw3NtEnumerateValueKey
__asm__("Sw3NtEnumerateValueKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x011958D8E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x011958D8E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFindAtom Sw3NtFindAtom
__asm__("Sw3NtFindAtom: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x048DE6F0C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x048DE6F0C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDefaultLocale Sw3NtQueryDefaultLocale
__asm__("Sw3NtQueryDefaultLocale: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A6AAFC1D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A6AAFC1D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryKey Sw3NtQueryKey
__asm__("Sw3NtQueryKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x095157F77 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x095157F77 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryValueKey Sw3NtQueryValueKey
__asm__("Sw3NtQueryValueKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00FDA326C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00FDA326C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAllocateVirtualMemory Sw3NtAllocateVirtualMemory
__asm__("Sw3NtAllocateVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x041D23933 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x041D23933 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationProcess Sw3NtQueryInformationProcess
__asm__("Sw3NtQueryInformationProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08F3D6E50 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08F3D6E50 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForMultipleObjects32 Sw3NtWaitForMultipleObjects32
__asm__("Sw3NtWaitForMultipleObjects32: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0102CEE619 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0102CEE619 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWriteFileGather Sw3NtWriteFileGather
__asm__("Sw3NtWriteFileGather: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AD8D79AC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AD8D79AC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateKey Sw3NtCreateKey
__asm__("Sw3NtCreateKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AAED834C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AAED834C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFreeVirtualMemory Sw3NtFreeVirtualMemory
__asm__("Sw3NtFreeVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CF4F2620 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CF4F2620 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwImpersonateClientOfPort Sw3NtImpersonateClientOfPort
__asm__("Sw3NtImpersonateClientOfPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06EF76164 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06EF76164 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReleaseMutant Sw3NtReleaseMutant
__asm__("Sw3NtReleaseMutant: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03ED41482 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03ED41482 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationToken Sw3NtQueryInformationToken
__asm__("Sw3NtQueryInformationToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00B92515E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B92515E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRequestWaitReplyPort Sw3NtRequestWaitReplyPort
__asm__("Sw3NtRequestWaitReplyPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06AB04F60 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06AB04F60 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryVirtualMemory Sw3NtQueryVirtualMemory
__asm__("Sw3NtQueryVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C455F4EC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C455F4EC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenThreadToken Sw3NtOpenThreadToken
__asm__("Sw3NtOpenThreadToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FCA9D433 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FCA9D433 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationThread Sw3NtQueryInformationThread
__asm__("Sw3NtQueryInformationThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01AB45A1F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01AB45A1F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenProcess Sw3NtOpenProcess
__asm__("Sw3NtOpenProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00FA30E32 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00FA30E32 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationFile Sw3NtSetInformationFile
__asm__("Sw3NtSetInformationFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E3D831EF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E3D831EF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMapViewOfSection Sw3NtMapViewOfSection
__asm__("Sw3NtMapViewOfSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x034AD1A31 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x034AD1A31 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAccessCheckAndAuditAlarm Sw3NtAccessCheckAndAuditAlarm
__asm__("Sw3NtAccessCheckAndAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0923C6C70 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0923C6C70 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnmapViewOfSection Sw3NtUnmapViewOfSection
__asm__("Sw3NtUnmapViewOfSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01C343EA5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01C343EA5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReplyWaitReceivePortEx Sw3NtReplyWaitReceivePortEx
__asm__("Sw3NtReplyWaitReceivePortEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0608F3450 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0608F3450 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTerminateProcess Sw3NtTerminateProcess
__asm__("Sw3NtTerminateProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FDA3163F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FDA3163F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetEventBoostPriority Sw3NtSetEventBoostPriority
__asm__("Sw3NtSetEventBoostPriority: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02C9C407A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02C9C407A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReadFileScatter Sw3NtReadFileScatter
__asm__("Sw3NtReadFileScatter: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C3B0CE2B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C3B0CE2B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenThreadTokenEx Sw3NtOpenThreadTokenEx
__asm__("Sw3NtOpenThreadTokenEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02A9BE5CD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02A9BE5CD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenProcessTokenEx Sw3NtOpenProcessTokenEx
__asm__("Sw3NtOpenProcessTokenEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0091E59C7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0091E59C7 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryPerformanceCounter Sw3NtQueryPerformanceCounter
__asm__("Sw3NtQueryPerformanceCounter: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0BB0FC18B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BB0FC18B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnumerateKey Sw3NtEnumerateKey
__asm__("Sw3NtEnumerateKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01F997A62 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01F997A62 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenFile Sw3NtOpenFile
__asm__("Sw3NtOpenFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x054C29D70 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x054C29D70 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDelayExecution Sw3NtDelayExecution
__asm__("Sw3NtDelayExecution: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01C950239 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01C950239 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDirectoryFile Sw3NtQueryDirectoryFile
__asm__("Sw3NtQueryDirectoryFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x023B4CD31 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x023B4CD31 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySystemInformation Sw3NtQuerySystemInformation
__asm__("Sw3NtQuerySystemInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00E6A1681 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E6A1681 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenSection Sw3NtOpenSection
__asm__("Sw3NtOpenSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D30CD39E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D30CD39E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryTimer Sw3NtQueryTimer
__asm__("Sw3NtQueryTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E44735E4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E44735E4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFsControlFile Sw3NtFsControlFile
__asm__("Sw3NtFsControlFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x050DFC2E8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x050DFC2E8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWriteVirtualMemory Sw3NtWriteVirtualMemory
__asm__("Sw3NtWriteVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00992F8FD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00992F8FD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCloseObjectAuditAlarm Sw3NtCloseObjectAuditAlarm
__asm__("Sw3NtCloseObjectAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FE3CF8A8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FE3CF8A8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDuplicateObject Sw3NtDuplicateObject
__asm__("Sw3NtDuplicateObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A155AD8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A155AD8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryAttributesFile Sw3NtQueryAttributesFile
__asm__("Sw3NtQueryAttributesFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C6FC32EE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C6FC32EE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwClearEvent Sw3NtClearEvent
__asm__("Sw3NtClearEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03CA6232C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03CA6232C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReadVirtualMemory Sw3NtReadVirtualMemory
__asm__("Sw3NtReadVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x003971B07 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x003971B07 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenEvent Sw3NtOpenEvent
__asm__("Sw3NtOpenEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0973F90AD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0973F90AD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAdjustPrivilegesToken Sw3NtAdjustPrivilegesToken
__asm__("Sw3NtAdjustPrivilegesToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F3D6C176 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F3D6C176 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDuplicateToken Sw3NtDuplicateToken
__asm__("Sw3NtDuplicateToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B5918530 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B5918530 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwContinue Sw3NtContinue
__asm__("Sw3NtContinue: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C2B521F9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C2B521F9 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDefaultUILanguage Sw3NtQueryDefaultUILanguage
__asm__("Sw3NtQueryDefaultUILanguage: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0358BF32A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0358BF32A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueueApcThread Sw3NtQueueApcThread
__asm__("Sw3NtQueueApcThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C897152E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C897152E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwYieldExecution Sw3NtYieldExecution
__asm__("Sw3NtYieldExecution: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C8A3CA33 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C8A3CA33 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAddAtom Sw3NtAddAtom
__asm__("Sw3NtAddAtom: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x054C15D50 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x054C15D50 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateEvent Sw3NtCreateEvent
__asm__("Sw3NtCreateEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0014C04C4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0014C04C4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryVolumeInformationFile Sw3NtQueryVolumeInformationFile
__asm__("Sw3NtQueryVolumeInformationFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D949BA4D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D949BA4D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateSection Sw3NtCreateSection
__asm__("Sw3NtCreateSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0128C3419 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0128C3419 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushBuffersFile Sw3NtFlushBuffersFile
__asm__("Sw3NtFlushBuffersFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x038B8FF1A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x038B8FF1A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwApphelpCacheControl Sw3NtApphelpCacheControl
__asm__("Sw3NtApphelpCacheControl: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E38CFC0F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E38CFC0F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateProcessEx Sw3NtCreateProcessEx
__asm__("Sw3NtCreateProcessEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x015EB5512 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x015EB5512 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateThread Sw3NtCreateThread
__asm__("Sw3NtCreateThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00B4EDFFE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B4EDFFE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwIsProcessInJob Sw3NtIsProcessInJob
__asm__("Sw3NtIsProcessInJob: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02FD7D983 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02FD7D983 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwProtectVirtualMemory Sw3NtProtectVirtualMemory
__asm__("Sw3NtProtectVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03DA9534F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03DA9534F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySection Sw3NtQuerySection
__asm__("Sw3NtQuerySection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A8602873 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A8602873 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwResumeThread Sw3NtResumeThread
__asm__("Sw3NtResumeThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03C85E6BB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03C85E6BB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTerminateThread Sw3NtTerminateThread
__asm__("Sw3NtTerminateThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x078DC366D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x078DC366D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReadRequestData Sw3NtReadRequestData
__asm__("Sw3NtReadRequestData: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x023830CCF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x023830CCF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateFile Sw3NtCreateFile
__asm__("Sw3NtCreateFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F95E1C05 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F95E1C05 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryEvent Sw3NtQueryEvent
__asm__("Sw3NtQueryEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x016830504 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x016830504 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWriteRequestData Sw3NtWriteRequestData
__asm__("Sw3NtWriteRequestData: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0765FA36D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0765FA36D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenDirectoryObject Sw3NtOpenDirectoryObject
__asm__("Sw3NtOpenDirectoryObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0203E2EA3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0203E2EA3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAccessCheckByTypeAndAuditAlarm Sw3NtAccessCheckByTypeAndAuditAlarm
__asm__("Sw3NtAccessCheckByTypeAndAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x052D57480 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x052D57480 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForMultipleObjects Sw3NtWaitForMultipleObjects
__asm__("Sw3NtWaitForMultipleObjects: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01BE5DFD93 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01BE5DFD93 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationObject Sw3NtSetInformationObject
__asm__("Sw3NtSetInformationObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03A150AA9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03A150AA9 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelIoFile Sw3NtCancelIoFile
__asm__("Sw3NtCancelIoFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B7194803 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B7194803 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTraceEvent Sw3NtTraceEvent
__asm__("Sw3NtTraceEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x010843514 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010843514 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPowerInformation Sw3NtPowerInformation
__asm__("Sw3NtPowerInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E84EE6D5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E84EE6D5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetValueKey Sw3NtSetValueKey
__asm__("Sw3NtSetValueKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05BE22000 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05BE22000 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelTimer Sw3NtCancelTimer
__asm__("Sw3NtCancelTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x099A2E129 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x099A2E129 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetTimer Sw3NtSetTimer
__asm__("Sw3NtSetTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E044CCFD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E044CCFD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAccessCheckByType Sw3NtAccessCheckByType
__asm__("Sw3NtAccessCheckByType: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0DF07D26F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DF07D26F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAccessCheckByTypeResultList Sw3NtAccessCheckByTypeResultList
__asm__("Sw3NtAccessCheckByTypeResultList: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02EB0C9A3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02EB0C9A3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAccessCheckByTypeResultListAndAuditAlarm Sw3NtAccessCheckByTypeResultListAndAuditAlarm
__asm__("Sw3NtAccessCheckByTypeResultListAndAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09F339E5F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09F339E5F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAccessCheckByTypeResultListAndAuditAlarmByHandle Sw3NtAccessCheckByTypeResultListAndAuditAlarmByHandle
__asm__("Sw3NtAccessCheckByTypeResultListAndAuditAlarmByHandle: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0973CB876 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0973CB876 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAcquireProcessActivityReference Sw3NtAcquireProcessActivityReference
__asm__("Sw3NtAcquireProcessActivityReference: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0569AADFA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0569AADFA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAddAtomEx Sw3NtAddAtomEx
__asm__("Sw3NtAddAtomEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00990B594 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00990B594 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAddBootEntry Sw3NtAddBootEntry
__asm__("Sw3NtAddBootEntry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x049853376 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x049853376 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAddDriverEntry Sw3NtAddDriverEntry
__asm__("Sw3NtAddDriverEntry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x047EB7D28 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x047EB7D28 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAdjustGroupsToken Sw3NtAdjustGroupsToken
__asm__("Sw3NtAdjustGroupsToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01390DDCC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01390DDCC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAdjustTokenClaimsAndDeviceGroups Sw3NtAdjustTokenClaimsAndDeviceGroups
__asm__("Sw3NtAdjustTokenClaimsAndDeviceGroups: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08DC0A159 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08DC0A159 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlertResumeThread Sw3NtAlertResumeThread
__asm__("Sw3NtAlertResumeThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01E86542F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E86542F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlertThread Sw3NtAlertThread
__asm__("Sw3NtAlertThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x040E00A35 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x040E00A35 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlertThreadByThreadId Sw3NtAlertThreadByThreadId
__asm__("Sw3NtAlertThreadByThreadId: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x022D6DD4D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x022D6DD4D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAllocateLocallyUniqueId Sw3NtAllocateLocallyUniqueId
__asm__("Sw3NtAllocateLocallyUniqueId: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07F8B431A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07F8B431A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAllocateReserveObject Sw3NtAllocateReserveObject
__asm__("Sw3NtAllocateReserveObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E0BF00E2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E0BF00E2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAllocateUserPhysicalPages Sw3NtAllocateUserPhysicalPages
__asm__("Sw3NtAllocateUserPhysicalPages: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A9B6BE16 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A9B6BE16 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAllocateUuids Sw3NtAllocateUuids
__asm__("Sw3NtAllocateUuids: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AD9CDB79 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AD9CDB79 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAllocateVirtualMemoryEx Sw3NtAllocateVirtualMemoryEx
__asm__("Sw3NtAllocateVirtualMemoryEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x066E23835 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x066E23835 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcAcceptConnectPort Sw3NtAlpcAcceptConnectPort
__asm__("Sw3NtAlpcAcceptConnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E54CDEE3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E54CDEE3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcCancelMessage Sw3NtAlpcCancelMessage
__asm__("Sw3NtAlpcCancelMessage: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B111222C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B111222C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcConnectPort Sw3NtAlpcConnectPort
__asm__("Sw3NtAlpcConnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x030B61AE8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x030B61AE8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcConnectPortEx Sw3NtAlpcConnectPortEx
__asm__("Sw3NtAlpcConnectPortEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A65FF889 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A65FF889 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcCreatePort Sw3NtAlpcCreatePort
__asm__("Sw3NtAlpcCreatePort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E870C1EC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E870C1EC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcCreatePortSection Sw3NtAlpcCreatePortSection
__asm__("Sw3NtAlpcCreatePortSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09255EA9F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09255EA9F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcCreateResourceReserve Sw3NtAlpcCreateResourceReserve
__asm__("Sw3NtAlpcCreateResourceReserve: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0289B3A33 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0289B3A33 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcCreateSectionView Sw3NtAlpcCreateSectionView
__asm__("Sw3NtAlpcCreateSectionView: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x092C4A77E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x092C4A77E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcCreateSecurityContext Sw3NtAlpcCreateSecurityContext
__asm__("Sw3NtAlpcCreateSecurityContext: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F66FF3E6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F66FF3E6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcDeletePortSection Sw3NtAlpcDeletePortSection
__asm__("Sw3NtAlpcDeletePortSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A81CAD2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A81CAD2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcDeleteResourceReserve Sw3NtAlpcDeleteResourceReserve
__asm__("Sw3NtAlpcDeleteResourceReserve: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x006D95411 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x006D95411 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcDeleteSectionView Sw3NtAlpcDeleteSectionView
__asm__("Sw3NtAlpcDeleteSectionView: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0EE48D7EF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EE48D7EF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcDeleteSecurityContext Sw3NtAlpcDeleteSecurityContext
__asm__("Sw3NtAlpcDeleteSecurityContext: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x094CC5A8D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x094CC5A8D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcDisconnectPort Sw3NtAlpcDisconnectPort
__asm__("Sw3NtAlpcDisconnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E037E7BC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E037E7BC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcImpersonateClientContainerOfPort Sw3NtAlpcImpersonateClientContainerOfPort
__asm__("Sw3NtAlpcImpersonateClientContainerOfPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E477EFE8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E477EFE8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcImpersonateClientOfPort Sw3NtAlpcImpersonateClientOfPort
__asm__("Sw3NtAlpcImpersonateClientOfPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05CB4552A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05CB4552A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcOpenSenderProcess Sw3NtAlpcOpenSenderProcess
__asm__("Sw3NtAlpcOpenSenderProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0693F9773 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0693F9773 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcOpenSenderThread Sw3NtAlpcOpenSenderThread
__asm__("Sw3NtAlpcOpenSenderThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x014884C37 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x014884C37 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcQueryInformation Sw3NtAlpcQueryInformation
__asm__("Sw3NtAlpcQueryInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05CC45E55 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05CC45E55 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcQueryInformationMessage Sw3NtAlpcQueryInformationMessage
__asm__("Sw3NtAlpcQueryInformationMessage: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x027123CAB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x027123CAB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcRevokeSecurityContext Sw3NtAlpcRevokeSecurityContext
__asm__("Sw3NtAlpcRevokeSecurityContext: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x016B20D3A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x016B20D3A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcSendWaitReceivePort Sw3NtAlpcSendWaitReceivePort
__asm__("Sw3NtAlpcSendWaitReceivePort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0ED760C6B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0ED760C6B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAlpcSetInformation Sw3NtAlpcSetInformation
__asm__("Sw3NtAlpcSetInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0178A1718 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0178A1718 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAreMappedFilesTheSame Sw3NtAreMappedFilesTheSame
__asm__("Sw3NtAreMappedFilesTheSame: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B1909816 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B1909816 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAssignProcessToJobObject Sw3NtAssignProcessToJobObject
__asm__("Sw3NtAssignProcessToJobObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x008946A49 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x008946A49 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAssociateWaitCompletionPacket Sw3NtAssociateWaitCompletionPacket
__asm__("Sw3NtAssociateWaitCompletionPacket: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07B5C01B1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07B5C01B1 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCallEnclave Sw3NtCallEnclave
__asm__("Sw3NtCallEnclave: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03AAA5638 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03AAA5638 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelIoFileEx Sw3NtCancelIoFileEx
__asm__("Sw3NtCancelIoFileEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E51A3345 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E51A3345 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelSynchronousIoFile Sw3NtCancelSynchronousIoFile
__asm__("Sw3NtCancelSynchronousIoFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x055DC6B49 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x055DC6B49 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelTimer2 Sw3NtCancelTimer2
__asm__("Sw3NtCancelTimer2: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B03B31EC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B03B31EC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelWaitCompletionPacket Sw3NtCancelWaitCompletionPacket
__asm__("Sw3NtCancelWaitCompletionPacket: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x029AC4F7E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x029AC4F7E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCommitComplete Sw3NtCommitComplete
__asm__("Sw3NtCommitComplete: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04EB13672 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04EB13672 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCommitEnlistment Sw3NtCommitEnlistment
__asm__("Sw3NtCommitEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x033BB262D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x033BB262D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCommitRegistryTransaction Sw3NtCommitRegistryTransaction
__asm__("Sw3NtCommitRegistryTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01E58D104 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E58D104 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCommitTransaction Sw3NtCommitTransaction
__asm__("Sw3NtCommitTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D8822BC6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D8822BC6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCompactKeys Sw3NtCompactKeys
__asm__("Sw3NtCompactKeys: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x059B04422 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x059B04422 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCompareObjects Sw3NtCompareObjects
__asm__("Sw3NtCompareObjects: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x081ADB90F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x081ADB90F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCompareSigningLevels Sw3NtCompareSigningLevels
__asm__("Sw3NtCompareSigningLevels: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A21BE2CE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A21BE2CE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCompareTokens Sw3NtCompareTokens
__asm__("Sw3NtCompareTokens: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x077D6695B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x077D6695B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCompleteConnectPort Sw3NtCompleteConnectPort
__asm__("Sw3NtCompleteConnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x064F16F6E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x064F16F6E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCompressKey Sw3NtCompressKey
__asm__("Sw3NtCompressKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x088CD5F92 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x088CD5F92 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwConnectPort Sw3NtConnectPort
__asm__("Sw3NtConnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x058F15B7E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x058F15B7E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwConvertBetweenAuxiliaryCounterAndPerformanceCounter Sw3NtConvertBetweenAuxiliaryCounterAndPerformanceCounter
__asm__("Sw3NtConvertBetweenAuxiliaryCounterAndPerformanceCounter: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E7D6389A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E7D6389A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateDebugObject Sw3NtCreateDebugObject
__asm__("Sw3NtCreateDebugObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00E33E64F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E33E64F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateDirectoryObject Sw3NtCreateDirectoryObject
__asm__("Sw3NtCreateDirectoryObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x018A42619 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018A42619 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateDirectoryObjectEx Sw3NtCreateDirectoryObjectEx
__asm__("Sw3NtCreateDirectoryObjectEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B0BCC246 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B0BCC246 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateEnclave Sw3NtCreateEnclave
__asm__("Sw3NtCreateEnclave: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0135CE116 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0135CE116 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateEnlistment Sw3NtCreateEnlistment
__asm__("Sw3NtCreateEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x079E37869 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x079E37869 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateEventPair Sw3NtCreateEventPair
__asm__("Sw3NtCreateEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01235DE6F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01235DE6F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateIRTimer Sw3NtCreateIRTimer
__asm__("Sw3NtCreateIRTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x005963FDE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x005963FDE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateIoCompletion Sw3NtCreateIoCompletion
__asm__("Sw3NtCreateIoCompletion: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00F296DB8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F296DB8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateJobObject Sw3NtCreateJobObject
__asm__("Sw3NtCreateJobObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09655BEE9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09655BEE9 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateJobSet Sw3NtCreateJobSet
__asm__("Sw3NtCreateJobSet: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00716F85D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00716F85D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateKeyTransacted Sw3NtCreateKeyTransacted
__asm__("Sw3NtCreateKeyTransacted: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x060BC2262 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x060BC2262 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateKeyedEvent Sw3NtCreateKeyedEvent
__asm__("Sw3NtCreateKeyedEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04F0D5284 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04F0D5284 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateLowBoxToken Sw3NtCreateLowBoxToken
__asm__("Sw3NtCreateLowBoxToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01A5200DF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A5200DF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateMailslotFile Sw3NtCreateMailslotFile
__asm__("Sw3NtCreateMailslotFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0393CB028 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0393CB028 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateMutant Sw3NtCreateMutant
__asm__("Sw3NtCreateMutant: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D10CD69F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D10CD69F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateNamedPipeFile Sw3NtCreateNamedPipeFile
__asm__("Sw3NtCreateNamedPipeFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01E5CE906 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E5CE906 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreatePagingFile Sw3NtCreatePagingFile
__asm__("Sw3NtCreatePagingFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E5659673 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E5659673 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreatePartition Sw3NtCreatePartition
__asm__("Sw3NtCreatePartition: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00B4E678C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B4E678C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreatePort Sw3NtCreatePort
__asm__("Sw3NtCreatePort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E570FAE3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E570FAE3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreatePrivateNamespace Sw3NtCreatePrivateNamespace
__asm__("Sw3NtCreatePrivateNamespace: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x017332B6A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x017332B6A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateProcess Sw3NtCreateProcess
__asm__("Sw3NtCreateProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x019A80240 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x019A80240 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateProfile Sw3NtCreateProfile
__asm__("Sw3NtCreateProfile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x074B7122C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x074B7122C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateProfileEx Sw3NtCreateProfileEx
__asm__("Sw3NtCreateProfileEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0409A1C4F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0409A1C4F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateRegistryTransaction Sw3NtCreateRegistryTransaction
__asm__("Sw3NtCreateRegistryTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CC9E2602 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC9E2602 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateResourceManager Sw3NtCreateResourceManager
__asm__("Sw3NtCreateResourceManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x035E66124 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x035E66124 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateSemaphore Sw3NtCreateSemaphore
__asm__("Sw3NtCreateSemaphore: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0742656EA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0742656EA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateSymbolicLinkObject Sw3NtCreateSymbolicLinkObject
__asm__("Sw3NtCreateSymbolicLinkObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x010BD4667 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010BD4667 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateThreadEx Sw3NtCreateThreadEx
__asm__("Sw3NtCreateThreadEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x052B396EE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x052B396EE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateTimer Sw3NtCreateTimer
__asm__("Sw3NtCreateTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07DC783AF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07DC783AF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateTimer2 Sw3NtCreateTimer2
__asm__("Sw3NtCreateTimer2: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D2BA19AC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D2BA19AC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateToken Sw3NtCreateToken
__asm__("Sw3NtCreateToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x071D583B5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x071D583B5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateTokenEx Sw3NtCreateTokenEx
__asm__("Sw3NtCreateTokenEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0786322BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0786322BE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateTransaction Sw3NtCreateTransaction
__asm__("Sw3NtCreateTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01774D223 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01774D223 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateTransactionManager Sw3NtCreateTransactionManager
__asm__("Sw3NtCreateTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x011B13D28 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x011B13D28 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateUserProcess Sw3NtCreateUserProcess
__asm__("Sw3NtCreateUserProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09E34A7BB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09E34A7BB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateWaitCompletionPacket Sw3NtCreateWaitCompletionPacket
__asm__("Sw3NtCreateWaitCompletionPacket: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B96399DE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B96399DE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateWaitablePort Sw3NtCreateWaitablePort
__asm__("Sw3NtCreateWaitablePort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A4B64F29 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A4B64F29 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateWnfStateName Sw3NtCreateWnfStateName
__asm__("Sw3NtCreateWnfStateName: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x074924D47 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x074924D47 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateWorkerFactory Sw3NtCreateWorkerFactory
__asm__("Sw3NtCreateWorkerFactory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x001151588 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x001151588 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDebugActiveProcess Sw3NtDebugActiveProcess
__asm__("Sw3NtDebugActiveProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x025952408 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x025952408 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDebugContinue Sw3NtDebugContinue
__asm__("Sw3NtDebugContinue: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D670918C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D670918C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteAtom Sw3NtDeleteAtom
__asm__("Sw3NtDeleteAtom: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x034A2D02B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x034A2D02B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteBootEntry Sw3NtDeleteBootEntry
__asm__("Sw3NtDeleteBootEntry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x009841114 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x009841114 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteDriverEntry Sw3NtDeleteDriverEntry
__asm__("Sw3NtDeleteDriverEntry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x003920900 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x003920900 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteFile Sw3NtDeleteFile
__asm__("Sw3NtDeleteFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x004B5CCE7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004B5CCE7 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteKey Sw3NtDeleteKey
__asm__("Sw3NtDeleteKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01A4EC31C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A4EC31C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteObjectAuditAlarm Sw3NtDeleteObjectAuditAlarm
__asm__("Sw3NtDeleteObjectAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CC93EE5E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC93EE5E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeletePrivateNamespace Sw3NtDeletePrivateNamespace
__asm__("Sw3NtDeletePrivateNamespace: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x011BDE62F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x011BDE62F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteValueKey Sw3NtDeleteValueKey
__asm__("Sw3NtDeleteValueKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02E9B310C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02E9B310C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteWnfStateData Sw3NtDeleteWnfStateData
__asm__("Sw3NtDeleteWnfStateData: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x062DD908C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x062DD908C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDeleteWnfStateName Sw3NtDeleteWnfStateName
__asm__("Sw3NtDeleteWnfStateName: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x004CB81D3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004CB81D3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDisableLastKnownGood Sw3NtDisableLastKnownGood
__asm__("Sw3NtDisableLastKnownGood: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x007B88DAE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x007B88DAE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDisplayString Sw3NtDisplayString
__asm__("Sw3NtDisplayString: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FACDACF0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FACDACF0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwDrawText Sw3NtDrawText
__asm__("Sw3NtDrawText: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A2DD8D4F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A2DD8D4F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnableLastKnownGood Sw3NtEnableLastKnownGood
__asm__("Sw3NtEnableLastKnownGood: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x029BA1D12 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x029BA1D12 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnumerateBootEntries Sw3NtEnumerateBootEntries
__asm__("Sw3NtEnumerateBootEntries: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F965FEF2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F965FEF2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnumerateDriverEntries Sw3NtEnumerateDriverEntries
__asm__("Sw3NtEnumerateDriverEntries: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00126F94D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00126F94D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnumerateSystemEnvironmentValuesEx Sw3NtEnumerateSystemEnvironmentValuesEx
__asm__("Sw3NtEnumerateSystemEnvironmentValuesEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F160323B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F160323B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwEnumerateTransactionObject Sw3NtEnumerateTransactionObject
__asm__("Sw3NtEnumerateTransactionObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x084B9B415 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x084B9B415 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwExtendSection Sw3NtExtendSection
__asm__("Sw3NtExtendSection: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F76CD7F2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F76CD7F2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFilterBootOption Sw3NtFilterBootOption
__asm__("Sw3NtFilterBootOption: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0048823DD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0048823DD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFilterToken Sw3NtFilterToken
__asm__("Sw3NtFilterToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00D950306 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00D950306 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFilterTokenEx Sw3NtFilterTokenEx
__asm__("Sw3NtFilterTokenEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00691504E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00691504E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushBuffersFileEx Sw3NtFlushBuffersFileEx
__asm__("Sw3NtFlushBuffersFileEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04DA38117 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04DA38117 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushInstallUILanguage Sw3NtFlushInstallUILanguage
__asm__("Sw3NtFlushInstallUILanguage: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C415F3C9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C415F3C9 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushInstructionCache Sw3NtFlushInstructionCache
__asm__("Sw3NtFlushInstructionCache: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x069BE1567 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x069BE1567 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushKey Sw3NtFlushKey
__asm__("Sw3NtFlushKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08491A72B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08491A72B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushProcessWriteBuffers Sw3NtFlushProcessWriteBuffers
__asm__("Sw3NtFlushProcessWriteBuffers: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0405C4CC4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0405C4CC4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushVirtualMemory Sw3NtFlushVirtualMemory
__asm__("Sw3NtFlushVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00D964559 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00D964559 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFlushWriteBuffer Sw3NtFlushWriteBuffer
__asm__("Sw3NtFlushWriteBuffer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01282CC22 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01282CC22 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFreeUserPhysicalPages Sw3NtFreeUserPhysicalPages
__asm__("Sw3NtFreeUserPhysicalPages: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FF61E8E2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FF61E8E2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFreezeRegistry Sw3NtFreezeRegistry
__asm__("Sw3NtFreezeRegistry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x002DA7A2B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x002DA7A2B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwFreezeTransactions Sw3NtFreezeTransactions
__asm__("Sw3NtFreezeTransactions: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04BDBA8CD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04BDBA8CD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetCachedSigningLevel Sw3NtGetCachedSigningLevel
__asm__("Sw3NtGetCachedSigningLevel: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0989B1BA4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0989B1BA4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetCompleteWnfStateSubscription Sw3NtGetCompleteWnfStateSubscription
__asm__("Sw3NtGetCompleteWnfStateSubscription: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A922E03 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A922E03 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetContextThread Sw3NtGetContextThread
__asm__("Sw3NtGetContextThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E84FA6ED \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E84FA6ED \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetCurrentProcessorNumber Sw3NtGetCurrentProcessorNumber
__asm__("Sw3NtGetCurrentProcessorNumber: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x007AAEEF2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x007AAEEF2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetCurrentProcessorNumberEx Sw3NtGetCurrentProcessorNumberEx
__asm__("Sw3NtGetCurrentProcessorNumberEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07F57B303 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07F57B303 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetDevicePowerState Sw3NtGetDevicePowerState
__asm__("Sw3NtGetDevicePowerState: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08D9DED10 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08D9DED10 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetMUIRegistryInfo Sw3NtGetMUIRegistryInfo
__asm__("Sw3NtGetMUIRegistryInfo: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x084BFA417 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x084BFA417 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetNextProcess Sw3NtGetNextProcess
__asm__("Sw3NtGetNextProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x005AB0E34 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x005AB0E34 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetNextThread Sw3NtGetNextThread
__asm__("Sw3NtGetNextThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01C304109 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01C304109 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetNlsSectionPtr Sw3NtGetNlsSectionPtr
__asm__("Sw3NtGetNlsSectionPtr: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B512DB0E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B512DB0E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetNotificationResourceManager Sw3NtGetNotificationResourceManager
__asm__("Sw3NtGetNotificationResourceManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x029BEF3F6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x029BEF3F6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetWriteWatch Sw3NtGetWriteWatch
__asm__("Sw3NtGetWriteWatch: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E749E9DF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E749E9DF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwImpersonateAnonymousToken Sw3NtImpersonateAnonymousToken
__asm__("Sw3NtImpersonateAnonymousToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06FD97754 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06FD97754 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwImpersonateThread Sw3NtImpersonateThread
__asm__("Sw3NtImpersonateThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x089284184 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x089284184 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwInitializeEnclave Sw3NtInitializeEnclave
__asm__("Sw3NtInitializeEnclave: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06AB60A7C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06AB60A7C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwInitializeNlsFiles Sw3NtInitializeNlsFiles
__asm__("Sw3NtInitializeNlsFiles: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x096B3A70C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x096B3A70C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwInitializeRegistry Sw3NtInitializeRegistry
__asm__("Sw3NtInitializeRegistry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x012990011 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x012990011 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwInitiatePowerAction Sw3NtInitiatePowerAction
__asm__("Sw3NtInitiatePowerAction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08C178E87 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08C178E87 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwIsSystemResumeAutomatic Sw3NtIsSystemResumeAutomatic
__asm__("Sw3NtIsSystemResumeAutomatic: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01EB92B2E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01EB92B2E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwIsUILanguageComitted Sw3NtIsUILanguageComitted
__asm__("Sw3NtIsUILanguageComitted: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0161A2485 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0161A2485 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwListenPort Sw3NtListenPort
__asm__("Sw3NtListenPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A23199FE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A23199FE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLoadDriver Sw3NtLoadDriver
__asm__("Sw3NtLoadDriver: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E447D09E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E447D09E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLoadEnclaveData Sw3NtLoadEnclaveData
__asm__("Sw3NtLoadEnclaveData: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0BD034913 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BD034913 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLoadHotPatch Sw3NtLoadHotPatch
__asm__("Sw3NtLoadHotPatch: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E4BF28EC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E4BF28EC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLoadKey Sw3NtLoadKey
__asm__("Sw3NtLoadKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C13CC0A4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C13CC0A4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLoadKey2 Sw3NtLoadKey2
__asm__("Sw3NtLoadKey2: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x065FDAE60 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x065FDAE60 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLoadKeyEx Sw3NtLoadKeyEx
__asm__("Sw3NtLoadKeyEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00B98CCC7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B98CCC7 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLockFile Sw3NtLockFile
__asm__("Sw3NtLockFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01AD9107E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01AD9107E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLockProductActivationKeys Sw3NtLockProductActivationKeys
__asm__("Sw3NtLockProductActivationKeys: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04AD7A349 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04AD7A349 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLockRegistryKey Sw3NtLockRegistryKey
__asm__("Sw3NtLockRegistryKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0172102BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0172102BE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwLockVirtualMemory Sw3NtLockVirtualMemory
__asm__("Sw3NtLockVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B1ADA932 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B1ADA932 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMakePermanentObject Sw3NtMakePermanentObject
__asm__("Sw3NtMakePermanentObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x012BC4C11 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x012BC4C11 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMakeTemporaryObject Sw3NtMakeTemporaryObject
__asm__("Sw3NtMakeTemporaryObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x074591ABA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x074591ABA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwManagePartition Sw3NtManagePartition
__asm__("Sw3NtManagePartition: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00C9C6847 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00C9C6847 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMapCMFModule Sw3NtMapCMFModule
__asm__("Sw3NtMapCMFModule: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x054DC6E5C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x054DC6E5C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMapUserPhysicalPages Sw3NtMapUserPhysicalPages
__asm__("Sw3NtMapUserPhysicalPages: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09EA0B300 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09EA0B300 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMapViewOfSectionEx Sw3NtMapViewOfSectionEx
__asm__("Sw3NtMapViewOfSectionEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0169D6260 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0169D6260 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwModifyBootEntry Sw3NtModifyBootEntry
__asm__("Sw3NtModifyBootEntry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0099D1D02 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0099D1D02 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwModifyDriverEntry Sw3NtModifyDriverEntry
__asm__("Sw3NtModifyDriverEntry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x031E02178 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x031E02178 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwNotifyChangeDirectoryFile Sw3NtNotifyChangeDirectoryFile
__asm__("Sw3NtNotifyChangeDirectoryFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x024B4D4EF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024B4D4EF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwNotifyChangeDirectoryFileEx Sw3NtNotifyChangeDirectoryFileEx
__asm__("Sw3NtNotifyChangeDirectoryFileEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C05A2120 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C05A2120 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwNotifyChangeKey Sw3NtNotifyChangeKey
__asm__("Sw3NtNotifyChangeKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AA9AA900 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA9AA900 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwNotifyChangeMultipleKeys Sw3NtNotifyChangeMultipleKeys
__asm__("Sw3NtNotifyChangeMultipleKeys: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B433BF47 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B433BF47 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwNotifyChangeSession Sw3NtNotifyChangeSession
__asm__("Sw3NtNotifyChangeSession: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0178CD9D0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0178CD9D0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenEnlistment Sw3NtOpenEnlistment
__asm__("Sw3NtOpenEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C9E33DA4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C9E33DA4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenEventPair Sw3NtOpenEventPair
__asm__("Sw3NtOpenEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05EE36E41 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05EE36E41 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenIoCompletion Sw3NtOpenIoCompletion
__asm__("Sw3NtOpenIoCompletion: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C2EDE2B3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C2EDE2B3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenJobObject Sw3NtOpenJobObject
__asm__("Sw3NtOpenJobObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00738FD36 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00738FD36 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenKeyEx Sw3NtOpenKeyEx
__asm__("Sw3NtOpenKeyEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FC7F0902 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FC7F0902 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenKeyTransacted Sw3NtOpenKeyTransacted
__asm__("Sw3NtOpenKeyTransacted: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D09DB644 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D09DB644 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenKeyTransactedEx Sw3NtOpenKeyTransactedEx
__asm__("Sw3NtOpenKeyTransactedEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E8D8A821 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E8D8A821 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenKeyedEvent Sw3NtOpenKeyedEvent
__asm__("Sw3NtOpenKeyedEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x048CA4B5C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x048CA4B5C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenMutant Sw3NtOpenMutant
__asm__("Sw3NtOpenMutant: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CD8FA06E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CD8FA06E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenObjectAuditAlarm Sw3NtOpenObjectAuditAlarm
__asm__("Sw3NtOpenObjectAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09E30605C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09E30605C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenPartition Sw3NtOpenPartition
__asm__("Sw3NtOpenPartition: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0DB441A16 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DB441A16 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenPrivateNamespace Sw3NtOpenPrivateNamespace
__asm__("Sw3NtOpenPrivateNamespace: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CACEFD5D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CACEFD5D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenProcessToken Sw3NtOpenProcessToken
__asm__("Sw3NtOpenProcessToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00396888F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00396888F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenRegistryTransaction Sw3NtOpenRegistryTransaction
__asm__("Sw3NtOpenRegistryTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A1D34B5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A1D34B5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenResourceManager Sw3NtOpenResourceManager
__asm__("Sw3NtOpenResourceManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A929FB0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A929FB0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenSemaphore Sw3NtOpenSemaphore
__asm__("Sw3NtOpenSemaphore: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D8880239 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D8880239 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenSession Sw3NtOpenSession
__asm__("Sw3NtOpenSession: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09E05BC99 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09E05BC99 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenSymbolicLinkObject Sw3NtOpenSymbolicLinkObject
__asm__("Sw3NtOpenSymbolicLinkObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00406029B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00406029B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenThread Sw3NtOpenThread
__asm__("Sw3NtOpenThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0020050BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0020050BE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenTimer Sw3NtOpenTimer
__asm__("Sw3NtOpenTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x004130C89 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004130C89 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenTransaction Sw3NtOpenTransaction
__asm__("Sw3NtOpenTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D20DF2D3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D20DF2D3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwOpenTransactionManager Sw3NtOpenTransactionManager
__asm__("Sw3NtOpenTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0192279D1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0192279D1 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPlugPlayControl Sw3NtPlugPlayControl
__asm__("Sw3NtPlugPlayControl: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00791E1C3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00791E1C3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrePrepareComplete Sw3NtPrePrepareComplete
__asm__("Sw3NtPrePrepareComplete: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02CD0DB5C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02CD0DB5C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrePrepareEnlistment Sw3NtPrePrepareEnlistment
__asm__("Sw3NtPrePrepareEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00CB6CCC5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00CB6CCC5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrepareComplete Sw3NtPrepareComplete
__asm__("Sw3NtPrepareComplete: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x048D1B28E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x048D1B28E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrepareEnlistment Sw3NtPrepareEnlistment
__asm__("Sw3NtPrepareEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0098CC9DB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0098CC9DB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrivilegeCheck Sw3NtPrivilegeCheck
__asm__("Sw3NtPrivilegeCheck: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01AB5D195 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01AB5D195 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrivilegeObjectAuditAlarm Sw3NtPrivilegeObjectAuditAlarm
__asm__("Sw3NtPrivilegeObjectAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D2D5D440 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D2D5D440 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPrivilegedServiceAuditAlarm Sw3NtPrivilegedServiceAuditAlarm
__asm__("Sw3NtPrivilegedServiceAuditAlarm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D6B931EE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D6B931EE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPropagationComplete Sw3NtPropagationComplete
__asm__("Sw3NtPropagationComplete: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0ACB0C7BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0ACB0C7BE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPropagationFailed Sw3NtPropagationFailed
__asm__("Sw3NtPropagationFailed: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02196A18A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02196A18A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPulseEvent Sw3NtPulseEvent
__asm__("Sw3NtPulseEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0020513EF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0020513EF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryAuxiliaryCounterFrequency Sw3NtQueryAuxiliaryCounterFrequency
__asm__("Sw3NtQueryAuxiliaryCounterFrequency: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x077470AC1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x077470AC1 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryBootEntryOrder Sw3NtQueryBootEntryOrder
__asm__("Sw3NtQueryBootEntryOrder: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08B9E7C9A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08B9E7C9A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryBootOptions Sw3NtQueryBootOptions
__asm__("Sw3NtQueryBootOptions: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A9BE4C6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A9BE4C6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDebugFilterState Sw3NtQueryDebugFilterState
__asm__("Sw3NtQueryDebugFilterState: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x032903C34 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x032903C34 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDirectoryFileEx Sw3NtQueryDirectoryFileEx
__asm__("Sw3NtQueryDirectoryFileEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07682ACD0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07682ACD0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDirectoryObject Sw3NtQueryDirectoryObject
__asm__("Sw3NtQueryDirectoryObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04B637DD9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04B637DD9 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryDriverEntryOrder Sw3NtQueryDriverEntryOrder
__asm__("Sw3NtQueryDriverEntryOrder: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09B396272 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09B396272 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryEaFile Sw3NtQueryEaFile
__asm__("Sw3NtQueryEaFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FDDC2DE8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FDDC2DE8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryFullAttributesFile Sw3NtQueryFullAttributesFile
__asm__("Sw3NtQueryFullAttributesFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x008B96472 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x008B96472 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationAtom Sw3NtQueryInformationAtom
__asm__("Sw3NtQueryInformationAtom: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D13DB435 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D13DB435 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationByName Sw3NtQueryInformationByName
__asm__("Sw3NtQueryInformationByName: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B8D9C539 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B8D9C539 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationEnlistment Sw3NtQueryInformationEnlistment
__asm__("Sw3NtQueryInformationEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D651E9F2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D651E9F2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationJobObject Sw3NtQueryInformationJobObject
__asm__("Sw3NtQueryInformationJobObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0DB44F9DA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DB44F9DA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationPort Sw3NtQueryInformationPort
__asm__("Sw3NtQueryInformationPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A538AABB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A538AABB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationResourceManager Sw3NtQueryInformationResourceManager
__asm__("Sw3NtQueryInformationResourceManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01EB789B6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01EB789B6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationTransaction Sw3NtQueryInformationTransaction
__asm__("Sw3NtQueryInformationTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x076EC1431 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x076EC1431 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationTransactionManager Sw3NtQueryInformationTransactionManager
__asm__("Sw3NtQueryInformationTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x029B0E7E0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x029B0E7E0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInformationWorkerFactory Sw3NtQueryInformationWorkerFactory
__asm__("Sw3NtQueryInformationWorkerFactory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00C5218CF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00C5218CF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryInstallUILanguage Sw3NtQueryInstallUILanguage
__asm__("Sw3NtQueryInstallUILanguage: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A8365A2B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A8365A2B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryIntervalProfile Sw3NtQueryIntervalProfile
__asm__("Sw3NtQueryIntervalProfile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09E3C579E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09E3C579E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryIoCompletion Sw3NtQueryIoCompletion
__asm__("Sw3NtQueryIoCompletion: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08C96EA06 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08C96EA06 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryLicenseValue Sw3NtQueryLicenseValue
__asm__("Sw3NtQueryLicenseValue: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07A91453E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07A91453E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryMultipleValueKey Sw3NtQueryMultipleValueKey
__asm__("Sw3NtQueryMultipleValueKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00AFB1769 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00AFB1769 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryMutant Sw3NtQueryMutant
__asm__("Sw3NtQueryMutant: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0963399A0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0963399A0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryOpenSubKeys Sw3NtQueryOpenSubKeys
__asm__("Sw3NtQueryOpenSubKeys: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0EEBBE53D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EEBBE53D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryOpenSubKeysEx Sw3NtQueryOpenSubKeysEx
__asm__("Sw3NtQueryOpenSubKeysEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00B87C6D3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B87C6D3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryPortInformationProcess Sw3NtQueryPortInformationProcess
__asm__("Sw3NtQueryPortInformationProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0772C96B0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0772C96B0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryQuotaInformationFile Sw3NtQueryQuotaInformationFile
__asm__("Sw3NtQueryQuotaInformationFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x010947812 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010947812 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySecurityAttributesToken Sw3NtQuerySecurityAttributesToken
__asm__("Sw3NtQuerySecurityAttributesToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C95FC9FE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C95FC9FE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySecurityObject Sw3NtQuerySecurityObject
__asm__("Sw3NtQuerySecurityObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08BB5B9FB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08BB5B9FB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySecurityPolicy Sw3NtQuerySecurityPolicy
__asm__("Sw3NtQuerySecurityPolicy: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x091ABB6F7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x091ABB6F7 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySemaphore Sw3NtQuerySemaphore
__asm__("Sw3NtQuerySemaphore: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08716AD59 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08716AD59 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySymbolicLinkObject Sw3NtQuerySymbolicLinkObject
__asm__("Sw3NtQuerySymbolicLinkObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x086B9BEF5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x086B9BEF5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySystemEnvironmentValue Sw3NtQuerySystemEnvironmentValue
__asm__("Sw3NtQuerySystemEnvironmentValue: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0069D86B6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0069D86B6 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySystemEnvironmentValueEx Sw3NtQuerySystemEnvironmentValueEx
__asm__("Sw3NtQuerySystemEnvironmentValueEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0002A4CFF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0002A4CFF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySystemInformationEx Sw3NtQuerySystemInformationEx
__asm__("Sw3NtQuerySystemInformationEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x010EA582A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010EA582A \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryTimerResolution Sw3NtQueryTimerResolution
__asm__("Sw3NtQueryTimerResolution: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x012081297 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x012081297 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryWnfStateData Sw3NtQueryWnfStateData
__asm__("Sw3NtQueryWnfStateData: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C685D537 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C685D537 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueryWnfStateNameInformation Sw3NtQueryWnfStateNameInformation
__asm__("Sw3NtQueryWnfStateNameInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x018037A0F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018037A0F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQueueApcThreadEx Sw3NtQueueApcThreadEx
__asm__("Sw3NtQueueApcThreadEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x055B8097C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x055B8097C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRaiseException Sw3NtRaiseException
__asm__("Sw3NtRaiseException: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00892543F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00892543F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRaiseHardError Sw3NtRaiseHardError
__asm__("Sw3NtRaiseHardError: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D651D7C2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D651D7C2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReadOnlyEnlistment Sw3NtReadOnlyEnlistment
__asm__("Sw3NtReadOnlyEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x069D16043 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x069D16043 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRecoverEnlistment Sw3NtRecoverEnlistment
__asm__("Sw3NtRecoverEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x071EE9685 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x071EE9685 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRecoverResourceManager Sw3NtRecoverResourceManager
__asm__("Sw3NtRecoverResourceManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x069B70354 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x069B70354 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRecoverTransactionManager Sw3NtRecoverTransactionManager
__asm__("Sw3NtRecoverTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06BB46528 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06BB46528 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRegisterProtocolAddressInformation Sw3NtRegisterProtocolAddressInformation
__asm__("Sw3NtRegisterProtocolAddressInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01FB52134 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01FB52134 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRegisterThreadTerminatePort Sw3NtRegisterThreadTerminatePort
__asm__("Sw3NtRegisterThreadTerminatePort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AA3EA3A2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA3EA3A2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReleaseKeyedEvent Sw3NtReleaseKeyedEvent
__asm__("Sw3NtReleaseKeyedEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07EE15774 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07EE15774 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReleaseWorkerFactoryWorker Sw3NtReleaseWorkerFactoryWorker
__asm__("Sw3NtReleaseWorkerFactoryWorker: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x094A3F471 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x094A3F471 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRemoveIoCompletionEx Sw3NtRemoveIoCompletionEx
__asm__("Sw3NtRemoveIoCompletionEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06CCEA288 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06CCEA288 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRemoveProcessDebug Sw3NtRemoveProcessDebug
__asm__("Sw3NtRemoveProcessDebug: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04024538C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04024538C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRenameKey Sw3NtRenameKey
__asm__("Sw3NtRenameKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06AFA85AD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06AFA85AD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRenameTransactionManager Sw3NtRenameTransactionManager
__asm__("Sw3NtRenameTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0633CAD60 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0633CAD60 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReplaceKey Sw3NtReplaceKey
__asm__("Sw3NtReplaceKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05EE37B7F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05EE37B7F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReplacePartitionUnit Sw3NtReplacePartitionUnit
__asm__("Sw3NtReplacePartitionUnit: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F778C9F1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F778C9F1 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReplyWaitReplyPort Sw3NtReplyWaitReplyPort
__asm__("Sw3NtReplyWaitReplyPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x062F05F50 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x062F05F50 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRequestPort Sw3NtRequestPort
__asm__("Sw3NtRequestPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06EF0676E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06EF0676E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwResetEvent Sw3NtResetEvent
__asm__("Sw3NtResetEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08A2195B2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08A2195B2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwResetWriteWatch Sw3NtResetWriteWatch
__asm__("Sw3NtResetWriteWatch: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01C429076 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01C429076 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRestoreKey Sw3NtRestoreKey
__asm__("Sw3NtRestoreKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07EAA1F50 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07EAA1F50 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwResumeProcess Sw3NtResumeProcess
__asm__("Sw3NtResumeProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D12F37BA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D12F37BA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRevertContainerImpersonation Sw3NtRevertContainerImpersonation
__asm__("Sw3NtRevertContainerImpersonation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05EC85E5F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05EC85E5F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRollbackComplete Sw3NtRollbackComplete
__asm__("Sw3NtRollbackComplete: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0964B681E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0964B681E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRollbackEnlistment Sw3NtRollbackEnlistment
__asm__("Sw3NtRollbackEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00F96E984 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F96E984 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRollbackRegistryTransaction Sw3NtRollbackRegistryTransaction
__asm__("Sw3NtRollbackRegistryTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02CA8701B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02CA8701B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRollbackTransaction Sw3NtRollbackTransaction
__asm__("Sw3NtRollbackTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00D450DD4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00D450DD4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRollforwardTransactionManager Sw3NtRollforwardTransactionManager
__asm__("Sw3NtRollforwardTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x005C180D2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x005C180D2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSaveKey Sw3NtSaveKey
__asm__("Sw3NtSaveKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x066FE5744 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x066FE5744 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSaveKeyEx Sw3NtSaveKeyEx
__asm__("Sw3NtSaveKeyEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x031BBFDCF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x031BBFDCF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSaveMergedKeys Sw3NtSaveMergedKeys
__asm__("Sw3NtSaveMergedKeys: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02AB6171D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02AB6171D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSecureConnectPort Sw3NtSecureConnectPort
__asm__("Sw3NtSecureConnectPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0DE4DC7A0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DE4DC7A0 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSerializeBoot Sw3NtSerializeBoot
__asm__("Sw3NtSerializeBoot: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0329C2233 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0329C2233 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetBootEntryOrder Sw3NtSetBootEntryOrder
__asm__("Sw3NtSetBootEntryOrder: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x073CD5B57 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x073CD5B57 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetBootOptions Sw3NtSetBootOptions
__asm__("Sw3NtSetBootOptions: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x017953D01 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x017953D01 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetCachedSigningLevel Sw3NtSetCachedSigningLevel
__asm__("Sw3NtSetCachedSigningLevel: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0207226C3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0207226C3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetCachedSigningLevel2 Sw3NtSetCachedSigningLevel2
__asm__("Sw3NtSetCachedSigningLevel2: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E3526281 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E3526281 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetContextThread Sw3NtSetContextThread
__asm__("Sw3NtSetContextThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x034963C39 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x034963C39 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetDebugFilterState Sw3NtSetDebugFilterState
__asm__("Sw3NtSetDebugFilterState: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0229809D4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0229809D4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetDefaultHardErrorPort Sw3NtSetDefaultHardErrorPort
__asm__("Sw3NtSetDefaultHardErrorPort: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x024B75F38 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024B75F38 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetDefaultLocale Sw3NtSetDefaultLocale
__asm__("Sw3NtSetDefaultLocale: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x043DE7109 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x043DE7109 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetDefaultUILanguage Sw3NtSetDefaultUILanguage
__asm__("Sw3NtSetDefaultUILanguage: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A91B6FBA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A91B6FBA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetDriverEntryOrder Sw3NtSetDriverEntryOrder
__asm__("Sw3NtSetDriverEntryOrder: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0218D1735 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0218D1735 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetEaFile Sw3NtSetEaFile
__asm__("Sw3NtSetEaFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03E6540BD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03E6540BD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetHighEventPair Sw3NtSetHighEventPair
__asm__("Sw3NtSetHighEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x074CC93A2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x074CC93A2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetHighWaitLowEventPair Sw3NtSetHighWaitLowEventPair
__asm__("Sw3NtSetHighWaitLowEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00EB0323D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00EB0323D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetIRTimer Sw3NtSetIRTimer
__asm__("Sw3NtSetIRTimer: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x027973716 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x027973716 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationDebugObject Sw3NtSetInformationDebugObject
__asm__("Sw3NtSetInformationDebugObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x068559059 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x068559059 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationEnlistment Sw3NtSetInformationEnlistment
__asm__("Sw3NtSetInformationEnlistment: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0099B2C2D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0099B2C2D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationJobObject Sw3NtSetInformationJobObject
__asm__("Sw3NtSetInformationJobObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FF54C7D8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FF54C7D8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationKey Sw3NtSetInformationKey
__asm__("Sw3NtSetInformationKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0AE9B3988 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AE9B3988 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationResourceManager Sw3NtSetInformationResourceManager
__asm__("Sw3NtSetInformationResourceManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00531159C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00531159C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationSymbolicLink Sw3NtSetInformationSymbolicLink
__asm__("Sw3NtSetInformationSymbolicLink: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F357F3C1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F357F3C1 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationToken Sw3NtSetInformationToken
__asm__("Sw3NtSetInformationToken: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07355266E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07355266E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationTransaction Sw3NtSetInformationTransaction
__asm__("Sw3NtSetInformationTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04886065F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04886065F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationTransactionManager Sw3NtSetInformationTransactionManager
__asm__("Sw3NtSetInformationTransactionManager: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0BB65C7A8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BB65C7A8 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationVirtualMemory Sw3NtSetInformationVirtualMemory
__asm__("Sw3NtSetInformationVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FB90F506 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FB90F506 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationWorkerFactory Sw3NtSetInformationWorkerFactory
__asm__("Sw3NtSetInformationWorkerFactory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0DB4AD3C5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DB4AD3C5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetIntervalProfile Sw3NtSetIntervalProfile
__asm__("Sw3NtSetIntervalProfile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F4BF6DBB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F4BF6DBB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetIoCompletion Sw3NtSetIoCompletion
__asm__("Sw3NtSetIoCompletion: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03EA41FF3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03EA41FF3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetIoCompletionEx Sw3NtSetIoCompletionEx
__asm__("Sw3NtSetIoCompletionEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A156DDD2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A156DDD2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetLdtEntries Sw3NtSetLdtEntries
__asm__("Sw3NtSetLdtEntries: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02A81C395 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02A81C395 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetLowEventPair Sw3NtSetLowEventPair
__asm__("Sw3NtSetLowEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05EB2462B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05EB2462B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetLowWaitHighEventPair Sw3NtSetLowWaitHighEventPair
__asm__("Sw3NtSetLowWaitHighEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x02232329B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02232329B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetQuotaInformationFile Sw3NtSetQuotaInformationFile
__asm__("Sw3NtSetQuotaInformationFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0DE5F0418 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DE5F0418 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetSecurityObject Sw3NtSetSecurityObject
__asm__("Sw3NtSetSecurityObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0FA40C2CC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FA40C2CC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetSystemEnvironmentValue Sw3NtSetSystemEnvironmentValue
__asm__("Sw3NtSetSystemEnvironmentValue: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03C972B1C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03C972B1C \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetSystemEnvironmentValueEx Sw3NtSetSystemEnvironmentValueEx
__asm__("Sw3NtSetSystemEnvironmentValueEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0978AC356 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0978AC356 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetSystemInformation Sw3NtSetSystemInformation
__asm__("Sw3NtSetSystemInformation: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0349A4F8F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0349A4F8F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetSystemPowerState Sw3NtSetSystemPowerState
__asm__("Sw3NtSetSystemPowerState: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01CA3F6D2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01CA3F6D2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetSystemTime Sw3NtSetSystemTime
__asm__("Sw3NtSetSystemTime: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x086A2D69F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x086A2D69F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetThreadExecutionState Sw3NtSetThreadExecutionState
__asm__("Sw3NtSetThreadExecutionState: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09D966489 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09D966489 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetTimer2 Sw3NtSetTimer2
__asm__("Sw3NtSetTimer2: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01DA4DA2D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01DA4DA2D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetTimerEx Sw3NtSetTimerEx
__asm__("Sw3NtSetTimerEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x026B9998E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x026B9998E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetTimerResolution Sw3NtSetTimerResolution
__asm__("Sw3NtSetTimerResolution: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03CAB3C3D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03CAB3C3D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetUuidSeed Sw3NtSetUuidSeed
__asm__("Sw3NtSetUuidSeed: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F1CF72F3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F1CF72F3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetVolumeInformationFile Sw3NtSetVolumeInformationFile
__asm__("Sw3NtSetVolumeInformationFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A9CC2BA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A9CC2BA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetWnfProcessNotificationEvent Sw3NtSetWnfProcessNotificationEvent
__asm__("Sw3NtSetWnfProcessNotificationEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03924D47D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03924D47D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwShutdownSystem Sw3NtShutdownSystem
__asm__("Sw3NtShutdownSystem: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x090BC8003 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x090BC8003 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwShutdownWorkerFactory Sw3NtShutdownWorkerFactory
__asm__("Sw3NtShutdownWorkerFactory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08C02BABA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08C02BABA \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSignalAndWaitForSingleObject Sw3NtSignalAndWaitForSingleObject
__asm__("Sw3NtSignalAndWaitForSingleObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07CA8145F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07CA8145F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSinglePhaseReject Sw3NtSinglePhaseReject
__asm__("Sw3NtSinglePhaseReject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x03E850E39 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03E850E39 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwStartProfile Sw3NtStartProfile
__asm__("Sw3NtStartProfile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CC9D0F3B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC9D0F3B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwStopProfile Sw3NtStopProfile
__asm__("Sw3NtStopProfile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x010B49B84 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010B49B84 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSubscribeWnfStateChange Sw3NtSubscribeWnfStateChange
__asm__("Sw3NtSubscribeWnfStateChange: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CC5EFDC4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC5EFDC4 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSuspendProcess Sw3NtSuspendProcess
__asm__("Sw3NtSuspendProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C6BBDF57 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C6BBDF57 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSuspendThread Sw3NtSuspendThread
__asm__("Sw3NtSuspendThread: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x014B83629 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x014B83629 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSystemDebugControl Sw3NtSystemDebugControl
__asm__("Sw3NtSystemDebugControl: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x047D16953 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x047D16953 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTerminateEnclave Sw3NtTerminateEnclave
__asm__("Sw3NtTerminateEnclave: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00EC2F49E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00EC2F49E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTerminateJobObject Sw3NtTerminateJobObject
__asm__("Sw3NtTerminateJobObject: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07EA07C3D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07EA07C3D \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTestAlert Sw3NtTestAlert
__asm__("Sw3NtTestAlert: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F2C58F34 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F2C58F34 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwThawRegistry Sw3NtThawRegistry
__asm__("Sw3NtThawRegistry: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x024AE2623 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024AE2623 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwThawTransactions Sw3NtThawTransactions
__asm__("Sw3NtThawTransactions: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0CC1ED09E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC1ED09E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTraceControl Sw3NtTraceControl
__asm__("Sw3NtTraceControl: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0BF914486 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BF914486 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwTranslateFilePath Sw3NtTranslateFilePath
__asm__("Sw3NtTranslateFilePath: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0721347BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0721347BE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUmsThreadYield Sw3NtUmsThreadYield
__asm__("Sw3NtUmsThreadYield: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x007BB766F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x007BB766F \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnloadDriver Sw3NtUnloadDriver
__asm__("Sw3NtUnloadDriver: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x018AB3010 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018AB3010 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnloadKey Sw3NtUnloadKey
__asm__("Sw3NtUnloadKey: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0082969B1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0082969B1 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnloadKey2 Sw3NtUnloadKey2
__asm__("Sw3NtUnloadKey2: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B92132FC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B92132FC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnloadKeyEx Sw3NtUnloadKeyEx
__asm__("Sw3NtUnloadKeyEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x07B98ADC5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07B98ADC5 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnlockFile Sw3NtUnlockFile
__asm__("Sw3NtUnlockFile: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x009990733 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x009990733 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnlockVirtualMemory Sw3NtUnlockVirtualMemory
__asm__("Sw3NtUnlockVirtualMemory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00A5B00DB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A5B00DB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnmapViewOfSectionEx Sw3NtUnmapViewOfSectionEx
__asm__("Sw3NtUnmapViewOfSectionEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09A91C446 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09A91C446 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUnsubscribeWnfStateChange Sw3NtUnsubscribeWnfStateChange
__asm__("Sw3NtUnsubscribeWnfStateChange: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0D344D0DD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D344D0DD \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwUpdateWnfStateData Sw3NtUpdateWnfStateData
__asm__("Sw3NtUpdateWnfStateData: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x066C9F2FE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x066C9F2FE \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwVdmControl Sw3NtVdmControl
__asm__("Sw3NtVdmControl: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x09F93E505 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09F93E505 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForAlertByThreadId Sw3NtWaitForAlertByThreadId
__asm__("Sw3NtWaitForAlertByThreadId: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0ACB3E812 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0ACB3E812 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForDebugEvent Sw3NtWaitForDebugEvent
__asm__("Sw3NtWaitForDebugEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x01085371E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01085371E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForKeyedEvent Sw3NtWaitForKeyedEvent
__asm__("Sw3NtWaitForKeyedEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B73DA6BB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B73DA6BB \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForWorkViaWorkerFactory Sw3NtWaitForWorkViaWorkerFactory
__asm__("Sw3NtWaitForWorkViaWorkerFactory: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x044954E00 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x044954E00 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitHighEventPair Sw3NtWaitHighEventPair
__asm__("Sw3NtWaitHighEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08315B9B2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08315B9B2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitLowEventPair Sw3NtWaitLowEventPair
__asm__("Sw3NtWaitLowEventPair: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F4B1D4EF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F4B1D4EF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwAcquireCMFViewOwnership Sw3NtAcquireCMFViewOwnership
__asm__("Sw3NtAcquireCMFViewOwnership: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x04E131538 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04E131538 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCancelDeviceWakeupRequest Sw3NtCancelDeviceWakeupRequest
__asm__("Sw3NtCancelDeviceWakeupRequest: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x041CF4952 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x041CF4952 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwClearAllSavepointsTransaction Sw3NtClearAllSavepointsTransaction
__asm__("Sw3NtClearAllSavepointsTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x05D0961A3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05D0961A3 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwClearSavepointTransaction Sw3NtClearSavepointTransaction
__asm__("Sw3NtClearSavepointTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0A206BCAF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A206BCAF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRollbackSavepointTransaction Sw3NtRollbackSavepointTransaction
__asm__("Sw3NtRollbackSavepointTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08099DE55 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08099DE55 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSavepointTransaction Sw3NtSavepointTransaction
__asm__("Sw3NtSavepointTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0174CD316 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0174CD316 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSavepointComplete Sw3NtSavepointComplete
__asm__("Sw3NtSavepointComplete: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E9569349 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E9569349 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateSectionEx Sw3NtCreateSectionEx
__asm__("Sw3NtCreateSectionEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x08694D44E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08694D44E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwCreateCrossVmEvent Sw3NtCreateCrossVmEvent
__asm__("Sw3NtCreateCrossVmEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C60CCF98 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C60CCF98 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwGetPlugPlayEvent Sw3NtGetPlugPlayEvent
__asm__("Sw3NtGetPlugPlayEvent: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0124DF03B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0124DF03B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwListTransactions Sw3NtListTransactions
__asm__("Sw3NtListTransactions: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x00F5D17D7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F5D17D7 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwMarshallTransaction Sw3NtMarshallTransaction
__asm__("Sw3NtMarshallTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x074AA567B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x074AA567B \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwPullTransaction Sw3NtPullTransaction
__asm__("Sw3NtPullTransaction: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C881EE55 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C881EE55 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwReleaseCMFViewOwnership Sw3NtReleaseCMFViewOwnership
__asm__("Sw3NtReleaseCMFViewOwnership: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0808559CF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0808559CF \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwWaitForWnfNotifications Sw3NtWaitForWnfNotifications
__asm__("Sw3NtWaitForWnfNotifications: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0C5893EE2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C5893EE2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwStartTm Sw3NtStartTm
__asm__("Sw3NtStartTm: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0539E1B22 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0539E1B22 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwSetInformationProcess Sw3NtSetInformationProcess
__asm__("Sw3NtSetInformationProcess: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x06739AA60 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06739AA60 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRequestDeviceWakeup Sw3NtRequestDeviceWakeup
__asm__("Sw3NtRequestDeviceWakeup: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x045A10570 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x045A10570 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwRequestWakeupLatency Sw3NtRequestWakeupLatency
__asm__("Sw3NtRequestWakeupLatency: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x001095ECC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x001095ECC \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwQuerySystemTime Sw3NtQuerySystemTime
__asm__("Sw3NtQuerySystemTime: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0E96EBE5E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E96EBE5E \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwManageHotPatch Sw3NtManageHotPatch
__asm__("Sw3NtManageHotPatch: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0B0AD6FE9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B0AD6FE9 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#define Sw3ZwContinueEx Sw3NtContinueEx
__asm__("Sw3NtContinueEx: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0F34DB5F2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F34DB5F2 \n\
call SW3_GetSyscallNumber \n\
add rsp, 0x28 \n\
mov rcx, [rsp+8] \n\
mov rdx, [rsp+16] \n\
mov r8, [rsp+24] \n\
mov r9, [rsp+32] \n\
mov r10, rcx \n\
jmp r11 \n\
");

#endif
