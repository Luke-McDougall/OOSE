package addressbook.controller;

import addressbook.model.*;

public interface Option
{
    public String do_option(String query);
    public boolean needs_input();
    public void set_address_book(AddressBook book);
}
