#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define p printf
#define s scanf
#define g gotoxy
#define c cprintf
#define MAX_CARS 5
#define SIZE 10

typedef struct
{
    int x;
    int y;
} Coords;

typedef struct
{
    char marker;
    int playerNumber;
} Player;

// Draw line n times
// After first line, switch to vertical lines and draw n times.
// Use current column, change rows
// After first vertical line, switch to horizontal again.
// Use current row, change columns
// After second horizontal line, switch to vertical but reduce 1 from n

void graph()
{
    int x, y, cpe, ce, ece, ee, me, ie, rem;

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
    g(22, 8);
    s("%d", &ece);
    g(22, 9);
    s("%d", &ee);
    g(22, 10);
    s("%d", &ce);
    g(22, 11);
    s("%d", &rem);
    g(22, 12);
    s("%d", &me);
    g(22, 13);
    s("%d", &ie);
    g(22, 14);
    s("%d", &cpe);

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

void maze()
{

    // g(column, row)
    int i;
    int length = 23;
    int y = 1;
    int x = 30;

    clrscr();
    // for(i = length; i >= 0; i--) {
    //     for(j = 0; j < 3; j++) {
    //         writeNTimes(x, y, i, j, horizontal, backwards);
    //     }
    // }

    // writeNTimes(int x, int y, int length, int n, int horizontal, int backwards)

    for (i = length; i >= 0; i--)
    {
        x = writeNTimes(x + 1, y, i, 1, 1, 0);
        y = writeNTimes(x, y, i, 1, 0, 0);
        x = writeNTimes(x, y, i, 1, 1, 1);
        i = i - 2;
        y = writeNTimes(x, y, i, 1, 0, 1);
    }

    promptBeforeExit();
}

void squareCubed()
{
    int x, qty;
    char items[15];
    float uprice, amount, totalamount;
    clrscr();
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

void typeOnScreen(message, x, y)
{
    g(x, y);
    p("%s", message);
}

void drawBlockOnScreen(x, y)
{
    g(x, y);
    p("%c", 219);
}

void drawOnScreen(character, x, y)
{
    g(x, y);
    p("%c", character);
}

void drawVerticalLine(x, y, length)
{
    int i;
    for (i = 0; i < (length - (length / 2)); i++)
    {
        drawBlockOnScreen(x, y + i);
    }
}

void drawHorizontalLine(x, y, length)
{

    int i;
    for (i = 0; i < length; i++)
    {
        drawBlockOnScreen(x + i, y);
    }
}

/*
Returns center of cell,
location to which character can be placed
*/
Coords drawCell(x, y, length)
{

    int centerX, centerY;
    Coords cellCenterCoords;
    drawHorizontalLine(x, y, length);
    drawVerticalLine(x + length, y, length);
    drawVerticalLine(x, y, length);
    drawHorizontalLine(x, y + (length / 2), length + 1);

    centerX = abs((x + (length / 2)));
    centerY = abs(y + (length * .33));

    cellCenterCoords.x = centerX;
    cellCenterCoords.y = centerY;
    return cellCenterCoords;
}

int hasHorizontalWinner(char gameboard[3][3])
{

    int i;

    int hasWinner = 0;

    for (i = 0; i < 3; i++)
    {
        if (gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2])
        {
            hasWinner = 1;
            return hasWinner;
        }
    }

    return hasWinner;
}

int hasVerticalWinner(char gameboard[3][3])
{

    int i;
    int j = 0;

    int hasWinner = 0;

    for (i = 0; i < 3; i++)
    {
        if (gameboard[j][i] == gameboard[j + 1][i] && gameboard[j + 1][i] == gameboard[j + 2][i])
        {
            hasWinner = 1;
            return hasWinner;
        }
    }

    return hasWinner;
}

int hasDiagonalWinner(char gameboard[3][3])
{

    int hasWinner = 0;

    if (gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] ||
        gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0])
    {
        hasWinner = 1;
        return hasWinner;
    }

    return hasWinner;
}

int hasWinner(char gameboard[3][3])
{

    if (hasHorizontalWinner(gameboard) || hasVerticalWinner(gameboard) || hasDiagonalWinner(gameboard))
    {
        return 1;
    }

    // char diagonalWinningPatterns[2][3] = {
    //     {gameboard[0][0], gameboard[1][1], gameboard[2][2]},
    //     {gameboard[0][2], gameboard[1][1], gameboard[2][0]}};
    return 0;
}

int hasDraw(char gameboard[3][3])
{
    int i, j;

    int filledCells = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (gameboard[i][j] == 'x' || gameboard[i][j] == 'o')
            {
                filledCells++;
            }
        }
    }
    if (filledCells >= 9 && hasWinner(gameboard) != 1)
    {
        return 1;
    }

    return 0;
}

