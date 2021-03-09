
PROGRAM _INIT
	//https://apps.timwhitlock.info/unicode/inspect?s=%D0%9F%D1%80%D0%B8%D0%B2%D0%B5%D1%82
	UnicodeMessage[0] := 1055;
	UnicodeMessage[1] := 1088;
	UnicodeMessage[2] := 1080;
	UnicodeMessage[3] := 1074;
	UnicodeMessage[4] := 1077;
	UnicodeMessage[5] := 1090;
	brsmemcpy(ADR(DemoVar.MyUnicodeString),ADR(UnicodeMessage),MIN(SIZEOF(DemoVar.MyUnicodeString),SIZEOF(UnicodeMessage)));
	
	DemoVar.MyString := 'This is a demo string';
	DemoVar.MyUsint := 58;
	DemoVar.MyRealArray[-5] := -5.5;
	DemoVar.MyRealArray[-4] := -4.4;
	DemoVar.MyRealArray[-3] := -3.3;
	DemoVar.MyRealArray[-2] := -2.2;
	DemoVar.MyRealArray[-1] := -1.1;
	DemoVar.MyRealArray[0] 	:= 0;
	DemoVar.MyRealArray[1] 	:= 1.1;
	DemoVar.MyRealArray[2] 	:= 2.2;
	DemoVar.MyRealArray[3] 	:= 3.3;
	DemoVar.MyRealArray[4] 	:= 4.4;
	DemoVar.MyRealArray[5] 	:= 5.5;
END_PROGRAM

PROGRAM _CYCLIC
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

