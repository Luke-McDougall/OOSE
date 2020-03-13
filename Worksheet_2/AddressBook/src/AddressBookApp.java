import java.io.*;
import java.util.*;

/**
 * A simple address book application.
 * @author Dave and ...
 */
public class AddressBookApp 
{
    /** Used to obtain user input. */
    private static Scanner input = new Scanner(System.in);
    private static HashMap<Integer, Option> options;
    private AddressBook addressBook;
    
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

    public void add_option(int key, Option opt)
    {
        options.put(key, opt);
    }

    public AddressBook get_address_book()
    {
        return addressBook;
    }
    
    /**
     * Read the address book file, containing all the names and email addresses.
     *
     * @param fileName The name of the address book file.
     * @return A new AddressBook object containing all the information.
     * @throws IOException If the file cannot be read.
     */
    private void readAddressBook(String fileName) throws IOException
    {
        AddressBook addressBook = new AddressBook();
        
        BufferedReader reader = new BufferedReader(new FileReader(fileName));
        String line = reader.readLine();
        while(line != null)
        {
            String[] parts = line.split(":");
            
            // Insert your code here to add a new address book entry.
            // Note: 
            // parts[0] contains the person's name.
            // parts[1], parts[2], etc. contain the person's email address(es).

            Entry entry = new Entry();
            entry.set_name(parts[0]);
            for(int i = 1; i < parts.length; i++)
            {
                entry.add_email(parts[i]);
            }

            addressBook.add_name_entry(parts[0], entry);
            for(int i = 1; i < parts.length; i++)
            {
                addressBook.add_email_entry(parts[i], entry);
            }
            
            line = reader.readLine();
        }
        reader.close();
        
	    this.addressBook = addressBook;
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
