#include "MainWindow.h"
#include <iostream>

/**
 * Constructor. We must initialise the GUI here, which includes creating and 
 * adding the GUI "widgets" and setting up callback functions.
 */
MainWindow::MainWindow(Album* newAlbum) :
    mainBox(),  // Value-typed object fields should be initialised here: "field(constructor args)"
    toolbar(),
    prevBtn("Previous"),
    nextBtn("Next"),
    scroller(),
    imageWidget(),
    captionWidget()
{
    album = newAlbum;
    
    // Set the window title (set_title is inherited from Gtk::Window).
    set_title("Gtk Image Viewer"); 
    
    // Set a default window size (or else it will probably be too small).
    set_default_size(400, 400);

    // *** Fix this code so that it loads the initial (first) image. ***
    Image *first_img = album->get_image();
    imageWidget.set(first_img->getFilename().c_str());
        
    // Add 'mainBox' to the window. This is a container for holding the other bits: the toolbar, 
    // scroller (containing the image), and caption.
    add(mainBox); 

    // Make the toolbar.
    mainBox.pack_start(toolbar, Gtk::PACK_SHRINK);
    toolbar.add(prevBtn);
    toolbar.add(nextBtn);

    // Set up nextBtnHandler() to be called when nextBtn is clicked, and similarly for prevBtn.
    prevBtn.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::prevBtnHandler));
    nextBtn.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::nextBtnHandler));
        
    // Set up the main image view.
    mainBox.pack_start(scroller, Gtk::PACK_EXPAND_WIDGET);
    scroller.add(imageWidget);    
    
    // Set up the caption. (The captionWidget is a Gtk::Label. Given its position at the bottom of 
    // the window, we would normally consider Gtk::Statusbar instead, but Label is simpler.)
    mainBox.pack_start(captionWidget, Gtk::PACK_SHRINK);
    // *** Fix this code so that it displays the caption for the first image. ***
    captionWidget.set_text(first_img->getCaption().c_str());
    
    // Tell all widgets to display themselves.
    show_all();
}

/**
 * Destructor. Destroy the album object.
 */
MainWindow::~MainWindow()
{    
    delete album;
}

/**
 * Retrieves the album by reference.
 */
Album* MainWindow::getAlbum() const
{
    return album;
}

/**
 * Called to handle "previous" button clicks.
 */
void MainWindow::prevBtnHandler()
{
    // *** Fix this code so that it actually displays the previous image & caption. ***
    album->prev_image();
    Image *img = album->get_image();
    imageWidget.set(img->getFilename().c_str());
    captionWidget.set_text(img->getCaption().c_str());
}

/**
 * Called to handle "next" button clicks.
 */
void MainWindow::nextBtnHandler()
{
    // *** Fix this code so that it actually displays the next image & caption. ***
    album->next_image();
    Image *img = album->get_image();
    imageWidget.set(img->getFilename().c_str());
    captionWidget.set_text(img->getCaption().c_str());
}

