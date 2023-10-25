#include "reader.hpp"
using namespace std;

enum order
{
    IN,
    PRE,
    POST
};

typedef struct node
{
    // struct node* parent;
    Battalion* data;
    struct node *left;
    struct node *right;
} tree;

tree *root = NULL;

bool is_empty_tree(tree *T)
{ 
    return T == NULL;
}

void filling_node(Battalion* data,Battalion value){
    data->setBudget(value.getBudget());
    data->setId(value.getId());
    data->setManpower(value.getManpower());
    data->setCode(value.getCode());
    data->setArmoredEquipment(value.getArmoredEquipment());
}   

tree *create_node(Battalion value)
{
    //crea un espacio de memoria
    tree *node = (tree *)malloc(sizeof(tree));
    node->data = new Battalion();
    filling_node(node->data,value);
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_aux(tree *T, Battalion value)
{
    if (value.getManpower() <= T->data->getManpower())
        if (T->left == NULL)
            T->left = create_node(value);
        else
            insert_aux(T->left, value);
    else if (T->right == NULL)
        T->right = create_node(value);
    else
        insert_aux(T->right, value);
}

void insert(tree *T, Battalion value)
{
    if (is_empty_tree(T))
        root = create_node(value);
    else 
        insert_aux(T, value);
}

void show_in_order(tree *T)
{
    if (T == NULL)
    {
        cout << "- ";
        return;
    }
    cout << "[ ";
    cout << (T->data)->getManpower() << " ";
    show_in_order(T->left);
    show_in_order(T->right);
    cout << "] ";
}

void show_pre_order(tree *T)
{
    if (T == NULL)
    {
        cout << "- ";
        return;
    }
    cout << "[ ";
    show_pre_order(T->left);
    cout << (T->data)->getManpower() << " ";
    show_pre_order(T->right);
    cout << "] ";
}

void show_post_order(tree *T)
{
    if (T == NULL)
    {
        cout << "- ";
        return;
    }
    cout << "[ ";
    show_post_order(T->left);
    show_post_order(T->right);
    cout << (T->data)->getManpower() << " ";
    cout << "] ";
}

void show(tree *T, order mode)
{
    switch (mode)
    {
    case IN:
        show_in_order(T);
        break;
    case PRE:
        show_pre_order(T);
        break;
    case POST:
        show_post_order(T);
        break;
    }
    cout << "\n";
}

bool find(tree *T, int value)
{
    if (T == NULL)
        return false;
    if (value == (T->data)->getManpower())
    {
        cout << "valor buscado: " << (T->data)->getManpower() << "SI existe";
        return true;
    }
    if (value < (T->data)->getManpower())
        return find(T->left, value);
    else
        return find(T->right, value);
}

bool findNoRecursive(tree* T, int value) {
    while (T != NULL) {
        if (value == (T->data)->getManpower()) {
            //cout << "Valor buscado: " << (T->data)->getManpower() << " SI existe" << endl;
            cout << " Valor buscado SI existe \n \n";
            return true;
        } else if (value < (T->data)->getManpower()) {
            T = T->left;  // Moverse hacia el subárbol izquierdo
        } else {
            T = T->right;  // Moverse hacia el subárbol derecho
        }
    }
    cout << " El valor buscado NO encontrado \n \n";
    return false;
}
