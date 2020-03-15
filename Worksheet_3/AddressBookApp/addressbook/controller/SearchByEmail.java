package addressbook.controller;

import addressbook.model.*;

public class SearchByEmail implements Option
{
    private AddressBook book;

    SearchByEmail()
    {
        book = null;
    }

    public void set_address_book(AddressBook book)
    {
        this.book = book;
    }

    public boolean needs_input()
    {
        return true;
    }
    
    public String do_option(String query)
    {
        Entry e = book.get_entry_by_email(query);
        return e == null ? "No result" : e.toString();
    }
}
