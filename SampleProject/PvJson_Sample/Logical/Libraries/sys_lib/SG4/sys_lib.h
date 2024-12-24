/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _SYS_LIB_H_
#define	_SYS_LIB_H_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>
#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif

/* Error codes of the BURTRAP/SYS_LIB services */
#define ERR_BUR_MO_NOTFOUND     3019    /* module not found */
#define ERR_BUR_ILLSTATE        3302    /* illegal state of object */
#define ERR_BUR_ILLTYP          3311    /* SYSreset - invalid input value for mode */
#define ERR_BUR_ILLPAR          3317    /* illegal parameter */
#define ERR_BUR_ILLOBJ          3324    /* object does not exist */
#define ERR_BUR_NOENTRY         3332    /* no entry */
#define	ERR_BUR_TOOLONG_PVNAME	3333	/* too long PV name */
#define ERR_BUR_ILLIDENT        3336    /* illegal ident */
#define ERR_BUR_NOTIME          3584    /* time not available */
#define ERR_BUR_TMP_ALLOC       3601    /* not enough continuous memory */
#define ERR_BUR_TMP_FREE        3701    /* invalid pointer/length */

/* State for object PLC task */
#define     Z_ST_created        1
#define     Z_ST_running        2
#define     Z_ST_blocked        3
#define     Z_ST_exist          0x00
#define     Z_ST_installed      0x82
#define     Z_ST_PVinstalled    0x83
#define     Z_ST_IOinstalled    0x84
#define     Z_ST_IOdeinstalled  0x85
#define     Z_ST_PVdeinstalled  0x86
#define     Z_ST_delete         0x87
#define     Z_ST_stdebug        0x88
#define     Z_ST_tmp_suspended  0x90

/* elementary data types */
#define 	SYSLIB_IEC_TYPE_USER_DEFINED	0	/* User-defined data type */
#define 	SYSLIB_IEC_TYPE_USER_DEFINED_2	15 	/* User-defined data type (legacy: array of structs) */
#define 	SYSLIB_IEC_TYPE_BOOL			1   /* 8 Bit containing a boolean value FALSE=0 or TRUE=1 */
#define 	SYSLIB_IEC_TYPE_SINT			2   /* 8 Bit signed integer */
#define 	SYSLIB_IEC_TYPE_INT				3   /* 16 Bit signed integer */
#define 	SYSLIB_IEC_TYPE_DINT			4   /* 32 Bit signed integer */
#define 	SYSLIB_IEC_TYPE_USINT			5   /* 8 Bit unsigned integer */
#define 	SYSLIB_IEC_TYPE_UINT			6   /* 16 Bit unsigned integer */
#define 	SYSLIB_IEC_TYPE_UDINT			7   /* 32 Bit unsigned integer */
#define 	SYSLIB_IEC_TYPE_REAL			8   /* 32 Bit floating point number */
#define 	SYSLIB_IEC_TYPE_STRING			9   /* Variable-length single-byte character string */
#define 	SYSLIB_IEC_TYPE_DATE_AND_TIME	11 	/* 32 Bit of Date in Seconds since 01.01.1970 00:00:00 */
#define 	SYSLIB_IEC_TYPE_TIME			12 	/* 32 Bit of Time in ms */
#define 	SYSLIB_IEC_TYPE_DATE			13 	/* 32 Bit of Date (only) */
#define 	SYSLIB_IEC_TYPE_LREAL			14 	/* 64 Bit floating point number */
#define 	SYSLIB_IEC_TYPE_TIME_OF_DAY		16 	/* 32 Bit Time of day (only) */
#define		SYSLIB_IEC_TYPE_BYTE			17 	/* Bit string of length 8 */
#define		SYSLIB_IEC_TYPE_WORD			18 	/* Bit string of length 16 */
#define		SYSLIB_IEC_TYPE_DWORD			19 	/* Bit string of length 32 */
#define		SYSLIB_IEC_TYPE_WSTRING			21	/* Variable-length double-byte character string */

