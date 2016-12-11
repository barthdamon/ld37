// Fill out your copyright notice in the Description page of Project Settings.

#include "ludum.h"
#include "FaceControl.h"


// Sets default values for this component's properties
UFaceControl::UFaceControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bTestBool = true;
	// ...
}


// Called when the game starts
void UFaceControl::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FTimerHandle TimerHandle;
	LoopTime = 2;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UFaceControl::OnTimer, LoopTime, true);


}

void UFaceControl::RotateSubroomsForInput(int input) 
{
	// 
}

void UFaceControl::OnTimer() 
{
	UE_LOG(LogTemp, Log, TEXT("Timer Run"));
	RotateSubroomsForInput(1);
}


// Called every frame
void UFaceControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

