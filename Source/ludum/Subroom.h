// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Subroom.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LUDUM_API USubroom : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USubroom();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//UFUNCTION(BlueprintCallable, Category = "SubroomControl")
	void RespondToParent(FTransform parent);
};
