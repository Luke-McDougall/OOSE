#ifndef AMAZINGWINDOW_H
#define	AMAZINGWINDOW_H

#include <memory>
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/toolbutton.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>

#include "Album.h"

/**
 * Represents our window, inheriting from Gtk::Window.
 */
class MainWindow : public Gtk::Window
{
    public:
        MainWindow(Album* newAlbum);  // Constructor
        ~MainWindow();                // Destructor
        
        // Accessor for the album (not really needed here, but just for illustration).
        Album* getAlbum() const;
        
    private:
        // Called to handle button presses
        void nextBtnHandler();
        void prevBtnHandler();
        
        // Album field, containing image information.
        Album* album;
        
        // Notice the following fields are value-typed objects (not pointers). Basically, we're 
        // just providing a place for all these parts of the window (called "widgets") to exist in 
        // memory. They'll be automatically destructed when MainWindow is.
        Gtk::VBox mainBox; 
        Gtk::Toolbar toolbar;
        Gtk::ToolButton nextBtn;
        Gtk::ToolButton prevBtn;
        Gtk::ScrolledWindow scroller;
        Gtk::Image imageWidget;
        Gtk::Label captionWidget;
};

#endif
