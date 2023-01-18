// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Xe.generated.h"
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class STANDFORD_API AXe : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AXe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere) USpringArmComponent* cespringarm;
	UPROPERTY(VisibleAnywhere) UCameraComponent* cecamera;
	void MoveForward(float value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to inputs
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
