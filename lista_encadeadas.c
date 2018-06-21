#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int id_increment = 0;

typedef struct field {
  int id;
  char content[1000];
  struct field *next;
} item;

item *items = NULL;

void create(char content[100])
{
  id_increment++;
  item* new;

  new = (item*)malloc(sizeof(item));
  new->id = id_increment;
  stpcpy(new->content, content);
  new->next = NULL;

  if (items == NULL)
  {
    items = new;
  }
  else 
  {
    new->next = items;
    items = new;
  }
  // f->next = new;
}
char *getText()
{
  char *text;
  printf("digite um texto: ");
  scanf("%s", text);
  return text;
}
void printItem(item* i)
{
  printf("ID: %d - CONTENT: %s \n\n", i->id, i->content);
}
void printAll()
{
  item* n;
  printf("--------- IMPRESSAO ----------\n");
  for (n = items; n != NULL; n = n->next)
  {
    printItem(n);
  }
  printf("--------- FIM DA IMPRESSAO ----------\n");
}
void printById(int id)
{
  item* n;
  printf("--------- IMPRESSAO ----------\n");
  for (n = items; n != NULL; n = n->next)
  {
    if (n->id == id)
    {
      printItem(n);
    }
  }
  printf("--------- FIM DA IMPRESSAO ----------\n");
}

void removeById(int id) 
{
  item* n;
  item* old = items;
  for (n = items; n != NULL; n = n->next)
  {
    if (n->id == id)
    {
      if (n == items) 
      {
        items = items->next;
        free(n);
      }
      else
      {
        old->next = n->next;
        free(n);
      }
    }
    else
    {
      old = n;
    }
  }
}
// void updateById(int id, char text[1000])
// {
//   item* n;
//   int updated = 0;
//   for (n = items; n != NULL; n = n->next)
//   {
//     if (n->id == id)
//     {
//       // strcpy(items->content, text);
//       updated = 1;
//     }
//   }

//   if (updated == 0) 
//   {
//     printf("falaha nao atualizado");
//   }
// }
int getId()
{
  int id;
  printf("Digite o ID: ");
  scanf("%d", &id);
  return id;
}
void callOpt(int opt)
{
  switch (opt)
  {
    case 1:
      create(getText());
    break;
    case 2:
      printAll();
    break;
    case 3:
      printById(getId());
    break;
    case 4:
      removeById(getId());
    break;
    // case 5:
    //   char text[1000];
    //   int id;
    //   id = getId();
    //   strcpy(text, getText());
    //   updateById(id, text);
    break;
    default:
      NULL;
    break;
  }
}
int main()
{
  int opt = 1234;
  while (opt != 0)
  {
    printf("1 - Registrar \n");
    printf("2 - Imprimir Todos \n");
    printf("3 - Imprimir Por Id \n");
    printf("4 - Remover Por Id \n");
    // printf("5 - Atualizar Por Id \n");
    printf("0 - Sair \n");
    printf("Digite a opcao: ");
    scanf("%d", &opt);
    callOpt(opt);
  }
  return 0;
}

