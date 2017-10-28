#include "BatchLODFactory.h"
#include "BatchLODTool.h"

UBatchLODFactory::UBatchLODFactory(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UObject::StaticClass();
}

UObject* UBatchLODFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	FBatchLODToolModule& BatchLODModule = FModuleManager::LoadModuleChecked<FBatchLODToolModule>("BatchLODTool");
	TArray<FAssetData> assets = BatchLODModule.GetSelectedAssetDatas();
	return nullptr;
}
