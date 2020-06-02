#pragma once
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

namespace editmemory
{
	void PatchMem(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
	template <typename Type>
	Type ReadMem(HANDLE handle, BYTE* addr)
	{
		Type cRead;
		ReadProcessMemory(handle, addr, &cRead, sizeof(cRead), nullptr);
		return cRead;
	}
	void WriteMem(HANDLE handle, BYTE* addr, BYTE* data);
}

DWORD GetProcId(const wchar_t* procName);

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);

uintptr_t FindDynamicAddr(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);