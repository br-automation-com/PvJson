
{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK JsonSerializer (*JsonSerializer converts PV into their JSON equivalent*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : {REDUND_UNREPLICABLE} BOOL; (*Enable FUB*)
		Execute : {REDUND_UNREPLICABLE} BOOL; (*On positive edge, it will serialize the given PV*)
		PVname : {REDUND_UNREPLICABLE} UDINT; (*Pointer to string containing the PV name*)
		FileDevice : {REDUND_UNREPLICABLE} UDINT; (*Pointer to string containing the file device name where the file will be generated. Can be 0*)
		FileName : {REDUND_UNREPLICABLE} UDINT; (*Pointer to string containing the file name that will be generated. Can be 0*)
	END_VAR
	VAR_OUTPUT
		Busy : {REDUND_UNREPLICABLE} BOOL; (*FUB is working*)
		Active : {REDUND_UNREPLICABLE} BOOL; (*FUB is ready to receive Execute*)
		Done : {REDUND_UNREPLICABLE} BOOL; (*FUB finished serializing*)
		StatusID : {REDUND_UNREPLICABLE} DINT; (*Error information*)
		Error : {REDUND_UNREPLICABLE} BOOL; (*Error*)
		JsonBuffer : {REDUND_UNREPLICABLE} UDINT; (*Memory address containing the serialized PV. It will be valid until FUB is disabled or a positive edge is given to Execute*)
	END_VAR
	VAR
		_addr : {REDUND_UNREPLICABLE} UDINT;
		_datalen : {REDUND_UNREPLICABLE} UDINT;
		_offset : {REDUND_UNREPLICABLE} UDINT;
		_execute : {REDUND_UNREPLICABLE} BOOL;
		_hTask : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK JsonParser (*JsonParser will parse a JSON object into the associated PV*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : {REDUND_UNREPLICABLE} BOOL; (* Enable FUB*)
		Execute : {REDUND_UNREPLICABLE} BOOL; (*On positive edge, it will serialize the given string*)
		FileDevice : {REDUND_UNREPLICABLE} UDINT; (*Pointer to string containing the file device name where the file is. It will be ignored if the buffer input is used*)
		FileName : {REDUND_UNREPLICABLE} UDINT; (*Pointer to string containing the file name containing the serialized PV. It will be ignored if the buffer input is used*)
		Buffer : {REDUND_UNREPLICABLE} UDINT; (*Pointer to string containing the serialized PV*)
		Configuration : {REDUND_UNREPLICABLE} JsonParserConfigurationType;
	END_VAR
	VAR_OUTPUT
		Busy : {REDUND_UNREPLICABLE} BOOL; (* FUB is working*)
		Active : {REDUND_UNREPLICABLE} BOOL; (*FUB is ready to receive Execute*)
		Done : {REDUND_UNREPLICABLE} BOOL; (* FUB finished parsing*)
		StatusID : {REDUND_UNREPLICABLE} DINT; (* Error information*)
		Error : {REDUND_UNREPLICABLE} BOOL; (*Error*)
	END_VAR
	VAR
		_pvname : {REDUND_UNREPLICABLE} UDINT;
		_execute : {REDUND_UNREPLICABLE} BOOL;
		_hTask : {REDUND_UNREPLICABLE} UDINT;
		_statusID : {REDUND_UNREPLICABLE} DINT;
		_nameOfNullItem : {REDUND_UNREPLICABLE} STRING[32];
	END_VAR
END_FUNCTION_BLOCK
