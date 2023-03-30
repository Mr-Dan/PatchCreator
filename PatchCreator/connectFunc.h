#pragma once
#ifdef PATCHCREATOR_EXPORTS
#define PATCHCREATOR_API __declspec(dllexport)
#else
#define PATCHCREATOR_API __declspec(dllimport)
#endif
#include <string>
#include <map>


struct Maap
{
    int Key;
    int Value;
};

extern "C" PATCHCREATOR_API bool PatchCreate(Maap * pMaap, int count,const char* a);
