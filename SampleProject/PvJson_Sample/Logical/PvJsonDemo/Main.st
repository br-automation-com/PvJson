
PROGRAM _INIT
	(* Insert code here *)
	JsonSerializer_0.Enable := TRUE;
	JsonParser_0.Enable 	:= TRUE;
END_PROGRAM

PROGRAM _CYCLIC
	
	// JsonSerializer_0.Execute ---> Set it using watch to test the functionality
	JsonSerializer_0.PVname := ADR('DemoTask:DemoVar');
	JsonSerializer_0.FileDevice := ADR('PvJson'); //Defined at CPU config. It's pointing to C:\Temp\PvJson 
	JsonSerializer_0.FileName := ADR('DemoVar.json');
	JsonSerializer_0();
	
	
	//JsonParser_0.Execute ---> Set it using watch to test the functionality
	JsonParser_0.FileDevice := ADR('PvJson');
	JsonParser_0.FileName 	:= ADR('DemoVar.json');
	JsonParser_0();
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	JsonSerializer_0(Enable := FALSE);
	JsonParser_0(Enable := FALSE);
END_PROGRAM

