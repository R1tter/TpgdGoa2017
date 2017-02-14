// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CharacterExemplo.generated.h"

UCLASS()
class JOGOEXEMPLO_API ACharacterExemplo : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterExemplo();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:

	UPROPERTY(EditAnywhere)
    USpringArmComponent* CameraBoom;
	//Ajusta a câmera ao personagem.


	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	//Define a câmera 

	void Move(float Value);

	void MoveSides(float Value);

	void ToggleCrouch();

	
};
