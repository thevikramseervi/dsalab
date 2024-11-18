//                 ========== DSA CASE STUDIES ==========
//                    By: Akshay S and B Vikram Seervi
//
//               ======== 1. MUSIC PLAYLIST SYSTEM ========

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
  char title[50];
  char artist[50];
  char genre[30];
  struct Song *next;
  struct Song *prev;
};

struct Song *head = NULL;
struct Song *tail = NULL;
struct Song *current = NULL;

void addSong(char title[], char artist[], char genre[]);
void displayPlaylist();
void displayCurrentSong();
void playNext();
void playPrevious();
void switchToSong(char title[]);
void displayByGenre();

int main() {
  int choice;
  char title[50], artist[50], genre[30];

  do {
    printf("\n=== Music Playlist System ===\n");
    printf("1. Add a Song\n");
    printf("2. Display Playlist\n");
    printf("3. Display Current Song\n");
    printf("4. Play Next Song\n");
    printf("5. Play Previous Song\n");
    printf("6. Switch to a Song\n");
    printf("7. Display Songs by Genre\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Clear input buffer

    switch (choice) {
    case 1:
      printf("Enter song title: ");
      scanf(" %[^\n]", title);
      printf("Enter artist: ");
      scanf(" %[^\n]", artist);
      printf("Enter genre: ");
      scanf(" %[^\n]", genre);
      addSong(title, artist, genre);
      break;

    case 2:
      displayPlaylist();
      break;
    case 3:
      displayCurrentSong();
      break;
    case 4:
      playNext();
      break;
    case 5:
      playPrevious();
      break;
    case 6:
      printf("Enter song title to switch to: ");
      scanf(" %[^\n]", title);
      switchToSong(title);
      break;
    case 7:
      displayByGenre();
      break;
    case 8:
      printf("Exiting... Thank you!\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 8);

  return 0;
}

// Add a song to the playlist
void addSong(char title[], char artist[], char genre[]) {
  struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
  strcpy(newSong->title, title);
  strcpy(newSong->artist, artist);
  strcpy(newSong->genre, genre);
  newSong->next = NULL;
  newSong->prev = NULL;

  if (head == NULL) {
    head = tail = newSong;
  } else {
    tail->next = newSong;
    newSong->prev = tail;
    tail = newSong;
  }

  if (current == NULL) {
    current = head;
  }

  printf("Song '%s' by %s added to the playlist.\n", title, artist);
}

// Display all songs in the playlist
void displayPlaylist() {
  struct Song *temp = head;
  if (temp == NULL) {
    printf("Playlist is empty.\n");
    return;
  }
  printf("\n=== Playlist ===\n");
  while (temp != NULL) {
    printf("Title: %s, Artist: %s, Genre: %s\n", temp->title, temp->artist,
           temp->genre);
    temp = temp->next;
  }
}

// Play the next song
void playNext() {
  if (current == NULL) {
    printf("No song is currently playing.\n");
    return;
  }
  if (current->next != NULL) {
    current = current->next;
    printf("Now playing: '%s' by %s\n", current->title, current->artist);
  } else {
    printf("You are at the last song in the playlist.\n");
  }
}

// Play the previous song
void playPrevious() {
  if (current == NULL) {
    printf("No song is currently playing.\n");
    return;
  }
  if (current->prev != NULL) {
    current = current->prev;
    printf("Now playing: '%s' by %s\n", current->title, current->artist);
  } else {
    printf("You are at the first song in the playlist.\n");
  }
}

// Switch to a specific song
void switchToSong(char title[]) {
  struct Song *temp = head;
  while (temp != NULL) {
    if (strcmp(temp->title, title) == 0) {
      current = temp;
      printf("Switched to: '%s' by %s\n", current->title, current->artist);
      return;
    }
    temp = temp->next;
  }
  printf("Song '%s' not found in the playlist.\n", title);
}

// Display all songs grouped by genres
void displayByGenre() {
  struct Song *temp = head;
  char genres[100][30];
  int genreCount = 0;

  if (temp == NULL) {
    printf("Playlist is empty.\n");
    return;
  }

  // Collect unique genres
  while (temp != NULL) {
    int printed = 0;
    for (int i = 0; i < genreCount; i++) {
      if (strcmp(genres[i], temp->genre) == 0) {
        printed = 1;
        break;
      }
    }
    if (!printed) {
      strcpy(genres[genreCount], temp->genre);
      genreCount++;
    }
    temp = temp->next;
  }

  // Display songs grouped by genres
  printf("\n=== Songs Grouped by Genres ===\n");
  for (int i = 0; i < genreCount; i++) {
    printf("\n--- Genre: %s ---\n", genres[i]);
    temp = head;
    while (temp != NULL) {
      if (strcmp(temp->genre, genres[i]) == 0) {
        printf("Title: %s, Artist: %s\n", temp->title, temp->artist);
      }
      temp = temp->next;
    }
  }
}

// Display the currently playing song
void displayCurrentSong() {
  if (current == NULL) {
    printf("\nNo song is currently playing.\n");
  } else {
    printf("\n=== Currently Playing ===\n");
    printf("Title: %s\n", current->title);
    printf("Artist: %s\n", current->artist);
    printf("Genre: %s\n", current->genre);
  }
}

//              ============= THANK YOU =================

