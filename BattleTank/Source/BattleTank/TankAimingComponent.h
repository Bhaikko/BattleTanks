// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBarrel.h"
#include "TankTurren.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialse(UTankBarrel* BarrelToSet, UTankTurren* TurrentToSet);

	void MoveBarrel(FVector);
	UTankBarrel* Barrel = NULL;
	UTankTurren* Turrent = NULL;


	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();
private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;   //In m/s


	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;



	float ReloadTime = 3;
	double LastTimeFired = 0;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Aiming;

	


	
};
