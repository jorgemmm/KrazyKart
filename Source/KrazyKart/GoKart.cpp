// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"

#include "Components/InputComponent.h"

// Sets default values
AGoKart::AGoKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Velmax= |1| * MaxDrivingForce * |1|= MaxDrivingForce
	FVector Force = GetActorForwardVector() * MaxDrivingForce * Acelerador;//Throttle;
	
	FVector Acceleration = Force / Mass;


	Velocity = Velocity + Acceleration * DeltaTime;


	Rotate(DeltaTime);

	Move(DeltaTime);
	//AddActorWorldOffset(Translation, true);
}
void AGoKart::Rotate(float DeltaTime)
{
	float RotatationAngle = MaxDegreePerSecond * DeltaTime* Volante;//SteeringThrow;

	UE_LOG(LogTemp, Warning, TEXT("Giro en Tick: %f "), Volante);
	UE_LOG(LogTemp, Warning, TEXT("RotatationAngle: %f "), RotatationAngle);
	
	FQuat RotationDelta(GetActorUpVector(),FMath::DegreesToRadians( RotatationAngle ));

	//Update Velocity
	Velocity = RotationDelta.RotateVector(Velocity);

	AddActorWorldRotation(RotationDelta);
}
/**UpdateLocationFromVelocity*/
void AGoKart::Move(float DeltaTime)
{
	FVector Translation = Velocity * 100 * DeltaTime;

	FHitResult Hit;
	AddActorWorldOffset(Translation, true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Warning, TEXT("Algo ha bloqueado al al kart"));
		Velocity = FVector::ZeroVector;
		UE_LOG(LogTemp, Warning, TEXT("Velocity: %f "), Velocity.Size());
	}
}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	//PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);
	PlayerInputComponent->BindAxis("MoveY", this, &AGoKart::MoveY);
	PlayerInputComponent->BindAxis("MoveX", this, &AGoKart::MoveX);
}


void AGoKart::MoveForward(float Value)
{
	 Throttle = Value;
	 //Velmax= 1 * 20 * |1| 
	//Velocity = GetActorForwardVector() * 20 * Value;
}

void AGoKart::MoveRight(float Value)
{
	SteeringThrow = Value;
}



void AGoKart::MoveY(float Value)
{

	Acelerador = Value;

	UE_LOG(LogTemp, Warning, TEXT("Acelerador en Input: %f "), Throttle);
}

void AGoKart::MoveX(float Value)
{
	
	Volante = Value;

	UE_LOG(LogTemp, Warning, TEXT("Giro en Input: %f "), Volante);
}
