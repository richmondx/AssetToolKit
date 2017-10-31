/**
@ 类描述
@Author TeenWolf
@Email  731796991@qq.com
@Date   2017-10-28 14:45:06
*/


#pragma once
#include "Engine/MeshMerging.h"
#include "BatchLODSetting.generated.h"

USTRUCT(BlueprintType)
struct FLODSetting
{
	GENERATED_USTRUCT_BODY()
	
	/** Percentage of triangles to keep. 1.0 = no reduction, 0.0 = no triangles. */
	UPROPERTY(EditAnywhere, Category = ReductionSettings)
		float PercentTriangles;

	/** Higher values reduce texture stretching. */
	UPROPERTY(EditAnywhere, Category = ReductionSettings)
		TEnumAsByte<EMeshFeatureImportance::Type> TextureImportance = EMeshFeatureImportance::Type::Normal;

	/** Higher values try to preserve normals better. */
	UPROPERTY(EditAnywhere, Category = ReductionSettings)
		TEnumAsByte<EMeshFeatureImportance::Type> ShadingImportance = EMeshFeatureImportance::Type::Normal;
};


UCLASS(config = Engine, defaultconfig, meta = (DisplayName = "BatchLOD"))
class BATCHLODTOOL_API UBatchLODSetting : public UObject
{
	GENERATED_UCLASS_BODY()

		UPROPERTY(config, EditAnywhere, Category = "LOD-Percent%1 - %100")
		TArray<FLODSetting>  ReductionSettings;

};