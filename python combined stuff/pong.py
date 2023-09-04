import pygame
import random

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
BALL_SPEED = 5
PADDLE_SPEED = 10

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Create the game window
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong")

# Define the paddles and ball
paddle_width, paddle_height = 10, 100
paddle1 = pygame.Rect(50, HEIGHT // 2 - paddle_height // 2, paddle_width, paddle_height)
paddle2 = pygame.Rect(WIDTH - 50 - paddle_width, HEIGHT // 2 - paddle_height // 2, paddle_width, paddle_height)
ball = pygame.Rect(WIDTH // 2 - 15, HEIGHT // 2 - 15, 30, 30)
ball_speed_x = BALL_SPEED * random.choice((1, -1))
ball_speed_y = BALL_SPEED * random.choice((1, -1))

# Initialize scores
score1, score2 = 0, 0
font = pygame.font.Font(None, 36)

# Main game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move paddles
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w] and paddle1.top > 0:
        paddle1.y -= PADDLE_SPEED
    if keys[pygame.K_s] and paddle1.bottom < HEIGHT:
        paddle1.y += PADDLE_SPEED
    if keys[pygame.K_UP] and paddle2.top > 0:
        paddle2.y -= PADDLE_SPEED
    if keys[pygame.K_DOWN] and paddle2.bottom < HEIGHT:
        paddle2.y += PADDLE_SPEED

    # Move the ball
    ball.x += ball_speed_x
    ball.y += ball_speed_y

    # Ball collisions with top and bottom walls
    if ball.top <= 0 or ball.bottom >= HEIGHT:
        ball_speed_y = -ball_speed_y

    # Ball collisions with paddles
    if ball.colliderect(paddle1) or ball.colliderect(paddle2):
        ball_speed_x = -ball_speed_x

    # Ball out of bounds
    if ball.left <= 0:
        score2 += 1
        ball = pygame.Rect(WIDTH // 2 - 15, HEIGHT // 2 - 15, 30, 30)
        ball_speed_x = BALL_SPEED * random.choice((1, -1))
        ball_speed_y = BALL_SPEED * random.choice((1, -1))
    if ball.right >= WIDTH:
        score1 += 1
        ball = pygame.Rect(WIDTH // 2 - 15, HEIGHT // 2 - 15, 30, 30)
        ball_speed_x = BALL_SPEED * random.choice((1, -1))
        ball_speed_y = BALL_SPEED * random.choice((1, -1))

    # Clear the screen
    window.fill(BLACK)

    # Draw paddles and ball
    pygame.draw.rect(window, WHITE, paddle1)
    pygame.draw.rect(window, WHITE, paddle2)
    pygame.draw.ellipse(window, WHITE, ball)

    # Draw the score
    score_text = font.render(f"{score1} - {score2}", True, WHITE)
    window.blit(score_text, (WIDTH // 2 - score_text.get_width() // 2, 20))

    # Update the display
    pygame.display.flip()

# Quit Pygame
pygame.quit()
