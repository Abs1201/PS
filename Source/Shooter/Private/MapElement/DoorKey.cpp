// Fill out your copyright notice in the Description page of Project Settings.


#include "MapElement/DoorKey.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"

ADoorKey::ADoorKey()
{
    DoorKeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorKeyMesh"));
	SetRootComponent(DoorKeyMesh);

	GetCollisionBox()->SetupAttachment(GetRootComponent());
	GetPickupWidget()->SetupAttachment(GetRootComponent());
	GetAreaSphere()->SetupAttachment(GetRootComponent());
}

void ADoorKey::SetItemProperties(EItemState State)
{
	Super::SetItemProperties(State);
	switch (State)
	{
	case EItemState::EIS_Pickup:
		// Set mesh properties
		DoorKeyMesh->SetSimulatePhysics(false);
		DoorKeyMesh->SetEnableGravity(false);
		DoorKeyMesh->SetVisibility(true);
		DoorKeyMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		DoorKeyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	case EItemState::EIS_Equipped:
		// Set mesh properties
		DoorKeyMesh->SetSimulatePhysics(false);
		DoorKeyMesh->SetEnableGravity(false);
		DoorKeyMesh->SetVisibility(true);
		DoorKeyMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		DoorKeyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	case EItemState::EIS_Falling:
		// Set mesh properties
		DoorKeyMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		DoorKeyMesh->SetSimulatePhysics(true);
		DoorKeyMesh->SetEnableGravity(true);
		DoorKeyMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		DoorKeyMesh->SetCollisionResponseToChannel(
			ECollisionChannel::ECC_WorldStatic,
			ECollisionResponse::ECR_Block);
		break;
	case EItemState::EIS_EquipInterping:
		// Set mesh properties
		DoorKeyMesh->SetSimulatePhysics(false);
		DoorKeyMesh->SetEnableGravity(false);
		DoorKeyMesh->SetVisibility(true);
		DoorKeyMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		DoorKeyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	}
}

void ADoorKey::EnableCustomDepth()
{
	DoorKeyMesh->SetRenderCustomDepth(true);
}

void ADoorKey::DisableCustomDepth()
{
	DoorKeyMesh->SetRenderCustomDepth(false);
}