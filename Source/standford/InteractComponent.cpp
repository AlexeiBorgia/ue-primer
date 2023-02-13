// Fill out your copyright notice in the Description page of Project Settings.
#include "InteractComponent.h"
#include "CeInterface.h"
#include "DrawDebugHelpers.h"
#include <iostream>
// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UInteractComponent::PrimaryInteract() {
	FHitResult hit;
	FVector begin, end;
	AActor* Owner = GetOwner();
	FVector eyelocation;
	FRotator eyerotation;
	FCollisionObjectQueryParams param;
	APawn* mypawn = dynamic_cast<APawn*>(Owner);
	Owner->GetActorEyesViewPoint(eyelocation,eyerotation);
	begin = eyelocation;
	end = mypawn->GetControlRotation().Vector() * 1000 + begin;
	param.AddObjectTypesToQuery(ECC_WorldDynamic);
	TArray<FHitResult>hits;
	FCollisionShape shape;
	shape.SetSphere(30.0f);
	AActor* hitactor=nullptr;
	GetWorld()->SweepMultiByObjectType(hits, begin, end, FQuat::Identity, param, shape);
	if (hits.Num() > 0) { hitactor = hits[hits.Num() - 1].GetActor(); }
	if (hitactor!=nullptr&&hitactor->Implements<UCeInterface>()) {
		ICeInterface::Execute_Interact(hitactor, mypawn);
	}
	DrawDebugLine(GetWorld(), begin, end, FColor::Red,false, 2.0f,0,2.0f);
}

