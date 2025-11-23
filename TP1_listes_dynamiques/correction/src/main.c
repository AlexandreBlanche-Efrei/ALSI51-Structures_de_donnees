#include <stdio.h>
#include <stdlib.h>
//#include "array/list_array.h"
#include "linked_list/list_linked.h"
//#include "linked_list/list_double-linked.h"

int main() {

    // printf("%d\n", f(3));
    // printf("%d\n", map(&f, 5));

    t_list list = create_empty_list();
    print_list(&list);
    //print_list_backward(&list);

    push_back(&list, 5);
    push_back(&list, 2);
    print_list(&list);

    push_back(&list, -3);
    push_back(&list, 4);
    print_list(&list);
    //print_list_backward(&list);v
    print_list(&list);

    delete_at(&list, 2);
    print_list(&list);

    insert(&list, 1, 0);
    print_list(&list);

    push_front(&list, 8);
    print_list(&list);

    set(&list, 3, 10);
    print_list(&list);

    printf("list[%d] = %d\n", 1, get(&list, 1));

    //print_list_backward(&list);
    print_list(&list);

    return 0;
}