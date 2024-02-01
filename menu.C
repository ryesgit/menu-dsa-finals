#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#define p printf
#define s scanf
#define g gotoxy
#define c cprintf
#define MAX_CARS 5
#define SIZE 10
#define GREEN 2
#define RED 4
#define BLUE 1
#define YELLOW 14
#define MAGENTA 5
#define DARKGRAY 8

typedef struct
{
    int x;
    int y;
} Coords;

void ensquare(int x, int y, int length, int height, char *text)
{
    int i, j;
    g(x, y);
    p("%c", 201);
    for (i = 0; i < length; i++)
    {
        p("%c", 205);
    }
    p("%c", 187);
    for (j = 0; j < height; j++)
    {
        g(x, y + j + 1);
        p("%c", 186);
        for (i = 0; i < length; i++)
        {
            p(" ");
        }
        p("%c", 186);
    }
    g(x, y + j + 1);
    p("%c", 200);
    for (i = 0; i < length; i++)
    {
        p("%c", 205);
    }
    p("%c", 188);
    g(x + 15, y + 1);
    p("%s", text);
}

void loadingScreenForNonGraphical()
{
    int x, y, i, j;

    int color[] = {RED, GREEN, BLUE, YELLOW, MAGENTA};
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

    // rainbow
    x = getmaxx() / 2;
    y = (300) / 2;
    for (i = 80; i < 150; i++)
    {
        sound(i * 100);
        delay(30);
        nosound();
        j = i / 5 - 100;
        setcolor(color[j % 5]);
        arc(x, y, 0, 180, i - 10);
    }
    // LOADING...
    setcolor(WHITE);
    for (i = 35; i < 550; i++)
    {
        line(20 + i, 170, 20 + i, 200);
    }

    for (i = 35; i < 550; i++)
    {
        setcolor(DARKGRAY);
        line(20 + i, 169, 20 + i, 199);
        delay(2);

        setcolor(WHITE);
        settextstyle(SMALL_FONT, 0, 16);
        outtextxy(220, 220, "LOADING");
        delay(3);

        setcolor(rand() % 16);
        settextstyle(SMALL_FONT, HORIZ_DIR, 16);
        outtextxy(390, 220, "...");
        delay(3);
    }
    closegraph();
}

void loadingScreenForGraphical()
{
    int x, y, i, j;

    int color[] = {RED, GREEN, BLUE, YELLOW, MAGENTA};
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

    // rainbow
    x = getmaxx() / 2;
    y = (300) / 2;
    for (i = 80; i < 150; i++)
    {
        sound(i * 100);
        delay(30);
        nosound();
        j = i / 5 - 100;
        setcolor(color[j % 5]);
        arc(x, y, 0, 180, i - 10);
    }
    // LOADING...
    setcolor(WHITE);
    for (i = 35; i < 550; i++)
    {
        line(20 + i, 170, 20 + i, 200);
    }

    for (i = 35; i < 550; i++)
    {
        setcolor(DARKGRAY);
        line(20 + i, 169, 20 + i, 199);
        delay(2);

        setcolor(WHITE);
        settextstyle(SMALL_FONT, 0, 16);
        outtextxy(220, 220, "LOADING");
        delay(3);

        setcolor(rand() % 16);
        settextstyle(SMALL_FONT, HORIZ_DIR, 16);
        outtextxy(390, 220, "...");
        delay(3);
    }
}

// Draw line n times
// After first line, switch to vertical lines and draw n times.
// Use current column, change rows
// After first vertical line, switch to horizontal again.
// Use current row, change columns
// After second horizontal line, switch to vertical but reduce 1 from n

void graph()
{
    int x, y, cpe, ce, ece, ee, me, ie, rem;
    loadingScreenForNonGraphical();
    clrscr();
    // screen
    for (x = 1; x <= 40; x++)
    {
        g(x, 1);
        p(" ");
        g(x, 24);
        p(" ");
    }
    for (y = 1; y <= 24; y++)
    {
        g(1, y);
        p(" ");
        g(40, y);
        p(" ");
    }
    g(1, 1);
    p(" ");
    g(40, 1);
    p(" ");
    g(1, 24);
    p(" ");
    g(40, 24);
    p(" ");
    for (x = 41; x <= 79; x++)
    {
        g(x, 1);
        p(" ");
        g(x, 24);
        p(" ");
    }
    for (y = 1; y <= 24; y++)
    {
        g(41, y);
        p(" ");
        g(79, y);
        p(" ");
    }
    g(41, 1);
    p(" ");
    g(79, 1);
    p(" ");
    g(41, 24);
    p(" ");
    g(79, 24);
    p(" ");
    g(9, 3);
    p("College of Engineering");
    g(14, 4);
    p("SY 2022-2023");
    g(5, 6);
    p("Course        No. of Students");
    g(5, 8);
    p("BSECE");
    g(5, 9);
    p("BSEE");
    g(5, 10);
    p("BSCE");
    g(5, 11);
    p("BSREM");
    g(5, 12);
    p("BSME");
    g(5, 13);
    p("BSIE");
    g(5, 14);
    p("BSCPE");
    // There is a g(22, 8) here formerly
    g(22, 8);
    while (scanf("%i", &ece) != 1 || ece > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 8);
    }
    g(22, 9);
    while (scanf("%i", &ee) != 1 || ee > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 9);
    }
    g(22, 10);
    while (scanf("%i", &ce) != 1 || ce > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 10);
    }
    g(22, 11);
    while (scanf("%i", &rem) != 1 || rem > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 11);
    }
    g(22, 12);
    while (scanf("%i", &me) != 1 || me > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 12);
    }
    g(22, 13);
    while (scanf("%i", &ie) != 1 || ie > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 13);
    }
    g(22, 14);
    while (scanf("%i", &cpe) != 1 || cpe > 30)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        g(5, 22);
        p("Invalid input. Please enter an integer (<= 30): ");
        g(22, 14);
    }
    // graph
    g(46, 5);
    p("ECE");

    for (x = 1; x <= ece; x++)
    {
        g(49 + x, 5);
        p("%c", 219);
    }

    g(46, 7);
    p("EE");

    for (x = 1; x <= ee; x++)
    {
        g(49 + x, 7);
        p("%c", 219);
    }

    g(46, 9);
    p("CE");

    for (x = 1; x <= ce; x++)
    {
        g(49 + x, 9);
        p("%c", 219);
    }

    g(46, 11);
    p("REM");

    for (x = 1; x <= rem; x++)
    {
        g(49 + x, 11);
        p("%c", 219);
    }

    g(46, 13);
    p("ME");

    for (x = 1; x <= me; x++)
    {
        g(49 + x, 13);
        p("%c", 219);
    }

    g(46, 15);
    p("IE");

    for (x = 1; x <= ie; x++)
    {
        g(49 + x, 15);
        p("%c", 219);
    }

    g(46, 17);
    p("CPE");

    for (x = 1; x <= cpe; x++)
    {
        g(49 + x, 17);
        p("%c", 219);
    }

    promptBeforeExit();
}

