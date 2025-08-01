// Xing He, z5413977, 01/07/2025
// Part 2: Arrays and Functions

#include <stdio.h>

// -----------------------------------------------------------------------------
// Constant Definition
// -----------------------------------------------------------------------------

#define SIZE 5
#define NEBULA_POINTS -10

#define CELESTIAL_BODY_END_SETUP 'q'
#define CELESTIAL_BODY_PLANET 'p'
#define CELESTIAL_BODY_NEBULA 'n'

// -----------------------------------------------------------------------------
// Enum Definition
// -----------------------------------------------------------------------------

enum entity {
    STAR,
    PLANET,
    NEBULA,
    SPACESHIP,
    EMPTY,
};

// -----------------------------------------------------------------------------
// Struct Definition
// -----------------------------------------------------------------------------

struct celestial_body {
    enum entity entity;
    int points;
};

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void print_map(struct celestial_body galaxy[SIZE][SIZE]);
void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]);
void place_player(struct celestial_body galaxy[SIZE][SIZE]);
void place_planets_and_nebula(struct celestial_body galaxy[SIZE][SIZE]);
void place_stars(struct celestial_body galaxy[SIZE][SIZE]);
void print_galaxy_sum(struct celestial_body galaxy[SIZE][SIZE]);

// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------

int main(void) {
    struct celestial_body galaxy[SIZE][SIZE];

    // Initialize the galaxy
    initialise_galaxy(galaxy);

    // Place the planets and nebulae in the galaxy
    place_planets_and_nebula(galaxy);

    // Place the player in the galaxy
    place_player(galaxy);

    // Place the stars in the galaxy
    place_stars(galaxy);

    // Print the galaxy
    print_map(galaxy);

    // Print the sum of the points in the galaxy
    print_galaxy_sum(galaxy);
}

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

// Function prints the map of the galaxy
// 
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void print_map(struct celestial_body galaxy[SIZE][SIZE]) {
    printf("\n---------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|");
            if (galaxy[i][j].entity == SPACESHIP) {
                printf(" X ");
            } else if (galaxy[i][j].entity == EMPTY) {
                printf("   ");
            } else if (galaxy[i][j].entity == STAR) {
                printf(" * ");
            } else if (galaxy[i][j].entity == PLANET) {
                printf(" o ");
            } else if (galaxy[i][j].entity == NEBULA) {
                printf(" # ");
            }
        }
        printf("|\n");
        printf("---------------------\n");
    }
}

// Function to initialize the galaxy
//
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void initialise_galaxy(struct celestial_body galaxy[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            galaxy[i][j].entity = EMPTY;
            galaxy[i][j].points = 0;
        }
    }
    return;
}

// Function to place the player in the galaxy
//
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void place_player(struct celestial_body galaxy[SIZE][SIZE]) {
    int row, col;
    printf("Enter the starting position of the player: ");
    scanf("%d %d", &row, &col);
    while (row < 0 || row >= SIZE || col < 0 || col >= SIZE ||
           galaxy[row][col].entity != EMPTY) {
        printf("Invalid player position!\n");
        printf("Please re-enter the starting position of the player: ");
        scanf("%d %d", &row, &col);
    }
    galaxy[row][col].entity = SPACESHIP;
    galaxy[row][col].points = 0;
    return;
}

// Function to place the planets and nebulae in the galaxy
//
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void place_planets_and_nebula(struct celestial_body galaxy[SIZE][SIZE]) {
    int row;
    int col;
    printf("Enter planets and nebulae: ");
    int points;
    char type;
    scanf(" %c", &type);
    while (type != CELESTIAL_BODY_END_SETUP) {
        scanf(" %d %d", &row, &col);
        if (type == CELESTIAL_BODY_PLANET) {
            scanf("%d", &points);
            galaxy[row][col].entity = PLANET;
            galaxy[row][col].points = points;
        } else if (type == CELESTIAL_BODY_NEBULA) {
            galaxy[row][col].entity = NEBULA;
            galaxy[row][col].points = NEBULA_POINTS;
        }
        scanf(" %c", &type);
    }
    return;
}

// Function to print the sum of the points in the galaxy
//
// Parameters:
// - galaxy: the 2D array representing the galaxy
// 
// returns: nothing
void print_galaxy_sum(struct celestial_body galaxy[SIZE][SIZE]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += galaxy[i][j].points;
        }
    }
    printf("The total points in the galaxy is: %d\n", sum);
}

// Function to place the stars in the galaxy
//
// Parameters:
// - galaxy: the 2D array representing the galaxy
//
// returns: nothing
void place_stars(struct celestial_body galaxy[SIZE][SIZE]) {
    int row;
    int col; 
    int points;
    printf("Enter the position and points of the star(s): \n");
    while(scanf("%d %d %d", &row, &col, &points) == 3) {
        galaxy[row][col].entity = STAR;
        galaxy[row][col].points = points;
    }
}