// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKSBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent *TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent *BarrelFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent *TankFromBP);
	

private:

	/*
		void RotateTurret();
		void RotateTurretn();
	*/
	void TurretRotate(float speed);
	void BarrelRotate(float speed);
	void TankMove(float speed);
	void TankRotate(float speed);
	UChildActorComponent *Tank = nullptr;
	UChildActorComponent *Turret = nullptr;
	UChildActorComponent *Barrel = nullptr;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 120.f;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 120.f;
};
