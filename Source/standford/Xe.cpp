// Fill out your copyright notice in the Description page of Project Settings.


#include "Xe.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Math/RotationMatrix.h"
#include "InteractComponent.h"
#include "CeAttribute.h"
#include "Components/CapsuleComponent.h"
//Sets default values
AXe::AXe()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cespringarm = CreateDefaultSubobject<USpringArmComponent>("cesare_springarm");
	cespringarm->SetupAttachment(RootComponent);
	cespringarm->bUsePawnControlRotation = true;
	cespringarm->bInheritPitch = true;
	cespringarm->bInheritRoll = false;
	cespringarm->bInheritYaw = true;
	cecamera = CreateDefaultSubobject<UCameraComponent>("cesare_camera");
	cecamera->SetupAttachment(cespringarm);
	bUseControllerRotationYaw =true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	interactcomp = CreateDefaultSubobject<UInteractComponent>("ineractcmp");
	attribute = CreateDefaultSubobject<UCeAttribute>("attributecmp");
	dynamic_cast<UPrimitiveComponent*>(RootComponent)->SetCollisionObjectType(ECC_WorldDynamic);
	GetMesh()->SetSimulatePhysics(false);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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
	PlayerInputComponent->BindAxis("MoveRight", this, &AXe::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AXe::AddControllerYawInput);
	PlayerInputComponent->BindAxis("pitch", this, &AXe::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("roll", this, &AXe::AddControllerRollInput);
	PlayerInputComponent->BindAction("PrimaryAttack",IE_Pressed,this,&AXe::launchattack);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AXe::PrimaryInteract);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AXe::Jump);
}
void AXe::MoveForward(float value) {
	FRotator cont = GetControlRotation();
	cont.Pitch = 0;
	cont.Roll = 0;
	AddMovementInput(cont.Vector(), value);
}
void AXe::MoveRight(float value) {
	FRotator cont = GetControlRotation();
	GetMesh();
	cont.Pitch = 0;
	cont.Roll = 0;
	AddMovementInput(FRotationMatrix(cont).GetUnitAxis(EAxis::Y), value);
	//cespringarm->GetRightVector();
	AddMovementInput(GetActorRightVector(),value);
}
void AXe::launchattack() {
	PlayAnimMontage(Attackanim);
	FVector Location = GetMesh()->GetSocketLocation("head");
	FTransform trans(GetActorRotation(), Location);
	FActorSpawnParameters para;
	para.Instigator = this;
	para.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(attackmethodinfo, trans, para);
}
void AXe::PrimaryInteract() {
	interactcomp->PrimaryInteract();
}
