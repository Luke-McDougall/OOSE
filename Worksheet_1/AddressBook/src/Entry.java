import java.util.*;
        
/**
 * Represents a single address book entry.
 * 
 * @author Luke McDougall 17179492
 */
public class Entry 
{
    private String name;
    // HashSet is used because there should not be any duplicate email addresses
    private HashSet<String> email_addresses;

    public Entry()
    {
        name = null;
        email_addresses = null;
    }

    public void set_name(String name)
    {
        this.name = name;
    }

    public void add_email(String email)
    {
        if(email_addresses == null)
        {
            email_addresses = new HashSet<String>();
        }
        email_addresses.add(email);
    }

    public String get_name()
    {
        return name;
    }

    public HashSet<String> get_email_addresses()
    {
        return email_addresses;
    }

    public String toString()
    {
        String value = "Name: " + name + "\nEmails: ";
        for(String email : email_addresses)
        {
            value += (email + "\n        ");
        }
        value += "\n";
        return value;
    }

    public boolean equals(Entry other)
    {
        return other.get_name().equals(name) && email_addresses.equals(other.get_email_addresses());
    }

    public int hashCode()
    {
        return Objects.hash(name, email_addresses);
    }
}
