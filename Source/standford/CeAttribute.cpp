// Fill out your copyright notice in the Description page of Project Settings.


#include "CeAttribute.h"

// Sets default values for this component's properties
UCeAttribute::UCeAttribute()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	HealthValue = 100;
	// ...
}


// Called when the game starts
void UCeAttribute::BeginPlay()
{
	UActorComponent::BeginPlay();

	// ...
	
}


// Called every frame
void UCeAttribute::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UActorComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
bool  UCeAttribute::ApplyHealthChange(float Delta) {
	HealthValue += Delta;
	healthhandler.Broadcast(nullptr,this,HealthValue,Delta);
	return true;
}

