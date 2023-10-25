using namespace std;

enum order {IN,PRE,POST};

typedef struct node {
    struct node* parent;
    string data;
    struct node* left;
    struct node* right;
} tree;

tree* root = NULL;

/*
    TODO:
    - Insertar
    - Eliminar
    - Buscar
    - Modificar nodo
    - Mostrar (In - Pre - Post)
    - Vacío
*/

bool is_empty_tree(tree* T){
    return T == NULL;
}
//creando espacio en memoria para el nuevo nodo
tree* create_node(string value){
    tree* node = (tree*) malloc( sizeof(tree) );
    
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_aux(tree* T, string value){
    if(value <= T->data)
        if(T->left == NULL) T->left = create_node(value);
        else insert_aux(T->left, value);
    else
        if(T->right == NULL) T->right = create_node(value);
        else insert_aux(T->right, value);
}

void insert(tree* T, string value){
    if(is_empty_tree(T)) root = create_node(value);
    else insert_aux(T, value);
}

void show_in_order(tree* T){
    if(T == NULL){
        cout << "- ";
        return;
    }
    cout << "[ ";
    cout << T->data << " ";
    show_in_order(T->left);
    show_in_order(T->right);
    cout << "] ";
}

void show_pre_order(tree* T){
    if(T == NULL){
        cout << "- ";
        return;
    }
    cout << "[ ";
    show_pre_order(T->left);
    cout << T->data << " ";
    show_pre_order(T->right);
    cout << "] ";
}

void show_post_order(tree* T){
    if(T == NULL){
        cout << "- ";
        return;
    }
    cout << "[ ";
    show_post_order(T->left);
    show_post_order(T->right);
    cout << T->data << " ";
    cout << "] ";
}

void show(tree* T, order mode){
    switch(mode){
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

//buscando el arbol
bool find(tree* T, string value){
    if(T == NULL) return false;
    if(value == T->data) return true;
    if(value < T->data) return find(T->left, value);
    else return find(T->right, value);
}

//Agregando una nueva palabra
void addWord(){
    string newWord;
    cout<<"Ingresa nueva palabra: ";
    cin>>newWord;
    cin.ignore();
    insert(root, newWord);
}

//Autocomplete -> autocompletado funcion
void complete_word(tree* node, string word){
    if (node != nullptr) {
        // Verificar si la palabra actual en el nodo comienza con el prefijo
        if (node->data.find(word) == 0) {
            cout << node->data << endl;
        }
        
        // Recursivamente buscar en los subárboles izquierdo y derecho
        complete_word(node->left, word);
        complete_word(node->right, word);
    }
}

void autocomplete(){
    string completeWord;
    cout<<"Autocomplementar palabra: ";
    cin>>completeWord;
    cin.ignore();
    complete_word(root,completeWord);
}

//Graficando en forma de arbol el arbol
void printTree(tree* node, string prefix = "") {
    if (node != nullptr) {
        // Imprime el valor del nodo
        cout << prefix << "├── " << node->data << endl;

        // Recursivamente imprime el subárbol derecho y luego el izquierdo
        printTree(node->right, prefix + "│   ");
        printTree(node->left, prefix + "│   ");
    }
}
void printAll(){
    // Imprime el árbol visualmente
    printTree(root);
    cout<<"\n";
    show(root, PRE);
}