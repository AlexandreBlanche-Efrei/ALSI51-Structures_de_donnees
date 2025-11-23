#include "tests/test_structures.h"

#include "structures/string_type.h"
#include "structures/bin_tree.h"
#include "structures/prefix_tree.h"

#include <stdio.h>
#include <string.h>

void get_file_name(char *file_name, int i) {
    const int len_file_name = strlen(file_name);
    // file ends with ".mmd"
    file_name[len_file_name - 7] = '0' + (i / 100);
    file_name[len_file_name - 6] = '0' + ((i / 10) % 10);
    file_name[len_file_name - 5] = '0' + (i % 10);
}

void test_bin_tree() {
    const string tab[] = { "9", "1", "2", "4", "8", "3", "5", "0", "6", "7" };
    
    const char *base_name = "output/tree_000.mmd";
    char file_name[strlen(base_name) + 1];
    strcpy(file_name, base_name);

    string_tree t = create_empty_tree();
    for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) {
        insert_bst(&t, tab[i]);

        get_file_name(file_name, i);
        const bool success = export_mermaid(&t, file_name);
        if (success)
            printf("File %s exported\n", file_name);
    }
}

void test_prefix_tree() {
    prefix_tree t = create_empty_prefix_tree();
    const char *strings[] = { "set", "make", "men", "ten", "tea", "tell",
            "tennis", "ten", "tear", "male", "war", "was", "wall",
            "walrus", "wake", "cake", "care", "car", "cook", "cool", "cost", "coast",
            "settle", "setting", "settings", "settling" };
    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        insert_in_prefix_tree(&t, strings[i]);
    }
    list_all_entries_prefix_tree(&t);
    export_mermaid_prefix_tree(&t, "prefix.mmd");
}