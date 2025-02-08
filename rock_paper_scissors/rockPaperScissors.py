#!/usr/bin/en Python3

#Linux user presents: Rock, Paper, Scissors The VIDEO GAME

import random
import time
import os

rock = 1
paper = 2
scissors = 3

names = {rock: 'Rock', paper: 'Paper', scissors: 'Scissors'}
rules = {rock: scissors, paper: rock, scissors: paper}

playerScore = 0
computerScore = 0

def center_text(text):
    # Get the terminal width
    terminal_width = os.get_terminal_size().columns
    # Calculate the padding needed to center the text
    padding = (terminal_width - len(text)) // 2
    # Return the centered text with appropriate padding
    return " " * padding + text

def start():
    print(center_text("Let's play a game of Rock, Paper, Scissors."))
    while game():
        pass
    scores()

def game():
    player = move()
    computer = random.randint(1, 3)
    result(player, computer)
    return playAgain()

def move():
    while True:
        player = input(("Rock=1\nPaper=2\nScissors=3\n\nMake a move: "))
        try:
            player = int(player)
            if player in (1, 2, 3):
                return player
        except ValueError:
            pass
        print(center_text("Oops! I didn't understand that. Please enter 1, 2, or 3."))

def result(player, computer):
    time.sleep(3)
    print_result(computer, player)

def print_result(computer, player):
    global playerScore, computerScore
    print(center_text(f"Computer threw {names[computer]}!"))
    if player == computer:
        print(center_text("Tie game."))
    else:
        if rules[player] == computer:
            print(center_text("Your victory has been assured."))
            playerScore += 1
        else:
            print(center_text("The computer laughs as you realise you have been defeated."))
            computerScore += 1

def playAgain():
    answer = input(center_text("Would you like to play again? y/n: "))
    if answer.lower() in ('y', 'yes', 'of course'):
        return answer
    else:
        print(center_text("Thank you very much for playing our game. See you next time!"))
        return False

def scores():
    global playerScore, computerScore
    print(center_text("HIGH SCORES"))
    print(center_text("---------------"))
    print(center_text(f"Player: {playerScore}"))
    print(center_text(f"Computer: {computerScore}"))

if __name__ == '__main__':
    start()