#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Menu
{
    char *class, *order, *family, *genus, *species;
    struct Menu *next;
} Menu;
Menu *add_species(char *class, char *order, char *family, char *genus, char *species)
{
    Menu *l = (Menu *)malloc(sizeof(Menu));
    l->class = (char *)malloc(strlen(class) + 1);
    strcpy(l->class, class);
    l->order = (char *)malloc(strlen(order) + 1);
    strcpy(l->order, order);
    l->family = (char *)malloc(strlen(family) + 1);
    strcpy(l->family, family);
    l->genus = (char *)malloc(strlen(genus) + 1);
    strcpy(l->genus, genus);
    l->species = (char *)malloc(strlen(species) + 1);
    strcpy(l->species, species);
    /*lin tüm değerleri burada giriliyor*/
    l->next = NULL;
    return l;
}

void swap_species(Menu *node1, Menu *node2)
{
    char *temp;
    temp = node1->class;
    node1->class = node2->class;
    node2->class = temp;
    temp = node1->order;
    node1->order = node2->order;
    node2->order = temp;
    temp = node1->family;
    node1->family = node2->family;
    node2->family = temp;
    temp = node1->genus;
    node1->genus = node2->genus;
    node2->genus = temp;
    temp = node1->species;
    node1->species = node2->species;
    node2->species = temp;
}
void sort_by_criteria(Menu **list, char *criteria)
{
    Menu *current = *list;
    Menu *curr_next = NULL;
    int isvalid = 0;
    if (current == NULL)
    {
        printf("There is no list\n");
        return;
    }
    else
    {
        while (current)
        {
            curr_next = current->next;
            while (curr_next)
            {
                if ((strcmp(criteria, "class")) == 0)
                {
                    if ((strcmp(current->class, curr_next->class)) > 0)
                    {
                        swap_species(current, curr_next);
                    }
                }
                else if ((strcmp(criteria, "order")) == 0)
                {
                    if ((strcmp(current->order, curr_next->order)) > 0)
                    {
                        swap_species(current, curr_next);
                    }
                }
                else if ((strcmp(criteria, "family")) == 0)
                {
                    if ((strcmp(current->family, curr_next->family)) > 0)
                    {
                        swap_species(current, curr_next);
                    }
                }
                else if ((strcmp(criteria, "genus")) == 0)
                {
                    if ((strcmp(current->genus, curr_next->genus)) > 0)
                    {
                        swap_species(current, curr_next);
                    }
                }
                else if ((strcmp(criteria, "species")) == 0)
                {
                    if ((strcmp(current->species, curr_next->species)) > 0)
                    {
                        swap_species(current, curr_next);
                    }
                }
                else
                {
                    isvalid = 1;
                    break;
                }
                curr_next = curr_next->next;
            }
            if (isvalid == 1)
            {
                printf("Invalid criteria!!\n\n");
                break;
            }
            current = current->next;
        }
    }
}

void delete_species(Menu **list, char *species)
{
    Menu *current = *list;
    Menu *prev = NULL;
    Menu *temp = NULL;

    if (!current)
    {
        printf("There is no list\n\n");
        return;
    }

    if (strcmp(current->species, species) == 0)
    {
        temp = current;
        *list = current->next;
        free(temp);
        return;
    }
    while (current != NULL && strcmp(current->species, species) != 0)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Species not found in the list\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void print_list(Menu *list)
{
    if (list == NULL)
    {
        printf("There is no list");
    }
    else
    {
        while (list != NULL)
        {
            printf("Class: %s\n", list->class);
            printf("Order: %s\n", list->order);
            printf("Family: %s\n", list->family);
            printf("Genus: %s\n", list->genus);
            printf("Species: %s\n\n", list->species);
            list = list->next;
        }
    }
}

Menu *modify_list(Menu *list, char *species){
	Menu *current=list;
    char class[25],order[25],family[25],genus[25], new_species[25];
    if(!current){
        printf("cannot find the list\n");
        return list;
    }
    while(current){
        if((strcmp(current->species,species))==0){
            printf("Enter new informations\n");
            printf("New Class: ");
            scanf("%[^\n]s",class);
            getchar();
            printf("New Order: ");
            scanf("%[^\n]s",order);
            getchar();
            printf("New Family: ");
            scanf("%[^\n]s",family);
           getchar();
            printf("New Genus: ");
            scanf("%[^\n]s",genus);
            getchar();
            printf("New Species: ");
            scanf("%[^\n]s", new_species);
           getchar();
            free(current->class);
            free(current->order);
            free(current->family);
            free(current->genus);
            free(current->species);

            current->class = (char *)malloc(strlen(class) + 1);
            strcpy(current->class, class);
            current->order = (char *)malloc(strlen(order) + 1);
            strcpy(current->order, order);
            current->family = (char *)malloc(strlen(family) + 1);
            strcpy(current->family, family);
            current->genus = (char *)malloc(strlen(genus) + 1);
            strcpy(current->genus, genus);
            current->species = (char *)malloc(strlen(new_species) + 1);
            strcpy(current->species, new_species);
            printf("Species modified succesfully\n");
            return list;
        }
        current=current->next;
    }
    printf("Species could not find\n");
    return list;
}

int main()
{
    Menu *list = NULL, *head = NULL;
    char choice;
    char class[25], order[25], family[25], genus[25], species[25];
    char criteria[25], to_be_deleted[25],old_species[25];
    do
    {
        printf("Enter Species Information\n");
        printf("Class: ");
        scanf("%[^\n]s",class);
        getchar();
        printf("Order: ");
	scanf("%[^\n]s",order);
        getchar();
        printf("Family: ");
         scanf("%[^\n]s",family);
           getchar();
        printf("Genus: ");
        scanf("%[^\n]s",genus);
            getchar();
        printf("Species: ");
        scanf("%[^\n]s", species);
        getchar();
        if (head == NULL)
        {
            head = add_species(class, order, family, genus, species);
            list = head;
        }
        else
        {
            list->next = add_species(class, order, family, genus, species);
            list = list->next;
        }
        printf("Do you want to add more species? yes(y),no(n)\n");
        scanf(" %c", &choice);
        getchar(); /*to get rid of the new line which comes from scanf*/
    } while (choice != 'n');
    printf("List\n");
    print_list(head);
    printf("Enter list criteria (class, order, family, genus, species): ");
    scanf("%s", criteria);
    /*gtechar to get rid of \n character from the last scanf function*/
    getchar();
    sort_by_criteria(&head, criteria);
    printf("Sorted List\n");
    print_list(head);
    printf("Enter a species to delete\n");
    scanf("%[^\n]s", to_be_deleted);
    getchar();
    delete_species(&head, to_be_deleted);
    printf("List After Deletion\n");
    print_list(head);
    printf("Enter the species you want to modify\n");
    printf("Old species: ");
    scanf("%[^\n]s", old_species);
    getchar();
    head=modify_list(head,old_species);
    print_list(head);
    Menu *current=head;
    while(current){
        free(current->class);
        free(current->family);
        free(current->genus);
        free(current->order);
        free(current->species);
        current=current->next;
    }
    free(head);
}
