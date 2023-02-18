// Fill out your copyright notice in the Description page of Project Settings.


#include "Master.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
void AMaster::BeginPlay() {
	Super::BeginPlay();
	RunBehaviorTree(btree);
	APawn* p = UGameplayStatics::GetPlayerPawn(this, 0);
	

		GetBlackboardComponent()->SetValueAsVector("Destination", p->GetActorLocation());
	
}