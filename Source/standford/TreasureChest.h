// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CeInterface.h"
#include "TreasureChest.generated.h"
UCLASS()
class STANDFORD_API ATreasureChest : public AActor,public ICeInterface
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) float flipargument;
public:	
	// Sets default values for this actor's properties
	ATreasureChest();
	void Interact_Implementation(APawn* intigator);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)	UStaticMeshComponent* base;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)	UStaticMeshComponent* lid;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
