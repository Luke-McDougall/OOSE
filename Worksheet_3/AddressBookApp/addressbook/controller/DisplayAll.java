package addressbook.controller;

import addressbook.model.*;

public class DisplayAll implements Option
{
    private AddressBook book;

    DisplayAll()
    {
        book = null;
    }

    public void set_address_book(AddressBook book)
    {
        this.book = book;
    }

    public boolean needs_input()
    {
        return false;
    }

    public String do_option(String query) // Query should always be null for this subclass
    {
        String result = new String();
        for(Entry e : book.get_entries())
        {
            result += e.toString();
        }
        return result;
    }
}
