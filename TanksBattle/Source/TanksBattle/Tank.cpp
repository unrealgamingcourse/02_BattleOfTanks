// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetWorld()->DeltaTimeSeconds;

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	/*
		InputComponent->BindAction("Turret_Rotate", IE_Pressed, this, &ATank::RotateTurret);
		InputComponent->BindAction("Turret_Rotaten", IE_Pressed, this, &ATank::RotateTurretn);
	*/
	
	InputComponent->BindAxis("Turret_Rotate", this, &ATank::TurretRotate);
	InputComponent->BindAxis("Barrel_Rotate", this, &ATank::BarrelRotate);
	InputComponent->BindAxis("Move_Tank", this, &ATank::TankMove);
	InputComponent->BindAxis("Rotate_Tank", this, &ATank::TankRotate);
}

/*
	void ATank::RotateTurret()
	{
		UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent called!"));
		Turret->SetRelativeRotation(FRotator(0,45.0f,0));
	}

	void ATank::RotateTurretn()
	{
		Turret->SetRelativeRotation(FRotator(0, -45.0f, 0));
	}

*/

void ATank::TurretRotate(float speed)
{
	if (!Turret)
	{
		return;
	}
	
	// PREVIOUSLY THIS METHOD WAS USED.

	//Turret->AddRelativeRotation(FRotator(0, speed, 0));

	float Rotation = GetWorld()->DeltaTimeSeconds*speed*RotationSpeed;
	Turret->AddRelativeRotation(FRotator(0, Rotation, 0));

}

void ATank::BarrelRotate(float speed)
{
	if (!Barrel)
	{
		return;
	}

	// PREVIOUSLY THIS METHOD WAS USED.

	//Barrel->AddRelativeRotation(FRotator(speed, 0, 0));
	float Rotation = GetWorld()->DeltaTimeSeconds*speed*RotationSpeed;
	Barrel->AddRelativeRotation(FRotator(Rotation, 0, 0));
}

void ATank::TankMove(float speed)
{
	if (!Tank)
	{
		return;
	}

	float Distance = GetWorld()->DeltaTimeSeconds*speed*MovementSpeed;

	Tank->AddRelativeLocation(Tank->GetForwardVector()*Distance);
}

void ATank::TankRotate(float speed)
{
	if (!Tank)
	{
		return;
	}

	// PREVIOUSLY THIS METHOD WAS USED.

	//Tank->AddRelativeRotation(FRotator(0, speed, 0));

	float Rotation = GetWorld()->DeltaTimeSeconds*speed*RotationSpeed;
	Tank->AddRelativeRotation(FRotator(0, Rotation, 0));
}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	if (!TurretFromBP)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor called!"));

	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{
	if (!BarrelFromBP)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SetBarrelChildActor called!"));

	Barrel = BarrelFromBP;
}

void ATank::SetTankChildActor(UChildActorComponent * TankFromBP)
{
	if (!TankFromBP)
	{
		return;
	}
	Tank = TankFromBP;
}


