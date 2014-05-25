#ifndef __miva_pcre_h
#define __miva_pcre_h

#include "mivapi.h"

#ifdef WIN32
	#define IMPORT __declspec(dllimport)
	#define EXPORT __declspec(dllexport)
	#define popen _popen
	#define pclose _pclose
#else
	#define IMPORT 
	#define EXPORT 
#endif

#ifdef __cplusplus
extern "C" {
#endif


void miva_exec(mvProgram prog, mvVariableHash parameters, mvVariable returnvalue, void ** unknown);
EXPORT MV_EL_Function_List *miva_function_table();


#ifdef __cplusplus
}
#endif

#endif