/* shutdown / reboot types */
#define     SYSLIB_WARMSTART			0x01	/*WARMSTART(with restart)*/
#define     SYSLIB_COLDSTART			0x02	/*COLDSTART(with restart)*/
#define     SYSLIB_WARMSTART_NO_REBOOT	0x11	/*WARMSTART(no restart, only shutdown)*/
#define     SYSLIB_COLDSTART_NO_REBOOT  0x12	/*COLDSTART(no restart, only shutdown)*/
#define     SYSLIB_DIAGNOSTICS          0x20	/*DIAGNOSTICS(with restart)*/
#define     SYSLIB_SERVICE				0x40	/*SERVICE(with restart) */

typedef struct RTCtime_typ {
            /* 1. UDINT */
            UINT     year;       /* year, starting with zero */
            USINT    month;      /* month: 1 - 12 */
            USINT    day;        /* day:   1 - 31 */
            /* 2. UDINT */
            USINT    reserve;
            USINT    hour;       /* hour:   0 - 23 */
            USINT    minute;     /* minute: 0 - 59 */
            USINT    second;     /* second: 0 - 59 */
            /* 3. UDINT */
            UINT     millisec;   /* millisecond: 0 - 999 */
            UINT     microsec;   /* microsecond: 0 - 999 */
        } RTCtime_typ;

/* structure for MO_list */
typedef struct MO_List_typ {
        char    name[14];        /* name of the module (ASCII) */
        USINT   grp;             /* groups */
        USINT   type;            /* module type */
        USINT   state;           /* state of the module */
        USINT   reserve;
        UDINT   adress;          /* physical address of the module */
        UDINT   memtype;         /* memory type (0=OTP,1=RAM,2=EPROM,3=FLASH */
        } MO_List_typ;           /* 5=FIXRAM) */
        
/* structure for slMoList */
typedef struct slMoList {
	/* VAR_INPUT (analog) */
	unsigned long	pMoName;
	unsigned long	sizeMoName;
	unsigned long	pAppMoName;
	unsigned long	sizeAppMoName;
	/* VAR_OUTPUT (analog) */
	unsigned short	status;
	unsigned long	moSize;
	unsigned char	moType;
	unsigned char	memType;
	/* VAR (analog) */
	unsigned long	i_hMo;
	/* VAR_INPUT (digital) */
	plcbit	enable;
	plcbit	first;
	plcbit	filter;
} slMoList_typ;

/* structure for MO_info */
typedef struct MO_info
{
	/* VAR_INPUT (analog) */
	unsigned long pName;
	unsigned char grp;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char type;
	unsigned char state;
	unsigned long memType;
	unsigned long address;
	unsigned long size;
	unsigned char version[10];
	struct RTCtime_typ date;
	/* VAR_INPUT (digital) */
	plcbit enable;
} MO_info_typ;

/* structue for PV_xlist */
typedef struct PV_xList_typ {

		char		name[33];    /* name of PV (ASCII)		*/
		USINT		data_typ;	 /* data type of PV			*/
		UDINT		data_len;	 /* data length of PV		*/
		UDINT		dimension;	 /* dimension of PV			*/
		UDINT		adress;		 /* physical address of PV	*/
		}PV_xList_typ;

/* structure for MO_ver */
typedef struct MoVerStruc_typ {
		USINT   version[10];		/* Version of the BR Module */
        UINT    year;
        USINT   month;
        USINT   day;
        USINT   reserve;
        USINT   hour;
        USINT   minute;
        USINT   second;
        } MoVerStruc_typ;

