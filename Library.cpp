#include "Library.h"
#include <iostream>

Library::Library()
{
    numBooks = 0;
    firstBook = nullptr;
    lastBook = nullptr;
}

//Copy constructor
Library::Library( Library& other)
{
   //  implement this function
   numBooks = 0;
   LibraryBook * temp = other.getFirstBook();
   firstBook = nullptr;
   lastBook = nullptr;
   while(temp!=nullptr){
      addBook(temp->book);
      temp=temp->next;
   }
}

int Library::getnumBooks() const
{
    return numBooks;
}

LibraryBook* Library::getFirstBook()
{
   return firstBook;
}
LibraryBook* Library::getLastBook()
{
   return lastBook;
}

// return a pointer to the n'th book in the linked list
LibraryBook* Library::getBook( const int pos )
{
  // implement this function
  // check if it really starts at 1st book
  LibraryBook* res = firstBook;
  //may be off by one here
  if(pos >= numBooks){
     cout << "Book at position " << pos << " not available.";
  }
  else{
   for(int i = 0; i < pos; i++){
      res = res->next;
   }
  }
  return res;
}

// add a Book to the end of the linked list
void Library::addBook(Book book)
{
   // implement this function
   numBooks += 1;
   LibraryBook* temp = new LibraryBook();
   temp->book = book;
   if(this->firstBook == nullptr){
      this->firstBook = temp;
      this->lastBook = temp;
   }else{
      this->lastBook->next = temp;
      temp ->prev = this->lastBook;
      temp ->next = nullptr;
      this->lastBook = temp;
   }

}


// Move a book to the front of the linked list
void Library::moveToFront (LibraryBook *entry)
{
   // implement this function
   if(entry->next == nullptr){
      entry->prev->next = nullptr;
   }else{
      entry->prev->next = entry->next;
      entry->next->prev = entry->prev;
   }
   
   entry->next = firstBook;
   entry->prev = nullptr;
   this->firstBook = entry;

}

// print all Books
void Library::printAllBooks() const
{
   // implement this function
   LibraryBook* cur = firstBook;
   while(cur != nullptr){
      cur->book.printBook();
      cur = cur->next;
   }
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(string genre)
{
   // implement this function
   LibraryBook* cur = firstBook;
   while(cur != nullptr){
      if(cur->book.getGenre() == genre){
         cur->book.printBook();
      }
      cur = cur->next;
   }
}
