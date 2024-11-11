// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
    
   
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	

    AActor* Actor = GetAccecptableActor();
	if (Actor != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("unlocking"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Relocking"));
	}
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}


AActor* UTriggerComponent::GetAccecptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag))
		{
			return Actor;
		}
	}
	return nullptr;
}