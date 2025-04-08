.code

EXTERN SW3_GetSyscallNumber: PROC

EXTERN SW3_GetSyscallAddress: PROC

Sw3NtAccessCheck PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C965F2CBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C965F2CBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheck ENDP

Sw3NtWorkerFactoryWorkerReady PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 081A87FD1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 081A87FD1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWorkerFactoryWorkerReady ENDP

Sw3NtAcceptConnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0204E19ECh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0204E19ECh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAcceptConnectPort ENDP

Sw3NtMapUserPhysicalPagesScatter PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A3A2E771h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A3A2E771h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMapUserPhysicalPagesScatter ENDP

Sw3NtWaitForSingleObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A09ED260h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A09ED260h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForSingleObject ENDP

Sw3NtCallbackReturn PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00A9FC9CEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00A9FC9CEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCallbackReturn ENDP

Sw3NtReadFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A57BC5ABh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A57BC5ABh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReadFile ENDP

Sw3NtDeviceIoControlFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E83EF884h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E83EF884h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeviceIoControlFile ENDP

Sw3NtWriteFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0729A044Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0729A044Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWriteFile ENDP

Sw3NtRemoveIoCompletion PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01E16E01Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01E16E01Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRemoveIoCompletion ENDP

Sw3NtReleaseSemaphore PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01C8E0E1Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01C8E0E1Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReleaseSemaphore ENDP

Sw3NtReplyWaitReceivePort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E170E2FFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E170E2FFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReplyWaitReceivePort ENDP

Sw3NtReplyPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0803183BEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0803183BEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReplyPort ENDP

Sw3NtSetInformationThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A41F2701h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A41F2701h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationThread ENDP

Sw3NtSetEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01183F3F5h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01183F3F5h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetEvent ENDP

Sw3NtClose PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E4944492h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E4944492h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtClose ENDP

Sw3NtQueryObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 006DE3A75h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 006DE3A75h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryObject ENDP

Sw3NtQueryInformationFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02A9AB4AEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02A9AB4AEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationFile ENDP

Sw3NtOpenKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 021144EF1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 021144EF1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenKey ENDP

Sw3NtEnumerateValueKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0011D32A4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0011D32A4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnumerateValueKey ENDP

Sw3NtFindAtom PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0ED7EEEEBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0ED7EEEEBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFindAtom ENDP

Sw3NtQueryDefaultLocale PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0812ECFFDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0812ECFFDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDefaultLocale ENDP

Sw3NtQueryKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FC79CFC2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FC79CFC2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryKey ENDP

Sw3NtQueryValueKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08F9EB228h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08F9EB228h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryValueKey ENDP

Sw3NtAllocateVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 003933D25h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 003933D25h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAllocateVirtualMemory ENDP

Sw3NtQueryInformationProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0822B83A7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0822B83A7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationProcess ENDP

Sw3NtWaitForMultipleObjects32 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0168F3166h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0168F3166h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForMultipleObjects32 ENDP

Sw3NtWriteFileGather PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0318E5D1Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0318E5D1Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWriteFileGather ENDP

Sw3NtCreateKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08DFFB044h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08DFFB044h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateKey ENDP

Sw3NtFreeVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04C580299h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04C580299h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFreeVirtualMemory ENDP

Sw3NtImpersonateClientOfPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 078F042BEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 078F042BEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtImpersonateClientOfPort ENDP

Sw3NtReleaseMutant PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B929ECF1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B929ECF1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReleaseMutant ENDP

Sw3NtQueryInformationToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0994887C4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0994887C4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationToken ENDP

Sw3NtRequestWaitReplyPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A8314B5Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A8314B5Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRequestWaitReplyPort ENDP

Sw3NtQueryVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09B098F85h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09B098F85h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryVirtualMemory ENDP

Sw3NtOpenThreadToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D38625C6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D38625C6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenThreadToken ENDP

Sw3NtQueryInformationThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 012CE4873h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 012CE4873h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationThread ENDP

Sw3NtOpenProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CDAFCA3Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CDAFCA3Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenProcess ENDP

Sw3NtSetInformationFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09B104927h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09B104927h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationFile ENDP

Sw3NtMapViewOfSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 014CC1651h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 014CC1651h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMapViewOfSection ENDP

Sw3NtAccessCheckAndAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FA551E04h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FA551E04h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheckAndAuditAlarm ENDP

Sw3NtUnmapViewOfSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09EC65C93h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09EC65C93h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnmapViewOfSection ENDP

Sw3NtReplyWaitReceivePortEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0858E67F5h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0858E67F5h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReplyWaitReceivePortEx ENDP

Sw3NtTerminateProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05F872F8Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05F872F8Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTerminateProcess ENDP

Sw3NtSetEventBoostPriority PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04716739Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04716739Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetEventBoostPriority ENDP

Sw3NtReadFileScatter PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 021A8372Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 021A8372Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReadFileScatter ENDP

Sw3NtOpenThreadTokenEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07440CA75h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07440CA75h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenThreadTokenEx ENDP

Sw3NtOpenProcessTokenEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 078430AB8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 078430AB8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenProcessTokenEx ENDP

Sw3NtQueryPerformanceCounter PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05B8C6521h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05B8C6521h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryPerformanceCounter ENDP

Sw3NtEnumerateKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A2DEB744h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A2DEB744h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnumerateKey ENDP

Sw3NtOpenFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0051DF979h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0051DF979h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenFile ENDP

Sw3NtDelayExecution PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01AB47C2Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01AB47C2Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDelayExecution ENDP

Sw3NtQueryDirectoryFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 078D88BC0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 078D88BC0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDirectoryFile ENDP

Sw3NtQuerySystemInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00916218Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00916218Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySystemInformation ENDP

Sw3NtOpenSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04EA93643h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04EA93643h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenSection ENDP

Sw3NtQueryTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 035AF616Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 035AF616Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryTimer ENDP

Sw3NtFsControlFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A31A69BFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A31A69BFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFsControlFile ENDP

Sw3NtWriteVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03DAE29C3h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03DAE29C3h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWriteVirtualMemory ENDP

Sw3NtCloseObjectAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B6384DB0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B6384DB0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCloseObjectAuditAlarm ENDP

Sw3NtDuplicateObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C31CC380h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C31CC380h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDuplicateObject ENDP

Sw3NtQueryAttributesFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07AB8701Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07AB8701Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryAttributesFile ENDP

Sw3NtClearEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F863E3F4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F863E3F4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtClearEvent ENDP

Sw3NtReadVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 015A90125h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 015A90125h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReadVirtualMemory ENDP

Sw3NtOpenEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 038812924h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 038812924h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenEvent ENDP

Sw3NtAdjustPrivilegesToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 005A20B3Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 005A20B3Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAdjustPrivilegesToken ENDP

Sw3NtDuplicateToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0AB95D777h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0AB95D777h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDuplicateToken ENDP

Sw3NtContinue PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01486710Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01486710Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtContinue ENDP

Sw3NtQueryDefaultUILanguage PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D38C35CDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D38C35CDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDefaultUILanguage ENDP

Sw3NtQueueApcThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08AACC278h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08AACC278h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueueApcThread ENDP

Sw3NtYieldExecution PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0095609C1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0095609C1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtYieldExecution ENDP

Sw3NtAddAtom PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 025BC202Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 025BC202Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAddAtom ENDP

Sw3NtCreateEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C8F775DEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C8F775DEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateEvent ENDP

Sw3NtQueryVolumeInformationFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 044D3BD41h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 044D3BD41h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryVolumeInformationFile ENDP

Sw3NtCreateSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0429D4009h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0429D4009h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateSection ENDP

Sw3NtFlushBuffersFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 022B4FAF2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 022B4FAF2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushBuffersFile ENDP

Sw3NtApphelpCacheControl PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00BA6033Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00BA6033Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtApphelpCacheControl ENDP

Sw3NtCreateProcessEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A7AA6BFEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A7AA6BFEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateProcessEx ENDP

Sw3NtCreateThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CE961430h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CE961430h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateThread ENDP

Sw3NtIsProcessInJob PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 069135941h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 069135941h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtIsProcessInJob ENDP

Sw3NtProtectVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 003930D15h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 003930D15h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtProtectVirtualMemory ENDP

Sw3NtQuerySection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08F23AFB1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08F23AFB1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySection ENDP

Sw3NtResumeThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 088AE0A87h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 088AE0A87h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtResumeThread ENDP

Sw3NtTerminateThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09920819Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09920819Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTerminateThread ENDP

Sw3NtReadRequestData PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05609B846h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05609B846h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReadRequestData ENDP

Sw3NtCreateFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02A7BCB3Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02A7BCB3Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateFile ENDP

Sw3NtQueryEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0608A651Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0608A651Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryEvent ENDP

Sw3NtWriteRequestData PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00DCFDDF3h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00DCFDDF3h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWriteRequestData ENDP

Sw3NtOpenDirectoryObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 066BA8EE7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 066BA8EE7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenDirectoryObject ENDP

Sw3NtAccessCheckByTypeAndAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 030B7D22Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 030B7D22Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheckByTypeAndAuditAlarm ENDP

Sw3NtWaitForMultipleObjects PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D2ACC223h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D2ACC223h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForMultipleObjects ENDP

Sw3NtSetInformationObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B629C6C5h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B629C6C5h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationObject ENDP

Sw3NtCancelIoFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B9218E7Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B9218E7Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelIoFile ENDP

Sw3NtTraceEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DB562323h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DB562323h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTraceEvent ENDP

Sw3NtPowerInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00AD3208Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00AD3208Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPowerInformation ENDP

Sw3NtSetValueKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01E552BE8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01E552BE8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetValueKey ENDP

Sw3NtCancelTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 083BB1CB1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 083BB1CB1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelTimer ENDP

Sw3NtSetTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01CAFE1C4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01CAFE1C4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetTimer ENDP

Sw3NtAccessCheckByType PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FCB2F61Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FCB2F61Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheckByType ENDP

Sw3NtAccessCheckByTypeResultList PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 035B05FAEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 035B05FAEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheckByTypeResultList ENDP

Sw3NtAccessCheckByTypeResultListAndAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00E50CC00h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00E50CC00h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheckByTypeResultListAndAuditAlarm ENDP

Sw3NtAccessCheckByTypeResultListAndAuditAlarmByHandle PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09B97A302h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09B97A302h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAccessCheckByTypeResultListAndAuditAlarmByHandle ENDP

Sw3NtAcquireProcessActivityReference PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 028EB6556h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 028EB6556h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAcquireProcessActivityReference ENDP

Sw3NtAddAtomEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C59532EDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C59532EDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAddAtomEx ENDP

Sw3NtAddBootEntry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00F961B3Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00F961B3Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAddBootEntry ENDP

Sw3NtAddDriverEntry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 009903534h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 009903534h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAddDriverEntry ENDP

Sw3NtAdjustGroupsToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08F99FB18h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08F99FB18h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAdjustGroupsToken ENDP

Sw3NtAdjustTokenClaimsAndDeviceGroups PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 053BD5F27h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 053BD5F27h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAdjustTokenClaimsAndDeviceGroups ENDP

Sw3NtAlertResumeThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 078D2666Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 078D2666Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlertResumeThread ENDP

Sw3NtAlertThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FA5CE4DDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FA5CE4DDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlertThread ENDP

Sw3NtAlertThreadByThreadId PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04CB57E62h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04CB57E62h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlertThreadByThreadId ENDP

Sw3NtAllocateLocallyUniqueId PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 097B4F33Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 097B4F33Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAllocateLocallyUniqueId ENDP

Sw3NtAllocateReserveObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0089598B9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0089598B9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAllocateReserveObject ENDP

Sw3NtAllocateUserPhysicalPages PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09FAEE84Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09FAEE84Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAllocateUserPhysicalPages ENDP

Sw3NtAllocateUuids PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0298D4F75h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0298D4F75h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAllocateUuids ENDP

Sw3NtAllocateVirtualMemoryEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B4B1EE63h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B4B1EE63h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAllocateVirtualMemoryEx ENDP

Sw3NtAlpcAcceptConnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02CB5171Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02CB5171Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcAcceptConnectPort ENDP

Sw3NtAlpcCancelMessage PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09242536Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09242536Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcCancelMessage ENDP

Sw3NtAlpcConnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03EA1DD3Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03EA1DD3Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcConnectPort ENDP

Sw3NtAlpcConnectPortEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0639D9F19h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0639D9F19h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcConnectPortEx ENDP

Sw3NtAlpcCreatePort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 064BF632Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 064BF632Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcCreatePort ENDP

Sw3NtAlpcCreatePortSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0726952FBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0726952FBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcCreatePortSection ENDP

Sw3NtAlpcCreateResourceReserve PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F2AC5EE2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F2AC5EE2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcCreateResourceReserve ENDP

Sw3NtAlpcCreateSectionView PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0923A83A1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0923A83A1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcCreateSectionView ENDP

Sw3NtAlpcCreateSecurityContext PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D742D2D3h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D742D2D3h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcCreateSecurityContext ENDP

Sw3NtAlpcDeletePortSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E00FE09Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E00FE09Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcDeletePortSection ENDP

Sw3NtAlpcDeleteResourceReserve PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01F5335DDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01F5335DDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcDeleteResourceReserve ENDP

