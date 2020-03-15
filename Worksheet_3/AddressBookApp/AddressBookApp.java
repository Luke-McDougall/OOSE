public static void main(String[] args)
{
    // TODO: Put some call to view here to get filename
    AddressBookApp app = new AddressBookApp();

    try
    {
        app.readAddressBook(fileName);

        app.add_option(1, new SearchByName(app.get_address_book()));
        app.add_option(2, new SearchByEmail(app.get_address_book()));
        app.add_option(3, new DisplayAll(app.get_address_book()));

        app.showMenu();
    }
    // TODO: Change this part to handle more specific exception
    catch(IOException e)
    {
        System.out.println("Could not read from " + fileName + ": " + e.getMessage());
    }
}
