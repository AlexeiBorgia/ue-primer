// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Delegates/DelegateCombinations.h"
#include "CeAttribute.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChange, AActor*, Instigator,UCeAttribute*, cmp, float, newhealth, float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STANDFORD_API UCeAttribute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCeAttribute();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attribute")	float HealthValue;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UPROPERTY(BlueprintAssignable) 
	FOnHealthChange healthhandler;  //binded by UI,used for UI'S Listening;			Better Name:healthchangeEventSocket
	UFUNCTION(BlueprintCallable, Category = "Attribute") bool ApplyHealthChange(float Delta);
		
};
