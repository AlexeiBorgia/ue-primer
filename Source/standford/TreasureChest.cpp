// Fill out your copyright notice in the Description page of Project Settings.


#include "TreasureChest.h"
#include "Components\StaticMeshComponent.h"
// Sets default values
ATreasureChest::ATreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	base = CreateDefaultSubobject<UStaticMeshComponent>("chestbase");
	RootComponent = base;
	lid= CreateDefaultSubobject<UStaticMeshComponent>("lid");
	lid->SetupAttachment(RootComponent);
	flipargument = 110;
}

// Called when the game starts or when spawned
void ATreasureChest::BeginPlay()
{
	AActor::BeginPlay();
	
}
void ATreasureChest::Interact_Implementation(APawn* Intigator) {
	lid->SetRelativeRotation(FRotator(flipargument, 0, 0));
}
// Called every frame
void ATreasureChest::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
	
}