Sw3NtAlpcDeleteSectionView PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F0ACE530h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F0ACE530h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcDeleteSectionView ENDP

Sw3NtAlpcDeleteSecurityContext PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03690C3F9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03690C3F9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcDeleteSecurityContext ENDP

Sw3NtAlpcDisconnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 060F77B78h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 060F77B78h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcDisconnectPort ENDP

Sw3NtAlpcImpersonateClientContainerOfPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DCB7B354h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DCB7B354h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcImpersonateClientContainerOfPort ENDP

Sw3NtAlpcImpersonateClientOfPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A032CDACh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A032CDACh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcImpersonateClientOfPort ENDP

Sw3NtAlpcOpenSenderProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 013AF0E22h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 013AF0E22h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcOpenSenderProcess ENDP

Sw3NtAlpcOpenSenderThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E84F35FEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E84F35FEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcOpenSenderThread ENDP

Sw3NtAlpcQueryInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05CCB7E87h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05CCB7E87h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcQueryInformation ENDP

Sw3NtAlpcQueryInformationMessage PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09E2E5B0Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09E2E5B0Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcQueryInformationMessage ENDP

Sw3NtAlpcRevokeSecurityContext PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08E9279D2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08E9279D2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcRevokeSecurityContext ENDP

Sw3NtAlpcSendWaitReceivePort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DC71D3E2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DC71D3E2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcSendWaitReceivePort ENDP

Sw3NtAlpcSetInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00CD60E47h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00CD60E47h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAlpcSetInformation ENDP

Sw3NtAreMappedFilesTheSame PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E1DDE647h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E1DDE647h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAreMappedFilesTheSame ENDP

Sw3NtAssignProcessToJobObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 070DA5F81h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 070DA5F81h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAssignProcessToJobObject ENDP

Sw3NtAssociateWaitCompletionPacket PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01928FA57h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01928FA57h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAssociateWaitCompletionPacket ENDP

Sw3NtCallEnclave PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0973B7EB9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0973B7EB9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCallEnclave ENDP

Sw3NtCancelIoFileEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A95AC9A2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A95AC9A2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelIoFileEx ENDP

Sw3NtCancelSynchronousIoFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DC98D803h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DC98D803h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelSynchronousIoFile ENDP

Sw3NtCancelTimer2 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03238E935h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03238E935h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelTimer2 ENDP

Sw3NtCancelWaitCompletionPacket PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0993EB9A2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0993EB9A2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelWaitCompletionPacket ENDP

Sw3NtCommitComplete PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D922D7CBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D922D7CBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCommitComplete ENDP

Sw3NtCommitEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 077D89043h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 077D89043h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCommitEnlistment ENDP

Sw3NtCommitRegistryTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 003A80732h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 003A80732h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCommitRegistryTransaction ENDP

Sw3NtCommitTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00843FA0Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00843FA0Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCommitTransaction ENDP

Sw3NtCompactKeys PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 043BB6C18h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 043BB6C18h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCompactKeys ENDP

Sw3NtCompareObjects PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 047AF4B2Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 047AF4B2Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCompareObjects ENDP

Sw3NtCompareSigningLevels PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CE83C917h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CE83C917h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCompareSigningLevels ENDP

Sw3NtCompareTokens PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0959468DCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0959468DCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCompareTokens ENDP

Sw3NtCompleteConnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00FAC3C03h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00FAC3C03h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCompleteConnectPort ENDP

Sw3NtCompressKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07451EB49h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07451EB49h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCompressKey ENDP

Sw3NtConnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 026B15D3Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 026B15D3Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtConnectPort ENDP

Sw3NtConvertBetweenAuxiliaryCounterAndPerformanceCounter PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F87AC4F0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F87AC4F0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtConvertBetweenAuxiliaryCounterAndPerformanceCounter ENDP

Sw3NtCreateDebugObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0071C7BF7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0071C7BF7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateDebugObject ENDP

Sw3NtCreateDirectoryObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CC28473Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CC28473Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateDirectoryObject ENDP

Sw3NtCreateDirectoryObjectEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08B144761h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08B144761h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateDirectoryObjectEx ENDP

Sw3NtCreateEnclave PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 048E66424h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 048E66424h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateEnclave ENDP

Sw3NtCreateEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07FA50653h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07FA50653h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateEnlistment ENDP

Sw3NtCreateEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FE5DD485h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FE5DD485h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateEventPair ENDP

Sw3NtCreateIRTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FBC823E2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FBC823E2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateIRTimer ENDP

Sw3NtCreateIoCompletion PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04B424DD7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04B424DD7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateIoCompletion ENDP

Sw3NtCreateJobObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0309C01D1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0309C01D1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateJobObject ENDP

Sw3NtCreateJobSet PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00EA21C3Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00EA21C3Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateJobSet ENDP

Sw3NtCreateKeyTransacted PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03EBD1E7Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03EBD1E7Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateKeyTransacted ENDP

Sw3NtCreateKeyedEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 042A05B04h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 042A05B04h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateKeyedEvent ENDP

Sw3NtCreateLowBoxToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DF97D62Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DF97D62Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateLowBoxToken ENDP

Sw3NtCreateMailslotFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0329C5206h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0329C5206h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateMailslotFile ENDP

Sw3NtCreateMutant PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 012BC2D36h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 012BC2D36h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateMutant ENDP

Sw3NtCreateNamedPipeFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02CBDBA86h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02CBDBA86h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateNamedPipeFile ENDP

Sw3NtCreatePagingFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 06CFAA548h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 06CFAA548h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreatePagingFile ENDP

Sw3NtCreatePartition PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 030177ECFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 030177ECFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreatePartition ENDP

Sw3NtCreatePort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02E4D3D22h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02E4D3D22h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreatePort ENDP

Sw3NtCreatePrivateNamespace PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 014BE497Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 014BE497Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreatePrivateNamespace ENDP

Sw3NtCreateProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E2BBDB10h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E2BBDB10h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateProcess ENDP

Sw3NtCreateProfile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F65AFCCAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F65AFCCAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateProfile ENDP

Sw3NtCreateProfileEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08A9048EBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08A9048EBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateProfileEx ENDP

Sw3NtCreateRegistryTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F3AFD2FCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F3AFD2FCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateRegistryTransaction ENDP

Sw3NtCreateResourceManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B310D1C0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B310D1C0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateResourceManager ENDP

Sw3NtCreateSemaphore PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01C48C67Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01C48C67Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateSemaphore ENDP

Sw3NtCreateSymbolicLinkObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 008553AEAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 008553AEAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateSymbolicLinkObject ENDP

Sw3NtCreateThreadEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07AA7385Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07AA7385Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateThreadEx ENDP

