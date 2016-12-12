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
	// initialize new array for ending positions
	TArray<AActor*> newPositions;
	newPositions.SetNum(RegisteredSubrooms.Num());

	FRotator inputRotation = FRotator(0, 0, input * 90);

	// for each subroom in registry
	for (int i = 0; i < RegisteredSubrooms.Num(); i++) 
	{
		//rotate cube around face's transform
		FTransform transform = GetComponentTransform();
		FTransform subroomTransform = RegisteredSubrooms[i]->GetTransform();

		FVector location = transform.GetLocation();
		UE_LOG(LogTemp, Log, TEXT("x: %lf y: %lf z: %lf"), location.X, location.Y, location.Z);

		FRotationTranslationMatrix translation = FRotationTranslationMatrix(inputRotation, location);

		FMatrix locationMatrix = FTranslationMatrix(subroomTransform.GetLocation());

		FMatrix finalMatrix = locationMatrix * translation;
		UE_LOG(LogTemp, Log, TEXT("Setting final matrix"));
		FTransform newTransform;
		newTransform.SetFromMatrix(finalMatrix);
		// rotation working, end location not
		RegisteredSubrooms[i]->SetActorTransform(newTransform);

		int index = i;
		index += input;
		//	new index = add/subtract 1 then clamp to 0 and 3
		if (index > 3) {
			index = 0;
		}
		if (index < 0) {
			index = 3;
		}

		//	set cube in new array at new index position
		newPositions[index] = RegisteredSubrooms[i];
	}
	// replace current subroom registry with new position registry
	RegisteredSubrooms = newPositions;

}

void UFaceControl::RotateSubroom_Implementation(AActor* subroom, int input)
{
	// default implementation outside blueprint
	// get this gameobject center point
	// rotate subroom around center point by 90 degrees * input
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

