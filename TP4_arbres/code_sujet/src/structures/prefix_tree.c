#include "structures/prefix_tree.h"

#include <stdio.h>
#include <stdlib.h>

prefix_node *create_prefix_tree_node() {
    // TODO
    return NULL;
}

void init_table(prefix_node *node) {
    // TODO
}

prefix_tree create_empty_prefix_tree() {
    prefix_tree t;
    // TODO
    return t;
}

void insert_prefix_aux(prefix_node *node, const string s) {
    // TODO
}

void insert_in_prefix_tree(prefix_tree *t, const string s) {
    // TODO
}


bool search_prefix_aux(const prefix_node *node, const string s) {
    // TODO
    return false;
}

bool search_in_prefix_tree(const prefix_tree *t, const string s) {
    // TODO
    return false;
}

void list_all_entries_prefix_tree_aux(const prefix_node *node, string s, const int depth) {
    // TODO
}

void list_all_entries_prefix_tree(const prefix_tree *t) {
    // TODO
}

////////////////////////////////////////////////////////

void print_prefix_mermaid_aux(FILE *file, const prefix_node *node, int *cpt, const string s, const int depth) {

    const int node_cpt = *cpt;
    if (node->is_present)
        fprintf(file, "\tA%d: %s\n", node_cpt, s);
    else
        fprintf(file, "\tA%d: _\n", node_cpt);
    (*cpt)++;

    if (!node->table_empty) {
        for (int i = 0; i < CHAR_SET_SIZE; i++) {
            if (node->table[i] != NULL) {
                s[depth] = char_of_index(i);
                fprintf(file, "\tA%d --> A%d: %c\n", node_cpt, *cpt, s[depth]);
                print_prefix_mermaid_aux(file, node->table[i], cpt, s, depth + 1);
            }
        }
    }
    s[depth] = '\0';
}

bool export_mermaid_prefix_tree(const prefix_tree *t, const char *file_name) {
    if (t->root == NULL)
        return false;
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("File %s could not be created\n", file_name);
        return false;
    }
    fprintf(file, "stateDiagram\n");
    if (t->root != NULL) {
        char s[MAX_STRING_LENGTH + 1];
        for (int i = 0; i < MAX_STRING_LENGTH + 1; i++)
            s[i] = '\0';
        int cpt = 0;
        print_prefix_mermaid_aux(file, t->root, &cpt, s, 0);
    }
    fclose(file);
    return true;
}


void destroy_prefix_tree_aux(prefix_node *node) {
    if (!node->table_empty) {
        for (unsigned int i = 0; i < CHAR_SET_SIZE; i++) {
            if (node->table[i] != NULL)
                destroy_prefix_tree_aux(node->table[i]);
        }
        free(node->table);
    }
    free(node);
}

void destroy_prefix_tree(prefix_tree *t) {
    t->size = 0;
    if (t->root != NULL)
        destroy_prefix_tree_aux(t->root);
    t->root = NULL;
}