void drawToScreen(int x, int y)
{
    delay(50);
    g(x, y);
    p("%c", 254);
}

int writeNTimes(int x, int y, int length, int n, int horizontal, int backwards)
{
    // writeNTimes(x, y, 30, 1, 1, 1);
    int iter;

    for (iter = 0; iter < n; iter++)
    {
        int i;
        // Backwards is false
        if (backwards == 0)
        {
            // Horizontal is true
            if (horizontal != 0)
            {
                for (i = 0; i < length; i++)
                {
                    x = x + 1;
                    drawToScreen(x, y);
                }
            }
            else
            {
                // horizontal is false
                for (i = 0; i < length; i++)
                {
                    y = y + 1;
                    drawToScreen(x, y);
                }
            }
        }
        else
        {
            // backwards is true
            if (horizontal == 0)
            {
                for (i = 0; i < length; i++)
                {
                    y = y - 1;
                    drawToScreen(x, y);
                }
            }
            else
            {
                for (i = 0; i < length; i++)
                {
                    x = x - 1;
                    drawToScreen(x, y);
                }
            }
        }
    }

    if (horizontal == 1)
    {
        return x;
    }

    return y;
}

int maze()
{
    int x, y, i, j;
    loadingScreenForGraphical();
    clrscr();
    // 1st loop
    for (x = 1; x <= 79; x++)
    {
        g(x, 1);
        delay(25);
        p("%c", 219);
    }
    for (y = 1; y <= 24; y++)
    {
        g(79, y);
        delay(25);
        p("%c", 219);
    }

    for (x = 79; x >= 1; x--)
    {
        g(x, 24);
        delay(25);
        p("%c", 219);
    }
    for (y = 24; y >= 3; y--)
    {
        g(1, y);
        delay(25);
        p("%c", 219);
    }
    // 2nd loop
    for (x = 1; x <= 77; x++)
    {
        g(x, 3);
        delay(25);
        p("%c", 219);
    }
    for (y = 3; y <= 22; y++)
    {
        g(77, y);
        delay(25);
        p("%c", 219);
    }

    for (x = 77; x >= 3; x--)
    {
        g(x, 22);
        delay(25);
        p("%c", 219);
    }
    for (y = 22; y >= 5; y--)
    {
        g(3, y);
        delay(25);
        p("%c", 219);
    }

    // 3rd loop
    for (x = 4; x <= 73; x++)
    {
        g(x, 5);
        delay(25);
        p("%c", 219);
    }

    for (y = 6; y <= 20; y++)
    {
        g(73, y);
        delay(25);
        p("%c", 219);
    }

    for (x = 73; x >= 7; x--)
    {
        g(x, 20);
        delay(25);
        p("%c", 219);
    }

    for (y = 20; y >= 7; y--)
    {
        g(7, y);
        delay(25);
        p("%c", 219);
    }

    // 4th loop
    for (x = 7; x <= 70; x++)
    {
        g(x, 7);
        delay(25);
        p("%c", 219);
    }

    for (y = 7; y <= 18; y++)
    {
        g(70, y);
        delay(25);
        p("%c", 219);
    }

    for (x = 70; x >= 10; x--)
    {
        g(x, 18);
        delay(25);
        p("%c", 219);
    }

    for (y = 18; y >= 9; y--)
    {
        g(10, y);
        delay(25);
        p("%c", 219);
    }

    // 5th loop
    for (x = 10; x <= 67; x++)
    {
        g(x, 9);
        delay(25);
        p("%c", 219);
    }

    for (y = 10; y <= 16; y++)
    {
        g(67, y);
        delay(25);
        p("%c", 219);
    }

    for (x = 67; x >= 13; x--)
    {
        g(x, 16);
        delay(25);
        p("%c", 219);
    }

    for (y = 16; y >= 11; y--)
    {
        g(13, y);
        delay(25);
        p("%c", 219);
    }

    // 6th loop
    for (x = 13; x <= 64; x++)
    {
        g(x, 11);
        delay(25);
        p("%c", 219);
    }

    for (y = 12; y <= 14; y++)
    {
        g(64, y);
        delay(25);
        p("%c", 219);
    }

    for (x = 64; x >= 16; x--)
    {
        g(x, 14);
        delay(25);
        p("%c", 219);
    }

    for (y = 14; y >= 13; y--)
    {
        g(16, y);
        delay(25);
        p("%c", 219);
    }

    getch();
    closegraph();
    return 0;
}

void squareCubed()
{
    int x, qty;
    char items[15];
    float uprice, amount, totalamount;
    loadingScreenForNonGraphical();
    clrscr();
    ensquare(0, 0, 76, 24, "");
    g(5, 2);
    p("N");

    g(15, 2);
    p("SQUARE");

    g(35, 2);
    p("CUBE");

    for (x = 0; x <= 10; x++)
    {
        g(5, 3 + x);
        p("%d", x);

        g(17, 3 + x);
        p("%d", x * x);

        g(36, 3 + x);
        p("%d", x * x * x);
    }

    promptBeforeExit();
}

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int win();
void board();
int player = 1, i, choice;

char mark;

int ticTacToe()
{
    loadingScreenForNonGraphical();
    clrscr();
    textcolor(YELLOW);

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        g(20, 12);
        printf("\tPlayer %d, enter a number to be marked: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            g(15, 18);
            printf("\t\tInvalid Move! Please input numbers 1 to 9 only \n\t\t\tand numbers that hasn't been marked yet.\n\n\t\t\tPress any key to continue...");

            player--;
            getch();
        }
        i = win();

        player++;
    } while (i == -1);

    board();

    if (i == 1)
        cprintf("        \aPlayer %d won!!!", --player);
    else
        cprintf("        \n\n\aGame Draw");

    promptBeforeExit();

    return 0;
}

/**********************
to check if there's a winner
*********************/
int win()
{
    /*********************
    horizontal points
    *********************/
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    /*********************
    vertical points
    *********************/
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    /*********************
    diagonal points
    *********************/
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

/*****************************
Function for the board
*****************************/
void board()
{

    system("cls");

    cprintf("     \n\nTIC TAC TOE\n\n");

    printf("\tPlayer 1(X) vs. Player 2(O)\n\n\n");

    printf("        |   |   \n");
    printf("      %c | %c | %c \n", square[1], square[2], square[3]);

    printf("     ___|___|___\n");
    printf("        |   |   \n");

    printf("      %c | %c | %c \n", square[4], square[5], square[6]);

    printf("     ___|___|___\n");
    printf("        |   |   \n");

    printf("      %c | %c | %c \n", square[7], square[8], square[9]);

    printf("        |   |   ");
}

typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} LinkedList;

