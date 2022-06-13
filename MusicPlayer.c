
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Track
{
    char name[15];
}Track;
typedef struct st
{
    struct st *next, *prev;
    char *name;
}Node;
int storeData(FILE *music, Track *details);
void storeinLinkedList(Node **Head, Track *details, int no_of_tracks);
Node *createNode(char name[]);
void traverse(Node *Head);
Node *searchbydata(Node *Head, char *data);
Node *searchbypos(Node *Head, int pos);
Node *play(Node *Head, int pos);
void addafter(Node *Head, char *newTracks);
void addbeg(Node **Head, char *newTracks);
void updateFile(FILE *music, Node *Head);

int main()
{
    Node *Head = NULL, *Currentplayed, *curr;
    FILE *Fmusic = fopen("Music.txt", "r");
    Track details[10];
    int no_of_tracks = storeData(Fmusic, details);
    char ch, dump, Track[15], newData[15];
    int i, trackNo, posi;
    storeinLinkedList(&Head, details, no_of_tracks);
    traverse(Head);
    printf("\n");
    curr = Head;
    do
    {
        printf("\nPress S : Start the Player.\n");
        printf("Press J : Jump to a Specific track.\n");
        printf("Press N : Play Next Track.\n");
        printf("Press F : Play First Track.\n");
        printf("Press L : Play Last Track.\n");
        printf("Press A : Add a track after an existing track.\n");
        printf("Press B : Add a track before an existing track.\n");
        printf("Press R : Remove a specific track from the list.\n");
        printf("Press O : Sort the tracks in alphabetical order.\n");
        printf("Press T : Stop The Player.\n");
        printf("Press C : Change all tracks posi.\n");
        printf("Press D : Display all tracks, Add a *besides the current tracks.\n");
        printf("Enter Your Choice : \n");
        scanf("%c%c", &ch, &dump);
        switch (ch)
        {
        case 'S':
            printf("\n\nMusic Player Starts...\nPlaying First Track :- ");
            Currentplayed = play(Head, 1);
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'J':
            printf("\nEnter the name of the track to be played :\n");
            fgets(Track, 15, stdin);
            Currentplayed = searchbydata(Head, Track);
            printf("\n\nNow Playing... :- ");
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'N':
            printf("\n\nNow Playing... :- ");
            Currentplayed = Currentplayed->next;
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'F':
            printf("\n\nNow Playing... :- ");
            Currentplayed = play(Head, 1);
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'L':
            printf("\n\nNow Playing... :- ");
            Currentplayed = play(Head, -1);
            fprintf(stdout, "%s", Currentplayed->name);
            printf("\n\n");
            break;
        case 'A':
            printf("\nEnter the name of the track after which new track is to added : \n");
            fgets(Track, 15, stdin);
            printf("Enter new Track name : \n");
            fgets(newData, 15, stdin);
            curr = searchbydata(Head, Track);
            addafter(curr, newData);
            traverse(Head);
            updateFile(Fmusic, Head);
            printf("\nSuccesfully Added.\n");
            break;
        case 'B':
            printf("\nEnter the name of the track before which new track is to added : \n");
            fgets(Track, 15, stdin);
            printf("Enter new Track name : \n");
            fgets(newData, 15, stdin);
            curr = searchbydata(Head, Track);
            if(curr == Head) 
                addbeg(Head, newData);
            else
                addafter(curr->prev, newData);
            traverse(Head);
            updateFile(Fmusic, Head);
            printf("\nSuccesfully Added.\n");
            break;
        case 'T':
            printf("Music Player Closed.\n");
            break;
        default:
            printf("Invalid Choice... Enter your choice again : \n");
            break;
        }
    }while(ch != 'T');
    fclose(Fmusic);
    return 0;
}
int storeData(FILE *music, Track *details)
{
    int count=0;
    while((fgets(details[count].name, 15, music) != NULL))
    {
        count++;
    }
    return count;
}
Node *createNode(char *name)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->name = strdup(name);
    tmp->next = tmp->prev = NULL;
    return tmp;
}

void storeinLinkedList(Node **Head, Track *details, int no_of_tracks)
{
    int i=0;
    Node *newNode = createNode(details[0].name);
    if(*Head == NULL)
    {
        newNode->next = newNode->prev = newNode;
        *Head = newNode;
    }
    for(i=1; i<no_of_tracks; i++)
    {
        newNode = createNode(details[i].name);
        newNode->next = (*Head);
        newNode->prev = (*Head)->prev;
        (*Head)->prev = (*Head)->prev->next = newNode;
    }
}
void traverse(Node *Head)
{
    Node *curr = Head;
    do
    {
        fprintf(stdout, "%s", curr->name);
        curr = curr->next;
    }
    while (curr != Head);
    
}
Node *searchbypos(Node *Head, int pos)
{
    Node *tmp = Head;
    int count = 1;
    while(tmp != NULL)
    {
        if(count == pos)
            return tmp;
        ++count;
        tmp = tmp->next;
    }
}
Node *searchbydata(Node *Head, char *data)
{
    Node *curr = Head;
    do
    {
        if(strcmp(data, curr->name) == 0)
            return curr;
        curr = curr->next;
    }while(curr != Head);
}

Node *play(Node *Head, int pos)
{
    Node *tmp = Head;
    if(pos == -1)
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
    if(*Head == NULL)
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
