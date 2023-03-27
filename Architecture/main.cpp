#include <iostream>
#include <string_view>
#include <format>

#include <intrin.h>

#include "Arch.h"

#define Log(set) LogSet<set>(#set)

template <InstructionSet set>
void LogSet(std::string_view setName)
{
	std::cout << std::format("{:^17} | {}\n", setName, Arch::HasInstructions<set>() ? "" : "  no");
}

int main()
{
	std::cout << Arch::CPUBrand() << "\n\n";

	// ECX1 flagged
	Log(SSE3);
	Log(PCLMULQDQ);
	Log(MONITOR);
	Log(SSSE3);
	Log(FMA);
	Log(CMPXCHG16B);
	Log(SSE41);
	Log(SSE42);
	Log(MOVBE);
	Log(POPCNT);
	Log(AES);
	Log(XSAVE);
	Log(OSXSAVE);
	Log(AVX);
	Log(F16C);
	Log(RDRAND);

	// EDX1 flagged 
	Log(TSC);
	Log(MSR);
	Log(CX8);
	Log(SEP);
	Log(CMOV);
	Log(CLFSH);
	Log(MMX);
	Log(FXSR);
	Log(SSE);
	Log(SSE2);

	// EBX7 flagged 
	Log(FSGSBASE);
	Log(BMI1);
	Log(HLE);
	Log(AVX2);
	Log(BMI2);
	Log(ERMS);
	Log(INVPCID);
	Log(RTM);
	Log(AVX512F);
	Log(RDSEED);
	Log(ADX);
	Log(AVX512PF);
	Log(AVX512ER);
	Log(AVX512CD);
	Log(SHA);

	// ECX7 flagged 
	Log(PREFETCHWT1);

	// ECX81 flagged
	Log(LAHF);
	Log(LZCNT);
	Log(ABM);
	Log(SSE4a);
	Log(misalignsse);
	Log(XOP);
	Log(FMA4);
	Log(TBM);

	// EDX81 flagged
	Log(SYSCALL);
	Log(MMXEXT);
	Log(RDTSCP);
	Log(_3DNOWEXT);
	Log(_3DNOW);
}