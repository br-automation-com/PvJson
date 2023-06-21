
TYPE
	JsonParserConfigurationType : 	STRUCT 
		NullValueHandling : PvJsonNullHandlingOptions;
	END_STRUCT;
	PvJsonNullHandlingOptions : 
		(
		PVJSON_NULL_IGNORE_AND_WARN
		);
END_TYPE