Sw3NtCreateTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 009932532h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 009932532h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateTimer ENDP

Sw3NtCreateTimer2 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03B9AC0B7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03B9AC0B7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateTimer2 ENDP

Sw3NtCreateToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FDA935F0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FDA935F0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateToken ENDP

Sw3NtCreateTokenEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0485A068Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0485A068Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateTokenEx ENDP

Sw3NtCreateTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F46CD4FFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F46CD4FFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateTransaction ENDP

Sw3NtCreateTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 003A9978Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 003A9978Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateTransactionManager ENDP

Sw3NtCreateUserProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F22BD3B7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F22BD3B7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateUserProcess ENDP

Sw3NtCreateWaitCompletionPacket PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01581272Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01581272Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateWaitCompletionPacket ENDP

Sw3NtCreateWaitablePort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E0B007A2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E0B007A2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateWaitablePort ENDP

Sw3NtCreateWnfStateName PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02CACBB9Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02CACBB9Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateWnfStateName ENDP

Sw3NtCreateWorkerFactory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CC92F82Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CC92F82Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateWorkerFactory ENDP

Sw3NtDebugActiveProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00EAC0F33h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00EAC0F33h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDebugActiveProcess ENDP

Sw3NtDebugContinue PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 054CF58A4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 054CF58A4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDebugContinue ENDP

Sw3NtDeleteAtom PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A3BFA62Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A3BFA62Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteAtom ENDP

Sw3NtDeleteBootEntry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00B963722h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00B963722h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteBootEntry ENDP

Sw3NtDeleteDriverEntry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 049807948h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 049807948h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteDriverEntry ENDP

Sw3NtDeleteFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02214D103h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02214D103h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteFile ENDP

Sw3NtDeleteKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01B0F42DCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01B0F42DCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteKey ENDP

Sw3NtDeleteObjectAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B22C4844h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B22C4844h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteObjectAuditAlarm ENDP

Sw3NtDeletePrivateNamespace PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B6903FB5h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B6903FB5h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeletePrivateNamespace ENDP

Sw3NtDeleteValueKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 086FBB741h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 086FBB741h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteValueKey ENDP

Sw3NtDeleteWnfStateData PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 022C64C0Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 022C64C0Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteWnfStateData ENDP

Sw3NtDeleteWnfStateName PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0BCBC3F9Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0BCBC3F9Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDeleteWnfStateName ENDP

Sw3NtDisableLastKnownGood PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02D83792Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02D83792Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDisableLastKnownGood ENDP

Sw3NtDisplayString PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 016CE0E6Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 016CE0E6Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDisplayString ENDP

Sw3NtDrawText PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EF0BE091h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EF0BE091h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtDrawText ENDP

Sw3NtEnableLastKnownGood PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 067F17746h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 067F17746h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnableLastKnownGood ENDP

Sw3NtEnumerateBootEntries PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0BA85C569h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0BA85C569h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnumerateBootEntries ENDP

Sw3NtEnumerateDriverEntries PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00A832F13h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00A832F13h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnumerateDriverEntries ENDP

Sw3NtEnumerateSystemEnvironmentValuesEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DE4E1C14h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DE4E1C14h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnumerateSystemEnvironmentValuesEx ENDP

Sw3NtEnumerateTransactionObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01AC2244Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01AC2244Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtEnumerateTransactionObject ENDP

Sw3NtExtendSection PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 034EB163Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 034EB163Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtExtendSection ENDP

Sw3NtFilterBootOption PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0048E645Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0048E645Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFilterBootOption ENDP

Sw3NtFilterToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 085D18B4Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 085D18B4Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFilterToken ENDP

Sw3NtFilterTokenEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FE9828C6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FE9828C6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFilterTokenEx ENDP

Sw3NtFlushBuffersFileEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05E478C1Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05E478C1Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushBuffersFileEx ENDP

Sw3NtFlushInstallUILanguage PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00FD97E02h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00FD97E02h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushInstallUILanguage ENDP

Sw3NtFlushInstructionCache PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0059B46BDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0059B46BDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushInstructionCache ENDP

Sw3NtFlushKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 060D84979h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 060D84979h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushKey ENDP

Sw3NtFlushProcessWriteBuffers PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FAB4D0EBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FAB4D0EBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushProcessWriteBuffers ENDP

Sw3NtFlushVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08C14829Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08C14829Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushVirtualMemory ENDP

Sw3NtFlushWriteBuffer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07F5A6FD9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07F5A6FD9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFlushWriteBuffer ENDP

Sw3NtFreeUserPhysicalPages PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09346ACEEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09346ACEEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFreeUserPhysicalPages ENDP

Sw3NtFreezeRegistry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04CDA667Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04CDA667Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFreezeRegistry ENDP

Sw3NtFreezeTransactions PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CF9429CFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CF9429CFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtFreezeTransactions ENDP

Sw3NtGetCachedSigningLevel PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EEBAE808h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EEBAE808h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetCachedSigningLevel ENDP

Sw3NtGetCompleteWnfStateSubscription PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 042CA6653h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 042CA6653h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetCompleteWnfStateSubscription ENDP

Sw3NtGetContextThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00C9E7E4Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00C9E7E4Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetContextThread ENDP

Sw3NtGetCurrentProcessorNumber PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 006B04E6Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 006B04E6Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetCurrentProcessorNumber ENDP

Sw3NtGetCurrentProcessorNumberEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07EDBAC81h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07EDBAC81h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetCurrentProcessorNumberEx ENDP

Sw3NtGetDevicePowerState PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 076C97E66h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 076C97E66h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetDevicePowerState ENDP

Sw3NtGetMUIRegistryInfo PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0251651FCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0251651FCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetMUIRegistryInfo ENDP

Sw3NtGetNextProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F9A3163Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F9A3163Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetNextProcess ENDP

Sw3NtGetNextThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 038A3F20Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 038A3F20Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetNextThread ENDP

Sw3NtGetNlsSectionPtr PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FF89FA1Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FF89FA1Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetNlsSectionPtr ENDP

Sw3NtGetNotificationResourceManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 031B0DFACh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 031B0DFACh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetNotificationResourceManager ENDP

Sw3NtGetWriteWatch PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08E434216h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08E434216h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetWriteWatch ENDP

Sw3NtImpersonateAnonymousToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0879D7B8Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0879D7B8Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtImpersonateAnonymousToken ENDP

Sw3NtImpersonateThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09ABC068Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09ABC068Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtImpersonateThread ENDP

Sw3NtInitializeEnclave PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09A45E89Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09A45E89Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtInitializeEnclave ENDP

Sw3NtInitializeNlsFiles PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C466DBCCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C466DBCCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtInitializeNlsFiles ENDP

Sw3NtInitializeRegistry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 006830003h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 006830003h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtInitializeRegistry ENDP

