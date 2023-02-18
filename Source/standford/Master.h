// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class UBehaviorTree;
#include "CoreMinimal.h"
#include "AIController.h"
#include "Master.generated.h"

/**
 * 
 */
UCLASS()
class STANDFORD_API AMaster : public AAIController
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere,Category="AI")UBehaviorTree* btree;
	virtual void BeginPlay() override;
};
