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