Sw3NtInitiatePowerAction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 002BD2C61h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 002BD2C61h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtInitiatePowerAction ENDP

Sw3NtIsSystemResumeAutomatic PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 015009D27h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 015009D27h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtIsSystemResumeAutomatic ENDP

Sw3NtIsUILanguageComitted PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07BAA3287h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07BAA3287h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtIsUILanguageComitted ENDP

Sw3NtListenPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 06D3166AEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 06D3166AEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtListenPort ENDP

Sw3NtLoadDriver PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04E983E76h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04E983E76h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLoadDriver ENDP

Sw3NtLoadEnclaveData PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FC468A92h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FC468A92h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLoadEnclaveData ENDP

Sw3NtLoadHotPatch PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0756F6FDDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0756F6FDDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLoadHotPatch ENDP

Sw3NtLoadKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 06D0E5EB7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 06D0E5EB7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLoadKey ENDP

Sw3NtLoadKey2 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DA630E85h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DA630E85h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLoadKey2 ENDP

Sw3NtLoadKeyEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 037B9F7E6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 037B9F7E6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLoadKeyEx ENDP

Sw3NtLockFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 001380599h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 001380599h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLockFile ENDP

Sw3NtLockProductActivationKeys PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04DD32032h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04DD32032h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLockProductActivationKeys ENDP

Sw3NtLockRegistryKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EFD8C27Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EFD8C27Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLockRegistryKey ENDP

Sw3NtLockVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0079D3D2Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0079D3D2Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtLockVirtualMemory ENDP

Sw3NtMakePermanentObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03AA6081Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03AA6081Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMakePermanentObject ENDP

Sw3NtMakeTemporaryObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0469217BFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0469217BFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMakeTemporaryObject ENDP

Sw3NtManagePartition PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0870D879Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0870D879Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtManagePartition ENDP

Sw3NtMapCMFModule PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A2AC6AFEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A2AC6AFEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMapCMFModule ENDP

Sw3NtMapUserPhysicalPages PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 023BF6C3Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 023BF6C3Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMapUserPhysicalPages ENDP

Sw3NtMapViewOfSectionEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0069D5240h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0069D5240h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMapViewOfSectionEx ENDP

Sw3NtModifyBootEntry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0099B3520h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0099B3520h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtModifyBootEntry ENDP

Sw3NtModifyDriverEntry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F955CDE8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F955CDE8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtModifyDriverEntry ENDP

Sw3NtNotifyChangeDirectoryFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 079B96703h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 079B96703h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtNotifyChangeDirectoryFile ENDP

Sw3NtNotifyChangeDirectoryFileEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 078B65E09h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 078B65E09h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtNotifyChangeDirectoryFileEx ENDP

Sw3NtNotifyChangeKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0069E5145h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0069E5145h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtNotifyChangeKey ENDP

Sw3NtNotifyChangeMultipleKeys PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 053C85658h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 053C85658h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtNotifyChangeMultipleKeys ENDP

Sw3NtNotifyChangeSession PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00991D6A0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00991D6A0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtNotifyChangeSession ENDP

Sw3NtOpenEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 057D96E73h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 057D96E73h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenEnlistment ENDP

Sw3NtOpenEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D0B1F817h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D0B1F817h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenEventPair ENDP

Sw3NtOpenIoCompletion PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08A938C0Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08A938C0Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenIoCompletion ENDP

Sw3NtOpenJobObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C745E7E6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C745E7E6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenJobObject ENDP

Sw3NtOpenKeyEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 06BE5BFBAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 06BE5BFBAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenKeyEx ENDP

Sw3NtOpenKeyTransacted PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0306FF032h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0306FF032h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenKeyTransacted ENDP

Sw3NtOpenKeyTransactedEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C45D1706h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C45D1706h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenKeyTransactedEx ENDP

Sw3NtOpenKeyedEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0608B7DEAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0608B7DEAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenKeyedEvent ENDP

Sw3NtOpenMutant PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F293FF0Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F293FF0Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenMutant ENDP

Sw3NtOpenObjectAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04F2F4FB8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04F2F4FB8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenObjectAuditAlarm ENDP

Sw3NtOpenPartition PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CC962FC2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CC962FC2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenPartition ENDP

Sw3NtOpenPrivateNamespace PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 06C33EA12h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 06C33EA12h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenPrivateNamespace ENDP

Sw3NtOpenProcessToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C0262E65h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C0262E65h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenProcessToken ENDP

Sw3NtOpenRegistryTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04CCD6651h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04CCD6651h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenRegistryTransaction ENDP

Sw3NtOpenResourceManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 031A76762h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 031A76762h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenResourceManager ENDP

Sw3NtOpenSemaphore PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 030D85A54h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 030D85A54h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenSemaphore ENDP

Sw3NtOpenSession PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 035AE1178h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 035AE1178h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenSession ENDP

Sw3NtOpenSymbolicLinkObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01D81F3FBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01D81F3FBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenSymbolicLinkObject ENDP

Sw3NtOpenThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E249F8F7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E249F8F7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenThread ENDP

Sw3NtOpenTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 077543786h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 077543786h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenTimer ENDP

Sw3NtOpenTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01572C81Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01572C81Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenTransaction ENDP

Sw3NtOpenTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09D22D3FAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09D22D3FAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtOpenTransactionManager ENDP

Sw3NtPlugPlayControl PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03F95ED33h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03F95ED33h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPlugPlayControl ENDP

Sw3NtPrePrepareComplete PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 048D7B186h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 048D7B186h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrePrepareComplete ENDP

Sw3NtPrePrepareEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C98735C4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C98735C4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrePrepareEnlistment ENDP

Sw3NtPrepareComplete PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0393AA60Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0393AA60Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrepareComplete ENDP

Sw3NtPrepareEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00F910E03h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00F910E03h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrepareEnlistment ENDP

Sw3NtPrivilegeCheck PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0069C3343h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0069C3343h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrivilegeCheck ENDP

Sw3NtPrivilegeObjectAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CEB02CE0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CEB02CE0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrivilegeObjectAuditAlarm ENDP

Sw3NtPrivilegedServiceAuditAlarm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02EA9AEBEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02EA9AEBEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPrivilegedServiceAuditAlarm ENDP

Sw3NtPropagationComplete PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EE52FCFEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EE52FCFEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPropagationComplete ENDP

Sw3NtPropagationFailed PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0ECB5EA57h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0ECB5EA57h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPropagationFailed ENDP

Sw3NtPulseEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B0AC953Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B0AC953Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPulseEvent ENDP

Sw3NtQueryAuxiliaryCounterFrequency PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04E9368CCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04E9368CCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryAuxiliaryCounterFrequency ENDP

Sw3NtQueryBootEntryOrder PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 041DB737Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 041DB737Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryBootEntryOrder ENDP

Sw3NtQueryBootOptions PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00D9A2309h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00D9A2309h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryBootOptions ENDP

Sw3NtQueryDebugFilterState PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E61980D4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E61980D4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDebugFilterState ENDP

Sw3NtQueryDirectoryFileEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EB18BFC4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EB18BFC4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDirectoryFileEx ENDP

Sw3NtQueryDirectoryObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08D20B3AAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08D20B3AAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDirectoryObject ENDP

Sw3NtQueryDriverEntryOrder PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01388191Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01388191Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryDriverEntryOrder ENDP

Sw3NtQueryEaFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07CDB929Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07CDB929Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryEaFile ENDP

Sw3NtQueryFullAttributesFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EE71FACEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EE71FACEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryFullAttributesFile ENDP

Sw3NtQueryInformationAtom PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04BC94858h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04BC94858h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationAtom ENDP

Sw3NtQueryInformationByName PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FEB8F112h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FEB8F112h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationByName ENDP

Sw3NtQueryInformationEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01FBA2019h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01FBA2019h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationEnlistment ENDP

Sw3NtQueryInformationJobObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 000987A75h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 000987A75h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationJobObject ENDP

Sw3NtQueryInformationPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02EBB2128h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02EBB2128h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationPort ENDP

Sw3NtQueryInformationResourceManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01583FEFEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01583FEFEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationResourceManager ENDP

Sw3NtQueryInformationTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09F059198h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09F059198h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationTransaction ENDP

Sw3NtQueryInformationTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 006239000h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 006239000h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationTransactionManager ENDP

Sw3NtQueryInformationWorkerFactory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FC62E8FFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FC62E8FFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInformationWorkerFactory ENDP

Sw3NtQueryInstallUILanguage PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EBB4D0E8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EBB4D0E8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryInstallUILanguage ENDP

Sw3NtQueryIntervalProfile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 018C2EF9Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 018C2EF9Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryIntervalProfile ENDP

Sw3NtQueryIoCompletion PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CC59EE89h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CC59EE89h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryIoCompletion ENDP

Sw3NtQueryLicenseValue PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F6609DEEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F6609DEEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryLicenseValue ENDP

Sw3NtQueryMultipleValueKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01E18F67Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01E18F67Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryMultipleValueKey ENDP

Sw3NtQueryMutant PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0228C4B58h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0228C4B58h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryMutant ENDP

Sw3NtQueryOpenSubKeys PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03FDD4C1Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03FDD4C1Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryOpenSubKeys ENDP

Sw3NtQueryOpenSubKeysEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F9B94891h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F9B94891h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryOpenSubKeysEx ENDP

Sw3NtQueryPortInformationProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F232D19Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F232D19Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryPortInformationProcess ENDP

Sw3NtQueryQuotaInformationFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D378A16Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D378A16Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryQuotaInformationFile ENDP

Sw3NtQuerySecurityAttributesToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0359403D0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0359403D0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySecurityAttributesToken ENDP

Sw3NtQuerySecurityObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C5661515h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C5661515h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySecurityObject ENDP

Sw3NtQuerySecurityPolicy PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 072C44F01h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 072C44F01h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySecurityPolicy ENDP

Sw3NtQuerySemaphore PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01E8556A8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01E8556A8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySemaphore ENDP

Sw3NtQuerySymbolicLinkObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08FA5B50Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08FA5B50Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySymbolicLinkObject ENDP

Sw3NtQuerySystemEnvironmentValue PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B423D3A8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B423D3A8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySystemEnvironmentValue ENDP

Sw3NtQuerySystemEnvironmentValueEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0578B9236h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0578B9236h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySystemEnvironmentValueEx ENDP

Sw3NtQuerySystemInformationEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A69BC47Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A69BC47Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySystemInformationEx ENDP

Sw3NtQueryTimerResolution PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0DA40DAD3h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0DA40DAD3h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryTimerResolution ENDP

Sw3NtQueryWnfStateData PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A211B0E2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A211B0E2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryWnfStateData ENDP

Sw3NtQueryWnfStateNameInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E656FD23h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E656FD23h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueryWnfStateNameInformation ENDP

Sw3NtQueueApcThreadEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F4D23A94h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F4D23A94h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQueueApcThreadEx ENDP

Sw3NtRaiseException PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CF052C50h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CF052C50h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRaiseException ENDP

Sw3NtRaiseHardError PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07BAC673Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07BAC673Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRaiseHardError ENDP

Sw3NtReadOnlyEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 059D87A4Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 059D87A4Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReadOnlyEnlistment ENDP

Sw3NtRecoverEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 019C73871h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 019C73871h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRecoverEnlistment ENDP

Sw3NtRecoverResourceManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08A1C5A3Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08A1C5A3Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRecoverResourceManager ENDP

Sw3NtRecoverTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08526B3A6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08526B3A6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRecoverTransactionManager ENDP

Sw3NtRegisterProtocolAddressInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FFBBDEE8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FFBBDEE8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRegisterProtocolAddressInformation ENDP

Sw3NtRegisterThreadTerminatePort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A6BE58CFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A6BE58CFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRegisterThreadTerminatePort ENDP

Sw3NtReleaseKeyedEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0902D72BBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0902D72BBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReleaseKeyedEvent ENDP

Sw3NtReleaseWorkerFactoryWorker PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 000986E05h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 000986E05h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReleaseWorkerFactoryWorker ENDP

Sw3NtRemoveIoCompletionEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01C0C3AB2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01C0C3AB2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRemoveIoCompletionEx ENDP

Sw3NtRemoveProcessDebug PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08A2C9F40h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08A2C9F40h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRemoveProcessDebug ENDP

Sw3NtRenameKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E72D1B49h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E72D1B49h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRenameKey ENDP

Sw3NtRenameTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 033956750h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 033956750h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRenameTransactionManager ENDP

Sw3NtReplaceKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 062FFB1A4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 062FFB1A4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReplaceKey ENDP

Sw3NtReplacePartitionUnit PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0193C0594h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0193C0594h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReplacePartitionUnit ENDP

Sw3NtReplyWaitReplyPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03CBA10EAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03CBA10EAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReplyWaitReplyPort ENDP

Sw3NtRequestPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 022B5051Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 022B5051Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRequestPort ENDP

Sw3NtResetEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01073CB24h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01073CB24h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtResetEvent ENDP

Sw3NtResetWriteWatch PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05E8F6620h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05E8F6620h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtResetWriteWatch ENDP

Sw3NtRestoreKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E6E2D959h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E6E2D959h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRestoreKey ENDP