void addNode(LinkedList *list, int value)
{
    LinkedList *currentList = list;
    LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));

    while (currentList->next != NULL)
    {
        currentList = currentList->next;
    }

    newList->value = value;
    newList->next = NULL;
    currentList->next = newList;
}

void printList(LinkedList *list)
{
    LinkedList *currentList = list;
    while (currentList->next != NULL)
    {
        currentList = currentList->next;
        // printf("%i\n", currentList->value);
        p("=========\n");
        p("\tCar %i\t\n", currentList->value);
        p("=========\n");
        // p("\nCar %i\t⣀⣀⣀⣀⣀⣀ ⢀⣀\n\t⣠⠞⢛⡉⠁⣀ ⠹⡁⢻⣿⣿\n⣀⣀⣀⣴⣧⣤⣾⣷⣶⣿⣶⣾⣷⣾⣿⣿\n⠠⠛⢻⣿⣿⣿⣿⣿⣿⣏⣥⣤⣿⡿⢿⣿⣿⡿\n⣿⣿⣿⡉⠛⠛⠛⠉⠉⣠⣿⣿⣿⡇ ⢹⣿⡇\n⠻⣿⣿⣿⣶⣶⣶⣶⣿⣿⣿⣿⣿ ⣼⠿⠷⠃\n⠈⠉⠉⠉⠉⠉\t⠙⠛⠛⠛\t\n", currentList->value);
    }
}

void removeNode(LinkedList *list, int value)
{
    LinkedList *currentList = list;
    LinkedList *previousList = list;

    while (currentList->next != NULL)
    {
        previousList = currentList;
        currentList = currentList->next;
        if (currentList->value == value)
        {
            previousList->next = currentList->next;
            free(currentList);
            return;
        }
    }
}

int sdisplayActions()
{
    int choice;
    p("What do you want to do?\n");
    p("1. Enter a new car\n");
    p("2. Remove a car by index\n");
    p("3. Display cars\n");
    p("4. Exit program\n");
    p("Please enter your choice: ");
    while (scanf("%i", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        p("Invalid input. Please enter an integer: ");
    }
    return choice;
}

void deleteAllCars(LinkedList *carList)
{

    int currentCarValue = carList->value;
    LinkedList *nextCar = carList->next;
    do
    {
        removeNode(carList, currentCarValue);
        carList = nextCar;
        nextCar = carList->next;
    } while (carList->next);
}

void carLink()
{
    LinkedList *carList = (LinkedList *)malloc(sizeof(LinkedList));
    int inProgress = 1;
    loadingScreenForNonGraphical();
    deleteAllCars(carList);

    clrscr();

    while (inProgress == 1)
    {
        int choice;
        clrscr();
        p("Current Car Garage\n");
        printList(carList);
        choice = displayActions();
        inProgress = determineAction(carList, choice);
    }

    promptBeforeExit();
}

typedef struct coords
{
    int x;
    int y;
} coords;

typedef struct Node
{
    char value[4];
    struct Node *left;
    struct Node *right;
    struct coords coords;
} Node;

typedef struct Queue
{
    Node *node;
    struct Queue *next;
} Queue;

void enqueue(Queue *queue, Node *node)
{
    Queue *currentQueue = queue;
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));

    while (currentQueue->next != NULL)
    {
        currentQueue = currentQueue->next;
    }

    newQueue->node = node;
    newQueue->next = NULL;
    currentQueue->next = newQueue;
}

Node *dequeue(Queue *queue)
{
    Node *tempNode;
    Queue *tempQueue;

    if (queue->node == NULL)
    {
        return NULL;
    }

    tempNode = queue->node;
    tempQueue = queue->next;

    if (tempQueue != NULL)
    {
        queue->node = tempQueue->node;
        queue->next = tempQueue->next;
        free(tempQueue);
    }
    else
    {
        queue->node = NULL;
    }

    return tempNode;
}

void addTree(Node *node, char value[4], coords *coords)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coords.x = coords->x;
    newNode->coords.y = coords->y;
    if (node->left == NULL)
    {
        strcpy(newNode->value, value);
        newNode->left = NULL;
        newNode->right = NULL;
        node->left = newNode;
        return;
    }

    if (node->right == NULL)
    {
        strcpy(newNode->value, value);
        newNode->left = NULL;
        newNode->right = NULL;
        node->right = newNode;
        return;
    }
}

int getNumberOfNodes(int numberOfLevels)
{

    int nodes;
    numberOfLevels--;

    if (numberOfLevels < 1)
    {
        nodes = pow(2, numberOfLevels);
    }

    else
    {
        nodes = pow(2, numberOfLevels + 1) - 1;
    }

    return nodes;
}

int log2(int x)
{
    return (int)(log(x) / log(2));
}

int getLevel(int index)
{

    int level;
    index--;

    if (index < 1)
    {
        level = 1;
    }

    else
    {
        level = log2(index) + 1;
    }

    return level;
}

void preOrder(Node *node)
{
    if (node == NULL || node->value[0] == '.')
    {
        return;
    }

    p("%s ", node->value);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == NULL || node->value[0] == '.')
    {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    p("%s ", node->value);
}

void inOrder(Node *node)
{
    if (node == NULL || node->value[0] == '.')
    {
        return;
    }

    inOrder(node->left);
    p("%s ", node->value);
    inOrder(node->right);
}

int isLeft(int index)
{
    return index % 2 == 0;
}

void binaryTree()

