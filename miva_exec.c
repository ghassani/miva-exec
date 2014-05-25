#include <stdio.h>
#include <string>
#include <iostream>
#include "mivaexec.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* Function Parameter Data Structures
*/
MV_EL_FunctionParameter miva_exec_parameters[] = {
	{ "cmd", 3, EPF_NORMAL },
};

/**
* miva_exec
*
* Execute a system call 
*
* Example:
*
* <MvASSIGN NAME="g.system_user" VALUE="{ exec("whoami") }" />
*/
void miva_exec(mvProgram prog, mvVariableHash parameters, mvVariable returnvalue, void **) {

	int command_length;
	char *result;
	char buffer[BUFSIZ];
	int i;
	size_t result_size = 0, buffer_size = 0;

	const char *command = mvVariable_Value( mvVariableHash_Index( parameters, 0 ), &command_length );

	FILE* pipe = popen(command, "r");

	if (!pipe) {
		mvVariable_SetValue( returnvalue, "Error Processing Command",  24);
		return;
	}

	result = (char*) calloc(BUFSIZ, sizeof(char));
	buffer_size = BUFSIZ;

	while(!feof(pipe)) {
		 memset(buffer, '\0', BUFSIZ);
		 if(fgets(buffer, BUFSIZ, pipe) != NULL){
			 for(int i = 0; i < BUFSIZ; i++) {
				 if(buffer[i] == '\0'){
					 break;
				 }

				 if(result_size < buffer_size){
					 buffer_size += BUFSIZ;
					 realloc(result, buffer_size);
				 }

				 result[result_size] = buffer[i];
				 result_size++;
			 }	 
		} 
	}
	
	pclose(pipe);

	mvVariable_SetValue( returnvalue, result, result_size );

	free(result);
}



/**
* Hook the functions into Miva
*/ 

EXPORT MV_EL_Function_List *miva_function_table() {
	static MV_EL_Function exported_functions[] = {
		{ "exec", 4, 1, miva_exec_parameters, miva_exec },
		{ 0 , 0 , 0, 0 , 0 }
	};

	static MV_EL_Function_List list = { MV_EL_FUNCTION_VERSION, exported_functions };

	return &list;
}


#ifdef __cplusplus
}
#endif