Sw3NtResumeProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 035993414h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 035993414h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtResumeProcess ENDP

Sw3NtRevertContainerImpersonation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 031167FCFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 031167FCFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRevertContainerImpersonation ENDP

Sw3NtRollbackComplete PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F9B5D77Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F9B5D77Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRollbackComplete ENDP

Sw3NtRollbackEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08818F1EEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08818F1EEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRollbackEnlistment ENDP

Sw3NtRollbackRegistryTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0960E92A7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0960E92A7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRollbackRegistryTransaction ENDP

Sw3NtRollbackTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07CA55A75h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07CA55A75h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRollbackTransaction ENDP

Sw3NtRollforwardTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0122E7AB4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0122E7AB4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRollforwardTransactionManager ENDP

Sw3NtSaveKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 046F92703h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 046F92703h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSaveKey ENDP

Sw3NtSaveKeyEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 061FB2F2Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 061FB2F2Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSaveKeyEx ENDP

Sw3NtSaveMergedKeys PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 023343E9Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 023343E9Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSaveMergedKeys ENDP

Sw3NtSecureConnectPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 038AE22C0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 038AE22C0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSecureConnectPort ENDP

Sw3NtSerializeBoot PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EDBCC528h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EDBCC528h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSerializeBoot ENDP

Sw3NtSetBootEntryOrder PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01CBF35E4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01CBF35E4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetBootEntryOrder ENDP

Sw3NtSetBootOptions PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FBA5133Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FBA5133Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetBootOptions ENDP

Sw3NtSetCachedSigningLevel PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 012DC99E2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 012DC99E2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetCachedSigningLevel ENDP

Sw3NtSetCachedSigningLevel2 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F0CE1B1Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F0CE1B1Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetCachedSigningLevel2 ENDP

Sw3NtSetContextThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B897B63Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B897B63Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetContextThread ENDP

Sw3NtSetDebugFilterState PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00319EE16h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00319EE16h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetDebugFilterState ENDP

Sw3NtSetDefaultHardErrorPort PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02632A128h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02632A128h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetDefaultHardErrorPort ENDP

Sw3NtSetDefaultLocale PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01DA1C595h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01DA1C595h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetDefaultLocale ENDP

Sw3NtSetDefaultUILanguage PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 028BBDE26h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 028BBDE26h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetDefaultUILanguage ENDP

Sw3NtSetDriverEntryOrder PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0359B0F33h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0359B0F33h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetDriverEntryOrder ENDP

Sw3NtSetEaFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B838A08Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B838A08Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetEaFile ENDP

Sw3NtSetHighEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 093345D68h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 093345D68h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetHighEventPair ENDP

Sw3NtSetHighWaitLowEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05D3E5BA9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05D3E5BA9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetHighWaitLowEventPair ENDP

Sw3NtSetIRTimer PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08011B4ABh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08011B4ABh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetIRTimer ENDP

Sw3NtSetInformationDebugObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EAB0F42Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EAB0F42Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationDebugObject ENDP

Sw3NtSetInformationEnlistment PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D954E0F9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D954E0F9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationEnlistment ENDP

Sw3NtSetInformationJobObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01CBF2A1Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01CBF2A1Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationJobObject ENDP

Sw3NtSetInformationKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01025338Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01025338Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationKey ENDP

Sw3NtSetInformationResourceManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01F8D0B10h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01F8D0B10h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationResourceManager ENDP

Sw3NtSetInformationSymbolicLink PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A03AA4A2h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A03AA4A2h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationSymbolicLink ENDP

Sw3NtSetInformationToken PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09BADD77Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09BADD77Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationToken ENDP

Sw3NtSetInformationTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04B6F67F5h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04B6F67F5h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationTransaction ENDP

Sw3NtSetInformationTransactionManager PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08300B5A4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08300B5A4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationTransactionManager ENDP

Sw3NtSetInformationVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00D99170Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00D99170Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationVirtualMemory ENDP

Sw3NtSetInformationWorkerFactory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0889D74D8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0889D74D8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationWorkerFactory ENDP

Sw3NtSetIntervalProfile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 018A2D100h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 018A2D100h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetIntervalProfile ENDP

Sw3NtSetIoCompletion PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E871E0EBh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E871E0EBh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetIoCompletion ENDP

Sw3NtSetIoCompletionEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0989B5AA0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0989B5AA0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetIoCompletionEx ENDP

Sw3NtSetLdtEntries PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0EDBE04E4h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0EDBE04E4h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetLdtEntries ENDP

Sw3NtSetLowEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 032AE5031h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 032AE5031h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetLowEventPair ENDP

Sw3NtSetLowWaitHighEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 015B64B66h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 015B64B66h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetLowWaitHighEventPair ENDP

Sw3NtSetQuotaInformationFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A8B8822Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A8B8822Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetQuotaInformationFile ENDP

Sw3NtSetSecurityObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0173B4D95h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0173B4D95h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetSecurityObject ENDP

Sw3NtSetSystemEnvironmentValue PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FB21BC01h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FB21BC01h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetSystemEnvironmentValue ENDP

Sw3NtSetSystemEnvironmentValueEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D320A3D8h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D320A3D8h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetSystemEnvironmentValueEx ENDP

Sw3NtSetSystemInformation PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 002AB003Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 002AB003Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetSystemInformation ENDP

Sw3NtSetSystemPowerState PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 01697C832h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 01697C832h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetSystemPowerState ENDP

Sw3NtSetSystemTime PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A036A9A3h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A036A9A3h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetSystemTime ENDP

Sw3NtSetThreadExecutionState PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0108EE080h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0108EE080h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetThreadExecutionState ENDP

Sw3NtSetTimer2 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D8B3182Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D8B3182Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetTimer2 ENDP

Sw3NtSetTimerEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0836BCFAFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0836BCFAFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetTimerEx ENDP

Sw3NtSetTimerResolution PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D64009EDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D64009EDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetTimerResolution ENDP

Sw3NtSetUuidSeed PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F9A03D18h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F9A03D18h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetUuidSeed ENDP

Sw3NtSetVolumeInformationFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0B81CBCBEh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0B81CBCBEh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetVolumeInformationFile ENDP

Sw3NtSetWnfProcessNotificationEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 02A94ECC1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 02A94ECC1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetWnfProcessNotificationEvent ENDP

Sw3NtShutdownSystem PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0029ED1A0h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0029ED1A0h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtShutdownSystem ENDP

Sw3NtShutdownWorkerFactory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0FFA115B3h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0FFA115B3h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtShutdownWorkerFactory ENDP

Sw3NtSignalAndWaitForSingleObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F6587134h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F6587134h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSignalAndWaitForSingleObject ENDP

Sw3NtSinglePhaseReject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 028857049h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 028857049h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSinglePhaseReject ENDP