/* structure for the FUB Bit2Byte */
typedef struct Bit2Byte {
		/* non boolean input parameter */
        UDINT   bitadr;
        UINT    length;
		/* non boolean output parameter*/
        UDINT   byteadr;
		/* non boolean static local */
        USINT	byte_00;
        USINT   byte_01;
        USINT   byte_02;
        USINT   byte_03;
        USINT   byte_04;
        USINT   byte_05;
        USINT   byte_06;
        USINT   byte_07;
        USINT   byte_08;
        USINT   byte_09;
        USINT   byte_10;
        USINT   byte_11;
        USINT   byte_12;
        USINT   byte_13;
        USINT   byte_14;
        USINT	byte_15;
		/* boolean input parameter */
		/* boolean output parameter */
		/* boolean static local */
        BOOL	bmem000;
        BOOL	bmem001;
        BOOL	bmem002;
        BOOL	bmem003;
        BOOL	bmem004;
        BOOL	bmem005;
        BOOL	bmem006;
        BOOL	bmem007;
        BOOL	bmem008;
        BOOL	bmem009;
        BOOL	bmem010;
        BOOL	bmem011;
        BOOL	bmem012;
        BOOL	bmem013;
        BOOL	bmem014;
        BOOL	bmem015;
        BOOL	bmem016;
        BOOL	bmem017;
        BOOL	bmem018;
        BOOL	bmem019;
        BOOL	bmem020;
        BOOL	bmem021;
        BOOL	bmem022;
        BOOL	bmem023;
        BOOL	bmem024;
        BOOL	bmem025;
        BOOL	bmem026;
        BOOL	bmem027;
        BOOL	bmem028;
        BOOL	bmem029;
        BOOL	bmem030;
        BOOL	bmem031;
        BOOL	bmem032;
        BOOL	bmem033;
        BOOL	bmem034;
        BOOL	bmem035;
        BOOL	bmem036;
        BOOL	bmem037;
        BOOL	bmem038;
        BOOL	bmem039;
        BOOL	bmem040;
        BOOL	bmem041;
        BOOL	bmem042;
        BOOL	bmem043;
        BOOL	bmem044;
        BOOL	bmem045;
        BOOL	bmem046;
        BOOL	bmem047;
        BOOL	bmem048;
        BOOL	bmem049;
        BOOL	bmem050;
        BOOL	bmem051;
        BOOL	bmem052;
        BOOL	bmem053;
        BOOL	bmem054;
        BOOL	bmem055;
        BOOL	bmem056;
        BOOL	bmem057;
        BOOL	bmem058;
        BOOL	bmem059;
        BOOL	bmem060;
        BOOL	bmem061;
        BOOL	bmem062;
        BOOL	bmem063;
        BOOL	bmem064;
        BOOL	bmem065;
        BOOL	bmem066;
        BOOL	bmem067;
        BOOL	bmem068;
        BOOL	bmem069;
        BOOL	bmem070;
        BOOL	bmem071;
        BOOL	bmem072;
        BOOL	bmem073;
        BOOL	bmem074;
        BOOL	bmem075;
        BOOL	bmem076;
        BOOL	bmem077;
        BOOL	bmem078;
        BOOL	bmem079;
        BOOL	bmem080;
        BOOL	bmem081;
        BOOL	bmem082;
        BOOL	bmem083;
        BOOL	bmem084;
        BOOL	bmem085;
        BOOL	bmem086;
        BOOL	bmem087;
        BOOL	bmem088;
        BOOL	bmem089;
        BOOL	bmem090;
        BOOL	bmem091;
        BOOL	bmem092;
        BOOL	bmem093;
        BOOL	bmem094;
        BOOL	bmem095;
        BOOL	bmem096;
        BOOL	bmem097;
        BOOL	bmem098;
        BOOL	bmem099;
        BOOL	bmem100;
        BOOL	bmem101;
        BOOL	bmem102;
        BOOL	bmem103;
        BOOL	bmem104;
        BOOL	bmem105;
        BOOL	bmem106;
        BOOL	bmem107;
        BOOL	bmem108;
        BOOL	bmem109;
        BOOL	bmem110;
        BOOL	bmem111;
        BOOL	bmem112;
        BOOL	bmem113;
        BOOL	bmem114;
        BOOL	bmem115;
        BOOL	bmem116;
        BOOL	bmem117;
        BOOL	bmem118;
        BOOL	bmem119;
        BOOL	bmem120;
        BOOL	bmem121;
        BOOL	bmem122;
        BOOL	bmem123;
        BOOL	bmem124;
        BOOL	bmem125;
        BOOL	bmem126;
        BOOL	bmem127;
        BOOL	bmem128;
        BOOL	bmem129;
        BOOL	bmem130;
        BOOL	bmem131;
        BOOL	bmem132;
        BOOL	bmem133;
        BOOL	bmem134;
        BOOL	bmem135;
        BOOL	bmem136;
        BOOL	bmem137;
        BOOL	bmem138;
        BOOL	bmem139;
		} Bit2Byte_typ;

