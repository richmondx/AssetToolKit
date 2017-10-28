/**
@ 类描述
@Author TeenWolf
@Email  731796991@qq.com
@Date   2017-10-28 12:39:18
*/


#pragma once
#include "Factories/Factory.h"
#include "BatchLODFactory.generated.h"

UCLASS()
class BATCHLODTOOL_API UBatchLODFactory : public UFactory
{
   GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

private:

};