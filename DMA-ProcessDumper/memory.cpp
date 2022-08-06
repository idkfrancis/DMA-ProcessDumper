#include "memory.hpp"

bool memory::init(const std::string process_name)
{
	LPCSTR szParams[] = { "", "-device", "fpga" };
	detail::hVMM = VMMDLL_Initialize(3, (LPSTR*)szParams);

	if (!detail::hVMM) {
		printf("[!] Failed to initialize memory process file system in call to vmm.dll!VMMDLL_Initialize (Error: %d)\n", GetLastError());
		return false;
	}

	printf("[>] Init handle VMM success\n");

	detail::process_name = process_name;
	detail::process_id = memory::get_process_id(process_name);

    printf("[+] Process id: %d\n", detail::process_id);

    if (!detail::process_id)
    {
        printf("[!] Failed to get process id of %s\n", process_name);
        return false;
    }

	if (!memory::get_process_base_address(process_name, detail::process_id))
	{
		printf("[+] Failed to get base address/size of process 0x%lX (Error: %d)\n", detail::process_base_address, GetLastError());
		return false;
	}

	printf("[+] Base address: 0x%llX\n", detail::process_base_address);
	printf("[+] Image size: 0x%llX\n", memory::detail::process_size);

    return true;
}