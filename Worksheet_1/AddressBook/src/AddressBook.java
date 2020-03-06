import java.util.*;

/**
 * Contains all the address book entries.
 * 
 * @author Luke McDougall 17179492
 */
public class AddressBook
{
    // Two maps so that you can search for an entry by name or by email
    private Map<String, Entry> names;
    private Map<String, Entry> emails;

    public AddressBook()
    {
        names = new HashMap<String, Entry>();
        emails = new HashMap<String, Entry>();
    }

    // Add an entry to the names map
    public void add_name_entry(String name, Entry new_entry)
    {
        names.put(name, new_entry);
    }

    // Add an entry to the emails map
    public void add_email_entry(String email, Entry new_entry)
    {
        emails.put(email, new_entry);
    }

    // Search for an entry by name
    public Entry get_entry_by_name(String name)
    {
        return names.get(name);
    }

    // Search for an entry by email
    public Entry get_entry_by_email(String email)
    {
        return emails.get(email);
    }
}
