// Fill out your copyright notice in the Description page of Project Settings.


#include "Xe.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
// Sets default values
AXe::AXe()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cespringarm = CreateDefaultSubobject<USpringArmComponent>("cesare_springarm");
	cespringarm->SetupAttachment(RootComponent);
	cecamera = CreateDefaultSubobject<UCameraComponent>("cesare_camera");
	cecamera->SetupAttachment(cespringarm);
}

// Called when the game starts or when spawned
void AXe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, & AXe::MoveForward);
}
void AXe::MoveForward(float value) {
	AddMovementInput(GetActorForwardVector(), value);
}
