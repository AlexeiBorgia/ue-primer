/*// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemChest.h"
// Sets default values
AItemChest::AItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	base = CreateDefaultSubobject<UStaticMeshComponent>("chestbody");
	RootComponent = base;
	lid = CreateDefaultSubobject< UStaticMeshComponent>("chestlid");
	lid->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemChest::BeginPlay()
{
	AActor::BeginPlay();
	
}
/*void AItemChest::Interact_Implementation(APawn* Intigator) {

}*/
// Called every frame
/*void AItemChest::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

}*/

