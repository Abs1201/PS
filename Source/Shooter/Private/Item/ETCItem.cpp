// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ETCItem.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"


AETCItem::AETCItem()
{
    ETCItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ETCItemMesh"));
	SetRootComponent(ETCItemMesh);

	GetCollisionBox()->SetupAttachment(GetRootComponent());
	GetPickupWidget()->SetupAttachment(GetRootComponent());
	GetAreaSphere()->SetupAttachment(GetRootComponent());
}

void AETCItem::SetItemProperties(EItemState State)
{
    Super::SetItemProperties(State);
	switch (State)
	{
	case EItemState::EIS_Pickup:
		// Set mesh properties
		ETCItemMesh->SetSimulatePhysics(false);
		ETCItemMesh->SetEnableGravity(false);
		ETCItemMesh->SetVisibility(true);
		ETCItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ETCItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	case EItemState::EIS_Equipped:
		// Set mesh properties
		ETCItemMesh->SetSimulatePhysics(false);
		ETCItemMesh->SetEnableGravity(false);
		ETCItemMesh->SetVisibility(true);
		ETCItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ETCItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	case EItemState::EIS_Falling:
		// Set mesh properties
		ETCItemMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		ETCItemMesh->SetSimulatePhysics(true);
		ETCItemMesh->SetEnableGravity(true);
		ETCItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ETCItemMesh->SetCollisionResponseToChannel(
			ECollisionChannel::ECC_WorldStatic,
			ECollisionResponse::ECR_Block);
		break;
	case EItemState::EIS_EquipInterping:
		// Set mesh properties
		ETCItemMesh->SetSimulatePhysics(false);
		ETCItemMesh->SetEnableGravity(false);
		ETCItemMesh->SetVisibility(true);
		ETCItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ETCItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	}
}


void AETCItem::EnableCustomDepth()
{
    ETCItemMesh->SetRenderCustomDepth(true);
}

void AETCItem::DisableCustomDepth()
{
    ETCItemMesh->SetRenderCustomDepth(false);
}
