#pragma once

#include "SlateBasics.h"

DECLARE_DELEGATE_RetVal(bool, FIsButtonActive)

class SFileButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SFileButton) {}
	SLATE_ARGUMENT(FText, ButtonLabel)
		SLATE_EVENT(FIsButtonActive, OnIsActive)
		SLATE_EVENT(FOnClicked, OnButtonClicked)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);

//	const FSlateBrush* GetButtonBorderImage() const;

	//FLinearColor GetTopbarColor() const;

	FIsButtonActive IsActive;

	FOnClicked OnButtonClicked;
};
