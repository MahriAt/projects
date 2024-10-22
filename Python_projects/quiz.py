print ("welcome to quiz")

points = 0
playing = input("Wanna play? ")
if playing.lower() != "yes":
    quit()

print("Okey lets play!")

answer = input("How many colors are there in a rainbow? ")
if answer.lower() == "7":
    print("Correct")
    points += 1
else:
    print("Incorrect :(")
answer = input("Who is the Greek goddess of love? ")
if answer.lower() == "aphrodite":
    print("Correct")
    points += 1
else:
    print("Incorrect :(")
answer = input("Where does rain come from? ")
if answer.lower() == "clouds":
    print("Correct")
    points += 1
else:
    print("Incorrect :(")
answer = input("What is the periodic symbol for oxygen? ")
if answer.lower() == "o":
    print("Correct")
    points += 1
else:
    print("Incorrect :(")
answer = input("What year was Barack Obama elected to the US presidency? ")
if answer.lower() == "2008":
    print("Correct")
    points += 1
else:
    print("Incorrect :(")

print("your total score is", (points))
print("You got", (points / 5) * 100, "%.")
