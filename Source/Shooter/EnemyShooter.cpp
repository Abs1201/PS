// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShooter.h"
#include "EnemyShooterGun.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyShooter::BeginPlay()
{
    Super::BeginPlay();

    EnemyShooterGun = GetWorld()->SpawnActor<AEnemyShooterGun>(EnemyShooterGunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
    if(EnemyShooterGun){
        EnemyShooterGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	    EnemyShooterGun->SetOwner(this);
    }


    if(EnemyController){
        if(EnemyController->GetBlackboardComponent()){
            if(EnemyController->GetPawn()){
                EnemyController->GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), EnemyController->GetPawn()->GetActorLocation());
            }
            
        }
    }
	
}

void AEnemyShooter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AEnemyShooter::Shoot()
{
    if(EnemyShooterGun){
		EnemyShooterGun->PullTrigger();
	}
}
