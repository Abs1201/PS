// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "EnemyShooter.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AEnemyShooter : public AEnemy
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TSubclassOf<class AEnemyShooterGun> EnemyShooterGunClass;

	UPROPERTY()
	AEnemyShooterGun* EnemyShooterGun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Start", meta = (AllowPrivateAccess = "true"))
	bool bIsWakeUp = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Start", meta = (AllowPrivateAccess = "true"))
	bool bIsEndWakeUp = false;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Shoot();

	UFUNCTION(BlueprintCallable)
	void EndWakeUp();

	bool GetIsEndWakeUp(){ return bIsEndWakeUp; }
	bool GetIsWakeUp(){ return bIsWakeUp; }
};
