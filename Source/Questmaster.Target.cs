// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class QuestmasterTarget : TargetRules
{
	public QuestmasterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		bUseUnityBuild = false;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("Questmaster");
	}
}
