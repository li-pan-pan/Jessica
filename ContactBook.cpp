#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX 30
#define TEL_MAX 20
#define ADDR_MAX 100

#define CONTACT_BOOK_MAX 100

typedef struct Contact
{
	char name[NAME_MAX];
	char tel[TEL_MAX];
	char address[ADDR_MAX];
	int age;
}Contact;

typedef struct ContactBook
{
	Contact array[CONTACT_BOOK_MAX];
	int size;
}ContactBook;


void ContactBookInit(ContactBook* pcb);
void ContactBookAdd(ContactBook* pcb, Contact* pc);
void ContactBookDel(ContactBook* pcb, char* name);
void ContactUpdate(ContactBook* pcb,Contact* pc);
Contact* ContactBookSearch(ContactBook* pcb, char* name);
void ContactBookPrint(ContactBook* pcb);
