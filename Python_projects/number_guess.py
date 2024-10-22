import random

top_of_the_range = input("Type a number: ")

if top_of_the_range.isdigit():
    top_of_the_range = int(top_of_the_range)
    
    if top_of_the_range <= 0:
        print("Please write a positive number next time")
        quit()
else:
    print("Please write a number next time")
    quit()

random_number = random.randint(0, top_of_the_range)
guesses = 0

while True:
    guesses += 1
    user_guess = input("Make a guess: ")
    if user_guess.isdigit():
        user_guess = int(user_guess)
    else:
        print("please write a number next time")
        continue

    if user_guess == random_number:
        print("You got it!")
        break
    elif user_guess > random_number:
        print("You were above the number")
    else:
        print("You were belove the number")

print("You got it in", guesses, "gyesses")