{
    int numberOfLevels;
    int nodes;
    int level;
    int presentNodes;
    char value[4];
    char rootValue[4];
    // char temp[2];
    Node *currentNode;
    coords currentNodeCoords;
    coords rootInitialCoords = {40, 5};
    Node root = {NULL, NULL, NULL};
    Queue queue;
    Node rootRight;
    Node rootRightLeft;
    queue.node = &root;
    queue.next = NULL;
    root.coords = rootInitialCoords;
    loadingScreenForNonGraphical();
    clrscr();
    presentNodes = 0;
    g(2, 3);
    p("Number of levels (Maximum of 4):");
    while (scanf("%i", &numberOfLevels) != 1 || numberOfLevels > 4)
    {
        while (getchar() != '\n')
            ;
        p("Invalid input. Please enter an integer (maximum of 4): ");
    }

    nodes = getNumberOfNodes(numberOfLevels);
    g(2, 6);
    p("Number of nodes: %i\n", nodes);

    if (!(nodes <= 0))
    {
        p("Value of root node: ");
        s("%s", &rootValue);

        strcpy(root.value, rootValue);

        currentNode = &root;
        presentNodes++;

        gotoxy(currentNode->coords.x, currentNode->coords.y);
        p("%s", currentNode->value);
        while (presentNodes <= nodes - 1)
        {
            coords newNodeCoords;

            if (currentNode->value[0] == '.')
            {

                currentNodeCoords = currentNode->coords;
                while (currentNode->left == NULL || currentNode->right == NULL)
                {
                    int level = getLevel(presentNodes);
                    if (isLeft(presentNodes + 1) == 1)
                    {
                        newNodeCoords.x = currentNodeCoords.x - (10 / level);
                        newNodeCoords.y = currentNodeCoords.y + 5;
                        gotoxy(newNodeCoords.x, newNodeCoords.y);

                        // Simulate input
                        p(".");
                        addTree(currentNode, ".", &newNodeCoords);

                        enqueue(&queue, currentNode->left);
                        presentNodes++;
                    }
                    else
                    {
                        newNodeCoords.x = currentNodeCoords.x + (10 / level);
                        newNodeCoords.y = currentNodeCoords.y + 5;
                        gotoxy(newNodeCoords.x, newNodeCoords.y);

                        p(".");
                        addTree(currentNode, ".", &newNodeCoords);

                        enqueue(&queue, currentNode->right);
                        presentNodes++;
                    }
                }
            }

            if (currentNode->left == NULL || currentNode->right == NULL)
            {
                // p("Value for node #%i", presentNodes);
                currentNodeCoords = currentNode->coords;
                gotoxy(1, 1);
                level = getLevel(presentNodes);
                if (isLeft(presentNodes + 1) == 1)
                {
                    newNodeCoords.x = currentNodeCoords.x - (10 / level);
                    newNodeCoords.y = currentNodeCoords.y + 5;
                    gotoxy(newNodeCoords.x, newNodeCoords.y);
                }
                else
                {
                    newNodeCoords.x = currentNodeCoords.x + (10 / level);
                    newNodeCoords.y = currentNodeCoords.y + 5;
                    gotoxy(newNodeCoords.x, newNodeCoords.y);
                }
                s(" %s", &value);
                addTree(currentNode, value, &newNodeCoords);
                presentNodes++;
                continue;
            }
            enqueue(&queue, currentNode->left);
            enqueue(&queue, currentNode->right);
            currentNode = dequeue(&queue);
        }

        p("\n");
        p("Preorder: \n");
        preOrder(&root);
        p("\n");
        p("Postorder: \n");
        postOrder(&root);
        p("\n");
        p("Inorder: \n");
        inOrder(&root);
        p("\n");
    }

    getch();
}

int promptBeforeExit()
{
    int keystroke;
    g(23, 19);
    p("Finally, press F to terminate program");

    keystroke = getch();

    while (keystroke != 'F' && keystroke != 'f')
    {
        keystroke = getch();
    }

    clrscr();

    return keystroke;
}

// #endregion

// Car queue
#include <stdio.h>
#include <conio.h>
#define p printf
#define c cprintf
#define s scanf
#define g gotoxy
#define QSIZE 15
int Front = -1;
int Rear = -1;

void clrscr()
{
    system("cls");
}

int isValidCarNumber(int carNumber)
{
    return carNumber > 0 && carNumber <= 9;
}

int isCarExist(int Q[QSIZE], int carNumber)
{
    int i;
    for (i = Front; i <= Rear; i++)
    {
        if (Q[i] == carNumber)
        {
            return 1;
        }
    }
    return 0;
}

void Qenqueue(int Q[QSIZE], int carNumber)
{
    clrscr();

    if (Rear == QSIZE - 1)
    {
        g(25, 11);
        p("Sorry, the garage is full.\n");
        sleep(2);
        return;
    }

    if (isCarExist(Q, carNumber))
    {
        g(6, 11);
        p("Car %d is already in the garage. Please choose a different car number.\n", carNumber);
        sleep(2);
    }
    else
    {
        Rear++;
        Q[Rear] = carNumber;
        g(25, 11);
        p("Car %d has entered the garage.\n", Q[Rear]);
        sleep(2);
    }

    if (Front == -1)
    {
        Front++;
    }
}

void Qdequeue(int Q[QSIZE])
{
    clrscr();

    if (Front < Rear)
    {
        g(25, 11);
        p("Car %d has left the garage.\n", Q[Front]);
        sleep(2);
        Front++;

        if (Front > Rear)
        {
            Front = -1;
            Rear = -1;
        }
    }
    else
    {
        g(30, 11);
        p("Garage is empty.\n");
        sleep(2);
        Front = -1;
        Rear = -1;
    }
}

void display(int Q[QSIZE])
{
    int x;

    clrscr();

    g(2, 3);
    p("==============================================================================\n");
    g(2, 4);
    p("|                              9-CAR GARAGE                                  |\n");
    g(2, 5);
    p("==============================================================================\n");
    g(2, 9);
    p("==============================================================================\n\n");
    g(4, 7);

    if (Front == -1)
    {
        g(29, 7);
        p("Garage Status: EMPTY \n");
        return;
    }

    for (x = Front; x <= Rear; x++)
    {
        p(" Car %d |", Q[x]);
    }
}

int carQueue()
{
    int Q[QSIZE];
    int carNumber, ch;
    int scanfResult;
    int quit = 0;
    loadingScreenForNonGraphical();
    do
    {
        clrscr();
        display(Q);

        g(27, 12);
        p("[1] Car Park\n");
        g(27, 13);
        p("[2] Car Departure\n");
        g(27, 14);
        p("[3] Exit Program\n");
        g(27, 16);
        p("Enter your choice: ");
        scanfResult = s("%d", &ch);
        sleep(1);

        if (ch == 3)
        {
            clrscr();
            g(27, 18);
            promptBeforeExit();
            quit = 1;
            continue;
        }

        if (scanfResult != 1 || (ch < 1 || ch > 2))
        {
            clrscr();
            g(17, 11);
            p("[ERROR] Please choose between 1, 2, and 3 only.\n");
            g(19, 13);
            p("Press any key to continue or 'Q' to exit.\n");
            ch = getch();

            if (ch == 'Q' || ch == 'q')
            {
                clrscr();
                g(27, 23);
                p("Exiting the program.\n");
                quit = 1;
            }
            continue;
        }

        switch (ch)
        {
        case 1:
            display(Q);
            g(23, 11);
            p("Enter Car Number to Park (1-9): ");
            scanfResult = s("%d", &carNumber);
            sleep(1);

            if (!isValidCarNumber(carNumber) || scanfResult != 1 || (carNumber <= 0 || carNumber > 9))
            {
                clrscr();
                g(19, 11);
                p("[ERROR] Please enter a number from 1 to 9.\n");
                g(20, 13);
                p("Press any key to continue or 'Q' to exit.\n");
                ch = getch();

                if (ch == 'Q' || ch == 'q')
                {
                    clrscr();
                    g(18, 16);
                    p("Exiting the program.");
                    exit(0);
                }
                continue;
            }

            Qenqueue(Q, carNumber);
            break;

        case 2:
            display(Q);
            Qdequeue(Q);
            break;

        default:
            clrscr();
            g(20, 16);
            p("Invalid choice. Please enter a valid option.\n");
        }

    } while (!quit);

    return 0;
}

