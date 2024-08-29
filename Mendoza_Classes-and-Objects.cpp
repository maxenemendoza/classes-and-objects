#include <iostream>
#include <iomanip>
using namespace std;

const int maxBooks = 100; // maximum number of books
const int columnWidth = 25; // width of columns 

class Library{
	private:
		string bookTitle, bookAuthor;
		int bookYear;
		
	public: 
		// function to set book title
		void setTitle (){ 
			cout << "Enter title: ";
			getline (cin, bookTitle); // accepts book titles with spaces
		}
		
		// function to get book title
		string getTitle () const{
			return bookTitle;
		}
		
		// function to set book author
		void setAuthor (){ 
			cout << "Enter author: ";
			getline (cin, bookAuthor); // accepts author name with spaces
		}
		
		// function to get book author
		string getAuthor () const{
			return bookAuthor;
		}
		
		// function to set book year
		void setYear (){ 
			cout << "Enter year: ";
			cin >> bookYear;
			cin.ignore();
		}
		
		// function to get book title
		int getYear () const{
			return bookYear;
		}
		
		// function to display book details
		void displayDetails () const{
			cout << left << setw(columnWidth) << bookTitle 
				 << left << setw(columnWidth) << bookAuthor 
				 << left << setw(columnWidth) << bookYear << endl;
		}
};

int main (){
	int menuChoice; // stores menu choice
	int bookCount = 0; // stores number of books
	string searchTitle; // stores title being searched
	
	Library bookCollection[maxBooks]; // stores collection of books
	
	// loop that displays menu until exit
	do {
		cout << "Maxene's Library" << endl << endl;
		cout << "MENU" << endl;
		cout << endl;
	
		cout << "1 - Add Book" << endl;
		cout << "2 - Display Books" << endl;
		cout << "3 - Search Book" << endl;
		cout << "4 - Exit" << endl;
		cout << endl;
		
		cout << "Enter choice: ";
		cin >> menuChoice; // allows user to input menu choice
		
		cout << endl;
		
		cin.ignore();
		
		switch (menuChoice){
			case 1: // add book
				if (bookCount < maxBooks){ // check if array has space for new book
					cout << "ADD BOOK" << endl;
					
					Library newBook; // create new book 
					
					// set details of new book 
					newBook.setTitle();
					newBook.setAuthor();
					newBook.setYear();
					
					// add new book to book collection and increment book count
					bookCollection[bookCount] = newBook;
					bookCount++;
					
					cout << endl;
					cout << "Book added successfully!" << endl;
					cout << endl;
				}
				
				else { // book collection is full
					cout << endl;
					cout << "Full library!" << endl;
					cout << endl;
				} 
				break;
				
			case 2: // display all books
				if (bookCount == 0){ // empty book collection
					cout << endl;
					cout << "Empty library!" << endl;
					cout << endl;
				}
				
				else { // displays all books
					cout << "DISPLAY BOOKS" << endl;
					cout << left << setw(columnWidth) << "Title" 
						 << left << setw(columnWidth) << "Author" 
						 << left << setw(columnWidth) << "Year" << endl;
                    cout << "---------------------------------------------------------" << endl;
					
					// loop that displays details of each book
					for (int i=0; i<bookCount; i++){
						bookCollection[i].displayDetails();
				} 
				cout << endl;
				break;
			}
			
			case 3: { // search book by title
				cout << "SEARCH BOOK" << endl;
				cout << "Enter title: ";
				getline (cin, searchTitle); // get title to be searched 
				
				bool bookFound = false; // assume that object is not found
				
				// loop that searches for book
				for (int i=0; i<bookCount; i++){
					if (bookCollection[i].getTitle() == searchTitle){
						cout << endl;
						cout << "Book found!" << endl;
						cout << endl;
						
						// display details of found book
						cout << "Title: " << bookCollection[i].getTitle() << endl;
						cout << "Author: " << bookCollection[i].getAuthor() << endl;
						cout << "Year: " << bookCollection[i].getYear() << endl;
						
						cout << endl;
						
						bookFound = true; // book is now found
						break;
					}
				}
				
				if (!bookFound){ // book is not found
						cout << endl;
						cout << "Book not found!" << endl;
						cout << endl;
					} 
				break;
			}
					
			case 4: // exit program
				cout << "Thank you for using Maxene's Library!" << endl;
				break;
			
			default: // invalid menu choice
				cout << "Invalid input! Enter a number from 1 to 4 only." << endl;
				cout << endl;
				break;
		}
			
	} while (menuChoice != 4); // loop until exit
	return 0;
}