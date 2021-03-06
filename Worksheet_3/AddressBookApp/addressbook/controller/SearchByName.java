package addressbook.controller;

import java.util.*;
import addressbook.model.*;

public class SearchByName implements Option
{
    private AddressBook book;

    SearchByName()
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
        Entry e = book.get_entry_by_name(query);
        return e == null ? "No result" : e.toString();
    }
}
