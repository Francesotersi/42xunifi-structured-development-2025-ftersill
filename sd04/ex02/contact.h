#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 1000
#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_CITY_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char city[MAX_CITY_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
    int max_id;
} ContactBook;

#endif