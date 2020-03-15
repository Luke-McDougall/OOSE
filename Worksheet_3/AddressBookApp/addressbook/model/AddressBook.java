package addressbook.model;

import java.util.*;
import java.io.*;

/**
 * Contains all the address book entries.
 * 
 * @author Luke McDougall 17179492
 */
public class AddressBook
{
    private HashMap<String, Entry> names;
    private HashMap<String, Entry> emails;

    public AddressBook()
    {
        names = null;
        emails = null;
    }

    public void add_name_entry(String name, Entry new_entry)
    {
        if(names == null)
        {
            names = new HashMap<String, Entry>();
        }
        names.put(name, new_entry);
    }

    public void add_email_entry(String email, Entry new_entry)
    {
        if(emails == null)
        {
            emails = new HashMap<String, Entry>();
        }
        emails.put(email, new_entry);
    }

    public Entry get_entry_by_name(String name)
    {
        return names.get(name);
    }

    public Entry get_entry_by_email(String email)
    {
        return emails.get(email);
    }

    public Collection<Entry> get_entries()
    {
        return names.values();
    }

    /**
     * Read the address book file, containing all the names and email addresses.
     *
     * @param fileName The name of the address book file.
     * @throws IOException If the file cannot be read.
     */
    public void read_address_book(String file_name) throws IOException
    {
        
        BufferedReader reader = new BufferedReader(new FileReader(file_name));
        String line = reader.readLine();
        while(line != null)
        {
            String[] parts = line.split(":");

            Entry entry = new Entry();
            entry.set_name(parts[0]);
            for(int i = 1; i < parts.length; i++)
            {
                entry.add_email(parts[i]);
            }

            this.add_name_entry(parts[0], entry);
            for(int i = 1; i < parts.length; i++)
            {
                this.add_email_entry(parts[i], entry);
            }
            
            line = reader.readLine();
        }
        reader.close();
    }
}