// Car stack
#define MAX_CARS 5
#define p printf

typedef struct
{
    int cars[MAX_CARS];
    int top;
} carStack;

void initializeCarStack(carStack *stack)
{
    stack->top = -1;
}

void addCarToStack(carStack *stack, int carNumber)
{
    if (stack->top < (MAX_CARS - 1))
    {
        int order = (stack->top) + 1;
        stack->cars[order] = carNumber;
        stack->top = order;
        p("Car %i added to stack\n", stack->cars[order]);
    }
    else
    {
        p("Sorry, full garage, can not add anymore vehicles :(");
    }
}

void printAllCarsInStack(carStack *stack)
{
    int i;
    p("Garage:\n");
    for (i = 0; i < (stack->top + 1); i++)
    {
        int carNumber = stack->cars[i];
        p("\n==========================\n");
        p("\nCar %i", carNumber);
        p("\n==========================\n");
    }
}

int pop(carStack *stack)
{
    int indexToRemove = stack->top;
    int valueToRemove = stack->cars[indexToRemove];
    stack->cars[indexToRemove] = NULL;
    stack->top = indexToRemove - 1;
    return valueToRemove;
}

int popByIndex(carStack *stack, int indexToRemove)
{
    int valueToRemove = stack->cars[indexToRemove];
    while (stack->top > indexToRemove - 2)
    {
        pop(stack);
    }
    return valueToRemove;
}

int displayActions()
{
    int choice;
    p("What do you want to do?\n");
    p("1. Enter a new car\n");
    p("2. Remove the latest parked car\n");
    p("3. Display cars\n");
    p("4. Remove a car by index\n");
    p("5. Exit program\n");
    p("Please enter your choice: ");
    while (scanf("%i", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        p("Invalid input. Please enter an integer: ");
    }
    return choice;
}

int determineAction(carStack *stack, int choice)
{
    int out;
    int carNumber;
    int numberToRemove;
    switch (choice)
    {
    case 1:
        p("Input a car number: ");
        while (scanf("%i", &carNumber) != 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            p("Invalid input. Please enter an integer: ");
        }
        addCarToStack(stack, carNumber);
        out = 1;
        break;
    case 2:
        pop(stack);
        out = 1;
        break;
    case 3:
        printAllCarsInStack(stack);
        out = 1;
        break;
    case 4:
        p("Input a car index to remove: ");
        p("(Note: Index starts at 1)\n");
        while (scanf("%i", &numberToRemove) != 1 || numberToRemove > stack->top + 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            p("Invalid input. Please enter an integer, or ensure that integer is within stack range: ");
        }
        popByIndex(stack, numberToRemove);
        out = 1;
        break;
    case 5:
        out = 0;
        break;
    }

    return out;
}

void playCarStack()
{
    int inProgress = 1;
    carStack stack;
    loadingScreenForNonGraphical();
    initializeCarStack(&stack);
    while (inProgress == 1)
    {
        int choice;
        clrscr();
        printAllCarsInStack(&stack);
        choice = displayActions();
        inProgress = determineAction(&stack, choice);
    }
}

// Search Tree
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define p printf
#define s scanf
#define g gotoxy

typedef struct STCoords
{
    int x;
    int y;
} STCoords;

typedef struct STNode
{
    int value;
    int depth;
    struct STNode *left;
    struct STNode *right;
    struct STCoords coords;
} STNode;

struct Tree
{
    struct STNode *root;
};

typedef struct STQueue
{
    STNode *node;
    struct STQueue *next;
} STQueue;

void STtypeOnScreen(int message, int x, int y)
{
    g(x, y);
    p("%i", message);
}

void STenqueue(STQueue *queue, STNode *node)
{
    STQueue *currentQueue = queue;
    STQueue *newQueue = (STQueue *)malloc(sizeof(STQueue));

    while (currentQueue->next != NULL)
    {
        currentQueue = currentQueue->next;
    }

    newQueue->node = node;
    newQueue->next = NULL;
    currentQueue->next = newQueue;
}

STNode *STdequeue(STQueue *queue)
{
    STNode *tempNode;
    STQueue *tempQueue;

    if (queue->node == NULL)
    {
        return NULL;
    }

    tempNode = queue->node;
    tempQueue = queue->next;

    if (tempQueue != NULL)
    {
        queue->node = tempQueue->node;
        queue->next = tempQueue->next;
        free(tempQueue);
    }
    else
    {
        queue->node = NULL;
    }

    return tempNode;
}

void printTree(struct Tree *tree)
{
    int nodeNum;
    struct STQueue *queue = (STQueue *)malloc(sizeof(STQueue));
    // printf("Trying to print tree...");
    queue->node = tree->root;
    queue->next = NULL;
    while (queue->node != NULL)
    {
        STNode *node = queue->node;
        STtypeOnScreen(node->value, node->coords.x, node->coords.y);
        if (node->left != NULL)
        {
            STenqueue(queue, node->left);
        }
        if (node->right != NULL)
        {
            STenqueue(queue, node->right);
        }
        STdequeue(queue);
        nodeNum++;
    }
}

void appendToTree(struct Tree *tree, int number)
{
    struct STNode **currentNode = &(tree->root);
    int unsolved = 1;
    int width = 50;

    while (unsolved)
    {
        int depth = (*currentNode)->depth + 1;
        struct STNode *parent = (*currentNode);
        if (number > (*currentNode)->value)
        {
            currentNode = &((*currentNode)->right);
        }
        else
        {
            currentNode = &((*currentNode)->left);
        }

        if (*currentNode == NULL)
        {
            *currentNode = malloc(sizeof(struct STNode));
            (*currentNode)->value = number;
            (*currentNode)->left = NULL;
            (*currentNode)->right = NULL;
            (*currentNode)->depth = depth;
            (*currentNode)->coords.x = parent->coords.x + (number > parent->value ? width / pow(2, depth) : -width / pow(2, depth));
            (*currentNode)->coords.y = parent->coords.y + 5;
            unsolved = 0;
        }
    }
}

void fillNumbers(struct Tree *tree, int numberCount)
{
    int i;
    for (i = 0; i < numberCount; i++)
    {

        int number;
        printf("Input #%i: ", i + 1);
        while (scanf("%i", &number) != 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            p("Invalid input. Please enter an integer: ");
        }
        appendToTree(tree, number);
    }
}

void searchTree()

{
    int numberCount;
    struct STNode root;
    struct Tree binaryTree;
    loadingScreenForNonGraphical();
    clrscr();
    printf("How many numbers will you input? (min of 1, max of 13)\n");
    while (scanf("%i", &numberCount) != 1 || numberCount < 1 || numberCount > 13)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        p("Invalid input. Please enter an integer: ");
    }
    printf("Enter value of root node\n");
    while (scanf("%i", &root.value) != 1)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        p("Invalid input. Please enter an integer: ");
    }
    // root.value = 7;
    binaryTree.root = &root;
    root.left = NULL;
    root.right = NULL;
    root.coords.x = 40;
    root.coords.y = 10;
    root.depth = 1;
    fillNumbers(&binaryTree, numberCount);
    printTree(&binaryTree);
    getch();
}

