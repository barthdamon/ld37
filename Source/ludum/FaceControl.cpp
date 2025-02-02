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
	LoopTime = 5;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UFaceControl::OnTimer, LoopTime, true);
	Destination = GetComponentTransform();

	SetSubroomsParent();


}

void UFaceControl::SetSubroomsParent()
{
	for (int i = 0; i < RegisteredSubrooms.Num(); i++)
	{
		RegisteredSubrooms[i]->FindComponentByClass<USubroom>()->SetLocalTransform(this);
	}
}

void UFaceControl::RotateFaceForInput(int input) {
	//UE_LOG(LogTemp, Log, TEXT("Rotating face for input"));
	FTransform transform = GetComponentTransform();
	FQuat currentRotation = transform.GetRotation();
	FQuat inputRotation = FQuat::MakeFromEuler(FVector(90, 0, 00));
	transform.SetRotation(currentRotation * inputRotation);
	Destination = transform;
	RotateSubroomsForInput(input);
}

void UFaceControl::RotateSubroomsForInput(int input) 
{
	// initialize new array for ending positions
	TArray<AActor*> newPositions;
	newPositions.SetNum(RegisteredSubrooms.Num());

//	FRotator inputRotation = FRotator(0, 0, input * 90);

	// for each subroom in registry
	for (int i = 0; i < RegisteredSubrooms.Num(); i++) 
	{
		//FTransform transform = GetComponentTransform();
		//USubroom* subroom = RegisteredSubrooms[i]->FindComponentByClass<USubroom>();
		//subroom->RespondToParent(transform);

		//rotate cube around face's transform
		//FTransform subroomTransform = RegisteredSubrooms[i]->GetTransform();

		//FVector location = transform.GetLocation();
		//UE_LOG(LogTemp, Log, TEXT("x: %lf y: %lf z: %lf"), location.X, location.Y, location.Z);

		//FRotationAboutPointMatrix translation = FRotationAboutPointMatrix(inputRotation, location);

		//FMatrix locationMatrix = FTranslationMatrix(subroomTransform.GetLocation());

		//FMatrix finalMatrix = locationMatrix * translation;
		////FMatrix finalMatrix = translation;
		//UE_LOG(LogTemp, Log, TEXT("Setting final matrix"));
		//FTransform newTransform;
		//newTransform.SetFromMatrix(finalMatrix);

		//LerpSubroom(RegisteredSubrooms[i], newTransform);
		//RegisteredSubrooms[i]->SetActorTransform(newTransform);

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

void UFaceControl::LerpSubroom_Implementation(AActor* subroom, FTransform destination)
{
	// default implementation outside blueprint
	// get this gameobject center point
	// rotate subroom around center point by 90 degrees * input
}

void UFaceControl::LerpFace_Implementation(FTransform destination)
{
	// default implementation outside blueprint
	// rotate the face so other objects can subscribe
}

void UFaceControl::OnTimer() 
{
	UE_LOG(LogTemp, Log, TEXT("Timer Run"));
	//RotateSubroomsForInput(1);
	RotateFaceForInput(1);
}


// Called every frame
void UFaceControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//for (int i = 0; i < RegisteredSubrooms.Num(); i++)
	//{
	//	// get where the component was relative to this object... then every tick apply the new coordinate space to it. Apply the change in this objects coordinate space to the object basically...
	//	FTransform transform = GetComponentTransform();
	//	USubroom* subroom = RegisteredSubrooms[i]->FindComponentByClass<USubroom>();
	//	subroom->RespondToParent(transform);
	//}
	// ...
}

