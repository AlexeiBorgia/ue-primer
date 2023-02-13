// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
class UCeAttribute;
class UStaticMeshComponent;
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlashWeapon.generated.h"
UCLASS()
class STANDFORD_API AFlashWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere) UCeAttribute* Attribute;
	UPROPERTY(VisibleAnywhere)	UStaticMeshComponent* Mesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable) void hithandle(AActor* Instigater, UCeAttribute* cmp, float newhealth, float delta);
};