Sw3NtStartProfile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09D251101h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09D251101h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtStartProfile ENDP

Sw3NtStopProfile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C1163B47h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C1163B47h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtStopProfile ENDP

Sw3NtSubscribeWnfStateChange PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 062BF2362h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 062BF2362h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSubscribeWnfStateChange ENDP

Sw3NtSuspendProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 06DB71254h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 06DB71254h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSuspendProcess ENDP

Sw3NtSuspendThread PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 032ADF50Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 032ADF50Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSuspendThread ENDP

Sw3NtSystemDebugControl PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07D521DC9h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07D521DC9h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSystemDebugControl ENDP

Sw3NtTerminateEnclave PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CB54AB5Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CB54AB5Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTerminateEnclave ENDP

Sw3NtTerminateJobObject PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00E347ABFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00E347ABFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTerminateJobObject ENDP

Sw3NtTestAlert PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 069B1701Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 069B1701Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTestAlert ENDP

Sw3NtThawRegistry PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 078E317F7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 078E317F7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtThawRegistry ENDP

Sw3NtThawTransactions PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 009DA7731h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 009DA7731h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtThawTransactions ENDP

Sw3NtTraceControl PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00D9BCBB1h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00D9BCBB1h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTraceControl ENDP

Sw3NtTranslateFilePath PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 028B0133Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 028B0133Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtTranslateFilePath ENDP

Sw3NtUmsThreadYield PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04A671051h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04A671051h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUmsThreadYield ENDP

Sw3NtUnloadDriver PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00EA7160Eh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00EA7160Eh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnloadDriver ENDP

Sw3NtUnloadKey PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0281E19A7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0281E19A7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnloadKey ENDP

Sw3NtUnloadKey2 PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08F3655DAh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08F3655DAh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnloadKey2 ENDP

Sw3NtUnloadKeyEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08BB9FF44h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08BB9FF44h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnloadKeyEx ENDP

Sw3NtUnlockFile PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 04217DB31h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 04217DB31h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnlockFile ENDP

Sw3NtUnlockVirtualMemory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 003902B07h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 003902B07h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnlockVirtualMemory ENDP

Sw3NtUnmapViewOfSectionEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07E55FD6Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07E55FD6Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnmapViewOfSectionEx ENDP

Sw3NtUnsubscribeWnfStateChange PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0A203EBA6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0A203EBA6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUnsubscribeWnfStateChange ENDP

Sw3NtUpdateWnfStateData PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0BD03560Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0BD03560Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtUpdateWnfStateData ENDP

Sw3NtVdmControl PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00999EF8Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00999EF8Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtVdmControl ENDP

Sw3NtWaitForAlertByThreadId PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 08CB03E66h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 08CB03E66h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForAlertByThreadId ENDP

Sw3NtWaitForDebugEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 030A30304h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 030A30304h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForDebugEvent ENDP

Sw3NtWaitForKeyedEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0F05FF5D6h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0F05FF5D6h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForKeyedEvent ENDP

Sw3NtWaitForWorkViaWorkerFactory PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0C495DC17h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0C495DC17h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForWorkViaWorkerFactory ENDP

Sw3NtWaitHighEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 062375A9Dh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 062375A9Dh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitHighEventPair ENDP

Sw3NtWaitLowEventPair PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 03192AE9Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 03192AE9Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitLowEventPair ENDP

Sw3NtAcquireCMFViewOwnership PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00C53C40Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00C53C40Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtAcquireCMFViewOwnership ENDP

Sw3NtCancelDeviceWakeupRequest PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 053CD7350h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 053CD7350h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCancelDeviceWakeupRequest ENDP

Sw3NtClearAllSavepointsTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 004961E63h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 004961E63h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtClearAllSavepointsTransaction ENDP

Sw3NtClearSavepointTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 00B1C2988h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 00B1C2988h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtClearSavepointTransaction ENDP

Sw3NtRollbackSavepointTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 082D45E9Fh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 082D45E9Fh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRollbackSavepointTransaction ENDP

Sw3NtSavepointTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0D00BD69Bh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0D00BD69Bh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSavepointTransaction ENDP

Sw3NtSavepointComplete PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 036A5241Ch        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 036A5241Ch        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSavepointComplete ENDP

Sw3NtCreateSectionEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 000953428h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 000953428h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateSectionEx ENDP

Sw3NtCreateCrossVmEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0016C04FCh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0016C04FCh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtCreateCrossVmEvent ENDP

Sw3NtGetPlugPlayEvent PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0634A48ECh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0634A48ECh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtGetPlugPlayEvent ENDP

Sw3NtListTransactions PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0014E05DDh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0014E05DDh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtListTransactions ENDP

Sw3NtMarshallTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09E009895h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09E009895h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtMarshallTransaction ENDP

Sw3NtPullTransaction PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 008670AF7h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 008670AF7h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtPullTransaction ENDP

Sw3NtReleaseCMFViewOwnership PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0CC93F41Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0CC93F41Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtReleaseCMFViewOwnership ENDP

Sw3NtWaitForWnfNotifications PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0E34BC5FFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0E34BC5FFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtWaitForWnfNotifications ENDP

Sw3NtStartTm PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 07C71DC43h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 07C71DC43h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtStartTm ENDP

Sw3NtSetInformationProcess PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 05F807A28h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 05F807A28h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtSetInformationProcess ENDP

Sw3NtRequestDeviceWakeup PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 055CD959Ah        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 055CD959Ah        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRequestDeviceWakeup ENDP

Sw3NtRequestWakeupLatency PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0173B7CAFh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0173B7CAFh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtRequestWakeupLatency ENDP

Sw3NtQuerySystemTime PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09A8F13ABh        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09A8F13ABh        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtQuerySystemTime ENDP

Sw3NtManageHotPatch PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 09FAF5188h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 09FAF5188h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtManageHotPatch ENDP

Sw3NtContinueEx PROC
	mov [rsp +8], rcx          ; Save registers.
	mov [rsp+16], rdx
	mov [rsp+24], r8
	mov [rsp+32], r9
	sub rsp, 28h
	mov ecx, 0978853B5h        ; Load function hash into ECX.
	call SW3_GetSyscallAddress              ; Resolve function hash into syscall offset.
	mov r11, rax                           ; Save the address of the syscall
	mov ecx, 0978853B5h        ; Re-Load function hash into ECX (optional).
	call SW3_GetSyscallNumber              ; Resolve function hash into syscall number.
	add rsp, 28h
	mov rcx, [rsp+8]                      ; Restore registers.
	mov rdx, [rsp+16]
	mov r8, [rsp+24]
	mov r9, [rsp+32]
	mov r10, rcx
	jmp r11                                ; Jump to -> Invoke system call.
Sw3NtContinueEx ENDP

end