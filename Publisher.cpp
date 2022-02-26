// Copyright (C) 2021 MoonStudio, Inc.All Rights Reserved.


#include "Publisher.h"
#include "JsonAssist.h"
#include "Misc/Paths.h"

void APublisher::BeginPlay()
{
	Super::BeginPlay();

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

	FString Fast = UJsonAssist::Get().FastPrint(Json);
	FString Full = UJsonAssist::Get().Print(Json);

	FString JsonFile = FPaths::ProjectDir() + "/Json.json";
	UJsonAssist::FileWrite(JsonFile, Full);

	FJson Temp = UJsonAssist::Get().Parse(UJsonAssist::FileRead(JsonFile));

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Full);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Fast);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, Json["Name"]);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, Temp["Members"][0]);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, Temp["Members"][1]);
}