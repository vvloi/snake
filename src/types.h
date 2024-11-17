#ifndef TYPES_H
#define TYPES_H

#include <time.h> // Include time.h for handling time-related functionalities

// Enum for representing the direction of movement
typedef enum
{
    left,  // Move left
    right, // Move right
    up,    // Move up
    down   // Move down
} Direction;

// Enum for types of food available in the game
typedef enum
{
    standard, // Standard food
    value,    // Value food with higher points
    hidden    // Hidden food that appears occasionally
} FoodType;

// Enum for modifiers applied to the snake or game
typedef enum
{
    slow, // Slows down the snake
    fast, // Speeds up the snake
    life  // Adds an extra life to the player
} Modifier;

// Enum for delay values used for resetting timers
typedef enum
{
    stdStart, // Standard food spawn start delay
    stdEnd,   // Standard food spawn end delay
    valStart, // Value food spawn start delay
    valEnd,   // Value food spawn end delay
    hidStart, // Hidden food spawn start delay
    hidEnd    // Hidden food spawn end delay
} DelayValues;

// Enum for tracking different game statistics
typedef enum
{
    hiscore, // High score
    lives,   // Number of lives left
    score    // Current score
} StatsValues;

// Enum for menu options
typedef enum
{
    startGame, // Start a new game
    settings,  // Open settings menu
    exitGame,  // Exit the game
    resumeGame // Resume a paused game
} Menu;

// Struct for representing a position on the game grid
typedef struct
{
    int x; // X-coordinate
    int y; // Y-coordinate
} Position;

// Struct for tracking the positions of the snake's head and tail
typedef struct
{
    Position pos;    // Current position
    Position oldPos; // Previous position
} EndPos;

// Struct for representing the snake's state
typedef struct
{
    EndPos head;         // Position of the snake's head
    EndPos tail;         // Position of the snake's tail
    Position *seg;       // Array of positions for the snake's body segments
    int segCount;        // Current number of body segments
    int allocatedMemory; // Amount of allocated memory for segments
    int speed;           // Current speed of the snake
    Direction dir;       // Current direction of movement
} Snake;

// Struct for representing food items
typedef struct
{
    Position pos;   // Position of the food
    time_t time;    // Time when the food was spawned
    Modifier mod;   // Modifier applied by the food
    FoodType ftype; // Type of the food
} Eats;

// Struct for managing all food items in the game
typedef struct
{
    Eats standard[15]; // Array of standard food items
    Eats value;        // Value food item
    Eats hidden;       // Hidden food item
    int stdCount;      // Count of standard food items
    int valCount;      // Count of value food items
    int hidCount;      // Count of hidden food items
    int foodToAdd;     // Number of food items to add
    int maxFood;       // Maximum number of food items allowed
} Food;

// Struct for managing game timers
typedef struct
{
    time_t begin, end;           // Start and end time for the timer
    time_t elapsed;              // Total elapsed time
    time_t resetStd, resetVal;   // Timers for resetting standard and value food
    time_t resetHid, resetSpeed; // Timers for resetting hidden food and speed
    time_t resetLife;            // Timer for resetting life modifier
    int delay[6];                // Delay values for different events
} Timer;

// Struct for tracking game statistics
typedef struct
{
    int lives;       // Number of lives remaining
    int score;       // Current score
    int hiscore;     // Highest score achieved
    int lifeAdded;   // Flag for whether a life has been added
    int lifeActive;  // Flag for whether the life modifier is active
    int speedActive; // Flag for whether the speed modifier is active
} Stats;

// Struct for the game window's dimensions
typedef struct
{
    int rows; // Number of rows in the window
    int cols; // Number of columns in the window
} Window;

// Struct for defining the game window's border
typedef struct
{
    int left;   // Left border position
    int right;  // Right border position
    int top;    // Top border position
    int bottom; // Bottom border position
} Border;

#endif /* TYPES_H */