/* structure for the FUB Byte2Bit */
typedef struct Byte2Bit {
		/* non boolean input parameter */
		UDINT	byteadr;
		UINT    length;
		/* non boolean output parameter*/
		UDINT   bitadr;
		/* non boolean static local */
		/* boolean input parameter */
		/* boolean output parameter */
		/* boolean static local */
		BOOL	bmem000;
		BOOL	bmem001;
		BOOL	bmem002;
		BOOL	bmem003;
		BOOL	bmem004;
		BOOL	bmem005;
		BOOL	bmem006;
		BOOL	bmem007;
		BOOL	bmem008;
		BOOL	bmem009;
		BOOL	bmem010;
		BOOL	bmem011;
		BOOL	bmem012;
		BOOL	bmem013;
		BOOL	bmem014;
		BOOL	bmem015;
		BOOL	bmem016;
		BOOL	bmem017;
		BOOL	bmem018;
		BOOL	bmem019;
		BOOL	bmem020;
		BOOL	bmem021;
		BOOL	bmem022;
		BOOL	bmem023;
		BOOL	bmem024;
		BOOL	bmem025;
		BOOL	bmem026;
		BOOL	bmem027;
		BOOL	bmem028;
		BOOL	bmem029;
		BOOL	bmem030;
		BOOL	bmem031;
		BOOL	bmem032;
		BOOL	bmem033;
		BOOL	bmem034;
		BOOL	bmem035;
		BOOL	bmem036;
		BOOL	bmem037;
		BOOL	bmem038;
		BOOL	bmem039;
		BOOL	bmem040;
		BOOL	bmem041;
		BOOL	bmem042;
		BOOL	bmem043;
		BOOL	bmem044;
		BOOL	bmem045;
		BOOL	bmem046;
		BOOL	bmem047;
		BOOL	bmem048;
		BOOL	bmem049;
		BOOL	bmem050;
		BOOL	bmem051;
		BOOL	bmem052;
		BOOL	bmem053;
		BOOL	bmem054;
		BOOL	bmem055;
		BOOL	bmem056;
		BOOL	bmem057;
		BOOL	bmem058;
		BOOL	bmem059;
		BOOL	bmem060;
		BOOL	bmem061;
		BOOL	bmem062;
		BOOL	bmem063;
		BOOL	bmem064;
		BOOL	bmem065;
		BOOL	bmem066;
		BOOL	bmem067;
		BOOL	bmem068;
		BOOL	bmem069;
		BOOL	bmem070;
		BOOL	bmem071;
		BOOL	bmem072;
		BOOL	bmem073;
		BOOL	bmem074;
		BOOL	bmem075;
		BOOL	bmem076;
		BOOL	bmem077;
		BOOL	bmem078;
		BOOL	bmem079;
		BOOL	bmem080;
		BOOL	bmem081;
		BOOL	bmem082;
		BOOL	bmem083;
		BOOL	bmem084;
		BOOL	bmem085;
		BOOL	bmem086;
		BOOL	bmem087;
		BOOL	bmem088;
		BOOL	bmem089;
		BOOL	bmem090;
		BOOL	bmem091;
		BOOL	bmem092;
		BOOL	bmem093;
		BOOL	bmem094;
		BOOL	bmem095;
		BOOL	bmem096;
		BOOL	bmem097;
		BOOL	bmem098;
		BOOL	bmem099;
		BOOL	bmem100;
		BOOL	bmem101;
		BOOL	bmem102;
		BOOL	bmem103;
		BOOL	bmem104;
		BOOL	bmem105;
		BOOL	bmem106;
		BOOL	bmem107;
		BOOL	bmem108;
		BOOL	bmem109;
		BOOL	bmem110;
		BOOL	bmem111;
		BOOL	bmem112;
		BOOL	bmem113;
		BOOL	bmem114;
		BOOL	bmem115;
		BOOL	bmem116;
		BOOL	bmem117;
		BOOL	bmem118;
		BOOL	bmem119;
		BOOL	bmem120;
		BOOL	bmem121;
		BOOL	bmem122;
		BOOL	bmem123;
		BOOL	bmem124;
		BOOL	bmem125;
		BOOL	bmem126;
		BOOL	bmem127;
		BOOL	bmem128;
		BOOL	bmem129;
		BOOL	bmem130;
		BOOL	bmem131;
		BOOL	bmem132;
		BOOL	bmem133;
		BOOL	bmem134;
		BOOL	bmem135;
		BOOL	bmem136;
		BOOL	bmem137;
		BOOL	bmem138;
		BOOL	bmem139;
		} Byte2Bit_typ;

