// Fill out your copyright notice in the Description page of Project Settings.

#include "Jogoexemplo.h"
#include "CharacterExemplo.h"


// Sets default values
ACharacterExemplo::ACharacterExemplo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>
		(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetCapsuleComponent());


	Camera = CreateDefaultSubobject<UCameraComponent>
		(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void ACharacterExemplo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterExemplo::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ACharacterExemplo::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("Move", this, &ACharacterExemplo::Move);
	InputComponent->BindAxis("Side", this, &ACharacterExemplo::MoveSides);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction("Crouch", IE_Pressed, this, &ACharacter::Crouch);
	

}
//Método que movimenta o personagem para frente e para trás.
void ACharacterExemplo::Move(float Value) {
	FVector Foward(1.0f, 0.0f, 0.0f);//X - Y - Z
	AddMovementInput(Foward, Value);

}
//Método que movimenta o personagem para os lados.
void ACharacterExemplo::MoveSides(float Value) {
	FVector Side(0.0f, 1.0f, 0.0f); //X -Y -Z
	AddMovementInput(Side, Value);
}