// Fibo
#define MAX 1000
void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

long long fib[MAX];

long long fibonacci(long long order)
{
    if (order == 0 || order == 1)
    {
        return order;
    }

    if (fib[order] != -1)
    {
        return fib[order];
    }

    fib[order] = fibonacci(order - 1) + fibonacci(order - 2);
    return fib[order];
}

void initializeFibArray()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        fib[i] = -1;
    }
}

void printFibonacciTable(long long input)
{
    long long i;
    g(14, 14);
    printf("Here is the Fibonacci sequence of %llu:\n", input);

    g(21, 15);
    printf("+-----------+-----------------------+\n");
    g(21, 16);
    printf("|   Order   |     Fibonacci Number  |\n");
    g(21, 17);
    printf("+-----------+-----------------------+\n");

    for (i = 0; i < input; i++)
    {
        g(21, 18 + i);
        printf("|%11llu|%23llu|\n", i + 1, fibonacci(i));
    }
    g(21, 18 + input);
    printf("+-----------+-----------------------+\n\n");
}

int fibo()
{
    long long input;
    int state = 1;

    initializeFibArray();

    while (state)
    {
        clrscr();
        g(12, 3);
        printf("========================================================\n");
        g(12, 4);
        printf("|                 FIBONACCI CALCULATOR                 |\n");
        g(12, 5);
        printf("========================================================\n");
        g(14, 7);
        printf("Type a number to find its fibonacci value (1-48) ");
        g(14, 9);
        printf("Enter the number:  ");

        if (s("%llu", &input) != 1)
        {
            sleep(1);
            g(14, 10);
            printf("[ERROR] Invalid input. Please enter a valid integer.\n");
            g(12, 12);
            printf("========================================================\n");
            g(14, 14);
            printf("Press 'F' to quit; press any other key to try again");

            if (getch() == 'F' || getch() == 'f')
            {
                state = 0;
            }
            while (getchar() != '\n')
                ;
            clrscr();
            continue;
        }
        else if (input < 0)
        {
            sleep(1);
            g(14, 10);
            printf("[ERROR] Invalid input. Please enter a positive integer.\n");
            g(12, 12);
            printf("========================================================\n");
            g(14, 14);
            printf("Press 'F' to quit; press any other key to try again");

            if (getch() == 'F' || getch() == 'f')
            {
                state = 0;
            }
            while (getchar() != '\n')
                ;
            clrscr();
            continue;
        }
        else if (input > 48)
        {
            sleep(1);
            g(14, 10);
            printf("[ERROR] The program cannot perform the calculation.\n");
            g(12, 12);
            printf("========================================================\n");
            g(14, 14);
            printf("Press 'F' to quit; press any other key to try again");

            if (getch() == 'F' || getch() == 'f')
            {
                state = 0;
            }
            while (getchar() != '\n')
                ;
            clrscr();
            continue;
        }

        g(14, 10);
        printf("Calculating....");
        sleep(2);

        g(14, 12);
        printf("The Fibonacci value of %llu is %llu\n", input, fibonacci(input - 1));

        printFibonacciTable(input);

        g(12, 17 + input + 5);
        printf("========================================================\n\n");
        g(14, 19 + input + 5);
        printf("Press 'F' to quit; press any other key to try again");

        if (getch() == 'F' || getch() == 'f')
        {
            state = 0;
        }
    }

    return 0;
}
// Tower of hanoi
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define p printf
#define g gotoxy

struct Disk
{
    int length;
    int colorCode;
};

struct Rod
{
    struct HStack *stack;
    int id;
};

struct HCoords
{
    int x;
    int y;
};

typedef struct HStack
{
    int top;
    struct Disk *array;
} HStack;

void HPush(HStack *stack, struct Disk item)
{
    stack->array[++stack->top] = item;
}

struct Disk HPop(HStack *stack)
{
    return stack->array[stack->top--];
}

