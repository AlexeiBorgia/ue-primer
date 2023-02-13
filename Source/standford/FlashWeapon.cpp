// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashWeapon.h"
#include "CeAttribute.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AFlashWeapon::AFlashWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	Attribute = CreateDefaultSubobject<UCeAttribute>("attribute");
	Attribute->healthhandler.AddDynamic(this, &AFlashWeapon::hithandle); 
}

// Called when the game starts or when spawned
void AFlashWeapon::BeginPlay()
{
	AActor::BeginPlay();
}

// Called every frame
void AFlashWeapon::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
}
void AFlashWeapon::hithandle(AActor* Instigater, UCeAttribute* cmp, float newhealth, float delta) {
	Mesh->SetScalarParameterValueOnMaterials("GameTime", GetWorld()->GetTimeSeconds());
	Mesh->SetScalarParameterValueOnMaterials("rem", 0.5);
}
