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

	void SetLocalTransform(AActor* parent);

	//TODO: in future will need relative space to each parent...
	// on every rotation will need to reregister each block with parents so they know who to rotate with
	// each subroom will need a struct with each parent and transform... then when the face starts turning maybe there is an event broadcasted so each subroom knows which transform to base theirs off
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FaceControl", meta = (AllowPrivateAccess = "true"))
	AActor* Parent;

	FTransform LocalTransform;
};
