// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class USpringArmComponent;
class UCameraComponent;
class UInteractComponent;
class UAnimMontage;
class UCeAttribute;
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Xe.generated.h"
UCLASS()
class STANDFORD_API AXe : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AXe();
public:
	 void PrimaryInteract();
protected:
	UPROPERTY(VisibleAnywhere)UInteractComponent* interactcomp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere) USpringArmComponent* cespringarm;
	UPROPERTY(VisibleAnywhere) UCameraComponent* cecamera;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly) UCeAttribute* attribute;
	void MoveForward(float value);
	void MoveRight(float value);
	void launchattack();
	FTimerHandle Timer_Attack;
	UPROPERTY(EditAnyWhere,Category="Attack")	UAnimMontage* Attackanim;
	UPROPERTY(EditAnywhere) TSubclassOf<AActor> attackmethodinfo;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to inputs
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
