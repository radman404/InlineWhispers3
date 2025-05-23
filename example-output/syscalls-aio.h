#pragma once
#include <windows.h>


// Code below is adapted from @modexpblog. Read linked article for more details.
// https://www.mdsec.co.uk/2020/12/bypassing-user-mode-hooks-and-direct-invocation-of-system-calls-for-red-teams

#ifndef SW3_HEADER_H_
#define SW3_HEADER_H_




#ifndef _NTDEF_
typedef _Return_type_success_(return >= 0) LONG NTSTATUS;
typedef NTSTATUS* PNTSTATUS;
#endif

#define SW3_SEED 0xCC6A5286
#define SW3_ROL8(v) (v << 8 | v >> 24)
#define SW3_ROR8(v) (v >> 8 | v << 24)
#define SW3_ROX8(v) ((SW3_SEED % 2) ? SW3_ROL8(v) : SW3_ROR8(v))
#define SW3_MAX_ENTRIES 600
#define SW3_RVA2VA(Type, DllBase, Rva) (Type)((ULONG_PTR) DllBase + Rva)

// Typedefs are prefixed to avoid pollution.

typedef struct _SW3_SYSCALL_ENTRY
{
DWORD Hash;
DWORD Address;
PVOID SyscallAddress;
} SW3_SYSCALL_ENTRY, *PSW3_SYSCALL_ENTRY;

typedef struct _SW3_SYSCALL_LIST
{
DWORD Count;
SW3_SYSCALL_ENTRY Entries[SW3_MAX_ENTRIES];
} SW3_SYSCALL_LIST, *PSW3_SYSCALL_LIST;

typedef struct _SW3_PEB_LDR_DATA {
BYTE Reserved1[8];
PVOID Reserved2[3];
LIST_ENTRY InMemoryOrderModuleList;
} SW3_PEB_LDR_DATA, *PSW3_PEB_LDR_DATA;

typedef struct _SW3_LDR_DATA_TABLE_ENTRY {
PVOID Reserved1[2];
LIST_ENTRY InMemoryOrderLinks;
PVOID Reserved2[2];
PVOID DllBase;
} SW3_LDR_DATA_TABLE_ENTRY, *PSW3_LDR_DATA_TABLE_ENTRY;

typedef struct _SW3_PEB {
BYTE Reserved1[2];
BYTE BeingDebugged;
BYTE Reserved2[1];
PVOID Reserved3[2];
PSW3_PEB_LDR_DATA Ldr;
} SW3_PEB, *PSW3_PEB;

