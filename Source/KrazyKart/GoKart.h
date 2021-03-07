// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKART_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	FVector GetAirResistance();

	FVector GetFrictionResistance();

	void Rotate(float DeltaTime);

	void Move(float DeltaTime);

	

	/**The mass of the car in (kg)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		float Mass = 1000;
	
	
	/**Acelerador Translation Deprec*/		
	float Throttle;
	/**Vplante Giro Deprec*/
	float SteeringThrow;

	/**Acelerador Translation*/
	float Volante, Acelerador;



	//The force applied to th car when the Throttle is fully down in (N)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		float MaxDrivingForce = 10000.0f;

		/*Minimun Radius of the car turning at the fukk lock (minutes)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		float MinimunTurningRadius = 10.0f;

	//The number of degrees rotated per second at full controll thtow fully in (degrees/s)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		float MaxDegreePerSecond = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		float DragCoefificient = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		float nuCoefificient = .015f;
	
	void MoveForward(float Value); //Deprec

	void MoveRight(float Value);  //Deprec

	void MoveX(float Value);

	void MoveY(float Value);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SettingKart", meta = (AllowPrivateAccess = "true"))
		FVector Velocity = FVector(0.f,0.f,0.f);





};
