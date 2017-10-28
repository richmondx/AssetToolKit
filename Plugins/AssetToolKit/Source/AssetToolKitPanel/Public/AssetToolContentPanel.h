// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SlateBasics.h"
/**
 * 
 */
class  SAssetToolContentPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAssetToolContentPanel)
	{}
	SLATE_EVENT(FSimpleDelegate, OnPluginCreated)
		SLATE_END_ARGS()

	SAssetToolContentPanel();
	~SAssetToolContentPanel();
	
	void Construct(const FArguments& InArgs, TSharedPtr<SDockTab> InOwnerTab);

private:
	

	FSimpleDelegate OnPluginCreated;

	TWeakPtr<SDockTab> OwnerTab;
};