DWORD SW3_HashSyscall(PCSTR FunctionName);
BOOL SW3_PopulateSyscallList();
EXTERN_C DWORD SW3_GetSyscallNumber(DWORD FunctionHash);
EXTERN_C PVOID SW3_GetSyscallAddress(DWORD FunctionHash);
EXTERN_C PVOID internal_cleancall_wow64_gate(VOID);
typedef struct _UNICODE_STRING
{
USHORT Length;
USHORT MaximumLength;
PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _SYSTEM_HANDLE
{
ULONG ProcessId;
BYTE ObjectTypeNumber;
BYTE Flags;
USHORT Handle;
PVOID Object;
ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE, *PSYSTEM_HANDLE;

typedef struct _TOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE
{
PVOID pValue;
ULONG ValueLength;
} TOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE, *PTOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE;

typedef struct _TOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE
{
ULONG64        Version;
UNICODE_STRING Name;
} TOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE, *PTOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE;

typedef struct _WNF_TYPE_ID
{
GUID TypeId;
} WNF_TYPE_ID, *PWNF_TYPE_ID;

typedef enum _KCONTINUE_TYPE
{
KCONTINUE_UNWIND,
KCONTINUE_RESUME,
KCONTINUE_LONGJUMP,
KCONTINUE_SET,
KCONTINUE_LAST
} KCONTINUE_TYPE;

typedef struct _IO_STATUS_BLOCK
{
union
{
NTSTATUS Status;
VOID*    Pointer;
};
ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

typedef enum _PS_CREATE_STATE
{
PsCreateInitialState,
PsCreateFailOnFileOpen,
PsCreateFailOnSectionCreate,
PsCreateFailExeFormat,
PsCreateFailMachineMismatch,
PsCreateFailExeName,
PsCreateSuccess,
PsCreateMaximumStates
} PS_CREATE_STATE, *PPS_CREATE_STATE;

typedef struct _SYSTEM_HANDLE_INFORMATION
{
ULONG HandleCount;
SYSTEM_HANDLE Handles[1];
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;

typedef struct _CLIENT_ID
{
HANDLE UniqueProcess;
HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef enum _PLUGPLAY_EVENT_CATEGORY
{
HardwareProfileChangeEvent,
TargetDeviceChangeEvent,
DeviceClassChangeEvent,
CustomDeviceEvent,
DeviceInstallEvent,
DeviceArrivalEvent,
PowerEvent,
VetoEvent,
BlockedDriverEvent,
InvalidIDEvent,
MaxPlugEventCategory
} PLUGPLAY_EVENT_CATEGORY, *PPLUGPLAY_EVENT_CATEGORY;

typedef enum _PNP_VETO_TYPE
{
PNP_VetoTypeUnknown, // unspecified
PNP_VetoLegacyDevice, // instance path
PNP_VetoPendingClose, // instance path
PNP_VetoWindowsApp, // module
PNP_VetoWindowsService, // service
PNP_VetoOutstandingOpen, // instance path
PNP_VetoDevice, // instance path
PNP_VetoDriver, // driver service name
PNP_VetoIllegalDeviceRequest, // instance path
PNP_VetoInsufficientPower, // unspecified
PNP_VetoNonDisableable, // instance path
PNP_VetoLegacyDriver, // service
PNP_VetoInsufficientRights  // unspecified
} PNP_VETO_TYPE, *PPNP_VETO_TYPE;

typedef struct _TOKEN_SECURITY_ATTRIBUTE_V1
{
UNICODE_STRING Name;
USHORT         ValueType;
USHORT         Reserved;
ULONG          Flags;
ULONG          ValueCount;
union
{
PLONG64                                      pInt64;
PULONG64                                     pUint64;
PUNICODE_STRING                              pString;
PTOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE         pFqbn;
PTOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE pOctetString;
} Values;
} TOKEN_SECURITY_ATTRIBUTE_V1, *PTOKEN_SECURITY_ATTRIBUTE_V1;

typedef VOID(KNORMAL_ROUTINE) (
IN PVOID NormalContext,
IN PVOID SystemArgument1,
IN PVOID SystemArgument2);

typedef struct _PS_ATTRIBUTE
{
ULONG  Attribute;
SIZE_T Size;
union
{
ULONG Value;
PVOID ValuePtr;
} u1;
PSIZE_T ReturnLength;
} PS_ATTRIBUTE, *PPS_ATTRIBUTE;

typedef struct _WNF_STATE_NAME
{
ULONG Data[2];
} WNF_STATE_NAME, *PWNF_STATE_NAME;

#ifndef InitializeObjectAttributes
#define InitializeObjectAttributes( p, n, a, r, s ) { \
(p)->Length = sizeof( OBJECT_ATTRIBUTES );        \
(p)->RootDirectory = r;                           \
(p)->Attributes = a;                              \
(p)->ObjectName = n;                              \
(p)->SecurityDescriptor = s;                      \
(p)->SecurityQualityOfService = NULL;             \
}
#endif

typedef struct _KEY_VALUE_ENTRY
{
PUNICODE_STRING ValueName;
ULONG           DataLength;
ULONG           DataOffset;
ULONG           Type;
} KEY_VALUE_ENTRY, *PKEY_VALUE_ENTRY;

typedef enum _KEY_SET_INFORMATION_CLASS
{
KeyWriteTimeInformation,
KeyWow64FlagsInformation,
KeyControlFlagsInformation,
KeySetVirtualizationInformation,
KeySetDebugInformation,
KeySetHandleTagsInformation,
MaxKeySetInfoClass  // MaxKeySetInfoClass should always be the last enum.
} KEY_SET_INFORMATION_CLASS, *PKEY_SET_INFORMATION_CLASS;

typedef enum _SYSTEM_INFORMATION_CLASS
{
SystemBasicInformation = 0,
SystemPerformanceInformation = 2,
SystemTimeOfDayInformation = 3,
SystemProcessInformation = 5,
SystemProcessorPerformanceInformation = 8,
SystemHandleInformation = 16,
SystemInterruptInformation = 23,
SystemExceptionInformation = 33,
SystemRegistryQuotaInformation = 37,
SystemLookasideInformation = 45,
SystemCodeIntegrityInformation = 103,
SystemPolicyInformation = 134,
} SYSTEM_INFORMATION_CLASS, *PSYSTEM_INFORMATION_CLASS;

typedef enum _PROCESSINFOCLASS
{
ProcessBasicInformation = 0,
ProcessDebugPort = 7,
ProcessWow64Information = 26,
ProcessImageFileName = 27,
ProcessBreakOnTermination = 29
} PROCESSINFOCLASS, *PPROCESSINFOCLASS;

typedef struct _MEMORY_RANGE_ENTRY
{
PVOID  VirtualAddress;
SIZE_T NumberOfBytes;
} MEMORY_RANGE_ENTRY, *PMEMORY_RANGE_ENTRY;

typedef struct _T2_SET_PARAMETERS_V0
{
ULONG    Version;
ULONG    Reserved;
LONGLONG NoWakeTolerance;
} T2_SET_PARAMETERS, *PT2_SET_PARAMETERS;

typedef struct _FILE_PATH
{
ULONG Version;
ULONG Length;
ULONG Type;
CHAR  FilePath[1];
} FILE_PATH, *PFILE_PATH;

typedef struct _FILE_USER_QUOTA_INFORMATION
{
ULONG         NextEntryOffset;
ULONG         SidLength;
LARGE_INTEGER ChangeTime;
LARGE_INTEGER QuotaUsed;
LARGE_INTEGER QuotaThreshold;
LARGE_INTEGER QuotaLimit;
SID           Sid[1];
} FILE_USER_QUOTA_INFORMATION, *PFILE_USER_QUOTA_INFORMATION;

typedef struct _FILE_QUOTA_LIST_INFORMATION
{
ULONG NextEntryOffset;
ULONG SidLength;
SID   Sid[1];
} FILE_QUOTA_LIST_INFORMATION, *PFILE_QUOTA_LIST_INFORMATION;

typedef struct _FILE_NETWORK_OPEN_INFORMATION
{
LARGE_INTEGER CreationTime;
LARGE_INTEGER LastAccessTime;
LARGE_INTEGER LastWriteTime;
LARGE_INTEGER ChangeTime;
LARGE_INTEGER AllocationSize;
LARGE_INTEGER EndOfFile;
ULONG         FileAttributes;
ULONG         Unknown;
} FILE_NETWORK_OPEN_INFORMATION, *PFILE_NETWORK_OPEN_INFORMATION;

typedef enum _FILTER_BOOT_OPTION_OPERATION
{
FilterBootOptionOperationOpenSystemStore,
FilterBootOptionOperationSetElement,
FilterBootOptionOperationDeleteElement,
FilterBootOptionOperationMax
} FILTER_BOOT_OPTION_OPERATION, *PFILTER_BOOT_OPTION_OPERATION;

typedef enum _EVENT_TYPE
{
NotificationEvent = 0,
SynchronizationEvent = 1,
} EVENT_TYPE, *PEVENT_TYPE;

typedef struct _FILE_FULL_EA_INFORMATION
{
ULONG  NextEntryOffset;
UCHAR  Flags;
UCHAR  EaNameLength;
USHORT EaValueLength;
CHAR   EaName[1];
} FILE_FULL_EA_INFORMATION, *PFILE_FULL_EA_INFORMATION;

typedef struct _FILE_GET_EA_INFORMATION
{
ULONG NextEntryOffset;
BYTE  EaNameLength;
CHAR  EaName[1];
} FILE_GET_EA_INFORMATION, *PFILE_GET_EA_INFORMATION;

typedef struct _BOOT_OPTIONS
{
ULONG Version;
ULONG Length;
ULONG Timeout;
ULONG CurrentBootEntryId;
ULONG NextBootEntryId;
WCHAR HeadlessRedirection[1];
} BOOT_OPTIONS, *PBOOT_OPTIONS;

typedef ULONG WNF_CHANGE_STAMP, *PWNF_CHANGE_STAMP;

typedef enum _WNF_DATA_SCOPE
{
WnfDataScopeSystem = 0,
WnfDataScopeSession = 1,
WnfDataScopeUser = 2,
WnfDataScopeProcess = 3,
WnfDataScopeMachine = 4
} WNF_DATA_SCOPE, *PWNF_DATA_SCOPE;

typedef enum _WNF_STATE_NAME_LIFETIME
{
WnfWellKnownStateName = 0,
WnfPermanentStateName = 1,
WnfPersistentStateName = 2,
WnfTemporaryStateName = 3
} WNF_STATE_NAME_LIFETIME, *PWNF_STATE_NAME_LIFETIME;

typedef enum _VIRTUAL_MEMORY_INFORMATION_CLASS
{
VmPrefetchInformation,
VmPagePriorityInformation,
VmCfgCallTargetInformation
} VIRTUAL_MEMORY_INFORMATION_CLASS, *PVIRTUAL_MEMORY_INFORMATION_CLASS;

typedef enum _IO_SESSION_EVENT
{
IoSessionEventIgnore,
IoSessionEventCreated,
IoSessionEventTerminated,
IoSessionEventConnected,
IoSessionEventDisconnected,
IoSessionEventLogon,
IoSessionEventLogoff,
IoSessionEventMax
} IO_SESSION_EVENT, *PIO_SESSION_EVENT;

typedef enum _PORT_INFORMATION_CLASS
{
PortBasicInformation,
#if DEVL
PortDumpInformation
#endif
} PORT_INFORMATION_CLASS, *PPORT_INFORMATION_CLASS;

typedef enum _PLUGPLAY_CONTROL_CLASS
{
PlugPlayControlEnumerateDevice,
PlugPlayControlRegisterNewDevice,
PlugPlayControlDeregisterDevice,
PlugPlayControlInitializeDevice,
PlugPlayControlStartDevice,
PlugPlayControlUnlockDevice,
PlugPlayControlQueryAndRemoveDevice,
PlugPlayControlUserResponse,
PlugPlayControlGenerateLegacyDevice,
PlugPlayControlGetInterfaceDeviceList,
PlugPlayControlProperty,
PlugPlayControlDeviceClassAssociation,
PlugPlayControlGetRelatedDevice,
PlugPlayControlGetInterfaceDeviceAlias,
PlugPlayControlDeviceStatus,
PlugPlayControlGetDeviceDepth,
PlugPlayControlQueryDeviceRelations,
PlugPlayControlTargetDeviceRelation,
PlugPlayControlQueryConflictList,
PlugPlayControlRetrieveDock,
PlugPlayControlResetDevice,
PlugPlayControlHaltDevice,
PlugPlayControlGetBlockedDriverList,
MaxPlugPlayControl
} PLUGPLAY_CONTROL_CLASS, *PPLUGPLAY_CONTROL_CLASS;

typedef enum _IO_COMPLETION_INFORMATION_CLASS
{
IoCompletionBasicInformation
} IO_COMPLETION_INFORMATION_CLASS, *PIO_COMPLETION_INFORMATION_CLASS;

typedef enum _SECTION_INHERIT
{
ViewShare = 1,
ViewUnmap = 2
} SECTION_INHERIT, *PSECTION_INHERIT;

typedef enum _DEBUGOBJECTINFOCLASS
{
DebugObjectFlags = 1,
MaxDebugObjectInfoClass
} DEBUGOBJECTINFOCLASS, *PDEBUGOBJECTINFOCLASS;

typedef enum _SEMAPHORE_INFORMATION_CLASS
{
SemaphoreBasicInformation
} SEMAPHORE_INFORMATION_CLASS, *PSEMAPHORE_INFORMATION_CLASS;

typedef struct _PS_ATTRIBUTE_LIST
{
SIZE_T       TotalLength;
PS_ATTRIBUTE Attributes[1];
} PS_ATTRIBUTE_LIST, *PPS_ATTRIBUTE_LIST;

typedef enum _VDMSERVICECLASS
{
VdmStartExecution,
VdmQueueInterrupt,
VdmDelayInterrupt,
VdmInitialize,
VdmFeatures,
VdmSetInt21Handler,
VdmQueryDir,
VdmPrinterDirectIoOpen,
VdmPrinterDirectIoClose,
VdmPrinterInitialize,
VdmSetLdtEntries,
VdmSetProcessLdtInfo,
VdmAdlibEmulation,
VdmPMCliControl,
VdmQueryVdmProcess
} VDMSERVICECLASS, *PVDMSERVICECLASS;

typedef struct _PS_CREATE_INFO
{
SIZE_T Size;
PS_CREATE_STATE State;
union
{
// PsCreateInitialState
struct {
union {
ULONG InitFlags;
struct {
UCHAR  WriteOutputOnExit : 1;
UCHAR  DetectManifest : 1;
UCHAR  IFEOSkipDebugger : 1;
UCHAR  IFEODoNotPropagateKeyState : 1;
UCHAR  SpareBits1 : 4;
UCHAR  SpareBits2 : 8;
USHORT ProhibitedImageCharacteristics : 16;
};
};
ACCESS_MASK AdditionalFileAccess;
} InitState;
// PsCreateFailOnSectionCreate
struct {
HANDLE FileHandle;
} FailSection;
// PsCreateFailExeFormat
struct {
USHORT DllCharacteristics;
} ExeFormat;
// PsCreateFailExeName
struct {
HANDLE IFEOKey;
} ExeName;
// PsCreateSuccess
struct {
union {
ULONG OutputFlags;
struct {
UCHAR  ProtectedProcess : 1;
UCHAR  AddressSpaceOverride : 1;
UCHAR  DevOverrideEnabled : 1; // from Image File Execution Options
UCHAR  ManifestDetected : 1;
UCHAR  ProtectedProcessLight : 1;
UCHAR  SpareBits1 : 3;
UCHAR  SpareBits2 : 8;
USHORT SpareBits3 : 16;
};
};
HANDLE    FileHandle;
HANDLE    SectionHandle;
ULONGLONG UserProcessParametersNative;
ULONG     UserProcessParametersWow64;
ULONG     CurrentParameterFlags;
ULONGLONG PebAddressNative;
ULONG     PebAddressWow64;
ULONGLONG ManifestAddress;
ULONG     ManifestSize;
} SuccessState;
};
} PS_CREATE_INFO, *PPS_CREATE_INFO;

typedef enum _MEMORY_INFORMATION_CLASS
{
MemoryBasicInformation,
MemoryWorkingSetInformation,
MemoryMappedFilenameInformation,
MemoryRegionInformation,
MemoryWorkingSetExInformation,
MemorySharedCommitInformation,
MemoryImageInformation,
MemoryRegionInformationEx,
MemoryPrivilegedBasicInformation,
MemoryEnclaveImageInformation,
MemoryBasicInformationCapped
} MEMORY_INFORMATION_CLASS, *PMEMORY_INFORMATION_CLASS;

typedef enum _MEMORY_RESERVE_TYPE
{
MemoryReserveUserApc,
MemoryReserveIoCompletion,
MemoryReserveTypeMax
} MEMORY_RESERVE_TYPE, *PMEMORY_RESERVE_TYPE;

typedef enum _ALPC_PORT_INFORMATION_CLASS
{
AlpcBasicInformation,
AlpcPortInformation,
AlpcAssociateCompletionPortInformation,
AlpcConnectedSIDInformation,
AlpcServerInformation,
AlpcMessageZoneInformation,
AlpcRegisterCompletionListInformation,
AlpcUnregisterCompletionListInformation,
AlpcAdjustCompletionListConcurrencyCountInformation,
AlpcRegisterCallbackInformation,
AlpcCompletionListRundownInformation
} ALPC_PORT_INFORMATION_CLASS, *PALPC_PORT_INFORMATION_CLASS;

typedef struct _ALPC_CONTEXT_ATTR
{
PVOID PortContext;
PVOID MessageContext;
ULONG SequenceNumber;
ULONG MessageID;
ULONG CallbackID;
} ALPC_CONTEXT_ATTR, *PALPC_CONTEXT_ATTR;

typedef struct _ALPC_DATA_VIEW_ATTR
{
ULONG  Flags;
HANDLE SectionHandle;
PVOID  ViewBase;
SIZE_T ViewSize;
} ALPC_DATA_VIEW_ATTR, *PALPC_DATA_VIEW_ATTR;

typedef struct _ALPC_SECURITY_ATTR
{
ULONG                        Flags;
PSECURITY_QUALITY_OF_SERVICE SecurityQos;
HANDLE                       ContextHandle;
ULONG                        Reserved1;
ULONG                        Reserved2;
} ALPC_SECURITY_ATTR, *PALPC_SECURITY_ATTR;

typedef PVOID* PPVOID;

typedef enum _KPROFILE_SOURCE
{
ProfileTime = 0,
ProfileAlignmentFixup = 1,
ProfileTotalIssues = 2,
ProfilePipelineDry = 3,
ProfileLoadInstructions = 4,
ProfilePipelineFrozen = 5,
ProfileBranchInstructions = 6,
ProfileTotalNonissues = 7,
ProfileDcacheMisses = 8,
ProfileIcacheMisses = 9,
ProfileCacheMisses = 10,
ProfileBranchMispredictions = 11,
ProfileStoreInstructions = 12,
ProfileFpInstructions = 13,
ProfileIntegerInstructions = 14,
Profile2Issue = 15,
Profile3Issue = 16,
Profile4Issue = 17,
ProfileSpecialInstructions = 18,
ProfileTotalCycles = 19,
ProfileIcacheIssues = 20,
ProfileDcacheAccesses = 21,
ProfileMemoryBarrierCycles = 22,
ProfileLoadLinkedIssues = 23,
ProfileMaximum = 24,
} KPROFILE_SOURCE, *PKPROFILE_SOURCE;

typedef enum _ALPC_MESSAGE_INFORMATION_CLASS
{
AlpcMessageSidInformation,
AlpcMessageTokenModifiedIdInformation
} ALPC_MESSAGE_INFORMATION_CLASS, *PALPC_MESSAGE_INFORMATION_CLASS;

typedef enum _WORKERFACTORYINFOCLASS
{
WorkerFactoryTimeout,
WorkerFactoryRetryTimeout,
WorkerFactoryIdleTimeout,
WorkerFactoryBindingCount,
WorkerFactoryThreadMinimum,
WorkerFactoryThreadMaximum,
WorkerFactoryPaused,
WorkerFactoryBasicInformation,
WorkerFactoryAdjustThreadGoal,
WorkerFactoryCallbackType,
WorkerFactoryStackInformation,
MaxWorkerFactoryInfoClass
} WORKERFACTORYINFOCLASS, *PWORKERFACTORYINFOCLASS;

typedef enum _MEMORY_PARTITION_INFORMATION_CLASS
{
SystemMemoryPartitionInformation,
SystemMemoryPartitionMoveMemory,
SystemMemoryPartitionAddPagefile,
SystemMemoryPartitionCombineMemory,
SystemMemoryPartitionInitialAddMemory,
SystemMemoryPartitionGetMemoryEvents,
SystemMemoryPartitionMax
} MEMORY_PARTITION_INFORMATION_CLASS, *PMEMORY_PARTITION_INFORMATION_CLASS;

typedef enum _MUTANT_INFORMATION_CLASS
{
MutantBasicInformation,
MutantOwnerInformation
} MUTANT_INFORMATION_CLASS, *PMUTANT_INFORMATION_CLASS;

typedef enum _ATOM_INFORMATION_CLASS
{
AtomBasicInformation,
AtomTableInformation
} ATOM_INFORMATION_CLASS, *PATOM_INFORMATION_CLASS;

typedef enum _SHUTDOWN_ACTION {
ShutdownNoReboot,
ShutdownReboot,
ShutdownPowerOff
} SHUTDOWN_ACTION;

typedef VOID(CALLBACK* PTIMER_APC_ROUTINE)(
IN PVOID TimerContext,
IN ULONG TimerLowValue,
IN LONG TimerHighValue);

typedef enum _KEY_VALUE_INFORMATION_CLASS {
KeyValueBasicInformation = 0,
KeyValueFullInformation,
KeyValuePartialInformation,
KeyValueFullInformationAlign64,
KeyValuePartialInformationAlign64,
MaxKeyValueInfoClass
} KEY_VALUE_INFORMATION_CLASS;

typedef LANGID* PLANGID;

typedef struct _PLUGPLAY_EVENT_BLOCK
{
GUID EventGuid;
PLUGPLAY_EVENT_CATEGORY EventCategory;
PULONG Result;
ULONG Flags;
ULONG TotalSize;
PVOID DeviceObject;

union
{
struct
{
GUID ClassGuid;
WCHAR SymbolicLinkName[1];
} DeviceClass;
struct
{
WCHAR DeviceIds[1];
} TargetDevice;
struct
{
WCHAR DeviceId[1];
} InstallDevice;
struct
{
PVOID NotificationStructure;
WCHAR DeviceIds[1];
} CustomNotification;
struct
{
PVOID Notification;
} ProfileNotification;
struct
{
ULONG NotificationCode;
ULONG NotificationData;
} PowerNotification;
struct
{
PNP_VETO_TYPE VetoType;
WCHAR DeviceIdVetoNameBuffer[1]; // DeviceId<null>VetoName<null><null>
} VetoNotification;
struct
{
GUID BlockedDriverGuid;
} BlockedDriverNotification;
struct
{
WCHAR ParentId[1];
} InvalidIDNotification;
} u;
} PLUGPLAY_EVENT_BLOCK, *PPLUGPLAY_EVENT_BLOCK;

typedef VOID(NTAPI* PIO_APC_ROUTINE) (
IN PVOID            ApcContext,
IN PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG            Reserved);

typedef KNORMAL_ROUTINE* PKNORMAL_ROUTINE;

typedef enum _DIRECTORY_NOTIFY_INFORMATION_CLASS
{
DirectoryNotifyInformation = 1,
DirectoryNotifyExtendedInformation = 2,
} DIRECTORY_NOTIFY_INFORMATION_CLASS, *PDIRECTORY_NOTIFY_INFORMATION_CLASS;

typedef enum _EVENT_INFORMATION_CLASS
{
EventBasicInformation
} EVENT_INFORMATION_CLASS, *PEVENT_INFORMATION_CLASS;

typedef struct _ALPC_MESSAGE_ATTRIBUTES
{
unsigned long AllocatedAttributes;
unsigned long ValidAttributes;
} ALPC_MESSAGE_ATTRIBUTES, *PALPC_MESSAGE_ATTRIBUTES;

typedef struct _ALPC_PORT_ATTRIBUTES
{
ULONG                       Flags;
SECURITY_QUALITY_OF_SERVICE SecurityQos;
SIZE_T                      MaxMessageLength;
SIZE_T                      MemoryBandwidth;
SIZE_T                      MaxPoolUsage;
SIZE_T                      MaxSectionSize;
SIZE_T                      MaxViewSize;
SIZE_T                      MaxTotalSectionSize;
ULONG                       DupObjectTypes;
#ifdef _WIN64
ULONG                       Reserved;
#endif
} ALPC_PORT_ATTRIBUTES, *PALPC_PORT_ATTRIBUTES;

typedef enum _IO_SESSION_STATE
{
IoSessionStateCreated = 1,
IoSessionStateInitialized = 2,
IoSessionStateConnected = 3,
IoSessionStateDisconnected = 4,
IoSessionStateDisconnectedLoggedOn = 5,
IoSessionStateLoggedOn = 6,
IoSessionStateLoggedOff = 7,
IoSessionStateTerminated = 8,
IoSessionStateMax = 9,
} IO_SESSION_STATE, *PIO_SESSION_STATE;

typedef const WNF_STATE_NAME *PCWNF_STATE_NAME;

typedef const WNF_TYPE_ID *PCWNF_TYPE_ID;

typedef struct _WNF_DELIVERY_DESCRIPTOR
{
unsigned __int64 SubscriptionId;
WNF_STATE_NAME   StateName;
unsigned long    ChangeStamp;
unsigned long    StateDataSize;
unsigned long    EventMask;
WNF_TYPE_ID      TypeId;
unsigned long    StateDataOffset;
} WNF_DELIVERY_DESCRIPTOR, *PWNF_DELIVERY_DESCRIPTOR;

typedef enum _DEBUG_CONTROL_CODE
{
SysDbgQueryModuleInformation = 0,
SysDbgQueryTraceInformation = 1,
SysDbgSetTracePoint = 2,
SysDbgSetSpecialCall = 3,
SysDbgClearSpecialCalls = 4,
SysDbgQuerySpecialCalls = 5,
SysDbgBreakPoint = 6,
SysDbgQueryVersion = 7,
SysDbgReadVirtual = 8,
SysDbgWriteVirtual = 9,
SysDbgReadPhysical = 10,
SysDbgWritePhysical = 11,
SysDbgReadControlSpace = 12,
SysDbgWriteControlSpace = 13,
SysDbgReadIoSpace = 14,
SysDbgWriteIoSpace = 15,
SysDbgReadMsr = 16,
SysDbgWriteMsr = 17,
SysDbgReadBusData = 18,
SysDbgWriteBusData = 19,
SysDbgCheckLowMemory = 20,
SysDbgEnableKernelDebugger = 21,
SysDbgDisableKernelDebugger = 22,
SysDbgGetAutoKdEnable = 23,
SysDbgSetAutoKdEnable = 24,
SysDbgGetPrintBufferSize = 25,
SysDbgSetPrintBufferSize = 26,
SysDbgGetKdUmExceptionEnable = 27,
SysDbgSetKdUmExceptionEnable = 28,
SysDbgGetTriageDump = 29,
SysDbgGetKdBlockEnable = 30,
SysDbgSetKdBlockEnable = 31
} DEBUG_CONTROL_CODE, *PDEBUG_CONTROL_CODE;

typedef struct _PORT_MESSAGE
{
union
{
union
{
struct
{
short DataLength;
short TotalLength;
} s1;
unsigned long Length;
};
} u1;
union
{
union
{
struct
{
short Type;
short DataInfoOffset;
} s2;
unsigned long ZeroInit;
};
} u2;
union
{
CLIENT_ID ClientId;
double    DoNotUseThisField;
};
unsigned long MessageId;
union
{
unsigned __int64 ClientViewSize;
struct
{
unsigned long CallbackId;
long          __PADDING__[1];
};
};
} PORT_MESSAGE, *PPORT_MESSAGE;

typedef struct _FILE_BASIC_INFORMATION
{
LARGE_INTEGER CreationTime;
LARGE_INTEGER LastAccessTime;
LARGE_INTEGER LastWriteTime;
LARGE_INTEGER ChangeTime;
ULONG         FileAttributes;
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;

typedef struct _PORT_SECTION_READ
{
ULONG Length;
ULONG ViewSize;
ULONG ViewBase;
} PORT_SECTION_READ, *PPORT_SECTION_READ;

typedef struct _PORT_SECTION_WRITE
{
ULONG  Length;
HANDLE SectionHandle;
ULONG  SectionOffset;
ULONG  ViewSize;
PVOID  ViewBase;
PVOID  TargetViewBase;
} PORT_SECTION_WRITE, *PPORT_SECTION_WRITE;

typedef enum _TIMER_TYPE
{
NotificationTimer,
SynchronizationTimer
} TIMER_TYPE, *PTIMER_TYPE;

typedef struct _BOOT_ENTRY
{
ULONG Version;
ULONG Length;
ULONG Id;
ULONG Attributes;
ULONG FriendlyNameOffset;
ULONG BootFilePathOffset;
ULONG OsOptionsLength;
UCHAR OsOptions[ANYSIZE_ARRAY];
} BOOT_ENTRY, *PBOOT_ENTRY;

typedef struct _EFI_DRIVER_ENTRY
{
ULONG Version;
ULONG Length;
ULONG Id;
ULONG Attributes;
ULONG FriendlyNameOffset;
ULONG DriverFilePathOffset;
} EFI_DRIVER_ENTRY, *PEFI_DRIVER_ENTRY;

typedef USHORT RTL_ATOM, *PRTL_ATOM;

typedef enum _TIMER_SET_INFORMATION_CLASS
{
TimerSetCoalescableTimer,
MaxTimerInfoClass
} TIMER_SET_INFORMATION_CLASS, *PTIMER_SET_INFORMATION_CLASS;

typedef enum _FSINFOCLASS
{
FileFsVolumeInformation = 1,
FileFsLabelInformation = 2,
FileFsSizeInformation = 3,
FileFsDeviceInformation = 4,
FileFsAttributeInformation = 5,
FileFsControlInformation = 6,
FileFsFullSizeInformation = 7,
FileFsObjectIdInformation = 8,
FileFsDriverPathInformation = 9,
FileFsVolumeFlagsInformation = 10,
FileFsSectorSizeInformation = 11,
FileFsDataCopyInformation = 12,
FileFsMetadataSizeInformation = 13,
FileFsFullSizeInformationEx = 14,
FileFsMaximumInformation = 15,
} FSINFOCLASS, *PFSINFOCLASS;

typedef enum _WAIT_TYPE
{
WaitAll = 0,
WaitAny = 1
} WAIT_TYPE, *PWAIT_TYPE;

typedef struct _USER_STACK
{
PVOID FixedStackBase;
PVOID FixedStackLimit;
PVOID ExpandableStackBase;
PVOID ExpandableStackLimit;
PVOID ExpandableStackBottom;
} USER_STACK, *PUSER_STACK;

typedef enum _SECTION_INFORMATION_CLASS
{
SectionBasicInformation,
SectionImageInformation,
} SECTION_INFORMATION_CLASS, *PSECTION_INFORMATION_CLASS;

typedef enum _APPHELPCACHESERVICECLASS
{
ApphelpCacheServiceLookup = 0,
ApphelpCacheServiceRemove = 1,
ApphelpCacheServiceUpdate = 2,
ApphelpCacheServiceFlush = 3,
ApphelpCacheServiceDump = 4,
ApphelpDBGReadRegistry = 0x100,
ApphelpDBGWriteRegistry = 0x101,
} APPHELPCACHESERVICECLASS, *PAPPHELPCACHESERVICECLASS;

typedef struct _TOKEN_SECURITY_ATTRIBUTES_INFORMATION
{
USHORT Version;
USHORT Reserved;
ULONG  AttributeCount;
union
{
PTOKEN_SECURITY_ATTRIBUTE_V1 pAttributeV1;
} Attribute;
} TOKEN_SECURITY_ATTRIBUTES_INFORMATION, *PTOKEN_SECURITY_ATTRIBUTES_INFORMATION;

typedef struct _FILE_IO_COMPLETION_INFORMATION
{
PVOID           KeyContext;
PVOID           ApcContext;
IO_STATUS_BLOCK IoStatusBlock;
} FILE_IO_COMPLETION_INFORMATION, *PFILE_IO_COMPLETION_INFORMATION;

typedef PVOID PT2_CANCEL_PARAMETERS;

typedef enum _THREADINFOCLASS
{
ThreadBasicInformation,
ThreadTimes,
ThreadPriority,
ThreadBasePriority,
ThreadAffinityMask,
ThreadImpersonationToken,
ThreadDescriptorTableEntry,
ThreadEnableAlignmentFaultFixup,
ThreadEventPair_Reusable,
ThreadQuerySetWin32StartAddress,
ThreadZeroTlsCell,
ThreadPerformanceCount,
ThreadAmILastThread,
ThreadIdealProcessor,
ThreadPriorityBoost,
ThreadSetTlsArrayAddress,
ThreadIsIoPending,
ThreadHideFromDebugger,
ThreadBreakOnTermination,
MaxThreadInfoClass
} THREADINFOCLASS, *PTHREADINFOCLASS;

typedef enum _OBJECT_INFORMATION_CLASS
{
ObjectBasicInformation,
ObjectNameInformation,
ObjectTypeInformation,
ObjectAllTypesInformation,
ObjectHandleInformation
} OBJECT_INFORMATION_CLASS, *POBJECT_INFORMATION_CLASS;

typedef enum _FILE_INFORMATION_CLASS
{
FileDirectoryInformation = 1,
FileFullDirectoryInformation = 2,
FileBothDirectoryInformation = 3,
FileBasicInformation = 4,
FileStandardInformation = 5,
FileInternalInformation = 6,
FileEaInformation = 7,
FileAccessInformation = 8,
FileNameInformation = 9,
FileRenameInformation = 10,
FileLinkInformation = 11,
FileNamesInformation = 12,
FileDispositionInformation = 13,
FilePositionInformation = 14,
FileFullEaInformation = 15,
FileModeInformation = 16,
FileAlignmentInformation = 17,
FileAllInformation = 18,
FileAllocationInformation = 19,
FileEndOfFileInformation = 20,
FileAlternateNameInformation = 21,
FileStreamInformation = 22,
FilePipeInformation = 23,
FilePipeLocalInformation = 24,
FilePipeRemoteInformation = 25,
FileMailslotQueryInformation = 26,
FileMailslotSetInformation = 27,
FileCompressionInformation = 28,
FileObjectIdInformation = 29,
FileCompletionInformation = 30,
FileMoveClusterInformation = 31,
FileQuotaInformation = 32,
FileReparsePointInformation = 33,
FileNetworkOpenInformation = 34,
FileAttributeTagInformation = 35,
FileTrackingInformation = 36,
FileIdBothDirectoryInformation = 37,
FileIdFullDirectoryInformation = 38,
FileValidDataLengthInformation = 39,
FileShortNameInformation = 40,
FileIoCompletionNotificationInformation = 41,
FileIoStatusBlockRangeInformation = 42,
FileIoPriorityHintInformation = 43,
FileSfioReserveInformation = 44,
FileSfioVolumeInformation = 45,
FileHardLinkInformation = 46,
FileProcessIdsUsingFileInformation = 47,
FileNormalizedNameInformation = 48,
FileNetworkPhysicalNameInformation = 49,
FileIdGlobalTxDirectoryInformation = 50,
FileIsRemoteDeviceInformation = 51,
FileUnusedInformation = 52,
FileNumaNodeInformation = 53,
FileStandardLinkInformation = 54,
FileRemoteProtocolInformation = 55,
FileRenameInformationBypassAccessCheck = 56,
FileLinkInformationBypassAccessCheck = 57,
FileVolumeNameInformation = 58,
FileIdInformation = 59,
FileIdExtdDirectoryInformation = 60,
FileReplaceCompletionInformation = 61,
FileHardLinkFullIdInformation = 62,
FileIdExtdBothDirectoryInformation = 63,
FileDispositionInformationEx = 64,
FileRenameInformationEx = 65,
FileRenameInformationExBypassAccessCheck = 66,
FileMaximumInformation = 67,
} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

typedef enum _KEY_INFORMATION_CLASS
{
KeyBasicInformation = 0,
KeyNodeInformation = 1,
KeyFullInformation = 2,
KeyNameInformation = 3,
KeyCachedInformation = 4,
KeyFlagsInformation = 5,
KeyVirtualizationInformation = 6,
KeyHandleTagsInformation = 7,
MaxKeyInfoClass = 8
} KEY_INFORMATION_CLASS, *PKEY_INFORMATION_CLASS;

typedef struct _OBJECT_ATTRIBUTES
{
ULONG           Length;
HANDLE          RootDirectory;
PUNICODE_STRING ObjectName;
ULONG           Attributes;
PVOID           SecurityDescriptor;
PVOID           SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef enum _TIMER_INFORMATION_CLASS
{
TimerBasicInformation
} TIMER_INFORMATION_CLASS, *PTIMER_INFORMATION_CLASS;

typedef struct _KCONTINUE_ARGUMENT
{
KCONTINUE_TYPE ContinueType;
ULONG          ContinueFlags;
ULONGLONG      Reserved[2];
} KCONTINUE_ARGUMENT, *PKCONTINUE_ARGUMENT;

EXTERN_C NTSTATUS Sw3NtAccessCheck(
IN PSECURITY_DESCRIPTOR pSecurityDescriptor,
IN HANDLE ClientToken,
IN ACCESS_MASK DesiaredAccess,
IN PGENERIC_MAPPING GenericMapping,
OUT PPRIVILEGE_SET PrivilegeSet OPTIONAL,
IN OUT PULONG PrivilegeSetLength,
OUT PACCESS_MASK GrantedAccess,
OUT PBOOLEAN AccessStatus);

EXTERN_C NTSTATUS Sw3NtWorkerFactoryWorkerReady(
IN HANDLE WorkerFactoryHandle);

EXTERN_C NTSTATUS Sw3NtAcceptConnectPort(
OUT PHANDLE ServerPortHandle,
IN ULONG AlternativeReceivePortHandle OPTIONAL,
IN PPORT_MESSAGE ConnectionReply,
IN BOOLEAN AcceptConnection,
IN OUT PPORT_SECTION_WRITE ServerSharedMemory OPTIONAL,
OUT PPORT_SECTION_READ ClientSharedMemory OPTIONAL);

EXTERN_C NTSTATUS Sw3NtMapUserPhysicalPagesScatter(
IN PVOID VirtualAddresses,
IN PULONG NumberOfPages,
IN PULONG UserPfnArray OPTIONAL);

EXTERN_C NTSTATUS Sw3NtWaitForSingleObject(
IN HANDLE ObjectHandle,
IN BOOLEAN Alertable,
IN PLARGE_INTEGER TimeOut OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCallbackReturn(
IN PVOID OutputBuffer OPTIONAL,
IN ULONG OutputLength,
IN NTSTATUS Status);

EXTERN_C NTSTATUS Sw3NtReadFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
OUT PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PVOID Buffer,
IN ULONG Length,
IN PLARGE_INTEGER ByteOffset OPTIONAL,
IN PULONG Key OPTIONAL);

EXTERN_C NTSTATUS Sw3NtDeviceIoControlFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG IoControlCode,
IN PVOID InputBuffer OPTIONAL,
IN ULONG InputBufferLength,
OUT PVOID OutputBuffer OPTIONAL,
IN ULONG OutputBufferLength);

EXTERN_C NTSTATUS Sw3NtWriteFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PVOID Buffer,
IN ULONG Length,
IN PLARGE_INTEGER ByteOffset OPTIONAL,
IN PULONG Key OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRemoveIoCompletion(
IN HANDLE IoCompletionHandle,
OUT PULONG KeyContext,
OUT PULONG ApcContext,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtReleaseSemaphore(
IN HANDLE SemaphoreHandle,
IN LONG ReleaseCount,
OUT PLONG PreviousCount OPTIONAL);

EXTERN_C NTSTATUS Sw3NtReplyWaitReceivePort(
IN HANDLE PortHandle,
OUT PVOID PortContext OPTIONAL,
IN PPORT_MESSAGE ReplyMessage OPTIONAL,
OUT PPORT_MESSAGE ReceiveMessage);

EXTERN_C NTSTATUS Sw3NtReplyPort(
IN HANDLE PortHandle,
IN PPORT_MESSAGE ReplyMessage);

EXTERN_C NTSTATUS Sw3NtSetInformationThread(
IN HANDLE ThreadHandle,
IN THREADINFOCLASS ThreadInformationClass,
IN PVOID ThreadInformation,
IN ULONG ThreadInformationLength);

EXTERN_C NTSTATUS Sw3NtSetEvent(
IN HANDLE EventHandle,
OUT PULONG PreviousState OPTIONAL);

EXTERN_C NTSTATUS Sw3NtClose(
IN HANDLE Handle);

EXTERN_C NTSTATUS Sw3NtQueryObject(
IN HANDLE Handle,
IN OBJECT_INFORMATION_CLASS ObjectInformationClass,
OUT PVOID ObjectInformation OPTIONAL,
IN ULONG ObjectInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PVOID FileInformation,
IN ULONG Length,
IN FILE_INFORMATION_CLASS FileInformationClass);

EXTERN_C NTSTATUS Sw3NtOpenKey(
OUT PHANDLE KeyHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtEnumerateValueKey(
IN HANDLE KeyHandle,
IN ULONG Index,
IN KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
OUT PVOID KeyValueInformation OPTIONAL,
IN ULONG Length,
OUT PULONG ResultLength);

EXTERN_C NTSTATUS Sw3NtFindAtom(
IN PWSTR AtomName OPTIONAL,
IN ULONG Length,
OUT PUSHORT Atom OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryDefaultLocale(
IN BOOLEAN UserProfile,
OUT PLCID DefaultLocaleId);

EXTERN_C NTSTATUS Sw3NtQueryKey(
IN HANDLE KeyHandle,
IN KEY_INFORMATION_CLASS KeyInformationClass,
OUT PVOID KeyInformation OPTIONAL,
IN ULONG Length,
OUT PULONG ResultLength);

EXTERN_C NTSTATUS Sw3NtQueryValueKey(
IN HANDLE KeyHandle,
IN PUNICODE_STRING ValueName,
IN KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
OUT PVOID KeyValueInformation OPTIONAL,
IN ULONG Length,
OUT PULONG ResultLength);

EXTERN_C NTSTATUS Sw3NtAllocateVirtualMemory(
IN HANDLE ProcessHandle,
IN OUT PVOID * BaseAddress,
IN ULONG ZeroBits,
IN OUT PSIZE_T RegionSize,
IN ULONG AllocationType,
IN ULONG Protect);

EXTERN_C NTSTATUS Sw3NtQueryInformationProcess(
IN HANDLE ProcessHandle,
IN PROCESSINFOCLASS ProcessInformationClass,
OUT PVOID ProcessInformation,
IN ULONG ProcessInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtWaitForMultipleObjects32(
IN ULONG ObjectCount,
IN PHANDLE Handles,
IN WAIT_TYPE WaitType,
IN BOOLEAN Alertable,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtWriteFileGather(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PFILE_SEGMENT_ELEMENT SegmentArray,
IN ULONG Length,
IN PLARGE_INTEGER ByteOffset,
IN PULONG Key OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateKey(
OUT PHANDLE KeyHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN ULONG TitleIndex,
IN PUNICODE_STRING Class OPTIONAL,
IN ULONG CreateOptions,
OUT PULONG Disposition OPTIONAL);

EXTERN_C NTSTATUS Sw3NtFreeVirtualMemory(
IN HANDLE ProcessHandle,
IN OUT PVOID * BaseAddress,
IN OUT PSIZE_T RegionSize,
IN ULONG FreeType);

EXTERN_C NTSTATUS Sw3NtImpersonateClientOfPort(
IN HANDLE PortHandle,
IN PPORT_MESSAGE Message);

EXTERN_C NTSTATUS Sw3NtReleaseMutant(
IN HANDLE MutantHandle,
OUT PULONG PreviousCount OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationToken(
IN HANDLE TokenHandle,
IN TOKEN_INFORMATION_CLASS TokenInformationClass,
OUT PVOID TokenInformation,
IN ULONG TokenInformationLength,
OUT PULONG ReturnLength);

EXTERN_C NTSTATUS Sw3NtRequestWaitReplyPort(
IN HANDLE PortHandle,
IN PPORT_MESSAGE RequestMessage,
OUT PPORT_MESSAGE ReplyMessage);

EXTERN_C NTSTATUS Sw3NtQueryVirtualMemory(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress,
IN MEMORY_INFORMATION_CLASS MemoryInformationClass,
OUT PVOID MemoryInformation,
IN SIZE_T MemoryInformationLength,
OUT PSIZE_T ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenThreadToken(
IN HANDLE ThreadHandle,
IN ACCESS_MASK DesiredAccess,
IN BOOLEAN OpenAsSelf,
OUT PHANDLE TokenHandle);

EXTERN_C NTSTATUS Sw3NtQueryInformationThread(
IN HANDLE ThreadHandle,
IN THREADINFOCLASS ThreadInformationClass,
OUT PVOID ThreadInformation,
IN ULONG ThreadInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenProcess(
OUT PHANDLE ProcessHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN PCLIENT_ID ClientId OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetInformationFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PVOID FileInformation,
IN ULONG Length,
IN FILE_INFORMATION_CLASS FileInformationClass);

EXTERN_C NTSTATUS Sw3NtMapViewOfSection(
IN HANDLE SectionHandle,
IN HANDLE ProcessHandle,
IN OUT PVOID BaseAddress,
IN ULONG ZeroBits,
IN SIZE_T CommitSize,
IN OUT PLARGE_INTEGER SectionOffset OPTIONAL,
IN OUT PSIZE_T ViewSize,
IN SECTION_INHERIT InheritDisposition,
IN ULONG AllocationType,
IN ULONG Win32Protect);

EXTERN_C NTSTATUS Sw3NtAccessCheckAndAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN PUNICODE_STRING ObjectTypeName,
IN PUNICODE_STRING ObjectName,
IN PSECURITY_DESCRIPTOR SecurityDescriptor,
IN ACCESS_MASK DesiredAccess,
IN PGENERIC_MAPPING GenericMapping,
IN BOOLEAN ObjectCreation,
OUT PACCESS_MASK GrantedAccess,
OUT PBOOLEAN AccessStatus,
OUT PBOOLEAN GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtUnmapViewOfSection(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress);

EXTERN_C NTSTATUS Sw3NtReplyWaitReceivePortEx(
IN HANDLE PortHandle,
OUT PULONG PortContext OPTIONAL,
IN PPORT_MESSAGE ReplyMessage OPTIONAL,
OUT PPORT_MESSAGE ReceiveMessage,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtTerminateProcess(
IN HANDLE ProcessHandle OPTIONAL,
IN NTSTATUS ExitStatus);

EXTERN_C NTSTATUS Sw3NtSetEventBoostPriority(
IN HANDLE EventHandle);

EXTERN_C NTSTATUS Sw3NtReadFileScatter(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PFILE_SEGMENT_ELEMENT SegmentArray,
IN ULONG Length,
IN PLARGE_INTEGER ByteOffset OPTIONAL,
IN PULONG Key OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenThreadTokenEx(
IN HANDLE ThreadHandle,
IN ACCESS_MASK DesiredAccess,
IN BOOLEAN OpenAsSelf,
IN ULONG HandleAttributes,
OUT PHANDLE TokenHandle);

EXTERN_C NTSTATUS Sw3NtOpenProcessTokenEx(
IN HANDLE ProcessHandle,
IN ACCESS_MASK DesiredAccess,
IN ULONG HandleAttributes,
OUT PHANDLE TokenHandle);

EXTERN_C NTSTATUS Sw3NtQueryPerformanceCounter(
OUT PLARGE_INTEGER PerformanceCounter,
OUT PLARGE_INTEGER PerformanceFrequency OPTIONAL);

EXTERN_C NTSTATUS Sw3NtEnumerateKey(
IN HANDLE KeyHandle,
IN ULONG Index,
IN KEY_INFORMATION_CLASS KeyInformationClass,
OUT PVOID KeyInformation OPTIONAL,
IN ULONG Length,
OUT PULONG ResultLength);

EXTERN_C NTSTATUS Sw3NtOpenFile(
OUT PHANDLE FileHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG ShareAccess,
IN ULONG OpenOptions);

EXTERN_C NTSTATUS Sw3NtDelayExecution(
IN BOOLEAN Alertable,
IN PLARGE_INTEGER DelayInterval);

EXTERN_C NTSTATUS Sw3NtQueryDirectoryFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PVOID FileInformation,
IN ULONG Length,
IN FILE_INFORMATION_CLASS FileInformationClass,
IN BOOLEAN ReturnSingleEntry,
IN PUNICODE_STRING FileName OPTIONAL,
IN BOOLEAN RestartScan);

EXTERN_C NTSTATUS Sw3NtQuerySystemInformation(
IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
IN OUT PVOID SystemInformation,
IN ULONG SystemInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenSection(
OUT PHANDLE SectionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtQueryTimer(
IN HANDLE TimerHandle,
IN TIMER_INFORMATION_CLASS TimerInformationClass,
OUT PVOID TimerInformation,
IN ULONG TimerInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtFsControlFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG FsControlCode,
IN PVOID InputBuffer OPTIONAL,
IN ULONG InputBufferLength,
OUT PVOID OutputBuffer OPTIONAL,
IN ULONG OutputBufferLength);

EXTERN_C NTSTATUS Sw3NtWriteVirtualMemory(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress,
IN PVOID Buffer,
IN SIZE_T NumberOfBytesToWrite,
OUT PSIZE_T NumberOfBytesWritten OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCloseObjectAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN BOOLEAN GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtDuplicateObject(
IN HANDLE SourceProcessHandle,
IN HANDLE SourceHandle,
IN HANDLE TargetProcessHandle OPTIONAL,
OUT PHANDLE TargetHandle OPTIONAL,
IN ACCESS_MASK DesiredAccess,
IN ULONG HandleAttributes,
IN ULONG Options);

EXTERN_C NTSTATUS Sw3NtQueryAttributesFile(
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PFILE_BASIC_INFORMATION FileInformation);

EXTERN_C NTSTATUS Sw3NtClearEvent(
IN HANDLE EventHandle);

EXTERN_C NTSTATUS Sw3NtReadVirtualMemory(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress OPTIONAL,
OUT PVOID Buffer,
IN SIZE_T BufferSize,
OUT PSIZE_T NumberOfBytesRead OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenEvent(
OUT PHANDLE EventHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtAdjustPrivilegesToken(
IN HANDLE TokenHandle,
IN BOOLEAN DisableAllPrivileges,
IN PTOKEN_PRIVILEGES NewState OPTIONAL,
IN ULONG BufferLength,
OUT PTOKEN_PRIVILEGES PreviousState OPTIONAL,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtDuplicateToken(
IN HANDLE ExistingTokenHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN BOOLEAN EffectiveOnly,
IN TOKEN_TYPE TokenType,
OUT PHANDLE NewTokenHandle);

EXTERN_C NTSTATUS Sw3NtContinue(
IN PCONTEXT ContextRecord,
IN BOOLEAN TestAlert);

EXTERN_C NTSTATUS Sw3NtQueryDefaultUILanguage(
OUT PLANGID DefaultUILanguageId);

EXTERN_C NTSTATUS Sw3NtQueueApcThread(
IN HANDLE ThreadHandle,
IN PKNORMAL_ROUTINE ApcRoutine,
IN PVOID ApcArgument1 OPTIONAL,
IN PVOID ApcArgument2 OPTIONAL,
IN PVOID ApcArgument3 OPTIONAL);

EXTERN_C NTSTATUS Sw3NtYieldExecution();

EXTERN_C NTSTATUS Sw3NtAddAtom(
IN PWSTR AtomName OPTIONAL,
IN ULONG Length,
OUT PUSHORT Atom OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateEvent(
OUT PHANDLE EventHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN EVENT_TYPE EventType,
IN BOOLEAN InitialState);

EXTERN_C NTSTATUS Sw3NtQueryVolumeInformationFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PVOID FsInformation,
IN ULONG Length,
IN FSINFOCLASS FsInformationClass);

EXTERN_C NTSTATUS Sw3NtCreateSection(
OUT PHANDLE SectionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PLARGE_INTEGER MaximumSize OPTIONAL,
IN ULONG SectionPageProtection,
IN ULONG AllocationAttributes,
IN HANDLE FileHandle OPTIONAL);

EXTERN_C NTSTATUS Sw3NtFlushBuffersFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock);

EXTERN_C NTSTATUS Sw3NtApphelpCacheControl(
IN APPHELPCACHESERVICECLASS Service,
IN PVOID ServiceData);

EXTERN_C NTSTATUS Sw3NtCreateProcessEx(
OUT PHANDLE ProcessHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN HANDLE ParentProcess,
IN ULONG Flags,
IN HANDLE SectionHandle OPTIONAL,
IN HANDLE DebugPort OPTIONAL,
IN HANDLE ExceptionPort OPTIONAL,
IN ULONG JobMemberLevel);

EXTERN_C NTSTATUS Sw3NtCreateThread(
OUT PHANDLE ThreadHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN HANDLE ProcessHandle,
OUT PCLIENT_ID ClientId,
IN PCONTEXT ThreadContext,
IN PUSER_STACK InitialTeb,
IN BOOLEAN CreateSuspended);

EXTERN_C NTSTATUS Sw3NtIsProcessInJob(
IN HANDLE ProcessHandle,
IN HANDLE JobHandle OPTIONAL);

EXTERN_C NTSTATUS Sw3NtProtectVirtualMemory(
IN HANDLE ProcessHandle,
IN OUT PVOID * BaseAddress,
IN OUT PSIZE_T RegionSize,
IN ULONG NewProtect,
OUT PULONG OldProtect);

EXTERN_C NTSTATUS Sw3NtQuerySection(
IN HANDLE SectionHandle,
IN SECTION_INFORMATION_CLASS SectionInformationClass,
OUT PVOID SectionInformation,
IN ULONG SectionInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtResumeThread(
IN HANDLE ThreadHandle,
IN OUT PULONG PreviousSuspendCount OPTIONAL);

EXTERN_C NTSTATUS Sw3NtTerminateThread(
IN HANDLE ThreadHandle,
IN NTSTATUS ExitStatus);

EXTERN_C NTSTATUS Sw3NtReadRequestData(
IN HANDLE PortHandle,
IN PPORT_MESSAGE Message,
IN ULONG DataEntryIndex,
OUT PVOID Buffer,
IN ULONG BufferSize,
OUT PULONG NumberOfBytesRead OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateFile(
OUT PHANDLE FileHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PLARGE_INTEGER AllocationSize OPTIONAL,
IN ULONG FileAttributes,
IN ULONG ShareAccess,
IN ULONG CreateDisposition,
IN ULONG CreateOptions,
IN PVOID EaBuffer OPTIONAL,
IN ULONG EaLength);

EXTERN_C NTSTATUS Sw3NtQueryEvent(
IN HANDLE EventHandle,
IN EVENT_INFORMATION_CLASS EventInformationClass,
OUT PVOID EventInformation,
IN ULONG EventInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtWriteRequestData(
IN HANDLE PortHandle,
IN PPORT_MESSAGE Request,
IN ULONG DataIndex,
IN PVOID Buffer,
IN ULONG Length,
OUT PULONG ResultLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenDirectoryObject(
OUT PHANDLE DirectoryHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtAccessCheckByTypeAndAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN PUNICODE_STRING ObjectTypeName,
IN PUNICODE_STRING ObjectName,
IN PSECURITY_DESCRIPTOR SecurityDescriptor,
IN PSID PrincipalSelfSid OPTIONAL,
IN ACCESS_MASK DesiredAccess,
IN AUDIT_EVENT_TYPE AuditType,
IN ULONG Flags,
IN POBJECT_TYPE_LIST ObjectTypeList OPTIONAL,
IN ULONG ObjectTypeListLength,
IN PGENERIC_MAPPING GenericMapping,
IN BOOLEAN ObjectCreation,
OUT PACCESS_MASK GrantedAccess,
OUT PULONG AccessStatus,
OUT PBOOLEAN GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtWaitForMultipleObjects(
IN ULONG Count,
IN PHANDLE Handles,
IN WAIT_TYPE WaitType,
IN BOOLEAN Alertable,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetInformationObject(
IN HANDLE Handle,
IN OBJECT_INFORMATION_CLASS ObjectInformationClass,
IN PVOID ObjectInformation,
IN ULONG ObjectInformationLength);

EXTERN_C NTSTATUS Sw3NtCancelIoFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock);

EXTERN_C NTSTATUS Sw3NtTraceEvent(
IN HANDLE TraceHandle,
IN ULONG Flags,
IN ULONG FieldSize,
IN PVOID Fields);

EXTERN_C NTSTATUS Sw3NtPowerInformation(
IN POWER_INFORMATION_LEVEL InformationLevel,
IN PVOID InputBuffer OPTIONAL,
IN ULONG InputBufferLength,
OUT PVOID OutputBuffer OPTIONAL,
IN ULONG OutputBufferLength);

EXTERN_C NTSTATUS Sw3NtSetValueKey(
IN HANDLE KeyHandle,
IN PUNICODE_STRING ValueName,
IN ULONG TitleIndex OPTIONAL,
IN ULONG Type,
IN PVOID SystemData,
IN ULONG DataSize);

EXTERN_C NTSTATUS Sw3NtCancelTimer(
IN HANDLE TimerHandle,
OUT PBOOLEAN CurrentState OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetTimer(
IN HANDLE TimerHandle,
IN PLARGE_INTEGER DueTime,
IN PTIMER_APC_ROUTINE TimerApcRoutine OPTIONAL,
IN PVOID TimerContext OPTIONAL,
IN BOOLEAN ResumeTimer,
IN LONG Period OPTIONAL,
OUT PBOOLEAN PreviousState OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAccessCheckByType(
IN PSECURITY_DESCRIPTOR SecurityDescriptor,
IN PSID PrincipalSelfSid OPTIONAL,
IN HANDLE ClientToken,
IN ULONG DesiredAccess,
IN POBJECT_TYPE_LIST ObjectTypeList,
IN ULONG ObjectTypeListLength,
IN PGENERIC_MAPPING GenericMapping,
OUT PPRIVILEGE_SET PrivilegeSet,
IN OUT PULONG PrivilegeSetLength,
OUT PACCESS_MASK GrantedAccess,
OUT PULONG AccessStatus);

EXTERN_C NTSTATUS Sw3NtAccessCheckByTypeResultList(
IN PSECURITY_DESCRIPTOR SecurityDescriptor,
IN PSID PrincipalSelfSid OPTIONAL,
IN HANDLE ClientToken,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_TYPE_LIST ObjectTypeList,
IN ULONG ObjectTypeListLength,
IN PGENERIC_MAPPING GenericMapping,
OUT PPRIVILEGE_SET PrivilegeSet,
IN OUT PULONG PrivilegeSetLength,
OUT PACCESS_MASK GrantedAccess,
OUT PULONG AccessStatus);

EXTERN_C NTSTATUS Sw3NtAccessCheckByTypeResultListAndAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN PUNICODE_STRING ObjectTypeName,
IN PUNICODE_STRING ObjectName,
IN PSECURITY_DESCRIPTOR SecurityDescriptor,
IN PSID PrincipalSelfSid OPTIONAL,
IN ACCESS_MASK DesiredAccess,
IN AUDIT_EVENT_TYPE AuditType,
IN ULONG Flags,
IN POBJECT_TYPE_LIST ObjectTypeList OPTIONAL,
IN ULONG ObjectTypeListLength,
IN PGENERIC_MAPPING GenericMapping,
IN BOOLEAN ObjectCreation,
OUT PACCESS_MASK GrantedAccess,
OUT PULONG AccessStatus,
OUT PULONG GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtAccessCheckByTypeResultListAndAuditAlarmByHandle(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN HANDLE ClientToken,
IN PUNICODE_STRING ObjectTypeName,
IN PUNICODE_STRING ObjectName,
IN PSECURITY_DESCRIPTOR SecurityDescriptor,
IN PSID PrincipalSelfSid OPTIONAL,
IN ACCESS_MASK DesiredAccess,
IN AUDIT_EVENT_TYPE AuditType,
IN ULONG Flags,
IN POBJECT_TYPE_LIST ObjectTypeList OPTIONAL,
IN ULONG ObjectTypeListLength,
IN PGENERIC_MAPPING GenericMapping,
IN BOOLEAN ObjectCreation,
OUT PACCESS_MASK GrantedAccess,
OUT PULONG AccessStatus,
OUT PULONG GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtAcquireProcessActivityReference();

EXTERN_C NTSTATUS Sw3NtAddAtomEx(
IN PWSTR AtomName,
IN ULONG Length,
IN PRTL_ATOM Atom,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtAddBootEntry(
IN PBOOT_ENTRY BootEntry,
OUT PULONG Id OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAddDriverEntry(
IN PEFI_DRIVER_ENTRY DriverEntry,
OUT PULONG Id OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAdjustGroupsToken(
IN HANDLE TokenHandle,
IN BOOLEAN ResetToDefault,
IN PTOKEN_GROUPS NewState OPTIONAL,
IN ULONG BufferLength OPTIONAL,
OUT PTOKEN_GROUPS PreviousState OPTIONAL,
OUT PULONG ReturnLength);

EXTERN_C NTSTATUS Sw3NtAdjustTokenClaimsAndDeviceGroups(
IN HANDLE TokenHandle,
IN BOOLEAN UserResetToDefault,
IN BOOLEAN DeviceResetToDefault,
IN BOOLEAN DeviceGroupsResetToDefault,
IN PTOKEN_SECURITY_ATTRIBUTES_INFORMATION NewUserState OPTIONAL,
IN PTOKEN_SECURITY_ATTRIBUTES_INFORMATION NewDeviceState OPTIONAL,
IN PTOKEN_GROUPS NewDeviceGroupsState OPTIONAL,
IN ULONG UserBufferLength,
OUT PTOKEN_SECURITY_ATTRIBUTES_INFORMATION PreviousUserState OPTIONAL,
IN ULONG DeviceBufferLength,
OUT PTOKEN_SECURITY_ATTRIBUTES_INFORMATION PreviousDeviceState OPTIONAL,
IN ULONG DeviceGroupsBufferLength,
OUT PTOKEN_GROUPS PreviousDeviceGroups OPTIONAL,
OUT PULONG UserReturnLength OPTIONAL,
OUT PULONG DeviceReturnLength OPTIONAL,
OUT PULONG DeviceGroupsReturnBufferLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlertResumeThread(
IN HANDLE ThreadHandle,
OUT PULONG PreviousSuspendCount OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlertThread(
IN HANDLE ThreadHandle);

EXTERN_C NTSTATUS Sw3NtAlertThreadByThreadId(
IN ULONG ThreadId);

EXTERN_C NTSTATUS Sw3NtAllocateLocallyUniqueId(
OUT PLUID Luid);

EXTERN_C NTSTATUS Sw3NtAllocateReserveObject(
OUT PHANDLE MemoryReserveHandle,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN MEMORY_RESERVE_TYPE Type);

EXTERN_C NTSTATUS Sw3NtAllocateUserPhysicalPages(
IN HANDLE ProcessHandle,
IN OUT PULONG NumberOfPages,
OUT PULONG UserPfnArray);

EXTERN_C NTSTATUS Sw3NtAllocateUuids(
OUT PLARGE_INTEGER Time,
OUT PULONG Range,
OUT PULONG Sequence,
OUT PUCHAR Seed);

EXTERN_C NTSTATUS Sw3NtAllocateVirtualMemoryEx(
IN HANDLE ProcessHandle,
IN OUT PPVOID lpAddress,
IN ULONG_PTR ZeroBits,
IN OUT PSIZE_T pSize,
IN ULONG flAllocationType,
IN OUT PVOID DataBuffer OPTIONAL,
IN ULONG DataCount);

EXTERN_C NTSTATUS Sw3NtAlpcAcceptConnectPort(
OUT PHANDLE PortHandle,
IN HANDLE ConnectionPortHandle,
IN ULONG Flags,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PALPC_PORT_ATTRIBUTES PortAttributes OPTIONAL,
IN PVOID PortContext OPTIONAL,
IN PPORT_MESSAGE ConnectionRequest,
IN OUT PALPC_MESSAGE_ATTRIBUTES ConnectionMessageAttributes OPTIONAL,
IN BOOLEAN AcceptConnection);

EXTERN_C NTSTATUS Sw3NtAlpcCancelMessage(
IN HANDLE PortHandle,
IN ULONG Flags,
IN PALPC_CONTEXT_ATTR MessageContext);

EXTERN_C NTSTATUS Sw3NtAlpcConnectPort(
OUT PHANDLE PortHandle,
IN PUNICODE_STRING PortName,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PALPC_PORT_ATTRIBUTES PortAttributes OPTIONAL,
IN ULONG Flags,
IN PSID RequiredServerSid OPTIONAL,
IN OUT PPORT_MESSAGE ConnectionMessage OPTIONAL,
IN OUT PULONG BufferLength OPTIONAL,
IN OUT PALPC_MESSAGE_ATTRIBUTES OutMessageAttributes OPTIONAL,
IN OUT PALPC_MESSAGE_ATTRIBUTES InMessageAttributes OPTIONAL,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlpcConnectPortEx(
OUT PHANDLE PortHandle,
IN POBJECT_ATTRIBUTES ConnectionPortObjectAttributes,
IN POBJECT_ATTRIBUTES ClientPortObjectAttributes OPTIONAL,
IN PALPC_PORT_ATTRIBUTES PortAttributes OPTIONAL,
IN ULONG Flags,
IN PSECURITY_DESCRIPTOR ServerSecurityRequirements OPTIONAL,
IN OUT PPORT_MESSAGE ConnectionMessage OPTIONAL,
IN OUT PSIZE_T BufferLength OPTIONAL,
IN OUT PALPC_MESSAGE_ATTRIBUTES OutMessageAttributes OPTIONAL,
IN OUT PALPC_MESSAGE_ATTRIBUTES InMessageAttributes OPTIONAL,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlpcCreatePort(
OUT PHANDLE PortHandle,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PALPC_PORT_ATTRIBUTES PortAttributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlpcCreatePortSection(
IN HANDLE PortHandle,
IN ULONG Flags,
IN HANDLE SectionHandle OPTIONAL,
IN SIZE_T SectionSize,
OUT PHANDLE AlpcSectionHandle,
OUT PSIZE_T ActualSectionSize);

EXTERN_C NTSTATUS Sw3NtAlpcCreateResourceReserve(
IN HANDLE PortHandle,
IN ULONG Flags,
IN SIZE_T MessageSize,
OUT PHANDLE ResourceId);

EXTERN_C NTSTATUS Sw3NtAlpcCreateSectionView(
IN HANDLE PortHandle,
IN ULONG Flags,
IN OUT PALPC_DATA_VIEW_ATTR ViewAttributes);

EXTERN_C NTSTATUS Sw3NtAlpcCreateSecurityContext(
IN HANDLE PortHandle,
IN ULONG Flags,
IN OUT PALPC_SECURITY_ATTR SecurityAttribute);

EXTERN_C NTSTATUS Sw3NtAlpcDeletePortSection(
IN HANDLE PortHandle,
IN ULONG Flags,
IN HANDLE SectionHandle);

EXTERN_C NTSTATUS Sw3NtAlpcDeleteResourceReserve(
IN HANDLE PortHandle,
IN ULONG Flags,
IN HANDLE ResourceId);

EXTERN_C NTSTATUS Sw3NtAlpcDeleteSectionView(
IN HANDLE PortHandle,
IN ULONG Flags,
IN PVOID ViewBase);

EXTERN_C NTSTATUS Sw3NtAlpcDeleteSecurityContext(
IN HANDLE PortHandle,
IN ULONG Flags,
IN HANDLE ContextHandle);

EXTERN_C NTSTATUS Sw3NtAlpcDisconnectPort(
IN HANDLE PortHandle,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtAlpcImpersonateClientContainerOfPort(
IN HANDLE PortHandle,
IN PPORT_MESSAGE Message,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtAlpcImpersonateClientOfPort(
IN HANDLE PortHandle,
IN PPORT_MESSAGE Message,
IN PVOID Flags);

EXTERN_C NTSTATUS Sw3NtAlpcOpenSenderProcess(
OUT PHANDLE ProcessHandle,
IN HANDLE PortHandle,
IN PPORT_MESSAGE PortMessage,
IN ULONG Flags,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtAlpcOpenSenderThread(
OUT PHANDLE ThreadHandle,
IN HANDLE PortHandle,
IN PPORT_MESSAGE PortMessage,
IN ULONG Flags,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtAlpcQueryInformation(
IN HANDLE PortHandle OPTIONAL,
IN ALPC_PORT_INFORMATION_CLASS PortInformationClass,
IN OUT PVOID PortInformation,
IN ULONG Length,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlpcQueryInformationMessage(
IN HANDLE PortHandle,
IN PPORT_MESSAGE PortMessage,
IN ALPC_MESSAGE_INFORMATION_CLASS MessageInformationClass,
OUT PVOID MessageInformation OPTIONAL,
IN ULONG Length,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlpcRevokeSecurityContext(
IN HANDLE PortHandle,
IN ULONG Flags,
IN HANDLE ContextHandle);

EXTERN_C NTSTATUS Sw3NtAlpcSendWaitReceivePort(
IN HANDLE PortHandle,
IN ULONG Flags,
IN PPORT_MESSAGE SendMessage OPTIONAL,
IN OUT PALPC_MESSAGE_ATTRIBUTES SendMessageAttributes OPTIONAL,
OUT PPORT_MESSAGE ReceiveMessage OPTIONAL,
IN OUT PSIZE_T BufferLength OPTIONAL,
IN OUT PALPC_MESSAGE_ATTRIBUTES ReceiveMessageAttributes OPTIONAL,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtAlpcSetInformation(
IN HANDLE PortHandle,
IN ALPC_PORT_INFORMATION_CLASS PortInformationClass,
IN PVOID PortInformation OPTIONAL,
IN ULONG Length);

EXTERN_C NTSTATUS Sw3NtAreMappedFilesTheSame(
IN PVOID File1MappedAsAnImage,
IN PVOID File2MappedAsFile);

EXTERN_C NTSTATUS Sw3NtAssignProcessToJobObject(
IN HANDLE JobHandle,
IN HANDLE ProcessHandle);

EXTERN_C NTSTATUS Sw3NtAssociateWaitCompletionPacket(
IN HANDLE WaitCompletionPacketHandle,
IN HANDLE IoCompletionHandle,
IN HANDLE TargetObjectHandle,
IN PVOID KeyContext OPTIONAL,
IN PVOID ApcContext OPTIONAL,
IN NTSTATUS IoStatus,
IN ULONG_PTR IoStatusInformation,
OUT PBOOLEAN AlreadySignaled OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCallEnclave(
IN PENCLAVE_ROUTINE Routine,
IN PVOID Parameter,
IN BOOLEAN WaitForThread,
IN OUT PVOID ReturnValue OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCancelIoFileEx(
IN HANDLE FileHandle,
IN PIO_STATUS_BLOCK IoRequestToCancel OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock);

EXTERN_C NTSTATUS Sw3NtCancelSynchronousIoFile(
IN HANDLE ThreadHandle,
IN PIO_STATUS_BLOCK IoRequestToCancel OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock);

EXTERN_C NTSTATUS Sw3NtCancelTimer2(
IN HANDLE TimerHandle,
IN PT2_CANCEL_PARAMETERS Parameters);

EXTERN_C NTSTATUS Sw3NtCancelWaitCompletionPacket(
IN HANDLE WaitCompletionPacketHandle,
IN BOOLEAN RemoveSignaledPacket);

EXTERN_C NTSTATUS Sw3NtCommitComplete(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCommitEnlistment(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCommitRegistryTransaction(
IN HANDLE RegistryHandle,
IN BOOL Wait);

EXTERN_C NTSTATUS Sw3NtCommitTransaction(
IN HANDLE TransactionHandle,
IN BOOLEAN Wait);

EXTERN_C NTSTATUS Sw3NtCompactKeys(
IN ULONG Count,
IN HANDLE KeyArray);

EXTERN_C NTSTATUS Sw3NtCompareObjects(
IN HANDLE FirstObjectHandle,
IN HANDLE SecondObjectHandle);

EXTERN_C NTSTATUS Sw3NtCompareSigningLevels(
IN ULONG UnknownParameter1,
IN ULONG UnknownParameter2);

EXTERN_C NTSTATUS Sw3NtCompareTokens(
IN HANDLE FirstTokenHandle,
IN HANDLE SecondTokenHandle,
OUT PBOOLEAN Equal);

EXTERN_C NTSTATUS Sw3NtCompleteConnectPort(
IN HANDLE PortHandle);

EXTERN_C NTSTATUS Sw3NtCompressKey(
IN HANDLE Key);

EXTERN_C NTSTATUS Sw3NtConnectPort(
OUT PHANDLE PortHandle,
IN PUNICODE_STRING PortName,
IN PSECURITY_QUALITY_OF_SERVICE SecurityQos,
IN OUT PPORT_SECTION_WRITE ClientView OPTIONAL,
IN OUT PPORT_SECTION_READ ServerView OPTIONAL,
OUT PULONG MaxMessageLength OPTIONAL,
IN OUT PVOID ConnectionInformation OPTIONAL,
IN OUT PULONG ConnectionInformationLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtConvertBetweenAuxiliaryCounterAndPerformanceCounter(
IN ULONG UnknownParameter1,
IN ULONG UnknownParameter2,
IN ULONG UnknownParameter3,
IN ULONG UnknownParameter4);

EXTERN_C NTSTATUS Sw3NtCreateDebugObject(
OUT PHANDLE DebugObjectHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtCreateDirectoryObject(
OUT PHANDLE DirectoryHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtCreateDirectoryObjectEx(
OUT PHANDLE DirectoryHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN HANDLE ShadowDirectoryHandle,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtCreateEnclave(
IN HANDLE ProcessHandle,
IN OUT PVOID BaseAddress,
IN ULONG_PTR ZeroBits,
IN SIZE_T Size,
IN SIZE_T InitialCommitment,
IN ULONG EnclaveType,
IN PVOID EnclaveInformation,
IN ULONG EnclaveInformationLength,
OUT PULONG EnclaveError OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateEnlistment(
OUT PHANDLE EnlistmentHandle,
IN ACCESS_MASK DesiredAccess,
IN HANDLE ResourceManagerHandle,
IN HANDLE TransactionHandle,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG CreateOptions OPTIONAL,
IN NOTIFICATION_MASK NotificationMask,
IN PVOID EnlistmentKey OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateEventPair(
OUT PHANDLE EventPairHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateIRTimer(
OUT PHANDLE TimerHandle,
IN ACCESS_MASK DesiredAccess);

EXTERN_C NTSTATUS Sw3NtCreateIoCompletion(
OUT PHANDLE IoCompletionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG Count OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateJobObject(
OUT PHANDLE JobHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateJobSet(
IN ULONG NumJob,
IN PJOB_SET_ARRAY UserJobSet,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtCreateKeyTransacted(
OUT PHANDLE KeyHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN ULONG TitleIndex,
IN PUNICODE_STRING Class OPTIONAL,
IN ULONG CreateOptions,
IN HANDLE TransactionHandle,
OUT PULONG Disposition OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateKeyedEvent(
OUT PHANDLE KeyedEventHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtCreateLowBoxToken(
OUT PHANDLE TokenHandle,
IN HANDLE ExistingTokenHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PSID PackageSid,
IN ULONG CapabilityCount,
IN PSID_AND_ATTRIBUTES Capabilities OPTIONAL,
IN ULONG HandleCount,
IN HANDLE Handles OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateMailslotFile(
OUT PHANDLE FileHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG CreateOptions,
IN ULONG MailslotQuota,
IN ULONG MaximumMessageSize,
IN PLARGE_INTEGER ReadTimeout);

EXTERN_C NTSTATUS Sw3NtCreateMutant(
OUT PHANDLE MutantHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN BOOLEAN InitialOwner);

EXTERN_C NTSTATUS Sw3NtCreateNamedPipeFile(
OUT PHANDLE FileHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG ShareAccess,
IN ULONG CreateDisposition,
IN ULONG CreateOptions,
IN BOOLEAN NamedPipeType,
IN BOOLEAN ReadMode,
IN BOOLEAN CompletionMode,
IN ULONG MaximumInstances,
IN ULONG InboundQuota,
IN ULONG OutboundQuota,
IN PLARGE_INTEGER DefaultTimeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreatePagingFile(
IN PUNICODE_STRING PageFileName,
IN PULARGE_INTEGER MinimumSize,
IN PULARGE_INTEGER MaximumSize,
IN ULONG Priority);

EXTERN_C NTSTATUS Sw3NtCreatePartition(
OUT PHANDLE PartitionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG PreferredNode);

EXTERN_C NTSTATUS Sw3NtCreatePort(
OUT PHANDLE PortHandle,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG MaxConnectionInfoLength,
IN ULONG MaxMessageLength,
IN ULONG MaxPoolUsage OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreatePrivateNamespace(
OUT PHANDLE NamespaceHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN PVOID BoundaryDescriptor);

EXTERN_C NTSTATUS Sw3NtCreateProcess(
OUT PHANDLE ProcessHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN HANDLE ParentProcess,
IN BOOLEAN InheritObjectTable,
IN HANDLE SectionHandle OPTIONAL,
IN HANDLE DebugPort OPTIONAL,
IN HANDLE ExceptionPort OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateProfile(
OUT PHANDLE ProfileHandle,
IN HANDLE Process OPTIONAL,
IN PVOID ProfileBase,
IN ULONG ProfileSize,
IN ULONG BucketSize,
IN PULONG Buffer,
IN ULONG BufferSize,
IN KPROFILE_SOURCE ProfileSource,
IN ULONG Affinity);

EXTERN_C NTSTATUS Sw3NtCreateProfileEx(
OUT PHANDLE ProfileHandle,
IN HANDLE Process OPTIONAL,
IN PVOID ProfileBase,
IN SIZE_T ProfileSize,
IN ULONG BucketSize,
IN PULONG Buffer,
IN ULONG BufferSize,
IN KPROFILE_SOURCE ProfileSource,
IN USHORT GroupCount,
IN PGROUP_AFFINITY GroupAffinity);

EXTERN_C NTSTATUS Sw3NtCreateRegistryTransaction(
OUT PHANDLE Handle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN DWORD Flags);

EXTERN_C NTSTATUS Sw3NtCreateResourceManager(
OUT PHANDLE ResourceManagerHandle,
IN ACCESS_MASK DesiredAccess,
IN HANDLE TmHandle,
IN LPGUID RmGuid,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG CreateOptions OPTIONAL,
IN PUNICODE_STRING Description OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateSemaphore(
OUT PHANDLE SemaphoreHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN LONG InitialCount,
IN LONG MaximumCount);

EXTERN_C NTSTATUS Sw3NtCreateSymbolicLinkObject(
OUT PHANDLE LinkHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN PUNICODE_STRING LinkTarget);

EXTERN_C NTSTATUS Sw3NtCreateThreadEx(
OUT PHANDLE ThreadHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN HANDLE ProcessHandle,
IN PVOID StartRoutine,
IN PVOID Argument OPTIONAL,
IN ULONG CreateFlags,
IN SIZE_T ZeroBits,
IN SIZE_T StackSize,
IN SIZE_T MaximumStackSize,
IN PPS_ATTRIBUTE_LIST AttributeList OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateTimer(
OUT PHANDLE TimerHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN TIMER_TYPE TimerType);

EXTERN_C NTSTATUS Sw3NtCreateTimer2(
OUT PHANDLE TimerHandle,
IN PVOID Reserved1 OPTIONAL,
IN PVOID Reserved2 OPTIONAL,
IN ULONG Attributes,
IN ACCESS_MASK DesiredAccess);

EXTERN_C NTSTATUS Sw3NtCreateToken(
OUT PHANDLE TokenHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN TOKEN_TYPE TokenType,
IN PLUID AuthenticationId,
IN PLARGE_INTEGER ExpirationTime,
IN PTOKEN_USER User,
IN PTOKEN_GROUPS Groups,
IN PTOKEN_PRIVILEGES Privileges,
IN PTOKEN_OWNER Owner OPTIONAL,
IN PTOKEN_PRIMARY_GROUP PrimaryGroup,
IN PTOKEN_DEFAULT_DACL DefaultDacl OPTIONAL,
IN PTOKEN_SOURCE TokenSource);

EXTERN_C NTSTATUS Sw3NtCreateTokenEx(
OUT PHANDLE TokenHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN TOKEN_TYPE TokenType,
IN PLUID AuthenticationId,
IN PLARGE_INTEGER ExpirationTime,
IN PTOKEN_USER User,
IN PTOKEN_GROUPS Groups,
IN PTOKEN_PRIVILEGES Privileges,
IN PTOKEN_SECURITY_ATTRIBUTES_INFORMATION UserAttributes OPTIONAL,
IN PTOKEN_SECURITY_ATTRIBUTES_INFORMATION DeviceAttributes OPTIONAL,
IN PTOKEN_GROUPS DeviceGroups OPTIONAL,
IN PTOKEN_MANDATORY_POLICY TokenMandatoryPolicy OPTIONAL,
IN PTOKEN_OWNER Owner OPTIONAL,
IN PTOKEN_PRIMARY_GROUP PrimaryGroup,
IN PTOKEN_DEFAULT_DACL DefaultDacl OPTIONAL,
IN PTOKEN_SOURCE TokenSource);

EXTERN_C NTSTATUS Sw3NtCreateTransaction(
OUT PHANDLE TransactionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN LPGUID Uow OPTIONAL,
IN HANDLE TmHandle OPTIONAL,
IN ULONG CreateOptions OPTIONAL,
IN ULONG IsolationLevel OPTIONAL,
IN ULONG IsolationFlags OPTIONAL,
IN PLARGE_INTEGER Timeout OPTIONAL,
IN PUNICODE_STRING Description OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateTransactionManager(
OUT PHANDLE TmHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PUNICODE_STRING LogFileName OPTIONAL,
IN ULONG CreateOptions OPTIONAL,
IN ULONG CommitStrength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateUserProcess(
OUT PHANDLE ProcessHandle,
OUT PHANDLE ThreadHandle,
IN ACCESS_MASK ProcessDesiredAccess,
IN ACCESS_MASK ThreadDesiredAccess,
IN POBJECT_ATTRIBUTES ProcessObjectAttributes OPTIONAL,
IN POBJECT_ATTRIBUTES ThreadObjectAttributes OPTIONAL,
IN ULONG ProcessFlags,
IN ULONG ThreadFlags,
IN PVOID ProcessParameters OPTIONAL,
IN OUT PPS_CREATE_INFO CreateInfo,
IN PPS_ATTRIBUTE_LIST AttributeList OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateWaitCompletionPacket(
OUT PHANDLE WaitCompletionPacketHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateWaitablePort(
OUT PHANDLE PortHandle,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN ULONG MaxConnectionInfoLength,
IN ULONG MaxMessageLength,
IN ULONG MaxPoolUsage OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateWnfStateName(
OUT PCWNF_STATE_NAME StateName,
IN WNF_STATE_NAME_LIFETIME NameLifetime,
IN WNF_DATA_SCOPE DataScope,
IN BOOLEAN PersistData,
IN PCWNF_TYPE_ID TypeId OPTIONAL,
IN ULONG MaximumStateSize,
IN PSECURITY_DESCRIPTOR SecurityDescriptor);

EXTERN_C NTSTATUS Sw3NtCreateWorkerFactory(
OUT PHANDLE WorkerFactoryHandleReturn,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN HANDLE CompletionPortHandle,
IN HANDLE WorkerProcessHandle,
IN PVOID StartRoutine,
IN PVOID StartParameter OPTIONAL,
IN ULONG MaxThreadCount OPTIONAL,
IN SIZE_T StackReserve OPTIONAL,
IN SIZE_T StackCommit OPTIONAL);

EXTERN_C NTSTATUS Sw3NtDebugActiveProcess(
IN HANDLE ProcessHandle,
IN HANDLE DebugObjectHandle);

EXTERN_C NTSTATUS Sw3NtDebugContinue(
IN HANDLE DebugObjectHandle,
IN PCLIENT_ID ClientId,
IN NTSTATUS ContinueStatus);

EXTERN_C NTSTATUS Sw3NtDeleteAtom(
IN USHORT Atom);

EXTERN_C NTSTATUS Sw3NtDeleteBootEntry(
IN ULONG Id);

EXTERN_C NTSTATUS Sw3NtDeleteDriverEntry(
IN ULONG Id);

EXTERN_C NTSTATUS Sw3NtDeleteFile(
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtDeleteKey(
IN HANDLE KeyHandle);

EXTERN_C NTSTATUS Sw3NtDeleteObjectAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN BOOLEAN GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtDeletePrivateNamespace(
IN HANDLE NamespaceHandle);

EXTERN_C NTSTATUS Sw3NtDeleteValueKey(
IN HANDLE KeyHandle,
IN PUNICODE_STRING ValueName);

EXTERN_C NTSTATUS Sw3NtDeleteWnfStateData(
IN PCWNF_STATE_NAME StateName,
IN PVOID ExplicitScope OPTIONAL);

EXTERN_C NTSTATUS Sw3NtDeleteWnfStateName(
IN PCWNF_STATE_NAME StateName);

EXTERN_C NTSTATUS Sw3NtDisableLastKnownGood();

EXTERN_C NTSTATUS Sw3NtDisplayString(
IN PUNICODE_STRING String);

EXTERN_C NTSTATUS Sw3NtDrawText(
IN PUNICODE_STRING String);

EXTERN_C NTSTATUS Sw3NtEnableLastKnownGood();

EXTERN_C NTSTATUS Sw3NtEnumerateBootEntries(
OUT PVOID Buffer OPTIONAL,
IN OUT PULONG BufferLength);

EXTERN_C NTSTATUS Sw3NtEnumerateDriverEntries(
OUT PVOID Buffer OPTIONAL,
IN OUT PULONG BufferLength);

EXTERN_C NTSTATUS Sw3NtEnumerateSystemEnvironmentValuesEx(
IN ULONG InformationClass,
OUT PVOID Buffer,
IN OUT PULONG BufferLength);

EXTERN_C NTSTATUS Sw3NtEnumerateTransactionObject(
IN HANDLE RootObjectHandle OPTIONAL,
IN KTMOBJECT_TYPE QueryType,
IN OUT PKTMOBJECT_CURSOR ObjectCursor,
IN ULONG ObjectCursorLength,
OUT PULONG ReturnLength);

EXTERN_C NTSTATUS Sw3NtExtendSection(
IN HANDLE SectionHandle,
IN OUT PLARGE_INTEGER NewSectionSize);

EXTERN_C NTSTATUS Sw3NtFilterBootOption(
IN FILTER_BOOT_OPTION_OPERATION FilterOperation,
IN ULONG ObjectType,
IN ULONG ElementType,
IN PVOID SystemData OPTIONAL,
IN ULONG DataSize);

EXTERN_C NTSTATUS Sw3NtFilterToken(
IN HANDLE ExistingTokenHandle,
IN ULONG Flags,
IN PTOKEN_GROUPS SidsToDisable OPTIONAL,
IN PTOKEN_PRIVILEGES PrivilegesToDelete OPTIONAL,
IN PTOKEN_GROUPS RestrictedSids OPTIONAL,
OUT PHANDLE NewTokenHandle);

EXTERN_C NTSTATUS Sw3NtFilterTokenEx(
IN HANDLE TokenHandle,
IN ULONG Flags,
IN PTOKEN_GROUPS SidsToDisable OPTIONAL,
IN PTOKEN_PRIVILEGES PrivilegesToDelete OPTIONAL,
IN PTOKEN_GROUPS RestrictedSids OPTIONAL,
IN ULONG DisableUserClaimsCount,
IN PUNICODE_STRING UserClaimsToDisable OPTIONAL,
IN ULONG DisableDeviceClaimsCount,
IN PUNICODE_STRING DeviceClaimsToDisable OPTIONAL,
IN PTOKEN_GROUPS DeviceGroupsToDisable OPTIONAL,
IN PTOKEN_SECURITY_ATTRIBUTES_INFORMATION RestrictedUserAttributes OPTIONAL,
IN PTOKEN_SECURITY_ATTRIBUTES_INFORMATION RestrictedDeviceAttributes OPTIONAL,
IN PTOKEN_GROUPS RestrictedDeviceGroups OPTIONAL,
OUT PHANDLE NewTokenHandle);

EXTERN_C NTSTATUS Sw3NtFlushBuffersFileEx(
IN HANDLE FileHandle,
IN ULONG Flags,
IN PVOID Parameters,
IN ULONG ParametersSize,
OUT PIO_STATUS_BLOCK IoStatusBlock);

EXTERN_C NTSTATUS Sw3NtFlushInstallUILanguage(
IN LANGID InstallUILanguage,
IN ULONG SetComittedFlag);

EXTERN_C NTSTATUS Sw3NtFlushInstructionCache(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress OPTIONAL,
IN ULONG Length);

EXTERN_C NTSTATUS Sw3NtFlushKey(
IN HANDLE KeyHandle);

EXTERN_C NTSTATUS Sw3NtFlushProcessWriteBuffers();

EXTERN_C NTSTATUS Sw3NtFlushVirtualMemory(
IN HANDLE ProcessHandle,
IN OUT PVOID BaseAddress,
IN OUT PULONG RegionSize,
OUT PIO_STATUS_BLOCK IoStatusBlock);

EXTERN_C NTSTATUS Sw3NtFlushWriteBuffer();

EXTERN_C NTSTATUS Sw3NtFreeUserPhysicalPages(
IN HANDLE ProcessHandle,
IN OUT PULONG NumberOfPages,
IN PULONG UserPfnArray);

EXTERN_C NTSTATUS Sw3NtFreezeRegistry(
IN ULONG TimeOutInSeconds);

EXTERN_C NTSTATUS Sw3NtFreezeTransactions(
IN PLARGE_INTEGER FreezeTimeout,
IN PLARGE_INTEGER ThawTimeout);

EXTERN_C NTSTATUS Sw3NtGetCachedSigningLevel(
IN HANDLE File,
OUT PULONG Flags,
OUT PSE_SIGNING_LEVEL SigningLevel,
OUT PUCHAR Thumbprint OPTIONAL,
IN OUT PULONG ThumbprintSize OPTIONAL,
OUT PULONG ThumbprintAlgorithm OPTIONAL);

EXTERN_C NTSTATUS Sw3NtGetCompleteWnfStateSubscription(
IN PCWNF_STATE_NAME OldDescriptorStateName OPTIONAL,
IN PLARGE_INTEGER OldSubscriptionId OPTIONAL,
IN ULONG OldDescriptorEventMask OPTIONAL,
IN ULONG OldDescriptorStatus OPTIONAL,
OUT PWNF_DELIVERY_DESCRIPTOR NewDeliveryDescriptor,
IN ULONG DescriptorSize);

EXTERN_C NTSTATUS Sw3NtGetContextThread(
IN HANDLE ThreadHandle,
IN OUT PCONTEXT ThreadContext);

EXTERN_C NTSTATUS Sw3NtGetCurrentProcessorNumber();

EXTERN_C NTSTATUS Sw3NtGetCurrentProcessorNumberEx(
OUT PULONG ProcNumber OPTIONAL);

EXTERN_C NTSTATUS Sw3NtGetDevicePowerState(
IN HANDLE Device,
OUT PDEVICE_POWER_STATE State);

EXTERN_C NTSTATUS Sw3NtGetMUIRegistryInfo(
IN ULONG Flags,
IN OUT PULONG DataSize,
OUT PVOID SystemData);

EXTERN_C NTSTATUS Sw3NtGetNextProcess(
IN HANDLE ProcessHandle,
IN ACCESS_MASK DesiredAccess,
IN ULONG HandleAttributes,
IN ULONG Flags,
OUT PHANDLE NewProcessHandle);

EXTERN_C NTSTATUS Sw3NtGetNextThread(
IN HANDLE ProcessHandle,
IN HANDLE ThreadHandle,
IN ACCESS_MASK DesiredAccess,
IN ULONG HandleAttributes,
IN ULONG Flags,
OUT PHANDLE NewThreadHandle);

EXTERN_C NTSTATUS Sw3NtGetNlsSectionPtr(
IN ULONG SectionType,
IN ULONG SectionData,
IN PVOID ContextData,
OUT PVOID SectionPointer,
OUT PULONG SectionSize);

EXTERN_C NTSTATUS Sw3NtGetNotificationResourceManager(
IN HANDLE ResourceManagerHandle,
OUT PTRANSACTION_NOTIFICATION TransactionNotification,
IN ULONG NotificationLength,
IN PLARGE_INTEGER Timeout OPTIONAL,
OUT PULONG ReturnLength OPTIONAL,
IN ULONG Asynchronous,
IN ULONG AsynchronousContext OPTIONAL);

EXTERN_C NTSTATUS Sw3NtGetWriteWatch(
IN HANDLE ProcessHandle,
IN ULONG Flags,
IN PVOID BaseAddress,
IN ULONG RegionSize,
OUT PULONG UserAddressArray,
IN OUT PULONG EntriesInUserAddressArray,
OUT PULONG Granularity);

EXTERN_C NTSTATUS Sw3NtImpersonateAnonymousToken(
IN HANDLE ThreadHandle);

EXTERN_C NTSTATUS Sw3NtImpersonateThread(
IN HANDLE ServerThreadHandle,
IN HANDLE ClientThreadHandle,
IN PSECURITY_QUALITY_OF_SERVICE SecurityQos);

EXTERN_C NTSTATUS Sw3NtInitializeEnclave(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress,
IN PVOID EnclaveInformation,
IN ULONG EnclaveInformationLength,
OUT PULONG EnclaveError OPTIONAL);

EXTERN_C NTSTATUS Sw3NtInitializeNlsFiles(
OUT PVOID BaseAddress,
OUT PLCID DefaultLocaleId,
OUT PLARGE_INTEGER DefaultCasingTableSize);

EXTERN_C NTSTATUS Sw3NtInitializeRegistry(
IN USHORT BootCondition);

EXTERN_C NTSTATUS Sw3NtInitiatePowerAction(
IN POWER_ACTION SystemAction,
IN SYSTEM_POWER_STATE LightestSystemState,
IN ULONG Flags,
IN BOOLEAN Asynchronous);

EXTERN_C NTSTATUS Sw3NtIsSystemResumeAutomatic();

EXTERN_C NTSTATUS Sw3NtIsUILanguageComitted();

EXTERN_C NTSTATUS Sw3NtListenPort(
IN HANDLE PortHandle,
OUT PPORT_MESSAGE ConnectionRequest);

EXTERN_C NTSTATUS Sw3NtLoadDriver(
IN PUNICODE_STRING DriverServiceName);

EXTERN_C NTSTATUS Sw3NtLoadEnclaveData(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress,
IN PVOID Buffer,
IN SIZE_T BufferSize,
IN ULONG Protect,
IN PVOID PageInformation,
IN ULONG PageInformationLength,
OUT PSIZE_T NumberOfBytesWritten OPTIONAL,
OUT PULONG EnclaveError OPTIONAL);

EXTERN_C NTSTATUS Sw3NtLoadHotPatch(
IN PUNICODE_STRING HotPatchName,
IN ULONG LoadFlag);

EXTERN_C NTSTATUS Sw3NtLoadKey(
IN POBJECT_ATTRIBUTES TargetKey,
IN POBJECT_ATTRIBUTES SourceFile);

EXTERN_C NTSTATUS Sw3NtLoadKey2(
IN POBJECT_ATTRIBUTES TargetKey,
IN POBJECT_ATTRIBUTES SourceFile,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtLoadKeyEx(
IN POBJECT_ATTRIBUTES TargetKey,
IN POBJECT_ATTRIBUTES SourceFile,
IN ULONG Flags,
IN HANDLE TrustClassKey OPTIONAL,
IN HANDLE Event OPTIONAL,
IN ACCESS_MASK DesiredAccess OPTIONAL,
OUT PHANDLE RootHandle OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatus OPTIONAL);

EXTERN_C NTSTATUS Sw3NtLockFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PULARGE_INTEGER ByteOffset,
IN PULARGE_INTEGER Length,
IN ULONG Key,
IN BOOLEAN FailImmediately,
IN BOOLEAN ExclusiveLock);

EXTERN_C NTSTATUS Sw3NtLockProductActivationKeys(
IN OUT PULONG pPrivateVer OPTIONAL,
OUT PULONG pSafeMode OPTIONAL);

EXTERN_C NTSTATUS Sw3NtLockRegistryKey(
IN HANDLE KeyHandle);

EXTERN_C NTSTATUS Sw3NtLockVirtualMemory(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress,
IN PULONG RegionSize,
IN ULONG MapType);

EXTERN_C NTSTATUS Sw3NtMakePermanentObject(
IN HANDLE Handle);

EXTERN_C NTSTATUS Sw3NtMakeTemporaryObject(
IN HANDLE Handle);

EXTERN_C NTSTATUS Sw3NtManagePartition(
IN HANDLE TargetHandle,
IN HANDLE SourceHandle,
IN MEMORY_PARTITION_INFORMATION_CLASS PartitionInformationClass,
IN OUT PVOID PartitionInformation,
IN ULONG PartitionInformationLength);

EXTERN_C NTSTATUS Sw3NtMapCMFModule(
IN ULONG What,
IN ULONG Index,
OUT PULONG CacheIndexOut OPTIONAL,
OUT PULONG CacheFlagsOut OPTIONAL,
OUT PULONG ViewSizeOut OPTIONAL,
OUT PVOID BaseAddress OPTIONAL);

EXTERN_C NTSTATUS Sw3NtMapUserPhysicalPages(
IN PVOID VirtualAddress,
IN PULONG NumberOfPages,
IN PULONG UserPfnArray OPTIONAL);

EXTERN_C NTSTATUS Sw3NtMapViewOfSectionEx(
IN HANDLE SectionHandle,
IN HANDLE ProcessHandle,
IN OUT PLARGE_INTEGER SectionOffset,
IN OUT PPVOID BaseAddress,
IN OUT PSIZE_T ViewSize,
IN ULONG AllocationType,
IN ULONG Protect,
IN OUT PVOID DataBuffer OPTIONAL,
IN ULONG DataCount);

EXTERN_C NTSTATUS Sw3NtModifyBootEntry(
IN PBOOT_ENTRY BootEntry);

EXTERN_C NTSTATUS Sw3NtModifyDriverEntry(
IN PEFI_DRIVER_ENTRY DriverEntry);

EXTERN_C NTSTATUS Sw3NtNotifyChangeDirectoryFile(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PFILE_NOTIFY_INFORMATION Buffer,
IN ULONG Length,
IN ULONG CompletionFilter,
IN BOOLEAN WatchTree);

EXTERN_C NTSTATUS Sw3NtNotifyChangeDirectoryFileEx(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PVOID Buffer,
IN ULONG Length,
IN ULONG CompletionFilter,
IN BOOLEAN WatchTree,
IN DIRECTORY_NOTIFY_INFORMATION_CLASS DirectoryNotifyInformationClass OPTIONAL);

EXTERN_C NTSTATUS Sw3NtNotifyChangeKey(
IN HANDLE KeyHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG CompletionFilter,
IN BOOLEAN WatchTree,
OUT PVOID Buffer OPTIONAL,
IN ULONG BufferSize,
IN BOOLEAN Asynchronous);

EXTERN_C NTSTATUS Sw3NtNotifyChangeMultipleKeys(
IN HANDLE MasterKeyHandle,
IN ULONG Count OPTIONAL,
IN POBJECT_ATTRIBUTES SubordinateObjects OPTIONAL,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN ULONG CompletionFilter,
IN BOOLEAN WatchTree,
OUT PVOID Buffer OPTIONAL,
IN ULONG BufferSize,
IN BOOLEAN Asynchronous);

EXTERN_C NTSTATUS Sw3NtNotifyChangeSession(
IN HANDLE SessionHandle,
IN ULONG ChangeSequenceNumber,
IN PLARGE_INTEGER ChangeTimeStamp,
IN IO_SESSION_EVENT Event,
IN IO_SESSION_STATE NewState,
IN IO_SESSION_STATE PreviousState,
IN PVOID Payload OPTIONAL,
IN ULONG PayloadSize);

EXTERN_C NTSTATUS Sw3NtOpenEnlistment(
OUT PHANDLE EnlistmentHandle,
IN ACCESS_MASK DesiredAccess,
IN HANDLE ResourceManagerHandle,
IN LPGUID EnlistmentGuid,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenEventPair(
OUT PHANDLE EventPairHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenIoCompletion(
OUT PHANDLE IoCompletionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenJobObject(
OUT PHANDLE JobHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenKeyEx(
OUT PHANDLE KeyHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN ULONG OpenOptions);

EXTERN_C NTSTATUS Sw3NtOpenKeyTransacted(
OUT PHANDLE KeyHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN HANDLE TransactionHandle);

EXTERN_C NTSTATUS Sw3NtOpenKeyTransactedEx(
OUT PHANDLE KeyHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN ULONG OpenOptions,
IN HANDLE TransactionHandle);

EXTERN_C NTSTATUS Sw3NtOpenKeyedEvent(
OUT PHANDLE KeyedEventHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenMutant(
OUT PHANDLE MutantHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenObjectAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN PUNICODE_STRING ObjectTypeName,
IN PUNICODE_STRING ObjectName,
IN PSECURITY_DESCRIPTOR SecurityDescriptor OPTIONAL,
IN HANDLE ClientToken,
IN ACCESS_MASK DesiredAccess,
IN ACCESS_MASK GrantedAccess,
IN PPRIVILEGE_SET Privileges OPTIONAL,
IN BOOLEAN ObjectCreation,
IN BOOLEAN AccessGranted,
OUT PBOOLEAN GenerateOnClose);

EXTERN_C NTSTATUS Sw3NtOpenPartition(
OUT PHANDLE PartitionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenPrivateNamespace(
OUT PHANDLE NamespaceHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PVOID BoundaryDescriptor);

EXTERN_C NTSTATUS Sw3NtOpenProcessToken(
IN HANDLE ProcessHandle,
IN ACCESS_MASK DesiredAccess,
OUT PHANDLE TokenHandle);

EXTERN_C NTSTATUS Sw3NtOpenRegistryTransaction(
OUT PHANDLE RegistryHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenResourceManager(
OUT PHANDLE ResourceManagerHandle,
IN ACCESS_MASK DesiredAccess,
IN HANDLE TmHandle,
IN LPGUID ResourceManagerGuid OPTIONAL,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenSemaphore(
OUT PHANDLE SemaphoreHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenSession(
OUT PHANDLE SessionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenSymbolicLinkObject(
OUT PHANDLE LinkHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenThread(
OUT PHANDLE ThreadHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN PCLIENT_ID ClientId OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenTimer(
OUT PHANDLE TimerHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes);

EXTERN_C NTSTATUS Sw3NtOpenTransaction(
OUT PHANDLE TransactionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes,
IN LPGUID Uow,
IN HANDLE TmHandle OPTIONAL);

EXTERN_C NTSTATUS Sw3NtOpenTransactionManager(
OUT PHANDLE TmHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PUNICODE_STRING LogFileName OPTIONAL,
IN LPGUID TmIdentity OPTIONAL,
IN ULONG OpenOptions OPTIONAL);

EXTERN_C NTSTATUS Sw3NtPlugPlayControl(
IN PLUGPLAY_CONTROL_CLASS PnPControlClass,
IN OUT PVOID PnPControlData,
IN ULONG PnPControlDataLength);

EXTERN_C NTSTATUS Sw3NtPrePrepareComplete(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtPrePrepareEnlistment(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtPrepareComplete(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtPrepareEnlistment(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtPrivilegeCheck(
IN HANDLE ClientToken,
IN OUT PPRIVILEGE_SET RequiredPrivileges,
OUT PBOOLEAN Result);

EXTERN_C NTSTATUS Sw3NtPrivilegeObjectAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PVOID HandleId OPTIONAL,
IN HANDLE ClientToken,
IN ACCESS_MASK DesiredAccess,
IN PPRIVILEGE_SET Privileges,
IN BOOLEAN AccessGranted);

EXTERN_C NTSTATUS Sw3NtPrivilegedServiceAuditAlarm(
IN PUNICODE_STRING SubsystemName,
IN PUNICODE_STRING ServiceName,
IN HANDLE ClientToken,
IN PPRIVILEGE_SET Privileges,
IN BOOLEAN AccessGranted);

EXTERN_C NTSTATUS Sw3NtPropagationComplete(
IN HANDLE ResourceManagerHandle,
IN ULONG RequestCookie,
IN ULONG BufferLength,
IN PVOID Buffer);

EXTERN_C NTSTATUS Sw3NtPropagationFailed(
IN HANDLE ResourceManagerHandle,
IN ULONG RequestCookie,
IN NTSTATUS PropStatus);

EXTERN_C NTSTATUS Sw3NtPulseEvent(
IN HANDLE EventHandle,
OUT PULONG PreviousState OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryAuxiliaryCounterFrequency(
OUT PULONGLONG lpAuxiliaryCounterFrequency);

EXTERN_C NTSTATUS Sw3NtQueryBootEntryOrder(
OUT PULONG Ids OPTIONAL,
IN OUT PULONG Count);

EXTERN_C NTSTATUS Sw3NtQueryBootOptions(
OUT PBOOT_OPTIONS BootOptions OPTIONAL,
IN OUT PULONG BootOptionsLength);

EXTERN_C NTSTATUS Sw3NtQueryDebugFilterState(
IN ULONG ComponentId,
IN ULONG Level);

EXTERN_C NTSTATUS Sw3NtQueryDirectoryFileEx(
IN HANDLE FileHandle,
IN HANDLE Event OPTIONAL,
IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
IN PVOID ApcContext OPTIONAL,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PVOID FileInformation,
IN ULONG Length,
IN FILE_INFORMATION_CLASS FileInformationClass,
IN ULONG QueryFlags,
IN PUNICODE_STRING FileName OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryDirectoryObject(
IN HANDLE DirectoryHandle,
OUT PVOID Buffer OPTIONAL,
IN ULONG Length,
IN BOOLEAN ReturnSingleEntry,
IN BOOLEAN RestartScan,
IN OUT PULONG Context,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryDriverEntryOrder(
IN PULONG Ids OPTIONAL,
IN OUT PULONG Count);

EXTERN_C NTSTATUS Sw3NtQueryEaFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PFILE_FULL_EA_INFORMATION Buffer,
IN ULONG Length,
IN BOOLEAN ReturnSingleEntry,
IN PFILE_GET_EA_INFORMATION EaList OPTIONAL,
IN ULONG EaListLength,
IN PULONG EaIndex OPTIONAL,
IN BOOLEAN RestartScan);

EXTERN_C NTSTATUS Sw3NtQueryFullAttributesFile(
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PFILE_NETWORK_OPEN_INFORMATION FileInformation);

EXTERN_C NTSTATUS Sw3NtQueryInformationAtom(
IN USHORT Atom,
IN ATOM_INFORMATION_CLASS AtomInformationClass,
OUT PVOID AtomInformation,
IN ULONG AtomInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationByName(
IN POBJECT_ATTRIBUTES ObjectAttributes,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PVOID FileInformation,
IN ULONG Length,
IN FILE_INFORMATION_CLASS FileInformationClass);

EXTERN_C NTSTATUS Sw3NtQueryInformationEnlistment(
IN HANDLE EnlistmentHandle,
IN ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
OUT PVOID EnlistmentInformation,
IN ULONG EnlistmentInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationJobObject(
IN HANDLE JobHandle,
IN JOBOBJECTINFOCLASS JobObjectInformationClass,
OUT PVOID JobObjectInformation,
IN ULONG JobObjectInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationPort(
IN HANDLE PortHandle,
IN PORT_INFORMATION_CLASS PortInformationClass,
OUT PVOID PortInformation,
IN ULONG Length,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationResourceManager(
IN HANDLE ResourceManagerHandle,
IN RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
OUT PVOID ResourceManagerInformation,
IN ULONG ResourceManagerInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationTransaction(
IN HANDLE TransactionHandle,
IN TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
OUT PVOID TransactionInformation,
IN ULONG TransactionInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationTransactionManager(
IN HANDLE TransactionManagerHandle,
IN TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
OUT PVOID TransactionManagerInformation,
IN ULONG TransactionManagerInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInformationWorkerFactory(
IN HANDLE WorkerFactoryHandle,
IN WORKERFACTORYINFOCLASS WorkerFactoryInformationClass,
OUT PVOID WorkerFactoryInformation,
IN ULONG WorkerFactoryInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryInstallUILanguage(
OUT PLANGID InstallUILanguageId);

EXTERN_C NTSTATUS Sw3NtQueryIntervalProfile(
IN KPROFILE_SOURCE ProfileSource,
OUT PULONG Interval);

EXTERN_C NTSTATUS Sw3NtQueryIoCompletion(
IN HANDLE IoCompletionHandle,
IN IO_COMPLETION_INFORMATION_CLASS IoCompletionInformationClass,
OUT PVOID IoCompletionInformation,
IN ULONG IoCompletionInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryLicenseValue(
IN PUNICODE_STRING ValueName,
OUT PULONG Type OPTIONAL,
OUT PVOID SystemData OPTIONAL,
IN ULONG DataSize,
OUT PULONG ResultDataSize);

EXTERN_C NTSTATUS Sw3NtQueryMultipleValueKey(
IN HANDLE KeyHandle,
IN OUT PKEY_VALUE_ENTRY ValueEntries,
IN ULONG EntryCount,
OUT PVOID ValueBuffer,
IN PULONG BufferLength,
OUT PULONG RequiredBufferLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryMutant(
IN HANDLE MutantHandle,
IN MUTANT_INFORMATION_CLASS MutantInformationClass,
OUT PVOID MutantInformation,
IN ULONG MutantInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryOpenSubKeys(
IN POBJECT_ATTRIBUTES TargetKey,
OUT PULONG HandleCount);

EXTERN_C NTSTATUS Sw3NtQueryOpenSubKeysEx(
IN POBJECT_ATTRIBUTES TargetKey,
IN ULONG BufferLength,
OUT PVOID Buffer,
OUT PULONG RequiredSize);

EXTERN_C NTSTATUS Sw3NtQueryPortInformationProcess();

EXTERN_C NTSTATUS Sw3NtQueryQuotaInformationFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
OUT PFILE_USER_QUOTA_INFORMATION Buffer,
IN ULONG Length,
IN BOOLEAN ReturnSingleEntry,
IN PFILE_QUOTA_LIST_INFORMATION SidList OPTIONAL,
IN ULONG SidListLength,
IN PSID StartSid OPTIONAL,
IN BOOLEAN RestartScan);

EXTERN_C NTSTATUS Sw3NtQuerySecurityAttributesToken(
IN HANDLE TokenHandle,
IN PUNICODE_STRING Attributes OPTIONAL,
IN ULONG NumberOfAttributes,
OUT PVOID Buffer,
IN ULONG Length,
OUT PULONG ReturnLength);

EXTERN_C NTSTATUS Sw3NtQuerySecurityObject(
IN HANDLE Handle,
IN SECURITY_INFORMATION SecurityInformation,
OUT PSECURITY_DESCRIPTOR SecurityDescriptor OPTIONAL,
IN ULONG Length,
OUT PULONG LengthNeeded);

EXTERN_C NTSTATUS Sw3NtQuerySecurityPolicy(
IN ULONG_PTR UnknownParameter1,
IN ULONG_PTR UnknownParameter2,
IN ULONG_PTR UnknownParameter3,
IN ULONG_PTR UnknownParameter4,
IN ULONG_PTR UnknownParameter5,
IN ULONG_PTR UnknownParameter6);

EXTERN_C NTSTATUS Sw3NtQuerySemaphore(
IN HANDLE SemaphoreHandle,
IN SEMAPHORE_INFORMATION_CLASS SemaphoreInformationClass,
OUT PVOID SemaphoreInformation,
IN ULONG SemaphoreInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQuerySymbolicLinkObject(
IN HANDLE LinkHandle,
IN OUT PUNICODE_STRING LinkTarget,
OUT PULONG ReturnedLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQuerySystemEnvironmentValue(
IN PUNICODE_STRING VariableName,
OUT PVOID VariableValue,
IN ULONG ValueLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQuerySystemEnvironmentValueEx(
IN PUNICODE_STRING VariableName,
IN LPGUID VendorGuid,
OUT PVOID Value OPTIONAL,
IN OUT PULONG ValueLength,
OUT PULONG Attributes OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQuerySystemInformationEx(
IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
IN PVOID InputBuffer,
IN ULONG InputBufferLength,
OUT PVOID SystemInformation OPTIONAL,
IN ULONG SystemInformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtQueryTimerResolution(
OUT PULONG MaximumTime,
OUT PULONG MinimumTime,
OUT PULONG CurrentTime);

EXTERN_C NTSTATUS Sw3NtQueryWnfStateData(
IN PCWNF_STATE_NAME StateName,
IN PCWNF_TYPE_ID TypeId OPTIONAL,
IN PVOID ExplicitScope OPTIONAL,
OUT PWNF_CHANGE_STAMP ChangeStamp,
OUT PVOID Buffer OPTIONAL,
IN OUT PULONG BufferSize);

EXTERN_C NTSTATUS Sw3NtQueryWnfStateNameInformation(
IN PCWNF_STATE_NAME StateName,
IN PCWNF_TYPE_ID NameInfoClass,
IN PVOID ExplicitScope OPTIONAL,
OUT PVOID InfoBuffer,
IN ULONG InfoBufferSize);

EXTERN_C NTSTATUS Sw3NtQueueApcThreadEx(
IN HANDLE ThreadHandle,
IN HANDLE UserApcReserveHandle OPTIONAL,
IN PKNORMAL_ROUTINE ApcRoutine,
IN PVOID ApcArgument1 OPTIONAL,
IN PVOID ApcArgument2 OPTIONAL,
IN PVOID ApcArgument3 OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRaiseException(
IN PEXCEPTION_RECORD ExceptionRecord,
IN PCONTEXT ContextRecord,
IN BOOLEAN FirstChance);

EXTERN_C NTSTATUS Sw3NtRaiseHardError(
IN NTSTATUS ErrorStatus,
IN ULONG NumberOfParameters,
IN ULONG UnicodeStringParameterMask,
IN PULONG_PTR Parameters,
IN ULONG ValidResponseOptions,
OUT PULONG Response);

EXTERN_C NTSTATUS Sw3NtReadOnlyEnlistment(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRecoverEnlistment(
IN HANDLE EnlistmentHandle,
IN PVOID EnlistmentKey OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRecoverResourceManager(
IN HANDLE ResourceManagerHandle);

EXTERN_C NTSTATUS Sw3NtRecoverTransactionManager(
IN HANDLE TransactionManagerHandle);

EXTERN_C NTSTATUS Sw3NtRegisterProtocolAddressInformation(
IN HANDLE ResourceManager,
IN LPGUID ProtocolId,
IN ULONG ProtocolInformationSize,
IN PVOID ProtocolInformation,
IN ULONG CreateOptions OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRegisterThreadTerminatePort(
IN HANDLE PortHandle);

EXTERN_C NTSTATUS Sw3NtReleaseKeyedEvent(
IN HANDLE KeyedEventHandle,
IN PVOID KeyValue,
IN BOOLEAN Alertable,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtReleaseWorkerFactoryWorker(
IN HANDLE WorkerFactoryHandle);

EXTERN_C NTSTATUS Sw3NtRemoveIoCompletionEx(
IN HANDLE IoCompletionHandle,
OUT PFILE_IO_COMPLETION_INFORMATION IoCompletionInformation,
IN ULONG Count,
OUT PULONG NumEntriesRemoved,
IN PLARGE_INTEGER Timeout OPTIONAL,
IN BOOLEAN Alertable);

EXTERN_C NTSTATUS Sw3NtRemoveProcessDebug(
IN HANDLE ProcessHandle,
IN HANDLE DebugObjectHandle);

EXTERN_C NTSTATUS Sw3NtRenameKey(
IN HANDLE KeyHandle,
IN PUNICODE_STRING NewName);

EXTERN_C NTSTATUS Sw3NtRenameTransactionManager(
IN PUNICODE_STRING LogFileName,
IN LPGUID ExistingTransactionManagerGuid);

EXTERN_C NTSTATUS Sw3NtReplaceKey(
IN POBJECT_ATTRIBUTES NewFile,
IN HANDLE TargetHandle,
IN POBJECT_ATTRIBUTES OldFile);

EXTERN_C NTSTATUS Sw3NtReplacePartitionUnit(
IN PUNICODE_STRING TargetInstancePath,
IN PUNICODE_STRING SpareInstancePath,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtReplyWaitReplyPort(
IN HANDLE PortHandle,
IN OUT PPORT_MESSAGE ReplyMessage);

EXTERN_C NTSTATUS Sw3NtRequestPort(
IN HANDLE PortHandle,
IN PPORT_MESSAGE RequestMessage);

EXTERN_C NTSTATUS Sw3NtResetEvent(
IN HANDLE EventHandle,
OUT PULONG PreviousState OPTIONAL);

EXTERN_C NTSTATUS Sw3NtResetWriteWatch(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress,
IN ULONG RegionSize);

EXTERN_C NTSTATUS Sw3NtRestoreKey(
IN HANDLE KeyHandle,
IN HANDLE FileHandle,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtResumeProcess(
IN HANDLE ProcessHandle);

EXTERN_C NTSTATUS Sw3NtRevertContainerImpersonation();

EXTERN_C NTSTATUS Sw3NtRollbackComplete(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRollbackEnlistment(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtRollbackRegistryTransaction(
IN HANDLE RegistryHandle,
IN BOOL Wait);

EXTERN_C NTSTATUS Sw3NtRollbackTransaction(
IN HANDLE TransactionHandle,
IN BOOLEAN Wait);

EXTERN_C NTSTATUS Sw3NtRollforwardTransactionManager(
IN HANDLE TransactionManagerHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSaveKey(
IN HANDLE KeyHandle,
IN HANDLE FileHandle);

EXTERN_C NTSTATUS Sw3NtSaveKeyEx(
IN HANDLE KeyHandle,
IN HANDLE FileHandle,
IN ULONG Format);

EXTERN_C NTSTATUS Sw3NtSaveMergedKeys(
IN HANDLE HighPrecedenceKeyHandle,
IN HANDLE LowPrecedenceKeyHandle,
IN HANDLE FileHandle);

EXTERN_C NTSTATUS Sw3NtSecureConnectPort(
OUT PHANDLE PortHandle,
IN PUNICODE_STRING PortName,
IN PSECURITY_QUALITY_OF_SERVICE SecurityQos,
IN OUT PPORT_SECTION_WRITE ClientView OPTIONAL,
IN PSID RequiredServerSid OPTIONAL,
IN OUT PPORT_SECTION_READ ServerView OPTIONAL,
OUT PULONG MaxMessageLength OPTIONAL,
IN OUT PVOID ConnectionInformation OPTIONAL,
IN OUT PULONG ConnectionInformationLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSerializeBoot();

EXTERN_C NTSTATUS Sw3NtSetBootEntryOrder(
IN PULONG Ids,
IN ULONG Count);

EXTERN_C NTSTATUS Sw3NtSetBootOptions(
IN PBOOT_OPTIONS BootOptions,
IN ULONG FieldsToChange);

EXTERN_C NTSTATUS Sw3NtSetCachedSigningLevel(
IN ULONG Flags,
IN SE_SIGNING_LEVEL InputSigningLevel,
IN PHANDLE SourceFiles,
IN ULONG SourceFileCount,
IN HANDLE TargetFile OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetCachedSigningLevel2(
IN ULONG Flags,
IN ULONG InputSigningLevel,
IN PHANDLE SourceFiles,
IN ULONG SourceFileCount,
IN HANDLE TargetFile OPTIONAL,
IN PVOID LevelInformation OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetContextThread(
IN HANDLE ThreadHandle,
IN PCONTEXT Context);

EXTERN_C NTSTATUS Sw3NtSetDebugFilterState(
IN ULONG ComponentId,
IN ULONG Level,
IN BOOLEAN State);

EXTERN_C NTSTATUS Sw3NtSetDefaultHardErrorPort(
IN HANDLE PortHandle);

EXTERN_C NTSTATUS Sw3NtSetDefaultLocale(
IN BOOLEAN UserProfile,
IN LCID DefaultLocaleId);

EXTERN_C NTSTATUS Sw3NtSetDefaultUILanguage(
IN LANGID DefaultUILanguageId);

EXTERN_C NTSTATUS Sw3NtSetDriverEntryOrder(
IN PULONG Ids,
IN PULONG Count);

EXTERN_C NTSTATUS Sw3NtSetEaFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PFILE_FULL_EA_INFORMATION EaBuffer,
IN ULONG EaBufferSize);

EXTERN_C NTSTATUS Sw3NtSetHighEventPair(
IN HANDLE EventPairHandle);

EXTERN_C NTSTATUS Sw3NtSetHighWaitLowEventPair(
IN HANDLE EventPairHandle);

EXTERN_C NTSTATUS Sw3NtSetIRTimer(
IN HANDLE TimerHandle,
IN PLARGE_INTEGER DueTime OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetInformationDebugObject(
IN HANDLE DebugObject,
IN DEBUGOBJECTINFOCLASS InformationClass,
IN PVOID Information,
IN ULONG InformationLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetInformationEnlistment(
IN HANDLE EnlistmentHandle,
IN ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
IN PVOID EnlistmentInformation,
IN ULONG EnlistmentInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationJobObject(
IN HANDLE JobHandle,
IN JOBOBJECTINFOCLASS JobObjectInformationClass,
IN PVOID JobObjectInformation,
IN ULONG JobObjectInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationKey(
IN HANDLE KeyHandle,
IN KEY_SET_INFORMATION_CLASS KeySetInformationClass,
IN PVOID KeySetInformation,
IN ULONG KeySetInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationResourceManager(
IN HANDLE ResourceManagerHandle,
IN RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
IN PVOID ResourceManagerInformation,
IN ULONG ResourceManagerInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationSymbolicLink(
IN HANDLE Handle,
IN ULONG Class,
IN PVOID Buffer,
IN ULONG BufferLength);

EXTERN_C NTSTATUS Sw3NtSetInformationToken(
IN HANDLE TokenHandle,
IN TOKEN_INFORMATION_CLASS TokenInformationClass,
IN PVOID TokenInformation,
IN ULONG TokenInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationTransaction(
IN HANDLE TransactionHandle,
IN TRANSACTIONMANAGER_INFORMATION_CLASS TransactionInformationClass,
IN PVOID TransactionInformation,
IN ULONG TransactionInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationTransactionManager(
IN HANDLE TransactionHandle,
IN TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
IN PVOID TransactionInformation,
IN ULONG TransactionInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationVirtualMemory(
IN HANDLE ProcessHandle,
IN VIRTUAL_MEMORY_INFORMATION_CLASS VmInformationClass,
IN ULONG_PTR NumberOfEntries,
IN PMEMORY_RANGE_ENTRY VirtualAddresses,
IN PVOID VmInformation,
IN ULONG VmInformationLength);

EXTERN_C NTSTATUS Sw3NtSetInformationWorkerFactory(
IN HANDLE WorkerFactoryHandle,
IN WORKERFACTORYINFOCLASS WorkerFactoryInformationClass,
IN PVOID WorkerFactoryInformation,
IN ULONG WorkerFactoryInformationLength);

EXTERN_C NTSTATUS Sw3NtSetIntervalProfile(
IN ULONG Interval,
IN KPROFILE_SOURCE Source);

EXTERN_C NTSTATUS Sw3NtSetIoCompletion(
IN HANDLE IoCompletionHandle,
IN ULONG CompletionKey,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN NTSTATUS CompletionStatus,
IN ULONG NumberOfBytesTransfered);

EXTERN_C NTSTATUS Sw3NtSetIoCompletionEx(
IN HANDLE IoCompletionHandle,
IN HANDLE IoCompletionPacketHandle,
IN PVOID KeyContext OPTIONAL,
IN PVOID ApcContext OPTIONAL,
IN NTSTATUS IoStatus,
IN ULONG_PTR IoStatusInformation);

EXTERN_C NTSTATUS Sw3NtSetLdtEntries(
IN ULONG Selector0,
IN ULONG Entry0Low,
IN ULONG Entry0Hi,
IN ULONG Selector1,
IN ULONG Entry1Low,
IN ULONG Entry1Hi);

EXTERN_C NTSTATUS Sw3NtSetLowEventPair(
IN HANDLE EventPairHandle);

EXTERN_C NTSTATUS Sw3NtSetLowWaitHighEventPair(
IN HANDLE EventPairHandle);

EXTERN_C NTSTATUS Sw3NtSetQuotaInformationFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PFILE_USER_QUOTA_INFORMATION Buffer,
IN ULONG Length);

EXTERN_C NTSTATUS Sw3NtSetSecurityObject(
IN HANDLE ObjectHandle,
IN SECURITY_INFORMATION SecurityInformationClass,
IN PSECURITY_DESCRIPTOR DescriptorBuffer);

EXTERN_C NTSTATUS Sw3NtSetSystemEnvironmentValue(
IN PUNICODE_STRING VariableName,
IN PUNICODE_STRING Value);

EXTERN_C NTSTATUS Sw3NtSetSystemEnvironmentValueEx(
IN PUNICODE_STRING VariableName,
IN LPGUID VendorGuid,
IN PVOID Value OPTIONAL,
IN ULONG ValueLength,
IN ULONG Attributes);

EXTERN_C NTSTATUS Sw3NtSetSystemInformation(
IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
IN PVOID SystemInformation,
IN ULONG SystemInformationLength);

EXTERN_C NTSTATUS Sw3NtSetSystemPowerState(
IN POWER_ACTION SystemAction,
IN SYSTEM_POWER_STATE MinSystemState,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtSetSystemTime(
IN PLARGE_INTEGER SystemTime,
OUT PLARGE_INTEGER PreviousTime OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSetThreadExecutionState(
IN EXECUTION_STATE ExecutionState,
OUT PEXECUTION_STATE PreviousExecutionState);

EXTERN_C NTSTATUS Sw3NtSetTimer2(
IN HANDLE TimerHandle,
IN PLARGE_INTEGER DueTime,
IN PLARGE_INTEGER Period OPTIONAL,
IN PT2_SET_PARAMETERS Parameters);

EXTERN_C NTSTATUS Sw3NtSetTimerEx(
IN HANDLE TimerHandle,
IN TIMER_SET_INFORMATION_CLASS TimerSetInformationClass,
IN OUT PVOID TimerSetInformation OPTIONAL,
IN ULONG TimerSetInformationLength);

EXTERN_C NTSTATUS Sw3NtSetTimerResolution(
IN ULONG DesiredResolution,
IN BOOLEAN SetResolution,
OUT PULONG CurrentResolution);

EXTERN_C NTSTATUS Sw3NtSetUuidSeed(
IN PUCHAR Seed);

EXTERN_C NTSTATUS Sw3NtSetVolumeInformationFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PVOID FileSystemInformation,
IN ULONG Length,
IN FSINFOCLASS FileSystemInformationClass);

EXTERN_C NTSTATUS Sw3NtSetWnfProcessNotificationEvent(
IN HANDLE NotificationEvent);

EXTERN_C NTSTATUS Sw3NtShutdownSystem(
IN SHUTDOWN_ACTION Action);

EXTERN_C NTSTATUS Sw3NtShutdownWorkerFactory(
IN HANDLE WorkerFactoryHandle,
IN OUT PLONG PendingWorkerCount);

EXTERN_C NTSTATUS Sw3NtSignalAndWaitForSingleObject(
IN HANDLE hObjectToSignal,
IN HANDLE hObjectToWaitOn,
IN BOOLEAN bAlertable,
IN PLARGE_INTEGER dwMilliseconds OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSinglePhaseReject(
IN HANDLE EnlistmentHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtStartProfile(
IN HANDLE ProfileHandle);

EXTERN_C NTSTATUS Sw3NtStopProfile(
IN HANDLE ProfileHandle);

EXTERN_C NTSTATUS Sw3NtSubscribeWnfStateChange(
IN PCWNF_STATE_NAME StateName,
IN WNF_CHANGE_STAMP ChangeStamp OPTIONAL,
IN ULONG EventMask,
OUT PLARGE_INTEGER SubscriptionId OPTIONAL);

EXTERN_C NTSTATUS Sw3NtSuspendProcess(
IN HANDLE ProcessHandle);

EXTERN_C NTSTATUS Sw3NtSuspendThread(
IN HANDLE ThreadHandle,
OUT PULONG PreviousSuspendCount);

EXTERN_C NTSTATUS Sw3NtSystemDebugControl(
IN DEBUG_CONTROL_CODE Command,
IN PVOID InputBuffer OPTIONAL,
IN ULONG InputBufferLength,
OUT PVOID OutputBuffer OPTIONAL,
IN ULONG OutputBufferLength,
OUT PULONG ReturnLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtTerminateEnclave(
IN PVOID BaseAddress,
IN BOOLEAN WaitForThread);

EXTERN_C NTSTATUS Sw3NtTerminateJobObject(
IN HANDLE JobHandle,
IN NTSTATUS ExitStatus);

EXTERN_C NTSTATUS Sw3NtTestAlert();

EXTERN_C NTSTATUS Sw3NtThawRegistry();

EXTERN_C NTSTATUS Sw3NtThawTransactions();

EXTERN_C NTSTATUS Sw3NtTraceControl(
IN ULONG FunctionCode,
IN PVOID InputBuffer OPTIONAL,
IN ULONG InputBufferLength,
OUT PVOID OutputBuffer OPTIONAL,
IN ULONG OutputBufferLength,
OUT PULONG ReturnLength);

EXTERN_C NTSTATUS Sw3NtTranslateFilePath(
IN PFILE_PATH InputFilePath,
IN ULONG OutputType,
OUT PFILE_PATH OutputFilePath OPTIONAL,
IN OUT PULONG OutputFilePathLength OPTIONAL);

EXTERN_C NTSTATUS Sw3NtUmsThreadYield(
IN PVOID SchedulerParam);

EXTERN_C NTSTATUS Sw3NtUnloadDriver(
IN PUNICODE_STRING DriverServiceName);

EXTERN_C NTSTATUS Sw3NtUnloadKey(
IN POBJECT_ATTRIBUTES DestinationKeyName);

EXTERN_C NTSTATUS Sw3NtUnloadKey2(
IN POBJECT_ATTRIBUTES TargetKey,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtUnloadKeyEx(
IN POBJECT_ATTRIBUTES TargetKey,
IN HANDLE Event OPTIONAL);

EXTERN_C NTSTATUS Sw3NtUnlockFile(
IN HANDLE FileHandle,
OUT PIO_STATUS_BLOCK IoStatusBlock,
IN PULARGE_INTEGER ByteOffset,
IN PULARGE_INTEGER Length,
IN ULONG Key);

EXTERN_C NTSTATUS Sw3NtUnlockVirtualMemory(
IN HANDLE ProcessHandle,
IN PVOID * BaseAddress,
IN PSIZE_T NumberOfBytesToUnlock,
IN ULONG LockType);

EXTERN_C NTSTATUS Sw3NtUnmapViewOfSectionEx(
IN HANDLE ProcessHandle,
IN PVOID BaseAddress OPTIONAL,
IN ULONG Flags);

EXTERN_C NTSTATUS Sw3NtUnsubscribeWnfStateChange(
IN PCWNF_STATE_NAME StateName);

EXTERN_C NTSTATUS Sw3NtUpdateWnfStateData(
IN PCWNF_STATE_NAME StateName,
IN PVOID Buffer OPTIONAL,
IN ULONG Length OPTIONAL,
IN PCWNF_TYPE_ID TypeId OPTIONAL,
IN PVOID ExplicitScope OPTIONAL,
IN WNF_CHANGE_STAMP MatchingChangeStamp,
IN ULONG CheckStamp);

EXTERN_C NTSTATUS Sw3NtVdmControl(
IN VDMSERVICECLASS Service,
IN OUT PVOID ServiceData);

EXTERN_C NTSTATUS Sw3NtWaitForAlertByThreadId(
IN HANDLE Handle,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtWaitForDebugEvent(
IN HANDLE DebugObjectHandle,
IN BOOLEAN Alertable,
IN PLARGE_INTEGER Timeout OPTIONAL,
OUT PVOID WaitStateChange);

EXTERN_C NTSTATUS Sw3NtWaitForKeyedEvent(
IN HANDLE KeyedEventHandle,
IN PVOID Key,
IN BOOLEAN Alertable,
IN PLARGE_INTEGER Timeout OPTIONAL);

EXTERN_C NTSTATUS Sw3NtWaitForWorkViaWorkerFactory(
IN HANDLE WorkerFactoryHandle,
OUT PVOID MiniPacket);

EXTERN_C NTSTATUS Sw3NtWaitHighEventPair(
IN HANDLE EventHandle);

EXTERN_C NTSTATUS Sw3NtWaitLowEventPair(
IN HANDLE EventHandle);

EXTERN_C NTSTATUS Sw3NtAcquireCMFViewOwnership(
OUT BOOLEAN TimeStamp,
OUT BOOLEAN TokenTaken,
IN BOOLEAN ReplaceExisting);

EXTERN_C NTSTATUS Sw3NtCancelDeviceWakeupRequest(
IN HANDLE DeviceHandle);

EXTERN_C NTSTATUS Sw3NtClearAllSavepointsTransaction(
IN HANDLE TransactionHandle);

EXTERN_C NTSTATUS Sw3NtClearSavepointTransaction(
IN HANDLE TransactionHandle,
IN ULONG SavePointId);

EXTERN_C NTSTATUS Sw3NtRollbackSavepointTransaction(
IN HANDLE TransactionHandle,
IN ULONG SavePointId);

EXTERN_C NTSTATUS Sw3NtSavepointTransaction(
IN HANDLE TransactionHandle,
IN BOOLEAN Flag,
OUT ULONG SavePointId);

EXTERN_C NTSTATUS Sw3NtSavepointComplete(
IN HANDLE TransactionHandle,
IN PLARGE_INTEGER TmVirtualClock OPTIONAL);

EXTERN_C NTSTATUS Sw3NtCreateSectionEx(
OUT PHANDLE SectionHandle,
IN ACCESS_MASK DesiredAccess,
IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
IN PLARGE_INTEGER MaximumSize OPTIONAL,
IN ULONG SectionPageProtection,
IN ULONG AllocationAttributes,
IN HANDLE FileHandle OPTIONAL,
IN PMEM_EXTENDED_PARAMETER ExtendedParameters,
IN ULONG ExtendedParametersCount);

EXTERN_C NTSTATUS Sw3NtCreateCrossVmEvent();

EXTERN_C NTSTATUS Sw3NtGetPlugPlayEvent(
IN HANDLE EventHandle,
IN PVOID Context OPTIONAL,
OUT PPLUGPLAY_EVENT_BLOCK EventBlock,
IN ULONG EventBufferSize);

EXTERN_C NTSTATUS Sw3NtListTransactions();

EXTERN_C NTSTATUS Sw3NtMarshallTransaction();

EXTERN_C NTSTATUS Sw3NtPullTransaction();

EXTERN_C NTSTATUS Sw3NtReleaseCMFViewOwnership();

EXTERN_C NTSTATUS Sw3NtWaitForWnfNotifications();

EXTERN_C NTSTATUS Sw3NtStartTm();

EXTERN_C NTSTATUS Sw3NtSetInformationProcess(
IN HANDLE DeviceHandle,
IN PROCESSINFOCLASS ProcessInformationClass,
IN PVOID ProcessInformation,
IN ULONG Length);

EXTERN_C NTSTATUS Sw3NtRequestDeviceWakeup(
IN HANDLE DeviceHandle);

EXTERN_C NTSTATUS Sw3NtRequestWakeupLatency(
IN ULONG LatencyTime);

EXTERN_C NTSTATUS Sw3NtQuerySystemTime(
OUT PLARGE_INTEGER SystemTime);

EXTERN_C NTSTATUS Sw3NtManageHotPatch(
IN ULONG UnknownParameter1,
IN ULONG UnknownParameter2,
IN ULONG UnknownParameter3,
IN ULONG UnknownParameter4);

EXTERN_C NTSTATUS Sw3NtContinueEx(
IN PCONTEXT ContextRecord,
IN PKCONTINUE_ARGUMENT ContinueArgument);

#endif



//#define DEBUG

#define JUMPER

#ifdef _M_IX86

EXTERN_C PVOID internal_cleancall_wow64_gate(VOID) {
    return (PVOID)__readfsdword(0xC0);
}

__declspec(naked) BOOL local_is_wow64(void)
{
    __asm {
        mov eax, fs:[0xc0]
        test eax, eax
        jne wow64
        mov eax, 0
        ret
        wow64:
        mov eax, 1
        ret
    }
}


#endif

// Code below is adapted from @modexpblog. Read linked article for more details.
// https://www.mdsec.co.uk/2020/12/bypassing-user-mode-hooks-and-direct-invocation-of-system-calls-for-red-teams

SW3_SYSCALL_LIST SW3_SyscallList;

// SEARCH_AND_REPLACE
#ifdef SEARCH_AND_REPLACE
// THIS IS NOT DEFINED HERE; don't know if I'll add it in a future release
EXTERN void SearchAndReplace(unsigned char[], unsigned char[]);
#endif

DWORD SW3_HashSyscall(PCSTR FunctionName)
{
    DWORD i = 0;
    DWORD Hash = SW3_SEED;

    while (FunctionName[i])
    {
        WORD PartialName = *(WORD*)((ULONG_PTR)FunctionName + i++);
        Hash ^= PartialName + SW3_ROR8(Hash);
    }

    return Hash;
}

#ifndef JUMPER
PVOID SC_Address(PVOID NtApiAddress)
{
    return NULL;
}
#else
PVOID SC_Address(PVOID NtApiAddress)
{
    DWORD searchLimit = 512;
    PVOID SyscallAddress;

   #ifdef _WIN64
    // If the process is 64-bit on a 64-bit OS, we need to search for syscall
    BYTE syscall_code[] = { 0x0f, 0x05, 0xc3 };
    ULONG distance_to_syscall = 0x12;
   #else
    // If the process is 32-bit on a 32-bit OS, we need to search for sysenter
    BYTE syscall_code[] = { 0x0f, 0x34, 0xc3 };
    ULONG distance_to_syscall = 0x0f;
   #endif

  #ifdef _M_IX86
    // If the process is 32-bit on a 64-bit OS, we need to jump to WOW32Reserved
    if (local_is_wow64())
    {
    #ifdef DEBUG
        // printf("[+] Running 32-bit app on x64 (WOW64)\n");
    #endif
        return NULL;
    }
  #endif

    // we don't really care if there is a 'jmp' between
    // NtApiAddress and the 'syscall; ret' instructions
    SyscallAddress = SW3_RVA2VA(PVOID, NtApiAddress, distance_to_syscall);

    int match = 1; // Assume a match initially
    for (size_t i = 0; i < sizeof(syscall_code); i++) {
        if (((BYTE*)syscall_code)[i] != ((BYTE*)SyscallAddress)[i]) {
            match = 0; // Set match to 0 if any byte doesn't match
            break;
        }
    }
    
    if (match) {
        // we can use the original code for this system call :)
        #if defined(DEBUG)
            // printf("Found Syscall Opcodes at address 0x%p\n", SyscallAddress);
        #endif
        return SyscallAddress;
    }

    // the 'syscall; ret' intructions have not been found,
    // we will try to use one near it, similarly to HalosGate

    for (ULONG32 num_jumps = 1; num_jumps < searchLimit; num_jumps++)
    {
        // let's try with an Nt* API below our syscall
        SyscallAddress = SW3_RVA2VA(
            PVOID,
            NtApiAddress,
            distance_to_syscall + num_jumps * 0x20);
        match = 1; // Assume a match initially
        for (size_t i = 0; i < sizeof(syscall_code); i++) {
            if (((BYTE*)syscall_code)[i] != ((BYTE*)SyscallAddress)[i]) {
                match = 0; // Set match to 0 if any byte doesn't match
                break;
            }
        }
        
        if (match) {
            // we can use the original code for this system call :)
            #if defined(DEBUG)
                // printf("Found Syscall Opcodes at address 0x%p\n", SyscallAddress);
            #endif
            return SyscallAddress;
        }

        // let's try with an Nt* API above our syscall
        SyscallAddress = SW3_RVA2VA(
            PVOID,
            NtApiAddress,
            distance_to_syscall - num_jumps * 0x20);
        
        match = 1; // Assume a match initially
        for (size_t i = 0; i < sizeof(syscall_code); i++) {
            if (((BYTE*)syscall_code)[i] != ((BYTE*)SyscallAddress)[i]) {
                match = 0; // Set match to 0 if any byte doesn't match
                break;
            }
        }

        if (match) {
            // we can use the original code for this system call :)
            #if defined(DEBUG)
                // printf("Found Syscall Opcodes at address 0x%p\n", SyscallAddress);
            #endif
            return SyscallAddress;
        }
    }

#ifdef DEBUG
    // printf("Syscall Opcodes not found!\n");
#endif

    return NULL;
}
#endif


BOOL SW3_PopulateSyscallList()
{
    // Return early if the list is already populated.
    if (SW3_SyscallList.Count) return TRUE;

    #ifdef _WIN64
    PSW3_PEB Peb = (PSW3_PEB)__readgsqword(0x60);
    #else
    PSW3_PEB Peb = (PSW3_PEB)__readfsdword(0x30);
    #endif
    PSW3_PEB_LDR_DATA Ldr = Peb->Ldr;
    PIMAGE_EXPORT_DIRECTORY ExportDirectory = NULL;
    PVOID DllBase = NULL;

    // Get the DllBase address of NTDLL.dll. NTDLL is not guaranteed to be the second
    // in the list, so it's safer to loop through the full list and find it.
    PSW3_LDR_DATA_TABLE_ENTRY LdrEntry;
    for (LdrEntry = (PSW3_LDR_DATA_TABLE_ENTRY)Ldr->Reserved2[1]; LdrEntry->DllBase != NULL; LdrEntry = (PSW3_LDR_DATA_TABLE_ENTRY)LdrEntry->Reserved1[0])
    {
        DllBase = LdrEntry->DllBase;
        PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)DllBase;
        PIMAGE_NT_HEADERS NtHeaders = SW3_RVA2VA(PIMAGE_NT_HEADERS, DllBase, DosHeader->e_lfanew);
        PIMAGE_DATA_DIRECTORY DataDirectory = (PIMAGE_DATA_DIRECTORY)NtHeaders->OptionalHeader.DataDirectory;
        DWORD VirtualAddress = DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        if (VirtualAddress == 0) continue;

        ExportDirectory = (PIMAGE_EXPORT_DIRECTORY)SW3_RVA2VA(ULONG_PTR, DllBase, VirtualAddress);

        // If this is NTDLL.dll, exit loop.
        PCHAR DllName = SW3_RVA2VA(PCHAR, DllBase, ExportDirectory->Name);

        if ((*(ULONG*)DllName | 0x20202020) != 0x6c64746e) continue;
        if ((*(ULONG*)(DllName + 4) | 0x20202020) == 0x6c642e6c) break;
    }

    if (!ExportDirectory) return FALSE;

    DWORD NumberOfNames = ExportDirectory->NumberOfNames;
    PDWORD Functions = SW3_RVA2VA(PDWORD, DllBase, ExportDirectory->AddressOfFunctions);
    PDWORD Names = SW3_RVA2VA(PDWORD, DllBase, ExportDirectory->AddressOfNames);
    PWORD Ordinals = SW3_RVA2VA(PWORD, DllBase, ExportDirectory->AddressOfNameOrdinals);

    // Populate SW3_SyscallList with unsorted Zw* entries.
    DWORD i = 0;
    PSW3_SYSCALL_ENTRY Entries = SW3_SyscallList.Entries;
    do
    {
        PCHAR FunctionName = SW3_RVA2VA(PCHAR, DllBase, Names[NumberOfNames - 1]);

        // Is this a system call?
        if (*(USHORT*)FunctionName == 0x775a)
        {
            Entries[i].Hash = SW3_HashSyscall(FunctionName);
            Entries[i].Address = Functions[Ordinals[NumberOfNames - 1]];
            Entries[i].SyscallAddress = SC_Address(SW3_RVA2VA(PVOID, DllBase, Entries[i].Address));

            i++;
            if (i == SW3_MAX_ENTRIES) break;
        }
    } while (--NumberOfNames);

    // Save total number of system calls found.
    SW3_SyscallList.Count = i;

    // Sort the list by address in ascending order.
    for (DWORD i = 0; i < SW3_SyscallList.Count - 1; i++)
    {
        for (DWORD j = 0; j < SW3_SyscallList.Count - i - 1; j++)
        {
            if (Entries[j].Address > Entries[j + 1].Address)
            {
                // Swap entries.
                SW3_SYSCALL_ENTRY TempEntry;

                TempEntry.Hash = Entries[j].Hash;
                TempEntry.Address = Entries[j].Address;
                TempEntry.SyscallAddress = Entries[j].SyscallAddress;

                Entries[j].Hash = Entries[j + 1].Hash;
                Entries[j].Address = Entries[j + 1].Address;
                Entries[j].SyscallAddress = Entries[j + 1].SyscallAddress;

                Entries[j + 1].Hash = TempEntry.Hash;
                Entries[j + 1].Address = TempEntry.Address;
                Entries[j + 1].SyscallAddress = TempEntry.SyscallAddress;
            }
        }
    }

    return TRUE;
}

EXTERN_C DWORD SW3_GetSyscallNumber(DWORD FunctionHash)
{
    // Ensure SW3_SyscallList is populated.
    if (!SW3_PopulateSyscallList()) return -1;

    for (DWORD i = 0; i < SW3_SyscallList.Count; i++)
    {
        if (FunctionHash == SW3_SyscallList.Entries[i].Hash)
        {
            return i;
        }
    }

    return -1;
}

EXTERN_C PVOID SW3_GetSyscallAddress(DWORD FunctionHash)
{
    // Ensure SW3_SyscallList is populated.
    if (!SW3_PopulateSyscallList()) return NULL;

    for (DWORD i = 0; i < SW3_SyscallList.Count; i++)
    {
        if (FunctionHash == SW3_SyscallList.Entries[i].Hash)
        {
            return SW3_SyscallList.Entries[i].SyscallAddress;
        }
    }

    return NULL;
}

DWORD LCG() {
    static DWORD seed = 123987654;
    return (seed >> 16) & 0x7FFF; // return a pseudo-random number
}

EXTERN_C PVOID SW3_GetRandomSyscallAddress(DWORD FunctionHash)
{
    // Ensure SW3_SyscallList is populated.
    if (!SW3_PopulateSyscallList()) return NULL;

    DWORD index = LCG() % SW3_SyscallList.Count;

    while (FunctionHash == SW3_SyscallList.Entries[index].Hash){
        // Spoofing the syscall return address
        index = LCG() % SW3_SyscallList.Count;
    }
    return SW3_SyscallList.Entries[index].SyscallAddress;
}




#if _WIN64





#define Sw3ZwAccessCheck Sw3NtAccessCheck
__asm__("Sw3NtAccessCheck: \n\
mov [rsp +8], rcx \n\
mov [rsp+16], rdx \n\
mov [rsp+24], r8 \n\
mov [rsp+32], r9 \n\
sub rsp, 0x28 \n\
mov ecx, 0x0645C3E6D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0645C3E6D \n\
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
mov ecx, 0x01B4539D3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01B4539D3 \n\
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
mov ecx, 0x05AF6675E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05AF6675E \n\
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
mov ecx, 0x03FE3054B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03FE3054B \n\
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
mov ecx, 0x0E6BDEE21 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E6BDEE21 \n\
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
mov ecx, 0x01E8C3B5A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E8C3B5A \n\
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
mov ecx, 0x07EBC3A1E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07EBC3A1E \n\
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
mov ecx, 0x0D879E2DE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D879E2DE \n\
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
mov ecx, 0x068A05664 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x068A05664 \n\
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
mov ecx, 0x004AE043D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004AE043D \n\
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
mov ecx, 0x0F518D1D1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F518D1D1 \n\
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
mov ecx, 0x060F05954 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x060F05954 \n\
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
mov ecx, 0x0A1AF22B1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A1AF22B1 \n\
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
mov ecx, 0x004AD5693 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004AD5693 \n\
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
mov ecx, 0x034A51D00 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x034A51D00 \n\
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
mov ecx, 0x0AD408ACA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AD408ACA \n\
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
mov ecx, 0x0805DA001 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0805DA001 \n\
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
mov ecx, 0x0368EE134 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0368EE134 \n\
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
mov ecx, 0x0283D1D87 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0283D1D87 \n\
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
mov ecx, 0x05C1D4188 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05C1D4188 \n\
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
mov ecx, 0x0DA5AD3C0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DA5AD3C0 \n\
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
mov ecx, 0x04F254987 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04F254987 \n\
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
mov ecx, 0x0599F6838 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0599F6838 \n\
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
mov ecx, 0x0B704DAEE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B704DAEE \n\
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
mov ecx, 0x000952C00 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x000952C00 \n\
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
mov ecx, 0x00DBD2C28 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00DBD2C28 \n\
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
mov ecx, 0x0869F2B00 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0869F2B00 \n\
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
mov ecx, 0x07DE26979 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07DE26979 \n\
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
mov ecx, 0x01F29FD57 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01F29FD57 \n\
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
mov ecx, 0x00EA01626 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00EA01626 \n\
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
mov ecx, 0x0E6B0C36A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E6B0C36A \n\
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
mov ecx, 0x014C41154 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x014C41154 \n\
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
mov ecx, 0x0FFA5F536 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FFA5F536 \n\
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
mov ecx, 0x0A4F12AEB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A4F12AEB \n\
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
mov ecx, 0x001912F07 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x001912F07 \n\
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
mov ecx, 0x00356F556 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00356F556 \n\
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
mov ecx, 0x00A498760 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A498760 \n\
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
mov ecx, 0x041B95814 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x041B95814 \n\
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
mov ecx, 0x0AA3A8ABC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA3A8ABC \n\
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
mov ecx, 0x026C81C6D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x026C81C6D \n\
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
mov ecx, 0x0C6B9C824 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C6B9C824 \n\
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
mov ecx, 0x00A822813 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A822813 \n\
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
mov ecx, 0x0ABA47EF8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0ABA47EF8 \n\
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
mov ecx, 0x0CD9F2E0F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CD9F2E0F \n\
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
mov ecx, 0x090D09AA3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x090D09AA3 \n\
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
mov ecx, 0x081AD76C8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x081AD76C8 \n\
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
mov ecx, 0x0F6002B55 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F6002B55 \n\
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
mov ecx, 0x078AB4A10 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x078AB4A10 \n\
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
mov ecx, 0x06956319D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06956319D \n\
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
mov ecx, 0x0BF625D19 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BF625D19 \n\
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
mov ecx, 0x0321B6CA0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0321B6CA0 \n\
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
mov ecx, 0x081066190 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x081066190 \n\
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
mov ecx, 0x0A8339060 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A8339060 \n\
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
mov ecx, 0x09C03BC91 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09C03BC91 \n\
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
mov ecx, 0x012942E5F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x012942E5F \n\
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
mov ecx, 0x00487F1E4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00487F1E4 \n\
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
mov ecx, 0x0C0D0C846 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C0D0C846 \n\
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
mov ecx, 0x00B931303 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B931303 \n\
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
mov ecx, 0x0FABBFC2B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FABBFC2B \n\
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
mov ecx, 0x0B51C4066 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B51C4066 \n\
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
mov ecx, 0x0F874C0A6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F874C0A6 \n\
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
mov ecx, 0x0CC94EB4F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC94EB4F \n\
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
mov ecx, 0x00392EB83 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00392EB83 \n\
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
mov ecx, 0x00E4CF53A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E4CF53A \n\
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
mov ecx, 0x0859D9118 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0859D9118 \n\
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
mov ecx, 0x017813F04 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x017813F04 \n\
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
mov ecx, 0x0CA63AD9C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CA63AD9C \n\
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
mov ecx, 0x0DF4DEED1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DF4DEED1 \n\
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
mov ecx, 0x07B4F7FEF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07B4F7FEF \n\
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
mov ecx, 0x01A8C1C19 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A8C1C19 \n\
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
mov ecx, 0x0B4A151F4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B4A151F4 \n\
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
mov ecx, 0x00E912132 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E912132 \n\
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
mov ecx, 0x06CDA7C68 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06CDA7C68 \n\
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
mov ecx, 0x0726D18F5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0726D18F5 \n\
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
mov ecx, 0x0D96293B7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D96293B7 \n\
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
mov ecx, 0x07DA26D25 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07DA26D25 \n\
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
mov ecx, 0x07C730285 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07C730285 \n\
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
mov ecx, 0x08F5785EE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08F5785EE \n\
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
mov ecx, 0x0FD0D21AF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FD0D21AF \n\
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
mov ecx, 0x05DCD332B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05DCD332B \n\
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
mov ecx, 0x04C966C59 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04C966C59 \n\
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
mov ecx, 0x01EB1460D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01EB1460D \n\
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
mov ecx, 0x07AC83479 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07AC83479 \n\
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
mov ecx, 0x03A4436EB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03A4436EB \n\
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
mov ecx, 0x050D087E2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x050D087E2 \n\
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
mov ecx, 0x0EF4EF6DB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EF4EF6DB \n\
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
mov ecx, 0x0E45CD0D6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E45CD0D6 \n\
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
mov ecx, 0x099A9A71B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x099A9A71B \n\
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
mov ecx, 0x0D75FFF83 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D75FFF83 \n\
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
mov ecx, 0x00DA60D39 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00DA60D39 \n\
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
mov ecx, 0x01E993221 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E993221 \n\
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
mov ecx, 0x03673AD45 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03673AD45 \n\
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
mov ecx, 0x0312B3EB8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0312B3EB8 \n\
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
mov ecx, 0x0AA8B8C1F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA8B8C1F \n\
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
mov ecx, 0x096234B77 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x096234B77 \n\
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
mov ecx, 0x09B8C698C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09B8C698C \n\
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
mov ecx, 0x0F357F1C8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F357F1C8 \n\
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
mov ecx, 0x0F058DAC8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F058DAC8 \n\
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
mov ecx, 0x024B3243F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024B3243F \n\
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
mov ecx, 0x0FE93120C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FE93120C \n\
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
mov ecx, 0x0163A4611 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0163A4611 \n\
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
mov ecx, 0x0328ABDAE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0328ABDAE \n\
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
mov ecx, 0x0555591E9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0555591E9 \n\
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
mov ecx, 0x019950D18 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x019950D18 \n\
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
mov ecx, 0x00F931B1C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F931B1C \n\
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
mov ecx, 0x090B144F4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x090B144F4 \n\
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
mov ecx, 0x08D9F4CC2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08D9F4CC2 \n\
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
mov ecx, 0x0954CD7F2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0954CD7F2 \n\
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
mov ecx, 0x094231E0D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x094231E0D \n\
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
mov ecx, 0x00C10728A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00C10728A \n\
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
mov ecx, 0x0B58DE571 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B58DE571 \n\
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
mov ecx, 0x098B1E84D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x098B1E84D \n\
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
mov ecx, 0x009D13A5A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x009D13A5A \n\
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
mov ecx, 0x02BED6D39 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02BED6D39 \n\
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
mov ecx, 0x02E947271 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02E947271 \n\
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
mov ecx, 0x0E0B0E622 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E0B0E622 \n\
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
mov ecx, 0x01A899698 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A899698 \n\
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
mov ecx, 0x000B1033E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x000B1033E \n\
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
mov ecx, 0x0A18EC572 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A18EC572 \n\
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
mov ecx, 0x028B1A9AC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x028B1A9AC \n\
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
mov ecx, 0x024881C03 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024881C03 \n\
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
mov ecx, 0x030BDD1B7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x030BDD1B7 \n\
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
mov ecx, 0x0B42997B3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B42997B3 \n\
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
mov ecx, 0x0184C3BD4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0184C3BD4 \n\
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
mov ecx, 0x0C101C192 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C101C192 \n\
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
mov ecx, 0x00EA729EB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00EA729EB \n\
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
mov ecx, 0x00A342F8F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A342F8F \n\
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
mov ecx, 0x0EF14EC9B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EF14EC9B \n\
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
mov ecx, 0x020AEC9BC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x020AEC9BC \n\
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
mov ecx, 0x0A536829D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A536829D \n\
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
mov ecx, 0x02132DE51 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02132DE51 \n\
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
mov ecx, 0x0DD8EDB1F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DD8EDB1F \n\
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
mov ecx, 0x0655675E5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0655675E5 \n\
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
mov ecx, 0x00B8CEC99 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00B8CEC99 \n\
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
mov ecx, 0x0AA0DDF9F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA0DDF9F \n\
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
mov ecx, 0x0D60CDD94 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D60CDD94 \n\
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
mov ecx, 0x0E173D93F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E173D93F \n\
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
mov ecx, 0x00A5DE107 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A5DE107 \n\
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
mov ecx, 0x014541FF3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x014541FF3 \n\
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
mov ecx, 0x088D770DB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x088D770DB \n\
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
mov ecx, 0x00F3D69AF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F3D69AF \n\
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
mov ecx, 0x00AAA2FE0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00AAA2FE0 \n\
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
mov ecx, 0x00D365FEC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00D365FEC \n\
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
mov ecx, 0x0F16BEDD3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F16BEDD3 \n\
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
mov ecx, 0x0171797C1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0171797C1 \n\
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
mov ecx, 0x0793D77A7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0793D77A7 \n\
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
mov ecx, 0x01E6E78A2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E6E78A2 \n\
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
mov ecx, 0x0E23AE7A8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E23AE7A8 \n\
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
mov ecx, 0x0508F701D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0508F701D \n\
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
mov ecx, 0x00CAE0633 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00CAE0633 \n\
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
mov ecx, 0x039A72E20 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x039A72E20 \n\
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
mov ecx, 0x07FE35B6D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07FE35B6D \n\
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
mov ecx, 0x05C833654 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05C833654 \n\
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
mov ecx, 0x096949C02 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x096949C02 \n\
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
mov ecx, 0x0A0F25D98 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A0F25D98 \n\
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
mov ecx, 0x01F0EFD55 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01F0EFD55 \n\
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
mov ecx, 0x0583059BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0583059BE \n\
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
mov ecx, 0x0FF89EE2A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FF89EE2A \n\
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
mov ecx, 0x018B1704D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018B1704D \n\
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
mov ecx, 0x03C98746F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03C98746F \n\
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
mov ecx, 0x04AF68480 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04AF68480 \n\
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
mov ecx, 0x0623FBA8C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0623FBA8C \n\
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
mov ecx, 0x008911B16 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x008911B16 \n\
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
mov ecx, 0x03CADECF3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03CADECF3 \n\
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
mov ecx, 0x0D193409F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D193409F \n\
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
mov ecx, 0x0F6EAD07F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F6EAD07F \n\
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
mov ecx, 0x036A9DE35 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x036A9DE35 \n\
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
mov ecx, 0x01E9E6E63 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E9E6E63 \n\
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
mov ecx, 0x0175D2600 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0175D2600 \n\
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
mov ecx, 0x06CAD176A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06CAD176A \n\
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
mov ecx, 0x0E3A711E4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E3A711E4 \n\
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
mov ecx, 0x0C8D9D96F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C8D9D96F \n\
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
mov ecx, 0x032B03B24 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x032B03B24 \n\
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
mov ecx, 0x042F85040 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x042F85040 \n\
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
mov ecx, 0x0DD7CF5F9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DD7CF5F9 \n\
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
mov ecx, 0x0F4AC12F9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F4AC12F9 \n\
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
mov ecx, 0x01AB723FA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01AB723FA \n\
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
mov ecx, 0x0EAD5E84C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EAD5E84C \n\
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
mov ecx, 0x0D9A327D3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D9A327D3 \n\
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
mov ecx, 0x01A83DCDE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A83DCDE \n\
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
mov ecx, 0x0C65DF5E6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C65DF5E6 \n\
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
mov ecx, 0x0A8A27BE6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A8A27BE6 \n\
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
mov ecx, 0x02117EE4E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02117EE4E \n\
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
mov ecx, 0x03F5809F6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03F5809F6 \n\
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
mov ecx, 0x038A6263B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x038A6263B \n\
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
mov ecx, 0x00AB9566C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00AB9566C \n\
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
mov ecx, 0x054642466 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x054642466 \n\
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
mov ecx, 0x0323032EE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0323032EE \n\
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
mov ecx, 0x0039E0D06 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0039E0D06 \n\
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
mov ecx, 0x00C9F465C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00C9F465C \n\
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
mov ecx, 0x0A044DCAF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A044DCAF \n\
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
mov ecx, 0x02BB338D2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02BB338D2 \n\
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
mov ecx, 0x016B40539 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x016B40539 \n\
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
mov ecx, 0x0378B4F66 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0378B4F66 \n\
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
mov ecx, 0x05C8E7512 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05C8E7512 \n\
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
mov ecx, 0x0331DB507 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0331DB507 \n\
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
mov ecx, 0x0F0A1E22C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F0A1E22C \n\
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
mov ecx, 0x02D96CEF8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02D96CEF8 \n\
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
mov ecx, 0x00A96D9AA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A96D9AA \n\
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
mov ecx, 0x0DD52DCC1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DD52DCC1 \n\
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
mov ecx, 0x015840F07 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x015840F07 \n\
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
mov ecx, 0x08313978E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08313978E \n\
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
mov ecx, 0x078D9B672 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x078D9B672 \n\
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
mov ecx, 0x0FA3F0A59 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FA3F0A59 \n\
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
mov ecx, 0x02AA300FA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02AA300FA \n\
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
mov ecx, 0x00A2DCF74 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A2DCF74 \n\
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
mov ecx, 0x03AF2EA94 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03AF2EA94 \n\
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
mov ecx, 0x0328A405A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0328A405A \n\
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
mov ecx, 0x0D6903E92 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D6903E92 \n\
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
mov ecx, 0x05D4D3DCE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05D4D3DCE \n\
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
mov ecx, 0x0009C380C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0009C380C \n\
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
mov ecx, 0x0E872ABA4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E872ABA4 \n\
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
mov ecx, 0x0AE3BD8A0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AE3BD8A0 \n\
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
mov ecx, 0x00AA2D409 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00AA2D409 \n\
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
mov ecx, 0x0F4A40CC8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F4A40CC8 \n\
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
mov ecx, 0x007EA5B2E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x007EA5B2E \n\
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
mov ecx, 0x01CB02C33 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01CB02C33 \n\
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
mov ecx, 0x064CC6259 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x064CC6259 \n\
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
mov ecx, 0x01A8219EF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A8219EF \n\
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
mov ecx, 0x09DA3F7BB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09DA3F7BB \n\
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
mov ecx, 0x0E81A166C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E81A166C \n\
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
mov ecx, 0x0CAD5AE29 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CAD5AE29 \n\
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
mov ecx, 0x0085E7D83 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0085E7D83 \n\
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
mov ecx, 0x00DB34A91 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00DB34A91 \n\
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
mov ecx, 0x0F329085D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F329085D \n\
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
mov ecx, 0x064B9E7B4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x064B9E7B4 \n\
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
mov ecx, 0x001A27963 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x001A27963 \n\
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
mov ecx, 0x0039B2D4B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0039B2D4B \n\
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
mov ecx, 0x0A11D5796 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A11D5796 \n\
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
mov ecx, 0x0C2AF2CCF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C2AF2CCF \n\
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
mov ecx, 0x0C75FDFD5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C75FDFD5 \n\
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
mov ecx, 0x0337A35E7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0337A35E7 \n\
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
mov ecx, 0x0786264F7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0786264F7 \n\
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
mov ecx, 0x0B49B7132 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B49B7132 \n\
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
mov ecx, 0x0A432B490 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A432B490 \n\
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
mov ecx, 0x09CA2CE78 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09CA2CE78 \n\
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
mov ecx, 0x0B4EA64C4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B4EA64C4 \n\
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
mov ecx, 0x066F34FA9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x066F34FA9 \n\
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
mov ecx, 0x0D59F3005 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D59F3005 \n\
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
mov ecx, 0x0AB0CE5AE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AB0CE5AE \n\
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
mov ecx, 0x0FDD419BF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FDD419BF \n\
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
mov ecx, 0x00E357ACF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E357ACF \n\
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
mov ecx, 0x0E8F41C98 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E8F41C98 \n\
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
mov ecx, 0x0E6350F6F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E6350F6F \n\
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
mov ecx, 0x0E88BF52A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E88BF52A \n\
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
mov ecx, 0x040BE3DA4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x040BE3DA4 \n\
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
mov ecx, 0x079402490 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x079402490 \n\
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
mov ecx, 0x0F2B30BD2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F2B30BD2 \n\
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
mov ecx, 0x01A5DCBFE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A5DCBFE \n\
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
mov ecx, 0x032A06F1A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x032A06F1A \n\
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
mov ecx, 0x0298C1D15 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0298C1D15 \n\
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
mov ecx, 0x0E933D4ED \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E933D4ED \n\
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
mov ecx, 0x000B53818 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x000B53818 \n\
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
mov ecx, 0x0D5CB8302 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D5CB8302 \n\
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
mov ecx, 0x072412E82 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x072412E82 \n\
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
mov ecx, 0x02CFC1F47 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02CFC1F47 \n\
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
mov ecx, 0x06BD091D8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06BD091D8 \n\
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
mov ecx, 0x0B1BAFD7E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B1BAFD7E \n\
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
mov ecx, 0x01CE4081E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01CE4081E \n\
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
mov ecx, 0x001443CEA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x001443CEA \n\
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
mov ecx, 0x0138CF6F0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0138CF6F0 \n\
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
mov ecx, 0x003960F01 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x003960F01 \n\
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
mov ecx, 0x0F4DE07B2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F4DE07B2 \n\
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
mov ecx, 0x08EBCF861 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08EBCF861 \n\
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
mov ecx, 0x07AE19AB3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07AE19AB3 \n\
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
mov ecx, 0x020FEA0D8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x020FEA0D8 \n\
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
mov ecx, 0x0F64DCDC3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F64DCDC3 \n\
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
mov ecx, 0x03EA57E7C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03EA57E7C \n\
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
mov ecx, 0x005930F00 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x005930F00 \n\
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
mov ecx, 0x08202B6BF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08202B6BF \n\
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
mov ecx, 0x002980808 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x002980808 \n\
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
mov ecx, 0x00A904A49 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00A904A49 \n\
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
mov ecx, 0x0229A7541 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0229A7541 \n\
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
mov ecx, 0x0AFD6AA47 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AFD6AA47 \n\
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
mov ecx, 0x099BAB924 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x099BAB924 \n\
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
mov ecx, 0x0D156F2C1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D156F2C1 \n\
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
mov ecx, 0x03610C255 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03610C255 \n\
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
mov ecx, 0x0CC83AC51 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CC83AC51 \n\
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
mov ecx, 0x0FF40CDFE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FF40CDFE \n\
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
mov ecx, 0x0BDBAF34F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BDBAF34F \n\
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
mov ecx, 0x0B31CD3C1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B31CD3C1 \n\
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
mov ecx, 0x01EDD4C18 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01EDD4C18 \n\
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
mov ecx, 0x0FF93EE16 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FF93EE16 \n\
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
mov ecx, 0x0CA8E29D8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CA8E29D8 \n\
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
mov ecx, 0x01A940814 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A940814 \n\
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
mov ecx, 0x036ADB6BF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x036ADB6BF \n\
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
mov ecx, 0x08CB7548A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08CB7548A \n\
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
mov ecx, 0x07BD96374 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07BD96374 \n\
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
mov ecx, 0x00AE52875 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00AE52875 \n\
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
mov ecx, 0x019A68BA6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x019A68BA6 \n\
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
mov ecx, 0x04CDA11E2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04CDA11E2 \n\
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
mov ecx, 0x0CA4ED4C3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CA4ED4C3 \n\
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
mov ecx, 0x026BA0017 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x026BA0017 \n\
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
mov ecx, 0x018BF560D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018BF560D \n\
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
mov ecx, 0x0DB03F5D8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DB03F5D8 \n\
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
mov ecx, 0x00248C518 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00248C518 \n\
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
mov ecx, 0x07E22AA7F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07E22AA7F \n\
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
mov ecx, 0x0678C673B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0678C673B \n\
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
mov ecx, 0x07AE180BE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07AE180BE \n\
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
mov ecx, 0x0006AE739 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0006AE739 \n\
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
mov ecx, 0x048B5AAFA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x048B5AAFA \n\
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
mov ecx, 0x01B863831 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01B863831 \n\
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
mov ecx, 0x03AA53105 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03AA53105 \n\
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
mov ecx, 0x09E207C70 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09E207C70 \n\
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
mov ecx, 0x0F0AC1F2E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F0AC1F2E \n\
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
mov ecx, 0x034A8C0B6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x034A8C0B6 \n\
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
mov ecx, 0x03A1A38A4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03A1A38A4 \n\
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
mov ecx, 0x098D4754D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x098D4754D \n\
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
mov ecx, 0x0EB50CAFE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EB50CAFE \n\
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
mov ecx, 0x01307ED6B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01307ED6B \n\
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
mov ecx, 0x01BDB91C3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01BDB91C3 \n\
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
mov ecx, 0x0F4332E0C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F4332E0C \n\
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
mov ecx, 0x08853ECAF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08853ECAF \n\
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
mov ecx, 0x0FE50C8DD \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FE50C8DD \n\
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
mov ecx, 0x0BBAF9533 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BBAF9533 \n\
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
mov ecx, 0x0D873AE60 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D873AE60 \n\
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
mov ecx, 0x0C979FDE9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C979FDE9 \n\
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
mov ecx, 0x0D6BDD720 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D6BDD720 \n\
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
mov ecx, 0x03C8F491F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03C8F491F \n\
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
mov ecx, 0x08B5490C3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08B5490C3 \n\
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
mov ecx, 0x0813EB182 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0813EB182 \n\
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
mov ecx, 0x0C28CC302 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C28CC302 \n\
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
mov ecx, 0x0F5AB08DB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F5AB08DB \n\
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
mov ecx, 0x078E11A31 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x078E11A31 \n\
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
mov ecx, 0x009A17D28 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x009A17D28 \n\
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
mov ecx, 0x07F7005F2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07F7005F2 \n\
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
mov ecx, 0x02FB1241C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02FB1241C \n\
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
mov ecx, 0x084BC1A88 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x084BC1A88 \n\
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
mov ecx, 0x062C86257 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x062C86257 \n\
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
mov ecx, 0x0ECA708E9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0ECA708E9 \n\
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
mov ecx, 0x02EBA1109 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02EBA1109 \n\
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
mov ecx, 0x09A1BB5B8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09A1BB5B8 \n\
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
mov ecx, 0x0B5114A7E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B5114A7E \n\
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
mov ecx, 0x0616EA2D5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0616EA2D5 \n\
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
mov ecx, 0x0412B5086 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0412B5086 \n\
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
mov ecx, 0x0E96E3F53 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E96E3F53 \n\
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
mov ecx, 0x0319F0D32 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0319F0D32 \n\
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
mov ecx, 0x00827289A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00827289A \n\
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
mov ecx, 0x00215038C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00215038C \n\
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
mov ecx, 0x00E9CD9AE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E9CD9AE \n\
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
mov ecx, 0x094B873C4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x094B873C4 \n\
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
mov ecx, 0x00E9C2F18 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E9C2F18 \n\
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
mov ecx, 0x01B855130 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01B855130 \n\
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
mov ecx, 0x090921BAE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x090921BAE \n\
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
mov ecx, 0x0C44D0A11 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C44D0A11 \n\
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
mov ecx, 0x072BB40E8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x072BB40E8 \n\
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
mov ecx, 0x01F871B16 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01F871B16 \n\
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
mov ecx, 0x0BCA07195 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BCA07195 \n\
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
mov ecx, 0x00CDAC37B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00CDAC37B \n\
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
mov ecx, 0x0BB9442FE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BB9442FE \n\
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
mov ecx, 0x0486273E5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0486273E5 \n\
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
mov ecx, 0x0086F160D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0086F160D \n\
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
mov ecx, 0x067C27067 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x067C27067 \n\
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
mov ecx, 0x003B39B92 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x003B39B92 \n\
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
mov ecx, 0x0858F851D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0858F851D \n\
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
mov ecx, 0x078F082FE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x078F082FE \n\
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
mov ecx, 0x03EB51926 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03EB51926 \n\
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
mov ecx, 0x09CABCC69 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x09CABCC69 \n\
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
mov ecx, 0x0C092F228 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C092F228 \n\
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
mov ecx, 0x00060FFF6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00060FFF6 \n\
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
mov ecx, 0x0BC38A7BB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BC38A7BB \n\
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
mov ecx, 0x01E2262C8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E2262C8 \n\
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
mov ecx, 0x0C105205E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C105205E \n\
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
mov ecx, 0x01E8B120A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E8B120A \n\
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
mov ecx, 0x060F14F22 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x060F14F22 \n\
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
mov ecx, 0x05AF0475E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x05AF0475E \n\
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
mov ecx, 0x0108A7760 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0108A7760 \n\
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
mov ecx, 0x0ACA3D026 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0ACA3D026 \n\
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
mov ecx, 0x025CF1878 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x025CF1878 \n\
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
mov ecx, 0x059FB5E70 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x059FB5E70 \n\
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
mov ecx, 0x0FE64D8ED \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FE64D8ED \n\
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
mov ecx, 0x018854646 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018854646 \n\
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
mov ecx, 0x0AFB6B025 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AFB6B025 \n\
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
mov ecx, 0x0FFAFE704 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FFAFE704 \n\
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
mov ecx, 0x01E57DF04 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01E57DF04 \n\
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
mov ecx, 0x0032E1982 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0032E1982 \n\
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
mov ecx, 0x041BF6024 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x041BF6024 \n\
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
mov ecx, 0x0AB996EC5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AB996EC5 \n\
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
mov ecx, 0x0EE72E3F5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EE72E3F5 \n\
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
mov ecx, 0x0F620DC7E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F620DC7E \n\
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
mov ecx, 0x068B8164B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x068B8164B \n\
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
mov ecx, 0x00F3279B7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F3279B7 \n\
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
mov ecx, 0x04F186D8F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x04F186D8F \n\
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
mov ecx, 0x00F43F70F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00F43F70F \n\
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
mov ecx, 0x0004CE6D8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0004CE6D8 \n\
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
mov ecx, 0x0338B2F32 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0338B2F32 \n\
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
mov ecx, 0x0D48F0430 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D48F0430 \n\
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
mov ecx, 0x025B0021B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x025B0021B \n\
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
mov ecx, 0x002A0929B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x002A0929B \n\
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
mov ecx, 0x083304E1A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x083304E1A \n\
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
mov ecx, 0x0049BFB9A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0049BFB9A \n\
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
mov ecx, 0x074D0140A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x074D0140A \n\
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
mov ecx, 0x020BE5C31 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x020BE5C31 \n\
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
mov ecx, 0x0CF8EC975 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CF8EC975 \n\
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
mov ecx, 0x0A861FCA3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A861FCA3 \n\
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
mov ecx, 0x000AD2811 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x000AD2811 \n\
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
mov ecx, 0x0B922BEB9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B922BEB9 \n\
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
mov ecx, 0x024841629 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024841629 \n\
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
mov ecx, 0x0E2541428 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E2541428 \n\
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
mov ecx, 0x001510DC8 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x001510DC8 \n\
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
mov ecx, 0x022B56062 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x022B56062 \n\
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
mov ecx, 0x01FAA092A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01FAA092A \n\
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
mov ecx, 0x0628C601D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0628C601D \n\
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
mov ecx, 0x083BF6FA2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x083BF6FA2 \n\
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
mov ecx, 0x01B8B736B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01B8B736B \n\
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
mov ecx, 0x0070AEF65 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0070AEF65 \n\
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
mov ecx, 0x0D5022B59 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D5022B59 \n\
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
mov ecx, 0x056C83A13 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x056C83A13 \n\
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
mov ecx, 0x050DB1DEE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x050DB1DEE \n\
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
mov ecx, 0x06AD01B2F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06AD01B2F \n\
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
mov ecx, 0x010B04471 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010B04471 \n\
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
mov ecx, 0x089558FC2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x089558FC2 \n\
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
mov ecx, 0x0960F582C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0960F582C \n\
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
mov ecx, 0x0FC562B4A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FC562B4A \n\
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
mov ecx, 0x0851AF0F2 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0851AF0F2 \n\
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
mov ecx, 0x077E8A0B7 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x077E8A0B7 \n\
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
mov ecx, 0x01A4A1CDF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01A4A1CDF \n\
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
mov ecx, 0x032119E5F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x032119E5F \n\
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
mov ecx, 0x0AA3EA39B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0AA3EA39B \n\
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
mov ecx, 0x004BA7256 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004BA7256 \n\
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
mov ecx, 0x03BA4D809 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x03BA4D809 \n\
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
mov ecx, 0x0F29FC82D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0F29FC82D \n\
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
mov ecx, 0x0D7B1DB2B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D7B1DB2B \n\
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
mov ecx, 0x009955728 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x009955728 \n\
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
mov ecx, 0x0E2BABC79 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E2BABC79 \n\
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
mov ecx, 0x0D73FDEBB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D73FDEBB \n\
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
mov ecx, 0x0389160BC \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0389160BC \n\
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
mov ecx, 0x0CCA2C85F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CCA2C85F \n\
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
mov ecx, 0x099BDA111 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x099BDA111 \n\
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
mov ecx, 0x0E2BC03C0 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0E2BC03C0 \n\
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
mov ecx, 0x0801A473A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0801A473A \n\
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
mov ecx, 0x004930E04 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004930E04 \n\
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
mov ecx, 0x036A6D1FA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x036A6D1FA \n\
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
mov ecx, 0x0C2B9CD28 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C2B9CD28 \n\
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
mov ecx, 0x0C6694B40 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0C6694B40 \n\
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
mov ecx, 0x0FB9002C6 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FB9002C6 \n\
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
mov ecx, 0x018C6CB7A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x018C6CB7A \n\
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
mov ecx, 0x013B9C6FB \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x013B9C6FB \n\
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
mov ecx, 0x02D5738DE \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x02D5738DE \n\
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
mov ecx, 0x004C91245 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x004C91245 \n\
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
mov ecx, 0x0CA18DA90 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CA18DA90 \n\
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
mov ecx, 0x0058C255B \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0058C255B \n\
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
mov ecx, 0x0B2B05EB5 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B2B05EB5 \n\
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
mov ecx, 0x07BA62213 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07BA62213 \n\
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
mov ecx, 0x014B74E1C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x014B74E1C \n\
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
mov ecx, 0x0152E229F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0152E229F \n\
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
mov ecx, 0x08A3B7E1D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08A3B7E1D \n\
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
mov ecx, 0x0D7B1E70E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0D7B1E70E \n\
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
mov ecx, 0x069246882 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x069246882 \n\
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
mov ecx, 0x08B1B879F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x08B1B879F \n\
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
mov ecx, 0x0A29110AA \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A29110AA \n\
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
mov ecx, 0x0EFBD9C60 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EFBD9C60 \n\
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
mov ecx, 0x0A2C39053 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0A2C39053 \n\
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
mov ecx, 0x011803113 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x011803113 \n\
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
mov ecx, 0x0069695A1 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0069695A1 \n\
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
mov ecx, 0x0CEC3C958 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0CEC3C958 \n\
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
mov ecx, 0x0BA114562 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BA114562 \n\
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
mov ecx, 0x00554EE46 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00554EE46 \n\
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
mov ecx, 0x0930FB190 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0930FB190 \n\
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
mov ecx, 0x024362AA9 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x024362AA9 \n\
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
mov ecx, 0x01EC4D49E \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x01EC4D49E \n\
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
mov ecx, 0x073C11532 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x073C11532 \n\
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
mov ecx, 0x07EA619B3 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x07EA619B3 \n\
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
mov ecx, 0x010B91215 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x010B91215 \n\
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
mov ecx, 0x008972E03 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x008972E03 \n\
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
mov ecx, 0x000E8263D \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x000E8263D \n\
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
mov ecx, 0x0088BE3C4 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0088BE3C4 \n\
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
mov ecx, 0x050982464 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x050982464 \n\
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
mov ecx, 0x00E8C0718 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E8C0718 \n\
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
mov ecx, 0x030A31730 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x030A31730 \n\
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
mov ecx, 0x0EF5C724C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0EF5C724C \n\
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
mov ecx, 0x00E96505F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x00E96505F \n\
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
mov ecx, 0x0900CD4DF \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0900CD4DF \n\
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
mov ecx, 0x0DA64052A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0DA64052A \n\
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
mov ecx, 0x0BBEB6740 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0BBEB6740 \n\
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
mov ecx, 0x015997F64 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x015997F64 \n\
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
mov ecx, 0x0FD9F1A0F \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0FD9F1A0F \n\
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
mov ecx, 0x015D6194A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x015D6194A \n\
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
mov ecx, 0x0868C9D1C \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0868C9D1C \n\
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
mov ecx, 0x0B020A793 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x0B020A793 \n\
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
mov ecx, 0x090431870 \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x090431870 \n\
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
mov ecx, 0x06FFF110A \n\
call SW3_GetSyscallAddress \n\
mov r11, rax \n\
mov ecx, 0x06FFF110A \n\
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
