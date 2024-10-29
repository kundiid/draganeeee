#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
typedef struct cvor {

	int god;
	char ime[M];
	char prezime[M];
	struct cvor* next;
	

}cvor;

void unesi_na_kraj(cvor*, char*, char*, int);
void unos_varijabli(char*, char*, int*);
void print_liste(cvor*);
void unesi_naprijed(cvor*, char*, char*, int);
cvor* pronajdi_po_prezimenu(cvor*, char*);
void unesi_nakon_clana(cvor*, char*, char*, int, cvor*);
void oslobodi_listu(cvor*);
void sort(cvor* head);

int main() {


	cvor* head = (cvor*)malloc(sizeof(cvor));
	if (head == NULL) {
		exit(1);
	}
	head->next = NULL;


	char i[M], p[M];
	int o;

	unos_varijabli(i, p, &o);
	unesi_na_kraj(head, i, p, o);
	print_liste(head);

	unos_varijabli(i, p, &o);
	unesi_na_kraj(head, i, p, o);
	print_liste(head);

	unos_varijabli(i, p, &o);
	unesi_naprijed(head, i, p, o);
	print_liste(head);

	unos_varijabli(i, p, &o);
	printf("Unesite prezime osobe nakon koje zelite dodati: "); scanf("%s", p);

	unesi_nakon_clana(head, i, p, o, pronajdi_po_prezimenu(head, p) );
	print_liste(head);

	oslobodi_listu(head);
	

	return 0;
}

void unos_varijabli(char* ime, char* prezime, int* god) {

	printf("Unesi osobu :\n");
	printf("Unesi ime : ");
	scanf("%s", ime);
	printf("Unesi prezime : ");
	scanf("%s", prezime);
	printf("Unesi God : ");
	scanf("%d", god);
	return;
}

void unesi_na_kraj(cvor* head, char* ime, char* prezime, int god) {

	cvor* novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	cvor* curr = head;

	while (curr->next != NULL) {
		curr = curr->next;
	}

	novi->next = NULL;
	curr->next = novi;
}

void print_liste(cvor* head) {
	printf("\nIme\tPrezime\tGod:\n");

	cvor* curr = head->next;

	while (curr != NULL) {
		printf("%s\t%s\t%d\n", curr->ime, curr->prezime, curr->god);
		curr = curr->next;
	}
	printf("\n");
}

void unesi_naprijed(cvor* head, char* ime, char* prezime, int god) {

	cvor* novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	cvor* curr = head;
	novi->next = curr->next;
	curr->next = novi;
}

cvor* pronajdi_po_prezimenu(cvor* head, char* prezime) {

	cvor* curr = head;
	while (curr != NULL) {

		if (strcmp(curr->prezime, prezime) == 0) {

			return curr;
		}
		curr = curr->next;
		
	}
	return NULL;
}

void unesi_nakon_clana(cvor* head, char* ime, char* prezime, int god, cvor * trazeni) {

	cvor* novi = (cvor*)malloc(sizeof(cvor));
	if (novi == NULL) {
		exit(1);
	}

	strcpy(novi->ime, ime);
	strcpy(novi->prezime, prezime);
	novi->god = god;

	
	trazeni->next = novi;
	novi->next = trazeni->next->next;

}

void oslobodi_listu(cvor* head) {

	cvor* curr = head;

	while (curr != NULL) {

		cvor* temp = curr;
		curr = curr->next;
		free(temp);

	}

	curr->next = NULL;
}


	void sort(cvor * head){

		cvor* curr = head;
		bool swaped = true;
		if (!curr->next || curr->next->next) {
			return;
		}


		while (swaped) {
			curr = head;
			swaped = false;
			while (curr->next->next) {
				if (curr->next->ime, curr->next->next->ime) {
					swaped = true;
					cvor* prvi = curr->next;
					cvor* drugi = curr;
					prvi->next = drugi->next;
					drugi->next = prvi;
					curr->next = drugi;



				}
				curr = curr->next;


			}


		}

	}
