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
	//SetLocalTransform();
	// ...
	
}

void USubroom::SetLocalTransform(USceneComponent* parent) 
{
	UE_LOG(LogTemp, Log, TEXT("Trying to set local transform"));
	if (parent != NULL) {
		// set local position relative to parents transform
		UE_LOG(LogTemp, Log, TEXT("local transform set"));
		Parent = parent;
		FTransform transform = GetAttachParent()->GetComponentTransform();
		LocalTransform = transform.GetRelativeTransform(Parent->GetComponentTransform());
	}
}

void USubroom::RespondToParent(FTransform parent) 
{
	// HERE HERE HERE
	// each subroom needs a local space relative to parent
	// then when the parent rotates, the subroom multiplies the rotation by its LOCAL space, not the world space
	// it needs to maintain it's local space within the parent basically
	// gameobject takes its space relative to parent every frame but converts it to world space and sets its world space to that...
	// HERE HERE HERE

	// set transform relative to parents rotation...
	FTransform transform = GetAttachParent()->GetComponentTransform();
	// get the transform relative to the faces (this objects coordinate space in relation to the face)
	FTransform inverted = transform.GetRelativeTransform(parent);
	// now take the parents rotation and apply it to this object in that relative space (with the origin at the parent)
	FTransform newTransform;
	FTransform::Multiply(&newTransform, &parent, &inverted);
	//GetComponentTransform(newTransform);
	GetAttachParent()->SetWorldTransform(newTransform);
	//SetWorldTransform(newTransform);
}

//Object::GetLocalToWorldMatrix(void) {
//	// mLocalToParentMatrix is an object of type "Matrix"	
//	if(GetParent())	{	
//		return matrixMultiply(GetParent()->GetLocalToWorldMatrix(), mLocalToParentMatrix);	
//	}	
//	return mLocalToParentMatrix;
//}


// Called every frame
void USubroom::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (Parent != NULL)
	{
		UE_LOG(LogTemp, Log, TEXT("Setting relative transform........."));
		FTransform parentTransform = Parent->GetComponentTransform();
		UE_LOG(LogTemp, Log, TEXT("x: %lf "), parentTransform.GetRotation().X);
		// find desired position in world space given parent transform....
		FTransform desiredRelativeTransform = LocalTransform * parentTransform;
		GetAttachParent()->SetWorldTransform(desiredRelativeTransform);
	}
}

