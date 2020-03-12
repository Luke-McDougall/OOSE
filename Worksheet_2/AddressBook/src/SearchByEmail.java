/* *
 * Luke McDougall
 */
public class SearchByEmail implements Option
{
    private AddressBook book;

    SearchByEmail(AddressBook book)
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
