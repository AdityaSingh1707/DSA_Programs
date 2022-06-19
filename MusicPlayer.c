// Music Player..

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
{
    struct st *next, *prev;
    char *name;
} Node;

Node *createNode(char *name);
void append(Node **Head, char *Track);
void traverse(Node *Head);
Node *searchbypos(Node *Head, int pos);
Node *searchbydata(Node *Head, char *data);
Node *play(Node *Head, int pos);
void addafter(Node *ptr, char *newTracks);
void addbeg(Node **Head, char *newTracks);
void delnode(Node **Head, Node *curr);
void sort(Node **Head);
void updateFile(FILE *music, Node *Head);
void insertSorted(Node **Head, Node *tmp);

int main()
{
    Node *Head = NULL, *Currentplayed, *curr;
    FILE *Fmusic = fopen("Music.txt", "r");
    char ch, dump, Track[15], newData[15];
    int i, trackNo, posi;
    while (fgets(Track, sizeof(Track), Fmusic) != NULL)
    {
        append(&Head, Track);
    }
    traverse(Head);
    curr = Head;
    do
    {
        printf("\nPress S : Start the Player.\n");
        printf("Press J : Jump to a Specific track.\n");
        printf("Press N : Play Next Track.\n");
        printf("Press P : Play Previous Track.\n");
        printf("Press F : Play First Track.\n");
        printf("Press L : Play Last Track.\n");
        printf("Press X : Add new Track in the playlist.\n");
        printf("Press A : Add a track after an existing track.\n");
        printf("Press B : Add a track before an existing track.\n");
        printf("Press R : Remove a specific track from the list.\n");
        printf("Press O : Sort the tracks in alphabetical order.\n");
        printf("Press T : Stop The Player.\n");
        printf("Press D : Display all tracks.\n");
        printf("Enter Your Choice : \n");
        scanf("%c%c", &ch, &dump);
        switch (ch)
        {
        case 'S':
            Currentplayed = play(Head, 1);
            if (Currentplayed == NULL)
            {
                printf("\nThe playlist is empty.\n");
                break;
            }
            printf("\n\nMusic Player Starts...\nPlaying First Track :- ");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'J':
            printf("\nEnter the name of the track to be played :\n");
            fgets(Track, 15, stdin);
            Currentplayed = searchbydata(Head, Track);
            if (Currentplayed == NULL)
            {
                printf("The playlist is empty.\n");
            }
            printf("\n\nNow Playing... :- ");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'N':
            Currentplayed = Currentplayed->next;
            if (Currentplayed == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            printf("\n\nNow Playing... :- ");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'P':
            Currentplayed = Currentplayed->prev;
            if (Currentplayed == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            printf("\n\nNow Playing... :- ");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'F':
            Currentplayed = play(Head, 1);
            if (Currentplayed == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            printf("\n\nNow Playing... :- ");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'L':
            printf("\n\nNow Playing... :- ");
            Currentplayed = play(Head, -1);
            if (Currentplayed == NULL)
                printf("The playlist is empty.\n");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'X':
            printf("\nEnter the name of the track to be added in the playlist :\n");
            fgets(Track, 15, stdin);
            insertSorted(&Head, createNode(Track));
            traverse(Head);
            printf("\n\n");
            break;
        case 'A':
            printf("\nEnter the name of the track after which new track is to added : \n");
            fgets(Track, 15, stdin);
            printf("Enter new Track name : \n");
            fgets(newData, 15, stdin);
            curr = searchbydata(Head, Track);
            if (curr == NULL)
            {
                printf("The given track is not present in the playlist.\n");
                break;
            }
            addafter(curr, newData);
            traverse(Head);
            updateFile(Fmusic, Head);
            printf("\nSuccesfully Added.\n");
            break;
        case 'B':
            if (Head == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            printf("\nEnter the name of the track before which new track is to added : \n");
            fgets(Track, 15, stdin);
            printf("Enter new Track name : \n");
            fgets(newData, 15, stdin);
            curr = searchbydata(Head, Track);
            if (curr == NULL)
                printf("No such Track is present in the playlist.\n");
            if (curr == Head)
                addbeg(&Head, newData);
            else
                addafter(curr->prev, newData);
            traverse(Head);
            updateFile(Fmusic, Head);
            printf("\nSuccesfully Added.\n");
            break;
        case 'R':
            if (Head == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            printf("\nEnter the name of the track which is needed to be removed : \n");
            fgets(Track, 15, stdin);
            curr = searchbydata(Head, Track);
            if (curr != NULL)
            {
                delnode(&Head, curr);
                traverse(Head);
                updateFile(Fmusic, Head);
            }
            else
                printf("Track doesn't exist in the List.\n");
            break;
        case 'O':
            if (Head == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            sort(&Head);
            printf("\nSorted List :\n");
            traverse(Head);
            printf("\n");
            updateFile(Fmusic, Head);
            break;
        case 'D':
            if (Head == NULL)
            {
                printf("The playlist is empty.\n");
                break;
            }
            printf("\n\nAll Tracks are displayed below :- \n");
            traverse(Head);
            printf("\n");
            break;
        case 'T':
            printf("Music Player Closed.\n");
            break;
        default:
            printf("Invalid Choice... Try Again...\n");
            break;
        }
    } while (ch != 'T');
    fclose(Fmusic);
    return 0;
}

Node *createNode(char *name)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->name = strdup(name);
    tmp->next = tmp->prev = NULL;
    return tmp;
}
void append(Node **Head, char *Track)
{
    Node *newNode = createNode(Track);
    if (*Head == NULL)
    {
        newNode->next = newNode->prev = newNode;
        *Head = newNode;
        return;
    }
    Node *last = (*Head)->prev;
    newNode->prev = last;
    newNode->next = *Head;
    last->next = newNode;
    (*Head)->prev = newNode;
}
void traverse(Node *Head)
{
    Node *curr = Head;
    printf("\n");
    do
    {
        fprintf(stdout, "%s", curr->name);
        curr = curr->next;
    } while (curr != Head);
    printf("\n");
}
Node *searchbypos(Node *Head, int pos)
{
    Node *tmp = Head;
    int count = 1;
    do
    {
        if (count == pos)
            return tmp;
        ++count;
        tmp = tmp->next;
    } while (tmp != Head);
    return NULL;
}
Node *searchbydata(Node *Head, char *data)
{
    Node *curr = Head;
    do
    {
        if (strcmp(data, curr->name) == 0)
            return curr;
        curr = curr->next;
    } while (curr != Head);
    return NULL;
}

Node *play(Node *Head, int pos)
{
    Node *tmp = Head;
    if (pos == -1)
        return tmp->prev;
    else
        return searchbypos(tmp, pos);
}
void addafter(Node *ptr, char *newTracks)
{
    Node *newNode = createNode(newTracks);
    newNode->prev = ptr;
    newNode->next = ptr->next;
    ptr->next = ptr->next->prev = newNode;
}
void updateFile(FILE *music, Node *Head)
{
    music = fopen("Music.txt", "w+");
    fseek(music, SEEK_SET, 0);
    Node *curr = Head;
    do
    {
        fputs(curr->name, music);
        curr = curr->next;
    } while (curr != Head);
}

void addbeg(Node **Head, char *newTracks)
{
    Node *newNode = createNode(newTracks);
    if (*Head == NULL)
    {
        newNode->next = newNode->prev = newNode;
        *Head = newNode;
        return;
    }
    Node *last = (*Head)->prev;
    newNode->next = *Head;
    newNode->prev = last;
    last->next = newNode;
    (*Head)->prev = newNode;
    *Head = newNode;
}

void delnode(Node **Head, Node *curr)
{
    Node *tmp = NULL;
    if (curr == *Head && (*Head)->next == *Head)
    {
        tmp = *Head;
        (*Head) = NULL;
        free(tmp);
        return;
    }
    else if (curr == (*Head))
    {
        tmp = *Head;
        (*Head)->prev->next = (*Head)->next;
        (*Head)->next->prev = (*Head)->prev;
        (*Head) = (*Head)->next;
        free(tmp);
        return;
    }
    tmp = curr;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(tmp);
}
void sort(Node **Head)
{
    Node *Head2 = NULL, *curr = *Head, *tmp;
    do
    {
        tmp = curr->next;
        insertSorted(&Head2, createNode(curr->name));
        free(curr);
        curr = tmp;
    } while (curr != *Head);
    *Head = Head2;
}
void insertSorted(Node **Head, Node *tmp)
{
    if (*Head == NULL)
    {
        tmp->next = tmp->prev = tmp;
        *Head = tmp;
        return;
    }
    else if (strcmp((*Head)->name, tmp->name) > 0)
    {
        addbeg(Head, tmp->name);
        return;
    }
    Node *curr = (*Head);
    while (curr->next != *Head && strcmp(curr->next->name, tmp->name) < 0)
    {
        curr = curr->next;
    }
    tmp->next = curr->next;
    tmp->prev = curr;
    curr->next->prev = tmp;
    curr->next = tmp;
}
