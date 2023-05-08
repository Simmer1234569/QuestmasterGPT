// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class QuestmasterEditorTarget : TargetRules
{
	public QuestmasterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		bUseUnityBuild = false;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_2;
		ExtraModuleNames.Add("Questmaster");
	}
}
