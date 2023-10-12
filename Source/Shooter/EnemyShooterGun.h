// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyShooterGun.generated.h"

UCLASS()
class SHOOTER_API AEnemyShooterGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyShooterGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category="Impact")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, Category="Impact")
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere, Category="Impact")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, Category="Impact")
	USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
	float MaxRange = 10000;
	
	UPROPERTY(EditAnywhere)
	float Damage = 10.f;

	bool GunTrace(FHitResult &Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
