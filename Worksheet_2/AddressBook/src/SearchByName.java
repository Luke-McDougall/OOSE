import java.util.*;
public class SearchByName implements Option
{
    private AddressBook book;
    private Scanner input;

    SearchByName(AddressBook book)
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
