// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashBomb.h"
#include "CeAttribute.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/Actor.h"
// Sets default values
AFlashBomb::AFlashBomb()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*Attribute = CreateDefaultSubobject<UCeAttribute>("attribute");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	Attribute->healthhandler.AddDynamic(this, &AFlashBomb::hithandle);*/
}

// Called when the game starts or when spawned
void AFlashBomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlashBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFlashBomb::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AFlashBomb::hithandle(AActor* instigate, UCeAttribute* cmp, float newhealth, float Delta) {
	//Mesh->SetScalarParameterValueOnMaterials("GameTime", GetWorld()->GetTimeSeconds());
}

