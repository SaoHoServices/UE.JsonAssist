# UE.JsonAssist
JsonAssist Plugin Documentation
  
Example:  

	// FJson Json = FJson(JsonType.Object);  
	FJson Json = JsonObject();  
	
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
  
	FString Fast = UJsonAssist::Get().FastPrint(Json);  
	FString Full = UJsonAssist::Get().Print(Json);  
  
	FString JsonFile = FPaths::ProjectDir() + "/Json.json";  
	UJsonAssist::FileWrite(JsonFile, Full);  
  
	FJson Temp = UJsonAssist::Get().Parse(UJsonAssist::FileRead(JsonFile));  
