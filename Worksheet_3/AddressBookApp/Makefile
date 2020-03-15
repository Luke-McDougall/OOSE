CC=javac
CP=~/OOSE/Worksheet_3/AddressBookApp/addressbook

$(CP)/model/Entry.class: $(CP)/model/Entry.java
	$(CC) $(CP)/model/Entry.java

$(CP)/model/AddressBook.class: $(CP)/model/AddressBook.java $(CP)/model/Entry.class
	$(CC) $(CP)/model/AddressBook.java

$(CP)/controller/Option.class: $(CP)/controller/Option.java $(CP)/model/AddressBook.class
	$(CC) $(CP)/controller/Option.java

build: $(CP)/controller/Option.class
	$(CC) $(CP)/controller/SearchByName.java $(CP)/controller/SearchByEmail.java $(CP)/controller/DisplayAll.java
