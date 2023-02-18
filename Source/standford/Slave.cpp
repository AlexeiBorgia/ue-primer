// Fill out your copyright notice in the Description page of Project Settings.


#include "Slave.h"

// Sets default values
ASlave::ASlave()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASlave::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

