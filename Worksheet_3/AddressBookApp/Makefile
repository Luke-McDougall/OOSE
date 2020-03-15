CC=javac
CP=~/OOSE/Worksheet_3/AddressBookApp

$(CP)/addressbook/model/Entry.class: $(CP)/addressbook/model/Entry.java
	$(CC) $(CP)/addressbook/model/Entry.java

$(CP)/addressbook/model/AddressBook.class: $(CP)/addressbook/model/AddressBook.java $(CP)/addressbook/model/Entry.class
	$(CC) $(CP)/addressbook/model/AddressBook.java

$(CP)/addressbook/controller/Option.class: $(CP)/addressbook/controller/Option.java $(CP)/addressbook/model/AddressBook.class
	$(CC) $(CP)/addressbook/controller/Option.java

$(CP)/addressbook/controller/SearchByName.class: $(CP)/addressbook/controller/Option.class
	$(CC) $(CP)/addressbook/controller/SearchByName.java

$(CP)/addressbook/controller/SearchByEmail.class: $(CP)/addressbook/controller/Option.class
	$(CC) $(CP)/addressbook/controller/SearchByEmail.java

$(CP)/addressbook/controller/DisplayAll.class: $(CP)/addressbook/controller/Option.class
	$(CC) $(CP)/addressbook/controller/DisplayAll.java

$(CP)/addressbook/view/LoadDataException.class: $(CP)/addressbook/controller/DisplayAll.class $(CP)/addressbook/controller/SearchByEmail.class $(CP)/addressbook/controller/SearchByName.class
	$(CC) -cp $(CP) $(CP)/addressbook/view/LoadDataException.java

$(CP)/addressbook/view/AddressBookUI.class: $(CP)/addressbook/controller/DisplayAll.class $(CP)/addressbook/controller/SearchByEmail.class $(CP)/addressbook/controller/SearchByName.class
	$(CC) -cp $(CP) $(CP)/addressbook/view/AddressBookUI.java

$(CP)/addressbook/controller/AddressBookController.class: $(CP)/addressbook/view/AddressBookUI.class
	$(CC) $(CP)/addressbook/controller/AddressBookController.java

build: $(CP)/addressbook/controller/AddressBookController.class 
	$(CC) -cp $(CP) AddressBookApp.java
