// Fill out your copyright notice in the Description page of Project Settings.


#include "magicimpact.h"
#include "Components/SphereComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"
#include "particles/ParticleSystemComponent.h"
#include "CeAttribute.h"
// Sets default values
Amagicimpact::Amagicimpact()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spherecmp = CreateDefaultSubobject<USphereComponent>("spherecmp");
	RootComponent = spherecmp;
	Movecmp = CreateDefaultSubobject<UProjectileMovementComponent>("movementcmp");
	Movecmp->InitialSpeed = 10.0f;
	Movecmp->bRotationFollowsVelocity = true;
	Movecmp->bInitialVelocityInLocalSpace = true;
	//UMovementComponent* mvcmp;
	/*Movecmp2 = CreateDefaultSubobject<UProjectileMovementComponent>("movementcmp2");
	Movecmp2->InitialSpeed = 2.0f;
	Movecmp2->bRotationFollowsVelocity = true;
	Movecmp2->bInitialVelocityInLocalSpace = true;*/
	effectcmp = CreateDefaultSubobject<UParticleSystemComponent>("effectcmp");
	effectcmp->SetupAttachment(RootComponent);
	spherecmp->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	spherecmp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	spherecmp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	spherecmp->OnComponentBeginOverlap.AddDynamic(this, &Amagicimpact::OnActorOverlap);
}

// Called when the game starts or when spawned
void Amagicimpact::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Amagicimpact::Tick(float DeltaTime){
	//spherecmp->MoveComponent(FVector(1,0 ,0), FRotator(0, 0, 0), false);
	Super::Tick(DeltaTime);
}
void Amagicimpact::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor) {
		UCeAttribute*attri=dynamic_cast<UCeAttribute * >(OtherActor->GetComponentByClass(UCeAttribute::StaticClass()));
		if (attri) {
			attri->ApplyHealthChange(-20.0f);
			Destroy();
		}
	}

}