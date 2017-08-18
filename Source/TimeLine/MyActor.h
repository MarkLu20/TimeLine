// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
//#include "MyActor.generated.h"

#include "MyActor.generated.h"

UCLASS()
class TIMELINE_API AMyActor : public AActor
{
	GENERATED_BODY()
		//virtual void PostInitializeComponents() override;
	/*UPROPERTY()
	
		class Uscenecomponent *Root;*/

	UStaticMeshComponent *RootStatic;
//UStaticMeshComponent *Root;
	//UPROPERTY(EditAnyWhere)
		//class UPaperSpriteComponent *SpriteMoveblePlatform;
	//UPROPERTY()
		//Uclass UPaperSprite *SoureMoveblePlatform;


	/*UPROPERTY()
		UUserWidget* WidgetInstance;*/
	UPROPERTY(EditAnyWhere, Category = "PlatformControls")
		FVector EndLocation;
	UPROPERTY(EditAnyWhere, Category = "PlatformControls")
	FVector InitialLcation;
	FVector location;
	UPROPERTY(EditAnyWhere, Category = "PlatformControls")
		float TravelTimeInSeconds;
	UPROPERTY(EditAnyWhere, Category = "PlatformControls")
		float StopDelay = 0.0f;
	UPROPERTY(EditAnyWhere, Category = "PlatformControls")
		bool bTestEndloaction = false;
	UPROPERTY(EditAnyWhere, Category = "PlatformControls")
		bool bOrientationAxisZ;
	UFUNCTION()
		void MovePlatform(float Value);
	class UCurveFloat *TimeLineCurve;
	FTimeline PlatformTimeline;


	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
