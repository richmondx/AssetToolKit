// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetToolKitRuntimePrivatePCH.h"
#include "AssetPakExecuteStreamer.h"
#include "AssetExecutePakFile.h"

ASceneAssetManager* UAssetExecutePakFile::m_Man = nullptr;

void UAssetExecutePakFile::ExecutePakFile()
{
	FAssetPakExecuteStreamer* stream = new FAssetPakExecuteStreamer();
	FStreamableManager BaseLoader;
	stream->Initialize(&BaseLoader);
	stream->StreamPackage("test1", new FAssetStreamerListener(), TEXT(""));
}

void UAssetExecutePakFile::SetSceneManage(ASceneAssetManager* Man) 
{
	m_Man = Man;
}
