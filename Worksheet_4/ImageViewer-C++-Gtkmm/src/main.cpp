/**
 * A simple image viewer application.
 */

#include <gtkmm/main.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "MainWindow.h"
#include "Album.h"

bool readAlbumFile(char *filename, Album *album);

int main(int argc, char **argv) 
{
    char filename[64];
    
    // Input the album filename.
    printf("Enter the album file name: ");
    scanf("%63s", filename);
    
    // Initialise GTK.
    Gtk::Main kit(argc, argv);
    
    // Construct an album object.
    Album *album = new Album();

    int exitCode;
    
    // Read an album file.
    if(readAlbumFile(filename, album))
    {
        // Construct new window object (on the stack; hence no "=" sign and no pointers).
        MainWindow window(album);

        // Run the GUI.
        Gtk::Main::run(window);   
        exitCode = 0;
    }
    else
    {
        std::cerr << "Error while reading " << filename << std::endl;
        exitCode = 1;
    }
    return exitCode;
}

/**
 * Reads an album file, given a filename and an Album object. Returns true if
 * successful, or false if the file could not be read.
 */
bool readAlbumFile(char *filename, Album *album)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL) return false;
    char buf[256];
    while(fgets(buf, 256, file))
    {
        char *token = strtok(buf, ":");
        char *name = (char*) malloc(sizeof(char) * (strlen(token) + 1));
        strncpy(name, token, strlen(token) + 1);

        token = strtok(NULL, ":");
        char *caption = (char*) malloc(sizeof(char) * (strlen(token) + 1));
        strncpy(caption, token, strlen(token) + 1);

        ImageInterface *img = new Image(name, caption);

        while((token = strtok(NULL, ":")))
        {
            if(strstr(token, "gps"))
            {
                int latitude, longitude, elevation;
                sscanf(token, "gps=%d %d %d", &latitude, &longitude, &elevation);
                img = new GPS(latitude, longitude, elevation, img);
            }
            else if(strstr(token, "rating"))
            {
                int rating;
                sscanf(token, "rating=%d", &rating);
                img = new Rating(rating, img);
            }
            else if(strstr(token, "date"))
            {
                // Date format is just the year. E.g. 1995 so 4 characters and 1 null byte
                char *date = (char *) malloc(sizeof(char) * 5);
                sscanf(token, "date=%s\n", date);
                img = new Date(date, img);
            }
        }
        album->add_image(img);
    }
    fclose(file);
    album->init_iterator();

    return true;
}
