// Fill out your copyright notice in the Description page of Project Settings.

#include "ludum.h"
#include "Subroom.h"


// Sets default values for this component's properties
USubroom::USubroom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USubroom::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void USubroom::RespondToParent(FTransform parent) 
{
	// set transform relative to parents rotation...
	FTransform transform = GetComponentTransform();
	FTransform newTransform = transform * parent;
	//GetComponentTransform(newTransform);
	SetRelativeTransform(newTransform);
}


// Called every frame
void USubroom::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

