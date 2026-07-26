import random

# Generate a random number between 1 and 10
secret_number = random.randint(1, 10)

# Keep asking until the user guesses correctly
while True:
    guess = int(input("Guess a number between 1 and 10: "))
    
    if guess > secret_number:
        print("Your guess is too high. Try again!")
    elif guess < secret_number:
        print("Your guess is too low. Try again!")
    else:
        print("🎉 Congratulations! You guessed the number.")
        break  # Stops the loop when the guess is correct