// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "EnemyShooter.h"
#include "AIController.h"


UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr){
        return EBTNodeResult::Failed;
    }

    AEnemyShooter* EnemyShooter = Cast<AEnemyShooter> (OwnerComp.GetAIOwner()->GetPawn());
    if(EnemyShooter){
        EnemyShooter->Shoot();
    }

    return EBTNodeResult::Succeeded;
}