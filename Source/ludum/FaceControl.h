// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Subroom.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "FaceControl.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LUDUM_API UFaceControl : public USceneComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UFaceControl();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void RotateSubroomsForInput(int input);

	void RotateFaceForInput(int input);

	void OnTimer();

	float LoopTime;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Subroom")
	void LerpSubroom(AActor* subroom, FTransform destination);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Face")
	void LerpFace(FTransform destination);


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FaceControl", meta = (AllowPrivateAccess = "true"))
	bool bTestBool;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FaceControl", meta = (AllowPrivateAccess = "true"))
	FTransform Destination;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FaceControl", meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> RegisteredSubrooms;
};
