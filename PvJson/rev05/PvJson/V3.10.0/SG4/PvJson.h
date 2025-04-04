/* Automation Studio generated header file */
/* Do not edit ! */
/* PvJson 3.10.0 */

#ifndef _PVJSON_
#define _PVJSON_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _PvJson_VERSION
#define _PvJson_VERSION 3.10.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "sys_lib.h"
		#include "FileIO.h"
#endif
#ifdef _SG4
		#include "sys_lib.h"
		#include "FileIO.h"
#endif
#ifdef _SGC
		#include "sys_lib.h"
		#include "FileIO.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define PARSON_ERR_EMPTY_BUFFER (-1001)
 #define PARSON_ERR_INVALID_PARAM (-1002)
 #define PARSON_ERR_EMPTY_BUFFER2 (-1003)
 #define PARSON_ERR_EMPTY_BUFFER3 (-1004)
 #define PARSON_ERR_PV_NOT_SUPPORTED (-1005)
 #define PVJSON_WRN_JSON_VALUE_NULL (-1101)
#else
 _GLOBAL_CONST signed long PARSON_ERR_EMPTY_BUFFER;
 _GLOBAL_CONST signed long PARSON_ERR_INVALID_PARAM;
 _GLOBAL_CONST signed long PARSON_ERR_EMPTY_BUFFER2;
 _GLOBAL_CONST signed long PARSON_ERR_EMPTY_BUFFER3;
 _GLOBAL_CONST signed long PARSON_ERR_PV_NOT_SUPPORTED;
 _GLOBAL_CONST signed long PVJSON_WRN_JSON_VALUE_NULL;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum PvJsonNullHandlingOptions
{	PVJSON_NULL_IGNORE_AND_WARN
} PvJsonNullHandlingOptions;

typedef struct JsonParserConfigurationType
{	enum PvJsonNullHandlingOptions NullValueHandling;
} JsonParserConfigurationType;

typedef struct JsonSerializer
{
	/* VAR_INPUT (analog) */
	unsigned long PVname;
	unsigned long FileDevice;
	unsigned long FileName;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	unsigned long JsonBuffer;
	/* VAR (analog) */
	unsigned long _addr;
	unsigned long _datalen;
	unsigned long _offset;
	unsigned long _hTask;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Active;
	plcbit Done;
	plcbit Error;
	/* VAR (digital) */
	plcbit _execute;
} JsonSerializer_typ;

typedef struct JsonParser
{
	/* VAR_INPUT (analog) */
	unsigned long FileDevice;
	unsigned long FileName;
	unsigned long Buffer;
	struct JsonParserConfigurationType Configuration;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	/* VAR (analog) */
	unsigned long _pvname;
	unsigned long _hTask;
	signed long _statusID;
	plcstring _nameOfNullItem[33];
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Busy;
	plcbit Active;
	plcbit Done;
	plcbit Error;
	/* VAR (digital) */
	plcbit _execute;
} JsonParser_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void JsonSerializer(struct JsonSerializer* inst);
_BUR_PUBLIC void JsonParser(struct JsonParser* inst);


#ifdef __cplusplus
};
#endif
#endif /* _PVJSON_ */

