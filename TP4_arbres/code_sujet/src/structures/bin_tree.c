#include "structures/bin_tree.h"

#include <stdio.h>
#include <stdlib.h>

t_node *create_node(const T val) {
    // TODO
    return NULL;
}

int max(const int a, const int b) {
    return a > b ? a : b;
}

string_tree create_empty_tree() {
    string_tree t;
    // TODO
    return t;
}

void insert_bst_aux(t_node *node, const T val) {
    // TODO
}

void insert_bst(string_tree *t, const T val) {
    // TODO
}

bool search_tree_aux(const t_node *node, const T val) {
    // TODO
    return false;
}

bool search_in_tree(const string_tree *t, const T val) {
    // TODO
    return false;
}

void list_all_entries_tree_aux(const t_node *node) {
    // TODO
}

void list_all_entries_tree(const string_tree *t) {
    // TODO
}

////////////////////////////////////////////////////////

// AVL structure

t_node *rotate_left(t_node *root) {

    // TODO

    t_node *new_root = NULL;
    return new_root;
}

t_node *rotate_right(t_node *root) {
    
    // TODO

    t_node *new_root = NULL;
    return new_root;
}

// Returns the new root of the subtree previously rooted on node
t_node *balance_node(t_node *node) {

    // We assume node->bf >= 2 || node->bf <= -2
    // if (node->bf > 2 || node->bf < -2) {
    //     printf("balance_tree: the tree is not an AVL\n");
    //     exit(EXIT_FAILURE);
    // }

    // TODO

    return node;
}

typedef struct {
    t_node *updated_node;
    bool needs_balancing;
} insertion_result;

// Returns true to stop
// False to continue balancing
insertion_result insert_avl_aux(t_node *node, const T val) {

    if (node == NULL) {
        printf("insert_avl: node is NULL\n");
        exit(EXIT_FAILURE);
    }
    
    const int comp = string_comp(val, node->value);
    if (comp == 0) {
        printf("insert_avl: node is already present\n");
        exit(EXIT_FAILURE);
    }

    // TODO

    insertion_result output;
    output.updated_node = node;
    output.needs_balancing = false;
    return output;
}

void insert_avl(string_tree *t, const T val) {
    // TODO
}


////////////////////////////////////////////////////////


void print_mermaid_aux(FILE *file, const t_node *node, int *cpt) {

    const int node_cpt = *cpt;
    if (node == NULL) {
        fprintf(file, "\tA%d: _\n", node_cpt);
        (*cpt)++;
        return;
    }
    
    fprintf(file, "\tA%d: %s\n", node_cpt, node->value);
    // fprintf(file, "\tA%d: %s (h = %d, bf = %d)\n", node_cpt, node->value, node->height, node->bf);
    (*cpt)++;
    print_mermaid_aux(file, node->left, cpt);
    const int right_node_cpt = *cpt;
    print_mermaid_aux(file, node->right, cpt);
    
    fprintf(file, "\tA%d --> A%d: left\n", node_cpt, node_cpt + 1);
    fprintf(file, "\tA%d --> A%d: right\n", node_cpt, right_node_cpt);
}

bool export_mermaid(const string_tree *t, const char *file_name) {
    if (t->root == NULL)
        return false;
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("File %s could not be created\n", file_name);
        return false;
    }
    int cpt = 0;
    fprintf(file, "stateDiagram\n");
    print_mermaid_aux(file, t->root, &cpt);
    fclose(file);
    return true;
}

void destroy_tree_aux(t_node *node) {
    free(node->value);
    if (node->left != NULL)
        destroy_tree_aux(node->left);
    if (node->right != NULL)
        destroy_tree_aux(node->right);
    free(node);
}

void destroy_tree(string_tree *t) {
    t->size = 0;
    if (t->root != NULL)
        destroy_tree_aux(t->root);
    t->root = NULL;
}
