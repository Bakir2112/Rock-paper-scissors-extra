#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINNING_SCORE 3

// Shapes
typedef enum {
    ROCK = 1,
    PAPER,
    SCISSORS,
    LIZARD,
    SPOCK
} Shape;

// Function to print shape name
const char* shape_name(Shape s) {
    switch(s) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        case LIZARD: return "Lizard";
        case SPOCK: return "Spock";
        default: return "Unknown";
    }
}

// Function to check who wins
// Returns: 0 = tie, 1 = player wins, -1 = agent wins
int check_winner(Shape player, Shape agent) {
    if (player == agent) return 0;

    if ((player == ROCK && (agent == SCISSORS || agent == LIZARD)) ||
        (player == PAPER && (agent == ROCK || agent == SPOCK)) ||
        (player == SCISSORS && (agent == PAPER || agent == LIZARD)) ||
        (player == LIZARD && (agent == PAPER || agent == SPOCK)) ||
        (player == SPOCK && (agent == ROCK || agent == SCISSORS))) {
        return 1;
    }
    return -1;
}

// Main game loop
void play_game() {
    int player_score = 0, agent_score = 0;

    while (player_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
        int choice;
        printf("\nSelect a shape:\n");
        printf("1) Rock\n2) Paper\n3) Scissors\n4) Lizard\n5) Spock\n> ");
        
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid choice. Try again Dork.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        Shape player = (Shape)choice;
        Shape agent = (Shape)(rand() % 5 + 1);

        printf("You chose %s, Agent chose %s\n", shape_name(player), shape_name(agent));

        int result = check_winner(player, agent);
        if (result == 1) {
            player_score++;
            printf("You win this round, Nerd!\n");
        } else if (result == -1) {
            agent_score++;
            printf("Agent wins this round, better luck next time LOSER!\n");
        } else {
            printf("It's a tie!\n");
        }

        printf("Score => You: %d | Agent: %d\n", player_score, agent_score);
    }

    if (player_score == WINNING_SCORE) {
        printf("\n🎉 You won the game, Nerd!\n");
    } else {
        printf("\n💻 Agent won the game, better luck next time LOSER!\n");
    }
}

// Main menu
int main() {
    srand(time(NULL));

    while (1) {
        printf("\nWelcome to Rock Paper Scissors Lizard Spock!\n");
        printf("(s) Single player\n");
        printf("(e) Exit\n> ");
        
        char option;
        scanf(" %c", &option);

        if (option == 's') {
            play_game();
        } else if (option == 'e') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Try again Dork.\n");
        }
    }
    return 0;
}
