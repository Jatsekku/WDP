#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

typedef struct sl_node{
  char content;
  struct sl_node* next;
}sl_node_t;

void SL_Init(sl_node_t** head)
{
  *head = NULL;
}

uint8_t SL_isEmpty(sl_node_t** head)
{
  return(*head == NULL);
}

void SL_Push(char data, sl_node_t** head)
{
  sl_node_t *new_node = malloc(sizeof(sl_node_t));
  new_node->content = data;
  new_node->next=*head;
  *head=new_node;
}

char SL_Pop(sl_node_t** head)
{
  sl_node_t* next_node = NULL;

  if(*head == NULL)
    return -1;

  next_node = (*head)->next;
  char data_tmp = (*head)->content;
  free(*head);
  *head = next_node;

  return data_tmp;
}

char SL_HeadContent(sl_node_t* head)
{
  return head->content;
}


void SL_DestroyAll(sl_node_t** head)
{
  sl_node_t* node_tmp = (*head);

  while(!((*head) == NULL))
  {
    node_tmp=(*head)->next;
    free(*head);
    (*head)=node_tmp;
  }
}

void SL_Print(sl_node_t* head)
{
  if(!SL_isEmpty(&head))
  {
    sl_node_t* node_tmp = head;
    printf("___________________________\n");
    printf("Single Linked List (Stack):\n");

    while(!(node_tmp==NULL))
    {
      printf("%c\n", node_tmp->content);
      node_tmp=node_tmp->next;
    }
    printf("___________________________\n");
  }
  else
    printf("No data! \n");
}

uint8_t SL_BracketParser(sl_node_t** head, char* str)
{
  char a;
  size_t i=0;
  SL_DestroyAll(head);
  while( (a = str[i]) != '\0')
  {
    if(a == '(')
      SL_Push(a, head);
    if(a == ')')
      SL_Pop(head);
      i++;
  }

  uint8_t result = SL_isEmpty(head);
  SL_DestroyAll(head);
  return result;

}


void API_Print(void)
{
  printf("________________________________\n\
  Single Linked List (Stack) API\n\
  1. SL_Push <data> <enter>\n\
  2. SL_Pop\n\
  3. SL_HeadContent\n\
  4. SL_DestroyAll\n\
  5. SL_BracketParser\n\
  6. Exit\n");
}

char getch(void)
{
  char tmp = getchar();
  system("clear");
  return tmp;
}

int main(void)
{
  uint8_t runing_state = 1;
  sl_node_t* stack;
  SL_Init(&stack);


  while(runing_state)
  {
    SL_Print(stack);
    API_Print();

    switch (getch())
    {
      case '1':
      {
        printf("Data to Push (one char):\n>" );
        getchar();  //dirty hack
        char char_tmp = getchar();
        SL_Push(char_tmp, &stack);
      }break;

      case '2':
      {
        char data_tmp = SL_Pop(&stack);
        printf("Poped data: %c\n", data_tmp);
        getchar();
      }break;

      case '3':
      {
        char data_tmp = SL_HeadContent(stack);
        printf("Data on the top: %c\n", data_tmp);
        getchar();

      }break;

      case '4':
      {
        printf("List destroyed\n");
        SL_DestroyAll(&stack);
      }break;

      case '5':
      {
        printf("Expresion to check:\n>");
        char buf[256];
        scanf("%255s", buf);

        if(SL_BracketParser(&stack, buf))
          printf("Balanced expression\n");
        else
          printf("Unbalanced expression\n");

        sleep(3);

      }break;

      case '6':
      {
        printf("The program will be closed\n");
        sleep(2);
        runing_state = 0;
      }break;

    }
  }

  system("clear");

}
