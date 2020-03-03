import java.util.*;

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
}
