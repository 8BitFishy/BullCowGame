// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{

    HiddenWord = TEXT("phineas");
    Lives = HiddenWord.Len() - 1;
    bGameOver = false;
    PrintLine(TEXT("Hello Player 1"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives + 1);
}

void UBullCowCartridge::EndGame()
{

    bGameOver = true;
    PrintLine(TEXT("Press enter to suck at this again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("WINNER WINNER CHICKEN DINNER!"));
        EndGame();
        return;
    }
    else
    {
        if (Lives > 0)
        {
            --Lives;
            PrintLine(TEXT("WRONG IDIOT!"));
            if (HiddenWord.Len() != Guess.Len())
            {
                PrintLine(TEXT("The word is %i letters long asshole\nI FUCKEN TOLD YOU THAT"), HiddenWord.Len());
            }
            PrintLine(TEXT("You have %i lives remaining"), Lives + 1);
            PrintLine(TEXT("Try again"));
        }

        else
        {
            PrintLine(TEXT("OUT OF LIVES MORON"));
            EndGame();
        }
    }
}