/***************/
/* Prototyping of functions and function blocks */
_BUR_PUBLIC UINT PV_xgetadr		(char *pv_name, UDINT *pv_adresse, UDINT *data_len);
_BUR_PUBLIC UINT PV_xlist		(UINT prev_index, UINT *index, PV_xList_typ *pvl_p);
_BUR_PUBLIC UINT PV_item		(char *pv_name, UINT index, char *itemname);
_BUR_PUBLIC UINT PV_ninfo		(char *pv_name, UDINT *data_typ_p, UDINT *data_len_p,
					 UINT *dimension_p);

_BUR_PUBLIC UINT  SYSreset		(BOOL enable, USINT mode);

_BUR_PUBLIC UINT MO_list		(UINT prev_index, UINT *index, MO_List_typ *mol_p);
_BUR_PUBLIC void MO_info		(struct MO_info* pInst);
_BUR_PUBLIC void slMoList		(slMoList_typ * pInst);

_BUR_PUBLIC UINT ST_ident		(char *st_name_p, USINT st_grp, UDINT *st_ident);
_BUR_PUBLIC UINT ST_tmp_suspend	(UDINT st_ident);
_BUR_PUBLIC UINT ST_tmp_resume  (UDINT st_ident);
_BUR_PUBLIC UINT ST_allsuspend	(void);
_BUR_PUBLIC UINT ST_info		(UDINT st_ident, USINT *state, SINT *tcnr);
_BUR_PUBLIC UINT ST_name		(UDINT st_ident, char *st_name_p, USINT *st_grp);

_BUR_PUBLIC UINT TMP_alloc		(UDINT memlng, void **memptr);
_BUR_PUBLIC UINT TMP_free		(UDINT memlng, void *memptr);

_BUR_PUBLIC UINT RTC_gettime	(RTCtime_typ *rtctime);
_BUR_PUBLIC UINT RTC_settime	(RTCtime_typ *rtctime);
_BUR_PUBLIC UINT TIM_musec		(void);
_BUR_PUBLIC UINT TIM_ticks		(void);

_BUR_PUBLIC UINT ERR_warning	(UINT errornr, UDINT errorinfo);
_BUR_PUBLIC UINT ERR_fatal		(UINT errornr, UDINT errorinfo);
_BUR_PUBLIC UINT ERRxwarning	(UINT errornr, UDINT errorinfo, char* errorstring);
_BUR_PUBLIC UINT ERRxfatal		(UINT errornr, UDINT errorinfo, char* errorstring);

_BUR_PUBLIC UINT MO_ver			(STRING *pName, USINT grp, MoVerStruc_typ* pMoVerStruc);

_BUR_PUBLIC unsigned long MO_versionMajor(STRING *pName);
_BUR_PUBLIC unsigned long MO_versionMinor(STRING *pName);
_BUR_PUBLIC unsigned long MO_versionPatch(STRING *pName);
_BUR_PUBLIC unsigned long MO_versionBuild(STRING *pName);

_BUR_PUBLIC void Bit2Byte		(Bit2Byte_typ*	Bit2Byte_ptr);
_BUR_PUBLIC void Byte2Bit		(Byte2Bit_typ*	Byte2Bit_ptr);

#ifdef __cplusplus
};
#endif
#endif /* _SYS_LIB_H_ */
     
