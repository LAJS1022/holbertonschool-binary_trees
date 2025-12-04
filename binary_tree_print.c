#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#define PRINT_NULL 0
#define PRINT_NODE 1
typedef struct levelorder_queue_s
{
const binary_tree_t *node;
int type;
struct levelorder_queue_s *next;
} levelorder_queue_t;
static void enqueue(levelorder_queue_t **head, const binary_tree_t *node, int type)
{
levelorder_queue_t *new;
new = malloc(sizeof(levelorder_queue_t));
if (new == NULL)
exit(1);
new->node = node;
new->type = type;
new->next = NULL;
if (*head == NULL)
*head = new;
else
{
levelorder_queue_t *tmp = *head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = new;
}
}
static void free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *tmp;
while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}
void binary_tree_print(const binary_tree_t *tree)
{
levelorder_queue_t *queue = NULL, *tmp;
int level = 0, nodes = 0;
if (tree == NULL)
return;
enqueue(&queue, tree, PRINT_NODE);
while (queue != NULL)
{
nodes = 0;
tmp = queue;
while (tmp != NULL)
{
if (tmp->type == PRINT_NODE)
{
printf("[%03d] %d\n", level, tmp->node->n);
enqueue(&queue, tmp->node->left, tmp->node->left ? PRINT_NODE : PRINT_NULL);
enqueue(&queue, tmp->node->right, tmp->node->right ? PRINT_NODE : PRINT_NULL);
}
else
printf("[%03d] NULL\n", level);
tmp = tmp->next;
nodes++;
}
level++;
free_queue(queue);
queue = NULL;
}
}
