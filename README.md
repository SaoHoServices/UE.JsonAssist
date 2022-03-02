# UE.JsonAssist
JsonAssist Plugin Documentation
  
// Can access members at multiple levels  
Example:  

	// FJson Json = FJson(JsonType.Object);  
	FJson Json = JsonObject();  
	
	// You can assign various values to json objects by operators.    
	Json["Name"] = "MoonStudio";  
	Json["Int"] = 1;  
	Json["Float"] = 1.0f;  
	Json["Double"] = 1.0;  
	Json["Online"] = true;  
  
	int64 Int64 = 1;  
	uint32 UInt32 = 1;  
	uint64 UInt64 = 1;  
  
	Json["int64"] = Int64;  
	Json["uint32"] = UInt32;  
	Json["uint64"] = UInt64;  
  
	// Json["Members"] = FJson(JsonType.Array);  
	// Json["Members"] = JsonArray();  
	Json["Members"][0] = "SaoHo";  
	Json["Members"][1] = "Erie";  
    
	Json["Object"]["Name"] = "Object";  
	Json["Array"][0] = "Array";  
  
  	// Fast print json to text without style format.  
	FString Fast = UJsonAssist::Get().FastPrint(Json);  
	  
	// Print json to text with style format.  
	FString Full = UJsonAssist::Get().Print(Json);  
  
	FString JsonFile = FPaths::ProjectDir() + "/Json.json";  
	// FileWrite function can write text to file  
	UJsonAssist::FileWrite(JsonFile, Full);  
    
  	// Parse json function, FileRead function can read text from file.  
	FJson Temp = UJsonAssist::Get().Parse(UJsonAssist::FileRead(JsonFile));  
	  
	// Get json value text.  
	FString Name = Temp["Name"].Get();  
	Name = Temp["Name"];  
	  
	// Get Other type value.  
	int32 tempint = Temp["Int"].GetInteger();  
	float tempfloat = Temp["Float"].GetFloat();  
	
	// Get the json all fields.  
	TArray<FString> Fields = Temp.GetFields();  
	  
	// Remove a json value when match is successful.  
	Temp.Remove([](const FJson &Entry)  
	{  
		return Entry.FieldName == "Name";  
	});  
	  
	// Remove all json value when match is successful.  
	Temp.RemoveAll([](const FJson &Entry)  
	{  
		return Entry.FieldName.Contains("i");  
	});  
	  
	// Find a json value when match is successful.  
	FJson Result;  
	Temp.Find([](const FJson &Entry)  
	{  
		return Entry.FieldName == "Name";  
	}, Result);  
	  
	// Find a json value when match is successful.  
	Result = Temp.Find([](const FJson &Entry)  
	{  
		return Entry.FieldName == "Name";  
	});  
