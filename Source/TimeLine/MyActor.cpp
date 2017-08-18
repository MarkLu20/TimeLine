// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeLine.h"
#include "MyActor.h"
//#include "PaperSpriteComponent.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include"Engine/GameEngine.h"


//void AMyActor::PostInitializeComponents()
//{
//	Super::PostInitializeComponents();
//
//	InitialLcation = GetActorLocation();
//	EndLocation += InitialLcation;
//}

void AMyActor::MovePlatform(float Value)
          

{
	//EndLocation += InitialLcation;
	InitialLcation = FMath::Lerp(InitialLcation, EndLocation, TimeLineCurve->GetFloatValue(Value));
	SetActorRelativeLocation(InitialLcation);
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString::SanitizeFloat(Value));
}

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//ConstructorHelpers::FObjectFinderOptional<UPaperSprite>(TEXT("/Game/Lege.Lege"));
	//SoureMoveblePlatform=
	RootStatic = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("root"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RootAsset(TEXT("/Game/Floor_Mesh.Floor_Mesh")); 
	ConstructorHelpers::FObjectFinder<UCurveFloat>Curve(TEXT("/Game/NewCurveBase.NewCurveBase"));

	//RootComponent = Root;
	if (RootAsset.Succeeded())
	{
		RootStatic->SetStaticMesh(RootAsset.Object);
		RootStatic->SetMobility(EComponentMobility::Movable);
	}
	RootComponent = RootStatic;
	
		if (Curve.Succeeded())
		{
			TimeLineCurve = Curve.Object;
		}
		
		//RootComponent = Root;
		PlatformTimeline = FTimeline{};
		  FOnTimelineFloat InterpFunc{};
	
	InterpFunc.BindUFunction(this,FName("MovePlatform"));
	PlatformTimeline.AddInterpFloat(TimeLineCurve,InterpFunc,FName("PlatformTimeline"));
	

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//UUserWidget
	//WidgetInstance->AddToViewport();
	
	InitialLcation = GetActorLocation();
	PlatformTimeline.PlayFromStart();
	//PlatformTimeline.ReverseFromEnd();
	//float time= GetWorld()->GetTimerManager().
	//PlatformTimeline.SetTimelineFinishedFunc(void(AMyActor::BeginPlay()));
	//UGameplayStatics::GetPlayerController(this,0)->
	
	PlatformTimeline.SetPlayRate(1);
	 

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PlatformTimeline.TickTimeline(DeltaTime);
	

}

