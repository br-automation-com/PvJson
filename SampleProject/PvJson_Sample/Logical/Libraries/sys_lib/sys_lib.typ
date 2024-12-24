TYPE
	MoVerStruc_typ : STRUCT
		version	: ARRAY[0..9] OF USINT ;
		year	: UINT ;
		month	: USINT ;
		day	: USINT ;
		reserve	: USINT ;
		hour	: USINT ;
		minute	: USINT ;
		second	: USINT ;
	END_STRUCT;
	PV_xList_typ : STRUCT
		name	: ARRAY[0..32] OF SINT ;		(*name of the process variable*)
		data_typ	: USINT ;					(*PV data type (see PV_info())*)
		data_len	: UDINT ;					(*length of the PV in bytes*)
		dimension	: UDINT ;					(*number of array elements*)
		adress	: UDINT ;						(*physical address of the PV (for dynamic access)*)
	END_STRUCT;
	MO_List_typ : STRUCT
		name	: ARRAY[0..13] OF SINT ;
		grp	: USINT ;
		type	: USINT ;
		state	: USINT ;
		reserve	: USINT ;
		adress	: UDINT ;
		memtype	: UDINT ;
	END_STRUCT;
	RTCtime_typ : STRUCT
		year	: UINT ;
		month	: USINT ;
		day	: USINT ;
		reserve	: USINT ;
		hour	: USINT ;
		minute	: USINT ;
		second	: USINT ;
		millisec	: UINT ;
		microsec	: UINT ;
	END_STRUCT;
END_TYPE
