package addressbook.controller;

import addressbook.view.*;

public class AddressBookController
{
    public static void run()
    {
        // TODO: Put some call to view here to get filename
        AddressBookUI ui = new AddressBookUI();

        try
        {
            ui.load_address_book();

            ui.add_option(1, new SearchByName());
            ui.add_option(2, new SearchByEmail());
            ui.add_option(3, new DisplayAll());

            ui.show_menu();
        }
        catch(LoadDataException e)
        {
            System.out.println(e.getMessage());
        }
    }
}
