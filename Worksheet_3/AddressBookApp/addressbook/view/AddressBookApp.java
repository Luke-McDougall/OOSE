package addressbook.view;

import java.io.*;
import java.util.*;
import view.LoadDataException;

/**
 * A simple address book application.
 * @author Dave and ...
 */
public class AddressBookApp 
{
    /** Used to obtain user input. */
    private static Scanner input = new Scanner(System.in);
    private HashMap<Integer, Option> options;
    private AddressBook address_book;
    
    public static void main(String[] args)
    {
        String fileName, entryName;
        
        System.out.print("Enter address book filename: ");
        fileName = input.nextLine();
        AddressBookApp app = new AddressBookApp();
        
        try
        {
            app.readAddressBook(fileName);
            
            // Initialize options map
            app.add_option(1, new SearchByName(app.get_address_book()));
            app.add_option(2, new SearchByEmail(app.get_address_book()));
            app.add_option(3, new DisplayAll(app.get_address_book()));

            app.showMenu();
        }
        catch(IOException e)
        {
            System.out.println("Could not read from " + fileName + ": " + e.getMessage());
        }
    }

    public AddressBookApp()
    {
        options = new HashMap<Integer, Option>();
        addressBook = null;
    }

    public void load_address_book() throws LoadDataException
    {
        String file_name;
        address_book = new AddressBook();
        for(;;)
        {
            try
            {
                System.out.print("Enter address book filename: ");
                file_name = input.nextLine();
                address_book.read_address_book(file_name);
                break;
            }
            catch(IOException e)
            {
                System.out.println("Error: " + e.getMessage());
                System.out.println("Press y[es] to re-enter the file name.");
                String choice = input.nextLine();
                if(choice.length() < 1 || (choice.charAt(0) != 'y' && choice.charAt(0) != 'Y'))
                {
                    throw new LoadDataException("Data was not loaded.", e);
                }
            }
        }
    }

    public void add_option(int key, Option opt)
    {
        options.put(key, opt);
    }

    public AddressBook get_address_book()
    {
        return addressBook;
    }
    
    /**
     * Show the main menu, offering the user options to (1) search entries by 
     * name, (2) search entries by email, or (3) quit.
     *
     * @param addressBook The AddressBook object to search.
     */
    private void showMenu()
    {
        boolean done = false;
        while(!done)
        {
            int choice;
            System.out.println("(1) Search by name, (2) Search by email, (3) Display all entries, (4) Exit");
            
            try
            {
                choice = Integer.parseInt(input.nextLine());
                if(choice == 4)
                {
                    done = true;
                }
                else
                {
                    Option opt = options.get(choice);
                    if(opt != null)
                    {
                        String query = null;
                        if(opt.needs_input())
                        {
                            System.out.print("Enter search query: ");
                            query = input.nextLine();
                        }
                        System.out.println(opt.do_option(query));
                    }
                }
            }
            catch(NumberFormatException e)
            {
                // The user entered something non-numerical.
                System.out.println("Enter a number");
            }
        }
    }
}
