{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK Byte2Bit 				(*converts a byte array into a bit array*)
	VAR_INPUT
		byteadr	:UDINT;					(*byte array address*)
		length	:UINT;					(*byte array length (1 through 16)*)
	END_VAR
	VAR_OUTPUT
		bitadr	:UDINT;					(*bit array address*)
	END_VAR
	VAR
		bmem000	:BOOL;					(*internal variable*)
		static_val	:ARRAY[0..138] OF USINT;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK Bit2Byte 				(*converts a bit array into a byte array where every bit of data corresponds to an element in the bit array*)
	VAR_INPUT
		bitadr	:UDINT;					(*BIT array address*)
		length	:UINT;					(*BIT array length (1 through 128)*)
	END_VAR
	VAR_OUTPUT
		byteadr	:UDINT;					(*BYTE array address*)
	END_VAR	
	VAR
		byte_00	:USINT;					(*internal variable*)
		byte_01	:USINT;					(*internal variable*)
		byte_02	:USINT;					(*internal variable*)
		byte_03	:USINT;					(*internal variable*)
		byte_04	:USINT;					(*internal variable*)
		byte_05	:USINT;					(*internal variable*)
		byte_06	:USINT;					(*internal variable*)
		byte_07	:USINT;					(*internal variable*)
		byte_08	:USINT;					(*internal variable*)
		byte_09	:USINT;					(*internal variable*)
		byte_10	:USINT;					(*internal variable*)
		byte_11	:USINT;					(*internal variable*)
		byte_12	:USINT;					(*internal variable*)
		byte_13	:USINT;					(*internal variable*)
		byte_14	:USINT;					(*internal variable*)
		byte_15	:USINT;					(*internal variable*)
		bmem000	:BOOL;					(*internal variable*)
		static_val	:ARRAY[0..138] OF USINT;	(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION ERRxfatal : UINT 				(*makes an log book entry in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
		errorstring	:UDINT;				(*pointer to string, ending in zero (32 characters maximum)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERR_fatal : UINT 				(*makes an entry (log book entry) in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERR_warning : UINT 			(*makes an entry (log book entry) in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ERRxwarning : UINT 			(*makes an entry (log book entry) in the error log book*)
	VAR_INPUT
		errornr	:UINT;					(*error number, which is entered in the error log book*)
		errorinfo	:UDINT;				(*optional additional information (error details)*)
		errorstring	:UDINT;				(*string ending in zero (32 characters maximum)*)
	END_VAR
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIM_ticks : UINT 				(*provides the number of ticks (1 tick = 10 ms) in the current second*)
(* The dummy_input parameter is obsolete.
	VAR_INPUT
		dummy_input	:USINT;				required for operation in ladder diagram
	END_VAR *)
END_FUNCTION

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION TIM_musec : UINT 				(*provides the (approximate) number of microseconds in the current tick (1 tick = 10 ms)*)
(* The dummy_input parameter is obsolete. 
	VAR_INPUT
		dummy_input	:USINT;				required for operation in ladder diagram
	END_VAR *)
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION RTC_settime : UINT 			(*sets the real-time clock to the desired time (RTCtime_struct structure)*)
	VAR_INPUT
		RTCtime_struct	:UDINT;			(*pointer to the structure which contains the time and date*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION RTC_gettime : UINT 			(*reads time and date from the real-time clock and writes this information in a RTCtime_struct structure*)
	VAR_INPUT
		RTCtime_struct	:UDINT;			(*pointer to the structure where the time and date are stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION TMP_free : UINT 				(*releases a memory area, which has been allocated using TMP_alloc()*)
	VAR_INPUT
		memlng	:UDINT;					(*size of the memory area to be released in bytes*)
		memptr	:UDINT;					(*address for the memory area to be released*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION TMP_alloc : UINT 				(*allocates memory in the temporary memory area (system RAM only)*)
	VAR_INPUT
		memlng	:UDINT;					(*size of the allocated memory area in bytes*)
		memptr	:UDINT;					(*pointer to requested memory area*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_name : UINT 				(*provides the name and group number for the object with the relevant ID number*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident() (0 = the object itself)*)
		st_name_p	:UDINT;				(*pointer to name of the object*)
		st_grp	:UDINT;					(*pointer to group number for the object (standard = 0)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_info : UINT 				(*provides information about the object with the relevant ID number*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident() (0 = the object itself)*)
		state	:UDINT;					(*pointer to status of the object: 1 ... Object installed, 2 ... Object running, ..*)
		tknr	:UDINT;					(*pointer to resource information: 1 through 8 ... Cyclic resource, -8 ... Exception resource, ..*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_allsuspend : UINT 			(*suspends all cyclic software objects*)
	VAR_INPUT
		dummy_input	:USINT;				(*required for operation in ladder diagram*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_tmp_resume : UINT 			(*activates a previously stopped (cyclic) software object*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the software object from ST_ident()*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_tmp_suspend : UINT 			(*suspends a cyclic object temporarily*)
	VAR_INPUT
		st_ident	:UDINT;				(*ID number for the object from ST_ident() (0 = object suspends itself)*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION ST_ident : UINT 				(*provides the ID number for a software object*)
	VAR_INPUT
		st_name	:UDINT;					(*pointer to name of the software object*)
		st_grp	:USINT;					(*group number for the object (standard = 0)*)
		st_ident	:UDINT;				(*pointer to ID number of the object*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION MO_ver : UINT					(*reads the version and the date of a B&R module*)
	VAR_INPUT
		pName	:UDINT;					(*pointer to name of the B&R module*)
		grp	:USINT;						(*group number for the object (standard = 0)*)
		pMoVerStruc	:UDINT;				(*pointer to the structure where the module version of the located B&R module is stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION MO_list : UINT 				(*browses all the B&R modules on the target system*)
	VAR_INPUT
		prev_index	:UINT;				(*index of the B&R module where the search is being started*)
		index	:UDINT;					(*pointer to index of the found B&R module*)
		MO_List_struct	:UDINT;			(*pointer to structure where the module information is stored*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK MO_info	 				(*reads information of a B&R module on the target system*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		pName	:UDINT;					(*pointer to name of the B&R module*)
		grp		:USINT;					(*group number for the object (standard = 0)*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		type	:USINT;					(*B&R module type*)
		state   :USINT;					(*B&R module status*)
		memType :UDINT;					(*memory of the B&R module*)
		address :UDINT;					(*physical address of the B&R module*)
		size    :UDINT;					(*size of the B&R module*)
		version :ARRAY[0..9] OF USINT;	(*B&R module version*)
		date    :RTCtime_typ;			(*B&R module date*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION MO_versionMajor : UDINT (*returns the major number of a B&R module, returns zero on error*)
	VAR_INPUT
			pName	:UDINT;					(*pointer to name of the B&R module*)
	END_VAR
END_FUNCTION

{REDUND_OK} FUNCTION MO_versionMinor : UDINT (*returns the minor number of a B&R module, returns zero on error*)
	VAR_INPUT
			pName	:UDINT;					(*pointer to name of the B&R module*)
	END_VAR
END_FUNCTION

{REDUND_OK} FUNCTION MO_versionPatch : UDINT (*returns the patch number of a B&R module, returns zero on error*)
	VAR_INPUT
			pName	:UDINT;					(*pointer to name of the B&R module*)
	END_VAR
END_FUNCTION

{REDUND_OK} FUNCTION MO_versionBuild : UDINT (*returns the build number of a B&R module, returns zero on error*)
	VAR_INPUT
			pName	:UDINT;					(*pointer to name of the B&R module*)
	END_VAR
END_FUNCTION
 

{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION SYSreset : UINT 				(*initiates a boot procedure on the target system in the specified mode (WARM or COLD START)*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		mode	:USINT;					(*boot mode: 0x01 .. WARM START (with Restart), 0x02 .. COLD START (with Restart), ..*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_xlist : UINT 				(*browse all the variables*)
	VAR_INPUT
		prev_index	:UINT;				(*index of the PV where the search is being started*)
		index	:UDINT;					(*pointer to index of the located PV*)
		PV_xList_struct	:UDINT;			(*pointer to structure which contains PV information about the located PV*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_ninfo : UINT 				(*reads data from a process variable of a complex data type (array or structure variable)*)
	VAR_INPUT
		pv_name	:UDINT;					(*pointer to name of the process variable*)
		data_typ_p	:UDINT;				(*pointer to data type of the PV*)
		data_len_p	:UDINT;				(*pointer to length of the PV in bytes*)
		dimension_p	:UDINT;				(*pointer to number of array or structure elements*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_item : UINT 				(*determines the names of structure elements*)
	VAR_INPUT
		pv_name	:UDINT;					(*pointer to name of the process variable*)
		index	:UINT;					(*structure element index*)
		itemname	:UDINT;				(*pointer to name of the structure element*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION PV_xgetadr : UINT 				(*provides the address and length of a variable*)
	VAR_INPUT
		pv_name_p	:UDINT;				(*pointer to name of the process variable*)
		pv_adresse	:UDINT;				(*PV address for dynamic access*)
		data_len	:UDINT;				(*pointer to length of the process variable in bytes*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK slMoList	 				(*browses the B&R modules on the target system*)
	VAR_INPUT
		enable			:BOOL;			(*enables execution*)
		first			:BOOL;			(*starting point for browsing*)
		filter			:BOOL;			(*filter for browsing in own application module*)
		pMoName			:UDINT;			(*name of the B&R module given as a pointer*)
		sizeMoName		:UDINT;			(*length of the string (pMoName) -> ideally, sizeMoName = 11*)
		pAppMoName		:UDINT;			(*name of the application module given as a pointer*)
		sizeAppMoName	:UDINT;			(*length of the string (pAppMoName) -> ideally, sizeAppMoName = 21*)
	END_VAR
	VAR_OUTPUT
		status			:UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		moSize			:UDINT;			(*size of the B&R module*)
		moType			:USINT;			(*type of the B&R module*)
		memType			:USINT;			(*memory type of the B&R module*)
	END_VAR
	VAR
		i_hMo			:UDINT;			(*internal variable*)		
	END_VAR
END_FUNCTION_BLOCK
