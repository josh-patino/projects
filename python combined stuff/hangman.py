import random

# List of words for the game (you can expand this list)
words = ["python", "hangman", "deez", "computer", "gaming", "minecraft"]

def choose_word():
    return random.choice(words)

def display_word(word, guessed_letters):
    display = ""
    for letter in word:
        if letter in guessed_letters:
            display += letter
        else:
            display += "_"
    return display

def main():
    word_to_guess = choose_word()
    guessed_letters = []
    attempts = 6  # You can adjust the number of allowed attempts

    print("Welcome to Hangman!")
    
    while attempts > 0:
        print("\nAttempts left:", attempts)
        print(display_word(word_to_guess, guessed_letters))

        guess = input("Guess a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Invalid input. Please enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You've already guessed that letter.")
            continue

        guessed_letters.append(guess)

        if guess in word_to_guess:
            print("Good guess!")
        else:
            print("Incorrect guess.")
            attempts -= 1

        if display_word(word_to_guess, guessed_letters) == word_to_guess:
            print("\nCongratulations! You've guessed the word:", word_to_guess)
            break

    if attempts == 0:
        print("\nSorry, you're out of attempts. The word was:", word_to_guess)

if __name__ == "__main__":
    main()