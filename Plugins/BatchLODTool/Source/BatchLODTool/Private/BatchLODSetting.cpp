#include "BatchLODSetting.h"

UBatchLODSetting::UBatchLODSetting(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	FLODSetting LODSetInit;
	LODSetInit.PercentTriangles = 1;
	LODSetInit.ShadingImportance = EMeshFeatureImportance::Type::Normal;
	LODSetInit.TextureImportance = EMeshFeatureImportance::Type::Normal;
	ReductionSettings.Add(LODSetInit);
}
