// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "magicimpact.generated.h"



UCLASS()
class STANDFORD_API Amagicimpact : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amagicimpact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly) USphereComponent* spherecmp;
	UPROPERTY(VisibleAnywhere)	UProjectileMovementComponent* Movecmp;
	UPROPERTY(VisibleAnywhere)	UParticleSystemComponent* effectcmp;
	UFUNCTION(BlueprintCallable) void OnActorOverlap(UPrimitiveComponent*OverlappedComponent, AActor*OtherActor, UPrimitiveComponent*OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