void playTurn(Player currentPlayer, char gameboard[3][3])
{
    int illegalMove;
    illegalMove = 1;
    while (illegalMove)
    {
        int choice, row, column;
        typeOnScreen("Please type in a choice: ", 25, 25);

        p("");
        s("%i", &choice);

        if (!isdigit(choice))
        {
            clrscr();
            p("Please enter a number only");
            delay(5000);
        }

        if (choice <= 3)
        {
            row = 0;
        }
        else if (choice > 3 && choice <= 6)
        {
            row = 1;
        }
        else
        {
            row = 2;
        }

        column = (choice - 1) % 3;

        if (gameboard[row][column] == 'x' || gameboard[row][column] == 'o')
        {
            g(25, 25);
            p("Illegal move, try again");
            delay(1000);
            continue;
        }
        else
        {
            p("%c", gameboard[row][column]);
            gameboard[row][column] = currentPlayer.marker;
            illegalMove = 0;
        }
    }
}

void drawGameboard(int x, int y, int length, char gameboard[3][3])
{
    int i;

    clrscr();

    for (i = 0; i < 3; i++)
    {
        Coords centerCoords;
        centerCoords = drawCell(x + (length * i), y, length);
        drawOnScreen(gameboard[0][i], centerCoords.x, centerCoords.y);
    };

    for (i = 0; i < 3; i++)
    {
        Coords centerCoords;
        centerCoords = drawCell(x + (length * i), (y + (length / 2)), length);
        drawOnScreen(gameboard[1][i], centerCoords.x, centerCoords.y);
    };

    for (i = 0; i < 3; i++)
    {
        Coords centerCoords;
        centerCoords = drawCell(x + (length * i), y + (length), length);
        drawOnScreen(gameboard[2][i], centerCoords.x, centerCoords.y);
    };
}

void ticTacToe()
{
    int i, j;

    Player playerOne = {
        'x',
        1};

    Player playerTwo = {
        'o',
        2};

    Player currentPlayer = playerOne;

    char gameboard[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    drawGameboard(25, 5, 10, gameboard);
    playTurn(currentPlayer, gameboard);
    drawGameboard(25, 5, 10, gameboard);

    // While there is no winner and there is no draw, just play game
    while (hasWinner(gameboard) != 1 && hasDraw(gameboard) != 1)
    {
        if (currentPlayer.playerNumber == playerOne.playerNumber)
        {
            currentPlayer = playerTwo;
        }
        else
        {
            currentPlayer = playerOne;
        }
        playTurn(currentPlayer, gameboard);
        drawGameboard(25, 5, 10, gameboard);
    }

    g(17, 13);

    if (hasWinner(gameboard) == 1)
    {
        p("Congratulations, player number %i! You have won!", currentPlayer.playerNumber);
    }

    if (hasDraw(gameboard) == 1)
    {
        p("It's a draw!");
    }
    g(25, 10);

    promptBeforeExit();
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
    scanf("%i", &choice);
    return choice;
}

// void removeNode(LinkedList *list, int value)
// {
//     LinkedList *currentList = list;
//     LinkedList *previousList = list;

//     while (currentList->next != NULL)
//     {
//         previousList = currentList;
//         currentList = currentList->next;
//         if (currentList->value == value)
//         {
//             previousList->next = currentList->next;
//             p("Removed %i car\n", currentList->value);
//             delay(500);
//             free(currentList);
//             return;
//         }
//     }
// }

int deleteAllCars(LinkedList *carList)
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

    clrscr();
    presentNodes = 0;

    p("Number of levels (Maximum of 5): \n");
    s(" %i", &numberOfLevels);

    if (numberOfLevels > 5)
    {
    }

    nodes = getNumberOfNodes(numberOfLevels);
    p("Number of nodes: %i\n", nodes);

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
        // if (currentNode->left->left == NULL || currentNode->left->right == NULL)
        // {
        //     enqueue(&queue, currentNode->left);
        // }

        // if (currentNode->right->left == NULL || currentNode->right->right == NULL)
        // {
        //     enqueue(&queue, currentNode->right);
        // }
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

    // p("Thank you! Program will automatically terminate in 5 seconds");
    // delay(5000);
    // clrscr();
    promptBeforeExit();
}