struct Rod *createThreeRods(int diskCount)
{
    int i;
    struct Rod *rods = malloc(3 * sizeof(struct Rod));
    if (rods == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (i = 0; i < 3; i++)
    {
        struct HStack *initialStack = malloc(sizeof(struct HStack));
        if (initialStack == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        initialStack->top = -1;
        initialStack->array = malloc(sizeof(struct Disk) * diskCount);
        if (initialStack->array == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        rods[i].stack = initialStack;
        rods[i].id = i + 1;
    }
    return rods;
}

void HDrawBlockOnScreen(x, y)
{
    g(x, y);
    p("%c", 219);
}

void HDrawCBlockOnScreen(x, y)
{
    g(x, y);
    cprintf("%c", 219);
}

void HDrawVerticalLine(x, y, length)
{
    int i;
    for (i = 0; i < (length - (length / 2)); i++)
    {
        HDrawBlockOnScreen(x, y + i);
    }
}

void HDrawCVerticalLine(x, y, length)
{
    int i;
    for (i = 0; i < (length - (length / 2)); i++)
    {
        HDrawCBlockOnScreen(x, y + i);
    }
}

void HDrawHorizontalLine(x, y, length)
{

    int i;
    for (i = 0; i < length; i++)
    {
        HDrawBlockOnScreen(x + i, y);
    }
}

void HDrawCHorizontalLine(x, y, length)
{

    int i;
    for (i = 0; i < length; i++)
    {
        HDrawCBlockOnScreen(x + i, y);
    }
}

void massAddDisksToRod(struct Rod *rod, struct Disk *disks, int diskCount)
{
    int i;
    for (i = 0; i < diskCount; i++)
    {
        HPush(rod->stack, disks[i]);
    }
}

struct Disk *createDisksBaseOnInput(int *input, int diskCount)
{
    int i;
    struct Disk *disks = malloc(sizeof(struct Disk) * diskCount);
    int colors[5] = {GREEN, RED, BLUE, YELLOW, MAGENTA}; // Define colors array
    for (i = 0; i < diskCount; i++)
    {
        struct Disk disk;
        disk.length = input[i];
        disk.colorCode = colors[i % 5];
        disks[i] = disk;
    }

    return disks;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSortDescending(int *arr, int n)
{
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

int *copyNumberArray(int *numbers, int *copy, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        copy[i] = numbers[i];
    }

    return copy;
}

int *sortNumbersDescending(int *numbers, int diskCount)
{
    int *result = malloc(sizeof(int) * diskCount);
    copyNumberArray(numbers, result, diskCount);

    // [[2, 1, 3], 5, 4]
    // [1, 2, 3]
    bubbleSortDescending(result, diskCount);
    return result;
}

int isSolved(struct Rod *threeRods, int diskCount)
{
    // If the second rod is full, then the puzzle is solved
    if (threeRods[1].stack->top == diskCount - 1)
    {
        return 1;
    }
    return 0;
}

struct HCoords createRodVisual(int x, int y)
{
    struct HCoords center;
    int i;

    HDrawCHorizontalLine(x, y, 10);
    HDrawCVerticalLine(x + 5, y - 5, 10);
    center.x = x + 5;
    center.y = y;
    return center;
}

void createDiskVisual(int x, int y, int diskLength, int *color)
{
    int start_x = x - (diskLength / 2);
    textcolor(*color);
    HDrawCHorizontalLine(start_x, y - 1, diskLength);
    cprintf("%i", diskLength);
}

struct HCoords *createThreeRodsVisual()
{
    struct HCoords *threeVisualCoords = malloc(sizeof(struct HCoords) * 3);
    int i;
    int y = 20;
    int x = 15;
    textcolor(WHITE);
    for (i = 0; i < 3; i++)
    {
        struct HCoords coords = createRodVisual(x + ((x + 5) * i), y);
        threeVisualCoords[i] = coords;
    }

    return threeVisualCoords;
}

void updateDisksState(struct Rod *rods, struct HCoords *rodsCoords)
{
    int i, j;
    clrscr();
    createThreeRodsVisual();
    // Different colors for disks
    // There are three rods. Print disks for each
    for (i = 0; i < 3; i++)
    {
        int numberOfDisksStacked = rods[i].stack->top + 1;
        for (j = 0; j < numberOfDisksStacked; j++)
        {
            struct HCoords currentRodCoords = rodsCoords[i];
            struct Disk disk = rods[i].stack->array[j]; // Get disk from stack
            createDiskVisual(currentRodCoords.x, currentRodCoords.y - j, disk.length, &disk.colorCode);
        }
    }
    delay(500);
}

void askForDiskLengths(int diskCount, int *diskLengths)
{
    int i;

    for (i = 0; i < diskCount; i++)
    {
        int input;
        cprintf("Length of disk #%i (max of 15, min of 1): ", i + 1);
        while (scanf("%i", &input) != 1 || input > 15 || input < 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            p("Invalid input. Please enter an integer (max of 15, min of 1): ");
        }
        diskLengths[i] = input;
    }
}

void TowerOfHanoi(int n, struct Rod *from_rod, struct Rod *to_rod, struct Rod *aux_rod, struct Rod *threeRods, struct HCoords *threeRodsVisualCoords)
{
    struct Disk removedDisk;
    if (n == 1)
    {
        struct Disk removedDisk = HPop(from_rod->stack);
        HPush(to_rod->stack, removedDisk);
        updateDisksState(threeRods, threeRodsVisualCoords);
        return;
    }
    TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod, threeRods, threeRodsVisualCoords);
    removedDisk = HPop(from_rod->stack);
    HPush(to_rod->stack, removedDisk);
    updateDisksState(threeRods, threeRodsVisualCoords);
    TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod, threeRods, threeRodsVisualCoords);
}

void towerOfHanoi()
{
    int diskCount;
    int isTraditional;
    struct Rod *threeRods;
    int *diskLengths;
    int *correctFormation;
    int solvedFormation = 0;
    struct Disk *disks;
    struct HCoords rodCenter;
    // Assign first rod to remove elements to as first rod.
    struct Rod *lastRod;
    struct HCoords *threeRodsVisualCoords;
    loadingScreenForNonGraphical();
    clrscr();
    // Add all disks to first rod initially
    textcolor(WHITE);
    cprintf("How many disks should there be? (max of 7, min of 1): ");
    while (scanf("%i", &diskCount) != 1 || diskCount > 7 || diskCount < 1)
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        p("Invalid input. Please enter an integer (max of 7, min of 1): ");
    }
    // [ rod1, rod2, rod3]
    threeRods = createThreeRods(diskCount);
    lastRod = &threeRods[0];
    diskLengths = malloc(sizeof(int) * diskCount);
    // diskLengths = {3, 2, 1};
    askForDiskLengths(diskCount, diskLengths);
    correctFormation = sortNumbersDescending(diskLengths, diskCount);

    // rodCenter = createRodVisual(10, 10);
    // createDiskVisual(rodCenter.x, rodCenter.y, 1);
    isTraditional = 0;
    cprintf("Do you want to play the traditional way? (1 for yes, 0 for no): ");
    while (scanf("%i", &isTraditional) != 1 || (isTraditional != 1 && isTraditional != 0))
    {
        while (getchar() != '\n')
            ; // clear the input buffer
        p("Invalid input. Please enter an integer, or ensure that number is either 0 or 1: ");
    }

    if (isTraditional)
    {
        disks = createDisksBaseOnInput(correctFormation, diskCount);
    }
    else
    {
        disks = createDisksBaseOnInput(diskLengths, diskCount);
    }

    threeRodsVisualCoords = createThreeRodsVisual();
    massAddDisksToRod(&threeRods[0], disks, diskCount);
    updateDisksState(threeRods, threeRodsVisualCoords);

    if (!isTraditional)
    {
        while (!isSolved(threeRods, diskCount))
        {
            if (lastRod->id == 1)
            {
                int top = lastRod->stack->top;

                // if stack empty, move to third rod
                if (top == -1)
                {
                    lastRod = &threeRods[2];
                    continue;
                }

                if (lastRod->stack->array[top].length == correctFormation[solvedFormation])
                {
                    struct Disk removedDisk = HPop(lastRod->stack);
                    struct Rod *secondRod = &threeRods[1];
                    HPush(secondRod->stack, removedDisk);
                    updateDisksState(threeRods, threeRodsVisualCoords);
                    solvedFormation++;
                }
                else
                {
                    struct Disk removedDisk = HPop(lastRod->stack);
                    struct Rod *thirdRod = &threeRods[2];
                    HPush(thirdRod->stack, removedDisk);
                    updateDisksState(threeRods, threeRodsVisualCoords);
                }
            }

            if (lastRod->id == 3)
            {
                int top = lastRod->stack->top;

                // if stack empty, move to third rod
                if (top == -1)
                {
                    lastRod = &threeRods[0];
                    continue;
                }

                if (lastRod->stack->array[top].length == correctFormation[solvedFormation])
                {
                    struct Disk removedDisk = HPop(lastRod->stack);
                    struct Rod *secondRod = &threeRods[1];
                    HPush(secondRod->stack, removedDisk);
                    updateDisksState(threeRods, threeRodsVisualCoords);
                    solvedFormation++;
                }
                else
                {
                    struct Disk removedDisk = HPop(lastRod->stack);
                    struct Rod *firstRod = &threeRods[0];
                    HPush(firstRod->stack, removedDisk);
                    updateDisksState(threeRods, threeRodsVisualCoords);
                }
            }
        }
    }
    else
    {
        TowerOfHanoi(diskCount, &threeRods[0], &threeRods[1], &threeRods[2], threeRods, threeRodsVisualCoords);
    }
    getch();
}

// Factorial

#define FACTORIAL_SIZE 1000
long factorialArray[FACTORIAL_SIZE];

long long factorial(int n)
{
    if (n == 0)
        return 1;
    if (factorialArray[n])
        return factorialArray[n];
    else
    {
        factorialArray[n] = n * factorial(n - 1);
        return factorialArray[n];
    }
}

int runFactorial()
{
    int number;
    long long value;
    char choice;
    loadingScreenForNonGraphical();
    clrscr();
    do
    {
        while (1)
        {
            g(12, 3);
            p("========================================================");
            g(12, 4);
            p("|                 FACTORIAL CALCULATOR                 |");
            g(12, 5);
            p("========================================================");

            g(12, 7);
            p(" Type the number you want to find the factorial (0-12) ");
            g(12, 9);
            p(" Enter the number:  ");
            if (s("%d", &number) != 1)
            {
                g(13, 10);
                p("[ERROR] Invalid input. Please enter a valid integer.\n");
                while (getchar() != '\n')
                    ;
                sleep(2);
                clrscr();
                continue;
            }
            else if (number < 0)
            {
                g(13, 10);
                p("[ERROR] Please enter a non-negative integer.\n");
                sleep(2);
                clrscr();
                continue;
            }
            else if (number > 12)
            {
                g(13, 10);
                p("[ERROR] The program cannot perform the calculation.\n");
                sleep(2);
                clrscr();
                continue;
            }
            else
            {
                break;
            }
        }
        while (number < 0 || getchar() != '\n')
            ;
        g(13, 10);
        p("Calculating....");
        sleep(1);
        value = factorial(number);
        g(13, 12);
        p("Factorial of %d is:  %llu\n\n", number, value);
        sleep(1);

        while (1)
        {
            p("            Do you want to calculate again (Y/N)?  ");
            s(" %c", &choice);

            if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
            {
                sleep(1);
                clrscr();
                break;
            }
            else
            {
                p("            [ERROR] Invalid choice. Please enter either Y or N.\n\n");
                while (getchar() != '\n')
                    ;
            }
        }

        if (choice == 'N' || choice == 'n')
        {
            g(19, 12);
            p("Thank you for using Factorial Calculator.\n");
            break;
        }

    } while (choice == 'Y' || choice == 'y');
    getch();

    return 0;
}

// Clock

void printLargerText(const char *text)
{
    int o;
    for (o = 0; o < 1; ++o)
    {
        printf("\n");
    }

    printf("%s", text);

    for (o = 0; o < 3; ++o)
    {
        printf("\n");
    }
}

void clockProgram()
{
    int i, j, k;
    loadingScreenForNonGraphical();
    for (i = 0; i <= 24; i++)
    {
        for (j = 0; j <= 59; j++)
        {
            for (k = 0; k <= 59; k++)
            {
                clrscr();
                ensquare(2, 3, 76, 24, "");
                g(36, 10);
                printf("%02d:%02d:%02d", i, j, k);
                g(28, 11);
                printf("Press 'q' to quit\n");
                g(28, 12);
                printf("Press 'p' to pause\n");
                g(28, 13);
                printf("Press 'r' to reset the clock\n");
                delay(1000);

                if (kbhit())
                {
                    char ch = getch();
                    // Add code here to handle the key press
                    switch (ch)
                    {
                    case 'q':
                        printf("\n\t\t\t\t   Sayonara!");
                        delay(1000);
                        return;
                    case 'p':
                        printf("\t\t\t  Press 'r' to resume");
                        while (getch() != 'r')
                            ;
                        break;
                    case 'r':
                        printf("\n\t\t\t\tResetting clock");
                        i = 0;
                        j = 0;
                        k = 0;
                        break;
                    }
                }
            }
        }
    }
}

void main()
{
    int choice;
    int quit;
    quit = 0;
    while (!quit)
    {
        int g_value = 5;
        clrscr();
        ensquare(1, 1, 78, 24, "");
        ensquare(1, 1, 78, 3, "Welcome to Data Structures and Algorithm Programs Menu");
        g(30, g_value++);
        p("What do you want to do?\n");
        g_value++;
        g(30, g_value++);
        p("1. Binary Tree\n");
        g(30, g_value++);
        p("2. Tic Tac Toe\n");
        g(30, g_value++);
        p("3. Square Cubed\n");
        g(30, g_value++);
        p("4. Maze\n");
        g(30, g_value++);
        p("5. Graph\n");
        g(30, g_value++);
        p("6. Car Queue\n");
        g(30, g_value++);
        p("7. Car Stack\n");
        g(30, g_value++);
        p("8. Binary Search Tree\n");
        g(30, g_value++);
        p("9. Fibonacci\n");
        g(30, g_value++);
        p("10. Tower of Hanoi\n");
        g(30, g_value++);
        p("11. Factorial\n");
        g(30, g_value++);
        p("12. Clock/Timer\n");
        g(30, g_value++);
        p("13. Exit Program\n");
        g(30, g_value++);
        p("Your choice: ");

        while (scanf("%i", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            p("Invalid input. Please enter an integer: ");
        }

        switch (choice)
        {
        case 1:
            binaryTree();
            break;
        case 2:
            ticTacToe();
            break;
        case 3:
            squareCubed();
            break;
        case 4:
            maze();
            break;
        case 5:
            graph();
            break;
        case 6:
            carQueue();
            break;
        case 7:
            playCarStack();
            break;
        case 8:
            searchTree();
            break;
        case 9:
            fibo();
            break;
        case 10:
            towerOfHanoi();
            break;
        case 11:
            runFactorial();
            break;
        case 12:
            clockProgram();
            break;
        case 13:
            quit = 1;
            break;
        default:
            p("Invalid choice");
            break;
        }
    }

    clrscr();
    p("Please press any key to finally terminate the program");
    getch();
}