// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	mesh->SetSimulatePhysics(true);
	RootComponent = mesh;
	forcecmp = CreateDefaultSubobject<URadialForceComponent>("force");
	forcecmp->SetupAttachment(RootComponent);
	forcecmp->SetAutoActivate(false);
	forcecmp->Radius = 750.0f;
	forcecmp->ImpulseStrength = 2500.0f;
	forcecmp->bImpulseVelChange = true;
	mesh->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnMeshHit);
}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void  AExplosiveBarrel::OnMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	forcecmp->FireImpulse();
}