int promptBeforeExit()
{
    int keystroke;
    p("\nFinally, press F to terminate program");

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
int Front = -1;
int Rear = -1;

void queueEnqueue(int Q[SIZE], int carNumber)
{
    if (Rear < SIZE - 1)
    {
        Rear++;
        Q[Rear] = carNumber;
        p("\nCar %d has entered the garage. \n", Q[Rear]);
    }
    else
    {
        p("\nSorry, the garage is full.\n");
    }
    if (Front == -1)
    {
        Front++;
    }
}

void queueDequeue(int Q[SIZE])
{
    if (Front <= Rear)
    {
        p("\nCar %d has left the garage. \n", Q[Front]);
        Front++;
    }
    else
    {
        p("\nGarage is empty. \n");
        Front = -1;
        Rear = -1;
    }
}

void display(int Q[SIZE])
{
    int x;
    clrscr();
    p("Garage\n");
    for (x = Front; x <= Rear; x++)
    {
        p("===========\n");
        p("Car %d ", Q[x]);
        p("\n===========\n");
    }
}
int carQueue()
{
    int Q[SIZE];
    int carNumber, ch;
    clrscr();
    g(10, 10);
    p("CAR GARAGE\n\n");

    do
    {
        p("\n[1] Car Park\n[2] Car Departure\n[3] Exit\n \nEnter your choice: ");
        s("%d", &ch);
        switch (ch)
        {
        case 1:
            p("Enter Car Number to Park: ");
            s("%d", &carNumber);
            queueEnqueue(Q, carNumber);
            display(Q);
            break;

        case 2:
            queueDequeue(Q);
            display(Q);
            break;

        case 3:
            p("Exiting the program.\n");
            break;

        default:
            p("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (ch != 3);
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
    while (stack->top != indexToRemove - 2)
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
    scanf("%i", &choice);
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
        p("Input a car number to remove: ");
        while (scanf("%i", &numberToRemove) != 1)
        {
            while (getchar() != '\n')
                ; // clear the input buffer
            p("Invalid input. Please enter an integer: ");
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
        scanf("%i", &number);
        appendToTree(tree, number);
    }
}

void searchTree()

{
    int numberCount;
    struct STNode root;
    struct Tree binaryTree;
    clrscr();
    printf("How many numbers will you input?\n");
    scanf("%i", &numberCount);
    printf("Enter value of root node\n");
    scanf("%i", &root.value);
    // root.value = 7;
    binaryTree.root = &root;
    root.left = NULL;
    root.right = NULL;
    root.coords.x = 40;
    root.coords.y = 5;
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
        else if (input > 33)
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
#define GREEN 2
#define RED 4
#define BLUE 1
#define YELLOW 14
#define MAGENTA 5

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
        cprintf("Length of disk #%i: ", i + 1);
        scanf("%i", &input);
        diskLengths[i] = input;
    }
}

void towerOfHanoi()
{
    int diskCount;
    struct Rod *threeRods;
    int *diskLengths;
    int *correctFormation;
    int solvedFormation = 0;
    struct Disk *disks;
    struct HCoords rodCenter;
    // Assign first rod to remove elements to as first rod.
    struct Rod *lastRod;
    struct HCoords *threeRodsVisualCoords;
    clrscr();
    // Add all disks to first rod initially
    textcolor(WHITE);
    cprintf("How many disks should there be? ");
    scanf("%i", &diskCount);
    // [ rod1, rod2, rod3]
    threeRods = createThreeRods(diskCount);
    lastRod = &threeRods[0];
    diskLengths = malloc(sizeof(int) * diskCount);
    // diskLengths = {3, 2, 1};
    askForDiskLengths(diskCount, diskLengths);
    correctFormation = sortNumbersDescending(diskLengths, diskCount);
    disks = createDisksBaseOnInput(diskLengths, diskCount);
    // rodCenter = createRodVisual(10, 10);
    // createDiskVisual(rodCenter.x, rodCenter.y, 1);

    threeRodsVisualCoords = createThreeRodsVisual();
    massAddDisksToRod(&threeRods[0], disks, diskCount);
    updateDisksState(threeRods, threeRodsVisualCoords);
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
    getch();
}

// Factorial

long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

int runFactorial()
{
    int number;
    long value;
    clrscr();
    g(20, 10);
    printf("Enter a number: ");
    s("%d", &number);

    value = factorial(number);

    g(20, 12);
    printf("Factorial of %d is %ld\n", number, value);

    promptBeforeExit();

    return 0;
}

void main()
{
    int choice;
    int quit;
    quit = 0;
    while (!quit)
    {
        clrscr();
        p("What do you want to do?\n");
        p("1. Binary Tree\n");
        p("2. Tic Tac Toe\n");
        p("3. Car Link\n");
        p("4. Square Cubed\n");
        p("5. Maze\n");
        p("6. Graph\n");
        p("7. Car Queue\n");
        p("8. Car Stack\n");
        p("9. Binary Search Tree\n");
        p("10. Fibonacci\n");
        p("11. Tower of Hanoi\n");
        p("12. Factorial\n");

        p("15. Exit Program\n");
        p("Your choice: ");

        s("%i", &choice);

        switch (choice)
        {
        case 1:
            binaryTree();
            break;
        case 2:
            ticTacToe();
            break;
        case 3:
            carLink();
            break;
        case 4:
            squareCubed();
            break;
        case 5:
            maze();
            break;
        case 6:
            graph();
            break;
        case 7:
            carQueue();
            break;
        case 8:
            playCarStack();
            break;
        case 9:
            searchTree();
            break;
        case 10:
            fibo();
            break;
        case 11:
            towerOfHanoi();
            textcolor(WHITE);
            cprintf("");
            break;
        case 12:
            runFactorial();
            break;
        case 15:
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