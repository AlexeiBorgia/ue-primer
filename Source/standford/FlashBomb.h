// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FlashBomb.generated.h"
class UCeAttribute;
class AActor;
class UStaticMeshComponent;
UCLASS()
class STANDFORD_API AFlashBomb : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFlashBomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere) UCeAttribute* Attribute;
	UPROPERTY(VisibleAnywhere)	UStaticMeshComponent* rootmesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable) void hithandle(AActor* instigate, UCeAttribute*cmp, float newhealth, float delta);
};
